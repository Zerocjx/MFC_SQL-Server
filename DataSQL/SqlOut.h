#pragma once


// CSqlOut �Ի���

class CSqlOut : public CDialogEx
{
	DECLARE_DYNAMIC(CSqlOut)

public:
	CSqlOut(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSqlOut();

// �Ի�������
	enum { IDD = IDD_SQL_EXE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
