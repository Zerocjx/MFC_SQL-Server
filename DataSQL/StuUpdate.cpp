// StuUpdate.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DataSQL.h"
#include "StuUpdate.h"
#include "afxdialogex.h"
#include "afxdb.h"
#include "mianMenu.h"

// CStuUpdate �Ի���

IMPLEMENT_DYNAMIC(CStuUpdate, CDialogEx)

CStuUpdate::CStuUpdate(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStuUpdate::IDD, pParent)
{

}

CStuUpdate::~CStuUpdate()
{
}

void CStuUpdate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStuUpdate, CDialogEx)
	ON_BN_CLICKED(IDOK, &CStuUpdate::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_OPTION, &CStuUpdate::OnCbnSelchangeCombo1)
	ON_EN_CHANGE(IDC_NAME_STU, &CStuUpdate::OnEnChangeNameStu)
	ON_BN_CLICKED(IDCANCEL, &CStuUpdate::OnBnClickedCancel)
END_MESSAGE_MAP()


// CStuUpdate ��Ϣ�������


void CStuUpdate::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString id;
	CString option;
	CString str1;
	CString str2;
	GetDlgItemText(IDC_ID, id);
	GetDlgItemText(IDC_OPTION, option);
	GetDlgItemText(IDC_VALUE, str2);
	if (id==""||option==""||str2=="")
	{
		MessageBox(_T("������Ч������������"));
		CDialogEx::OnOK();
		CStuUpdate dlg;
		dlg.DoModal();
		CDialogEx::OnOK();
	}
	else
	{
		if (option == "����")
		{
			str1 = "SNAME";
		}
		else if (option == "����")
		{
			str1 = "SAGE";
		}
		else if (option == "רҵ")
		{
			str1 = "SDEPT";
		}

		CDatabase db;
		CString str;
		str.Format(_T("UPDATE StuInfo SET %s = '%s' WHERE SNO='%s'"), str1, str2, id);

		//�жϸü�¼�Ƿ���� 
		str2.Format(_T("SELECT * FROM StuInfo WHERE SNO='%s'"), id);
		db.Open(_T("studentinfor"));
		CRecordset rec(&db);
		rec.Open(CRecordset::forwardOnly, str2, CRecordset::readOnly);
		//��ѯ��¼�Ƿ���� 
		if (rec.GetRecordCount() > 0)
		{
			rec.Close();
			db.ExecuteSQL(str);
			MessageBox(_T("�޸����ݳɹ�"));

			CDialogEx::OnOK();
			CStuUpdate dlg;
			dlg.DoModal();
			CDialogEx::OnOK();

		}
		else {
			MessageBox(_T("�Բ���,Ҫ�޸ĵ�ѧ����Ϣ������"));
			CDialogEx::OnOK();
			CStuUpdate dlg;
			dlg.DoModal();
			CDialogEx::OnOK();
		}
	}
}


void CStuUpdate::OnCbnSelchangeCombo1()
{

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CStuUpdate::OnEnChangeNameStu()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CStuUpdate::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	mianMenu dlg;
	dlg.DoModal();
	CDialogEx::OnOK();
	CDialogEx::OnCancel();
}
