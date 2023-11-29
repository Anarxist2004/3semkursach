
// 3semkursachDoc.h: интерфейс класса CMy3semkursachDoc 
//


#pragma once

class CMyTreeView;
class CMy3semkursachView;
class CMy3semkursachDoc : public CDocument
{
protected: // создать только из сериализации
	CMy3semkursachDoc() noexcept;
	DECLARE_DYNCREATE(CMy3semkursachDoc)

// Атрибуты
public:
	bool m_bSborka, m_bVrez, m_bRing, m_bFlan, m_bBolt;
	CMy3semkursachView* pView;
	CMyTreeView* pTree;
// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CMy3semkursachDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
