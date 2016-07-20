// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// AD5254
// This code is designed to work with the AD5254_I2CPOT_10K I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Potentiometers?sku=AD5254_I2CPOT_10K#tabs-0-product_tabset-2

import com.pi4j.io.i2c.I2CBus;
import com.pi4j.io.i2c.I2CDevice;
import com.pi4j.io.i2c.I2CFactory;
import java.io.IOException;

public class AD5254
{
	public static void main(String args[]) throws Exception
	{
		// Create I2C bus
		I2CBus Bus = I2CFactory.getInstance(I2CBus.BUS_1);
		// Get I2C device, AD5254 I2C address is 0x2C(44)
		I2CDevice device = Bus.getDevice(0x2C);

		// Send instruction for POT channel-0
		// Input resistance value = 0x80(128)
		device.write(0x00, (byte)0x80);
		Thread.sleep(100);
		
		// Send instruction for POT channel-1
		// Input resistance value = 0x80(128)
		device.write(0x01, (byte)0x80);
		Thread.sleep(100);
		
		// Send instruction for POT channel-2
		// Input resistance value = 0x80(128)
		device.write(0x02, (byte)0x80);
		Thread.sleep(100);
		
		// Send instruction for POT channel-3
		// Input resistance value = 0x80(128)
		device.write(0x03, (byte)0x80);
		Thread.sleep(500);

		// Read 1 byte of data from address 0x00(00)
		byte[] data = new byte[2];
		data[0] = (byte)device.read(0x00);
		Thread.sleep(100);

		// Read 1 byte of data from address 0x01(01)
		byte[] data = new byte[2];
		data[0] = (byte)device.read(0x01);
		Thread.sleep(100);

		// Read 1 byte of data from address 0x02(02)
		byte[] data = new byte[2];
		data[0] = (byte)device.read(0x02);
		Thread.sleep(100);

		// Read 1 byte of data from address 0x03 (03)
		data[1] = (byte)device.read(0x03);
		Thread.sleep(100);

		// Convert the data
		double res_0 = ((data[0] & 0xFF) / 256.0) * 10.0;
		double res_1 = ((data[1] & 0xFF) / 256.0) * 10.0;
		double res_2 = ((data[1] & 0xFF) / 256.0) * 10.0;
		double res_3 = ((data[1] & 0xFF) / 256.0) * 10.0;

		// Output data to screen
		System.out.printf("Resistance Channel-0 : %.2f K %n", res_0);
		System.out.printf("Resistance Channel-1 : %.2f K %n", res_1);
		System.out.printf("Resistance Channel-2 : %.2f K %n", res_2);
		System.out.printf("Resistance Channel-3 : %.2f K %n", res_3);
	}
}