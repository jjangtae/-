#pragma once

LRESULT CALLBACK OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK OnDestroy(HWND hwnd, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK OnLButtonup(HWND hwnd, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK OnMousemove(HWND hwnd, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK OnContextmenu(HWND hwnd, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK OnInitmenupopup(HWND hwnd, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK OnTimer(HWND hwnd, WPARAM wParam, LPARAM lParam);