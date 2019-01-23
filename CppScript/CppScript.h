#pragma once
#include <string>
#include <vector>

class CppScript
{
public:
	///eval�Ľ������smart ptr��dll handle���й���
	class Context
	{
	public:
		Context(unsigned long long hMod = NULL);
		~Context();
		Context(const Context& o);
		Context& operator=(const Context& o);
		
		///�Ƿ���Ч
		bool isValid();

		///��õ����ĵ�ַ
		void* getAddress(const std::string& name);

		///������е���������
		bool getNames(std::vector<std::string>& outNames);

	protected:
		void _deRef();

	private:
		int* m_pRefCount;
		unsigned long long m_hMod;
		std::string m_name;
	};

	class WorkingDirScope
	{
	public:
		WorkingDirScope(CppScript* cs);
		WorkingDirScope(const char* dirSwitchTo);
		~WorkingDirScope();
		std::string m_sOriginalDir;
	};

public:
	CppScript();
	~CppScript();

	///���ù���Ŀ¼
	// Ĭ��Ϊ��ǰĿ¼
	std::string getWorkingDir();
	bool setWorkingDir(const std::string& sDir);

	///����compiler��·������cl.exe���ļ�·��
	// ���Ϊ���·�����������WorkingDir
	void setCompilePath(const std::string& sPath);
	std::string getCompilePath();

	///����linker��·������link.exe���ļ�·��
	// ���Ϊ���·�����������WorkingDir
	void setLinkPath(const std::string& sPath);
	std::string getLinkPath();

	///����compile������ѡ��
	// ���磺Ԥ����ȡ��� cl.exe /?
	void setCompileOption(const std::string& sOption);
	std::string getCompileOption();

	///����link������ѡ��
	// ���磺�Ż��ȡ��� link.exe /?
	void setLinkOption(const std::string& sOption);
	std::string getLinkOption();
	
	///��Ӱ���Ŀ¼
	// ���Ϊ���·�����������WorkingDir
	void addIncDir(const std::string& sDir);
	///
	std::vector<std::string> getIncDirs();
	///����include dirs��������
	std::string getIncDirsCmdLine();

	///���lib�ļ�
	// ���Ϊ���·�����������WorkingDir
	void addLibrary(const std::string& sLibPath);
	///
	std::vector<std::string> getLibraries();
	///����libraries��������
	std::string getLibrariesCmdLine();
	///���libĿ¼
	// ���Ϊ���·�����������WorkingDir
	void addLibDir(const std::string& sDir);
	///
	std::vector<std::string> getLibDirs();
	///����libĿ¼������
	std::string getLibDirsCmdLine();

	///compile
	// sScript����Ϊ���պϵĴ���
	bool compile(const std::string& sScript, std::string* result = NULL);

	///compile in closure
	// sScript����Ϊ���պϵĴ��룬��:int n = 0; ++n;
	bool compileInClosure(const std::string& sScript, std::string* result = NULL, 
		const std::vector<std::string>* vctIncludedFiles = NULL);

	///link����compiled������
	bool link(std::string* result = NULL);

	///���ز�����linked�Ĵ���
	CppScript::Context eval();

	///�����ʱ�ļ�
	void clean();
		
protected:
	std::string _getMainTempName();//��ʱ���֣�Ϊthis���ַ���
	std::string _getCurTempFileName();//��ʱ�ļ�����������׺��_getMainTempName() + '-' + m_compileCount
	std::string _generateIncludeFile();//����ͷ�ļ�
	std::vector<std::string> _generateCFile(const std::string& sCode);//����Դ�ļ������ز���cpp��׺�����б�
	std::string _getSrcFileCmdLine(const std::vector<std::string>& vctNames);//���Դ�ļ�������
	std::string _getObjFileCmdLine(const std::vector<std::string>& vctNames);//���obj�ļ�������
	std::string _getOutFile();//�������ļ���

private:
	std::string m_CompilePath;
	std::string m_CompileOption;
	std::string m_LinkPath;	
	std::string m_LinkOption;
	std::vector<std::string> m_vctIncDirs;
	std::vector<std::string> m_vctLibs;
	std::vector<std::string> m_vctLibDirs;
	std::string m_workingDir;
	int m_compileCount;//ÿcompileһ�ξ͵���1

private:
	std::vector<std::string> m_vctTmpCompiledNames;
};

