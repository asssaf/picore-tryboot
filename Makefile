SRC := tryboot.c
BIN := tryboot
EXTDIR := extension
TCZ := $(BIN).tcz
LIST := $(TCZ).list
MD5 := $(TCZ).md5.txt

all: tryboot.tcz.list tryboot.tcz.md5.txt


$(BIN): $(SRC)
	gcc $(STATIC) -I/usr/include -o $(BIN) $(SRC)


$(EXTDIR): $(BIN)
	install -D $(BIN) $(EXTDIR)/usr/local/bin/$(BIN)


$(TCZ): $(EXTDIR)
	mksquashfs $(EXTDIR) $(TCZ) -all-root -noappend


$(LIST): $(TCZ)
	unsquashfs -lc $(TCZ) | sed 's|^squashfs-root/||' > $(LIST)


$(MD5): $(TCZ)
	md5sum $(TCZ) > $(MD5)


clean:
	rm -r $(BIN) $(EXTDIR) $(TCZ) $(LIST) $(MD5)
