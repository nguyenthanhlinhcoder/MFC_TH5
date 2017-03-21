
// MFCThucHanh5View.h : interface of the CMFCThucHanh5View class
//

#pragma once


class CMFCThucHanh5View : public CView
{
protected: // create from serialization only
	CMFCThucHanh5View();
	DECLARE_DYNCREATE(CMFCThucHanh5View)

// Attributes
public:
	CMFCThucHanh5Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CMFCThucHanh5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in MFCThucHanh5View.cpp
inline CMFCThucHanh5Doc* CMFCThucHanh5View::GetDocument() const
   { return reinterpret_cast<CMFCThucHanh5Doc*>(m_pDocument); }
#endif

