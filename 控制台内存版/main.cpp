// 控制台内存版.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "call.h"
#include "send_packet.h"
#include "status_3.h"
#include "function.h"

int HotKeyId_END = 0;
int HotKeyId_HOME = 0;
int HotKeyId_F1 = 0;
SendPacket sp;

void exitProcess()
{
	int s = 3;
	UnregisterHotKey(NULL, HotKeyId_END);
	UnregisterHotKey(NULL, HotKeyId_HOME);
	msdk.closeHandle();
	utils::myprintf("msdk_handle close ...");
	rw2.closeHandle();
	utils::myprintf("rw2 close ...");
	//UN_PROTECT_FILE();
	
	while (s > 0) {
		utils::myprintf("程序将在 %d 秒后结束...",RED, s);
		s--;
		Sleep(1000);
	}
	exit(0);
}

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
			exitProcess();
		
		}
		else if (wParam == HotKeyId_HOME) {
			utils::myprintf("HotKeyId_HOME");
			rw2.Init();
			utils::myprintf("ProcessId->:%d\nProcessBaseAddress->:%x", GREEN, rw2.dwProcessId, rw2.dwProcessBaseAddress);
			msdk.openHandle();
			utils::myprintf("msdk_handle->:%x", GREEN, msdk.msdk_handle);
			
		}
		else if (wParam == HotKeyId_F1) {
			//sp.返回角色();
			//status_3::outputMapObjectInfo();
			utils::myprintf("status->:%d",RED,memory::read<int>(rw2.dwProcessBaseAddress));

		}
	default:
		break;
	}
}

void RegHotKeys()
{
	HotKeyId_END = GlobalAddAtom(L"HotKeyId_END") - 0xC000;
	HotKeyId_HOME = GlobalAddAtom(L"HotKeyId_HOME") - 0xC000;
	HotKeyId_HOME = GlobalAddAtom(L"HotKeyId_F1") - 0xC000;
	RegisterHotKey(NULL, HotKeyId_END, NULL, VK_END);
	RegisterHotKey(NULL, HotKeyId_HOME, NULL, VK_HOME);
	RegisterHotKey(NULL, HotKeyId_F1, NULL, VK_F1);
}


int main()
{
	utils::windowInitialize();
	RegHotKeys();
	//PROTECT_FILE();
	
	MSG msg;//消息指针
	while (GetMessage(&msg, NULL, 0, 0))
	{
		ThreadMessage(msg.message, msg.wParam, msg.lParam);//线程消息处理
		TranslateMessage(&msg);//等待信号
		DispatchMessage(&msg);//处理信号
	}
}


