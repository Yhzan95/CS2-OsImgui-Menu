#pragma once
#include <Windows.h>
#include <thread>
#include <chrono>
#include <cstdlib>

inline void MonitorCS2Window()
{
    while (true)
    {
        HWND hwnd = FindWindowA(NULL, "Counter-Strike 2");
        if (!hwnd)
        {
            // If cs2 closed or crashed exit thread
            exit(0);
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void MonitorCS2WindowThread()
{
    std::thread monitorThread(MonitorCS2Window);
    monitorThread.detach();
}
