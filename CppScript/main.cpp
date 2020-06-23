#include "CppScript.h"
#include <windows.h>
#include "Communal.h"
#include <assert.h>

class MyClass//��Ӧscript�����MyClass����Ҫ�������������� script�����MyClass���麯�� �������麯����λ��˳��Ҫ��һ��
{
public:
	virtual ~MyClass() = 0;
	virtual void printTest() = 0;
};

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

	//���ù���Ŀ¼(���Ϊ��ʱ��Ŀ¼����Ϊ��������ݻᱻ�����)
	cs.setWorkingDir("..\\..\\tmp");

	//��Ӱ���·��
	cs.addIncDir("..\\cl\\include\\SDK");
	cs.addIncDir("..\\cl\\include\\VC10");
		
#ifdef _WIN64
	//����cl.exe��link.exe��·��
	cs.setCompilePath("..\\cl\\x64\\cl.exe");
	cs.setLinkPath("..\\cl\\x64\\link.exe");

	//���libĿ¼
	cs.addLibDir("..\\cl\\x64\\lib\\VC10\\");
	cs.addLibDir("..\\cl\\x64\\lib\\SDK");

	//���lib
	//û��ָ��·����lib����lib dirs������
	cs.addLibrary("LIBCMT.lib");
	cs.addLibrary("OLDNAMES.lib");
	cs.addLibrary("libcpmt.lib");
	cs.addLibrary("..\\cl\\x64\\lib\\SDK\\kernel32.lib");
	cs.addLibrary("..\\cl\\x64\\lib\\SDK\\uuid.lib");
	cs.addLibrary("..\\cl\\x64\\lib\\SDK\\User32.lib");
#else
	//����cl.exe��link.exe��·��
	cs.setCompilePath("..\\cl\\x86\\cl.exe");
	cs.setLinkPath("..\\cl\\x86\\link.exe");

	//���libĿ¼
	cs.addLibDir("..\\cl\\x86\\lib\\VC10\\");
	cs.addLibDir("..\\cl\\x86\\lib\\SDK");

	//���lib
	//û��ָ��·����lib����lib dirs������
	cs.addLibrary("LIBCMT.lib");
	cs.addLibrary("OLDNAMES.lib");
	cs.addLibrary("libcpmt.lib");
	cs.addLibrary("..\\cl\\x86\\lib\\SDK\\kernel32.lib");
	cs.addLibrary("..\\cl\\x86\\lib\\SDK\\uuid.lib");
	cs.addLibrary("..\\cl\\x86\\lib\\SDK\\User32.lib");
#endif
	
	//��Ӻ궨��
	cs.addDefinition("MY_DEF=1");

#ifdef _DEBUG
	cs.addCompileOption("/Od /Zi");//Od�����Ż���Zi���õ�����Ϣ
	cs.addCompileOption("/showIncludes");//��ӡ����include files
	cs.addLinkOption("/DEBUG");
	cs.addLinkOption("/VERBOSE:Lib");
#endif

	//compile
	std::string sResult;
	printf("==================COMPILE===============\n");
#if 0
	std::string sCpp = Communal::ReadText(argv[1]);
	bool res = cs.compile(sCpp, &sResult);
#elif 1
	std::vector<std::string> cppFiles;
	cppFiles.push_back("..\\testScript.cpp");
	bool res = cs.compile(cppFiles, &sResult);
#else
	bool res = cs.compileInClosure("MessageBoxA(NULL, \"compileInClosure\", SCRIPT_ID, 0);", &sResult);
#endif
	printf(sResult.c_str());
	if (!res)
	{
		system("pause");
		cs.clean();
		return;
	}

	//link
	printf("===================LINK=================\n");
	res = cs.link(&sResult);
	printf(sResult.c_str());
	if (!res)
	{
		system("pause");
		cs.clean();
		return;
	}
	
	{//ʹ��
		CppScript::Context ct = cs.eval();

		printf("================�г��ű������еĵ���===============\n");
		std::vector<std::string> vctNames;
		ct.getNames(vctNames);
		for (int i = 0; i < vctNames.size(); ++i)
		{
			void* p = ct.getAddress(vctNames[i]);
			printf("%s:0x%p\n", vctNames[i].c_str(), p);
			assert(p);
		}

		printf("================���Զ�ȡ�ű��еı���===============\n");
		//ȡscript������
		int* pMyData = (int *)ct.getAddress("myData");
		DWORD err = GetLastError();
		if (pMyData)
			printf("Data in script: %d\n", *pMyData);

		printf("=================��C�еĺ��������ű�===============\n");
		//�Ѻ�����scriptʹ��
		typedef int(*PFN_extFoo)(int n);
		PFN_extFoo* pPFN = (PFN_extFoo*)ct.getAddress("pfnExtFoo");
		if (pPFN)
			*pPFN = extFoo;

		printf("================== ���ýű��еĺ��� ===============\n");
		//����script�ĺ���
		typedef void(*PFN_printTest)();
		PFN_printTest pfnPrintTest = (PFN_printTest)ct.getAddress("printTest");
		if (pfnPrintTest)
			pfnPrintTest();

		printf("================== ���ýű��е��� =================\n");
		typedef MyClass* (*PFN_create_MyClass)(/*���캯������*/);
		PFN_create_MyClass create_MyClass = (PFN_create_MyClass)ct.getAddress("create_MyClass");
		if (create_MyClass)
		{
			MyClass* pMyClass = create_MyClass();
			if (pMyClass)
				pMyClass->printTest();
		}
	}

	system("pause");
}