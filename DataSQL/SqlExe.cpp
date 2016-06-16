// SqlExe.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DataSQL.h"
#include "SqlExe.h"
#include "afxdialogex.h"
#include "afxdb.h"
#include "mianMenu.h"

// CSqlExe �Ի���

IMPLEMENT_DYNAMIC(CSqlExe, CDialogEx)

CSqlExe::CSqlExe(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSqlExe::IDD, pParent)
{

}

CSqlExe::~CSqlExe()
{
}

void CSqlExe::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_OUT, myList);
}


BEGIN_MESSAGE_MAP(CSqlExe, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSqlExe::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CSqlExe::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_chaxun, &CSqlExe::OnBnClickedchaxun)
	//ON_LBN_SELCHANGE(IDC_LIST_OUT, &CSqlExe::OnLbnSelchangeListOut)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_OUT, &CSqlExe::OnLvnItemchangedListOut)
END_MESSAGE_MAP()


// CSqlExe ��Ϣ�������


void CSqlExe::OnBnClickedOk()
{
	CString sql;
	try {
		GetDlgItemText(IDC_SQL_IN,sql);
	}
	catch (CDBException* e)
	{
		MessageBox(_T("SQL��䲻�Ϸ�!"));
	}
	
	CDatabase db; 
	db.Open(_T("studentinfor"));
	CRecordset rec(&db);
	
	sql.TrimLeft();
	if(sql.IsEmpty())
	{ 
		MessageBox(_T("SQL��䲻��Ϊ��!"));
		return;
	}
	char temp[3];
	for (int i = 0; i<3; i++)
	{ 
		if (isupper(sql[i])) 
			temp[i] = tolower(sql[i]);
		else
			temp[i] = sql[i];
	}
	if ((temp[0] == 's' || temp[0] == 'S') && (temp[1] == 'e' || temp[1] == 'E') && (temp[2] == 'l' || temp[2] == 'L'))
	{
		try
		{
			rec.Open(CRecordset::forwardOnly, sql, CRecordset::readOnly);
			int n = rec.GetODBCFieldCount();
			CString *str1 = new CString[n];
			myList.DeleteAllItems();
			for (int i = 0; i < 5; i++)
			{
				myList.DeleteColumn(0);
			}
			CRect rect;
			myList.GetClientRect(&rect);
			myList.SetExtendedStyle(myList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
			myList.InsertColumn(0, _T("ѧ��"), LVCFMT_CENTER, rect.Width() / 3, 0);
			myList.InsertColumn(1, _T("�γ̺�"), LVCFMT_CENTER, rect.Width() / 3, 0);
			myList.InsertColumn(2, _T("�ɼ�"), LVCFMT_CENTER, rect.Width() / 3, 0);
			if (rec.IsEOF())
			{
				MessageBox(_T("�Բ���,û���ҵ���Ҫ�ҵ���Ϣ"));
				return;
			}
			else
			{

				int flag = 0;
				while (!rec.IsEOF())
				{

					for (int i = 0; i < n; i++)
					{
						rec.GetFieldValue(i, str1[i]);
					}
					int i = 0;
					myList.InsertItem(flag, str1[i++]);
					myList.SetItemText(flag, 1, str1[i++]);
					myList.SetItemText(flag, 2, str1[i++]);

					flag++;
					rec.MoveNext();

				}
				rec.Close();
				db.Close();
			}
		}
		catch(CDBException* e) 
		{ 
			MessageBox(_T("������Ϸ���SQL��䣡"));
			//AfxMessageBox(e->m_strError);
			return; 
		} 
	} 
	else 
	{
		try 
		{
			db.ExecuteSQL(sql);
			MessageBox(_T("�����ɹ�")); 
		}
		catch (CDBException* e)
		{
			MessageBox(_T("������Ϸ���SQL��䣡"));
		}
		
	}
		
}


void CSqlExe::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	mianMenu dlg;
	dlg.DoModal();
	CDialogEx::OnOK();
	CDialogEx::OnCancel();
}


void CSqlExe::OnBnClickedchaxun()
{
	CString select;
	CString stuid;
	GetDlgItemText(IDC_OP_SELECT, select);
	GetDlgItemText(IDC_STU_ID, stuid);
	CDatabase db;
	db.Open(_T("studentinfor"));
	CRecordset rec(&db);
	CString strSql;

	if (stuid.IsEmpty())
	{
		MessageBox(_T("����Ϊ��!"));
		return;
	}
	 if (select == "ѧ����Ϣϵͳ")
	{
		 strSql.Format(_T("SELECT SNO,SNAME,SAGE,SDEPT FROM StuInfo WHERE SNO='%s'"), stuid);
		 rec.Open(CRecordset::forwardOnly, strSql, CRecordset::readOnly);
		 int n = rec.GetODBCFieldCount();
		 CString *str1 = new CString[n];
		 myList.DeleteAllItems();
		 if (rec.IsEOF())
		 {
			 MessageBox(_T("�Բ���,û���ҵ���Ҫ�ҵ���Ϣ"));
			 return;
		 }
		 else
		 {
			 myList.DeleteAllItems();
			 for (int i = 0; i < 5; i++)
			 {
				 myList.DeleteColumn(0);
			 }
			 CRect rect;
			 myList.GetClientRect(&rect);
			 myList.SetExtendedStyle(myList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
			 myList.InsertColumn(0, _T("ѧ��"), LVCFMT_CENTER, rect.Width() / 4, 0);
			 myList.InsertColumn(1, _T("����"), LVCFMT_CENTER, rect.Width() / 4, 0);
			 myList.InsertColumn(2, _T("����"), LVCFMT_CENTER, rect.Width() / 4, 0);
			 myList.InsertColumn(3, _T("רҵ"), LVCFMT_CENTER, rect.Width() / 4, 0);

			 short int i = 0;
			 CString sno, sname, sage,major;
			 rec.GetFieldValue(i++, sno);
			 rec.GetFieldValue(i++, sname);
			 rec.GetFieldValue(i++, sage);
			 rec.GetFieldValue(i++, major);
			 rec.Close();
			 CString str11, str22, str33,str44;
			 str11.Format(_T("%s"), sno);
			 str22.Format(_T("%s"), sname);
			 str33.Format(_T("%s"), sage);
			 str44.Format(_T("%s"), major);
/*
			 myList.DeleteAllItems();
			 for (int i = 0; i < 5; i++)
			 {
				 myList.DeleteColumn(0);
			 }
			 CRect rect;
			 myList.GetClientRect(&rect);
			 myList.SetExtendedStyle(myList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
			 myList.InsertColumn(0, _T("ѧ��"), LVCFMT_CENTER, rect.Width() / 4, 0);
			 myList.InsertColumn(1, _T("����"), LVCFMT_CENTER, rect.Width() / 4, 0);
			 myList.InsertColumn(2, _T("����"), LVCFMT_CENTER, rect.Width() / 4, 0);
			 myList.InsertColumn(3, _T("רҵ"), LVCFMT_CENTER, rect.Width() / 4, 0);
			 CRecordset rec(&db);
			 if (rec.IsEOF())
			 {
				 MessageBox(_T("�Բ���,û���ҵ���Ҫ�ҵ���Ϣ"));
				 return;
			 }
			 int flag = 0;
			 while (!rec.IsEOF())
			 {

				 for (int i = 0; i<n; i++)
				 {
					 rec.GetFieldValue(i, str1[i]);
				 }
				 int i = 0;
				 myList.InsertItem(flag, str1[i++]);
				 myList.SetItemText(flag, 1, str1[i++]);
				 myList.SetItemText(flag, 2, str1[i++]);
				 myList.SetItemText(flag, 3, str1[i++]);
				 flag++;
				 rec.MoveNext();

			 }
			 */
			 rec.Close();
			 db.Close();
			 myList.InsertItem(0, str11);
			 myList.SetItemText(0, 1, str22);
			 myList.SetItemText(0, 2, str33);
			 myList.SetItemText(0, 3, str44);
		 }
	
	}
	 else
	//else if (select == "ѡ����Ϣϵͳ��Ĭ�ϣ�SC��")
	{
		strSql.Format(_T("SELECT SNO,CNO,GRADE FROM StuClass WHERE SNO='%s'"), stuid);
		rec.Open(CRecordset::forwardOnly, strSql, CRecordset::readOnly);
		/*int n = rec.GetODBCFieldCount();
		CString *str1 = new CString[n];
		myList.DeleteAllItems();*/
		if (rec.IsEOF())
		{
			MessageBox(_T("�Բ���,û���ҵ���Ҫ�ҵ���Ϣ"));
			return;
		}
		else
		{
			try 
			{
				//rec.Open(CRecordset::forwardOnly, strSql, CRecordset::readOnly);
				int n = rec.GetODBCFieldCount();
				CString *str1 = new CString[n];
				myList.DeleteAllItems();
				for (int i = 0; i < 5; i++)
				{
					myList.DeleteColumn(0);
				}
				CRect rect;
				myList.GetClientRect(&rect);
				myList.SetExtendedStyle(myList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
				myList.InsertColumn(0, _T("ѧ��"), LVCFMT_CENTER, rect.Width() / 3, 0);
				myList.InsertColumn(1, _T("�γ̺�"), LVCFMT_CENTER, rect.Width() / 3, 0);
				myList.InsertColumn(2, _T("�ɼ�"), LVCFMT_CENTER, rect.Width() / 3, 0);
				int flag = 0;
				while (!rec.IsEOF())
				{

					for (int i = 0; i < n; i++)
					{
						rec.GetFieldValue(i, str1[i]);
					}
					int i = 0;
					myList.InsertItem(flag, str1[i++]);
					myList.SetItemText(flag, 1, str1[i++]);
					myList.SetItemText(flag, 2, str1[i++]);

					flag++;
					rec.MoveNext();

				}
				rec.Close();
				db.Close();
			}
		catch (CDBException* e)
		{
			MessageBox(_T("������Ч��"));
			//AfxMessageBox(e->m_strError);
			return;
		}


/*
			short int i = 0;
			CString sno, cno, grade;
			rec.GetFieldValue(i++, sno);
			rec.GetFieldValue(i++, cno);
			rec.GetFieldValue(i++, grade);
			rec.Close();
			CString str11, str22, str33;
			str11.Format(_T("%s"), sno);
			str22.Format(_T("%s"), cno);
			str33.Format(_T("%s"), grade);

			myList.DeleteAllItems();
			for (int i = 0; i < 4; i++)
			{
				myList.DeleteColumn(0);
			}
			CRect rect;
			myList.GetClientRect(&rect);
			myList.SetExtendedStyle(myList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
			myList.InsertColumn(0, _T("ѧ��"), LVCFMT_CENTER, rect.Width() / 3, 0);
			myList.InsertColumn(1, _T("�γ̺�"), LVCFMT_CENTER, rect.Width() / 3, 0);
			myList.InsertColumn(2, _T("�ɼ�"), LVCFMT_CENTER, rect.Width() / 3, 0);
			myList.InsertItem(0, str11);
			myList.SetItemText(0, 1, str22);
			myList.SetItemText(0, 2, str33);
*/
		}
	}

}  


/*
void CSqlExe::OnLbnSelchangeListOut()
{
	
}
*/

void CSqlExe::OnLvnItemchangedListOut(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	*pResult = 0;
}
