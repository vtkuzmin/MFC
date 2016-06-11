// DlgProperties.cpp: ���� ����������
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "CDlgProperties.h"
#include "afxdialogex.h"


// ���������� ���� CDlgProperties

IMPLEMENT_DYNAMIC(CDlgProperties, CDialogEx)

CDlgProperties::CDlgProperties(double A1,double A, double A2, double A3, double angle, CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgProperties::IDD, pParent)
	, m_A1(A1)
	, m_A(A)
	, m_A2(A2)
	, m_A3(A3)
	, m_Angle(angle)
{

}

CDlgProperties::~CDlgProperties()
{
}

void CDlgProperties::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_A1);
	DDX_Text(pDX, IDC_EDIT2, m_A);
	DDV_MinMaxDouble(pDX, m_A, 0, 1000);
	DDX_Text(pDX, IDC_EDIT3, m_A2);
	DDV_MinMaxDouble(pDX, m_A2, 0, 10000);
	DDX_Text(pDX, IDC_EDIT4, m_A3);
	DDV_MinMaxDouble(pDX, m_A3, 0, 1000);
	DDX_Text(pDX, IDC_EDIT5, m_Angle);
}


BEGIN_MESSAGE_MAP(CDlgProperties, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CDlgProperties::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &CDlgProperties::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgProperties::OnBnClickedCancel)
END_MESSAGE_MAP()


// ����������� ��������� CDlgProperties


void CDlgProperties::OnEnChangeEdit1()
{
	// TODO:  ���� ��� ������� ���������� RICHEDIT, �� ������� ���������� �� �����
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  �������� ��� �������� ����������
}


void CDlgProperties::OnBnClickedOk()
{
	// TODO: �������� ���� ��� ����������� �����������
	CDialogEx::OnOK();
}


void CDlgProperties::OnBnClickedCancel()
{
	// TODO: �������� ���� ��� ����������� �����������
	//CEdit *cedit = 
	CDialogEx::OnCancel();
}
