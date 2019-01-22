#include "CppScript.h"
#include <windows.h>
#include "Communal.h"
#include <assert.h>

int extFoo(int n)
{
	return n * 1000;
}

void main()
{
	CppScript cs;
	cs.setWorkingDir("..\\..\\tmp");

	cs.addIncDir("..\\cl\\include\\SDK");
	cs.addIncDir("..\\cl\\include\\VC10");

#ifdef _WIN64
	cs.setCompilePath("..\\cl\\x86_amd64\\cl.exe");
	cs.setLinkPath("..\\cl\\x86_amd64\\link.exe");

	cs.addLibrary("..\\cl\\lib\\x64\\VC10\\LIBCMT.lib");
	cs.addLibrary("..\\cl\\lib\\x64\\VC10\\OLDNAMES.lib");
	cs.addLibrary("..\\cl\\lib\\x64\\VC10\\libcpmt.lib");
	cs.addLibrary("..\\cl\\lib\\x64\\SDK\\kernel32.lib");
	cs.addLibrary("..\\cl\\lib\\x64\\SDK\\uuid.lib");
	cs.addLibrary("..\\cl\\lib\\x64\\SDK\\User32.lib");
#else
	cs.setCompilePath("..\\cl\\cl.exe");
	cs.setLinkPath("..\\cl\\link.exe");

	cs.addLibrary("..\\cl\\lib\\x86\\VC10\\LIBCMT.lib");
	cs.addLibrary("..\\cl\\lib\\x86\\VC10\\OLDNAMES.lib");
	cs.addLibrary("..\\cl\\lib\\x86\\VC10\\libcpmt.lib");
	cs.addLibrary("..\\cl\\lib\\x86\\SDK\\kernel32.lib");
	cs.addLibrary("..\\cl\\lib\\x86\\SDK\\uuid.lib");
	cs.addLibrary("..\\cl\\lib\\x86\\SDK\\User32.lib");
#endif
	
	std::string sResult;
	std::string sCpp = Communal::ReadText("..\\..\\test.cpp");
	printf("==================%s===============\n", "COMPILE");
	bool res = cs.compile(sCpp, &sResult);
	printf(sResult.c_str());
	if (!res)
	{
		cs.clean();
		return;
	}

	printf("==================%s===============\n", "LINK");
	res = cs.link(&sResult);
	printf(sResult.c_str());
	if (!res)//259������GetLastError�еĴ����룺û�п��õ������ˣ������еĶ��Ѿ����꣬û�п��õ����ݿ��Բ����ˣ����Է��أ��Ҳµģ�
	{
		cs.clean();
		return;
	}

	printf("==================%s===============\n", "USE");
	{//ʹ��
		CppScript::Context ct = cs.eval();

		std::vector<std::string> vctNames;
		ct.getNames(vctNames);
		for (int i = 0; i < vctNames.size(); ++i)
		{
			void* p = ct.getAddress(vctNames[i]);
			printf("%s:%llu\n", vctNames[i].c_str(), (unsigned long long)p);
			assert(p);
		}

		//ȡscript������
		int* pMyData = (int *)ct.getAddress("myData");
		DWORD err = GetLastError();
		if (pMyData)
			printf("%d\n", *pMyData);

		//�Ѻ�����scriptʹ��
		typedef int(*PFN_extFoo)(int n);
		PFN_extFoo* pPFN = (PFN_extFoo*)ct.getAddress("pfnExtFoo");
		if (pPFN)
			*pPFN = extFoo;

		//����script�ĺ���
		typedef void(*PFN_printTest)();
		PFN_printTest pfnPrintTest = (PFN_printTest)ct.getAddress("printTest");
		if (pfnPrintTest)
			pfnPrintTest();
	}

	system("pause");

	printf("==================%s===============\n", "CLEAN");
	//������ʱ�ļ�
	cs.clean();


	//CppScriptPack pack(&cs);
	//pack.init("G:\\test");
	//pack.testIncludes();
}