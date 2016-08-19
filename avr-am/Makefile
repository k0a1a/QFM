default:
	# compile for attiny86 with warnings, optimizations, and 1 MHz clock frequency
	#avr-gcc -Wall -Os -std=c99 -DF_CPU=1048576 -mmcu=attiny85 -o avr-am-sender.o avr-am-sender.c
	avr-gcc -Wall -Os -std=c99 -DF_CPU=1000000 -mmcu=attiny85 -o avr-am-sender.o avr-am-sender.c
	avr-objcopy -j .text -j .data -O ihex avr-am-sender.o avr-am-sender.hex
	avrdude -c usbasp -p t85 -U lfuse:w:0x22:m -U hfuse:w:0xdf:m -U efuse:w:0xff:m -U flash:w:avr-am-sender.hex:i

clean: /dev/null
	rm -f avr-am-sender.o avr-am-sender.hex
