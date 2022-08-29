#pragma once
#include <Windows.h>
#include <string>

#define BUTTON 1


LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

MSG message;
HWND hWnd, hTitle, hDescription, hButtonOK, hEdit;
HFONT hFont;
