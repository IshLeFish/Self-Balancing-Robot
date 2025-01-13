#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BusIO_Register.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>

Adafruit_MPU6050 mpu;


int i = 0;

void setup()
{
    delay(500);
    Serial.begin(9600);
    if (!mpu.begin())
    {
        Serial.println("Sensor init failed");
        while (1)
            yield();
    }
    Serial.println("hello world");
    mpu.setGyroRange(MPU6050_RANGE_250_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_94_HZ);
    
}

float angle = 0;
float gyroX = 0;

void loop()
{
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    gyroX = g.gyro.x - 0.02248;
    angle = gyroX+angle;
    //Serial.print("Rotation X: ");
    Serial.print(gyroX);
    Serial.print('\t');
    Serial.println(angle);
    delay(50);
    
}
