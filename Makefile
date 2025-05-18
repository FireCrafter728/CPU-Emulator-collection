include scripts/config.mk

.PHONY: all 6502 firmware dir clean

all: dir 6502 firmware

6502:
	$(MAKE) -C $(src)/6502
	echo "Created -> cec-6502"

firmware:
	$(MAKE) -C src/6502/Firmware
	echo "Created->6502.fd"

dir:
	mkdir -p $(output)
	mkdir -p $(bin)
	mkdir -p $(obj)
	mkdir -p $(bin)/6502
	mkdir -p $(obj)/6502

clean:
	rm -rf $(output)