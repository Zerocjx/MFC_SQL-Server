#pragma once


// CStuinforDel �Ի���

class CStuinforDel : public CDialogEx
{
	DECLARE_DYNAMIC(CStuinforDel)

public:
	CStuinforDel(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStuinforDel();

// �Ի�������
	enum { IDD = IDD_STU_DEL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
