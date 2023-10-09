# picore-tryboot
On a Raspberry Pi, a custom command is needed to use the tryboot facility.
However, piCore uses busybox, and it doesn't support passing a command to the reboot syscall.
This extension provides an alternative binary to trigger a reboot with a custom command.

## Loading the extension
On the piCore system, copy the extension (`tryboot.tcz`) to `<tce-dir>/optional/` and run:
```
$ tce-load -i tryboot
```

## Rebooting
```
$ sudo tryboot "0 tryboot"
```

## Building the extension
On an arm system the extension can just be built using `make`.

On a non arm system a docker build can be done by running `scripts/build.sh`
