#include "VisualHelp.h"

VisualHelp::VisualHelp(): hwnd(0){
}

VisualHelp::~VisualHelp(){
}

VisualHelp::operator HWND(){
	return hwnd;
}

HWND VisualHelp::Create(HINSTANCE hinst, LPCTSTR clsname, LPCTSTR wndname, HWND parent, DWORD dStyle,
	int x, int y, int width, int height) {
	hwnd = CreateWindow(clsname, wndname, dStyle,
		x, y, width, height, parent, NULL, hinst, NULL);

	return hwnd;
}

BOOL VisualHelp::Show(int dCmdShow) {
	BOOL CanShow = ::ShowWindow(hwnd, dCmdShow);

	if (CanShow)
		return TRUE;
	return FALSE;
}

HINSTANCE VisualHelp::GetInstance() {
	return mhInst;
}