#include <Servo.h>

#define photoPin1 A0
#define photoPin2 A1
#define photoPin3 A2
#define photoPin4 A3
#define maxValue 1023
#define minValue 0

int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;

int maxValue1 = minValue;
int maxValue2 = minValue;
int maxValue3 = minValue;
int maxValue4 = minValue;

int minValue1 = maxValue;
int minValue2 = maxValue;
int minValue3 = maxValue;
int minValue4 = maxValue;

int outValue1;
int outValue2;
int outValue3;
int outValue4;

const int arrayLength = 4;
int pinArray[] = {photoPin1, photoPin2, photoPin3, photoPin4};
int valueArray[] = {sensorValue1, sensorValue2, sensorValue3, sensorValue4};
int maxArray[] = {maxValue1, maxValue2, maxValue3, maxValue4};
int minArray[] = {minValue1, minValue2, minValue3, minValue4};
int outArray[] = {outValue1, outValue2};
 

int sensorValue;
int sensorMax = 0;
int sensorMin = 1023;


void setup(){
    Serial.begin(9600);

    for (int i = 0; i < arrayLength; i++){
        pinMode(pinArray[i], INPUT_PULLUP);
    }

    //La sensortårnet snurre rundt for å sjekke sensorverider

    while (millis() < 5000){
        for (int i = 0; i < arrayLength; i++){
            valueArray[i] = analogRead(pinArray[i]);

            if (valueArray[i] > maxArray[i]){
                maxArray[i] = valueArray[i];
            }

            if (valueArray[i] < minArray[i]){
                minArray[i] = valueArray[i];
            }
        }
    }

}

void sensorMapping(){
    for (int i = 0; i < arrayLength; i++){
        valueArray[i] = analogRead(pinArray[i]);
        
    }
}

void loop(){

}