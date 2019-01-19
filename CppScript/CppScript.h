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
		
		///��õ����ĵ�ַ
		void* getAddress(const std::string& name);

	protected:
		void _deRef();

	private:
		int* m_pRefCount;
		unsigned long long m_hMod;
		std::string m_name;
	};

public:
	CppScript();
	~CppScript();

	///���ù���Ŀ¼
	// Ĭ��Ϊ��ǰĿ¼
	std::string getWorkingDir();
	void setWorkingDir(const std::string& sDir);

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
	std::string getIncDirs();

	///���lib�ļ�
	// ���Ϊ���·�����������WorkingDir
	void addLibrary(const std::string& sLibPath);
	std::string getLibrarys();

	///compile
	// sScript����Ϊ���պϵĴ���
	int compile(const std::string& sScript, std::string* result = NULL);

	///compile in closure
	// sScript����Ϊ���պϵĴ��룬��:int n = 0; ++n;
	int compileInClosure(const std::string& sScript, std::string* result = NULL, 
		const std::vector<std::string>* vctIncludedFiles = NULL);

	///link����compiled������
	int link(std::string* result = NULL);

	///���ز�����linked�Ĵ���
	CppScript::Context eval();

	///�����ʱ�ļ�
	void clean();

protected:
	class _WorkingDirMan
	{
	public:
		_WorkingDirMan(CppScript* THIS);
		~_WorkingDirMan();
		std::string m_sOriginalDir;
	};
		
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
	std::string m_LinkPath;
	std::string m_CompileOption;
	std::string m_LinkOption;
	std::vector<std::string> m_vctIncDirs;
	std::vector<std::string> m_vctLibs;
	std::string m_workingDir;
	int m_compileCount;//ÿcompileһ�ξ͵���1

private:
	std::vector<std::string> m_vctTmpCompiledNames;
};

