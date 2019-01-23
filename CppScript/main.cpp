#include "CppScript.h"
#include <windows.h>
#include "Communal.h"
#include <assert.h>

int extFoo(int n)
{
	return n * 1000;
}

void main(int argc, char** argv)
{
	if (argc != 2)
	{
		printf("CppScript.exe scriptfile\n");
		return;
	}

	CppScript cs;
	cs.setWorkingDir("..\\..\\tmp");

	cs.addIncDir("..\\cl\\include\\SDK");
	cs.addIncDir("..\\cl\\include\\VC10");

#ifdef _WIN64
	cs.setCompilePath("..\\cl\\x64\\cl.exe");
	cs.setLinkPath("..\\cl\\x64\\link.exe");

	cs.addLibrary("..\\cl\\x64\\lib\\VC10\\LIBCMT.lib");
	cs.addLibrary("..\\cl\\x64\\lib\\VC10\\OLDNAMES.lib");
	cs.addLibrary("..\\cl\\x64\\lib\\VC10\\libcpmt.lib");
	cs.addLibrary("..\\cl\\x64\\lib\\SDK\\kernel32.lib");
	cs.addLibrary("..\\cl\\x64\\lib\\SDK\\uuid.lib");
	cs.addLibrary("..\\cl\\x64\\lib\\SDK\\User32.lib");
#else
	cs.setCompilePath("..\\cl\\x86\\cl.exe");
	cs.setLinkPath("..\\cl\\x86\\link.exe");

	cs.addLibrary("..\\cl\\x86\\lib\\VC10\\LIBCMT.lib");
	cs.addLibrary("..\\cl\\x86\\lib\\VC10\\OLDNAMES.lib");
	cs.addLibrary("..\\cl\\x86\\lib\\VC10\\libcpmt.lib");
	cs.addLibrary("..\\cl\\x86\\lib\\SDK\\kernel32.lib");
	cs.addLibrary("..\\cl\\x86\\lib\\SDK\\uuid.lib");
	cs.addLibrary("..\\cl\\x86\\lib\\SDK\\User32.lib");
#endif
	
#ifdef _DEBUG
	cs.setLinkOption("/DEBUG");
#endif

	std::string sResult;
	std::string sCpp = Communal::ReadText(argv[1]);
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
	if (!res)
	{
		cs.clean();
		return;
	}

	printf("==================%s===============\n", "USE");
	{//ʹ��
		CppScript::Context ct = cs.eval();

		printf("==================%d===============\n", 1);

		//std::vector<std::string> vctNames;
		//ct.getNames(vctNames);
		//for (int i = 0; i < vctNames.size(); ++i)
		//{
		//	void* p = ct.getAddress(vctNames[i]);
		//	printf("%s:%llu\n", vctNames[i].c_str(), (unsigned long long)p);
		//	assert(p);
		//}

		printf("==================%d===============\n", 2);

		//ȡscript������
		int* pMyData = (int *)ct.getAddress("myData");
		DWORD err = GetLastError();
		if (pMyData)
			printf("%d\n", *pMyData);

		printf("==================%d===============\n", 3);

		//�Ѻ�����scriptʹ��
		typedef int(*PFN_extFoo)(int n);
		PFN_extFoo* pPFN = (PFN_extFoo*)ct.getAddress("pfnExtFoo");
		if (pPFN)
			*pPFN = extFoo;

		printf("==================%d===============\n", 4);

		//����script�ĺ���
		typedef void(*PFN_printTest)();
		PFN_printTest pfnPrintTest = (PFN_printTest)ct.getAddress("printTest");
		if (pfnPrintTest)
			pfnPrintTest();

		printf("==================%d===============\n", 5);
	}

	system("pause");

	printf("==================%s===============\n", "CLEAN");
	//������ʱ�ļ�
	cs.clean();


	//CppScriptPack pack(&cs);
	//pack.init("G:\\test");
	//pack.testIncludes();
}