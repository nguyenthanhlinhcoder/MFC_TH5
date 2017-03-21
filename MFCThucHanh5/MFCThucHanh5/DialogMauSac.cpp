// DialogMauSac.cpp : implementation file
//

#include "stdafx.h"
#include "MFCThucHanh5.h"
#include "DialogMauSac.h"
#include "afxdialogex.h"


// DialogMauSac dialog

IMPLEMENT_DYNAMIC(DialogMauSac, CDialog)

DialogMauSac::DialogMauSac(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOGMAUSAC, pParent)
	, d_MauSac(0)
{

}

DialogMauSac::~DialogMauSac()
{
}

void DialogMauSac::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_MAUSAC, d_MauSac);
}


BEGIN_MESSAGE_MAP(DialogMauSac, CDialog)
END_MESSAGE_MAP()


// DialogMauSac message handlers
