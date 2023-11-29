// CMyTreeView.cpp: файл реализации
//

#include "pch.h"
#include"3semkursach.h"
#include "3semkursach.h"
#include "CMyTreeView.h"
#include "3semkursachDoc.h"
#include "3semkursachView.h"

// CMyTreeView

IMPLEMENT_DYNCREATE(CMyTreeView, CTreeView)

CMyTreeView::CMyTreeView()
{

}

CMyTreeView::~CMyTreeView()
{
}

BEGIN_MESSAGE_MAP(CMyTreeView, CTreeView)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// Диагностика CMyTreeView

#ifdef _DEBUG
void CMyTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// Обработчики сообщений CMyTreeView


int CMyTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	
	lpCreateStruct->style |= TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS | TVS_CHECKBOXES;
	
	// TODO:  Добавьте специализированный код создания
if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;
	return 0;
}
void CMyTreeView::FillTree()
{
	CTreeCtrl& tree = GetTreeCtrl();


	tree.DeleteAllItems();

	m_hSborka = tree.InsertItem(L"Сборка", -1, -1, NULL, TVI_FIRST);
	m_hVrez = tree.InsertItem(L"Резинка", -1, -1, NULL, TVI_FIRST);
	m_hRing = tree.InsertItem(L"Кольцо", -1, -1, NULL, TVI_FIRST);
	m_hFlan = tree.InsertItem(L"Фланец", -1, -1, NULL, TVI_FIRST);
	m_hBolt = tree.InsertItem(L"Болт", -1, -1, NULL, TVI_FIRST);


}


void CMyTreeView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CTreeCtrl& tree = GetTreeCtrl();

	CTreeView::OnLButtonDown(nFlags, point);
	CRect rc;
	tree.GetItemRect(m_hSborka, &rc, false);
	if (rc.PtInRect(point)) {
		tree.SelectItem(m_hSborka);
	}
	tree.GetItemRect(m_hVrez, &rc, false);
	if (rc.PtInRect(point)) {
		tree.SelectItem(m_hVrez);
	}
	tree.GetItemRect(m_hRing, &rc, false);
	if (rc.PtInRect(point)) {
		tree.SelectItem(m_hRing);
	}
	tree.GetItemRect(m_hFlan, &rc, false);
	if (rc.PtInRect(point)) {
		tree.SelectItem(m_hFlan);
	}
	tree.GetItemRect(m_hBolt, &rc, false);
	if (rc.PtInRect(point)) {
		tree.SelectItem(m_hBolt);
	}


	if (tree.GetSelectedItem() == m_hSborka)
	{
		bool check = tree.GetCheck(m_hSborka);
		tree.SetCheck(m_hVrez, 0);
		tree.SetCheck(m_hBolt, 0);
		tree.SetCheck(m_hRing, 0);
		tree.SetCheck(m_hFlan, 0);
	}
	if (tree.GetSelectedItem() == m_hVrez)
	{
		bool check = tree.GetCheck(m_hVrez);
		tree.SetCheck(m_hSborka, 0);
		tree.SetCheck(m_hBolt, 0);
		tree.SetCheck(m_hRing, 0);
		tree.SetCheck(m_hFlan, 0);
	}
	if (tree.GetSelectedItem() == m_hBolt)
	{
		bool check = tree.GetCheck(m_hBolt);
		tree.SetCheck(m_hVrez, 0);
		tree.SetCheck(m_hSborka, 0);
		tree.SetCheck(m_hRing, 0);
		tree.SetCheck(m_hFlan, 0);
	}
	if (tree.GetSelectedItem() == m_hRing)
	{
		bool check = tree.GetCheck(m_hRing);
		tree.SetCheck(m_hVrez, 0);
		tree.SetCheck(m_hBolt, 0);
		tree.SetCheck(m_hSborka, 0);
		tree.SetCheck(m_hFlan, 0);
	}
	if (tree.GetSelectedItem() == m_hFlan)
	{
		bool check = tree.GetCheck(m_hFlan);
		tree.SetCheck(m_hVrez, 0);
		tree.SetCheck(m_hBolt, 0);
		tree.SetCheck(m_hRing, 0);
		tree.SetCheck(m_hSborka, 0);
	}
	m_pDoc->m_bSborka = 1;
	m_pDoc->pView->Invalidate(1);
}
