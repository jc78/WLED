#include "wled.h"


void applyDefaultControllerConfigs() {
    Serial.println("Applying default controller settings...");

    JsonObject hw = doc["hw"];

    // LEDs
    //===========================================
    JsonObject hw_led = hw["led"];
    hw_led.remove("ins");
    JsonArray hw_led_ins = hw_led.createNestedArray("ins");

    uint8_t start = 0;
    uint8_t len = 16;
    uint8_t pin = 1;
    uint8_t skip = 0;

    for (uint8_t s=0; s<2; s++) {
        JsonObject ins = hw_led_ins.createNestedObject();

        ins["start"] = start;
        ins["len"] = len;
        JsonArray ins_pin = ins.createNestedArray("pin");
        ins_pin.add(pin);

        ins[F("order")] = 0;
        ins["rev"] = false;
        ins[F("skip")] = skip;
        ins["type"] = 22;
        ins["ref"] = false;
        ins[F("rgbwm")] = 0;
        ins[F("freq")] = 0;

        start = len + start;
        len = 1;
        skip = 1;

        switch (s) {
            case 0:
                pin = 2;
                break;                        
        }
    }   
    //===========================================
}