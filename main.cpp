#include "mbed.h"
#include "HEPTA_EPS.h"
#include "HEPTA_SENSOR.h"
 
RawSerial pc(USBTX,USBRX,9600);
HEPTA_EPS eps(p16,p26);
HEPTA_SENSOR sensor(p17,
                  p28,p27,0x19,0x69,0x13,
                  p13, p14,p25,p24);
Timer sattime;

int main(){
    sattime.start();
    float temp;
    for (int i=0;i<50;i++) {
        sensor.temp_sense(&temp);
        pc.printf("Time = %.2f [s] temp = %f [deg]\r\n",sattime.read(),temp);
        wait(1.0);
    }
}