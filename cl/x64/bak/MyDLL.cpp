// MyDLL.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "MyDLL.h"
#include <vector>


// ���ǵ���������һ��ʾ��
MYDLL_API int nMyDLL=0;

// ���ǵ���������һ��ʾ����
MYDLL_API int fnMyDLL(void)
{
	std::vector<int> vct;
	vct.push_back(0);
	vct.push_back(1);
	vct.push_back(2);
	vct.push_back(3);
    return vct[0];
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� MyDLL.h
CMyDLL::CMyDLL()
{
    return;
}
