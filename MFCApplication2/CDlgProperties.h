#pragma once


// диалоговое окно CDlgProperties

class CDlgProperties : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgProperties)

public:

	CDlgProperties(double A1 = 1.0,double A = 1.0,double A2 = 1.0,double A3 = 1.0, double angle = 1.0,  CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CDlgProperties();

// Данные диалогового окна
	enum { IDD = IDD_PROPERTIES };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	double m_A1;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	double m_A;
	double m_A2;
	double m_A3;
	double m_Angle;
};
