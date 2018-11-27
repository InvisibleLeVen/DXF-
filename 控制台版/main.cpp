// 控制台版.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

//Driver driver;
RW2 rw2;
int main()
{
	rw2.Init();
	DWORD address = rw2.dwProcessBaseAddress + 0x846290;//0x633000;
	printf("address %x\n", address);

	printf("value %d\n",rw2.read<DWORD>(address));

	std::wstring wstr = rw2.readWString(address, 100);
	std::wcout.imbue(std::locale("chs"));
	std::wcout << "wstr->:" << wstr.c_str() << "\n";

	std::string str = rw2.readString(address,100);
	std::cout << "str->:" << str.c_str() << "\n";
	printf("str->: %s \n",str.c_str());

	std::vector<byte> bytes = rw2.readBytes(address, 1000);
	for (size_t i = 0; i < 1000; i++)
	{
		printf("%02x ", bytes[i]);

	}
	printf("\n");

	//rw2.writeBytes(address, {1,0,0,0,0,0,0,0,0,0x11});

	//rw2.write(address,100);

	system("pause");
}


