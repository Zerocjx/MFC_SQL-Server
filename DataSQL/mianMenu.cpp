// mianMenu.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DataSQL.h"
#include "DataSQLDlg.h"
#include "addstuinfo.h"
#include "mianMenu.h"
#include "afxdialogex.h"
#include "StuinforDel.h"
#include "StuUpdate.h"
#include "StuQuery.h"
#include "afxdb.h"
#include "AddClass.h"
#include "SqlExe.h"
#include "TableChange.h"
#include "XuanKe.h"

// mianMenu �Ի���

IMPLEMENT_DYNAMIC(mianMenu, CDialogEx)

mianMenu::mianMenu(CWnd* pParent /*=NULL*/)
	: CDialogEx(mianMenu::IDD, pParent)
{

}

mianMenu::~mianMenu()
{
}

void mianMenu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(mianMenu, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON10, &mianMenu::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON1, &mianMenu::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &mianMenu::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &mianMenu::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &mianMenu::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &mianMenu::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &mianMenu::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &mianMenu::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON9, &mianMenu::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_CLOSE, &mianMenu::OnBnClickedClose)
	ON_BN_CLICKED(IDC_BUTTON11, &mianMenu::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON8, &mianMenu::OnBnClickedButton8)
END_MESSAGE_MAP()


// mianMenu ��Ϣ�������


void mianMenu::OnBnClickedButton10()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->OnOK();
	CDialogEx::OnCancel();
	CDataSQLDlg dlg;
	dlg.DoModal();
	
}


void mianMenu::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->OnOK();
	CDialogEx::OnCancel();
	addstuinfo dlg;
	dlg.DoModal();
	
}


void mianMenu::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->OnOK();
	CDialogEx::OnCancel();
	CStuinforDel dlg;
	dlg.DoModal();

	
}


void mianMenu::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->OnOK();
	CDialogEx::OnCancel();
	CStuUpdate dlg;
	dlg.DoModal();
}


void mianMenu::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->OnOK();
	CDialogEx::OnCancel();
	CStuQuery dlg;
	dlg.DoModal();
}


void mianMenu::OnBnClickedButton5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDatabase db; 
	db.Open(_T("studentinfor"));
	try{
		CString str;
		str.Format(_T("CREATE TABLE Class(CNO varchar(20),CNAME varchar(40),TEACHER varchar(30))"));
		db.ExecuteSQL(str);
		MessageBox(_T("�½���ɹ�!"));
	}
	catch (CDBException *e)
	{
		MessageBox(_T("��Ҫ�½��ı��Ѵ���!"));
	}
	

}


void mianMenu::OnBnClickedButton6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDatabase db; db.Open(_T("studentinfor"));
	try{
		CString str;
		str.Format(_T("DROP TABLE Class"));
		db.ExecuteSQL(str);
		MessageBox(_T("ɾ����ɹ�!"));
	}
	catch (CDBException *e)
	{
		MessageBox(_T("��Ҫɾ���ı�����!"));
	}

}


void mianMenu::OnBnClickedButton7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->OnOK();
	CDatabase db;
	db.Open(_T("studentinfor"));
	CString str;
	str.Format(_T("SELECT * FROM Class"));
	try
	{
		db.ExecuteSQL(str);
		CDialogEx::OnCancel();
		CAddClass dlg;
		dlg.DoModal();
	}
	catch (CDBException *e)
	{
		MessageBox(_T("��Ҫ������ݵı�����!"));
		
		mianMenu dlg;
		dlg.DoModal();
		CDialogEx::OnOK();
	}

}


void mianMenu::OnBnClickedButton9()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->OnOK();
	CDialogEx::OnCancel();
	CSqlExe dlg;
	dlg.DoModal();
}


void mianMenu::OnBnClickedClose()
{
	CDialogEx::OnCancel();
}


void mianMenu::OnBnClickedButton11()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDatabase db;
	db.Open(_T("studentinfor"));
	CString str;
	str.Format(_T("SELECT * FROM Class"));
	try
	{
	this->OnOK();
	db.ExecuteSQL(str);
	CDialogEx::OnCancel();
	CTableChange dlg;
	dlg.DoModal();
	}
	catch (CDBException *e)
	{
		MessageBox(_T("��Ҫ������ݵı�����!"));
		
		mianMenu dlg;
		dlg.DoModal();
		CDialogEx::OnOK();
	}
}


void mianMenu::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	this->OnOK();
	CDialogEx::OnCancel();
	CXuanKe dlg;
	dlg.DoModal();
}
