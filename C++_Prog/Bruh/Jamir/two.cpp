// Some macro definitions, not needed for our current project, but you are quite likely to run into situations when they are useful.
#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

// You do not need any of the above, but it can get useful, see the link or, if the link is dead, google the term "#ifndef UNICODE"

// This is where the interesting stuff starts:
// First, we need access to the Windows API (Application Programming Interface):
#include <windows.h>

/*
	HDC = Handle to Device Context
	
	Device Context, as defined on Microsoft Docs: 

		A device context is a structure that defines a set of graphic objects and 
		their associated attributes, as well as the graphic modes that affect output.
*/
HDC hdc_main; // Represents our physical device
HDC hdc_comp; // A virtual device which we will use to draw "behind the scenes"

// A pointer to the buffer that we will be using to play with pixels =) 
DWORD* window_bmp_p;

// The Windows API specific bitmap 
HBITMAP whole_screen; // Handle to a bitmap
BITMAPINFO bmi; // A data struct holding info necessary to create a bitmap

// Windows requires this to draw:
PAINTSTRUCT ps;

int screenw = GetSystemMetrics(SM_CXSCREEN);
int screenh = GetSystemMetrics(SM_CYSCREEN);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void MakeBitMap(HWND hwnd, HBITMAP* Bitmap, BITMAPINFO Bmi, DWORD** window_p, int Width, int Height)
{
	// Create the bitmap info header:
	Bmi.bmiHeader.biSize = sizeof(Bmi.bmiHeader);
	Bmi.bmiHeader.biWidth = Width;
	Bmi.bmiHeader.biHeight = -Height;
	Bmi.bmiHeader.biPlanes = 1;
	Bmi.bmiHeader.biBitCount = GetDeviceCaps(GetDC(hwnd), BITSPIXEL);
	Bmi.bmiHeader.biCompression = BI_RGB;
	Bmi.bmiHeader.biSizeImage = 0;
	Bmi.bmiHeader.biXPelsPerMeter = 0;
	Bmi.bmiHeader.biYPelsPerMeter = 0;
	Bmi.bmiHeader.biClrUsed = 0;
	Bmi.bmiHeader.biClrImportant = 0;

	// DIB = Device Independent Bitmap, a bitmap we can use regardless of device:
	*Bitmap = CreateDIBSection 
	(
		GetDC(hwnd),
		&Bmi,
		DIB_RGB_COLORS,
		(void**)window_p,
		0,
		0
	);

	// Get a handle (pointer) to the bits of the bitmap:
	GetDIBits
	(
		GetDC(hwnd),
		*Bitmap,
		0,
		Height,
		*window_p,
		&Bmi,
		DIB_RGB_COLORS
	);

	// Write some colour value to the buffer:
	DWORD* ws_cpy = *window_p; // This creates a local copy of our bitmap pointer
	int MapSize = Width * Height; // Just to be explicit, probably would get optimized to this by compiler
	for (int c = 0; c < MapSize; c++) ws_cpy[c] = 0x0000aaff; // aRGB in hexadecimal format
}

void Prepare_Screen(HWND hwnd)
{
	MakeBitMap(hwnd, &whole_screen, bmi, &window_bmp_p, screenw, screenh);
	hdc_main = GetDC(hwnd);
	hdc_comp = CreateCompatibleDC(hdc_main);
	SelectObject(hdc_comp, whole_screen);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow)
{
	// Register the window class:
	const wchar_t CLASS_NAME[] = L"TheWindowClass";

	WNDCLASS wc = { 0 };

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	//ShowCursor(false);

	// Create the window:
	/*
		The "Ex" suffix inf "CreateWindowEx" allows us to use "extended window styles" (the first argument). 
		Not actually required for what we are doing, but you might find it fun to play with.
		If you want to, you can just use "Create Window" and omit the first argument.
	*/ 
	HWND hwnd = CreateWindowEx( 
		WS_EX_TRANSPARENT, //WS_EX_TRANSPARENT, WS_EX_OVERLAPPEDWINDOW  // Optional, "extended" window styles.
		CLASS_NAME,                     // Window class
		L"YT_Tutorial",					// Window text
		WS_POPUP | WS_VISIBLE,			// Window style

		// Position and size:
		0, 0,
		GetSystemMetrics(SM_CXSCREEN), // 400
		GetSystemMetrics(SM_CYSCREEN), // 600

		// Just leave this as is:
		NULL,       // Parent window
		NULL,       // Menu
		hInstance,  // Instance handle
		NULL        // Additional application data
	);

	Prepare_Screen(hwnd);

	ShowWindow(hwnd, nCmdShow);

	// Run the message loop:
	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

// This is where the messages are handled. As you expand your program, you will essentially use this as your starting point (tutorial upcoming).
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	BitBlt(BeginPaint(hwnd, &ps), 0, 0, screenw, screenh, hdc_comp, 0, 0, SRCCOPY);
	EndPaint(hwnd, &ps);

	RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE);

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}