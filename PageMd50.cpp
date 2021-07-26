// PageMd50.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "EKonfigurator.h"
#include "PageMd50.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CPageMd50 


CPageMd50::CPageMd50(CWnd* pParent /*=NULL*/)
	: CDialog(CPageMd50::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPageMd50)
		// HINWEIS: Der Klassen-Assistent fügt hier Elementinitialisierung ein
	//}}AFX_DATA_INIT
}


void CPageMd50::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageMd50)
		// HINWEIS: Der Klassen-Assistent fügt hier DDX- und DDV-Aufrufe ein
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageMd50, CDialog)
	//{{AFX_MSG_MAP(CPageMd50)
		// HINWEIS: Der Klassen-Assistent fügt hier Zuordnungsmakros für Nachrichten ein
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CPageMd50 
