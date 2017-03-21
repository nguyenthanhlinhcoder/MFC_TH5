
// MFCThucHanh5View.cpp : implementation of the CMFCThucHanh5View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCThucHanh5.h"
#endif

#include "MFCThucHanh5Doc.h"
#include "MFCThucHanh5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCThucHanh5View

IMPLEMENT_DYNCREATE(CMFCThucHanh5View, CView)

BEGIN_MESSAGE_MAP(CMFCThucHanh5View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCThucHanh5View construction/destruction

CMFCThucHanh5View::CMFCThucHanh5View()
{
	// TODO: add construction code here

}

CMFCThucHanh5View::~CMFCThucHanh5View()
{
}

BOOL CMFCThucHanh5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCThucHanh5View drawing

void CMFCThucHanh5View::OnDraw(CDC* pDC)
{
	CMFCThucHanh5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	pDC->SetMapMode(MM_LOENGLISH);

	//Lấy về số hình, kích thước từ file Doc
	int v_sohinh = pDoc->GetSoHinh();
	int v_kichthuoc = pDoc->GetKichThuoc();

	
	int size = v_kichthuoc*(v_sohinh)+50;

	//Thực hiện vẽ các ô màu tương ứng với grid
	if (v_sohinh != 0 && v_kichthuoc != 0)
	{
		for (int i = 0; i < v_sohinh; i++)
		{
			for (int j = 0; j < v_sohinh; j++)
			{
				int mausac = pDoc->GetMauSacTheoViTri(i, j);
				COLORREF color;
				switch (mausac)
				{
				case 1:
					color = RGB(255, 0, 0);
					break;
				case 2:
					color = RGB(0, 255, 0);
					break;
				case 3:
					color = RGB(0, 0, 255);
					break;
				default:
					color = RGB(255, 255, 255);
					break;
				}
				CBrush brush(color);
				int x1 = (j*v_kichthuoc) + 50;
				int y1 = (i*-v_kichthuoc) - 50;
				int x2 = x1 + v_kichthuoc;
				int y2 = y1 - v_kichthuoc;
				CRect rect(x1, y1, x2, y2);
				pDC->FillRect(rect, &brush);
			}
		}
		//Vẽ các đường sọc ngang, dọc
		for (int i = 50; i <= size; i += v_kichthuoc)
		{
			pDC->MoveTo(i, -50);
			pDC->LineTo(i, -size);
		}
		for (int i = -50; i >= -size; i -= v_kichthuoc)
		{
			pDC->MoveTo(50, i);
			pDC->LineTo(size, i);
		}

	}



}


// CMFCThucHanh5View diagnostics

#ifdef _DEBUG
void CMFCThucHanh5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCThucHanh5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCThucHanh5Doc* CMFCThucHanh5View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCThucHanh5Doc)));
	return (CMFCThucHanh5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCThucHanh5View message handlers


void CMFCThucHanh5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnLButtonDown(nFlags, point);
	//Lấy về màn hình hiện tại
	CClientDC dc(this);

	//Đổi hệ trục sang đơn vị inch
	dc.SetMapMode(MM_LOENGLISH);
	CPoint pos = point;
	dc.DPtoLP(&pos);

	//Lấy về đối tượng Document tương ứng
	CMFCThucHanh5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int v_sohinh = pDoc->GetSoHinh();
	int v_kichthuoc = pDoc->GetKichThuoc();
	int size = v_kichthuoc*(v_sohinh)+50;

	if (pos.x >= 50 && pos.x <= size && pos.y <= -50 && pos.y >= -size)
	{
		int i = -(pos.y + 50) / v_kichthuoc;
		int j = (pos.x - 50) / v_kichthuoc;
		int currentColor = pDoc->GetMauSacHienTai();
		pDoc->SetMauSacTheoViTri(i, j, currentColor);
	}

}
