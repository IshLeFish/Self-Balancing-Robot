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
    pinMode(LED_BUILTIN,OUTPUT);
    Serial.begin(115200);
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
    
    //Dynamic error
    if (abs(gyroX) <0.1) {  
        digitalWrite(LED_BUILTIN,HIGH);
    } else {
        digitalWrite(LED_BUILTIN,LOW);
    }

    // steady state reset
    if(abs(gyroX)>=0.01){ 
        angle = gyroX+angle;
    }
    if (state != 2 && gyroX == prevgyroX) {
        period = millis();
        state = 2;
    }
    if (state == 2 && millis() - period >=200) {
        angle = 0;
        state = 1;
    }

    //display

    //Serial.print("Rotation X: ");
    Serial.print(gyroX);
    Serial.print('\t');
    Serial.print(state);
    Serial.print('\t');
    Serial.println(angle);

    

    delay(50);
    prevgyroX = gyroX;
    
}


/*
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

*/