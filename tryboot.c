#define _GNU_SOURCE

#include <linux/unistd.h>
#include <linux/reboot.h>
#include <sys/syscall.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[])  {
    char *param = NULL;
    int cmd;

    if(argc == 2) {
        param = argv[1];
        cmd = LINUX_REBOOT_CMD_RESTART2;
    }
    else {
        cmd = LINUX_REBOOT_CMD_RESTART;
    }

    // prevent being killed when parent dies
    int rc = daemon(0, 1);
    if (rc == -1) {
        perror("daemon() failed");
        return 1;
    }

    // write current pid to the killall5 skip file
    pid_t pid = getpid();

    FILE *k5skip = fopen("/var/tmp/k5_skip", "a");
    fprintf(k5skip, "%d\n", pid);
    fclose(k5skip);

    system("/etc/init.d/rc.shutdown");

    sync();
    printf("Calling reboot syscall...\n");

    // calling reboot() doesn't work, need to use syscall()
    //int rc = reboot(LINUX_REBOOT_MAGIC1, LINUX_REBOOT_MAGIC2, cmd, param);
    //printf("After reboot: rc=%d, errno=%d\n", rc, errno);
    syscall(SYS_reboot, LINUX_REBOOT_MAGIC1, LINUX_REBOOT_MAGIC2, cmd, param);

    return 0;
}
