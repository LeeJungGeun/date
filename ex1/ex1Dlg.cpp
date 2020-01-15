
// ex1Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ex1.h"
#include "ex1Dlg.h"
#include "afxdialogex.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cex1Dlg 대화 상자



Cex1Dlg::Cex1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EX1_DIALOG, pParent)
	, start(0)
	, first(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cex1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cex1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cex1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cex1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cex1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Cex1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Cex1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &Cex1Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &Cex1Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &Cex1Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &Cex1Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &Cex1Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON12, &Cex1Dlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTONPlus, &Cex1Dlg::OnBnClickedButtonplus)
	ON_BN_CLICKED(IDC_BUTTON13, &Cex1Dlg::OnBnClickedButtonmultiply)
	ON_BN_CLICKED(IDC_BUTTON14, &Cex1Dlg::OnBnClickedButtondivision)
	ON_BN_CLICKED(IDC_BUTTON16, &Cex1Dlg::OnBnClickedButtonfinish)
	ON_BN_CLICKED(IDC_BUTTON15, &Cex1Dlg::OnBnClickedButtonclear)
	ON_BN_CLICKED(IDC_BUTTONpoint, &Cex1Dlg::OnBnClickedButtonpoint)
	ON_BN_CLICKED(IDC_BUTTONback, &Cex1Dlg::OnBnClickedButtonback)
	ON_BN_CLICKED(root, &Cex1Dlg::OnBnClickedroot)
	ON_BN_CLICKED(IDC_BUTTONvalue, &Cex1Dlg::OnBnClickedButtonvalue)
END_MESSAGE_MAP()


// Cex1Dlg 메시지 처리기

BOOL Cex1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Cex1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Cex1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cex1Dlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str+L"1");
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"1");
}


void Cex1Dlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + L"2");
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"2");
}


void Cex1Dlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + L"3");
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"3");
}


void Cex1Dlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + L"4");
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"4");
}


void Cex1Dlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + L"5");
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"5");
}


void Cex1Dlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + L"6");
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"6");
}


void Cex1Dlg::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + L"7");
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"7");
}


void Cex1Dlg::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + L"8");
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"8");
}


void Cex1Dlg::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + L"9");
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"9");
}


void Cex1Dlg::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + L"0");
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"0");
}

void Cex1Dlg::OnBnClickedButtonplus()//플러스
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	start = 0;
	CString firsts;
	GetDlgItemText(IDC_EDIT1,firsts);
	first = _wtof(firsts);
	SetDlgItemText(IDC_EDIT1, L" ");
	CString str;
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"+");
}


void Cex1Dlg::OnBnClickedButtonMinus()//마이너스
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	start = 1;
	CString firsts;
	GetDlgItemText(IDC_EDIT1, firsts);
	first = _wtof(firsts);
	SetDlgItemText(IDC_EDIT1, L" ");
	CString str;
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"-");
}




void Cex1Dlg::OnBnClickedButtonmultiply()//곱하기
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	start = 2;
	CString firsts;
	GetDlgItemText(IDC_EDIT1, firsts);
	first = _wtof(firsts);
	SetDlgItemText(IDC_EDIT1, L" ");
	CString str;
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"*");
}


void Cex1Dlg::OnBnClickedButtondivision()//나누기
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	start = 3;
	CString firsts;
	GetDlgItemText(IDC_EDIT1, firsts);
	first = _wtof(firsts);
	SetDlgItemText(IDC_EDIT1, L" ");
	CString str;
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"/");
}


void Cex1Dlg::OnBnClickedButtonfinish()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	switch (start) {
	case 0 : // +
	{
		CString str;
		GetDlgItemText(IDC_EDIT1, str);

		double num1 = _wtof(str); //실수형변환
		int bb = first + num1; // 최종결과값 정수형 변환

		if ((first + num1) - bb > 0) {		// 정수형의 소숫점은 버린다는것을 이용하여 실수-정수를 계산 소숫점 이하의 수가 있는경우
			str.Format(L"%g", first + num1);
			SetDlgItemText(IDC_EDIT1, str);
		}
		else { // 실수-정수가 0인상태 소숫점 이하의 수가 없는경우
			SetDlgItemInt(IDC_EDIT1, first+num1);
		}
		break;
	}
	case 1: // -
	{
		CString str;
		GetDlgItemText(IDC_EDIT1, str);

		double num1 = _wtof(str);
		int bb = first - num1;

		if ((first - num1) - bb > 0) {		//소숫점 이하의 수가 있는경우
			str.Format(L"%g", first - num1);
			SetDlgItemText(IDC_EDIT1, str);
			
		}
		else {	// 실수-정수가 0인상태 소숫점 이하의 수가 없는경우
			SetDlgItemInt(IDC_EDIT1, first - num1);
		}
		break;
	}
	case 2: // *
	{
		CString str;
		GetDlgItemText(IDC_EDIT1, str);

		double num1 = _wtof(str);
		int bb = first * num1;

		if ((first * num1) - bb > 0) {		//소숫점 이하의 수가 있는경우
			str.Format(L"%g", first * num1);
			SetDlgItemText(IDC_EDIT1, str);
		}
		else {	// 실수-정수가 0인상태 소숫점 이하의 수가 없는경우
			SetDlgItemInt(IDC_EDIT1, first * num1);
		}
		break;
	}
	case 3: // /
	{
		CString str;
		GetDlgItemText(IDC_EDIT1, str);

		double num1 = _wtof(str);
		int bb = first / num1;

		if ((first/num1) -bb > 0) {		//소숫점 이하의 수가 있는경우
			str.Format(L"%g", first / num1);
			SetDlgItemText(IDC_EDIT1, str);
		}
		else {	// 실수-정수가 0인상태 소숫점 이하의 수가 없는경우
			SetDlgItemInt(IDC_EDIT1, first / num1);
		}
		break;
	}
	}
}


void Cex1Dlg::OnBnClickedButtonclear() // 클리어
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetDlgItemText(IDC_EDIT1, L" ");
	SetDlgItemText(IDC_EDIT2, L" ");
}


void Cex1Dlg::OnBnClickedButtonpoint() //소숫점입력
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + L".");

	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L".");
}

BOOL Cex1Dlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		//  키보드의 1 키 일때
		if (pMsg->wParam == 49)
		{
			OnBnClickedButton1();  //  1함수 처리

			return TRUE;
		}
		//  키보드의 2키 일때
		if (pMsg->wParam == 50)
		{
			OnBnClickedButton2();  //  2함수 처리

			return TRUE;
		}
		//  키보드의 3 키 일때
		if (pMsg->wParam == 51)
		{
			OnBnClickedButton3();  //  3함수 처리

			return TRUE;
		}
		//  키보드의 4 키 일때
		if (pMsg->wParam == 52)
		{
			OnBnClickedButton4();  //  4함수 처리

			return TRUE;
		}
		//  키보드의 5 키 일때
		if (pMsg->wParam == 53)
		{
			OnBnClickedButton5();  //  5함수 처리

			return TRUE;
		}
		//  키보드의 6 키 일때
		if (pMsg->wParam == 54)
		{
			OnBnClickedButton6();  //  6함수 처리

			return TRUE;
		}
		//  키보드의 7 키 일때
		if (pMsg->wParam == 55)
		{
			OnBnClickedButton7();  //  7함수 처리

			return TRUE;
		}
		//  키보드의 8 키 일때
		if (pMsg->wParam == 56)
		{
			OnBnClickedButton8();  //  8함수 처리

			return TRUE;
		}
		//  키보드의 9 키 일때
		if (pMsg->wParam == 57)
		{
			OnBnClickedButton9();  //  9함수 처리

			return TRUE;
		}
		//  키보드의 0 키 일때
		if (pMsg->wParam == 48)
		{
			OnBnClickedButton10();  //  0함수 처리

			return TRUE;
		}
		// 엔터키
		if ((pMsg->message == WM_KEYDOWN) && (pMsg->wParam == VK_RETURN))
		{
			OnBnClickedButtonfinish();	//finish 함수처리
			return true;
		}
		// esc키
		if ((pMsg->message == WM_KEYDOWN) && (pMsg->wParam == VK_ESCAPE))
		{
			OnBnClickedButtonclear();
			return true;
		}
		//  키패드의 + 키 일때
		if (pMsg->wParam == 107)
		{
			OnBnClickedButtonplus();  //  plus함수 처리

			return TRUE;
		}
		//  키패드의 - 키 일때
		if (pMsg->wParam == 109)
		{
			OnBnClickedButtonMinus();  //  minus함수 처리

			return TRUE;
		}
		//  키패드의 * 키 일때
		if (pMsg->wParam == 106)
		{
			OnBnClickedButtonmultiply();  //  multiply함수 처리

			return TRUE;
		}
		//  키패드의 / 키 일때
		if (pMsg->wParam == 111)
		{
			OnBnClickedButtondivision();  //  division함수 처리

			return TRUE;
		}
		// 키패드의 .키 일때
		if (pMsg->wParam == 110)
		{
			OnBnClickedButtonpoint();  //  division함수 처리

			return TRUE;
		}
		// 백스페이스
		if (pMsg->wParam == 8)
		{
			OnBnClickedButtonback();

			return TRUE;
		}

	}
	return CDialog::PreTranslateMessage(pMsg);
}




void Cex1Dlg::OnBnClickedButtonback() //1글자만 지우기
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	CString str;
	CString str2;
	GetDlgItemText(IDC_EDIT1, str);
	GetDlgItemText(IDC_EDIT2, str2);

	str = str.Left(str.GetLength() - 1); // 문자열 str의 길이를 1칸 줄인다.

	SetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT2, str);
}


void Cex1Dlg::OnBnClickedroot() //루트
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	double num1 = _wtof(str);
	num1 = sqrt(num1);
	str.Format(_T("%f"), num1);
	SetDlgItemText(IDC_EDIT1,str);

	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"√");
}


void Cex1Dlg::OnBnClickedButtonvalue() //플마변환
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	double n, num1= _wtof(str);
	n = num1*-1;
	str.Format(_T("%g"), n);
	SetDlgItemText(IDC_EDIT1, str);

	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, L"-"+str);

}
