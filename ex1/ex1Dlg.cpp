
// ex1Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ex1.h"
#include "ex1Dlg.h"
#include "afxdialogex.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cex1Dlg ��ȭ ����



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


// Cex1Dlg �޽��� ó����

BOOL Cex1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void Cex1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR Cex1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cex1Dlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str+L"1");
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"1");
}


void Cex1Dlg::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + L"2");
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"2");
}


void Cex1Dlg::OnBnClickedButton3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + L"3");
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"3");
}


void Cex1Dlg::OnBnClickedButton4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + L"4");
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"4");
}


void Cex1Dlg::OnBnClickedButton5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + L"5");
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"5");
}


void Cex1Dlg::OnBnClickedButton6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + L"6");
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"6");
}


void Cex1Dlg::OnBnClickedButton7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + L"7");
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"7");
}


void Cex1Dlg::OnBnClickedButton8()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + L"8");
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"8");
}


void Cex1Dlg::OnBnClickedButton9()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + L"9");
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"9");
}


void Cex1Dlg::OnBnClickedButton10()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + L"0");
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"0");
}

void Cex1Dlg::OnBnClickedButtonplus()//�÷���
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	start = 0;
	CString firsts;
	GetDlgItemText(IDC_EDIT1,firsts);
	first = _wtof(firsts);
	SetDlgItemText(IDC_EDIT1, L" ");
	CString str;
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"+");
}


void Cex1Dlg::OnBnClickedButtonMinus()//���̳ʽ�
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	start = 1;
	CString firsts;
	GetDlgItemText(IDC_EDIT1, firsts);
	first = _wtof(firsts);
	SetDlgItemText(IDC_EDIT1, L" ");
	CString str;
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"-");
}




void Cex1Dlg::OnBnClickedButtonmultiply()//���ϱ�
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	start = 2;
	CString firsts;
	GetDlgItemText(IDC_EDIT1, firsts);
	first = _wtof(firsts);
	SetDlgItemText(IDC_EDIT1, L" ");
	CString str;
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"*");
}


void Cex1Dlg::OnBnClickedButtondivision()//������
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	switch (start) {
	case 0 : // +
	{
		CString str;
		GetDlgItemText(IDC_EDIT1, str);

		double num1 = _wtof(str); //�Ǽ�����ȯ
		int bb = first + num1; // ��������� ������ ��ȯ

		if ((first + num1) - bb > 0) {		// �������� �Ҽ����� �����ٴ°��� �̿��Ͽ� �Ǽ�-������ ��� �Ҽ��� ������ ���� �ִ°��
			str.Format(L"%g", first + num1);
			SetDlgItemText(IDC_EDIT1, str);
		}
		else { // �Ǽ�-������ 0�λ��� �Ҽ��� ������ ���� ���°��
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

		if ((first - num1) - bb > 0) {		//�Ҽ��� ������ ���� �ִ°��
			str.Format(L"%g", first - num1);
			SetDlgItemText(IDC_EDIT1, str);
			
		}
		else {	// �Ǽ�-������ 0�λ��� �Ҽ��� ������ ���� ���°��
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

		if ((first * num1) - bb > 0) {		//�Ҽ��� ������ ���� �ִ°��
			str.Format(L"%g", first * num1);
			SetDlgItemText(IDC_EDIT1, str);
		}
		else {	// �Ǽ�-������ 0�λ��� �Ҽ��� ������ ���� ���°��
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

		if ((first/num1) -bb > 0) {		//�Ҽ��� ������ ���� �ִ°��
			str.Format(L"%g", first / num1);
			SetDlgItemText(IDC_EDIT1, str);
		}
		else {	// �Ǽ�-������ 0�λ��� �Ҽ��� ������ ���� ���°��
			SetDlgItemInt(IDC_EDIT1, first / num1);
		}
		break;
	}
	}
}


void Cex1Dlg::OnBnClickedButtonclear() // Ŭ����
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetDlgItemText(IDC_EDIT1, L" ");
	SetDlgItemText(IDC_EDIT2, L" ");
}


void Cex1Dlg::OnBnClickedButtonpoint() //�Ҽ����Է�
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
		//  Ű������ 1 Ű �϶�
		if (pMsg->wParam == 49)
		{
			OnBnClickedButton1();  //  1�Լ� ó��

			return TRUE;
		}
		//  Ű������ 2Ű �϶�
		if (pMsg->wParam == 50)
		{
			OnBnClickedButton2();  //  2�Լ� ó��

			return TRUE;
		}
		//  Ű������ 3 Ű �϶�
		if (pMsg->wParam == 51)
		{
			OnBnClickedButton3();  //  3�Լ� ó��

			return TRUE;
		}
		//  Ű������ 4 Ű �϶�
		if (pMsg->wParam == 52)
		{
			OnBnClickedButton4();  //  4�Լ� ó��

			return TRUE;
		}
		//  Ű������ 5 Ű �϶�
		if (pMsg->wParam == 53)
		{
			OnBnClickedButton5();  //  5�Լ� ó��

			return TRUE;
		}
		//  Ű������ 6 Ű �϶�
		if (pMsg->wParam == 54)
		{
			OnBnClickedButton6();  //  6�Լ� ó��

			return TRUE;
		}
		//  Ű������ 7 Ű �϶�
		if (pMsg->wParam == 55)
		{
			OnBnClickedButton7();  //  7�Լ� ó��

			return TRUE;
		}
		//  Ű������ 8 Ű �϶�
		if (pMsg->wParam == 56)
		{
			OnBnClickedButton8();  //  8�Լ� ó��

			return TRUE;
		}
		//  Ű������ 9 Ű �϶�
		if (pMsg->wParam == 57)
		{
			OnBnClickedButton9();  //  9�Լ� ó��

			return TRUE;
		}
		//  Ű������ 0 Ű �϶�
		if (pMsg->wParam == 48)
		{
			OnBnClickedButton10();  //  0�Լ� ó��

			return TRUE;
		}
		// ����Ű
		if ((pMsg->message == WM_KEYDOWN) && (pMsg->wParam == VK_RETURN))
		{
			OnBnClickedButtonfinish();	//finish �Լ�ó��
			return true;
		}
		// escŰ
		if ((pMsg->message == WM_KEYDOWN) && (pMsg->wParam == VK_ESCAPE))
		{
			OnBnClickedButtonclear();
			return true;
		}
		//  Ű�е��� + Ű �϶�
		if (pMsg->wParam == 107)
		{
			OnBnClickedButtonplus();  //  plus�Լ� ó��

			return TRUE;
		}
		//  Ű�е��� - Ű �϶�
		if (pMsg->wParam == 109)
		{
			OnBnClickedButtonMinus();  //  minus�Լ� ó��

			return TRUE;
		}
		//  Ű�е��� * Ű �϶�
		if (pMsg->wParam == 106)
		{
			OnBnClickedButtonmultiply();  //  multiply�Լ� ó��

			return TRUE;
		}
		//  Ű�е��� / Ű �϶�
		if (pMsg->wParam == 111)
		{
			OnBnClickedButtondivision();  //  division�Լ� ó��

			return TRUE;
		}
		// Ű�е��� .Ű �϶�
		if (pMsg->wParam == 110)
		{
			OnBnClickedButtonpoint();  //  division�Լ� ó��

			return TRUE;
		}
		// �齺���̽�
		if (pMsg->wParam == 8)
		{
			OnBnClickedButtonback();

			return TRUE;
		}

	}
	return CDialog::PreTranslateMessage(pMsg);
}




void Cex1Dlg::OnBnClickedButtonback() //1���ڸ� �����
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	
	CString str;
	CString str2;
	GetDlgItemText(IDC_EDIT1, str);
	GetDlgItemText(IDC_EDIT2, str2);

	str = str.Left(str.GetLength() - 1); // ���ڿ� str�� ���̸� 1ĭ ���δ�.

	SetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT2, str);
}


void Cex1Dlg::OnBnClickedroot() //��Ʈ
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	double num1 = _wtof(str);
	num1 = sqrt(num1);
	str.Format(_T("%f"), num1);
	SetDlgItemText(IDC_EDIT1,str);

	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + L"��");
}


void Cex1Dlg::OnBnClickedButtonvalue() //�ø���ȯ
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	double n, num1= _wtof(str);
	n = num1*-1;
	str.Format(_T("%g"), n);
	SetDlgItemText(IDC_EDIT1, str);

	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, L"-"+str);

}
