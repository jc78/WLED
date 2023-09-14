#include "wled.h"


void applyDefaultControllerPresets(JsonObject sObj) {
    Serial.println("Applying default controller presets...");

    int buttonId = 0;
    char buttonLabelSave[15];
    char buttonLabelApply[16];
    int preset_int = 238;
    char preset_char[5];
    char preset_save_char[8];

    int red = 255;
    int green = 0;
    int blue = 0;
    
    for (uint8_t i=0; i<WLED_MAX_BUTTONS; i++) {
        Serial.println("Setting up button " + String(buttonId) + " presets");
        sprintf(preset_char, "%d", preset_int);
        JsonObject buttonSave = sObj.createNestedObject(preset_char);
        sprintf(preset_save_char, "PS=%d", preset_int+1);
        buttonSave["win"] = preset_save_char;
        sprintf(buttonLabelSave, "_Button %d Save", buttonId);
        buttonSave["n"] = buttonLabelSave;    

        sprintf(preset_char, "%d", preset_int+1);
        JsonObject buttonApply = sObj.createNestedObject(preset_char);   
        buttonApply["mainseg"] = 0;

        JsonArray buttonApply_seg = buttonApply.createNestedArray("seg");
        JsonObject buttonApply_seg_obj = buttonApply_seg.createNestedObject();
        buttonApply_seg_obj["id"] = 0; 
        buttonApply_seg_obj["grp"] = 1;   
        buttonApply_seg_obj["spc"] = 0;   
        buttonApply_seg_obj["of"] = 0;            
        buttonApply_seg_obj["on"] = true;  
        buttonApply_seg_obj["frz"] = false;     
        buttonApply_seg_obj["bri"] = 128; 
        buttonApply_seg_obj["cct"] = 127;  
        buttonApply_seg_obj["set"] = 0; 

        JsonArray buttonApply_seg_obj_col = buttonApply_seg_obj.createNestedArray("col");
        JsonArray buttonApply_seg_obj_col_red = buttonApply_seg_obj_col.createNestedArray();
        buttonApply_seg_obj_col_red.add(red);
        buttonApply_seg_obj_col_red.add(green);
        buttonApply_seg_obj_col_red.add(blue);
        JsonArray buttonApply_seg_obj_col_green = buttonApply_seg_obj_col.createNestedArray();
        buttonApply_seg_obj_col_green.add(red);
        buttonApply_seg_obj_col_green.add(green);
        buttonApply_seg_obj_col_green.add(blue);    
        JsonArray buttonApply_seg_obj_col_blue = buttonApply_seg_obj_col.createNestedArray();
        buttonApply_seg_obj_col_blue.add(red);
        buttonApply_seg_obj_col_blue.add(green);
        buttonApply_seg_obj_col_blue.add(blue);       

        buttonApply_seg_obj["fx"] = 0;  
        buttonApply_seg_obj["sx"] = 128; 
        buttonApply_seg_obj["ix"] = 128; 
        buttonApply_seg_obj["pal"] = 0; 
        buttonApply_seg_obj["c1"] = 128; 
        buttonApply_seg_obj["c2"] = 128; 
        buttonApply_seg_obj["c3"] = 16; 
        buttonApply_seg_obj["sel"] = true; 
        buttonApply_seg_obj["rev"] = false; 
        buttonApply_seg_obj["mi"] = false; 
        buttonApply_seg_obj["o1"] = false; 
        buttonApply_seg_obj["o2"] = false; 
        buttonApply_seg_obj["o3"] = false; 
        buttonApply_seg_obj["si"] = 0; 
        buttonApply_seg_obj["m12"] = 0;   

        sprintf(buttonLabelApply, "_Button %d Apply", buttonId);
        buttonApply["n"] = buttonLabelApply;

        switch (buttonId) {
            case 0:
                red = 0;
                green = 255;
                blue = 0;
                break;
            case 1:
                red = 0;
                green = 0;
                blue = 255;
                break;
            case 2:
                red = 255;
                green = 0;
                blue = 255;
                break;                               
        }
        preset_int = preset_int + 3;
        buttonId++;
    }  
}