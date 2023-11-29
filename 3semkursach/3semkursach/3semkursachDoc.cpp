
// 3semkursachDoc.cpp: реализация класса CMy3semkursachDoc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "3semkursach.h"
#endif

#include "3semkursachDoc.h"

#include <propkey.h>
#include "CMyTreeView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy3semkursachDoc

IMPLEMENT_DYNCREATE(CMy3semkursachDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy3semkursachDoc, CDocument)
END_MESSAGE_MAP()


// Создание или уничтожение CMy3semkursachDoc

CMy3semkursachDoc::CMy3semkursachDoc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CMy3semkursachDoc::~CMy3semkursachDoc()
{
}

BOOL CMy3semkursachDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	m_bSborka=m_bVrez=m_bRing=m_bFlan=m_bBolt=0;
	pTree->FillTree();
	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// Сериализация CMy3semkursachDoc

void CMy3semkursachDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CMy3semkursachDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
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

// Поддержка обработчиков поиска
void CMy3semkursachDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CMy3semkursachDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CMy3semkursachDoc

#ifdef _DEBUG
void CMy3semkursachDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy3semkursachDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CMy3semkursachDoc
