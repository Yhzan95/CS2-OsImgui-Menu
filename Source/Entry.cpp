#include <iostream>
#include "../Ext/OS-ImGui/OS-ImGui.h"
#include "Render.h"
#include "ToggleMenu.h"
#include "CS2Monitor.h" // ← Ici on inclut

int main()
{
    try {
        StartToggleThread();     // Pour toggle HOME
        MonitorCS2WindowThread(); // Pour quitter quand CS2 ferme

        Gui.AttachAnotherWindow("Counter-Strike 2", "", DrawCallBack);
    }
    catch (OSImGui::OSException& e)
    {
        std::cout << e.what() << std::endl;
    }

    system("pause");
    return 0;
}
