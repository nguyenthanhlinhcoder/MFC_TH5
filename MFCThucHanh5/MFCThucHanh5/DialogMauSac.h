#pragma once


// DialogMauSac dialog

class DialogMauSac : public CDialog
{
	DECLARE_DYNAMIC(DialogMauSac)

public:
	DialogMauSac(CWnd* pParent = NULL);   // standard constructor
	virtual ~DialogMauSac();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGMAUSAC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int d_MauSac;
};
