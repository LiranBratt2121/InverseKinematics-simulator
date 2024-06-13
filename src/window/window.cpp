#include "window/window.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
    switch (uMsg){
        case WM_CLOSE:
            DestroyWindow(hWnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_LBUTTONDOWN:
            Window::GetScreenXY(lParam);
            break;
    }

    return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}

Window::Window() : m_hInstance(GetModuleHandle(nullptr)){
    WNDCLASSW wndClass = {};
    wndClass.lpszClassName = CLASS_NAME;
    wndClass.hInstance = m_hInstance;
    wndClass.hIcon = LoadIcon(nullptr, IDI_WINLOGO);
    wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wndClass.lpfnWndProc = WindowProc;

    RegisterClassW(&wndClass);

    DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

    int width = 640;
    int height = 480;

    RECT rect;
    rect.top = 250;
    rect.left = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;

    float realWidth = rect.right - rect.left;
    float realHeight = rect.bottom - rect.top;

    m_middlePoint.Update((float)realWidth / 2, (float)realHeight / 2);

    AdjustWindowRect(&rect, style, FALSE);

    m_hWnd = CreateWindowExW(0, 
                             CLASS_NAME,
                             L"InverseKinematics",
                             style,
                             rect.left,
                             rect.top,
                             realWidth,
                             realHeight,
                             nullptr,
                             nullptr,
                             m_hInstance,
                             nullptr
                        );

    ShowWindow(m_hWnd, SW_SHOW);
}

Window::~Window(){
    UnregisterClassW(CLASS_NAME, m_hInstance);
}

void Window::Draw(Arm &arm){
    m_line1.Update(arm.GetPart1() + m_middlePoint);
    m_line2.Update(arm.GetPart2() - m_line1);

    // DRAWING LOGIC!
}

bool Window::ProcessMessages(){
    MSG msg = {};

    while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE)){
        if (msg.message == WM_QUIT){
            return false;
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return true;
}
Vector2d Window::GetScreenXY(LPARAM lParam){
    float x = LOWORD(lParam);
    float y = HIWORD(lParam);
    Vector2d screenXY = Vector2d(x, y);

    std::cout << screenXY.ToString() << std::endl;
    return screenXY;
}
void Window::DrawLine(const HDC& hdc, const Vector2d &start, const Vector2d &end) const {
    std::cout << "drawing line, start:" << start.ToString() << ", end:" << end.ToString() << std::endl;

    MoveToEx(hdc, start.m_x, start.m_y, nullptr);
    LineTo(hdc, end.m_x, end.m_y);
}
