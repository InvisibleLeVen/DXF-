// 控制台版.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "rw2.h"
// 全局变量的声明

bool g_auto_switch;//自动开关
int HotKeyId_END = 0;
int HotKeyId_HOME = 0;

VOID ThreadMessage(
	UINT message,
	WPARAM wParam,
	LPARAM lParam
)
{
	switch (message)
	{
	case WM_HOTKEY:
		if (wParam == HotKeyId_END)
		{
			utils::myprintf("HotKeyId_END");

			UnregisterHotKey(NULL, HotKeyId_END);
			UnregisterHotKey(NULL, HotKeyId_HOME);
			utils::processExit();
		}
		else if (wParam == HotKeyId_HOME) {
			utils::myprintf("HotKeyId_HOME");
		}
	default:
		break;
	}
}

void RegHotKeys()
{
	HotKeyId_END = GlobalAddAtom(L"HotKeyId_END") - 0xC000;
	HotKeyId_HOME = GlobalAddAtom(L"HotKeyId_HOME") - 0xC000;

	RegisterHotKey(NULL, HotKeyId_END, NULL, VK_END);
	RegisterHotKey(NULL, HotKeyId_HOME, NULL, VK_HOME);
}

int main()
{
	//rw2.Init();
	utils::windowInitialize();
	utils::msdkInit();
	RegHotKeys();

	MSG msg;//消息指针
	while (GetMessage(&msg, NULL, 0, 0))
	{
		ThreadMessage(msg.message, msg.wParam, msg.lParam);//线程消息处理
		TranslateMessage(&msg);//等待信号
		DispatchMessage(&msg);//处理信号
	}
}


