#pragma once


// DialogKichThuoc dialog

class DialogKichThuoc : public CDialog
{
	DECLARE_DYNAMIC(DialogKichThuoc)

public:
	DialogKichThuoc(CWnd* pParent = NULL);   // standard constructor
	virtual ~DialogKichThuoc();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGKICHTHUOC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int d_KichThuoc;
	int d_SoHinh;
};
