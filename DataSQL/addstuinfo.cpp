// addstuinfo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DataSQL.h"
#include "DataSQLDlg.h"
#include "addstuinfo.h"
#include "afxdialogex.h"
#include "mianMenu.h"
#include "afxdb.h"


// addstuinfo �Ի���

IMPLEMENT_DYNAMIC(addstuinfo, CDialogEx)

addstuinfo::addstuinfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(addstuinfo::IDD, pParent)
{

}

addstuinfo::~addstuinfo()
{
}

void addstuinfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(addstuinfo, CDialogEx)
	ON_BN_CLICKED(IDOK, &addstuinfo::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &addstuinfo::OnBnClickedCancel)
END_MESSAGE_MAP()


// addstuinfo ��Ϣ�������


void addstuinfo::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	CString id = NULL, name = NULL, age = NULL, major = NULL;
	GetDlgItemText(IDC_ID_STU, id);
	GetDlgItemText(IDC_NAME_STU, name);
	GetDlgItemText(IDC_AGE_STU, age);
	GetDlgItemText(IDC_MAJOR_STU, major);
	CString str;
	CString str2;
	CDatabase db;
	if (id != "" || name != "" || age != "" || major != "")
	{
		try
		{
			str.Format(_T("INSERT INTO StuInfo(SNO,SNAME,SAGE,SDEPT) values('%s','%s','%s','%s')"), id, name, age, major);
			str2.Format(_T("SELECT * FROM StuInfo WHERE SNO='%s'"), id);
			db.Open(_T("studentinfor"));
			CRecordset rec(&db);
			rec.Open(CRecordset::forwardOnly, str2, CRecordset::readOnly);
			if (rec.GetRecordCount()>0)
				//�����¼���еĸ�����Ϊ0,˵����ѧ����Ϣ�Ѵ���,(��ѧ��Ϊ����) 
			{
				MessageBox(_T("�Բ���,Ҫ��ӵ�ѧ����Ϣ�Ѵ���"));
				return;
			}
			else
			{
			rec.Close();
			db.ExecuteSQL(str);
			str.Format(_T("���[%s]�ɹ���"), name);
			//MessageBox(str, NULL, MB_OK | MB_ICONINFORMATION);
			MessageBox(str);
			CDialogEx::OnCancel();
			addstuinfo dlg;
			dlg.DoModal();
			CDialogEx::OnCancel();
			}

		}
		catch (CDBException *e)
		{
			AfxMessageBox(e->m_strError);
			return;
		}
	}
	else
	{
		str.Format(_T("��������Ч���ݣ�"));
		//MessageBox(str, NULL, MB_OK | MB_ICONINFORMATION);
		CDialogEx::OnCancel();
		addstuinfo dlg;
		dlg.DoModal();
	}


}


void addstuinfo::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	mianMenu dlg;
	dlg.DoModal();
	CDialogEx::OnOK();
}
