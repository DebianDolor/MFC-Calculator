#pragma once
#include <iostream>

class CcalculatorDlg : public CDialogEx
{
// Construction
public:
	CcalculatorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	CEdit m_edit;
	CString m_res;
	
	// 2 values ​​entered
	double m_fNumber1;
	double m_fNumber2;

	// stored data (used for MS, MC, MR, M+, M-)
	double m_m;

	// symbol: 1 = '+', 2= '-', 3 = '*', 4 = '/'
	int m_iSign;

	// number of calculations
	int m_time;

	// input data (number of character in integer/float/double)
	int m_number;

	// 1 = + or -1 = - (negate)
	int m_symbol;

	// convert
	void str_to_double(double f ,CString & m_temp);


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	// load list control
	void loadList();
public:

	afx_msg void OnButtonBack();
	afx_msg void OnButtonClear();
	afx_msg void OnButtonClearall();

	afx_msg void OnButton0();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	afx_msg void OnButton9();

	afx_msg void OnButtonComma();

	afx_msg void OnButtonAdd();
	afx_msg void OnButtonMinus();
	afx_msg void OnButtonMultiply();
	afx_msg void OnButtonDivide();

	afx_msg void OnButtonSqrt();
	afx_msg void OnButtonPrecent();
	afx_msg void OnButtonInverse();
	afx_msg void OnButtonNegate();
	afx_msg void OnButtonLog();
	afx_msg void OnButtonLn();

	afx_msg void OnButtonMS();
	afx_msg void OnButtonMR();
	afx_msg void OnButtonMC();
	afx_msg void OnButtonMadd();
	afx_msg void OnButtonMminus();

	afx_msg void OnButtonSin();
	afx_msg void OnButtonCos();
	afx_msg void OnButtonTan();

	afx_msg void OnButtonPI();

	afx_msg void OnButtonEqual();

private:
	CString m_History;
	CString m_temp;

	std::string historyString; // string include numbers and operators
	std::string tempOperand; // string include numbers only
	std::string t;

	char tempOperator = ' ';

	void addCharacter(char c);
	void doOperation(double& a, double& b, char op);
	char getLastOp(const std::string& operations);
	void extract(std::string s);
public:
	CListCtrl m_listBox;

	bool check = false; // editable flag

	int iItem; // index of the current selected item in history panel

	// filter user's input in edit mode
	bool validate(std::string& s);
	bool singleInput(std::string& s);

	afx_msg void OnBnClickedButtonClearhistory();
	afx_msg void OnBnClickedButtonEdit();
	afx_msg void OnBnClickedButtonRecalc();
	afx_msg void OnBnClickedButtonUp();
	afx_msg void OnBnClickedButtonDown();

	afx_msg void OnLvnEndlabeleditListCtrl(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMClickListCtrl(NMHDR* pNMHDR, LRESULT* pResult);
};

