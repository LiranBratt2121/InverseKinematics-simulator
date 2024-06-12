#pragma once

#include <wtypes.h>
#include "arm/arm.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class Window {
    public:
        Window();
        ~Window();
        void Draw(Arm &arm);
        bool ProcessMessages();
    private:
        HINSTANCE m_hInstance;
        HWND m_hWnd;
        const wchar_t *CLASS_NAME = L"WindowClass";
        Vector2d m_middlePoint;
        Vector2d m_line1, m_line2;
};