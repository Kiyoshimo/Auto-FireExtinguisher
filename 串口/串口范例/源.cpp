

#include <locale.h>
#include <iostream>
#include <string>

#include "..\CnComm.h"
using namespace std;

//! ��������0
class HelloComm : public CnComm
{	//! \sa CnComm::OnReceive()
	void OnReceive()
	{
		TCHAR buffer[1024];
		setlocale(LC_ALL, "chs");// Unicode��������ʾ���� ����һ�� CBC ��֧�� "chs"
		_tprintf(_T("\nRecv:%s\n"), ReadString(buffer, 1024));
	}
};
//! Main()  COM1 ---�ַ���----> COM4 (������9600)
int main()
{
	HelloComm Com;//! Ĭ��ģʽ �ص�IO �����߳�
	int CP = 4;
	Com.Open(CP, 9600);

	std::cout << "Com:" << CP <<"�Ѵ�"<< std::endl;
	system("pause");//��ͣ
	while (1) {
		//��char[]��arduino
		string str;
		cin >> str;
		char c[20];
		const char *c_str();
		strcpy_s(c,str.c_str());

		if (str == "quit")break;//����quit�˳�����
		Com.Write(_T(c));

		
	}
	std::cout << "Com:" << CP << "�����ر�" << std::endl;
	system("pause");//��ͣ

	return 0;
}

