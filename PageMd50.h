#if !defined(AFX_PAGEMD50_H__510074A4_C7BA_4775_8A2C_6DDD573C1DB1__INCLUDED_)
#define AFX_PAGEMD50_H__510074A4_C7BA_4775_8A2C_6DDD573C1DB1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageMd50.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CPageMd50 

class CPageMd50 : public CDialog
{
// Konstruktion
public:
	CPageMd50(CWnd* pParent = NULL);   // Standardkonstruktor

// Dialogfelddaten
	//{{AFX_DATA(CPageMd50)
	enum { IDD = IDD_PROPPAGE_MD50 };
		// HINWEIS: Der Klassen-Assistent f�gt hier Datenelemente ein
	//}}AFX_DATA


// �berschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktions�berschreibungen
	//{{AFX_VIRTUAL(CPageMd50)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterst�tzung
	//}}AFX_VIRTUAL

// Implementierung
protected:

	// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(CPageMd50)
		// HINWEIS: Der Klassen-Assistent f�gt hier Member-Funktionen ein
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // AFX_PAGEMD50_H__510074A4_C7BA_4775_8A2C_6DDD573C1DB1__INCLUDED_
