#pragma once
#include <thread>
#include <chrono>
#include <Windows.h>
#include "Render.h"
bool menuOpen = true;

// Toggle Thread
inline void ToggleMenuThread()
{
    static std::chrono::time_point LastTimePoint = std::chrono::steady_clock::now();

    while (true)
    {
        auto CurTimePoint = std::chrono::steady_clock::now();

        if (GetAsyncKeyState(VK_INSERT)
            && CurTimePoint - LastTimePoint >= std::chrono::milliseconds(150))
        {
            menuOpen = !menuOpen;
            LastTimePoint = CurTimePoint;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

// Toggle Start
inline void StartToggleThread()
{
    std::thread toggleThread(ToggleMenuThread);
    toggleThread.detach();
}
