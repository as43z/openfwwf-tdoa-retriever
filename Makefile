# Makefile

# Target output module
obj-m += cb43.o

# Current directory
PWD := $(CURDIR)

# Build
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

# Clean
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean