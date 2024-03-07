#include "std.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	// 메뉴 추가 + 중복 금지 부분
	case WM_CONTEXTMENU:
	{
		return OnContextmenu(hwnd, wParam, lParam);
	}

	case WM_INITMENUPOPUP:
	{
		return OnInitmenupopup(hwnd, wParam, lParam);
	}

	case WM_COMMAND:
	{
		return OnCommand(hwnd, wParam, lParam);
	}
	
	case WM_LBUTTONUP:
	{
		return OnLButtonup(hwnd, wParam, lParam);
	}

	case WM_MOUSEMOVE:
	{
		return OnMousemove(hwnd, wParam, lParam);
	}

	case WM_LBUTTONDOWN:
	{
		return OnLButtonDown(hwnd, wParam, lParam);
	}
	
	case WM_TIMER:
	{
		return OnTimer(hwnd, wParam, lParam);
	}

	// 시작
	case WM_CREATE:
	{
		OnTimer;
		return OnCreate(hwnd, wParam, lParam);
	}

	// 파괴 (수정할 필요 X)
	case WM_DESTROY:

		return OnDestroy(hwnd, wParam, lParam);
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}


int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd)
{
	WNDCLASS wc;
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = TEXT("First");
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wc.style = 0;

	RegisterClass(&wc);

	HWND hwnd = CreateWindowEx(0, TEXT("First"), TEXT("DC실습_0307"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, 0, 0, hInst, 0);

	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}