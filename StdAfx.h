// stdafx.h : Include-Datei f�r Standard-System-Include-Dateien,
//  oder projektspezifische Include-Dateien, die h�ufig benutzt, aber
//      in unregelm��igen Abst�nden ge�ndert werden.
//

#if !defined(STDAFX_H__38FC9AF9_D4E2_4B94_815F_3CCDFBB9CF9E__INCLUDED_)
#define STDAFX_H__38FC9AF9_D4E2_4B94_815F_3CCDFBB9CF9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#define VC_EXTRALEAN		// Selten verwendete Teile der Windows-Header nicht einbinden

#include <afxwin.h>         // MFC-Kern- und -Standardkomponenten
#include <afxext.h>         // MFC-Erweiterungen
#include <afxdisp.h>        // MFC Automatisierungsklassen
#include <afxdtctl.h>		// MFC-Unterst�tzung f�r allgemeine Steuerelemente von Internet Explorer 4
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC-Unterst�tzung f�r g�ngige Windows-Steuerelemente
#endif // _AFX_NO_AFXCMN_SUPPORT

#include "..\..\MCommon\implement\MCommon_Include.h"
using namespace MCommon ;

#include "..\..\EagCommon_6\implement\EagCommon_Include.h"
using namespace eag;


#include "..\..\dtl\implement\Globals_Include.h"
#include  "..\..\XmlDll\implement\XmlDLL_include.h"


using namespace XmlDll ;


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // !defined(STDAFX_H__38FC9AF9_D4E2_4B94_815F_3CCDFBB9CF9E__INCLUDED_)
