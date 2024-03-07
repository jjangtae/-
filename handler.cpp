#include "std.h"

#define IDC_BUTTON1		1

HWND hButton;

// 타이머
TCHAR infoText[50];

// 컨트롤 Button 정보(문자열)
TCHAR info[50];

//출력되는 정보
TCHAR lastcolor[20] = _TEXT("검정");
TCHAR lastshape[20] = _TEXT("자유 곡선");

// 시작하면서 좌표 값 + 색상 + 도형 초기화
LRESULT CALLBACK OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	SetTimer(hwnd, 1, 1000, NULL);
	SendMessage(hwnd, WM_TIMER, 1, NULL); // 강제로 주기

	hButton = CreateWindow(TEXT("button"), TEXT("정보"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 10, 100, 30, hwnd, (HMENU)IDC_BUTTON1, 0, 0);
	
	
	return 0;
}
// 수정
LRESULT CALLBACK OnLButtonup(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	SetCapture(0);

	return 0;
}

LRESULT CALLBACK OnMousemove(HWND hwnd, WPARAM wParam, LPARAM lParam)
{	
	switch (color / 1)
	{
	case 0:
		_tcscpy_s(lastcolor, _TEXT("검정"));
		break;
	case 1:
		_tcscpy_s(lastcolor, _TEXT("빨강"));
		break;
	case 2:
		_tcscpy_s(lastcolor, _TEXT("초록"));
		break;
	case 3:
		_tcscpy_s(lastcolor, _TEXT("파랑"));
		break;
	default:
		_tcscpy_s(lastcolor, _TEXT("Unknown"));
	}

	// 모양 문자열 설정
	switch (shape / 1)
	{
	case 0:
		_tcscpy_s(lastshape, _TEXT("자유 곡선"));
		break;
	case 1:
		_tcscpy_s(lastshape, _TEXT("사각형"));
		break;
	case 2:
		_tcscpy_s(lastshape, _TEXT("타원"));
		break;
	default:
		_tcscpy_s(lastshape, _TEXT("Unknown")); // 예외 처리
	}

	wsprintf(info, TEXT("마지막 좌표 : (%d, %d)   색깔 : %s   모양 : %s"),
		end1.x, end1.y, lastcolor, lastshape);

	if (color == 0) // 색
	{
		if (GetCapture() == hwnd && shape == 0) // 자유 곡선
		{
			HDC hdc = GetDC(hwnd);

			HPEN pen0 = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
			HPEN oldpen0 = (HPEN)SelectObject(hdc, pen0);

			MoveToEx(hdc, end1.x, end1.y, NULL);

			end1 = MAKEPOINTS(lParam);

			LineTo(hdc, end1.x, end1.y);

			SelectObject(hdc, oldpen0);
			DeleteObject(SelectObject(hdc, oldpen0));
			ReleaseDC(hwnd, hdc);
		}

		else if (GetCapture() == hwnd && shape == 1) // 사각형
		{
			HDC hdc = GetDC(hwnd);

			SetROP2(hdc, R2_NOTXORPEN);

			HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH); //투명 브러쉬
			HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

			HPEN pen0 = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
			HPEN oldpen0 = (HPEN)SelectObject(hdc, pen0);

			Rectangle(hdc, start.x, start.y, end1.x, end1.y);

			end1 = MAKEPOINTS(lParam);
			Rectangle(hdc, start.x, start.y, end1.x, end1.y);

			SelectObject(hdc, oldpen0);
			DeleteObject(SelectObject(hdc, oldpen0));
			ReleaseDC(hwnd, hdc);
		}

		else if (GetCapture() == hwnd && shape == 2) // 타원형
		{
			HDC hdc = GetDC(hwnd);

			SetROP2(hdc, R2_NOTXORPEN);

			HPEN pen0 = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
			HPEN oldpen0 = (HPEN)SelectObject(hdc, pen0);

			Ellipse(hdc, start.x, start.y, end1.x, end1.y);

			end1 = MAKEPOINTS(lParam);
			Ellipse(hdc, start.x, start.y, end1.x, end1.y);

			SelectObject(hdc, oldpen0);
			DeleteObject(SelectObject(hdc, oldpen0));
			ReleaseDC(hwnd, hdc);
		}
	}

	if (color == 1)
	{
		if (GetCapture() == hwnd && shape == 0) // 자유 곡선
		{
			HDC hdc = GetDC(hwnd);

			HPEN pen0 = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
			HPEN oldpen0 = (HPEN)SelectObject(hdc, pen0);

			MoveToEx(hdc, end1.x, end1.y, NULL);

			end1 = MAKEPOINTS(lParam);

			LineTo(hdc, end1.x, end1.y);

			SelectObject(hdc, oldpen0);
			DeleteObject(SelectObject(hdc, oldpen0));
			ReleaseDC(hwnd, hdc);
		}

		else if (GetCapture() == hwnd && shape == 1) // 사각형
		{
			HDC hdc = GetDC(hwnd);

			SetROP2(hdc, R2_NOTXORPEN);

			HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH); //투명 브러쉬
			HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

			HPEN pen0 = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
			HPEN oldpen0 = (HPEN)SelectObject(hdc, pen0);

			Rectangle(hdc, start.x, start.y, end1.x, end1.y);

			end1 = MAKEPOINTS(lParam);
			Rectangle(hdc, start.x, start.y, end1.x, end1.y);

			SelectObject(hdc, oldpen0);
			DeleteObject(SelectObject(hdc, oldpen0));
			ReleaseDC(hwnd, hdc);
		}

		else if (GetCapture() == hwnd && shape == 2) // 타원형
		{
			HDC hdc = GetDC(hwnd);

			SetROP2(hdc, R2_NOTXORPEN);

			HPEN pen0 = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
			HPEN oldpen0 = (HPEN)SelectObject(hdc, pen0);

			Ellipse(hdc, start.x, start.y, end1.x, end1.y);

			end1 = MAKEPOINTS(lParam);
			Ellipse(hdc, start.x, start.y, end1.x, end1.y);

			SelectObject(hdc, oldpen0);
			DeleteObject(SelectObject(hdc, oldpen0));
			ReleaseDC(hwnd, hdc);
		}

	}

	if (color == 2)
	{
		if (GetCapture() == hwnd && shape == 0) // 자유 곡선
		{
			HDC hdc = GetDC(hwnd);

			HPEN pen0 = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
			HPEN oldpen0 = (HPEN)SelectObject(hdc, pen0);

			MoveToEx(hdc, end1.x, end1.y, NULL);

			end1 = MAKEPOINTS(lParam);

			LineTo(hdc, end1.x, end1.y);

			SelectObject(hdc, oldpen0);
			DeleteObject(SelectObject(hdc, oldpen0));
			ReleaseDC(hwnd, hdc);
		}

		else if (GetCapture() == hwnd && shape == 1) // 사각형
		{
			HDC hdc = GetDC(hwnd);

			SetROP2(hdc, R2_NOTXORPEN);

			HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH); //투명 브러쉬
			HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

			HPEN pen0 = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
			HPEN oldpen0 = (HPEN)SelectObject(hdc, pen0);

			Rectangle(hdc, start.x, start.y, end1.x, end1.y);

			end1 = MAKEPOINTS(lParam);
			Rectangle(hdc, start.x, start.y, end1.x, end1.y);

			SelectObject(hdc, oldpen0);
			DeleteObject(SelectObject(hdc, oldpen0));
			ReleaseDC(hwnd, hdc);
		}

		else if (GetCapture() == hwnd && shape == 2) // 타원형
		{
			HDC hdc = GetDC(hwnd);

			SetROP2(hdc, R2_NOTXORPEN);

			HPEN pen0 = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
			HPEN oldpen0 = (HPEN)SelectObject(hdc, pen0);

			Ellipse(hdc, start.x, start.y, end1.x, end1.y);

			end1 = MAKEPOINTS(lParam);
			Ellipse(hdc, start.x, start.y, end1.x, end1.y);

			SelectObject(hdc, oldpen0);
			DeleteObject(SelectObject(hdc, oldpen0));
			ReleaseDC(hwnd, hdc);
		}

	}

	if (color == 3)
	{
		if (GetCapture() == hwnd && shape == 0) // 자유 곡선
		{
			HDC hdc = GetDC(hwnd);

			HPEN pen0 = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
			HPEN oldpen0 = (HPEN)SelectObject(hdc, pen0);

			MoveToEx(hdc, end1.x, end1.y, NULL);

			end1 = MAKEPOINTS(lParam);

			LineTo(hdc, end1.x, end1.y);

			SelectObject(hdc, oldpen0);
			DeleteObject(SelectObject(hdc, oldpen0));
			ReleaseDC(hwnd, hdc);
		}

		else if (GetCapture() == hwnd && shape == 1) // 사각형
		{
			HDC hdc = GetDC(hwnd);

			SetROP2(hdc, R2_NOTXORPEN);

			HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH); //투명 브러쉬
			HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

			HPEN pen0 = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
			HPEN oldpen0 = (HPEN)SelectObject(hdc, pen0);

			Rectangle(hdc, start.x, start.y, end1.x, end1.y);

			end1 = MAKEPOINTS(lParam);
			Rectangle(hdc, start.x, start.y, end1.x, end1.y);

			SelectObject(hdc, oldpen0);
			DeleteObject(SelectObject(hdc, oldpen0));
			ReleaseDC(hwnd, hdc);
		}

		else if (GetCapture() == hwnd && shape == 2) // 타원형
		{
			HDC hdc = GetDC(hwnd);

			SetROP2(hdc, R2_NOTXORPEN);

			HPEN pen0 = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
			HPEN oldpen0 = (HPEN)SelectObject(hdc, pen0);

			Ellipse(hdc, start.x, start.y, end1.x, end1.y);

			end1 = MAKEPOINTS(lParam);
			Ellipse(hdc, start.x, start.y, end1.x, end1.y);

			SelectObject(hdc, oldpen0);
			DeleteObject(SelectObject(hdc, oldpen0));
			ReleaseDC(hwnd, hdc);
		}

	}

	return 0;
}

LRESULT CALLBACK OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	start = end1 = MAKEPOINTS(lParam);
	SetCapture(hwnd);

	return 0;
}

LRESULT CALLBACK OnTimer(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	// 타이머 발생 시 시간을 출력
	time_t rawtime;
	struct tm timeinfo;

	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	_stprintf_s(infoText, _T("현재 시간 : %02d:%02d:%02d"), timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
	SetWindowText(hwnd, infoText);
	return 0;
}


// 수정 필요 없는 부분
LRESULT CALLBACK OnDestroy(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
	return 0;
}

// 메뉴 추가 + 메뉴 색깔 바꾸기 + 도형 바꾸기
LRESULT CALLBACK OnContextmenu(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HMENU hmMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU2)); //리소스에서 

	HMENU hSubMenu = GetSubMenu(hmMenu, 0);

	POINT pt = { LOWORD(lParam), HIWORD(lParam) }; // 스크린 좌표
	TrackPopupMenu(hSubMenu, TPM_LEFTBUTTON, pt.x, pt.y, 0, hwnd, 0);

	return 0;
}

LRESULT CALLBACK OnInitmenupopup(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HMENU hMenu = GetMenu(hwnd); 
	EnableMenuItem(hMenu, ID_40005, color == RGB(255, 0, 0) ? MF_GRAYED : MF_ENABLED); // 현재 색이 빨강색이면 비활성화
	EnableMenuItem(hMenu, ID_40006, color == RGB(0, 255, 0) ? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hMenu, ID_40007, color == RGB(0, 0, 255) ? MF_GRAYED : MF_ENABLED);

	return 0;
}

LRESULT CALLBACK OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	// 메시지
	if (LOWORD(wParam) == IDC_BUTTON1)
	{
		TCHAR coordText[50];
		_stprintf_s(coordText, info, end1.x, end1.y, lastcolor, lastshape);
		MessageBox(hwnd, coordText, _TEXT("정보"), MB_OK | MB_ICONINFORMATION);
	}

	// 도형
	if (LOWORD(wParam) == ID_40002) // 자유 곡선
	{
		shape = 0;
		InvalidateRect(hwnd, 0, false);
	}

	else if (LOWORD(wParam) == ID_40004) // 타원
	{
		shape = 1;
		InvalidateRect(hwnd, 0, false);
	}

	else if (LOWORD(wParam) == ID_40003) // 사각형
	{
		shape = 2;
		InvalidateRect(hwnd, 0, false);
	}

	// 색상
	else if (LOWORD(wParam) == ID_40014)
	{
		color = 1;
		InvalidateRect(hwnd, 0, false);
	}

	else if (LOWORD(wParam) == ID_40015)
	{
		color = 2;
		InvalidateRect(hwnd, 0, false);
	}

	else if (LOWORD(wParam) == ID_40016)
	{
		color = 3;
		InvalidateRect(hwnd, 0, false);
	}

	else if (LOWORD(wParam) == ID_40017)
	{
		color = 0;
		InvalidateRect(hwnd, 0, false);
	}

	else if (LOWORD(wParam) == ID_40001)
	{
		SendMessage(hwnd, WM_CLOSE, 0, 0);
	}

	return 0;
}