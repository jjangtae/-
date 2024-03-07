#include "std.h"

#define IDC_BUTTON1		1

HWND hButton;

// Ÿ�̸�
TCHAR infoText[50];

// ��Ʈ�� Button ����(���ڿ�)
TCHAR info[50];

//��µǴ� ����
TCHAR lastcolor[20] = _TEXT("����");
TCHAR lastshape[20] = _TEXT("���� �");

// �����ϸ鼭 ��ǥ �� + ���� + ���� �ʱ�ȭ
LRESULT CALLBACK OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	SetTimer(hwnd, 1, 1000, NULL);
	SendMessage(hwnd, WM_TIMER, 1, NULL); // ������ �ֱ�

	hButton = CreateWindow(TEXT("button"), TEXT("����"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 10, 100, 30, hwnd, (HMENU)IDC_BUTTON1, 0, 0);
	
	
	return 0;
}
// ����
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
		_tcscpy_s(lastcolor, _TEXT("����"));
		break;
	case 1:
		_tcscpy_s(lastcolor, _TEXT("����"));
		break;
	case 2:
		_tcscpy_s(lastcolor, _TEXT("�ʷ�"));
		break;
	case 3:
		_tcscpy_s(lastcolor, _TEXT("�Ķ�"));
		break;
	default:
		_tcscpy_s(lastcolor, _TEXT("Unknown"));
	}

	// ��� ���ڿ� ����
	switch (shape / 1)
	{
	case 0:
		_tcscpy_s(lastshape, _TEXT("���� �"));
		break;
	case 1:
		_tcscpy_s(lastshape, _TEXT("�簢��"));
		break;
	case 2:
		_tcscpy_s(lastshape, _TEXT("Ÿ��"));
		break;
	default:
		_tcscpy_s(lastshape, _TEXT("Unknown")); // ���� ó��
	}

	wsprintf(info, TEXT("������ ��ǥ : (%d, %d)   ���� : %s   ��� : %s"),
		end1.x, end1.y, lastcolor, lastshape);

	if (color == 0) // ��
	{
		if (GetCapture() == hwnd && shape == 0) // ���� �
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

		else if (GetCapture() == hwnd && shape == 1) // �簢��
		{
			HDC hdc = GetDC(hwnd);

			SetROP2(hdc, R2_NOTXORPEN);

			HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH); //���� �귯��
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

		else if (GetCapture() == hwnd && shape == 2) // Ÿ����
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
		if (GetCapture() == hwnd && shape == 0) // ���� �
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

		else if (GetCapture() == hwnd && shape == 1) // �簢��
		{
			HDC hdc = GetDC(hwnd);

			SetROP2(hdc, R2_NOTXORPEN);

			HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH); //���� �귯��
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

		else if (GetCapture() == hwnd && shape == 2) // Ÿ����
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
		if (GetCapture() == hwnd && shape == 0) // ���� �
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

		else if (GetCapture() == hwnd && shape == 1) // �簢��
		{
			HDC hdc = GetDC(hwnd);

			SetROP2(hdc, R2_NOTXORPEN);

			HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH); //���� �귯��
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

		else if (GetCapture() == hwnd && shape == 2) // Ÿ����
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
		if (GetCapture() == hwnd && shape == 0) // ���� �
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

		else if (GetCapture() == hwnd && shape == 1) // �簢��
		{
			HDC hdc = GetDC(hwnd);

			SetROP2(hdc, R2_NOTXORPEN);

			HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH); //���� �귯��
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

		else if (GetCapture() == hwnd && shape == 2) // Ÿ����
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
	// Ÿ�̸� �߻� �� �ð��� ���
	time_t rawtime;
	struct tm timeinfo;

	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	_stprintf_s(infoText, _T("���� �ð� : %02d:%02d:%02d"), timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
	SetWindowText(hwnd, infoText);
	return 0;
}


// ���� �ʿ� ���� �κ�
LRESULT CALLBACK OnDestroy(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
	return 0;
}

// �޴� �߰� + �޴� ���� �ٲٱ� + ���� �ٲٱ�
LRESULT CALLBACK OnContextmenu(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HMENU hmMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU2)); //���ҽ����� 

	HMENU hSubMenu = GetSubMenu(hmMenu, 0);

	POINT pt = { LOWORD(lParam), HIWORD(lParam) }; // ��ũ�� ��ǥ
	TrackPopupMenu(hSubMenu, TPM_LEFTBUTTON, pt.x, pt.y, 0, hwnd, 0);

	return 0;
}

LRESULT CALLBACK OnInitmenupopup(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HMENU hMenu = GetMenu(hwnd); 
	EnableMenuItem(hMenu, ID_40005, color == RGB(255, 0, 0) ? MF_GRAYED : MF_ENABLED); // ���� ���� �������̸� ��Ȱ��ȭ
	EnableMenuItem(hMenu, ID_40006, color == RGB(0, 255, 0) ? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hMenu, ID_40007, color == RGB(0, 0, 255) ? MF_GRAYED : MF_ENABLED);

	return 0;
}

LRESULT CALLBACK OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	// �޽���
	if (LOWORD(wParam) == IDC_BUTTON1)
	{
		TCHAR coordText[50];
		_stprintf_s(coordText, info, end1.x, end1.y, lastcolor, lastshape);
		MessageBox(hwnd, coordText, _TEXT("����"), MB_OK | MB_ICONINFORMATION);
	}

	// ����
	if (LOWORD(wParam) == ID_40002) // ���� �
	{
		shape = 0;
		InvalidateRect(hwnd, 0, false);
	}

	else if (LOWORD(wParam) == ID_40004) // Ÿ��
	{
		shape = 1;
		InvalidateRect(hwnd, 0, false);
	}

	else if (LOWORD(wParam) == ID_40003) // �簢��
	{
		shape = 2;
		InvalidateRect(hwnd, 0, false);
	}

	// ����
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