#pragma once


// addstuinfo �Ի���

class addstuinfo : public CDialogEx
{
	DECLARE_DYNAMIC(addstuinfo)

public:
	addstuinfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~addstuinfo();

// �Ի�������
	enum { IDD = IDD_ADD_STU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
