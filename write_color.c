#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

void i2c_write(int fd, char reg, char val) {
	int result = wiringPiI2CWriteReg8(fd, reg, val);

	if (result == -1) {
		fprintf(stderr, "Error.  Errno %s\n", errno);
		exit(errno);
	}
}


int main(int argc, char** argv) {
	if ( (argc != 5) || (atoi(argv[1]) > 127)) {
		fprintf(stderr, "usage: %s <address> <red> <green> <blue>\n", argv[0]);
		exit(1);
	}
	int addr = atoi(argv[1]);
	int red = atoi(argv[2]);
	int green = atoi(argv[3]);
	int blue = atoi(argv[4]);

	int fd = wiringPiI2CSetup(addr);

	i2c_write(fd, 'R', red);
	i2c_write(fd, 'G', green);
	i2c_write(fd, 'B', blue);

	return 0;
}
