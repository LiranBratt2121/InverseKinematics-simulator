#include "window/window.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
    Window *window = nullptr;

    if (uMsg == WM_NCCREATE) {
        CREATESTRUCT *cs = reinterpret_cast<CREATESTRUCT *>(lParam);
        window = reinterpret_cast<Window *>(cs->lpCreateParams);
        SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window));
    } else {
        window = reinterpret_cast<Window *>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
    }

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
        case WM_PAINT:
            window->DrawGrid();
            break;
    }

    return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}

Window::Window() : m_hInstance(GetModuleHandle(nullptr)), m_arm(20, 25, Vector2d{0, 0}) {
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

void Window::DrawLine(HDC hdc, const Vector2d& start, const Vector2d& end) const {
    MoveToEx(hdc, static_cast<int>(start.m_x), static_cast<int>(start.m_y), nullptr);
    LineTo(hdc, static_cast<int>(end.m_x), static_cast<int>(end.m_y));
    std::cout << "drawing line, start: " << start.ToString() << ", end: " << end.ToString() << std::endl;
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
