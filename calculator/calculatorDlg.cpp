#include "pch.h"
#include "framework.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include <string>
#include <math.h>
#include <iostream>
#include <sstream>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#define PI 3.1415926535897932

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()



CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_res = _T("");
	m_History = _T("");

	tempOperand = "";
	historyString = "";

	m_fNumber1 = 0.0f;
	m_fNumber2 = 0.0f;

	m_m = 0.0f;

	m_symbol = 1;
	m_time = 0;
	m_number = 0;

	m_iSign = 0;

	check = false;

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_RES, m_edit);
	DDX_Text(pDX, IDC_EDIT_HISTORY, m_History);
	DDX_Text(pDX, IDC_EDIT_RES, m_res);
	DDX_Control(pDX, IDC_LIST_CTRL, m_listBox);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON0, &CcalculatorDlg::OnButton0)
	ON_BN_CLICKED(IDC_BUTTON1, &CcalculatorDlg::OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CcalculatorDlg::OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CcalculatorDlg::OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CcalculatorDlg::OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CcalculatorDlg::OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CcalculatorDlg::OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CcalculatorDlg::OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CcalculatorDlg::OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CcalculatorDlg::OnButton9)
	ON_BN_CLICKED(IDC_BUTTON_BACKSPACE, &CcalculatorDlg::OnButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CcalculatorDlg::OnButtonClearall)
	ON_BN_CLICKED(IDC_BUTTON_CE, &CcalculatorDlg::OnButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_MC, &CcalculatorDlg::OnButtonMC)
	ON_BN_CLICKED(IDC_BUTTON_MR, &CcalculatorDlg::OnButtonMR)
	ON_BN_CLICKED(IDC_BUTTON_MS, &CcalculatorDlg::OnButtonMS)
	ON_BN_CLICKED(IDC_BUTTON_M_PLUS, &CcalculatorDlg::OnButtonMadd)
	ON_BN_CLICKED(IDC_BUTTON_M_SUB, &CcalculatorDlg::OnButtonMminus)
	ON_BN_CLICKED(IDC_BUTTON_NEGATE, &CcalculatorDlg::OnButtonNegate)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CcalculatorDlg::OnButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CcalculatorDlg::OnButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CcalculatorDlg::OnButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CcalculatorDlg::OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_LN, &CcalculatorDlg::OnButtonLn)
	ON_BN_CLICKED(IDC_BUTTON_LOG, &CcalculatorDlg::OnButtonLog)
	ON_BN_CLICKED(IDC_BUTTON_INVERSE, &CcalculatorDlg::OnButtonInverse)
	ON_BN_CLICKED(IDC_BUTTON_PERCENTAGE, &CcalculatorDlg::OnButtonPrecent)
	ON_BN_CLICKED(IDC_BUTTON_SQRT, &CcalculatorDlg::OnButtonSqrt)
	ON_BN_CLICKED(IDC_BUTTON_SIN, &CcalculatorDlg::OnButtonSin)
	ON_BN_CLICKED(IDC_BUTTON_COS, &CcalculatorDlg::OnButtonCos)
	ON_BN_CLICKED(IDC_BUTTON_TAN, &CcalculatorDlg::OnButtonTan)
	ON_BN_CLICKED(IDC_BUTTON_PI, &CcalculatorDlg::OnButtonPI)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CcalculatorDlg::OnButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_COMMA, &CcalculatorDlg::OnButtonComma)
	ON_BN_CLICKED(IDC_BUTTON_CLEARHISTORY, &CcalculatorDlg::OnBnClickedButtonClearhistory)
	ON_BN_CLICKED(IDC_BUTTON_EDIT, &CcalculatorDlg::OnBnClickedButtonEdit)
	ON_BN_CLICKED(IDC_BUTTON_RECALC, &CcalculatorDlg::OnBnClickedButtonRecalc)
	ON_BN_CLICKED(IDC_BUTTON_UP, &CcalculatorDlg::OnBnClickedButtonUp)
	ON_BN_CLICKED(IDC_BUTTON_DOWN, &CcalculatorDlg::OnBnClickedButtonDown)
	ON_NOTIFY(LVN_ENDLABELEDIT, IDC_LIST_CTRL, &CcalculatorDlg::OnLvnEndlabeleditListCtrl)
	ON_NOTIFY(NM_CLICK, IDC_LIST_CTRL, &CcalculatorDlg::OnNMClickListCtrl)
END_MESSAGE_MAP()



BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		

	m_fNumber1 = 0.0f;
	historyString = "";
	m_m = 0;

	loadList();
	SetFocus();

	return TRUE;  
}


void CcalculatorDlg::loadList() {
	m_listBox.SetFocus();
	int s = m_listBox.GetItemCount();
	m_listBox.SetItemState(s, ~LVIS_SELECTED, LVIS_SELECTED);
	m_listBox.SetItemState(s - 1, LVIS_SELECTED, LVIS_SELECTED);
	m_listBox.SetSelectionMark(s - 1);
	iItem = m_listBox.GetItemCount() - 1;
}


void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
		CDialogEx::OnSysCommand(nID, lParam);
}


void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}


HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// convert double to CString and show result on the screen
void CcalculatorDlg::str_to_double(double f, CString &m_temp)
{
	if (m_symbol == 1)
	{
		// if the floating point number is actually an integer
		if (f - int(f) <= 1e-9)
			m_temp.Format(_T("%d"), (int)f);
		
		else
		{
			m_temp.Format(_T("%.8f"), f);
			if (m_temp.Find('.') != -1)
			{
				int count = 0;
				for (int i = 0; i < m_temp.GetLength(); i++)
				{
					if (i == m_temp.Find('0', i))
						count++;
					else
						count = 0;
				}
				m_temp = m_temp.Left((m_temp.GetLength() - count));
			}
		}
	}
	else
	{
		// if the floating point number is actually an integer
		if ((-f - int(f)) <= 1e-9)
			m_temp.Format(_T("%d"), -(int)f);

		else
		{
			// m_temp.Format(_T("%.8f"), f);
			std::ostringstream ss;
			ss << f;
			m_temp = (ss.str()).c_str();

			/*std::string temp = std::to_string(f);
			temp.erase(temp.find_last_not_of('0') + 1, std::string::npos);

			m_temp = temp.c_str();*/

			if (m_temp.Find('.') != -1)
			{
				int count = 0;
				for (int i = 0; i < m_temp.GetLength(); i++)
				{
					if (i == m_temp.Find('0', i))
						count++;
					else
						count = 0;
				}
				m_temp = m_temp.Left((m_temp.GetLength() - count));
			}
		}
	}
}


void CcalculatorDlg::addCharacter(char c) {
	if (!isdigit(c) && c != '.') {	// if input is an operator

		if (tempOperand.empty()) {	// if tempOperand string is empty
			if (!historyString.empty()) {	// case 1: historyString is not empty => 2 operators consecutive
				historyString.back() = c; // update latest operator in historyString
				m_History = historyString.c_str();
				UpdateData(FALSE);
				return;
			}

			else { // case 2: historyString is empty => operators inputed when nothing on screen

				std::ostringstream ss;
				ss << m_fNumber1;

				historyString = ss.str();
				m_History = historyString.c_str();
			}
		}
		else {
			m_res = tempOperand.c_str();
			m_fNumber2 = _wtof(m_res.GetBuffer(0));

			if (m_fNumber2 == 0.0f && getLastOp(historyString) == '/') {
				m_res = "Cannot divide by zero!";
				historyString = "";
				m_History.Empty();
				tempOperand = "";
				UpdateData(FALSE);
				return;
			}	
			
			doOperation(m_fNumber1, m_fNumber2, getLastOp(historyString));
			tempOperand = "";
		}
	}

	else {	// if input is digit or comma

		if (historyString.empty() && m_fNumber1 != 0) m_fNumber1 = 0; // after equal button pressed, start new operation
		tempOperand += c;
		historyString += c;
		m_res = tempOperand.c_str();
		UpdateData(FALSE);
		return;
	}

	historyString += c;
	m_History = historyString.c_str();
	str_to_double(m_fNumber1, m_res);  // show output on screen 
	UpdateData(FALSE);

}


// do operation
void CcalculatorDlg::doOperation(double &a, double &b, char op) {
	if (op == '+') {
		a += b;
		if (a < 0)
			m_symbol = -1;
		else
			m_symbol = 1;
		str_to_double(a, m_res);
	}
	if (op == '-') {
		a -= b;
		if (a < 0)
			m_symbol = -1;
		else
			m_symbol = 1;
		str_to_double(a, m_res);
	}
	if (op == '*') {
		a *= b;
		if (a < 0)
			m_symbol = -1;
		else
			m_symbol = 1;
		str_to_double(a, m_res);
	}
	if (op == '/') {
		if (b == 0.0f)
		{
			m_res = (CString)"Cannot divided by zero!";
			m_number = 0;
			m_time = 0;
			m_symbol = 1;
		}
		else
		{
			a /= b;
			if (a < 0)
				m_symbol = -1;
			else
				m_symbol = 1;
			str_to_double(a, m_res);
		}
	}
}


// get last operation, incase user click multiple operator buttons
char CcalculatorDlg::getLastOp(const std::string& operations) {
	if (m_symbol == -1 && operations[0] != '-') {
		for (int i = operations.length() - 1; i >= 0; i--) {
			if (operations[i] == '-') {
				return operations[i - 1];
				break;
			}
		}
		return '+';
	}
	else {
		for (int i = operations.length() - 1; i >= 0; i--) {
			if (operations[i] == '+' ||
				operations[i] == '-' ||
				operations[i] == '*' ||
				operations[i] == '/')
				return operations[i];
		}
		return '+';
	}

}


void CcalculatorDlg::OnButtonEqual()
{
	for(int i = m_listBox.GetItemCount(); i >= 0; i--)
		m_listBox.SetItemState(i, ~LVIS_SELECTED, LVIS_SELECTED);


	if (!tempOperand.empty()) {

		m_res = tempOperand.c_str();
		m_fNumber2 = _wtof(m_res.GetBuffer(0));

		if (m_fNumber2 == 0.0f && getLastOp(historyString) == '/') {
			m_res = "Cannot divide by zero!";
			historyString = "";
			m_History.Empty();
			tempOperand = "";
			UpdateData(FALSE);
			return;
		}	// this if block handle divide by zero exception

		tempOperator = getLastOp(historyString);
		
		doOperation(m_fNumber1, m_fNumber2, getLastOp(historyString));
		tempOperand = "";

		m_History = historyString.c_str(); 
		historyString = "";
		str_to_double(m_fNumber1, m_res);

		CString res;
		res += m_History + _T("=") + m_res;
		m_listBox.InsertItem(m_listBox.GetItemCount() + 1, res);

		UpdateData(FALSE);
		loadList();
	}

	else if (tempOperand.empty() && historyString.empty()) {
		// if equal button is pressed keep doing previous operation
		std::ostringstream ss, ss1;
		ss << m_fNumber1;
		ss1 << m_fNumber2;
		std::string s = ss.str() + tempOperator + ss1.str();
		m_History.Empty();

		doOperation(m_fNumber1, m_fNumber2, tempOperator);
		str_to_double(m_fNumber1, m_res);
		
		if (m_fNumber1 == 0.0f && m_fNumber2 == 0.0f) {
			CString res;
			res += _T("=") + m_res;
			m_listBox.InsertItem(m_listBox.GetItemCount() + 1, res);
		}
		else {
			m_History = s.c_str();
			CString res;
			res += m_History + _T("=") + m_res;
			m_listBox.InsertItem(m_listBox.GetItemCount() + 1, res);
			
		}

		UpdateData(FALSE);
		loadList();
	}
}


// Positive or negative
void CcalculatorDlg::OnButtonNegate()
{
	for (int i = m_listBox.GetItemCount(); i >= 0; i--)
		m_listBox.SetItemState(i, ~LVIS_SELECTED, LVIS_SELECTED);

	if (!tempOperand.empty()) {
		double tempValue;
		std::string tempString;
		m_res = tempOperand.c_str();
		tempValue = _wtof(m_res.GetBuffer(0));

		historyString = historyString.substr(0, historyString.size() - tempOperand.size());
		tempOperand = "";
		tempValue = 0 - tempValue;

		/*tempString = std::to_string(tempValue);
		tempString.erase(tempString.find_last_not_of('0') + 1, std::string::npos);*/

		std::ostringstream ss;
		ss << tempValue;
		tempString = ss.str();


		doOperation(m_fNumber1, tempValue, getLastOp(historyString));


		historyString += tempString;
		str_to_double(m_fNumber1, m_res);
		m_History = historyString.c_str();

		CString res = m_History + _T("=") + m_res;
		m_listBox.InsertItem(m_listBox.GetItemCount() + 1, res);

		historyString = "";

		UpdateData(FALSE);
		loadList();
	}
	else if (tempOperand.empty() && historyString.empty()) {	//equal button pressed
		m_fNumber1 = 0 - (m_fNumber1);

		std::ostringstream ss;
		ss << m_fNumber1;

		m_res = (ss.str()).c_str();
		m_History = (ss.str()).c_str();

		CString res = m_History + _T("=") + m_res;
		m_listBox.InsertItem(m_listBox.GetItemCount() + 1, res);

		UpdateData(FALSE);
		m_symbol = 0 - m_symbol;
		loadList();
	}
}


void CcalculatorDlg::OnButtonPrecent()
{
	for (int i = m_listBox.GetItemCount(); i >= 0; i--)
		m_listBox.SetItemState(i, ~LVIS_SELECTED, LVIS_SELECTED);

	UpdateData(TRUE);
	m_fNumber2 = _wtof(m_res.GetBuffer(0));
	m_fNumber2 = m_fNumber2 * m_fNumber1 / 100;
	str_to_double(m_fNumber2, m_res);
	
	UpdateData(FALSE);
	loadList();

	m_number = 0;
}


// square root
// if u use this function along with other operators, "equal" pressed is required
// otherwise, single click on the sqrt button will show result
void CcalculatorDlg::OnButtonSqrt()
{
	for (int i = m_listBox.GetItemCount(); i >= 0; i--)
		m_listBox.SetItemState(i, ~LVIS_SELECTED, LVIS_SELECTED);

	if (m_symbol == -1 ||
		(m_res[0] == '-' && m_res.GetLength() == 1)
		|| (m_res[0] == '.' && m_res.GetLength() == 1))
	{
		m_res = (CString)"Invalid input for function.";
		m_number = 0;
		m_time = 0;
		m_symbol = 1;

		historyString = "";
		tempOperand = "";
		m_History.Empty();
		UpdateData(FALSE);
		return;
	}


	if (!tempOperand.empty()) {
		double tempValue;
		std::string tempString;
		//tempValue = stod(tempOperand);
		m_res = tempOperand.c_str();
		tempValue = _wtof(m_res.GetBuffer(0));

		std::ostringstream ss1;
		ss1 << tempValue;

		historyString = historyString.substr(0, historyString.size() - tempOperand.size());
			
		//m_temp = historyString.c_str();
		t += "sqrt(" + ss1.str() + ")";
		m_temp += t.c_str();

		tempOperand = "";
		tempValue = sqrt(tempValue);


		std::ostringstream ss;
		ss << tempValue;
		tempString = ss.str();

		for (int i = 0; i < tempString.size(); i++) {
			addCharacter(tempString.at(i));
		}


		//CString res = m_History + _T("=") + m_res;
		CString res = m_temp + _T("=") + m_res;
		m_listBox.InsertItem(m_listBox.GetItemCount() + 1, res);
		m_temp.Empty();
		t = "";
		UpdateData(FALSE);

		loadList();
	}

	else if (tempOperand.empty() && historyString.empty()) {	//equal button pressed
		std::ostringstream ss0;
		ss0 << m_fNumber1;

		m_fNumber1 = sqrt(m_fNumber1);

		/*std::ostringstream ss;
		ss << m_fNumber1;

		m_res = (ss.str()).c_str();*/

		str_to_double(m_fNumber1, m_res);

		m_temp = historyString.c_str();
		t += "sqrt(" + ss0.str() + ")";
		m_temp += t.c_str();

		//CString res = m_History + _T("=") + m_res;
		CString res = m_temp + _T("=") + m_res;
		m_listBox.InsertItem(m_listBox.GetItemCount() + 1, res);
		m_temp.Empty();
		UpdateData(FALSE);

		loadList();
	}
}


// this function is used to inverse a number
// if u use this function along with other operators, "equal" pressed is required
// otherwise, single click on the inverse button will show result
void CcalculatorDlg::OnButtonInverse()
{
	for (int i = m_listBox.GetItemCount(); i >= 0; i--)
		m_listBox.SetItemState(i, ~LVIS_SELECTED, LVIS_SELECTED);

	// exception handling
	double s = _wtof(m_res.GetBuffer(0));
	if (s == 0)
	{
		m_res = (CString)"Invalid input for function.";
		m_number = 0;
		m_time = 0;
		m_symbol = 1;

		historyString = "";
		tempOperand = "";
		m_History.Empty();
		UpdateData(FALSE);
		return;
	}

	if (m_symbol == 1) {
		UpdateData(TRUE);
		double tempValue;
		std::string tempString;
		tempValue = _wtof(m_res.GetBuffer(0));

		std::ostringstream ss1;
		ss1 << tempValue;

		historyString = historyString.substr(0, historyString.size() - tempOperand.size() - 1);

		t += "reciproc(" + ss1.str() + ")";
		m_temp += t.c_str();

		tempOperand = "";
		tempValue = 1 / tempValue;

		std::ostringstream ss;
		ss << tempValue;
		tempString = ss.str();

		historyString = "";
		m_History = historyString.c_str();

		for (int i = 0; i < tempString.length(); i++) {
			addCharacter(tempString.at(i));
		}
		m_res = tempString.c_str();

		// add to history panel
		CString res = m_temp + _T("=") + m_res;
		m_listBox.InsertItem(m_listBox.GetItemCount() + 1, res);
		m_temp.Empty();
		t = "";

		loadList();
	}

	else {
		UpdateData(TRUE);
		double tempValue;
		std::string tempString;
		tempValue = _wtof(m_res.GetBuffer(0));

		std::ostringstream ss1;
		ss1 << tempValue;

		historyString = historyString.substr(0, historyString.size() - tempOperand.size() - 1);

		t += "reciproc(" + ss1.str() + ")";
		m_temp += t.c_str();

		tempOperand = "";
		tempValue = 1 / tempValue;

		std::ostringstream ss;
		ss << tempValue;
		tempString = ss.str();

		historyString = "";
		m_History = historyString.c_str();

		m_res = tempString.c_str();

		CString res = m_temp + _T("=") + m_res;
		m_listBox.InsertItem(m_listBox.GetItemCount() + 1, res);
		m_temp.Empty();
		t = "";

		loadList();
	}

	if (tempOperand.empty() && historyString.empty()) {	//equal button pressed 

		m_fNumber1 = 1 / m_fNumber1;

		std::ostringstream ss1;
		ss1 << m_fNumber1;

		m_res = (ss1.str()).c_str();

		UpdateData(FALSE);

		loadList();
	}

}


// "CE" button
void CcalculatorDlg::OnButtonClear()
{
	UpdateData(TRUE);
	m_res = "";
	m_number = 0;
	UpdateData(FALSE);
}


// memory function////////////////////////////////////////////////////////////////////////

// save value to m_m
void CcalculatorDlg::OnButtonMS()
{
	UpdateData(TRUE);
	m_m = _wtof(m_res.GetBuffer(0));
	m_number = 0;
	UpdateData(FALSE);
}


// m_m recal
void CcalculatorDlg::OnButtonMR()
{
	UpdateData(TRUE);
	str_to_double(m_m, m_res);
	m_number = 0;
	UpdateData(FALSE);
}


// clear m_m
void CcalculatorDlg::OnButtonMC()
{
	UpdateData(TRUE);
	m_m = 0;
	m_number = 0;
	UpdateData(FALSE);
}


// add to m_m
void CcalculatorDlg::OnButtonMadd()
{
	UpdateData(TRUE);
	m_m += _wtof(m_res.GetBuffer(0));
	str_to_double(m_m, m_res);
	m_number = 0;
	UpdateData(FALSE);
}


// subtract from m_m
void CcalculatorDlg::OnButtonMminus()
{
	UpdateData(TRUE);
	m_m -= _wtof(m_res.GetBuffer(0));
	str_to_double(m_m, m_res);
	m_number = 0;
	UpdateData(FALSE);
}
/// //////////////////////////////////////////////////////////////////////////////////////




// aditional function////////////////////////////////////////////////////////////////////
void CcalculatorDlg::OnButtonSin()
{
	for (int i = m_listBox.GetItemCount(); i >= 0; i--)
		m_listBox.SetItemState(i, ~LVIS_SELECTED, LVIS_SELECTED);

	UpdateData(TRUE);
	m_fNumber1 = _wtof(m_res.GetBuffer(0));
	double f = sin(m_fNumber1 * PI / 180);
	str_to_double(f, m_res);

	std::ostringstream ss;
	ss << m_fNumber1;

	historyString = "";
	historyString += "sin(" + ss.str() + ")";
	m_History = historyString.c_str();

	CString res;
	res = m_History + _T("=") + m_res;
	m_listBox.InsertItem(m_listBox.GetItemCount() + 1, res);

	m_number = 0;

	UpdateData(FALSE);

	loadList();

	m_fNumber1 = f;
	m_fNumber2 = 0.0f;
}												


void CcalculatorDlg::OnButtonCos()
{
	for (int i = m_listBox.GetItemCount(); i >= 0; i--)
		m_listBox.SetItemState(i, ~LVIS_SELECTED, LVIS_SELECTED);

	UpdateData(TRUE);
	m_fNumber1 = _wtof(m_res.GetBuffer(0));
	double f = cos(m_fNumber1 * PI / 180);
	str_to_double(f, m_res);

	std::ostringstream ss;
	ss << m_fNumber1;

	historyString = "";
	historyString += "cos(" + ss.str() + ")";
	m_History = historyString.c_str();

	CString res;
	res = m_History + _T("=") + m_res;
	m_listBox.InsertItem(m_listBox.GetItemCount() + 1, res);

	m_number = 0;

	UpdateData(FALSE);

	loadList();

	m_fNumber1 = f;
	m_fNumber2 = 0.0f;
}


void CcalculatorDlg::OnButtonTan()
{
	for (int i = m_listBox.GetItemCount(); i >= 0; i--)
		m_listBox.SetItemState(i, ~LVIS_SELECTED, LVIS_SELECTED);

	UpdateData(TRUE);
	m_fNumber1 = _wtof(m_res.GetBuffer(0));
	if (cos(m_fNumber1 * PI / 180) <= 1e-5 && cos(m_fNumber1 * PI / 180) >= -1e-5)
	{
		m_res = (CString)"Invalid input for function.";
		m_time = 0;
		m_symbol = 1;
		UpdateData(FALSE);
		return;
	}
	else
	{
		double f = tan(m_fNumber1 * PI / 180);
		str_to_double(f, m_res);
		m_fNumber1 = f;
		m_fNumber2 = 0.0f;

		std::ostringstream ss;
		ss << m_fNumber1;

		historyString = "";
		historyString += "tan(" + ss.str() + ")";
		m_History = historyString.c_str();
	}

	CString res;
	res = m_History + _T("=") + m_res;
	m_listBox.InsertItem(m_listBox.GetItemCount() + 1, res);

	m_number = 0;

	loadList();

	UpdateData(FALSE);
}


void CcalculatorDlg::OnButtonPI()
{
	for (int i = m_listBox.GetItemCount(); i >= 0; i--)
		m_listBox.SetItemState(i, ~LVIS_SELECTED, LVIS_SELECTED);

	UpdateData(TRUE);
	str_to_double(PI, m_res);

	historyString = "";
	historyString += "PI";
	m_History = historyString.c_str();

	CString res;
	res = m_History + _T("=") + m_res;
	m_listBox.InsertItem(m_listBox.GetItemCount() + 1, res);

	UpdateData(FALSE);

	loadList();
}


void CcalculatorDlg::OnButtonLog()
{
	for (int i = m_listBox.GetItemCount(); i >= 0; i--)
		m_listBox.SetItemState(i, ~LVIS_SELECTED, LVIS_SELECTED);

	UpdateData(TRUE);
	m_fNumber1 = _wtof(m_res.GetBuffer(0));
	if (m_fNumber1 <= 0)
	{
		m_res = (CString)"Invalid input for funtion.";
		m_time = 0;
		m_symbol = 1;
		tempOperand = "";
		historyString = "";
		m_History.Empty();
		UpdateData(FALSE);
		return;
	}
	else
	{
		double f = log10(m_fNumber1);
		str_to_double(f, m_res);
		m_fNumber1 = f;
		m_fNumber2 = 0.0f;

		std::ostringstream ss;
		ss << m_fNumber1;

		historyString = "";
		historyString += "log(" + ss.str() + ")";
		m_History = historyString.c_str();
	}

	CString res;
	res = m_History + _T("=") + m_res;
	m_listBox.InsertItem(m_listBox.GetItemCount() + 1, res);

	m_number = 0;

	UpdateData(FALSE);

	loadList();
}


void CcalculatorDlg::OnButtonLn()
{
	for (int i = m_listBox.GetItemCount(); i >= 0; i--)
		m_listBox.SetItemState(i, ~LVIS_SELECTED, LVIS_SELECTED);

	UpdateData(TRUE);
	m_fNumber1 = _wtof(m_res.GetBuffer(0));
	if (m_fNumber1 <= 0)
	{
		m_res = (CString)"Invalid input for function.";
		m_time = 0;
		m_symbol = 1;
		tempOperand = "";
		historyString = "";
		m_History.Empty();
		UpdateData(FALSE);
		return;
	}
	else
	{
		double f = log(m_fNumber1);
		str_to_double(f, m_res);
		m_fNumber1 = f;
		m_fNumber2 = 0.0f;

		std::ostringstream ss;
		ss << m_fNumber1;

		historyString = "";
		historyString += "ln(" + ss.str() + ")";
		m_History = historyString.c_str();

	}
	CString res;
	res = m_History + _T("=") + m_res;
	m_listBox.InsertItem(m_listBox.GetItemCount() + 1, res);

	m_number = 0;

	UpdateData(FALSE);

	loadList();
}
/// //////////////////////////////////////////////////////////////////////////////////////

void CcalculatorDlg::OnButtonAdd()
{
	UpdateData(TRUE);
	m_number = 0;
	addCharacter('+');
	UpdateData(FALSE);
}


void CcalculatorDlg::OnButtonMinus()
{
	UpdateData(TRUE);
	m_number = 0;
	addCharacter('-');
	UpdateData(FALSE);
}


void CcalculatorDlg::OnButtonMultiply()
{
	UpdateData(TRUE);
	m_number = 0;
	addCharacter('*');
	UpdateData(FALSE);
}


void CcalculatorDlg::OnButtonDivide()
{
	UpdateData(TRUE);
	m_number = 0;
	addCharacter('/');
	UpdateData(FALSE);
}


void CcalculatorDlg::OnButtonBack() {
	// remove the rightmost char
	if (!historyString.empty() && (isdigit(historyString.back()) || historyString.back() == '.')) {
		historyString = historyString.substr(0, historyString.size() - 1);
		tempOperand = tempOperand.substr(0, tempOperand.size() - 1);
		m_res = tempOperand.c_str();
		UpdateData(FALSE);
	}
}


// "C" button
void CcalculatorDlg::OnButtonClearall() {
	UpdateData(TRUE);

	m_res = _T("");
	m_History = _T("");

	tempOperand = "";
	historyString = "";

	m_fNumber1 = 0.0f;
	m_fNumber2 = 0.0f;

	m_symbol = 1;
	m_time = 0;
	m_number = 0;

	m_iSign = 0;
	UpdateData(FALSE);
}


void CcalculatorDlg::OnButtonComma()
{
	UpdateData(TRUE);
	
	 if (m_res[0] == '+' && isdigit(m_res[1]) == 0 ||
		 m_res[0] == '-' && isdigit(m_res[1]) == 0 ||
		 m_res[0] == '*' && isdigit(m_res[1]) == 0 ||
		 m_res[0] == '/' && isdigit(m_res[1]) == 0)
		 m_res = "Invalid input for function.";

	// if there is no decimal point, add a decimal point. 
	// if there is a decimal point, ignore the decimal point this time 
	// ensure that there is at most one decimal point.
	 if (-1 == m_res.Find('.') && isdigit(m_res[0]))
		 addCharacter('.');

	UpdateData(FALSE);
}


void CcalculatorDlg::OnButton0()
{
	addCharacter('0');
}


void CcalculatorDlg::OnButton1()
{
	addCharacter('1');
}


void CcalculatorDlg::OnButton2()
{
	addCharacter('2');
}


void CcalculatorDlg::OnButton3()
{
	addCharacter('3');
}


void CcalculatorDlg::OnButton4()
{
	addCharacter('4');
}


void CcalculatorDlg::OnButton5()
{
	addCharacter('5');
}


void CcalculatorDlg::OnButton6()
{
	addCharacter('6');
}


void CcalculatorDlg::OnButton7()
{
	addCharacter('7');
}


void CcalculatorDlg::OnButton8()
{
	addCharacter('8');
}


void CcalculatorDlg::OnButton9()
{
	addCharacter('9');
}


// clear historypanel
void CcalculatorDlg::OnBnClickedButtonClearhistory()
{
	m_listBox.DeleteAllItems();
}


// when clicking this, the item is set to editable (default position is the last item on the CListCtrl)
// to edit other item, use "up" and "down" button
void CcalculatorDlg::OnBnClickedButtonEdit()
{
	check = true;
}


// on click, user's input is calculated and result is show on the history panel
// notice that this can only be used to edit simple operators like '+', '-', '*', '/', other operators are not supported
void CcalculatorDlg::OnBnClickedButtonRecalc()
{
	m_listBox.SetFocus();
	CString str = m_listBox.GetItemText(iItem, 0);
	
	CT2CA pszConvertedAnsiString(str);

	std::string s(pszConvertedAnsiString);
	
	if (validate(s) && singleInput(s)) {
		extract(s);
		check = false;
		loadList();
	}
	else {
		m_listBox.DeleteItem(iItem);
		m_listBox.InsertItem(m_listBox.GetItemCount() + 1, m_temp);

		UpdateData(TRUE);

		m_History.Empty();
		m_res.Empty();
		m_res = _T("Invalid!");
		UpdateData(FALSE);
		return;
	}
}


// validate user input in edit mode
bool CcalculatorDlg::validate(std::string& str) {
	for (int i = 0; i < str.length(); i++) {
		if (!isdigit(str[i]) 
			&& str[i] != '.'
			&& str[i] != '+'
			&& str[i] != '-'
			&& str[i] != '*'
			&& str[i] != '/')
			return false;
	}
	return true;
}


// check if user insert 1 number only in edit mode
bool CcalculatorDlg::singleInput(std::string& str) {
	size_t plus = str.find('+');
	size_t minus = str.find('-');
	size_t mul = str.find('*');
	size_t div = str.find('/');

	if (plus == std::string::npos
		&& minus == std::string::npos
		&& mul == std::string::npos
		&& div == std::string::npos)
		return false;
	return true;
}


// extract user's input to doOperation
void CcalculatorDlg::extract(std::string s) {
	int i = 0;
	std::string temp1, temp2;
	char tempOp;
	s = s.substr(0, s.find('=') - 1);

	if (isdigit(s[0])) {
			while (isdigit(s[i]) || s[i] == '.') {
				temp1 += s[i];
				i++;
			}

			tempOp = s[i];
			i++;

			if (s[i] == '-') {
				temp2 += s[i];
				i++;
			}

			while (isdigit(s[i]) || s[i] == '.') {
				temp2 += s[i];
				i++;
			}
		}

	else {
			temp1 += s[i];
			i++;

			while (isdigit(s[i]) || s[i] == '.') {
				temp1 += s[i];
				i++;
			}

			tempOp = s[i];
			i++;

			if (s[i] == '-') {
				temp2 += s[i];
				i++;
			}

			while (isdigit(s[i]) || s[i] == '.') {
				temp2 += s[i];
				i++;
			}
		}

	m_listBox.DeleteItem(iItem);

	double m1, m2;

	m1 = stod(temp1);
	m2 = stod(temp2);
	doOperation(m1, m2, tempOp);
	str_to_double(m1, m_res);


	std::string ts(1, tempOp);
	CString t;
	ts = temp1 + ts + temp2 + "=";
	t = ts.c_str();
	CString result;
	result += t + m_res;
	m_listBox.InsertItem(m_listBox.GetItemCount() + 1, result);
}


// move up in history panel
void CcalculatorDlg::OnBnClickedButtonUp()
{
	m_listBox.SetFocus();

	int sel = m_listBox.GetNextItem(-1, LVNI_SELECTED);

	int next = sel - 1;
	if (next < 0)
		return;

	// Move selection
	m_listBox.SetItemState(sel, ~LVNI_SELECTED, LVIS_SELECTED);
	m_listBox.SetItemState(next, LVNI_SELECTED, LVIS_SELECTED);
	m_listBox.SetSelectionMark(next);
	iItem = next;
}


// move down in history panel
void CcalculatorDlg::OnBnClickedButtonDown()
{
	m_listBox.SetFocus();

	int sel = m_listBox.GetNextItem(-1, LVNI_SELECTED);

	int prev = sel + 1;
	if (prev >= m_listBox.GetItemCount())
		return;

	// Move selection
	m_listBox.SetItemState(sel, ~LVNI_SELECTED, LVIS_SELECTED);
	m_listBox.SetItemState(prev, LVNI_SELECTED, LVIS_SELECTED);
	m_listBox.SetSelectionMark(prev);
	iItem = prev;
}
	

// this function is to edit history
void CcalculatorDlg::OnLvnEndlabeleditListCtrl(NMHDR* pNMHDR, LRESULT* pResult)
{
	m_temp = m_listBox.GetItemText(iItem, 0);
	if (check == true) {
		CString str = _T("");

		CEdit* pEdit = m_listBox.GetEditControl();
		pEdit->GetWindowTextW(str);

		m_listBox.SetItemText(iItem, 0, str);
		*pResult = 0;

	}
}


// enable edit by single click
void CcalculatorDlg::OnNMClickListCtrl(NMHDR* pNMHDR, LRESULT* pResult)
{
	if (check == true) {
		HD_NOTIFY* phdn = (HD_NOTIFY*)pNMHDR;
		m_listBox.EditLabel(phdn->iItem);
		*pResult = 0;
	}
}
