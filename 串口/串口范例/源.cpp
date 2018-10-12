

#include <locale.h>
#include <iostream>
#include <string>

#include "..\CnComm.h"
using namespace std;

//! 样例程序0
class HelloComm : public CnComm
{	//! \sa CnComm::OnReceive()
	void OnReceive()
	{
		TCHAR buffer[1024];
		setlocale(LC_ALL, "chs");// Unicode下中文显示不出 配置一下 CBC 不支持 "chs"
		_tprintf(_T("\nRecv:%s\n"), ReadString(buffer, 1024));
	}
};
//! Main()  COM1 ---字符串----> COM4 (波特率9600)
int main()
{
	HelloComm Com;//! 默认模式 重叠IO 监视线程
	int CP = 4;
	Com.Open(CP, 9600);

	std::cout << "Com:" << CP <<"已打开"<< std::endl;
	system("pause");//暂停
	while (1) {
		//传char[]给arduino
		string str;
		cin >> str;
		char c[20];
		const char *c_str();
		strcpy_s(c,str.c_str());

		if (str == "quit")break;//输入quit退出传输
		Com.Write(_T(c));

		
	}
	std::cout << "Com:" << CP << "即将关闭" << std::endl;
	system("pause");//暂停

	return 0;
}

