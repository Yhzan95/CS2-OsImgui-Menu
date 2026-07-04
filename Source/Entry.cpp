#include <iostream>
#include "../Ext/OS-ImGui/OS-ImGui.h"
#include "Render.h"
#include "ToggleMenu.h"
#include "CS2Monitor.h"

int main()
{
    try {
        StartToggleThread();
        MonitorCS2WindowThread();
        
        Gui.AttachAnotherWindow("Counter-Strike 2", "", DrawCallBack);
    }
    catch (OSImGui::OSException& e)
    {
        std::cout << e.what() << std::endl;
    }

    system("pause");
    return 0;
}
