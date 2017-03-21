
// MFCThucHanh5Doc.h : interface of the CMFCThucHanh5Doc class
//


#pragma once


class CMFCThucHanh5Doc : public CDocument
{
protected: // create from serialization only
	CMFCThucHanh5Doc();
	DECLARE_DYNCREATE(CMFCThucHanh5Doc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CMFCThucHanh5Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnThietlapKichthuoc();
	afx_msg void OnThietlapMausac();
	int m_MauSac;
	int m_KichThuoc;
	int m_SoHinh;
	int m_MauSacHienTai;
	int m_GridMauSac[10][10];
	int GetSoHinh();
	int GetKichThuoc();
	int GetMauSacHienTai();
	int GetMauSacTheoViTri(int i, int j);
//	int SetMauSacTheoViTri(int i, int j, int mauSac);
	void SetMauSacTheoViTri(int i, int j, int mauSac);
};
