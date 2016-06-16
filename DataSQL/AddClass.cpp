// AddClass.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DataSQL.h"
#include "AddClass.h"
#include "afxdialogex.h"
#include "mianMenu.h"
#include "afxdb.h"


// CAddClass �Ի���

IMPLEMENT_DYNAMIC(CAddClass, CDialogEx)

CAddClass::CAddClass(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddClass::IDD, pParent)
{

}

CAddClass::~CAddClass()
{
}

void CAddClass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddClass, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddClass::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CAddClass::OnBnClickedCancel)
END_MESSAGE_MAP()


// CAddClass ��Ϣ�������


void CAddClass::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString id = NULL, name = NULL, teacher= NULL;
	GetDlgItemText(IDC_CLASS_ID, id);
	GetDlgItemText(IDC_CLASS_NAME, name);
	GetDlgItemText(IDC_CLASS_TEACHER, teacher);
	CString str;
	CString str2;
	CDatabase db;
	if ((id != "" )&& (name != "" )&&( teacher != ""))
	{
		try
		{
			str.Format(_T("INSERT INTO Class(CNO,CNAME,TEACHER) values('%s','%s','%s')"), id, name, teacher);
			str2.Format(_T("SELECT * FROM Class WHERE CNO='%s'"), id);
			db.Open(_T("studentinfor"));
			CRecordset rec(&db);
			rec.Open(CRecordset::forwardOnly, str2, CRecordset::readOnly);
			if (rec.GetRecordCount()>0)
				//�����¼���еĸ�����Ϊ0,˵����ѧ����Ϣ�Ѵ���,(��ѧ��Ϊ����) 
			{
				MessageBox(_T("�Բ���,Ҫ��ӵĿγ���Ϣ�Ѵ���"));
				return;
			}
			else
			{
				rec.Close();
				db.ExecuteSQL(str);
				str.Format(_T("��ӿγ�[%s]�ɹ���"), name);
				MessageBox(str);
				CDialogEx::OnCancel();
				CAddClass dlg;
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
		MessageBox(str, NULL, MB_OK | MB_ICONINFORMATION);
		CDialogEx::OnCancel();
		CAddClass dlg;
		dlg.DoModal();
	}

	CDialogEx::OnOK();
}


void CAddClass::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	mianMenu dlg;
	dlg.DoModal();
	CDialogEx::OnOK();
	CDialogEx::OnCancel();
}
