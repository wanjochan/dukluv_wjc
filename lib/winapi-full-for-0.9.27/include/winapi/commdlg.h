/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_COMMDLG
#define _INC_COMMDLG

#ifdef DEFINE_GUID
DEFINE_GUID(IID_IPrintDialogCallback,0x5852a2c3,0x6530,0x11d1,0xb6,0xa3,0x0,0x0,0xf8,0x75,0x7b,0xf9);
DEFINE_GUID(IID_IPrintDialogServices,0x509aaeda,0x5639,0x11d1,0xb6,0xa1,0x0,0x0,0xf8,0x75,0x7b,0xf9);
#endif

#ifndef GUID_DEFS_ONLY
#include <prsht.h>
#if !defined(_WIN64)
#include <pshpack1.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WINCOMMDLGAPI
#ifndef _COMDLG32_
#define WINCOMMDLGAPI DECLSPEC_IMPORT
#else
#define WINCOMMDLGAPI
#endif
#endif

#ifndef SNDMSG
#ifdef __cplusplus
#define SNDMSG ::SendMessage
#else
#define SNDMSG SendMessage
#endif
#endif

  typedef UINT_PTR (CALLBACK *LPOFNHOOKPROC) (HWND,UINT,WPARAM,LPARAM);

#ifndef CDSIZEOF_STRUCT
#define CDSIZEOF_STRUCT(structname,member) (((int)((LPBYTE)(&((structname*)0)->member) - ((LPBYTE)((structname*)0)))) + sizeof(((structname*)0)->member))
#endif

  typedef struct tagOFN_NT4A {
    DWORD lStructSize;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCSTR lpstrFilter;
    LPSTR lpstrCustomFilter;
    DWORD nMaxCustFilter;
    DWORD nFilterIndex;
    LPSTR lpstrFile;
    DWORD nMaxFile;
    LPSTR lpstrFileTitle;
    DWORD nMaxFileTitle;
    LPCSTR lpstrInitialDir;
    LPCSTR lpstrTitle;
    DWORD Flags;
    WORD nFileOffset;
    WORD nFileExtension;
    LPCSTR lpstrDefExt;
    LPARAM lCustData;
    LPOFNHOOKPROC lpfnHook;
    LPCSTR lpTemplateName;
  } OPENFILENAME_NT4A,*LPOPENFILENAME_NT4A;
  typedef struct tagOFN_NT4W {
    DWORD lStructSize;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCWSTR lpstrFilter;
    LPWSTR lpstrCustomFilter;
    DWORD nMaxCustFilter;
    DWORD nFilterIndex;
    LPWSTR lpstrFile;
    DWORD nMaxFile;
    LPWSTR lpstrFileTitle;
    DWORD nMaxFileTitle;
    LPCWSTR lpstrInitialDir;
    LPCWSTR lpstrTitle;
    DWORD Flags;
    WORD nFileOffset;
    WORD nFileExtension;
    LPCWSTR lpstrDefExt;
    LPARAM lCustData;
    LPOFNHOOKPROC lpfnHook;
    LPCWSTR lpTemplateName;
  } OPENFILENAME_NT4W,*LPOPENFILENAME_NT4W;
#ifdef UNICODE
  typedef OPENFILENAME_NT4W OPENFILENAME_NT4;
  typedef LPOPENFILENAME_NT4W LPOPENFILENAME_NT4;
#else
  typedef OPENFILENAME_NT4A OPENFILENAME_NT4;
  typedef LPOPENFILENAME_NT4A LPOPENFILENAME_NT4;
#endif

  typedef struct tagOFNA {
    DWORD lStructSize;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCSTR lpstrFilter;
    LPSTR lpstrCustomFilter;
    DWORD nMaxCustFilter;
    DWORD nFilterIndex;
    LPSTR lpstrFile;
    DWORD nMaxFile;
    LPSTR lpstrFileTitle;
    DWORD nMaxFileTitle;
    LPCSTR lpstrInitialDir;
    LPCSTR lpstrTitle;
    DWORD Flags;
    WORD nFileOffset;
    WORD nFileExtension;
    LPCSTR lpstrDefExt;
    LPARAM lCustData;
    LPOFNHOOKPROC lpfnHook;
    LPCSTR lpTemplateName;
    void *pvReserved;
    DWORD dwReserved;
    DWORD FlagsEx;
  } OPENFILENAMEA,*LPOPENFILENAMEA;
  typedef struct tagOFNW {
    DWORD lStructSize;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCWSTR lpstrFilter;
    LPWSTR lpstrCustomFilter;
    DWORD nMaxCustFilter;
    DWORD nFilterIndex;
    LPWSTR lpstrFile;
    DWORD nMaxFile;
    LPWSTR lpstrFileTitle;
    DWORD nMaxFileTitle;
    LPCWSTR lpstrInitialDir;
    LPCWSTR lpstrTitle;
    DWORD Flags;
    WORD nFileOffset;
    WORD nFileExtension;
    LPCWSTR lpstrDefExt;
    LPARAM lCustData;
    LPOFNHOOKPROC lpfnHook;
    LPCWSTR lpTemplateName;
    void *pvReserved;
    DWORD dwReserved;
    DWORD FlagsEx;
  } OPENFILENAMEW,*LPOPENFILENAMEW;
#ifdef UNICODE
  typedef OPENFILENAMEW OPENFILENAME;
  typedef LPOPENFILENAMEW LPOPENFILENAME;
#else
  typedef OPENFILENAMEA OPENFILENAME;
  typedef LPOPENFILENAMEA LPOPENFILENAME;
#endif

#define OPENFILENAME_SIZE_VERSION_400A CDSIZEOF_STRUCT(OPENFILENAMEA,lpTemplateName)
#define OPENFILENAME_SIZE_VERSION_400W CDSIZEOF_STRUCT(OPENFILENAMEW,lpTemplateName)
#ifdef UNICODE
#define OPENFILENAME_SIZE_VERSION_400 OPENFILENAME_SIZE_VERSION_400W
#else
#define OPENFILENAME_SIZE_VERSION_400 OPENFILENAME_SIZE_VERSION_400A
#endif

  WINCOMMDLGAPI WINBOOL WINAPI GetOpenFileNameA(LPOPENFILENAMEA);
  WINCOMMDLGAPI WINBOOL WINAPI GetOpenFileNameW(LPOPENFILENAMEW);
#ifdef UNICODE
#define GetOpenFileName GetOpenFileNameW
#else
#define GetOpenFileName GetOpenFileNameA
#endif
  WINCOMMDLGAPI WINBOOL WINAPI GetSaveFileNameA(LPOPENFILENAMEA);
  WINCOMMDLGAPI WINBOOL WINAPI GetSaveFileNameW(LPOPENFILENAMEW);
#ifdef UNICODE
#define GetSaveFileName GetSaveFileNameW
#else
#define GetSaveFileName GetSaveFileNameA
#endif

  WINCOMMDLGAPI short WINAPI GetFileTitleA(LPCSTR,LPSTR,WORD);
  WINCOMMDLGAPI short WINAPI GetFileTitleW(LPCWSTR,LPWSTR,WORD);
#ifdef UNICODE
#define GetFileTitle GetFileTitleW
#else
#define GetFileTitle GetFileTitleA
#endif

#define OFN_READONLY 0x1
#define OFN_OVERWRITEPROMPT 0x2
#define OFN_HIDEREADONLY 0x4
#define OFN_NOCHANGEDIR 0x8
#define OFN_SHOWHELP 0x10
#define OFN_ENABLEHOOK 0x20
#define OFN_ENABLETEMPLATE 0x40
#define OFN_ENABLETEMPLATEHANDLE 0x80
#define OFN_NOVALIDATE 0x100
#define OFN_ALLOWMULTISELECT 0x200
#define OFN_EXTENSIONDIFFERENT 0x400
#define OFN_PATHMUSTEXIST 0x800
#define OFN_FILEMUSTEXIST 0x1000
#define OFN_CREATEPROMPT 0x2000
#define OFN_SHAREAWARE 0x4000
#define OFN_NOREADONLYRETURN 0x8000
#define OFN_NOTESTFILECREATE 0x10000
#define OFN_NONETWORKBUTTON 0x20000
#define OFN_NOLONGNAMES 0x40000
#define OFN_EXPLORER 0x80000
#define OFN_NODEREFERENCELINKS 0x100000
#define OFN_LONGNAMES 0x200000
#define OFN_ENABLEINCLUDENOTIFY 0x400000
#define OFN_ENABLESIZING 0x800000
#define OFN_DONTADDTORECENT 0x2000000
#define OFN_FORCESHOWHIDDEN 0x10000000
#define OFN_EX_NOPLACESBAR 0x1
#define OFN_SHAREFALLTHROUGH 2
#define OFN_SHARENOWARN 1
#define OFN_SHAREWARN 0

  typedef UINT_PTR (CALLBACK *LPCCHOOKPROC) (HWND,UINT,WPARAM,LPARAM);

  typedef struct _OFNOTIFYA {
    NMHDR hdr;
    LPOPENFILENAMEA lpOFN;
    LPSTR pszFile;
  } OFNOTIFYA,*LPOFNOTIFYA;

  typedef struct _OFNOTIFYW {
    NMHDR hdr;
    LPOPENFILENAMEW lpOFN;
    LPWSTR pszFile;
  } OFNOTIFYW,*LPOFNOTIFYW;
#ifdef UNICODE
  typedef OFNOTIFYW OFNOTIFY;
  typedef LPOFNOTIFYW LPOFNOTIFY;
#else
  typedef OFNOTIFYA OFNOTIFY;
  typedef LPOFNOTIFYA LPOFNOTIFY;
#endif

  typedef struct _OFNOTIFYEXA {
    NMHDR hdr;
    LPOPENFILENAMEA lpOFN;
    LPVOID psf;
    LPVOID pidl;
  } OFNOTIFYEXA,*LPOFNOTIFYEXA;

  typedef struct _OFNOTIFYEXW {
    NMHDR hdr;
    LPOPENFILENAMEW lpOFN;
    LPVOID psf;
    LPVOID pidl;
  } OFNOTIFYEXW,*LPOFNOTIFYEXW;
#ifdef UNICODE
  typedef OFNOTIFYEXW OFNOTIFYEX;
  typedef LPOFNOTIFYEXW LPOFNOTIFYEX;
#else
  typedef OFNOTIFYEXA OFNOTIFYEX;
  typedef LPOFNOTIFYEXA LPOFNOTIFYEX;
#endif

#define CDN_FIRST (0U-601U)
#define CDN_LAST (0U-699U)

#define CDN_INITDONE (CDN_FIRST)
#define CDN_SELCHANGE (CDN_FIRST - 1)
#define CDN_FOLDERCHANGE (CDN_FIRST - 2)
#define CDN_SHAREVIOLATION (CDN_FIRST - 3)
#define CDN_HELP (CDN_FIRST - 4)
#define CDN_FILEOK (CDN_FIRST - 5)
#define CDN_TYPECHANGE (CDN_FIRST - 6)
#define CDN_INCLUDEITEM (CDN_FIRST - 7)

#define CDM_FIRST (WM_USER + 100)
#define CDM_LAST (WM_USER + 200)

#define CDM_GETSPEC (CDM_FIRST)
#define CommDlg_OpenSave_GetSpecA(_hdlg,_psz,_cbmax) (int)SNDMSG(_hdlg,CDM_GETSPEC,(WPARAM)_cbmax,(LPARAM)(LPSTR)_psz)
#define CommDlg_OpenSave_GetSpecW(_hdlg,_psz,_cbmax) (int)SNDMSG(_hdlg,CDM_GETSPEC,(WPARAM)_cbmax,(LPARAM)(LPWSTR)_psz)
#ifdef UNICODE
#define CommDlg_OpenSave_GetSpec CommDlg_OpenSave_GetSpecW
#else
#define CommDlg_OpenSave_GetSpec CommDlg_OpenSave_GetSpecA
#endif

#define CDM_GETFILEPATH (CDM_FIRST + 1)
#define CommDlg_OpenSave_GetFilePathA(_hdlg,_psz,_cbmax) (int)SNDMSG(_hdlg,CDM_GETFILEPATH,(WPARAM)_cbmax,(LPARAM)(LPSTR)_psz)
#define CommDlg_OpenSave_GetFilePathW(_hdlg,_psz,_cbmax) (int)SNDMSG(_hdlg,CDM_GETFILEPATH,(WPARAM)_cbmax,(LPARAM)(LPWSTR)_psz)
#ifdef UNICODE
#define CommDlg_OpenSave_GetFilePath CommDlg_OpenSave_GetFilePathW
#else
#define CommDlg_OpenSave_GetFilePath CommDlg_OpenSave_GetFilePathA
#endif

#define CDM_GETFOLDERPATH (CDM_FIRST + 2)
#define CommDlg_OpenSave_GetFolderPathA(_hdlg,_psz,_cbmax) (int)SNDMSG(_hdlg,CDM_GETFOLDERPATH,(WPARAM)_cbmax,(LPARAM)(LPSTR)_psz)
#define CommDlg_OpenSave_GetFolderPathW(_hdlg,_psz,_cbmax) (int)SNDMSG(_hdlg,CDM_GETFOLDERPATH,(WPARAM)_cbmax,(LPARAM)(LPWSTR)_psz)
#ifdef UNICODE
#define CommDlg_OpenSave_GetFolderPath CommDlg_OpenSave_GetFolderPathW
#else
#define CommDlg_OpenSave_GetFolderPath CommDlg_OpenSave_GetFolderPathA
#endif

#define CDM_GETFOLDERIDLIST (CDM_FIRST + 3)
#define CommDlg_OpenSave_GetFolderIDList(_hdlg,_pidl,_cbmax) (int)SNDMSG(_hdlg,CDM_GETFOLDERIDLIST,(WPARAM)_cbmax,(LPARAM)(LPVOID)_pidl)
#define CDM_SETCONTROLTEXT (CDM_FIRST + 4)
#define CommDlg_OpenSave_SetControlText(_hdlg,_id,_text) (void)SNDMSG(_hdlg,CDM_SETCONTROLTEXT,(WPARAM)_id,(LPARAM)(LPSTR)_text)
#define CDM_HIDECONTROL (CDM_FIRST + 5)
#define CommDlg_OpenSave_HideControl(_hdlg,_id) (void)SNDMSG(_hdlg,CDM_HIDECONTROL,(WPARAM)_id,0)
#define CDM_SETDEFEXT (CDM_FIRST + 6)
#define CommDlg_OpenSave_SetDefExt(_hdlg,_pszext) (void)SNDMSG(_hdlg,CDM_SETDEFEXT,0,(LPARAM)(LPSTR)_pszext)

  typedef struct tagCHOOSECOLORA {
    DWORD lStructSize;
    HWND hwndOwner;
    HWND hInstance;
    COLORREF rgbResult;
    COLORREF *lpCustColors;
    DWORD Flags;
    LPARAM lCustData;
    LPCCHOOKPROC lpfnHook;
    LPCSTR lpTemplateName;
  } CHOOSECOLORA,*LPCHOOSECOLORA;
  typedef struct tagCHOOSECOLORW {
    DWORD lStructSize;
    HWND hwndOwner;
    HWND hInstance;
    COLORREF rgbResult;
    COLORREF *lpCustColors;
    DWORD Flags;
    LPARAM lCustData;
    LPCCHOOKPROC lpfnHook;
    LPCWSTR lpTemplateName;
  } CHOOSECOLORW,*LPCHOOSECOLORW;
#ifdef UNICODE
  typedef CHOOSECOLORW CHOOSECOLOR;
  typedef LPCHOOSECOLORW LPCHOOSECOLOR;
#else
  typedef CHOOSECOLORA CHOOSECOLOR;
  typedef LPCHOOSECOLORA LPCHOOSECOLOR;
#endif

  WINCOMMDLGAPI WINBOOL WINAPI ChooseColorA(LPCHOOSECOLORA);
  WINCOMMDLGAPI WINBOOL WINAPI ChooseColorW(LPCHOOSECOLORW);
#ifdef UNICODE
#define ChooseColor ChooseColorW
#else
#define ChooseColor ChooseColorA
#endif

#define CC_RGBINIT 0x1
#define CC_FULLOPEN 0x2
#define CC_PREVENTFULLOPEN 0x4
#define CC_SHOWHELP 0x8
#define CC_ENABLEHOOK 0x10
#define CC_ENABLETEMPLATE 0x20
#define CC_ENABLETEMPLATEHANDLE 0x40
#define CC_SOLIDCOLOR 0x80
#define CC_ANYCOLOR 0x100

  typedef UINT_PTR (CALLBACK *LPFRHOOKPROC) (HWND,UINT,WPARAM,LPARAM);

  typedef struct tagFINDREPLACEA {
    DWORD lStructSize;
    HWND hwndOwner;
    HINSTANCE hInstance;
    DWORD Flags;
    LPSTR lpstrFindWhat;
    LPSTR lpstrReplaceWith;
    WORD wFindWhatLen;
    WORD wReplaceWithLen;
    LPARAM lCustData;
    LPFRHOOKPROC lpfnHook;
    LPCSTR lpTemplateName;
  } FINDREPLACEA,*LPFINDREPLACEA;

  typedef struct tagFINDREPLACEW {
    DWORD lStructSize;
    HWND hwndOwner;
    HINSTANCE hInstance;
    DWORD Flags;
    LPWSTR lpstrFindWhat;
    LPWSTR lpstrReplaceWith;
    WORD wFindWhatLen;
    WORD wReplaceWithLen;
    LPARAM lCustData;
    LPFRHOOKPROC lpfnHook;
    LPCWSTR lpTemplateName;
  } FINDREPLACEW,*LPFINDREPLACEW;
#ifdef UNICODE
  typedef FINDREPLACEW FINDREPLACE;
  typedef LPFINDREPLACEW LPFINDREPLACE;
#else
  typedef FINDREPLACEA FINDREPLACE;
  typedef LPFINDREPLACEA LPFINDREPLACE;
#endif

#define FR_DOWN 0x1
#define FR_WHOLEWORD 0x2
#define FR_MATCHCASE 0x4
#define FR_FINDNEXT 0x8
#define FR_REPLACE 0x10
#define FR_REPLACEALL 0x20
#define FR_DIALOGTERM 0x40
#define FR_SHOWHELP 0x80
#define FR_ENABLEHOOK 0x100
#define FR_ENABLETEMPLATE 0x200
#define FR_NOUPDOWN 0x400
#define FR_NOMATCHCASE 0x800
#define FR_NOWHOLEWORD 0x1000
#define FR_ENABLETEMPLATEHANDLE 0x2000
#define FR_HIDEUPDOWN 0x4000
#define FR_HIDEMATCHCASE 0x8000
#define FR_HIDEWHOLEWORD 0x10000
#define FR_RAW 0x20000
#define FR_MATCHDIAC 0x20000000
#define FR_MATCHKASHIDA 0x40000000
#define FR_MATCHALEFHAMZA 0x80000000

  WINCOMMDLGAPI HWND WINAPI FindTextA(LPFINDREPLACEA);
  WINCOMMDLGAPI HWND WINAPI FindTextW(LPFINDREPLACEW);
#ifdef UNICODE
#define FindText FindTextW
#else
#define FindText FindTextA
#endif
  WINCOMMDLGAPI HWND WINAPI ReplaceTextA(LPFINDREPLACEA);
  WINCOMMDLGAPI HWND WINAPI ReplaceTextW(LPFINDREPLACEW);
#ifdef UNICODE
#define ReplaceText ReplaceTextW
#else
#define ReplaceText ReplaceTextA
#endif

  typedef UINT_PTR (CALLBACK *LPCFHOOKPROC) (HWND,UINT,WPARAM,LPARAM);

  typedef struct tagCHOOSEFONTA {
    DWORD lStructSize;
    HWND hwndOwner;
    HDC hDC;
    LPLOGFONTA lpLogFont;
    INT iPointSize;
    DWORD Flags;
    COLORREF rgbColors;
    LPARAM lCustData;
    LPCFHOOKPROC lpfnHook;
    LPCSTR lpTemplateName;
    HINSTANCE hInstance;
    LPSTR lpszStyle;
    WORD nFontType;
    WORD ___MISSING_ALIGNMENT__;
    INT nSizeMin;
    INT nSizeMax;
  } CHOOSEFONTA,*LPCHOOSEFONTA;

  typedef struct tagCHOOSEFONTW {
    DWORD lStructSize;
    HWND hwndOwner;
    HDC hDC;
    LPLOGFONTW lpLogFont;
    INT iPointSize;
    DWORD Flags;
    COLORREF rgbColors;
    LPARAM lCustData;
    LPCFHOOKPROC lpfnHook;
    LPCWSTR lpTemplateName;
    HINSTANCE hInstance;
    LPWSTR lpszStyle;
    WORD nFontType;
    WORD ___MISSING_ALIGNMENT__;
    INT nSizeMin;
    INT nSizeMax;
  } CHOOSEFONTW,*LPCHOOSEFONTW;
#ifdef UNICODE
  typedef CHOOSEFONTW CHOOSEFONT;
  typedef LPCHOOSEFONTW LPCHOOSEFONT;
#else
  typedef CHOOSEFONTA CHOOSEFONT;
  typedef LPCHOOSEFONTA LPCHOOSEFONT;
#endif

  WINCOMMDLGAPI WINBOOL WINAPI ChooseFontA(LPCHOOSEFONTA);
  WINCOMMDLGAPI WINBOOL WINAPI ChooseFontW(LPCHOOSEFONTW);
#ifdef UNICODE
#define ChooseFont ChooseFontW
#else
#define ChooseFont ChooseFontA
#endif

#define CF_SCREENFONTS 0x1
#define CF_PRINTERFONTS 0x2
#define CF_BOTH (CF_SCREENFONTS | CF_PRINTERFONTS)
#define CF_SHOWHELP 0x4L
#define CF_ENABLEHOOK 0x8L
#define CF_ENABLETEMPLATE 0x10L
#define CF_ENABLETEMPLATEHANDLE 0x20L
#define CF_INITTOLOGFONTSTRUCT 0x40L
#define CF_USESTYLE 0x80L
#define CF_EFFECTS 0x100L
#define CF_APPLY 0x200L
#define CF_ANSIONLY 0x400L
#define CF_SCRIPTSONLY CF_ANSIONLY
#define CF_NOVECTORFONTS 0x800L
#define CF_NOOEMFONTS CF_NOVECTORFONTS
#define CF_NOSIMULATIONS 0x1000L
#define CF_LIMITSIZE 0x2000L
#define CF_FIXEDPITCHONLY 0x4000L
#define CF_WYSIWYG 0x8000L
#define CF_FORCEFONTEXIST 0x10000L
#define CF_SCALABLEONLY 0x20000L
#define CF_TTONLY 0x40000L
#define CF_NOFACESEL 0x80000L
#define CF_NOSTYLESEL 0x100000L
#define CF_NOSIZESEL 0x200000L
#define CF_SELECTSCRIPT 0x400000L
#define CF_NOSCRIPTSEL 0x800000L
#define CF_NOVERTFONTS 0x1000000L

#define SIMULATED_FONTTYPE 0x8000
#define PRINTER_FONTTYPE 0x4000
#define SCREEN_FONTTYPE 0x2000
#define BOLD_FONTTYPE 0x100
#define ITALIC_FONTTYPE 0x200
#define REGULAR_FONTTYPE 0x400

#ifdef WINNT
#define PS_OPENTYPE_FONTTYPE 0x10000
#define TT_OPENTYPE_FONTTYPE 0x20000
#define TYPE1_FONTTYPE 0x40000
#endif

#define WM_CHOOSEFONT_GETLOGFONT (WM_USER + 1)
#define WM_CHOOSEFONT_SETLOGFONT (WM_USER + 101)
#define WM_CHOOSEFONT_SETFLAGS (WM_USER + 102)

#define LBSELCHSTRINGA "commdlg_LBSelChangedNotify"
#define SHAREVISTRINGA "commdlg_ShareViolation"
#define FILEOKSTRINGA "commdlg_FileNameOK"
#define COLOROKSTRINGA "commdlg_ColorOK"
#define SETRGBSTRINGA "commdlg_SetRGBColor"
#define HELPMSGSTRINGA "commdlg_help"
#define FINDMSGSTRINGA "commdlg_FindReplace"

#define LBSELCHSTRINGW L"commdlg_LBSelChangedNotify"
#define SHAREVISTRINGW L"commdlg_ShareViolation"
#define FILEOKSTRINGW L"commdlg_FileNameOK"
#define COLOROKSTRINGW L"commdlg_ColorOK"
#define SETRGBSTRINGW L"commdlg_SetRGBColor"
#define HELPMSGSTRINGW L"commdlg_help"
#define FINDMSGSTRINGW L"commdlg_FindReplace"

#ifdef UNICODE
#define LBSELCHSTRING LBSELCHSTRINGW
#define SHAREVISTRING SHAREVISTRINGW
#define FILEOKSTRING FILEOKSTRINGW
#define COLOROKSTRING COLOROKSTRINGW
#define SETRGBSTRING SETRGBSTRINGW
#define HELPMSGSTRING HELPMSGSTRINGW
#define FINDMSGSTRING FINDMSGSTRINGW
#else
#define LBSELCHSTRING LBSELCHSTRINGA
#define SHAREVISTRING SHAREVISTRINGA
#define FILEOKSTRING FILEOKSTRINGA
#define COLOROKSTRING COLOROKSTRINGA
#define SETRGBSTRING SETRGBSTRINGA
#define HELPMSGSTRING HELPMSGSTRINGA
#define FINDMSGSTRING FINDMSGSTRINGA
#endif

#define CD_LBSELNOITEMS -1
#define CD_LBSELCHANGE 0
#define CD_LBSELSUB 1
#define CD_LBSELADD 2

  typedef UINT_PTR (CALLBACK *LPPRINTHOOKPROC) (HWND,UINT,WPARAM,LPARAM);
  typedef UINT_PTR (CALLBACK *LPSETUPHOOKPROC) (HWND,UINT,WPARAM,LPARAM);

  typedef struct tagPDA {
    DWORD lStructSize;
    HWND hwndOwner;
    HGLOBAL hDevMode;
    HGLOBAL hDevNames;
    HDC hDC;
    DWORD Flags;
    WORD nFromPage;
    WORD nToPage;
    WORD nMinPage;
    WORD nMaxPage;
    WORD nCopies;
    HINSTANCE hInstance;
    LPARAM lCustData;
    LPPRINTHOOKPROC lpfnPrintHook;
    LPSETUPHOOKPROC lpfnSetupHook;
    LPCSTR lpPrintTemplateName;
    LPCSTR lpSetupTemplateName;
    HGLOBAL hPrintTemplate;
    HGLOBAL hSetupTemplate;
  } PRINTDLGA,*LPPRINTDLGA;

  typedef struct tagPDW {
    DWORD lStructSize;
    HWND hwndOwner;
    HGLOBAL hDevMode;
    HGLOBAL hDevNames;
    HDC hDC;
    DWORD Flags;
    WORD nFromPage;
    WORD nToPage;
    WORD nMinPage;
    WORD nMaxPage;
    WORD nCopies;
    HINSTANCE hInstance;
    LPARAM lCustData;
    LPPRINTHOOKPROC lpfnPrintHook;
    LPSETUPHOOKPROC lpfnSetupHook;
    LPCWSTR lpPrintTemplateName;
    LPCWSTR lpSetupTemplateName;
    HGLOBAL hPrintTemplate;
    HGLOBAL hSetupTemplate;
  } PRINTDLGW,*LPPRINTDLGW;
#ifdef UNICODE
  typedef PRINTDLGW PRINTDLG;
  typedef LPPRINTDLGW LPPRINTDLG;
#else
  typedef PRINTDLGA PRINTDLG;
  typedef LPPRINTDLGA LPPRINTDLG;
#endif

  WINCOMMDLGAPI WINBOOL WINAPI PrintDlgA(LPPRINTDLGA);
  WINCOMMDLGAPI WINBOOL WINAPI PrintDlgW(LPPRINTDLGW);
#ifdef UNICODE
#define PrintDlg PrintDlgW
#else
#define PrintDlg PrintDlgA
#endif

#ifdef STDMETHOD
#undef INTERFACE
#define INTERFACE IPrintDialogCallback

  DECLARE_INTERFACE_(IPrintDialogCallback,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(InitDone) (THIS) PURE;
    STDMETHOD(SelectionChange) (THIS) PURE;
    STDMETHOD(HandleMessage) (THIS_ HWND hDlg,UINT uMsg,WPARAM wParam,LPARAM lParam,LRESULT *pResult) PURE;
  };

#undef INTERFACE
#define INTERFACE IPrintDialogServices
  DECLARE_INTERFACE_(IPrintDialogServices,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(GetCurrentDevMode) (THIS_ LPDEVMODE pDevMode,UINT *pcbSize) PURE;
    STDMETHOD(GetCurrentPrinterName) (THIS_ LPTSTR pPrinterName,UINT *pcchSize) PURE;
    STDMETHOD(GetCurrentPortName) (THIS_ LPTSTR pPortName,UINT *pcchSize) PURE;
  };

  typedef struct tagPRINTPAGERANGE {
    DWORD nFromPage;
    DWORD nToPage;
  } PRINTPAGERANGE,*LPPRINTPAGERANGE;

  typedef struct tagPDEXA {
    DWORD lStructSize;
    HWND hwndOwner;
    HGLOBAL hDevMode;
    HGLOBAL hDevNames;
    HDC hDC;
    DWORD Flags;
    DWORD Flags2;
    DWORD ExclusionFlags;
    DWORD nPageRanges;
    DWORD nMaxPageRanges;
    LPPRINTPAGERANGE lpPageRanges;
    DWORD nMinPage;
    DWORD nMaxPage;
    DWORD nCopies;
    HINSTANCE hInstance;
    LPCSTR lpPrintTemplateName;
    LPUNKNOWN lpCallback;
    DWORD nPropertyPages;
    HPROPSHEETPAGE *lphPropertyPages;
    DWORD nStartPage;
    DWORD dwResultAction;
  } PRINTDLGEXA,*LPPRINTDLGEXA;

  typedef struct tagPDEXW {
    DWORD lStructSize;
    HWND hwndOwner;
    HGLOBAL hDevMode;
    HGLOBAL hDevNames;
    HDC hDC;
    DWORD Flags;
    DWORD Flags2;
    DWORD ExclusionFlags;
    DWORD nPageRanges;
    DWORD nMaxPageRanges;
    LPPRINTPAGERANGE lpPageRanges;
    DWORD nMinPage;
    DWORD nMaxPage;
    DWORD nCopies;
    HINSTANCE hInstance;
    LPCWSTR lpPrintTemplateName;
    LPUNKNOWN lpCallback;
    DWORD nPropertyPages;
    HPROPSHEETPAGE *lphPropertyPages;
    DWORD nStartPage;
    DWORD dwResultAction;
  } PRINTDLGEXW,*LPPRINTDLGEXW;
#ifdef UNICODE
  typedef PRINTDLGEXW PRINTDLGEX;
  typedef LPPRINTDLGEXW LPPRINTDLGEX;
#else
  typedef PRINTDLGEXA PRINTDLGEX;
  typedef LPPRINTDLGEXA LPPRINTDLGEX;
#endif

  WINCOMMDLGAPI HRESULT WINAPI PrintDlgExA(LPPRINTDLGEXA);
  WINCOMMDLGAPI HRESULT WINAPI PrintDlgExW(LPPRINTDLGEXW);
#ifdef UNICODE
#define PrintDlgEx PrintDlgExW
#else
#define PrintDlgEx PrintDlgExA
#endif
#endif

#define PD_ALLPAGES 0x0
#define PD_SELECTION 0x1
#define PD_PAGENUMS 0x2
#define PD_NOSELECTION 0x4
#define PD_NOPAGENUMS 0x8
#define PD_COLLATE 0x10
#define PD_PRINTTOFILE 0x20
#define PD_PRINTSETUP 0x40
#define PD_NOWARNING 0x80
#define PD_RETURNDC 0x100
#define PD_RETURNIC 0x200
#define PD_RETURNDEFAULT 0x400
#define PD_SHOWHELP 0x800
#define PD_ENABLEPRINTHOOK 0x1000
#define PD_ENABLESETUPHOOK 0x2000
#define PD_ENABLEPRINTTEMPLATE 0x4000
#define PD_ENABLESETUPTEMPLATE 0x8000
#define PD_ENABLEPRINTTEMPLATEHANDLE 0x10000
#define PD_ENABLESETUPTEMPLATEHANDLE 0x20000
#define PD_USEDEVMODECOPIES 0x40000
#define PD_USEDEVMODECOPIESANDCOLLATE 0x40000
#define PD_DISABLEPRINTTOFILE 0x80000
#define PD_HIDEPRINTTOFILE 0x100000
#define PD_NONETWORKBUTTON 0x200000
#define PD_CURRENTPAGE 0x400000
#define PD_NOCURRENTPAGE 0x800000
#define PD_EXCLUSIONFLAGS 0x1000000
#define PD_USELARGETEMPLATE 0x10000000

#define PD_EXCL_COPIESANDCOLLATE (DM_COPIES | DM_COLLATE)
#define START_PAGE_GENERAL 0xffffffff

#define PD_RESULT_CANCEL 0
#define PD_RESULT_PRINT 1
#define PD_RESULT_APPLY 2

  typedef struct tagDEVNAMES {
    WORD wDriverOffset;
    WORD wDeviceOffset;
    WORD wOutputOffset;
    WORD wDefault;
  } DEVNAMES,*LPDEVNAMES;

#define DN_DEFAULTPRN 0x1

  WINCOMMDLGAPI DWORD WINAPI CommDlgExtendedError(VOID);

#define WM_PSD_PAGESETUPDLG (WM_USER)
#define WM_PSD_FULLPAGERECT (WM_USER+1)
#define WM_PSD_MINMARGINRECT (WM_USER+2)
#define WM_PSD_MARGINRECT (WM_USER+3)
#define WM_PSD_GREEKTEXTRECT (WM_USER+4)
#define WM_PSD_ENVSTAMPRECT (WM_USER+5)
#define WM_PSD_YAFULLPAGERECT (WM_USER+6)

  typedef UINT_PTR (CALLBACK *LPPAGEPAINTHOOK)(HWND,UINT,WPARAM,LPARAM);
  typedef UINT_PTR (CALLBACK *LPPAGESETUPHOOK)(HWND,UINT,WPARAM,LPARAM);

  typedef struct tagPSDA {
    DWORD lStructSize;
    HWND hwndOwner;
    HGLOBAL hDevMode;
    HGLOBAL hDevNames;
    DWORD Flags;
    POINT ptPaperSize;
    RECT rtMinMargin;
    RECT rtMargin;
    HINSTANCE hInstance;
    LPARAM lCustData;
    LPPAGESETUPHOOK lpfnPageSetupHook;
    LPPAGEPAINTHOOK lpfnPagePaintHook;
    LPCSTR lpPageSetupTemplateName;
    HGLOBAL hPageSetupTemplate;
  } PAGESETUPDLGA,*LPPAGESETUPDLGA;

  typedef struct tagPSDW {
    DWORD lStructSize;
    HWND hwndOwner;
    HGLOBAL hDevMode;
    HGLOBAL hDevNames;
    DWORD Flags;
    POINT ptPaperSize;
    RECT rtMinMargin;
    RECT rtMargin;
    HINSTANCE hInstance;
    LPARAM lCustData;
    LPPAGESETUPHOOK lpfnPageSetupHook;
    LPPAGEPAINTHOOK lpfnPagePaintHook;
    LPCWSTR lpPageSetupTemplateName;
    HGLOBAL hPageSetupTemplate;
  } PAGESETUPDLGW,*LPPAGESETUPDLGW;
#ifdef UNICODE
  typedef PAGESETUPDLGW PAGESETUPDLG;
  typedef LPPAGESETUPDLGW LPPAGESETUPDLG;
#else
  typedef PAGESETUPDLGA PAGESETUPDLG;
  typedef LPPAGESETUPDLGA LPPAGESETUPDLG;
#endif

  WINCOMMDLGAPI WINBOOL WINAPI PageSetupDlgA(LPPAGESETUPDLGA);
  WINCOMMDLGAPI WINBOOL WINAPI PageSetupDlgW(LPPAGESETUPDLGW);
#ifdef UNICODE
#define PageSetupDlg PageSetupDlgW
#else
#define PageSetupDlg PageSetupDlgA
#endif

#define PSD_DEFAULTMINMARGINS 0x0
#define PSD_INWININIINTLMEASURE 0x0
#define PSD_MINMARGINS 0x1
#define PSD_MARGINS 0x2
#define PSD_INTHOUSANDTHSOFINCHES 0x4
#define PSD_INHUNDREDTHSOFMILLIMETERS 0x8
#define PSD_DISABLEMARGINS 0x10
#define PSD_DISABLEPRINTER 0x20
#define PSD_NOWARNING 0x80
#define PSD_DISABLEORIENTATION 0x100
#define PSD_RETURNDEFAULT 0x400
#define PSD_DISABLEPAPER 0x200
#define PSD_SHOWHELP 0x800
#define PSD_ENABLEPAGESETUPHOOK 0x2000
#define PSD_ENABLEPAGESETUPTEMPLATE 0x8000
#define PSD_ENABLEPAGESETUPTEMPLATEHANDLE 0x20000
#define PSD_ENABLEPAGEPAINTHOOK 0x40000
#define PSD_DISABLEPAGEPAINTING 0x80000
#define PSD_NONETWORKBUTTON 0x200000

#ifdef __cplusplus
}
#endif

#ifndef _WIN64
#include <poppack.h>
#endif
#endif
#endif
