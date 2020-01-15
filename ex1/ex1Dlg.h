
// ex1Dlg.h : 헤더 파일
//

#pragma once


// Cex1Dlg 대화 상자
class Cex1Dlg : public CDialogEx
{
// 생성입니다.
public:
	Cex1Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EX1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
	int start; // 0=플러스 1=마이너스 2=곱하기 3=나누기
	double first; // 계산전의 수
	afx_msg void OnBnClickedButtonfinish();
	afx_msg void OnBnClickedButtonclear();
	afx_msg void OnBnClickedButtonpoint();
	BOOL PreTranslateMessage(MSG * pMsg);
	afx_msg void OnBnClickedButtonback();
	CString str2;
};
