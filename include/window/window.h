#pragma once

#include <wtypes.h>
#include "arm/arm.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class Window {
    public:
        Window();
        ~Window();
        void Draw();
        void DrawGrid() const;
        bool ProcessMessages();
        static Vector2d GetScreenXY(LPARAM lParam);
    private:
        HINSTANCE m_hInstance;
        HWND m_hWnd;
        const wchar_t *CLASS_NAME = L"WindowClass";
        Vector2d m_middlePoint;
        Vector2d m_line1, m_line2;
    private:
        void DrawLine(const HDC& hdc, const Vector2d &start, const Vector2d &end) const;
};