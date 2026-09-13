#include <stdio.h>
#include <stdint.h>

// Predefined masks 
#define ENABLE_SENSOR (1U << 0)
#define ENABLE_LED (1U << 1)
#define ENABLE_BUZZER (1U << 2)
#define ENABLE_LOGGING (1U << 3)

// Check which bit positions are enabled in control register
void checkControl(uint8_t* control){
    // Checks 
    for(uint8_t i = 0; i < 4; i++){
        if (*control & (1U << i)){
            switch(i){
                case 0:
                    printf("\nSensor Enabled");
                    break;
                case 1:
                    printf("\nLED enabled");
                    break;
                case 2: 
                    printf("\nBuzzer enabled");
                    break;
                case 3:
                    printf("\nLogging enabled");
                    break;
                default:
                    break;
            }
        }
    }
}

int main(){

    // Control register for peripherals 
    uint8_t control = 0b00000000;
    uint8_t* ptr = &control;

    /*
    Bit 0 → ENABLE_SENSOR
    Bit 1 → ENABLE_LED
    Bit 2 → ENABLE_BUZZER
    Bit 3 → ENABLE_LOGGING
    */

    /* TODO:
    Enable the sensor.
    Enable the buzzer.
    Disable the sensor again.
    Toggle the LED.
    Print the final register value in hexadecimal.    
    */

    // Enable sensor
    control = control | ENABLE_SENSOR;

    // Enable buzzer 
    control = control | ENABLE_BUZZER;

    // Disable the sensor 
    control = control & ~(ENABLE_SENSOR);

    // Toggle the LED
    for(int i = 0; i < 3; i++){ 
    control = control ^ ENABLE_LED;
    if(control & ENABLE_LED) printf("\nLED ON");
    else if(!(control & ENABLE_LED)) printf("\nLED OFF");
    // Add delay possibly using millis or implement my own similar to FreeRTOS using sys/time.h or time.h
    }

    // Print the final register value
    fprintf(stdout, "\n\nControl = 0x%02X\n", control);
    checkControl(ptr);

    // Result should be 0b00000110

    return 0;
}