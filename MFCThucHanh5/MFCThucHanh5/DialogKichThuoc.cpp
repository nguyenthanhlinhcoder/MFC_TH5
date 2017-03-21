// DialogKichThuoc.cpp : implementation file
//

#include "stdafx.h"
#include "MFCThucHanh5.h"
#include "DialogKichThuoc.h"
#include "afxdialogex.h"


// DialogKichThuoc dialog

IMPLEMENT_DYNAMIC(DialogKichThuoc, CDialog)

DialogKichThuoc::DialogKichThuoc(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOGKICHTHUOC, pParent)
	, d_KichThuoc(0)
	, d_SoHinh(0)
{

}

DialogKichThuoc::~DialogKichThuoc()
{
}

void DialogKichThuoc::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_KICHTHUOC, d_KichThuoc);
	DDV_MinMaxInt(pDX, d_KichThuoc, 0, 100);
	DDX_Text(pDX, IDC_EDIT_SOHINH, d_SoHinh);
	DDV_MinMaxInt(pDX, d_SoHinh, 0, 10);
}


BEGIN_MESSAGE_MAP(DialogKichThuoc, CDialog)
END_MESSAGE_MAP()


// DialogKichThuoc message handlers
