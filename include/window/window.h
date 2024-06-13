#pragma once

#include <wtypes.h>
#include "arm/arm.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class Window {
    public:
        Window();
        ~Window();
        void DrawArm(HDC& hdc) const;
        void DrawGrid(HDC& hdc) const;
        bool ProcessMessages();
        Vector2d GetScreenXY(LPARAM lParam) const;
        void UpdateOnScreenVectors(LPARAM lParam);

    private:
        HINSTANCE m_hInstance;
        HWND m_hWnd;
        const wchar_t *CLASS_NAME = L"WindowClass";
        Arm m_arm;
        Vector2d m_middlePoint;
        Vector2d m_line1, m_line2;
        
        void DrawLine(HDC hdc, const Vector2d& start, const Vector2d& end) const;
};
