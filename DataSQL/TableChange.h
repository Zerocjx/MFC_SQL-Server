#pragma once


// CTableChange �Ի���

class CTableChange : public CDialogEx
{
	DECLARE_DYNAMIC(CTableChange)

public:
	CTableChange(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTableChange();

// �Ի�������
	enum { IDD = IDD_TABLE_CHANGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeValueChange();
};
