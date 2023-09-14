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
    uint8_t pin = 32;
    uint8_t skip = 0;

    for (uint8_t s=0; s<WLED_MAX_BUSSES; s++) {
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
                pin = 33;
                break;
            case 1:
                pin = 25;
                break;
            case 2:
                pin = 26;
                break;
            case 3:
                pin = 27;
                break;
            case 4:
                pin = 14;
                break;
            case 5:
                pin = 13;
                break;                                
        }
    }   
    //===========================================


    // Buttons
    //===========================================
    // Button 0
    btnPin[0] = 34;
    buttonType[0] = 2;
    macroButton[0] = 239;
    macroLongPress[0] = 238;

    // Button 1
    btnPin[1] = 35;
    buttonType[1] = 2;
    macroButton[1] = 242;
    macroLongPress[1] = 241;    

    // Button 2
    btnPin[2] = 36;
    buttonType[2] = 2;
    macroButton[2] = 245;
    macroLongPress[2] = 244;

    // Button 3
    btnPin[3] = 39;
    buttonType[3] = 2;
    macroButton[3] = 248;
    macroLongPress[3] = 247;    

    JsonObject hw_btn = hw["btn"];
    hw_btn.remove("ins");
    JsonArray hw_btn_ins = hw_btn.createNestedArray("ins");

    for (uint8_t b = 0; b < WLED_MAX_BUTTONS; b++) { // deallocate existing button pins
        pinManager.deallocatePin(btnPin[b], PinOwner::Button); // does nothing if trying to deallocate a pin with PinOwner != Button
    }

    for (uint8_t i=0; i<WLED_MAX_BUTTONS; i++) {
        JsonObject hw_btn_ins_0 = hw_btn_ins.createNestedObject();
        hw_btn_ins_0["type"] = 2;
        JsonArray hw_btn_ins_0_pin = hw_btn_ins_0.createNestedArray("pin");
        hw_btn_ins_0_pin.add(btnPin[i]);
        JsonArray hw_btn_ins_0_macros = hw_btn_ins_0.createNestedArray("macros");
        hw_btn_ins_0_macros.add(macroButton[i]);
        hw_btn_ins_0_macros.add(macroLongPress[i]);
        hw_btn_ins_0_macros.add(macroDoublePress[i]);    
    }
    //===========================================
}