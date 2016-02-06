#ifndef VISUALHELP_H
#define VISUALHELP_H

#include <windows.h>

class VisualHelp
{
public:
	VisualHelp();
	virtual ~VisualHelp();
	HINSTANCE GetInstance();

	HWND Create(HINSTANCE hinst, LPCTSTR clsname,
		LPCTSTR wndname, HWND parent = NULL,
		DWORD dStyle = WS_OVERLAPPEDWINDOW,
		int x = CW_USEDEFAULT, int y = CW_USEDEFAULT,
		int width = 450, int height = 380);
	BOOL Show(int dCmdShow = SW_SHOWNORMAL);
	operator HWND();

protected:
	HWND hwnd;
	HINSTANCE mhInst;
};
#endif	