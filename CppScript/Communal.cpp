#include "Communal.h"
#include <malloc.h>
#include <windows.h>

bool Communal::Execute(const char* szFile, const char* szParam, unsigned long& exitCode, std::string& sPrintText)
{
	if (!szFile || szFile[0] == '\0')
		return false;

	//���������ܵ�
	SECURITY_ATTRIBUTES sa = { sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };
	HANDLE hRead, hWrite;
	if (!CreatePipe(&hRead, &hWrite, &sa, 0))
	{
		return false;
	}

	int nCmdLen = (strlen(szFile) + strlen(szParam) + 2) * sizeof(char);
	char* szCmd = (char*)_alloca(nCmdLen);//_alloca��ջ������ģ����Զ��ͷ�
	memset(szCmd, 0, nCmdLen);
	strcpy(szCmd, szFile);
	if (szParam)
	{
		strcat(szCmd, " ");
		strcat(szCmd, szParam);
	}

	//���������н���������Ϣ(�����ط�ʽ���������λ�������hWrite)
	STARTUPINFOA si = { sizeof(STARTUPINFOA) };
	GetStartupInfoA(&si);
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	si.wShowWindow = SW_HIDE;
	si.hStdError = hWrite;
	si.hStdOutput = hWrite;

	//����������
	PROCESS_INFORMATION pi;
	if (!CreateProcessA(NULL, (char *)szCmd, NULL, NULL, TRUE, NULL, NULL, NULL, &si, &pi))
	{
		CloseHandle(hWrite);
		CloseHandle(hRead);
		return false;
	}

	//�����ر�hWrite
	CloseHandle(hWrite);

	//��÷���ֵ
	GetExitCodeProcess(pi.hProcess, &exitCode);

	//��ȡ�����з���ֵ
	char buff[1024];
	DWORD dwRead = 0;
	while (ReadFile(hRead, buff, 1024, &dwRead, NULL))
	{
		buff[dwRead] = '\0';
		sPrintText.append(buff, dwRead);
	}
	CloseHandle(hRead);

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return true;
}

size_t Communal::WriteFile(const char * path, const char * writeContent, size_t & in_outLen,
	int start/* = -1*/, bool bInsert/* = true*/, bool bDelTail/* = true*/)
{
	if (!path)
	{
		return -1;
	}

	FILE *f = NULL;
	if ((f = fopen(path, "rb+")) == NULL)
	{
		//�ļ������ڣ����½�һ���յ�
		if ((f = fopen(path, "wb")) == NULL)
		{
			return -1;
		}
		fclose(f);

		if ((f = fopen(path, "rb+")) == NULL)
			return -1;
	}

	do
	{
		int nFileSize = 0;
		if (fseek(f, 0, SEEK_END) != 0)
		{
			nFileSize = 0;
		}
		else
		{
			nFileSize = ftell(f);
		}
		if (nFileSize < 0)
		{
			break;
		}

		char* pOldStart = NULL;
		char* pOldEnd = NULL;
		if (start > -1)
		{
			if (nFileSize < start)
			{//���봦��ԭ�е��ļ�������ԭ�ļ�β�����봦�հ׵���Щλ�����NULL
				int nSpace = start - nFileSize + 1;
				char *pSpace = new char[nSpace];
				memset(pSpace, 0, nSpace);
				fwrite(pSpace, nSpace, 1, f);
				delete[] pSpace;
			}
			else if (bInsert && (nFileSize > start))
			{//���м����Ҫд������
			 //��ȡ���봦��ԭ�ļ���β�������ݣ��Ի�д
				int nRead = (nFileSize - start);
				fseek(f, start, SEEK_SET);
				pOldEnd = new char[nRead];
				fread(pOldEnd, 1, nRead, f);
			}
			else if (bDelTail && (nFileSize > start) && (in_outLen < nFileSize - start))
			{//��д���봦ǰ������ݣ����������봦���������
			 //��ȡ���봦ǰ�������
				if (start > 0)
				{
					fseek(f, 0, SEEK_SET);
					pOldStart = new char[start];
					fread(pOldStart, 1, start, f);
				}

				//ɾ��ԭ�е��ļ����½�һ���յ�
				fclose(f);
				remove(path);
				if ((f = fopen(path, "wb")) == NULL)
				{
					return -1;
				}
				//��д���봦ǰ������ݣ����������봦���������
				if (start > 0)
					fwrite(pOldStart, 1, start, f);
			}

			if (fseek(f, start, SEEK_SET) != 0)
			{
				if (pOldEnd)
				{
					delete[] pOldEnd;
				}
				break;
			}
		}

		in_outLen = fwrite(writeContent, 1, in_outLen, f);
		if (pOldEnd)
		{
			fwrite(pOldEnd, 1, (nFileSize - start), f);
			delete[] pOldEnd;
		}

	} while (0);

	int nFileSize = 0;
	if (fseek(f, 0, SEEK_END) != 0)
	{
		nFileSize = -1;
	}
	else
	{
		nFileSize = ftell(f);
	}

	fclose(f);
	return nFileSize;
}

std::string Communal::ReadText(const char * path)
{
	FILE *f = NULL;
	long sz;

	if (!path)
	{
		return "";
	}

	std::string sRet;

	f = fopen(path, "rb");
	if (!f)
	{
		return "";
	}

	do
	{
		if (fseek(f, 0, SEEK_END) < 0)
		{
			break;
		}

		sz = ftell(f);
		if (sz < 0)
		{
			break;
		}

		if (fseek(f, 0, SEEK_SET) < 0)
		{
			break;
		}

		sRet.resize((size_t)sz + 1, '\0');

		if ((size_t)fread(const_cast<char*>(sRet.c_str()), 1, (size_t)sz, f) != (size_t)sz)
		{
			sRet = "";
			break;
		}
	} while (0);

	fclose(f);

	return sRet;
}

std::string Communal::GetWorkingDir()
{
	char path[MAX_PATH] = { 0 };
	GetCurrentDirectoryA(MAX_PATH, path);
	return path;
}

bool Communal::SetWorkingDir(const char* dir)
{
	return (TRUE == SetCurrentDirectoryA(dir));
}

unsigned long long Communal::LoadLib(const char* libPath)
{
	unsigned long long h = (unsigned long long)::LoadLibraryA(libPath);
	return h;
}

void* Communal::GetAddressByExportName(unsigned long long hHanle, const char* sExportName)
{
	return GetProcAddress((HMODULE)hHanle, sExportName);
}

bool Communal::FreeLib(unsigned long long hHandle)
{
	return (TRUE == FreeLibrary((HMODULE)hHandle));
}

std::vector<std::string> Communal::GetDllExportNames(const char* pFile)
{
	std::vector<std::string> vctRet;

	return vctRet;
}

std::string Communal::GetModulePath(unsigned long long hHandle)
{
	char path[MAX_PATH] = { 0 };
	GetModuleFileNameA((HMODULE)hHandle, path, MAX_PATH);
	return path;
}

void Communal::ListFilesA(const char * lpPath, std::vector<std::string>& vctDir, std::vector<std::string>& vctFiles,
	const char * filter, bool bSubDir, bool bAppendPath)
{
	char szFind[MAX_PATH] = { 0 };
	lstrcpyA(szFind, lpPath);
	lstrcatA(szFind, "/");
	lstrcatA(szFind, filter);
	
	WIN32_FIND_DATAA FindFileData;
	HANDLE hFind = ::FindFirstFileA(szFind, &FindFileData);
	if (INVALID_HANDLE_VALUE == hFind)
	{
		//int n = GetLastError();
		return;
	}

	char szFile[MAX_PATH] = { 0 };
	while (TRUE)
	{
		szFile[0] = '\0';
		if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if (FindFileData.cFileName[0] != '.')
			{
				if (bAppendPath)
				{
					lstrcpyA(szFile, lpPath);
					lstrcatA(szFile, "\\");
					lstrcatA(szFile, FindFileData.cFileName);
				}
				else
				{
					lstrcpyA(szFile, FindFileData.cFileName);
				}
				vctDir.push_back(szFile);

				if (bSubDir)
				{
					ListFilesA(szFile, vctDir, vctFiles, filter, bSubDir, bAppendPath);
				}
			}
		}
		else
		{
			if (bAppendPath)
			{
				lstrcpyA(szFile, lpPath);
				lstrcatA(szFile, "\\");
				lstrcatA(szFile, FindFileData.cFileName);
			}
			else
			{
				lstrcpyA(szFile, FindFileData.cFileName);
			}
			vctFiles.push_back(szFile);
		}

		if (!FindNextFileA(hFind, &FindFileData))
			break;
	}

	FindClose(hFind);
}

bool Communal::DelFile(const char* pFilePath)
{
	return (DeleteFileA(pFilePath) == TRUE);
}
