
// MFCThucHanh5Doc.cpp : implementation of the CMFCThucHanh5Doc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCThucHanh5.h"
#endif

#include "MFCThucHanh5Doc.h"
#include "DialogMauSac.h"
#include "DialogKichThuoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCThucHanh5Doc

IMPLEMENT_DYNCREATE(CMFCThucHanh5Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCThucHanh5Doc, CDocument)
	ON_COMMAND(ID_THIETLAP_KICHTHUOC, &CMFCThucHanh5Doc::OnThietlapKichthuoc)
	ON_COMMAND(ID_THIETLAP_MAUSAC, &CMFCThucHanh5Doc::OnThietlapMausac)
END_MESSAGE_MAP()


// CMFCThucHanh5Doc construction/destruction

CMFCThucHanh5Doc::CMFCThucHanh5Doc()
{
	// TODO: add one-time construction code here

	m_MauSac = 0;
	m_KichThuoc = 0;
	m_SoHinh = 0;
	m_MauSacHienTai = 0;
}

CMFCThucHanh5Doc::~CMFCThucHanh5Doc()
{
}

BOOL CMFCThucHanh5Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CMFCThucHanh5Doc serialization

void CMFCThucHanh5Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar << m_MauSacHienTai;
		ar << m_KichThuoc;
		ar << m_SoHinh;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				ar << m_GridMauSac[i][j];
			}
		}
	}
	else
	{
		// TODO: add loading code here
		ar >> m_MauSacHienTai;
		ar >> m_KichThuoc;
		ar >> m_SoHinh;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				ar >> m_GridMauSac[i][j];
			}
		}
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMFCThucHanh5Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMFCThucHanh5Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCThucHanh5Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCThucHanh5Doc diagnostics

#ifdef _DEBUG
void CMFCThucHanh5Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCThucHanh5Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCThucHanh5Doc commands


void CMFCThucHanh5Doc::OnThietlapKichthuoc()
{
	// TODO: Add your command handler code here
	DialogKichThuoc dlg = new DialogKichThuoc();

	//Lấy giá trị đã lưu lần trước gán vào các ô textbox trong Dialog
	dlg.d_SoHinh = m_SoHinh;
	dlg.d_KichThuoc = m_KichThuoc;

	if (dlg.DoModal() == IDOK)
	{
		m_SoHinh = dlg.d_SoHinh;
		m_KichThuoc = dlg.d_KichThuoc;

		UpdateAllViews(NULL);
	}

}


void CMFCThucHanh5Doc::OnThietlapMausac()
{
	// TODO: Add your command handler code here
	DialogMauSac dlg = new DialogMauSac();

	dlg.d_MauSac = m_MauSacHienTai - 1;

	if (dlg.DoModal()==IDOK)
	{
		m_MauSacHienTai = dlg.d_MauSac + 1 ;
	}
}


int CMFCThucHanh5Doc::GetSoHinh()
{
	return m_SoHinh;
}


int CMFCThucHanh5Doc::GetKichThuoc()
{
	return m_KichThuoc;
}


int CMFCThucHanh5Doc::GetMauSacHienTai()
{
	return m_MauSacHienTai;
}


int CMFCThucHanh5Doc::GetMauSacTheoViTri(int i, int j)
{
	return m_GridMauSac[i][j];
}


//int CMFCThucHanh5Doc::SetMauSacTheoViTri(int i, int j, int mauSac)
//{
//	return 0;
//}


void CMFCThucHanh5Doc::SetMauSacTheoViTri(int i, int j, int mauSac)
{
	m_GridMauSac[i][j] = mauSac;
	SetModifiedFlag(true);
	UpdateAllViews(NULL);
}
