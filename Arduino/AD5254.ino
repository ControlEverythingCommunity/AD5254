// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// AD5254
// This code is designed to work with the AD5254_I2CPOT_10K I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Potentiometers?sku=AD5254_I2CPOT_10K#tabs-0-product_tabset-2

#include<Wire.h>

// AD5254 I2C address is 0x2C(44)
#define Addr 0x2C

void setup()
{
  // Initialise I2C communication as Master
  Wire.begin();
  // Initialise serial communication, set baud rate = 9600
  Serial.begin(9600);

  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Send instruction for POT channel-0
  Wire.write(0x00);
  // Input resistance value, 0x80(128)
  Wire.write(0x80);
  // Stop I2C transmission
  Wire.endTransmission();

  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Send instruction for POT channel-1
  Wire.write(0x01);
  // Input resistance value, 0x80(128)
  Wire.write(0x80);
  // Stop I2C transmission
  Wire.endTransmission();

  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Send instruction for POT channel-2
  Wire.write(0x02);
  // Input resistance value, 0x80(128)
  Wire.write(0x80);
  // Stop I2C transmission
  Wire.endTransmission();

  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Send instruction for POT channel-3
  Wire.write(0x03);
  // Input resistance value, 0x80(128)
  Wire.write(0x80);
  // Stop I2C transmission
  Wire.endTransmission();
  delay(300);
}

void loop()
{
  unsigned int data;

  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Select data register
  Wire.write(0x00);
  // Stop I2C transmission
  Wire.endTransmission();

  // Request 1 byte of data
  Wire.requestFrom(Addr, 1);

  // Read 1 byte of data
  if (Wire.available() == 1)
  {
    data = Wire.read();
  }
  // Convert the data
  float res_0 = (data / 256.0 ) * 10.0;

  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Select data register
  Wire.write(0x01);
  // Stop I2C transmission
  Wire.endTransmission();

  // Request 1 byte of data
  Wire.requestFrom(Addr, 1);

  // Read 1 byte of data
  if (Wire.available() == 1)
  {
    data = Wire.read();
  }
  // Convert the data
  float res_1 = (data / 256.0 ) * 10.0;

  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Select data register
  Wire.write(0x02);
  // Stop I2C transmission
  Wire.endTransmission();

  // Request 1 byte of data
  Wire.requestFrom(Addr, 1);

  // Read 1 byte of data
  if (Wire.available() == 1)
  {
    data = Wire.read();
  }
  // Convert the data
  float res_2 = (data / 256.0 ) * 10.0;

  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Select data register
  Wire.write(0x03);
  // Stop I2C transmission
  Wire.endTransmission();

  // Request 1 byte of data
  Wire.requestFrom(Addr, 1);

  // Read 1 byte of data
  if (Wire.available() == 1)
  {
    data = Wire.read();
  }
  // Convert the data
  float res_3 = (data / 256.0 ) * 10.0;

  // Output data to serial monitor
  Serial.print("Resistance Channel-0 : ");
  Serial.print(res_0);
  Serial.println(" K");
  Serial.print("Resistance Channel-1 : ");
  Serial.print(res_1);
  Serial.println(" K");
  Serial.print("Resistance Channel-2 : ");
  Serial.print(res_2);
  Serial.println(" K");
  Serial.print("Resistance Channel-3 : ");
  Serial.print(res_3);
  Serial.println(" K");
  delay(500);
}
