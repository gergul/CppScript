#define MYDLL_API __declspec(dllexport)

// �����Ǵ� MyDLL.dll ������
class MYDLL_API CMyDLL {
public:
	CMyDLL(void);
	// TODO:  �ڴ�������ķ�����
};

extern MYDLL_API int nMyDLL;

MYDLL_API int fnMyDLL(void);
