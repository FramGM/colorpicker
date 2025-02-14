#include <Windows.h>
#include <iostream>
int main()
{
    while (true)
    {
        Sleep(10);
        if (!GetAsyncKeyState('Z'))
            continue;

        POINT p;
        COLORREF color;
        HDC hDC;
        BOOL b;

        hDC = GetDC(NULL);
        if (hDC == NULL)
            continue;

        if (!GetCursorPos(&p))
            continue;

        color = GetPixel(hDC, p.x, p.y);
        if (color == CLR_INVALID)
            continue;

        ReleaseDC(GetDesktopWindow(), hDC);

        printf("%i %i %i\n", GetRValue(color), GetGValue(color), GetBValue(color));
        Sleep(100);
    }
	return 0;
}