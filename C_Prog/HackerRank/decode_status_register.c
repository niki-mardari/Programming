#include <stdio.h>
#include <stdint.h>

// Predefined bit mask positions 
#define SENSOR_READY (1U << 0)
#define OVER_TEMPERATURE (1U << 1)
#define DATA_AVAILABLE (1U << 2)
#define BATTERY_LOW (1U << 3)
#define COMMUNICATION_ERROR (1U << 4)
#define CALIBRATING (1U << 5)
// The last 2 bits are apparently reserved

int main(){
    // Sensor status register
    uint8_t status = 0b00101101;

    /*
    // Expected:

    Sensor ready
    Data available
    Battery low
    Calibrating
    */

    /*
    Bit 0 → SENSOR_READY
    Bit 1 → OVER_TEMPERATURE
    Bit 2 → DATA_AVAILABLE
    Bit 3 → BATTERY_LOW
    Bit 4 → COMMUNICATION_ERROR
    Bit 5 → CALIBRATING
    Bit 6 → RESERVED
    Bit 7 → RESERVED
    */

        if(status & SENSOR_READY) printf("\nSENSOR_READY"); 
        if (status & OVER_TEMPERATURE) printf("\nOVER_TEMPERATURE");
        if (status & DATA_AVAILABLE) printf("\nDATA_AVAILABLE"); 
        if (status & BATTERY_LOW) printf("\nBATTERY_LOW"); 
        if (status & COMMUNICATION_ERROR) printf("\nCOMMUNICATION_ERROR"); 
        if (status & CALIBRATING) printf("\nCALIBRATING\n"); 

        return 0;
}

/*
Could also use a loop and switch case like this:

for (uint8_t i = 0; i < 6; i++) {

    if (status & (1 << i)) {
        switch (i) {
            case 0:
                printf("\nSENSOR_READY");
                break;
            case 1:
                printf("\nOVER_TEMPERATURE");
                break;
            case 2:
                printf("\nDATA_AVAILABLE");
                break;
            case 3:
                printf("\nBATTERY_LOW");
                break;
            case 4:
                printf("\nCOMMUNICATION_ERROR");
                break;
            case 5:
                printf("\nCALIBRATING\n");
                break;
            default:
                break;
        }
    }
}
return 0;

*/