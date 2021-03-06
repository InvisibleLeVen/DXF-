#ifndef __UTILS_H__
#define __UTILS_H__
#include <ctime>
#include <string>
#include <iostream>
#include <tchar.h>
#include <windows.h>
#include <vector>

#define RED FOREGROUND_INTENSITY | FOREGROUND_RED
#define CYAN FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE
#define YELLOW FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN
#define PINK FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE
#define GREEN FOREGROUND_INTENSITY | FOREGROUND_GREEN

typedef struct _WINDOW_INFO
{
	int top = 0;
	int bottom = 0;
	int left = 0;
	int right = 0;
	int width = 0;
	int height = 0;
} WINDOW_INFO, *PWINDOW_INFO;

namespace utils
{
	void myprintf(const char * _Format, WORD Color = CYAN, ...);
	HWND getWindowHandle();
	WINDOW_INFO getWindowInfo(HWND hWnd);
	int createRandom(int min, int max);
	void randomSleep(int min, int max);
	void outputDbebugWString(const wchar_t * lpcszFormat, ...);
	void outputDbebugString(const char * lpcszFormat, ...);
	void windowInitialize();
	std::string formatString(const char * lpcszFormat, ...);
	std::wstring formatWstring(const wchar_t * lpcwszFormat, ...);
	void vectorBytesToBytes(std::vector<byte> v_bytes, byte * bytes);
	std::vector<byte> bytesToVectorBytes(byte * bytes, size_t size);
};
#endif



