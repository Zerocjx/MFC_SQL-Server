#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CSqlExe �Ի���

class CSqlExe : public CDialogEx
{
	DECLARE_DYNAMIC(CSqlExe)

public:
	CSqlExe(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSqlExe();

// �Ի�������
	enum { IDD = IDD_SQL_EXE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedchaxun();
	afx_msg void OnLbnSelchangeListOut();
	CListCtrl myList;
	afx_msg void OnLvnItemchangedListOut(NMHDR *pNMHDR, LRESULT *pResult);
};
