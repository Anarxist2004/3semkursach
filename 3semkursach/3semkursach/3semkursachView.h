
// 3semkursachView.h: интерфейс класса CMy3semkursachView
//

#pragma once

#include "3semkursachDoc.h"
class CMy3semkursachView : public CView
{
protected: // создать только из сериализации
	CMy3semkursachView() noexcept;
	DECLARE_DYNCREATE(CMy3semkursachView)

// Атрибуты
public:
	CMy3semkursachDoc* GetDocument() const;

// Операции
public:
	CButton m_radioB1, m_radioB2, m_radioB3, m_radioB4, m_radioB5, m_radioB6,Start;
	CEdit m_editD, m_editD1, m_editd, m_editL, m_editB, m_editm;
	CString strD, strD1, strd, strL, strB, strm;
	CStatic T_D, T_D1, T_d, T_L, T_B, T_m;
	double D, D1, d, L, B, m;
// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	void Updatedrawing();
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();

	afx_msg void OnEditChangeD();
	afx_msg void OnEditChangeD1();
	afx_msg void OnEditChanged();
	afx_msg void OnEditChangeL();
	afx_msg void OnEditChangeB();
	afx_msg void OnEditChangem();
	void DoubleToCString();
	void StartKompas();
// Реализация
public:
	virtual ~CMy3semkursachView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // версия отладки в 3semkursachView.cpp
inline CMy3semkursachDoc* CMy3semkursachView::GetDocument() const
   { return reinterpret_cast<CMy3semkursachDoc*>(m_pDocument); }
#endif

