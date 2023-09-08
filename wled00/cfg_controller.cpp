#include "wled.h"


void applyDefaultControllerConfigs() {
    Serial.println("Applying default controller settings...");

    // // HW Buttons
    // btnPin[0] = 34;
    // btnPin[1] = 35;
    // btnPin[2] = 36;
    // btnPin[3] = 39;
    // buttonType[0] = 2;
    // buttonType[1] = 2;
    // buttonType[2] = 2;
    // buttonType[3] = 2;

    // JsonObject hw = doc["hw"];
    // JsonObject hw_btn = hw["btn"];
    // hw_btn.remove("ins");
    // JsonArray hw_btn_ins = hw_btn.createNestedArray("ins");


    // for (uint8_t b = 0; b < WLED_MAX_BUTTONS; b++) { // deallocate existing button pins
    //     pinManager.deallocatePin(btnPin[b], PinOwner::Button); // does nothing if trying to deallocate a pin with PinOwner != Button
    // }

    // // Button #0
    // JsonObject hw_btn_ins_0 = hw_btn_ins.createNestedObject();
    // hw_btn_ins_0["type"] = 2;
    // JsonArray hw_btn_ins_0_pin = hw_btn_ins_0.createNestedArray("pin");
    // hw_btn_ins_0_pin.add(btnPin[0]);
    // JsonArray hw_btn_ins_0_macros = hw_btn_ins_0.createNestedArray("macros");
    // hw_btn_ins_0_macros.add(242);
    // hw_btn_ins_0_macros.add(243);
    // hw_btn_ins_0_macros.add(0);
}