#pragma once


// CStuQuery �Ի���

class CStuQuery : public CDialogEx
{
	DECLARE_DYNAMIC(CStuQuery)

public:
	CStuQuery(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStuQuery();

// �Ի�������
	enum { IDD = IDD_STU_QUERY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
