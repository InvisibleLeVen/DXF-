// 控制台版.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

Driver driver;
int main()
{
	////driversss.Init();
	//hDriver = GetDriverHandle();
	///*TargetProcessId = GetTargetProcessId();
	//utils::myprintf("TargetProcessId %d", CYAN, TargetProcessId);*/
	//int value = read<int>(0x009FB570);
	//utils::myprintf("value %d",CYAN, value);
	//////write<DWORD>(0x00AEB570,100);
	////utils::myprintf("string %s", CYAN, read_string(0x008EB570, 100).c_str());
	////printf("wstring %Ls\n", read_wstring(0x008EB570,100).c_str());
	//wchar_t wstr[100] = { 0 };
	//read_wstring(0x009FB570, wstr,100);
	////printf("wstring %ls\n", wstr);
	////wsprintf("wstring %ls\n", L"啊啊啊");
	////swprintf_s();
	//std::wcout.imbue(std::locale("chs"));
	//std::wcout << wstr << std::endl;
	//std::wcout << L"啊啊啊" << std::endl;

	std::wcout.imbue(std::locale("chs"));

	DWORD value = driver.RPM<DWORD>(0x009FB570);
	std::cout << "value" << value << std::endl;
	wchar_t wstr[100] = { 0 };
	driver.ReadStr(0x009FB570, wstr,100);
	std::wcout << "wstr " << wstr << std::endl;
	int i = 0;
	while (true)
	{
		driver.RPM<DWORD>(0x009FB570);
		std::cout << "第" << i << "次 value" << value << std::endl;
		i++;
	}
	
	system("pause");
}


