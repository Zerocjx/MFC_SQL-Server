// TableChange.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DataSQL.h"
#include "TableChange.h"
#include "afxdialogex.h"
#include "mianmenu.h"
#include "afxdb.h"

// CTableChange �Ի���

IMPLEMENT_DYNAMIC(CTableChange, CDialogEx)

CTableChange::CTableChange(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTableChange::IDD, pParent)
{

}

CTableChange::~CTableChange()
{
}

void CTableChange::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTableChange, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CTableChange::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CTableChange::OnBnClickedOk)
	//ON_EN_CHANGE(IDC_VALUE_CHANGE, &CTableChange::OnEnChangeValueChange)
END_MESSAGE_MAP()


// CTableChange ��Ϣ�������


void CTableChange::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	mianMenu dlg;
	dlg.DoModal();
	CDialogEx::OnOK();
}


void CTableChange::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString option;
	CString value;
	CDatabase db;
	CString str;
	GetDlgItemText(IDC_OPTION_CHANGE, option);
	GetDlgItemText(IDC_VALUE_CHANGE, value);
	if (value != "")
	{
		if (option == "���")
		{
			try
			{
				str.Format(_T("ALTER TABLE Class ADD %s nchar(20)"), value);
				db.Open(_T("studentinfor"));
				db.ExecuteSQL(str);
				str.Format(_T("���[%s]�гɹ���"), value);
				MessageBox(str);
			}
			catch (CDBException* e)
			{
				MessageBox(_T("���ʧ��!�����Ѵ���"));
			}
		}
		else if (option == "ɾ��")
		{
			str.Format(_T("ALTER TABLE Class DROP COLUMN %s"), value);
			db.Open(_T("studentinfor"));
			try
			{
				db.ExecuteSQL(str);
				str.Format(_T("ɾ��[%s]�гɹ���"), value);
				MessageBox(str);
			}
			catch (CDBException* e)
			{
				MessageBox(_T("ɾ��ʧ��!Ŀ���в�����"));
			}
		}
		else
		{
			MessageBox(_T("��ѡ�����"));
		}
	}
	else
	{
		MessageBox(_T("����д����"));
	}
		CTableChange dlg;
		dlg.DoModal();
		CDialogEx::OnOK();
}


/*void CTableChange::OnEnChangeValueChange()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
*/