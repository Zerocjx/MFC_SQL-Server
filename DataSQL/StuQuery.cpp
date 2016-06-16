// StuQuery.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DataSQL.h"
#include "StuQuery.h"
#include "afxdialogex.h"
#include "afxdb.h"
#include "mianMenu.h"

// CStuQuery �Ի���

IMPLEMENT_DYNAMIC(CStuQuery, CDialogEx)

CStuQuery::CStuQuery(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStuQuery::IDD, pParent)
{

}   

CStuQuery::~CStuQuery()
{
}

void CStuQuery::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStuQuery, CDialogEx)
	ON_BN_CLICKED(IDOK, &CStuQuery::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CStuQuery::OnBnClickedCancel)
END_MESSAGE_MAP()


// CStuQuery ��Ϣ�������


void CStuQuery::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString id;
	CString name;
	CString age;
	CString major;
	CString option;
	CString value;
	CString str1;
	CString str2;
	GetDlgItemText(IDC_OPTION, option);
	GetDlgItemText(IDC_VALUE, value);
	if (option == "����")
	{
		str1 = "SNAME";
	}
	else if (option == "ѧ��")
	{
		str1 = "SNO";
	}

	CDatabase db;
	CString str;
	if (value != "")
	{
		str.Format(_T("SELECT SNO,SNAME,SAGE,SDEPT FROM StuInfo WHERE %s='%s'"), str1, value);
		//str2.Format(_T("SELECT * FROM StuInfo WHERE %s='%s'"), str1, value);
		db.Open(_T("studentinfor"));
		CRecordset rect(&db);
		rect.Open(CRecordset::forwardOnly, str, CRecordset::readOnly);
		//��ѯ��¼�Ƿ���� 
		if (rect.GetRecordCount()>0)
		{
			short int i = 0;
		
			rect.GetFieldValue(i++, id);
			rect.GetFieldValue(i++, name);
			rect.GetFieldValue(i++, age);
			rect.GetFieldValue(i++, major);
	
			SetDlgItemText(IDC_STU_ID, id);
			SetDlgItemText(IDC_STU_NAME, name);
			SetDlgItemText(IDC_STU_AGE, age);
			SetDlgItemText(IDC_STU_MAJOR, major);
			rect.Close();

		}
		else {
			MessageBox(_T("�Բ���,Ҫ��ѯ��ѧ����Ϣ������"));
			CDialogEx::OnOK();
			CStuQuery dlg;
			dlg.DoModal();
			CDialogEx::OnOK();
		}
	}
	else
	{
		MessageBox(_T("Ҫ��ѯ����Ϣ����Ϊ�գ�"));
	}
	
}


void CStuQuery::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	mianMenu dlg;
	dlg.DoModal();
	CDialogEx::OnOK();
	CDialogEx::OnCancel();
}
