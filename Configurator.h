#if !defined(AFX_CONFIGURATOR_H__F407A3AA_0E52_490C_B596_570F6631D3E1__INCLUDED_)
#define AFX_CONFIGURATOR_H__F407A3AA_0E52_490C_B596_570F6631D3E1__INCLUDED_

#include "EKonfiguratorDlg.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Configurator.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// CConfigurator

class CConfigurator : public CPropertySheet
{
	DECLARE_DYNAMIC(CConfigurator)

// Konstruktion
public:
	CConfigurator(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CConfigurator(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attribute
public:
	CEKonfiguratorDlg			m_pageMD50;

// Operationen
public:

// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(CConfigurator)
	//}}AFX_VIRTUAL

// Implementierung
public:
	virtual ~CConfigurator();

	// Generierte Nachrichtenzuordnungsfunktionen
protected:
	//{{AFX_MSG(CConfigurator)
		// HINWEIS - Der Klassen-Assistent fügt hier Member-Funktionen ein und entfernt diese.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // AFX_CONFIGURATOR_H__F407A3AA_0E52_490C_B596_570F6631D3E1__INCLUDED_
