#include "Visual.h"


Visual::Visual(std::vector<Animal> &incPop):pop(incPop){
}

void Visual::visualSetup(){
	LPCWSTR myClass = L"Green Monkeys";
	LPCWSTR myTitle = L"Natural Selection Simulator";

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

LRESULT CALLBACK Visual::WindowProcedure(HWND hWnd, unsigned int msg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (msg)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 20, NULL);
		SetTimer(hWnd, 2, 2000, NULL);
		break;
	case WM_TIMER:
		if (wParam == 1){
			//Screen refresh (illusion of moving)
			InvalidateRect(hWnd,NULL, TRUE);
			UpdateWindow(hWnd);
		}
		else if (wParam == 2){
			//Animal Pos Update with screen refresh
			//animalPosUpdate();
			x += 5;
			TextOut(hdc, x, x, L"HI", 2);
			InvalidateRect(hWnd, NULL, TRUE);
			UpdateWindow(hWnd);
		}
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		/*Window here*/

		//code to plot points of animal locations called here
	   // paintAnimals(hdc, hWnd);
		Ellipse(hdc, 90, 90, 110, 110);



		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}

void Visual::animalPosUpdate(){
	
}

void Visual::paintAnimals(HDC hdc, HWND hWnd){
	TextOut(hdc, x+30, x+30, L"HI", 2);
}