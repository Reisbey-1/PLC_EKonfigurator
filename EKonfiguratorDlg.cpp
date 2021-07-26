// EKonfiguratorDlg.cpp : Implementierungsdatei
//

#include "stdafx.h"
#include "EKonfigurator.h"
#include "EKonfiguratorDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg-Dialogfeld für Anwendungsbefehl "Info"

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialogfelddaten
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// Keine Nachrichten-Handler
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEKonfiguratorDlg Dialogfeld

CEKonfiguratorDlg::CEKonfiguratorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEKonfiguratorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEKonfiguratorDlg)
	//}}AFX_DATA_INIT
	// Beachten Sie, dass LoadIcon unter Win32 keinen nachfolgenden DestroyIcon-Aufruf benötigt
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_csFileName = "";
}

void CEKonfiguratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEKonfiguratorDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEKonfiguratorDlg, CDialog)
	//{{AFX_MSG_MAP(CEKonfiguratorDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO_MODES, OnSelchangeComboModes)
	ON_CBN_SELCHANGE(IDC_COMBO_PINS, OnSelchangeComboPins)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_BN_CLICKED(IDB_UPDATE, OnUpdate)
	ON_BN_CLICKED(IDC_RADIO_DIGITAL_IN, OnRadioDigitalIn)
	ON_BN_CLICKED(IDC_RADIO_DIGITAL_OUT, OnRadioDigitalOut)
	ON_BN_CLICKED(IDC_RADIO_ANALOG_IN, OnRadioAnalogIn)
	ON_BN_CLICKED(IDC_RADIO_ANALOG_OUT, OnRadioAnalogOut)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, OnButtonOpen)
	ON_CBN_SELCHANGE(IDC_COMBO_REGISTER, OnSelchangeComboRegister)
	ON_CBN_SELCHANGE(IDC_COMBO_BIT, OnSelchangeComboBit)
	ON_BN_CLICKED(IDC_RADIO20, OnRadio20)
	ON_BN_CLICKED(IDC_RADIO21, OnRadio21)
	ON_BN_CLICKED(IDC_RADIO22, OnRadio22)
	ON_BN_CLICKED(IDC_RADIO23, OnRadio23)
	ON_BN_CLICKED(IDC_RADIO24, OnRadio24)
	ON_BN_CLICKED(IDC_RADIO25, OnRadio25)
	ON_BN_CLICKED(IDC_RADIO26, OnRadio26)
	ON_BN_CLICKED(IDC_RADIO27, OnRadio27)
	ON_BN_CLICKED(IDC_RADIO31, OnRadio31)
	ON_BN_CLICKED(IDC_RADIO32, OnRadio32)
	ON_BN_CLICKED(IDC_RADIO33, OnRadio33)
	ON_BN_CLICKED(IDC_RADIO34, OnRadio34)
	ON_BN_CLICKED(IDC_RADIO35, OnRadio35)
	ON_BN_CLICKED(IDC_RADIO36, OnRadio36)
	ON_BN_CLICKED(IDC_RADIO37, OnRadio37)
	ON_BN_CLICKED(IDC_RADIO38, OnRadio38)
	ON_BN_CLICKED(IDC_RADIO39, OnRadio39)
	ON_BN_CLICKED(IDC_RADIO19, OnRadio19)
	ON_BN_CLICKED(IDC_RADIO18, OnRadio18)
	ON_BN_CLICKED(IDC_RADIO17, OnRadio17)
	ON_BN_CLICKED(IDC_RADIO16, OnRadio16)
	ON_BN_CLICKED(IDC_RADIO15, OnRadio15)
	ON_BN_CLICKED(IDC_RADIO7, OnRadio7)
	ON_BN_CLICKED(IDC_RADIO6, OnRadio6)
	ON_BN_CLICKED(IDC_RADIO5, OnRadio5)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO0, OnRadio0)
	ON_CBN_SELCHANGE(IDC_COMBO_PROCESSOR, OnSelchangeComboProcessor)
	ON_CBN_SELCHANGE(IDC_COMBO_SPI_FREQUENCY, OnSelchangeComboSpiFrequency)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEKonfiguratorDlg Nachrichten-Handler

BOOL CEKonfiguratorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Hinzufügen des Menübefehls "Info..." zum Systemmenü.

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{	
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Symbol für dieses Dialogfeld festlegen. Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden
	
	// pin radios
	_FillPinRadios();
	_FillPinEdits();
	
	CComboBox * pComboModes = (CComboBox *)GetDlgItem(IDC_COMBO_MODES);

	pComboModes->ResetContent();
	pComboModes->AddString(_T("ALONE"));
	pComboModes->AddString(_T("MASTER"));
	pComboModes->AddString(_T("SLAVE"));
///	pComboModes->SetCurSel(ALONE);
///	OnSelchangeComboModes();


	CComboBox * pBit= (CComboBox *)GetDlgItem(IDC_COMBO_BIT)	;
	pBit->ResetContent();
//	pBit->AddString(" ");
	pBit->AddString(_T("0"));
	pBit->AddString(_T("1"));
	pBit->AddString(_T("2"));
	pBit->AddString(_T("3"));
	pBit->AddString(_T("4"));
	pBit->AddString(_T("5"));
	pBit->AddString(_T("6"));
	pBit->AddString(_T("7"));
//	pBit->SetCurSel(6);

	
	CComboBox * pRegister = (CComboBox *)GetDlgItem(IDC_COMBO_REGISTER);
	pRegister->ResetContent();
	pRegister->AddString(_T("IM00"));
	pRegister->AddString(_T("IM01"));
	pRegister->AddString(_T("IM02"));
	pRegister->AddString(_T("IM03"));

//	pRegister->SetCurSel(0);

//	OnSelchangeComboModes();

	


	CComboBox * pComboProcessor = (CComboBox *)GetDlgItem(IDC_COMBO_PROCESSOR);
	pComboProcessor->ResetContent();
	pComboProcessor->AddString(gsProcessor[0]);
	pComboProcessor->AddString(gsProcessor[1]);
	pComboProcessor->AddString(gsProcessor[2]);
	pComboProcessor->AddString(gsProcessor[3]);
	pComboProcessor->AddString(gsProcessor[4]);
	pComboProcessor->AddString(gsProcessor[5]);
	pComboProcessor->AddString(gsProcessor[6]);

	CComboBox * pComboSpiFrequency = (CComboBox *)GetDlgItem(IDC_COMBO_SPI_FREQUENCY);
	pComboSpiFrequency->ResetContent();
	pComboSpiFrequency->AddString(gsSpiFrequency[0]);
	pComboSpiFrequency->AddString(gsSpiFrequency[1]);
	pComboSpiFrequency->AddString(gsSpiFrequency[2]);
	pComboSpiFrequency->AddString(gsSpiFrequency[3]);
	pComboSpiFrequency->AddString(gsSpiFrequency[4]);

	// ZU ERLEDIGEN: Hier zusätzliche Initialisierung einfügen
	
	return TRUE;  // Geben Sie TRUE zurück, außer ein Steuerelement soll den Fokus erhalten
}

void CEKonfiguratorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// Wollen Sie Ihrem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie 
//  den nachstehenden Code, um das Symbol zu zeichnen. Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch für Sie erledigt.

void CEKonfiguratorDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Gerätekontext für Zeichnen

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Symbol in Client-Rechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// Die Systemaufrufe fragen den Cursorform ab, die angezeigt werden soll, während der Benutzer
//  das zum Symbol verkleinerte Fenster mit der Maus zieht.
HCURSOR CEKonfiguratorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CEKonfiguratorDlg::_UpdatePinRadios(int nSelection)
{
	CButton * pAnalogIn  = (CButton *) GetDlgItem(IDC_RADIO_ANALOG_IN);
	CButton * pAnalogOut = (CButton *) GetDlgItem(IDC_RADIO_ANALOG_OUT);
	for(int i = 0; i< 40; i++)
	{
		CButton * pBt = m_pPinSelection[i];
		pBt->SetCheck(0);
	}
	
	
	m_pPinSelection[nSelection]->SetCheck(1);

	// if analog outputs activeta respective radio buttons
	if (nSelection == PD4 || nSelection == PD5 )
	{
		pAnalogOut->EnableWindow(TRUE);
	}
	else 
	{
		///pAnalogOut->EnableWindow(FALSE);
	}
	// if analog inputs activeta respective radio buttons
	if (nSelection == PA0 || nSelection == PA1 )
	{
		pAnalogIn->EnableWindow(TRUE);
	}
	else 
	{
		///pAnalogIn->EnableWindow(FALSE);
	}


}
void CEKonfiguratorDlg::_FillPinEdits()
{
	m_pPinEditSelection[0] = (CEdit *) GetDlgItem(IDC_EDIT2);
	m_pPinEditSelection[1] = (CEdit *) GetDlgItem(IDC_EDIT3);
	m_pPinEditSelection[2] = (CEdit *) GetDlgItem(IDC_EDIT4);
	m_pPinEditSelection[3] = (CEdit *) GetDlgItem(IDC_EDIT5);
	m_pPinEditSelection[4] = (CEdit *) GetDlgItem(IDC_EDIT6);
	m_pPinEditSelection[5] = (CEdit *) GetDlgItem(IDC_EDIT7);
	m_pPinEditSelection[6] = (CEdit *) GetDlgItem(IDC_EDIT8);
	m_pPinEditSelection[7] = (CEdit *) GetDlgItem(IDC_EDIT9);
	m_pPinEditSelection[8] = (CEdit *) GetDlgItem(IDC_EDIT10);
	m_pPinEditSelection[9] = (CEdit *) GetDlgItem(IDC_EDIT11);

	m_pPinEditSelection[10] = (CEdit *) GetDlgItem(IDC_EDIT12);
	m_pPinEditSelection[11] = (CEdit *) GetDlgItem(IDC_EDIT13);
	m_pPinEditSelection[12] = (CEdit *) GetDlgItem(IDC_EDIT14);
	m_pPinEditSelection[13] = (CEdit *) GetDlgItem(IDC_EDIT15);
	m_pPinEditSelection[14] = (CEdit *) GetDlgItem(IDC_EDIT16);
	m_pPinEditSelection[15] = (CEdit *) GetDlgItem(IDC_EDIT17);
	m_pPinEditSelection[16] = (CEdit *) GetDlgItem(IDC_EDIT18);
	m_pPinEditSelection[17] = (CEdit *) GetDlgItem(IDC_EDIT19);
	m_pPinEditSelection[18] = (CEdit *) GetDlgItem(IDC_EDIT20);
	m_pPinEditSelection[19] = (CEdit *) GetDlgItem(IDC_EDIT21);


	m_pPinEditSelection[20] = (CEdit *) GetDlgItem(IDC_EDIT41);
	m_pPinEditSelection[21] = (CEdit *) GetDlgItem(IDC_EDIT40);
	m_pPinEditSelection[22] = (CEdit *) GetDlgItem(IDC_EDIT39);
	m_pPinEditSelection[23] = (CEdit *) GetDlgItem(IDC_EDIT38);
	m_pPinEditSelection[24] = (CEdit *) GetDlgItem(IDC_EDIT37);
	m_pPinEditSelection[25] = (CEdit *) GetDlgItem(IDC_EDIT36);
	m_pPinEditSelection[26] = (CEdit *) GetDlgItem(IDC_EDIT35);
	m_pPinEditSelection[27] = (CEdit *) GetDlgItem(IDC_EDIT34);
	m_pPinEditSelection[28] = (CEdit *) GetDlgItem(IDC_EDIT33);
	m_pPinEditSelection[29] = (CEdit *) GetDlgItem(IDC_EDIT32);

	m_pPinEditSelection[30] = (CEdit *) GetDlgItem(IDC_EDIT31);
	m_pPinEditSelection[31] = (CEdit *) GetDlgItem(IDC_EDIT30);
	m_pPinEditSelection[32] = (CEdit *) GetDlgItem(IDC_EDIT29);
	m_pPinEditSelection[33] = (CEdit *) GetDlgItem(IDC_EDIT28);
	m_pPinEditSelection[34] = (CEdit *) GetDlgItem(IDC_EDIT27);
	m_pPinEditSelection[35] = (CEdit *) GetDlgItem(IDC_EDIT26);
	m_pPinEditSelection[36] = (CEdit *) GetDlgItem(IDC_EDIT25);
	m_pPinEditSelection[37] = (CEdit *) GetDlgItem(IDC_EDIT24);
	m_pPinEditSelection[38] = (CEdit *) GetDlgItem(IDC_EDIT23);
	m_pPinEditSelection[39] = (CEdit *) GetDlgItem(IDC_EDIT22);

}
void CEKonfiguratorDlg::_FillPinRadios()
{
	// set selection array
	m_pPinSelection[0]  = (CButton *) GetDlgItem(IDC_RADIO0);
	m_pPinSelection[1]  = (CButton *) GetDlgItem(IDC_RADIO1);
	m_pPinSelection[2]  = (CButton *) GetDlgItem(IDC_RADIO2);
	m_pPinSelection[3]  = (CButton *) GetDlgItem(IDC_RADIO3);
	m_pPinSelection[4]  = (CButton *) GetDlgItem(IDC_RADIO4);
	m_pPinSelection[5]  = (CButton *) GetDlgItem(IDC_RADIO5);
	m_pPinSelection[6]  = (CButton *) GetDlgItem(IDC_RADIO6);
	m_pPinSelection[7]  = (CButton *) GetDlgItem(IDC_RADIO7);
	m_pPinSelection[8]  = (CButton *) GetDlgItem(IDC_RADIO8);
	m_pPinSelection[9]  = (CButton *) GetDlgItem(IDC_RADIO9);
	m_pPinSelection[10] = (CButton *) GetDlgItem(IDC_RADIO10);
	m_pPinSelection[11] = (CButton *) GetDlgItem(IDC_RADIO11);
	m_pPinSelection[12] = (CButton *) GetDlgItem(IDC_RADIO12);
	m_pPinSelection[13] = (CButton *) GetDlgItem(IDC_RADIO13);
	m_pPinSelection[14] = (CButton *) GetDlgItem(IDC_RADIO14);
	m_pPinSelection[15] = (CButton *) GetDlgItem(IDC_RADIO15);
	m_pPinSelection[16] = (CButton *) GetDlgItem(IDC_RADIO16);
	m_pPinSelection[17] = (CButton *) GetDlgItem(IDC_RADIO17);
	m_pPinSelection[18] = (CButton *) GetDlgItem(IDC_RADIO18);
	m_pPinSelection[19] = (CButton *) GetDlgItem(IDC_RADIO19);

	m_pPinSelection[20] = (CButton *) GetDlgItem(IDC_RADIO39);
	m_pPinSelection[21] = (CButton *) GetDlgItem(IDC_RADIO38);
	m_pPinSelection[22] = (CButton *) GetDlgItem(IDC_RADIO37);
	m_pPinSelection[23] = (CButton *) GetDlgItem(IDC_RADIO36);
	m_pPinSelection[24] = (CButton *) GetDlgItem(IDC_RADIO35);
	m_pPinSelection[25] = (CButton *) GetDlgItem(IDC_RADIO34);
	m_pPinSelection[26] = (CButton *) GetDlgItem(IDC_RADIO33);
	m_pPinSelection[27] = (CButton *) GetDlgItem(IDC_RADIO32);
	m_pPinSelection[28] = (CButton *) GetDlgItem(IDC_RADIO31);
	m_pPinSelection[29] = (CButton *) GetDlgItem(IDC_RADIO30);
	m_pPinSelection[30] = (CButton *) GetDlgItem(IDC_RADIO29);
	m_pPinSelection[31] = (CButton *) GetDlgItem(IDC_RADIO28);
	m_pPinSelection[32] = (CButton *) GetDlgItem(IDC_RADIO27);
	m_pPinSelection[33] = (CButton *) GetDlgItem(IDC_RADIO26);
	m_pPinSelection[34] = (CButton *) GetDlgItem(IDC_RADIO25);
	m_pPinSelection[35] = (CButton *) GetDlgItem(IDC_RADIO24);
	m_pPinSelection[36] = (CButton *) GetDlgItem(IDC_RADIO23);
	m_pPinSelection[37] = (CButton *) GetDlgItem(IDC_RADIO22);
	m_pPinSelection[38] = (CButton *) GetDlgItem(IDC_RADIO21);
	m_pPinSelection[39] = (CButton *) GetDlgItem(IDC_RADIO20);

	for (int i = 0; i<40; i++)
	{
		//m_pPinSelection[39]->ena
	}





}
void CEKonfiguratorDlg::_FillComboPins(int nMode)
{
	CComboBox * pComboPins = (CComboBox *)GetDlgItem(IDC_COMBO_PINS);

	// depend upon mode always
	
	// port B
	pComboPins->ResetContent();
	pComboPins->AddString(_T("PB0"));
	pComboPins->AddString(_T("PB1"));
	pComboPins->AddString(_T("PB2"));
	pComboPins->AddString(_T("PB3"));
	pComboPins->AddString(_T("PB4"));
	pComboPins->AddString(_T("PB5"));
	pComboPins->AddString(_T("PB6"));
	pComboPins->AddString(_T("PB7"));

	CComboBox * pComboFrequency = (CComboBox *)GetDlgItem(IDC_COMBO_SPI_FREQUENCY);

	if (nMode == ALONE)
	{
		m_pPinEditSelection[4]->EnableWindow(TRUE);
		m_pPinSelection[4]->EnableWindow(TRUE);
		m_pPinEditSelection[5]->EnableWindow(TRUE);
		m_pPinSelection[5]->EnableWindow(TRUE);
		m_pPinEditSelection[6]->EnableWindow(TRUE);
		m_pPinSelection[6]->EnableWindow(TRUE);
		m_pPinEditSelection[7]->EnableWindow(TRUE);
		m_pPinSelection[7]->EnableWindow(TRUE);
		pComboFrequency->EnableWindow(FALSE);

	}
	else
	{
		m_pPinEditSelection[4]->EnableWindow(FALSE);
		m_pPinSelection[4]->EnableWindow(FALSE);
		m_pPinEditSelection[5]->EnableWindow(FALSE);
		m_pPinSelection[5]->EnableWindow(FALSE);
		m_pPinEditSelection[6]->EnableWindow(FALSE);
		m_pPinSelection[6]->EnableWindow(FALSE);
		m_pPinEditSelection[7]->EnableWindow(FALSE);
		m_pPinSelection[7]->EnableWindow(FALSE);
		pComboFrequency->EnableWindow(TRUE);
	}
	
	// port D
	pComboPins->AddString(_T("PD2"));
	pComboPins->AddString(_T("PD3"));
	pComboPins->AddString(_T("PD4"));
	pComboPins->AddString(_T("PD5"));
	pComboPins->AddString(_T("PD6"));
	pComboPins->AddString(_T("PD7"));

	// port C
	pComboPins->AddString(_T("PC0"));
	pComboPins->AddString(_T("PC1"));
	pComboPins->AddString(_T("PC2"));
	pComboPins->AddString(_T("PC3"));
	pComboPins->AddString(_T("PC4"));
	pComboPins->AddString(_T("PC5"));
	pComboPins->AddString(_T("PC6"));
	pComboPins->AddString(_T("PC7"));

	// port A
	pComboPins->AddString(_T("PA7"));
	pComboPins->AddString(_T("PA6"));
	pComboPins->AddString(_T("PA5"));
	pComboPins->AddString(_T("PA4"));
	pComboPins->AddString(_T("PA3"));
	pComboPins->AddString(_T("PA2"));
	pComboPins->AddString(_T("PA1"));
	pComboPins->AddString(_T("PA0"));

	pComboPins->SetCurSel(0);

}
int CEKonfiguratorDlg::_GetPinSelection()
{
	CComboBox * pComboModes = (CComboBox *)GetDlgItem(IDC_COMBO_MODES);
	int nMode = pComboModes->GetCurSel();
	
	CComboBox * pComboPins = (CComboBox *)GetDlgItem(IDC_COMBO_PINS);
	int nSel  = pComboPins->GetCurSel();

	CString rText;
	pComboPins->GetWindowText(rText);

	if (rText.CompareNoCase(_T("PA0"))==0)
		return 39;
	else if (rText.CompareNoCase(_T("PA1"))==0)
		return 38;
	else if (rText.CompareNoCase(_T("PA2"))==0)
		return 37;
	else if (rText.CompareNoCase(_T("PA3"))==0)
		return 36;
	else if (rText.CompareNoCase(_T("PA4"))==0)
		return 35;
	else if (rText.CompareNoCase(_T("PA5"))==0)
		return 34;
	else if (rText.CompareNoCase(_T("PA6"))==0)
		return 33;
	else if (rText.CompareNoCase(_T("PA7"))==0)
		return 32;
	

	else if (rText.CompareNoCase(_T("PC7"))==0)
		return 28;
	else if (rText.CompareNoCase(_T("PC6"))==0)
		return 27;
	else if (rText.CompareNoCase(_T("PC5"))==0)
		return 26;
	else if (rText.CompareNoCase(_T("PC4"))==0)
		return 25;
	else if (rText.CompareNoCase(_T("PC3"))==0)
		return 24;
	else if (rText.CompareNoCase(_T("PC2"))==0)
		return 23;
	else if (rText.CompareNoCase(_T("PC1"))==0)
		return 22;
	else if (rText.CompareNoCase(_T("PC0"))==0)
		return 21;

	else if (rText.CompareNoCase(_T("PD7"))==0)
		return 20;
	else if (rText.CompareNoCase(_T("PD6"))==0)
		return 19;
	else if (rText.CompareNoCase(_T("PD5"))==0)
		return 18;
	else if (rText.CompareNoCase(_T("PD4"))==0)
		return 17;
	else if (rText.CompareNoCase(_T("PD3"))==0)
		return 16;
	else if (rText.CompareNoCase(_T("PD2"))==0)
		return 15;
	else if (rText.CompareNoCase(_T("PD1"))==0)
		return 14;
	else if (rText.CompareNoCase(_T("PD0"))==0)
		return 11;


	else if (rText.CompareNoCase(_T("PD7"))==0)
		return 20;
	else if (rText.CompareNoCase(_T("PD6"))==0)
		return 19;
	else if (rText.CompareNoCase(_T("PD5"))==0)
		return 18;
	else if (rText.CompareNoCase(_T("PD4"))==0)
		return 17;
	else if (rText.CompareNoCase(_T("PD3"))==0)
		return 16;
	else if (rText.CompareNoCase(_T("PD2"))==0)
		return 15;

	else if (rText.CompareNoCase(_T("PB7"))==0)
		return 7;
	else if (rText.CompareNoCase(_T("PB6"))==0)
		return 6;
	else if (rText.CompareNoCase(_T("PB5"))==0)
		return 5;
	else if (rText.CompareNoCase(_T("PB4"))==0)
		return 4;
	else if (rText.CompareNoCase(_T("PB3"))==0)
		return 3;
	else if (rText.CompareNoCase(_T("PB2"))==0)
		return 2;
	else if (rText.CompareNoCase(_T("PB1"))==0)
		return 1;
	else if (rText.CompareNoCase(_T("PB0"))==0)
		return 0;

return -1;

}
void CEKonfiguratorDlg::OnSelchangeComboModes() 
{
	CComboBox * pComboModes			= (CComboBox *)GetDlgItem(IDC_COMBO_MODES);
	CComboBox * pComboSpiFrequency	= (CComboBox *)GetDlgItem(IDC_COMBO_SPI_FREQUENCY);
	
	int nMode = pComboModes->GetCurSel();
	_FillComboPins(nMode);
	OnSelchangeComboPins();

	MPin pin;
	BOOL b;
	if ( (nMode == MASTER) )
	{
		// enable spi-frequency combo
		pComboSpiFrequency->EnableWindow(TRUE);

		// /SS
		b = m_EmbeddedConfig.GetPinByName(pin, CString("PB4"));
		pin.SetSubType(MPin::SPI_SS);
		if (b)
			m_EmbeddedConfig.SetPinByName(pin,pin.GetName());
		else
			m_EmbeddedConfig.AddTail(pin);
		// MOSI
		b = m_EmbeddedConfig.GetPinByName(pin, CString("PB5"));
		pin.SetSubType(MPin::SPI_MOSI);
		if (b)
			m_EmbeddedConfig.SetPinByName(pin,pin.GetName());
	}

	else
	{
		// disable spi-frequency combo
		pComboSpiFrequency->EnableWindow(FALSE);
	}

	// update
	OnUpdate();
}
void CEKonfiguratorDlg::OnSelchangeComboPins() 
{
	CButton* pDigIn  = (CButton*) GetDlgItem(IDC_RADIO_DIGITAL_IN);
	CButton* pDigOut = (CButton*) GetDlgItem(IDC_RADIO_DIGITAL_OUT);
	CButton* pAnaIn  = (CButton*) GetDlgItem(IDC_RADIO_ANALOG_IN);
	CButton* pAnaOut = (CButton*) GetDlgItem(IDC_RADIO_ANALOG_OUT);

	CComboBox * pPins = (CComboBox *)GetDlgItem(IDC_COMBO_PINS)	;
	_UpdatePinRadios(_GetPinSelection());

	// get pin from XMLSturct;
	CString csName;
	pPins->GetLBText(pPins->GetCurSel(), csName);
	//AfxMessageBox(csName);

	
	CComboBox * pcRegisters = (CComboBox *)GetDlgItem(IDC_COMBO_REGISTER)	;
	CComboBox * pcBits = (CComboBox *)GetDlgItem(IDC_COMBO_BIT)	;
	
	
	MPin pin;
	if (TRUE == m_EmbeddedConfig.GetPinByName(pin, csName))
	{
		pDigIn->EnableWindow(TRUE);
		pDigOut->EnableWindow(TRUE);
	///	pAnaIn->EnableWindow(FALSE);
	///	pAnaOut->EnableWindow(FALSE);
		
		pDigIn->SetCheck(0);
		pDigOut->SetCheck(0);
		pAnaIn->SetCheck(0);
		pAnaOut->SetCheck(0);


		if ( (pin.GetName() == _T("PD4")) || (pin.GetName() == _T("PD5")) )
		{
			pAnaOut->EnableWindow(TRUE);
		}
		else if (
			   (pin.GetName() == _T("PA0")) || (pin.GetName() == _T("PA1"))
			|| (pin.GetName() == _T("PA2")) || (pin.GetName() == _T("PA3"))
			|| (pin.GetName() == _T("PA4")) || (pin.GetName() == _T("PA5"))
			|| (pin.GetName() == _T("PA6")) || (pin.GetName() == _T("PA7"))
			
			)
		{
			pAnaIn->EnableWindow(TRUE);
		}


		
		if (pin.GetType() == MPin::DIG_IN)
		{
			pDigIn->SetCheck(1);
		}
		else if (pin.GetType() == MPin::DIG_OUT)
		{
			pDigOut->SetCheck(1);
		}
		else if (pin.GetType() == MPin::ANALOG_OUT)
		{
			pAnaOut->SetCheck(1);
		}
		else if (pin.GetType() == MPin::ANALOG_IN)
		{
			pAnaIn->SetCheck(1);
		}
	
		if(pin.GetRegister().CompareNoCase(_T("IM00")) == 0)
			pcRegisters->SetCurSel(0);
		else if(pin.GetRegister().CompareNoCase(_T("IM01")) == 0)
			pcRegisters->SetCurSel(1);
		else if(pin.GetRegister().CompareNoCase(_T("IM02")) == 0)
			pcRegisters->SetCurSel(2);
		else if(pin.GetRegister().CompareNoCase(_T("IM03")) == 0)
			pcRegisters->SetCurSel(3);
		else if(pin.GetRegister().CompareNoCase(_T("OM00")) == 0)
			pcRegisters->SetCurSel(0);
		else if(pin.GetRegister().CompareNoCase(_T("OM01")) == 0)
			pcRegisters->SetCurSel(1);
		else if(pin.GetRegister().CompareNoCase(_T("OM02")) == 0)
			pcRegisters->SetCurSel(2);
		else if(pin.GetRegister().CompareNoCase(_T("OM03")) == 0)
			pcRegisters->SetCurSel(3);
		else if (pin.GetRegister().CompareNoCase(_T("AI00")) == 0)
			pcRegisters->SetCurSel(0);
		else if (pin.GetRegister().CompareNoCase(_T("AI01")) == 0)
			pcRegisters->SetCurSel(1);
		else if (pin.GetRegister().CompareNoCase(_T("AO00")) == 0)
			pcRegisters->SetCurSel(0);
		else if (pin.GetRegister().CompareNoCase(_T("AO01")) == 0)
			pcRegisters->SetCurSel(1);


		else 
			pcRegisters->SetCurSel(-1);

		if(pin.GetBit().CompareNoCase(_T("0")) == 0)
			pcBits->SetCurSel(0);
		else if(pin.GetBit().CompareNoCase(_T("1")) == 0)
			pcBits->SetCurSel(1);
		else if(pin.GetBit().CompareNoCase(_T("2")) == 0)
			pcBits->SetCurSel(2);
		else if(pin.GetBit().CompareNoCase(_T("3")) == 0)
			pcBits->SetCurSel(3);
		else if(pin.GetBit().CompareNoCase(_T("4")) == 0)
			pcBits->SetCurSel(4);
		else if(pin.GetBit().CompareNoCase(_T("5")) == 0)
			pcBits->SetCurSel(5);
		else if(pin.GetBit().CompareNoCase(_T("6")) == 0)
			pcBits->SetCurSel(6);
		else if(pin.GetBit().CompareNoCase(_T("7")) == 0)
			pcBits->SetCurSel(7);
		else 
			pcBits->SetCurSel(-1);

	
	}

}
void CEKonfiguratorDlg::OnButtonOpen() 
{
	CString csProfiles;
	CString csAllFiles;
	CString csError;
	CString csDumy;
	CComboBox * pComboModes		= (CComboBox *)GetDlgItem(IDC_COMBO_MODES);
	CComboBox * pComboProcessor = (CComboBox *)GetDlgItem(IDC_COMBO_PROCESSOR);
	CComboBox * pComboFrequency = (CComboBox *)GetDlgItem(IDC_COMBO_SPI_FREQUENCY);
	
	CComboBox * pComboPins		= (CComboBox *)GetDlgItem(IDC_COMBO_PINS);


	csProfiles.LoadString(IDS_STRING_TAG_CONFIG);
	csAllFiles.LoadString(IDS_STRING_TAG_ALLFILES);

	CString strFilter = csProfiles + " (*.ecf)|*.ecf|" + csAllFiles +" (*.*)|*.*||";
	
	CFileDialog SaveCfgDialog(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter);
	SaveCfgDialog.m_ofn.lpstrTitle = csProfiles ;
	

	CFile file;
	//CString csFileName;
	if(SaveCfgDialog.DoModal() == IDOK)
	{
		m_csFileName = SaveCfgDialog.GetPathName() ;
		m_EmbeddedConfig.ReadFromConfigFile(m_csFileName);

		CString csTitle = "E-Konfigurator [";
		csTitle.Format(L"E-Konfigurator [%s]", m_csFileName);
		SetWindowText(csTitle.GetBuffer(0));
		
		// update 
		pComboModes->SetCurSel(m_EmbeddedConfig.GetMode());
		pComboProcessor->SetCurSel(m_EmbeddedConfig.GetProcessor());
		pComboFrequency->SetCurSel(m_EmbeddedConfig.GetSpiFrequency());
		OnSelchangeComboModes();


		CComboBox * pComboPins = (CComboBox *)GetDlgItem(IDC_COMBO_PINS);
		int nCount  = pComboPins->GetCount();

		CString csPin;
		MPin pin;
		for (int i = 0; i< nCount ; i++)
		{
			try
			{
				pComboPins->SetCurSel(i);
				pComboPins->GetLBText(i, csPin);
				m_EmbeddedConfig.GetPinByName(pin, csPin);
				if (   (pin.GetType()== MPin::DIG_IN) || (pin.GetType() == MPin::DIG_OUT) )
				{
					csDumy = pin.GetRegister() + "." +pin.GetBit() ;
					m_pPinEditSelection[_GetPinSelection()]->SetWindowText( csDumy);
				
				}
				else
				{
					csDumy = pin.GetRegister()  ;
					m_pPinEditSelection[_GetPinSelection()]->SetWindowText( csDumy);
				}
			}
			catch(...)
			{}
		}

		// set focus on first element
		pComboPins->SetCurSel(0);		
		
		//OnRadio0() ; 


	}			
}
void CEKonfiguratorDlg::OnButtonSave() 
{
/*
*/
	if(!m_csFileName.IsEmpty())
	{
		m_EmbeddedConfig.WriteIntoConfigFile(m_csFileName);
	}
	else 
	{
		AfxMessageBox(L"No config file is selected !");
	}
}
void CEKonfiguratorDlg::OnUpdate() 
{
	UpdateData();
	CButton* pDigIn  = (CButton*) GetDlgItem(IDC_RADIO_DIGITAL_IN);
	CButton* pDigOut = (CButton*) GetDlgItem(IDC_RADIO_DIGITAL_OUT);
	CButton* pAnaIn  = (CButton*) GetDlgItem(IDC_RADIO_ANALOG_IN);
	CButton* pAnaOut = (CButton*) GetDlgItem(IDC_RADIO_ANALOG_OUT);

	CComboBox * pComboModes = (CComboBox *)GetDlgItem(IDC_COMBO_MODES);
	
	CButton * pUpdate = (CButton *)GetDlgItem(IDB_UPDATE);
///	pUpdate->EnableWindow(FALSE);

	CComboBox * pPins = (CComboBox *)GetDlgItem(IDC_COMBO_PINS)	;
	CComboBox * pReg = (CComboBox *)GetDlgItem(IDC_COMBO_REGISTER)	;
	CComboBox * pBit= (CComboBox *)GetDlgItem(IDC_COMBO_BIT)	;

	// get pin from XMLSturct;
	CString csName;
	pPins->GetLBText(pPins->GetCurSel(), csName);

	MPin pin;
	if (TRUE == m_EmbeddedConfig.GetPinByName(pin, csName))
	{
		if (pDigIn->GetCheck() == 1)
		{
			pin.SetType(MPin::DIG_IN);
		}
		else if (pDigOut->GetCheck() == 1)
		{
			pin.SetType(MPin::DIG_OUT);
		}
		else if (pAnaIn->GetCheck() == 1)
		{
			pin.SetType(MPin::ANALOG_IN);
		}
		else if (pAnaOut->GetCheck() == 1)
		{
			pin.SetType(MPin::ANALOG_OUT);
		}

//		m_EmbeddedConfig.SetMode(pComboModes->GetCurSel());

		CString csRegister;
		pReg->GetLBText(pReg->GetCurSel(), csRegister);
		pin.SetRegister(csRegister);

		CString csBit;
		pBit->GetLBText(pBit->GetCurSel(), csBit);
		
		if ( (pin.GetType()== MPin::DIG_IN)  || (pin.GetType()== MPin::DIG_OUT) )
			m_pPinEditSelection[_GetPinSelection()]->SetWindowText(csRegister + "." + csBit);
		
		else 
			m_pPinEditSelection[_GetPinSelection()]->SetWindowText(csRegister );
		
		pin.SetRegister(csRegister);
		pin.SetBit(csBit);
				
		m_EmbeddedConfig.SetPinByName(pin, csName);

		///
		CComboBox * pComboMode = (CComboBox *)GetDlgItem(IDC_COMBO_MODES);
		m_nMode = pComboMode->GetCurSel();
		m_EmbeddedConfig.SetMode(m_nMode);
		
		///
		CComboBox * pComboProcessor = (CComboBox *)GetDlgItem(IDC_COMBO_PROCESSOR);
		m_nProcessor = pComboProcessor->GetCurSel();
		m_EmbeddedConfig.SetProcessor(m_nProcessor);

		CComboBox * pComboFrequency = (CComboBox *)GetDlgItem(IDC_COMBO_SPI_FREQUENCY);
		m_nSpiFrequency = pComboFrequency->GetCurSel();
		m_EmbeddedConfig.SetSpiFrequency(m_nSpiFrequency);

	}
}
void CEKonfiguratorDlg::OnRadioDigitalIn() 
{
	CButton * pUpdate = (CButton *)GetDlgItem(IDB_UPDATE);
	pUpdate->EnableWindow(TRUE);	
	
	CComboBox * pRegister = (CComboBox *)GetDlgItem(IDC_COMBO_REGISTER);
	pRegister->ResetContent();
	pRegister->AddString(_T("IM00"));
	pRegister->AddString(_T("IM01"));
	pRegister->AddString(_T("IM02"));
	pRegister->AddString(_T("IM03"));
	pRegister->SetCurSel(0);

}
void CEKonfiguratorDlg::OnRadioDigitalOut() 
{
	CButton * pUpdate = (CButton *)GetDlgItem(IDB_UPDATE);
	pUpdate->EnableWindow(TRUE);		

	CComboBox * pRegister = (CComboBox *)GetDlgItem(IDC_COMBO_REGISTER);
	pRegister->ResetContent();
	pRegister->AddString(_T("OM00"));
	pRegister->AddString(_T("OM01"));
	pRegister->AddString(_T("OM02"));
	pRegister->AddString(_T("OM03"));
	pRegister->SetCurSel(0);
}
void CEKonfiguratorDlg::OnRadioAnalogIn() 
{
	CButton * pUpdate = (CButton *)GetDlgItem(IDB_UPDATE);
	pUpdate->EnableWindow(TRUE);	
	
	CComboBox * pRegister = (CComboBox *)GetDlgItem(IDC_COMBO_REGISTER);
	pRegister->ResetContent();
	pRegister->AddString(_T("AI00"));
	pRegister->AddString(_T("AI01"));
	pRegister->SetCurSel(0);
}
void CEKonfiguratorDlg::OnRadioAnalogOut() 
{
	CButton * pUpdate = (CButton *)GetDlgItem(IDB_UPDATE);
	pUpdate->EnableWindow(TRUE);		
	CComboBox * pRegister = (CComboBox *)GetDlgItem(IDC_COMBO_REGISTER);
	pRegister->ResetContent();

	CButton * pD4 = (CButton *)GetDlgItem(IDC_RADIO17);
	CButton * pD5 = (CButton *)GetDlgItem(IDC_RADIO18);

/*	
*/
	{
		pRegister->AddString(_T("AO00"));
		pRegister->AddString(_T("AO01"));
	}

	pRegister->SetCurSel(0);
}
void CEKonfiguratorDlg::OnSelchangeComboRegister() 
{
	CButton * pUpdate = (CButton *)GetDlgItem(IDB_UPDATE);
	pUpdate->EnableWindow(TRUE);	
}
void CEKonfiguratorDlg::OnSelchangeComboBit() 
{
	CButton * pUpdate = (CButton *)GetDlgItem(IDB_UPDATE);
	pUpdate->EnableWindow(TRUE);

	// update
	OnUpdate();

}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
void CEKonfiguratorDlg::_SetPinComboBox(CString csTitle)
{
	CButton* pDigIn  = (CButton*) GetDlgItem(IDC_RADIO_DIGITAL_IN);
	CButton* pDigOut = (CButton*) GetDlgItem(IDC_RADIO_DIGITAL_OUT);
	CButton* pAnaIn  = (CButton*) GetDlgItem(IDC_RADIO_ANALOG_IN);
	CButton* pAnaOut = (CButton*) GetDlgItem(IDC_RADIO_ANALOG_OUT);

	if (pDigIn->GetCheck() == 1)
	{
		OnRadioDigitalIn();
	}
	else if (pDigOut->GetCheck() == 1)
	{
		OnRadioDigitalOut();
	}
	else if (pAnaIn->GetCheck() == 1)
	{
		OnRadioAnalogIn();
	}
	else if (pAnaOut->GetCheck() == 1)
	{
		OnRadioAnalogOut();
	}

	CComboBox * pComboPins = (CComboBox *)GetDlgItem(IDC_COMBO_PINS);
	CComboBox * pComboReg = (CComboBox *)GetDlgItem(IDC_COMBO_REGISTER);
	CString csText;
	for (int i = 0; i< pComboPins->GetCount(); i++)
	{
		pComboPins->GetLBText(i, csText);
		if (csText.CompareNoCase(csTitle.GetBuffer(0)) == 0)
		{
			pComboPins->SetCurSel(i);
			pComboPins->SetFocus();
			OnSelchangeComboPins();
			break;
		}
	}
} 
void CEKonfiguratorDlg::OnRadio20() 
{
	_SetPinComboBox(_T("PA0"));
	_SetPinComboBox(_T("PA0"));

}
void CEKonfiguratorDlg::OnRadio21() 
{
	_SetPinComboBox(_T("PA1"));
	_SetPinComboBox(_T("PA1"));
}
void CEKonfiguratorDlg::OnRadio22() 
{
	_SetPinComboBox(_T("PA2"));
	_SetPinComboBox(_T("PA2"));
}
void CEKonfiguratorDlg::OnRadio23() 
{
	_SetPinComboBox(_T("PA3"));
	_SetPinComboBox(_T("PA3"));
}
void CEKonfiguratorDlg::OnRadio24() 
{
	_SetPinComboBox(_T("PA4"));
	_SetPinComboBox(_T("PA4"));
}
void CEKonfiguratorDlg::OnRadio25() 
{
	_SetPinComboBox(_T("PA5"));
	_SetPinComboBox(_T("PA5"));
}
void CEKonfiguratorDlg::OnRadio26() 
{
	_SetPinComboBox(_T("PA6"));
	_SetPinComboBox(_T("PA6"));
}
void CEKonfiguratorDlg::OnRadio27() 
{
	_SetPinComboBox(_T("PA7"));
	_SetPinComboBox(_T("PA7"));
}
void CEKonfiguratorDlg::OnRadio31() 
{
	_SetPinComboBox(_T("PC7"));
	_SetPinComboBox(_T("PC7"));
}
void CEKonfiguratorDlg::OnRadio32() 
{
	_SetPinComboBox(_T("PC6"));
	_SetPinComboBox(_T("PC6"));
}
void CEKonfiguratorDlg::OnRadio33() 
{
	_SetPinComboBox(_T("PC5"));
	_SetPinComboBox(_T("PC5"));
}
void CEKonfiguratorDlg::OnRadio34() 
{
	_SetPinComboBox(_T("PC4"));
	_SetPinComboBox(_T("PC4"));
}
void CEKonfiguratorDlg::OnRadio35() 
{
	_SetPinComboBox(_T("PC3"));
	_SetPinComboBox(_T("PC3"));
}
void CEKonfiguratorDlg::OnRadio36() 
{
	_SetPinComboBox(_T("PC2"));
	_SetPinComboBox(_T("PC2"));
}
void CEKonfiguratorDlg::OnRadio37() 
{
	_SetPinComboBox(_T("PC1"));
	_SetPinComboBox(_T("PC1"));
}
void CEKonfiguratorDlg::OnRadio38() 
{
	_SetPinComboBox(_T("PC0"));
	_SetPinComboBox(_T("PC0"));
}
void CEKonfiguratorDlg::OnRadio39() 
{
	_SetPinComboBox(_T("PD7"));
	_SetPinComboBox(_T("PD7"));
}
void CEKonfiguratorDlg::OnRadio19() 
{
	_SetPinComboBox(_T("PD6"));
	_SetPinComboBox(_T("PD6"));
}
void CEKonfiguratorDlg::OnRadio18() 
{
	_SetPinComboBox(_T("PD5"));
	_SetPinComboBox(_T("PD5"));
}
void CEKonfiguratorDlg::OnRadio17() 
{
	_SetPinComboBox(_T("PD4"));
	_SetPinComboBox(_T("PD4"));
}
void CEKonfiguratorDlg::OnRadio16() 
{
	_SetPinComboBox(_T("PD3"));
	_SetPinComboBox(_T("PD3"));
}
void CEKonfiguratorDlg::OnRadio15() 
{
	_SetPinComboBox(_T("PD2"));
	_SetPinComboBox(_T("PD2"));
}
void CEKonfiguratorDlg::OnRadio7() 
{
	_SetPinComboBox(_T("PB7"));
	_SetPinComboBox(_T("PB7"));
}
void CEKonfiguratorDlg::OnRadio6() 
{
	_SetPinComboBox(_T("PB6"));
	_SetPinComboBox(_T("PB6"));
}
void CEKonfiguratorDlg::OnRadio5() 
{
	_SetPinComboBox(_T("PB5"));
	_SetPinComboBox(_T("PB5"));
}
void CEKonfiguratorDlg::OnRadio4() 
{
	_SetPinComboBox(_T("PB4"));
	_SetPinComboBox(_T("PB4"));
}
void CEKonfiguratorDlg::OnRadio3() 
{
	_SetPinComboBox(_T("PB3"));
	_SetPinComboBox(_T("PB3"));
}
void CEKonfiguratorDlg::OnRadio2() 
{
	_SetPinComboBox(_T("PB2"));
	_SetPinComboBox(_T("PB2"));
}
void CEKonfiguratorDlg::OnRadio1() 
{
	_SetPinComboBox(_T("PB1"));
	_SetPinComboBox(_T("PB1"));
}
void CEKonfiguratorDlg::OnRadio0() 
{
	_SetPinComboBox(_T("PB0"));
	_SetPinComboBox(_T("PB0"));
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

void CEKonfiguratorDlg::OnSelchangeComboProcessor() 
{
	// update
	OnUpdate();
}

void CEKonfiguratorDlg::OnSelchangeComboSpiFrequency() 
{
	// update
	OnUpdate();
}
