#include "Visual.h"

void visualSetup(){
	LPCWSTR myClass = L"Green Monkeys";
	LPCWSTR myTitle = L"Title";

	WNDCLASSEX wndclass = { sizeof(WNDCLASSEX), CS_DBLCLKS, WindowProcedure,
		0, 0, GetModuleHandle(0), LoadIcon(0, IDI_APPLICATION),
		LoadCursor(0, IDC_ARROW), HBRUSH(COLOR_WINDOW + 1),
		0, myClass, LoadIcon(0, IDI_APPLICATION) };

	if (RegisterClassEx(&wndclass))
	{
		HWND window = CreateWindowEx(0, myClass, myTitle,
			WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
			CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, GetModuleHandle(0), 0);
		if (window)
		{
			ShowWindow(window, SW_SHOWDEFAULT);
			MSG msg;
			while (GetMessage(&msg, 0, 0, 0)) DispatchMessage(&msg);
		}
	}
}

long __stdcall WindowProcedure(HWND hWnd, unsigned int msg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	switch (msg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		/*Window here*/
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
		break;
	}
	return 0L;
}