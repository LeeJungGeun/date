
// ex1Dlg.h : ��� ����
//

#pragma once


// Cex1Dlg ��ȭ ����
class Cex1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	Cex1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EX1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonplus();
	afx_msg void OnBnClickedButtonmultiply();
	afx_msg void OnBnClickedButtondivision();
	int start; // 0=�÷��� 1=���̳ʽ� 2=���ϱ� 3=������
	double first; // ������� ��
	afx_msg void OnBnClickedButtonfinish();
	afx_msg void OnBnClickedButtonclear();
	afx_msg void OnBnClickedButtonpoint();
	BOOL PreTranslateMessage(MSG * pMsg);
	afx_msg void OnBnClickedButtonback();
	CString str2;
};
