// EKonfigurator.h : Haupt-Header-Datei f�r die Anwendung EKONFIGURATOR
//

#if !defined(AFX_EKONFIGURATOR_H__824C7489_D7BC_400E_A623_97130AF5C4FA__INCLUDED_)
#define AFX_EKONFIGURATOR_H__824C7489_D7BC_400E_A623_97130AF5C4FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CEKonfiguratorApp:
// Siehe EKonfigurator.cpp f�r die Implementierung dieser Klasse
//

class CEKonfiguratorApp : public CWinApp
{
public:
	CEKonfiguratorApp();

// �berladungen
	// Vom Klassenassistenten generierte �berladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CEKonfiguratorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung

	//{{AFX_MSG(CEKonfiguratorApp)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingef�gt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VER�NDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // !defined(AFX_EKONFIGURATOR_H__824C7489_D7BC_400E_A623_97130AF5C4FA__INCLUDED_)
