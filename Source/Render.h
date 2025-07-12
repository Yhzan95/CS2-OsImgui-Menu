#pragma once

#include "../Ext/OS-ImGui/OS-ImGui.h"
#include <chrono>
#include <iostream>
#include <functional>

extern bool menuOpen;

void DrawCallBack() {
    if (!menuOpen)
        return;

    ImGui::Begin("Menu");
    {
        ImGui::Text("This is a text.");
        if (ImGui::Button("Quit"))
        {
            Gui.Quit();
        }
        static bool a = false, b = false, c = false, d = false;
        static float Value = 0;
        float min = 0, max = 100;
        Gui.MyCheckBox("CheckBox1", &a);
        ImGui::Text("This is a text.");
        Gui.MyCheckBox2("CheckBox2", &b);
        Gui.MyCheckBox3("CheckBox3", &c);
        Gui.MyCheckBox4("CheckBox4", &d);
        Gui.SliderScalarEx1("[Slider]", ImGuiDataType_Float, &Value, &min, &max, "%.1f", ImGuiSliderFlags_None);
    }
    ImGui::End();
}
