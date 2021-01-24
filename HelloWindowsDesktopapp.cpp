#include <windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <string.h>


static TCHAR szWindowClass[] = _T("DesktopApp");

static TCHAR szTitle[] = _T("Windows Desktop Guided Tour Application");

HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(
		_In_ HINSTANCE hInstance,
		_In_opt_ HINSTANCE hPrevInstance,
		_In_ LPSTR	lpCmdLine,
		_In_ int	nCmdShow
)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = WndProc;
	wcex.cdClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex)){
		MessageBox(NULL, _T("Call to RegisterClassEx failed!"),_T("Windows Desktop Guided Tour"), NULL);
		return 1;
	}
	hInst = hInstance;

	HWND hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFUALT, 500,100,NULL,NULL,hInstance,NULL);

	if (!hWnd){
		MessageBox(Null,_T("Call to CreateWindow failed!"),_T("Windows Desktop Guided Tour"), NULL);
		return 1;
	}
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);
	MSG msg;
	return (int) msg.wPram;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lPram){
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("Hello, Windows desktop!");
	switch (message){
		case WM_PAINT:
			hdc=BeginPaint(hWnd,&ps);
			TextOut(hdc,5,5,greeting, _tcslen(greeting));
			EndPaint(hWnd, &ps);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return defWindowProc(hWnd, message, wParam, lParam);
			break;
		}
}
return 0;
}

