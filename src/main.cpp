#include <Arduino.h>
/*
#include <Wire.h>
#include <Adafruit_BusIO_Register.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>

Adafruit_MPU6050 mpu;

// Pin Definitions
#define enb 10 // D10
#define in1 11 // D11
#define in2 12 // D12
#define in3 13 // D13
#define in4 A0 // A0
#define ena A1 // A1

#define m1y 2 // Motor 1 Yellow (D2)
#define m1g 3 // Motor 1 Green (D3)
#define m2y 9 // Motor 2 Yellow (D5)
#define m2g 6 // Motor 2 Green (D6)

int i = 0;

void setup()
{
    delay(500);
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
    // Set pinModes for motor driver inputs and enable pins
    pinMode(enb, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(ena, OUTPUT);

    // Set pinModes for motor connections
    pinMode(m1y, INPUT);
    pinMode(m1g, INPUT);
    pinMode(m2y, INPUT);
    pinMode(m2g, INPUT);

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
float prevgyroX = 0;
int state = 1;
unsigned long period = 0;

void loop()
{
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    // static error offset
    gyroX = g.gyro.x - 0.02248;

    // Dynamic error
    if (abs(gyroX) < 0.1)
    {
        digitalWrite(LED_BUILTIN, HIGH);
    }
    else
    {
        digitalWrite(LED_BUILTIN, LOW);
    }

    // steady state reset
    if (abs(gyroX) >= 0.01)
    {
        angle = gyroX + angle;
    }
    if (state != 2 && gyroX == prevgyroX)
    {
        period = millis();
        state = 2;
    }
    if (state == 2 && millis() - period >= 200)
    {
        angle = 0;
        state = 1;
    }

    // display

    // Serial.print("Rotation X: ");
    Serial.print(gyroX);
    Serial.print('\t');
    Serial.print(state);
    Serial.print('\t');
    Serial.print(angle);
    Serial.print('\t');
    Serial.print(digitalRead(m1g));
    Serial.print('\t');
    Serial.print(digitalRead(m1y));
    Serial.print('\t');
    Serial.print(digitalRead(m2g));
    Serial.print('\t');
    Serial.println(digitalRead(m2y));

    delay(50);
    prevgyroX = gyroX;
}

*/
bool i = 0;



void setup() {
    pinMode(LED_BUILTIN,OUTPUT);
    Serial.begin(115200);
}

void loop() {
    digitalWrite(LED_BUILTIN,i);
    Serial.println(i);
    i = !i;
    delay(5*(sqrt(millis())));
}

