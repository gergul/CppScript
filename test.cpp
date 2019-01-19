#include <iostream>
#include <string>

//���ڽ��� ������scriptʹ�õĺ���
typedef int(*PFN_extFoo)(int n);
C_DATA PFN_extFoo pfnExtFoo = NULL;

//����һ������������ʹ��
FUNC_API void printTest()
{
	int n = pfnExtFoo(123);
	std::cout << "printTest()" << std::to_string((long long)n) << std::endl;
}

//����һ�����ݸ�����ʹ��
C_DATA int myData = 123456;

//����һ�����͸�����ʹ�ã�������ô����Ҳ��֪��
class CLASS_API MyClass
{
public:
	MyClass()
	{

	}
	~MyClass()
	{

	}
	void printTest()
	{
		std::cout << "MyClass::printTest()" << std::endl;
	}
};

//������ڵ㣬Ҳ���Բ�����
DECLARE_ENTRY(MyEntry)
BOOL MyEntry(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		MessageBoxA(NULL, "DLL_PROCESS_ATTACH", "", 0);
		break;
	case DLL_PROCESS_DETACH:
		MessageBoxA(NULL, "DLL_PROCESS_DETACH", "", 0);
		break;
	case DLL_THREAD_ATTACH:
		MessageBoxA(NULL, "DLL_THREAD_ATTACH", "", 0);
		break;
	case DLL_THREAD_DETACH:
		MessageBoxA(NULL, "DLL_THREAD_DETACH", "", 0);
		break;
	default:
		break;
	}
	return TRUE;
}