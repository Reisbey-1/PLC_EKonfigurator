// EKonfiguratorDlg.h : Header-Datei
//

#if !defined(AFX_EKONFIGURATORDLG_H__DC11D805_B9E5_4EED_9DA0_E87A9E1BEB9C__INCLUDED_)
#define AFX_EKONFIGURATORDLG_H__DC11D805_B9E5_4EED_9DA0_E87A9E1BEB9C__INCLUDED_



/////////////////////////////////////////////////////////////////////////////
// CEKonfiguratorDlg Dialogfeld

class CEKonfiguratorDlg : public CDialog
{

	int		m_nSpiFrequency;
	int		m_nProcessor;
	int		m_nMode;
	CString m_csFileName;

// Konstruktion
	enum
	{
		ALONE = 0,
		MASTER,
		SLAVE
	};

	enum
	{
		PB0 = 0,
		PB1,
		PB2,
		PB3,
		PB4,
		PB5,
		PB6,
		PB7,
		RESET,
		VCC,
		GND,
		XTAL2,
		XTAL1,
		PD0,
		PD1,
		
		PD2 = 15,
		PD3,
		PD4,
		PD5,
		PD6,
		PD7,
		
		PC0,
		PC1,
		PC2,
		PC3,
		PC4,
		PC5,
		PC6,
		PC7,
		AVCC,
		GND2,
		AREF,
		
		PA7 = 32,
		PA6,
		PA5,
		PA4,
		PA3,
		PA2,
		PA1,
		PA0
	};

public:
	CEKonfiguratorDlg(CWnd* pParent = NULL);	// Standard-Konstruktor

// Dialogfelddaten
	//{{AFX_DATA(CEKonfiguratorDlg)
	enum { IDD = IDD_EKONFIGURATOR_DIALOG };
	//}}AFX_DATA

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CEKonfiguratorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Message-Map-Funktionen
	//{{AFX_MSG(CEKonfiguratorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeComboModes();
	afx_msg void OnSelchangeComboPins();
	afx_msg void OnButtonSave();
	afx_msg void OnUpdate();
	afx_msg void OnRadioDigitalIn();
	afx_msg void OnRadioDigitalOut();
	afx_msg void OnRadioAnalogIn();
	afx_msg void OnRadioAnalogOut();
	afx_msg void OnButtonOpen();
	afx_msg void OnSelchangeComboRegister();
	afx_msg void OnSelchangeComboBit();
	afx_msg void OnRadio20();
	afx_msg void OnRadio21();
	afx_msg void OnRadio22();
	afx_msg void OnRadio23();
	afx_msg void OnRadio24();
	afx_msg void OnRadio25();
	afx_msg void OnRadio26();
	afx_msg void OnRadio27();
	afx_msg void OnRadio31();
	afx_msg void OnRadio32();
	afx_msg void OnRadio33();
	afx_msg void OnRadio34();
	afx_msg void OnRadio35();
	afx_msg void OnRadio36();
	afx_msg void OnRadio37();
	afx_msg void OnRadio38();
	afx_msg void OnRadio39();
	afx_msg void OnRadio19();
	afx_msg void OnRadio18();
	afx_msg void OnRadio17();
	afx_msg void OnRadio16();
	afx_msg void OnRadio15();
	afx_msg void OnRadio7();
	afx_msg void OnRadio6();
	afx_msg void OnRadio5();
	afx_msg void OnRadio4();
	afx_msg void OnRadio3();
	afx_msg void OnRadio2();
	afx_msg void OnRadio1();
	afx_msg void OnRadio0();

	afx_msg void OnSelchangeComboProcessor();
	afx_msg void OnSelchangeComboSpiFrequency();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	CButton * m_pPinSelection[40];
	CEdit   * m_pPinEditSelection[40];

	MEmbeddedConfig m_EmbeddedConfig;

private:
	void _FillComboPins(int nMode);
	void _FillPinRadios();
	void _UpdatePinRadios(int nSelection);
	int  _GetPinSelection();
	void _FillPinEdits();
	void _SetPinComboBox(CString csTitle);

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_EKONFIGURATORDLG_H__DC11D805_B9E5_4EED_9DA0_E87A9E1BEB9C__INCLUDED_)
