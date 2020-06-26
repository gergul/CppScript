
#include "CPP_COM.H"
#include <iostream>
#include <string>
#include "subScript.h"

//���ڽ��� ������scriptʹ�õĺ���
typedef int(*PFN_extFoo)(int n);
C_DATA PFN_extFoo pfnExtFoo = NULL;

//����һ������������ʹ��
FUNC_API void printTest()
{
	if (pfnExtFoo)
	{
		int n = pfnExtFoo(123);
		std::cout << "compute use C function():" << std::to_string((long long)n) << std::endl;
	}
	subfoo1("test sub script foo.");
}

//����һ�����ݸ�����ʹ��
C_DATA int myData = 123456;

class MyClass
{
public:
	MyClass()
	{

	}
	virtual ~MyClass()
	{

	}

	void _printTest()
	{
		std::cout << "MyClass::_printTest()" << std::endl;
	}

	virtual void printTest()
	{
		std::cout << "MyClass::printTest()" << std::endl;
		_printTest();
	}
	
};
//����һ�����͸�����ʹ�ã�����ֻ���麯������C����
FUNC_API MyClass* create_MyClass(/*���캯������*/)
{
	return new MyClass(/*���캯������*/);
}

extern "C" BOOL WINAPI DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		printf("================DLL_PROCESS_ATTACH================\n");

		printf("�ű�Ψһ��ʶ:%s\n", SCRIPT_ID);
#if (defined MY_DEF) && (MY_DEF == 1)
		//MessageBoxA(NULL, "MY_DEF", SCRIPT_ID, 0);
		printf("MY_DEF=%d\n", MY_DEF);
#endif
		break;
	case DLL_PROCESS_DETACH:
		printf("================DLL_PROCESS_DETACH================\n");
		break;
	case DLL_THREAD_ATTACH:
		printf("================DLL_THREAD_ATTACH================\n");
		break;
	case DLL_THREAD_DETACH:
		printf("================DLL_THREAD_DETACH================\n");
		break;
	default:
		break;
	}
	
	return TRUE;
}