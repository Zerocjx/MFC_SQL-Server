#pragma once


// CStuUpdate �Ի���

class CStuUpdate : public CDialogEx
{
	DECLARE_DYNAMIC(CStuUpdate)

public:
	CStuUpdate(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStuUpdate();

// �Ի�������
	enum { IDD = IDD_STUUPDATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnEnChangeNameStu();
	afx_msg void OnBnClickedCancel();
};
