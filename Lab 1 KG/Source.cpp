#include <iostream>
#include <windows.h>
#include <time.h>
//#include <vector>
//LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);

using namespace std;

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

LONG WINAPI WndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam)
{
    switch (Message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, Message, wparam, lparam);
    }
    return 0;
}

/*int GetRandomNumber(int min, int max)
{
    // ���������� ��������� ��������� �����
    srand(time(NULL));

    // �������� ��������� ����� - �������
    int num = min + rand() % (max - min + 1);

    return num;
}*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    srand(time(0));
        HWND hwnd; // ���������� ����
        MSG msg; // ��������� ���������
        WNDCLASS w; // ��������� ������ ����
        // ����������� ������ ����
        memset(&w, 0, sizeof(WNDCLASS));
        w.style = CS_HREDRAW | CS_VREDRAW;
        w.lpfnWndProc = WndProc; // ��� ������� �������
        w.hInstance = hInstance;
        w.hbrBackground = (HBRUSH)(WHITE_BRUSH);
        w.lpszClassName = L"My Class";
        RegisterClass(&w);
        // �������� ����
        hwnd = CreateWindow(L"My Class", L"���� ������������",
            WS_OVERLAPPEDWINDOW, 500, 300, 300, 300, NULL, NULL, hInstance, NULL);
        ShowWindow(hwnd, nCmdShow); // �����������
        UpdateWindow(hwnd);          // �����������
        

        int x1 = getRandomNumber(0, 299);
        int x2 = getRandomNumber(0, 299);
        int y1 = getRandomNumber(0, 299);
        int y2 = getRandomNumber(0, 299);

        int dx = x2 - x1;
        int dy = y2 - y1;
        float k = dy / dx;
        int x = x1;
        int y = y1;

        HDC hdc = GetDC(hwnd);
                                     
        // ���� ��������� ���������
        while (GetMessage(&msg, NULL, 0, 0))
        {

            while (x <= x2)
            {

                SetPixel(hdc, x, y, RGB(0, 0, 0));
                y += (int)k;
                x++;
            }



            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
       
       return msg.wParam;

}