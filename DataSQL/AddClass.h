#pragma once


// CAddClass �Ի���

class CAddClass : public CDialogEx
{
	DECLARE_DYNAMIC(CAddClass)

public:
	CAddClass(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddClass();

// �Ի�������
	enum { IDD = IDD_ADD_CLASS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
