// StuinforDel.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DataSQL.h"
#include "StuinforDel.h"
#include "afxdialogex.h"
#include "afxdb.h"
#include "mianMenu.h"

// CStuinforDel �Ի���

IMPLEMENT_DYNAMIC(CStuinforDel, CDialogEx)

CStuinforDel::CStuinforDel(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStuinforDel::IDD, pParent)
{

}

CStuinforDel::~CStuinforDel()
{
}

void CStuinforDel::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStuinforDel, CDialogEx)
	ON_BN_CLICKED(IDOK, &CStuinforDel::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CStuinforDel::OnBnClickedCancel)
END_MESSAGE_MAP()


// CStuinforDel ��Ϣ�������


void CStuinforDel::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString id;
	GetDlgItemText(IDC_ID, id);
	CDatabase db;
	CString str1; 
	str1.Format(_T("DELETE FROM StuInfo WHERE SNO='%s'"), id);
	CString str2; 
	//�жϸü�¼�Ƿ���� 
	str2.Format(_T("SELECT * FROM StuInfo WHERE SNO='%s'"),id);
	db.Open(_T("studentinfor"));
	CRecordset rec(&db); 
	rec.Open(CRecordset::forwardOnly,str2 , CRecordset::readOnly);
	//��ѯ��¼�Ƿ���� 
	if(rec.GetRecordCount()>0) 
	{ 
		rec.Close();
		db.ExecuteSQL(str1);
		MessageBox(_T("ɾ�����ݳɹ�"));
		//MessageBox(str1, NULL, MB_OK | MB_ICONINFORMATION);
		CDialogEx::OnOK();
		CStuinforDel dlg;
		dlg.DoModal();
		CDialogEx::OnOK();
		
	}
	else { 
		 MessageBox(_T("�Բ���,Ҫɾ����ѧ����Ϣ������"));
		 CDialogEx::OnOK();
		 CStuinforDel dlg;
		 dlg.DoModal();
		 CDialogEx::OnOK();
 }
}


void CStuinforDel::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	mianMenu dlg;
	dlg.DoModal();
	CDialogEx::OnOK();
	
}
