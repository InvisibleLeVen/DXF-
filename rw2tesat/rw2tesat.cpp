// rw2tesat.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <windows.h>
#include <stdio.h>
#include "../RW2/rw2api.h"
int main()
{
	HANDLE hDriver = CreateFile(
		L"\\\\.\\" SYMBOLIC_LINK_SHORT_NAME,
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		0,
		OPEN_EXISTING,
		0,
		0
	);
	if (hDriver == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, L"#驱动链接失败,解决办法如下\n\n#家庭用户请关闭安全软件\n#网吧请干掉网吧防火墙回调\n\n#如果以上方法没有解决您的问题请重启电脑管理员身份运行", NULL, NULL);
		exit(0);
	}
	int a = 0;
	READ_VIRTUAL_MEMORY_STRUCT rvms;
	rvms.Response = &a;
	rvms.Address = 0x00946290;
	rvms.Size = sizeof(int);
	DeviceIoControl(hDriver, READ_VIRTUAL_MEMORY, &rvms, sizeof(rvms), &rvms, sizeof(rvms), 0, 0);
	printf("a %d",a);
	system("pause");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
