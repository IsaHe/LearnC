

#include <windows.h>
#include "point.h"

#define WIDTH 800
#define HEIGHT 600


Point3D start = { 400, 300, 100 };
Point3D end = { 200, 200, 100 };


// Procedimiento de ventana personalizado
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        RECT rect = { 0, 0, WIDTH, HEIGHT };
        HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
        FillRect(hdc, &rect, brush);
        DeleteObject(brush);

        // Convertir los puntos 3D a 2D
        Point start2D = point_project(start, 100);
        Point end2D = point_project(end, 100);

        // Establecer el punto de inicio
        MoveToEx(hdc, start2D.x, start2D.y, NULL);
        // Dibujar la línea hasta el punto final
        LineTo(hdc, end2D.x, end2D.y);

        EndPaint(hwnd, &ps);

        point_rotate(&end, 0.1);
        point_rotate(&start, 0.1);

        Sleep(100);

        InvalidateRect(hwnd, NULL, TRUE);
    }
    break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return 0;
}

// Crear una ventana
HWND CreateDefaultWindow(HINSTANCE hInstance, int nCmdShow, const char* title, int width, int height)
{
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProcedure; // Usar el procedimiento de ventana personalizado
    wc.hInstance = hInstance;
    wc.lpszClassName = "MyC3Dengine";
    RegisterClass(&wc);

    HWND hwnd = CreateWindow(wc.lpszClassName, title, WS_OVERLAPPEDWINDOW, 0, 0, width, height, 0, 0, hInstance, 0);

    if (hwnd)
    {
        ShowWindow(hwnd, nCmdShow);
    }

    return hwnd;
}

// Bucle de mensajes
int MessageLoop()
{
    MSG msg = { 0 };

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// Punto de entrada
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    HWND hwnd = CreateDefaultWindow(hInstance, nCmdShow, "MyC3Dengine", WIDTH, HEIGHT);

    if (hwnd)
    {
        MessageLoop();
    }

    return 0;
}