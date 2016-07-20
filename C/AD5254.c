// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// AD5254
// This code is designed to work with the AD5254_I2CPOT_10K I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Potentiometers?sku=AD5254_I2CPOT_10K#tabs-0-product_tabset-2

#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>

void main() 
{
	// Create I2C bus
	int file;
	char *bus = "/dev/i2c-1";
	if((file = open(bus, O_RDWR)) < 0) 
	{
		printf("Failed to open the bus. \n");
		exit(1);
	}
	// Get I2C device, AD5254 I2C address is 0x2C(44)
	ioctl(file, I2C_SLAVE, 0x2C);

	// Send instruction for POT channel-0(0x00)
	// Input resistance value(0x80)
	char config[2] = {0};
	config[0] = 0x00;
	config[1] = 0x80;
	write(file, config, 2);

	// Send instruction for POT channel-1(0x01)
	// Input resistance value(0x80)
	config[0] = 0x01;
	config[1] = 0x80;
	write(file, config, 2);

	// Send instruction for POT channel-2(0x02)
	// Input resistance value(0x80)
	config[0] = 0x02;
	config[1] = 0x80;
	write(file, config, 2);

	// Send instruction for POT channel-3(0x03)
	// Input resistance value(0x80)
	config[0] = 0x03;
	config[1] = 0x80;
	write(file, config, 2);
	sleep(1);

	// Read 1 byte of data from the register(0x00)
	char reg[1] = {0x00};
	write(file, reg, 1);
	char data[1] = {0};
	if(read(file, data, 1) != 1)
	{
		printf("Erorr : Input/output Erorr \n");
	}
		
	// Convert the data
	float resistance_0 = (data[0] / 256.0) * 10.0;

	// Read 1 byte of data from the register(0x01)
	reg[1] = 0x01;
	write(file, reg, 1);
	if(read(file, data, 1) != 1)
	{
		printf("Erorr : Input/output Erorr \n");
	}
		
	// Convert the data
	float resistance_1 = (data[0] / 256.0) * 10.0;

	// Read 1 byte of data from the register(0x02)
	reg[1] = 0x02;
	write(file, reg, 1);
	if(read(file, data, 1) != 1)
	{
		printf("Erorr : Input/output Erorr \n");
	}
		
	// Convert the data
	float resistance_2 = (data[0] / 256.0) * 10.0;

	// Read 1 byte of data from the register(0x03)
    reg[0] = 0x03;
	write(file, reg, 1);
	if(read(file, data, 1) != 1)
	{
		printf("Erorr : Input/output Erorr \n");
	}
		
	// Convert the data
	float resistance_3 = (data[0] / 256.0) * 10.0;
	
	// Output data to screen
	printf("Resistance Channel-0 : %.2f K \n", resistance_0);
	printf("Resistance Channel-1 : %.2f K \n", resistance_1);
	printf("Resistance Channel-2 : %.2f K \n", resistance_2);
	printf("Resistance Channel-3 : %.2f K \n", resistance_3);
}