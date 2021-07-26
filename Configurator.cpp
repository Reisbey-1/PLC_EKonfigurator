// Configurator.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "EKonfigurator.h"
#include "Configurator.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConfigurator

IMPLEMENT_DYNAMIC(CConfigurator, CPropertySheet)

CConfigurator::CConfigurator(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CConfigurator::CConfigurator(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	///AddPage((CPropertyPage*)(&m_pageMD50));
}

CConfigurator::~CConfigurator()
{
}


BEGIN_MESSAGE_MAP(CConfigurator, CPropertySheet)
	//{{AFX_MSG_MAP(CConfigurator)
		// HINWEIS - Der Klassen-Assistent fügt hier Zuordnungsmakros ein und entfernt diese.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CConfigurator 
