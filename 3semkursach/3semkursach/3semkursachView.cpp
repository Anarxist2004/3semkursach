
// 3semkursachView.cpp: реализация класса CMy3semkursachView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "3semkursach.h"
#endif

#include "3semkursachDoc.h"
#include "3semkursachView.h"
#include "CMyTreeView.h"
#include "C:\Program Files\ASCON\KOMPAS-3D v21 Study\SDK\Include\ksConstants.h"
#include "C:\Program Files\ASCON\KOMPAS-3D v21 Study\SDK\Include\ksConstants3D.h"


#import "C:\Program Files\ASCON\KOMPAS-3D v21 Study\SDK\lib\kAPI5.tlb"
using namespace Kompas6API5;

KompasObjectPtr pKompasApp5;
//KompasObjectPtr pKompasApp5;

ksPartPtr pPart;// = PartDoc->GetTopPart();
ksDocument3DPtr pDoc;
#ifdef _DEBUG
#define new DEBUG_NEW
#define kolzodef
#define detal2
#endif
#define OPA
#define cionid
// CMy3semkursachView

IMPLEMENT_DYNCREATE(CMy3semkursachView, CView)

BEGIN_MESSAGE_MAP(CMy3semkursachView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_RADIO1, &CMy3semkursachView::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMy3semkursachView::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CMy3semkursachView::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CMy3semkursachView::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CMy3semkursachView::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CMy3semkursachView::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_START, &CMy3semkursachView::StartKompas)

	ON_EN_CHANGE(IDC_editD, &CMy3semkursachView::OnEditChangeD)
	ON_EN_CHANGE(IDC_editD1, &CMy3semkursachView::OnEditChangeD1)
	ON_EN_CHANGE(IDC_editd, &CMy3semkursachView::OnEditChanged)
	ON_EN_CHANGE(IDC_editL, &CMy3semkursachView::OnEditChangeL)
	ON_EN_CHANGE(IDC_editB, &CMy3semkursachView::OnEditChangeB)
	ON_EN_CHANGE(IDC_editm, &CMy3semkursachView::OnEditChangem)
END_MESSAGE_MAP()

// Создание или уничтожение CMy3semkursachView

CMy3semkursachView::CMy3semkursachView() noexcept
{
	// TODO: добавьте код создания

}

CMy3semkursachView::~CMy3semkursachView()
{
}

BOOL CMy3semkursachView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CMy3semkursachView

void CMy3semkursachView::OnDraw(CDC* pDC)
{
	CMy3semkursachDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	
	
	if (pDoc->m_bSborka == 1)
	{

		CImage image;
		image.Load(_T("C:\\detali\\sborka.bmp"));

		if (image.IsNull()) {
			return;
		}
		CDC memDC;
		int imageWidth = image.GetWidth();
		int imageHeight = image.GetHeight();
		image.StretchBlt(pDC->GetSafeHdc(), 200, 0, imageWidth, imageHeight, 0, 0, imageWidth, imageHeight, SRCCOPY);
	
	}
	if (pDoc->m_bVrez == 1)
	{
		AfxMessageBox(123);
	}
	if (pDoc->m_bRing == 1)
	{
		AfxMessageBox(123);
	}
	if (pDoc->m_bFlan == 1)
	{
		AfxMessageBox(123);
	}
	if (pDoc->m_bBolt == 1)
	{
		AfxMessageBox(123);
	}


	// TODO: добавьте здесь код отрисовки для собственных данных
}


// Печать CMy3semkursachView

BOOL CMy3semkursachView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CMy3semkursachView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CMy3semkursachView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void CMy3semkursachView::Updatedrawing()
{
	CMy3semkursachDoc* pDoc = GetDocument();
	if (pDoc->m_bSborka == 1)
	{
		AfxMessageBox(123);
	}
	if (pDoc->m_bVrez == 1)
	{
		AfxMessageBox(123);
	}
	if (pDoc->m_bRing == 1)
	{
		AfxMessageBox(123);
	}
	if (pDoc->m_bFlan == 1)
	{
		AfxMessageBox(123);
	}
	if (pDoc->m_bBolt == 1)
	{
		AfxMessageBox(123);
	}
}
// Диагностика CMy3semkursachView

#ifdef _DEBUG
void CMy3semkursachView::AssertValid() const
{
	CView::AssertValid();
}

void CMy3semkursachView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3semkursachDoc* CMy3semkursachView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3semkursachDoc)));
	return (CMy3semkursachDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CMy3semkursachView


void CMy3semkursachView::OnInitialUpdate()
{
	m_radioB1.Create(_T("1 вариант"), WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON, CRect(10, 10, 100, 30), this, IDC_RADIO1);
	m_radioB2.Create(_T("2 вариант"), WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON, CRect(10, 30, 100, 50), this, IDC_RADIO2);
	m_radioB3.Create(_T("3 вариант"), WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON, CRect(10, 50, 100, 70), this, IDC_RADIO3);
	m_radioB4.Create(_T("4 вариант"), WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON, CRect(10, 70, 100, 90), this, IDC_RADIO4);
	m_radioB5.Create(_T("5 вариант"), WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON, CRect(10, 90, 100, 110), this, IDC_RADIO5);
	m_radioB6.Create(_T("6 вариант"), WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON, CRect(10, 110, 100, 130), this, IDC_RADIO6);

	m_editD.Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(30, 130, 100, 150), this, IDC_editD);
	T_D.Create(L"D", WS_CHILD | WS_VISIBLE, CRect(10, 130, 30, 150), this, 0);
	m_editD1.Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(30, 150, 100, 170), this, IDC_editD1);
	T_D1.Create(L"D1", WS_CHILD | WS_VISIBLE, CRect(10, 150, 30, 170), this, 0);
	m_editd.Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(30, 170, 100, 190), this, IDC_editd);
	T_d.Create(L"d", WS_CHILD | WS_VISIBLE, CRect(10, 170, 30, 190), this, 0);
	m_editL.Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(30, 190, 100, 210), this, IDC_editL);
	T_L.Create(L"L", WS_CHILD | WS_VISIBLE, CRect(10, 190, 30, 210), this, 0);
	m_editB.Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(30, 210, 100, 230), this, IDC_editB);
	T_B.Create(L"B", WS_CHILD | WS_VISIBLE, CRect(10, 210, 30, 230), this, 0);
	m_editm.Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(30, 230, 100, 250), this, IDC_editm);
	T_m.Create(L"m", WS_CHILD | WS_VISIBLE, CRect(10, 230, 30, 250), this, 0);


	Start.Create(_T("СТАРТ"), WS_CHILD | WS_VISIBLE, CRect(10, 260, 100, 280), this, IDC_START);



	CView::OnInitialUpdate();




}
void CMy3semkursachView::OnBnClickedRadio1() {
	if (m_radioB1.GetCheck()) {
		m_radioB1.SetCheck(0);
	}
	else {
		m_radioB1.SetCheck(1);
		m_radioB2.SetCheck(0);
		m_radioB3.SetCheck(0);
		m_radioB4.SetCheck(0);
		m_radioB5.SetCheck(0);
		m_radioB6.SetCheck(0);
		D = 104;
		D1 = 50;
		d = 12;
		L = 64;
		B = 16;
		m = 28;
		DoubleToCString();
	}
}
void CMy3semkursachView::OnBnClickedRadio2() {
	if (m_radioB2.GetCheck()) {
		m_radioB2.SetCheck(0);
	}
	else {
		m_radioB1.SetCheck(0);
		m_radioB2.SetCheck(1);
		m_radioB3.SetCheck(0);
		m_radioB4.SetCheck(0);
		m_radioB5.SetCheck(0);
		m_radioB6.SetCheck(0);
		D = 136;
		D1 = 65;
		d = 15;
		L = 88;
		B = 18;
		m = 35;
		DoubleToCString();
	}
}
void CMy3semkursachView::OnBnClickedRadio3() {
	if (m_radioB3.GetCheck()) {
		m_radioB3.SetCheck(0);
	}
	else {
		m_radioB1.SetCheck(0);
		m_radioB2.SetCheck(0);
		m_radioB3.SetCheck(1);
		m_radioB4.SetCheck(0);
		m_radioB5.SetCheck(0);
		m_radioB6.SetCheck(0);
		D = 178;
		D1 = 85;
		d = 20;
		L = 125;
		B = 35;
		m = 47;
		DoubleToCString();
	}
}
void CMy3semkursachView::OnBnClickedRadio4() {
	if (m_radioB4.GetCheck()) {
		m_radioB4.SetCheck(0);
	}
	else {
		m_radioB1.SetCheck(0);
		m_radioB2.SetCheck(0);
		m_radioB3.SetCheck(0);
		m_radioB4.SetCheck(1);
		m_radioB5.SetCheck(0);
		m_radioB6.SetCheck(0);
		D = 210;
		D1 = 110;
		d = 25;
		L = 150;
		B = 38;
		m = 59;
		DoubleToCString();
	}
}
void CMy3semkursachView::OnBnClickedRadio5() {
	if (m_radioB5.GetCheck()) {
		m_radioB5.SetCheck(0);
	}
	else {
		m_radioB1.SetCheck(0);
		m_radioB2.SetCheck(0);
		m_radioB3.SetCheck(0);
		m_radioB4.SetCheck(0);
		m_radioB5.SetCheck(1);
		m_radioB6.SetCheck(0);
		D = 263;
		D1 = 140;
		d = 30;
		L = 174;
		B = 44;
		m = 67;
		DoubleToCString();
	}
}
void CMy3semkursachView::OnBnClickedRadio6() {
	if (m_radioB6.GetCheck()) {
		m_radioB6.SetCheck(0);
	}
	else {
		m_radioB1.SetCheck(0);
		m_radioB2.SetCheck(0);
		m_radioB3.SetCheck(0);
		m_radioB4.SetCheck(0);
		m_radioB5.SetCheck(0);
		m_radioB6.SetCheck(1);
		D = 310;
		D1 = 180;
		d = 38;
		L = 200;
		B = 42;
		m = 75;
		DoubleToCString();

	}
}
afx_msg void CMy3semkursachView::OnEditChangeD() {
	m_editD.GetWindowText(strD);
	//AfxMessageBox(_T("Текст изменен: ") + strText);
}
afx_msg void CMy3semkursachView::OnEditChangeD1() {
	m_editD1.GetWindowText(strD1);
}
afx_msg void CMy3semkursachView::OnEditChanged() {
	m_editd.GetWindowText(strd);
}
afx_msg void CMy3semkursachView::OnEditChangeL() {
	m_editL.GetWindowText(strL);
}
afx_msg void CMy3semkursachView::OnEditChangeB() {
	m_editB.GetWindowText(strB);
}
afx_msg void CMy3semkursachView::OnEditChangem() {
	m_editm.GetWindowText(strm);
}
void CMy3semkursachView::DoubleToCString() {
	int boofer;
	boofer = static_cast<int>(D);
	strD.Format(_T("%i"), boofer);
	boofer = static_cast<int>(D1);
	strD1.Format(_T("%i"), boofer);
	boofer = static_cast<int>(d);
	strd.Format(_T("%i"), boofer);
	boofer = static_cast<int>(L);
	strL.Format(_T("%i"), boofer);
	boofer = static_cast<int>(B);
	strB.Format(_T("%i"), boofer);
	boofer = static_cast<int>(m);
	strm.Format(_T("%i"), boofer);


	m_editD.SetWindowText(strD);
	m_editD1.SetWindowText(strD1);
	m_editd.SetWindowText(strd);
	m_editL.SetWindowText(strL);
	m_editB.SetWindowText(strB);
	m_editm.SetWindowText(strm);

}
void CMy3semkursachView::StartKompas() {

	D = _wtof(strD);
	D1 = _wtof(strD1);
	d = _wtof(strd);
	L = _wtof(strL);
	B = _wtof(strB);
	m = _tstof(strm);



	CComPtr<IUnknown> pKompasAppUnk = nullptr;
	if (!pKompasApp5)
	{
		// Получаем CLSID для Компас
		CLSID InvAppClsid;
		HRESULT hRes = CLSIDFromProgID(L"Kompas.Application.5", &InvAppClsid);
		if (FAILED(hRes)) {
			pKompasApp5 = nullptr;
			return;
		}

		// Проверяем есть ли запущенный экземпляр Компас
		//если есть получаем IUnknown
		hRes = ::GetActiveObject(InvAppClsid, NULL, &pKompasAppUnk);
		if (FAILED(hRes)) {
			// Приходится запускать Компас самим так как работающего нет
			// Также получаем IUnknown для только что запущенного приложения Компас
			TRACE(L"Could not get hold of an active Inventor, will start a new session\n");
			hRes = CoCreateInstance(InvAppClsid, NULL, CLSCTX_LOCAL_SERVER, __uuidof(IUnknown), (void**)&pKompasAppUnk);
			if (FAILED(hRes)) {
				pKompasApp5 = nullptr;
				return;
			}
		}

		// Получаем интерфейс приложения Компас
		hRes = pKompasAppUnk->QueryInterface(__uuidof(KompasObject), (void**)&pKompasApp5);
		if (FAILED(hRes)) {
			return;
		}
	}
	pKompasApp5->Visible = true;

#ifdef cionid
#ifdef OPA 
	pDoc = pKompasApp5->Document3D();
	pDoc->Create(false, true);
	pPart = pDoc->GetPart(pTop_Part);
	ksEntityPtr pSketch = pPart->NewEntity(o3d_sketch);
	ksSketchDefinitionPtr pSketchDef = pSketch->GetDefinition();



	ksDocument2DPtr p2DDoc = pSketchDef->BeginEdit();
	pSketchDef->EndEdit();
	ksEntityPtr pSketch1 = pPart->NewEntity(o3d_sketch);
	pSketchDef = pSketch1->GetDefinition();//получаем параметры эскиза
	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOY));//плоскость созданную для отверстия пишем просто название смещ плоскости
	pSketch1->Create();
	p2DDoc = pSketchDef->BeginEdit();
	p2DDoc->ksLineSeg(0.875 * D1 / 2, 0, 0.875 * D1 / 2 + 0.625 * D1 / 2, 0, 1);
	p2DDoc->ksLineSeg(0.875 * D1 / 2 + 0.625 * D1 / 2, 0, 0.875 * D1 / 2 + 0.625 * D1 / 2, B / 4, 1);
	p2DDoc->ksLineSeg(0.875 * D1 / 2 + 0.625 * D1 / 2, B / 4, D1 / 2 + D1 / 14, B / 4, 1);//3
	p2DDoc->ksLineSeg(D1 / 2 + D1 / 14, B / 4, D1 / 2 + D1 / 14, B / 4 * 2, 1);
	p2DDoc->ksLineSeg(D1 / 2 + D1 / 14, B / 4 * 2, D1 / 2 - D1 / 14, B / 4 * 2, 1);
	p2DDoc->ksLineSeg(D1 / 2 - D1 / 14, B / 4 * 2, D1 / 2 - D1 / 14, B / 4 * 2 + B / 8, 1);
	p2DDoc->ksLineSeg(D1 / 2 - D1 / 14, B / 4 * 2 + B / 8, D1 / 2 - D1 / 14 - D1 / 28, B / 4 * 2 + B / 8, 1);
	p2DDoc->ksLineSeg(D1 / 2 - D1 / 14 - D1 / 28, B / 4 * 2 + B / 8, D1 / 2 - D1 / 14 - D1 / 28, B / 4 * 2 + B / 8 + B / 4, 1);
	p2DDoc->ksLineSeg(D1 / 2 - D1 / 14 - D1 / 28, B / 4 * 2 + B / 8 + B / 4, D1 / 2 - D1 / 14 - D1 / 11, B / 4 * 2 + B / 8 + B / 4, 1);//9
	p2DDoc->ksLineSeg(D1 / 2 - D1 / 14 - D1 / 11, B / 4 * 2 + B / 8 + B / 4, D1 / 2 - D1 / 14 - D1 / 11, L / 2 - B / 4, 1);
	p2DDoc->ksLineSeg(D1 / 2 - D1 / 14 - D1 / 11, L / 2 - B / 4, d, L / 2 - B / 4, 1);
	p2DDoc->ksLineSeg(d, L / 2 - B / 4, d, L / 2 - B / 4 - m + 2, 1);//пропорции гг
	p2DDoc->ksLineSeg(d, L / 2 - B / 4 - m + 2, d + 0.3 * D1 / 2, L / 2 - B / 4 - m + 2, 1);
	p2DDoc->ksLineSeg(d + 0.3 * D1 / 2, L / 2 - B / 4 - m + 2, 0.875 * D1 / 2, 0, 1);
	p2DDoc->ksLineSeg(0, 0, 0, 100, 3);
	pSketchDef->EndEdit();

	ksEntityPtr telo = pPart->NewEntity(o3d_baseRotated);
	ksBaseRotatedDefinitionPtr ptelo = telo->GetDefinition();
	ptelo->SetSideParam(TRUE, 360);
	ptelo->directionType* (dtNormal);
	ptelo->SetSketch(pSketch1);
	telo->Create();



	ksEntityCollectionPtr fledges2 = pPart->EntityCollection(o3d_edge);//ребра


	ksEntityPtr pChamfer = pPart->NewEntity(o3d_chamfer);
	ksChamferDefinitionPtr pChamferDef = pChamfer->GetDefinition();
	ksEntityCollectionPtr flc = pChamferDef->array();
	pChamferDef->SetChamferParam(true, B / 8, B / 8);
	flc = pChamferDef->array();
	flc->Clear();

	ksEntityPtr pTHread = pPart->NewEntity(o3d_thread);
	ksThreadDefinitionPtr pTHreadDef = pTHread->GetDefinition();
	pTHreadDef->allLength = true;
	pTHreadDef->autoDefinDr = true;
	pTHreadDef->faceValue = true;
	pTHreadDef->p = 2;
	for (int i = 0; i < fledges2->GetCount(); i++)
	{
		ksEntityPtr ed2 = fledges2->GetByIndex(i);//ложим индексы ребер в ed
		ksEdgeDefinitionPtr def2 = ed2->GetDefinition();
		ksVertexDefinitionPtr p1 = def2->GetVertex(true);//тоесть тут берем вершину
		ksVertexDefinitionPtr p2 = def2->GetVertex(false);

		if (!p1 || !p2)
			continue;

		double x1, y1, z1, x2, y2, z2;
		p1->GetPoint(&x1, &y1, &z1);
		p2->GetPoint(&x2, &y2, &z2);

		if (y1 == y2 && y2 == 0 && x2 == 0.875 * D1 / 2 + 0.625 * D1 / 2)
		{
			flc->Add(ed2);//скругление сверху на само
			//ed2->Putname("shtir");
			ed2->Update();
		}
		if (y1 == y2 && y2 == L / 2 - B / 4 && x2 == d)
		{
			flc->Add(ed2);//скругление сверху на само
			//ed2->Putname("ffdg");
			ed2->Update();
			pTHreadDef->SetBaseObject(ed2);
		}
		if (y1 == y2 && y2 == L / 2 - B / 4)
		{
			flc->Add(ed2);//скругление сверху на само
			//ed2->Putname("ffdg");
		}

	}
	pTHread->Create();
	pChamfer->Create();


	ksDocument2DPtr p3DDoc = pSketchDef->BeginEdit();
	pSketchDef->EndEdit();
	ksEntityPtr pSketch2 = pPart->NewEntity(o3d_sketch);
	pSketchDef = pSketch2->GetDefinition();//получаем параметры эскиза
	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOZ));//плоскость созданную для отверстия пишем просто название смещ плоскости
	pSketch2->Create();
	p3DDoc = pSketchDef->BeginEdit();
	p3DDoc->ksCircle(0, D1 / 2, D1 / 25, 1);
	pSketchDef->EndEdit();


	ksEntityPtr otv = pPart->NewEntity(o3d_cutExtrusion);
	ksCutExtrusionDefinitionPtr potv = otv->GetDefinition();
	potv->directionType = dtReverse;
	potv->SetSketch(pSketch2);
	potv->SetSideParam(true, etThroughAll, 100, 0, false);//A это глубина выреза
	potv->SetSideParam(false, etThroughAll, 0, 0, false);//A это глубина выреза
	otv->Create();

	ksEntityPtr circcopy = pPart->NewEntity(o3d_circularCopy);
	ksCircularCopyDefinitionPtr circcopydef = circcopy->GetDefinition();
	circcopydef->SetAxis(pPart->GetDefaultEntity(o3d_axisOY));
	circcopydef->SetCopyParamAlongDir(8, 360, true, false);
	ksEntityCollectionPtr ColEn = circcopydef->GetOperationArray();
	ColEn->Add(otv);
	circcopy->Create();

	bool Flag = 0;
	//для сборки//
	ksEntityCollectionPtr fledges3 = pPart->EntityCollection(o3d_face);//ребра
	for (int i = 0; i < fledges3->GetCount(); i++)
	{

		ksEntityPtr face = fledges3->GetByIndex(i);
		ksFaceDefinitionPtr def = face->GetDefinition();

		if (def->IsCylinder())
		{
			double h, r;
			def->GetCylinderParam(&h, &r);
			if (r == d)
			{
				face->Putname("inner diameter");
				face->Update();
			}
			if (r == D1 / 25 && Flag == 0)
			{
				face->Putname("bolthole");
				face->Update();
				Flag++;
			}
		}
		ksEdgeCollectionPtr col = def->EdgeCollection();//пробегаемся по ребрам
		for (int k = 0; k < col->GetCount() - 1; k++)
		{
			ksEdgeDefinitionPtr d = col->GetByIndex(k);
			ksEdgeDefinitionPtr d1 = col->GetByIndex(k + 1);
			if (d->IsCircle())
			{
				ksVertexDefinitionPtr p1 = d->GetVertex(true);
				ksVertexDefinitionPtr p2 = d1->GetVertex(true);
				double x1, y1, z1;
				double x2, y2, z2;
				p1->GetPoint(&x1, &y1, &z1);
				p1->GetPoint(&x2, &y2, &z2);
				if (y1 == B / 4 && y2 == B / 4)
				{
					face->Putname("dno");
					face->Update();
					break;
				}
			}
		}
	}
	pDoc->SaveAs(L"C:\\detali\\Part1.m3d");

#endif
#ifdef detal2

	pDoc = pKompasApp5->Document3D();
	pDoc->Create(false, true);
	pPart = pDoc->GetPart(pTop_Part);

	ksEntityPtr pSketch3 = pPart->NewEntity(o3d_sketch);
	ksSketchDefinitionPtr pSketchDef3 = pSketch3->GetDefinition();
	ksDocument2DPtr p2DDoc3 = pSketchDef3->BeginEdit();
	pSketchDef3->EndEdit();
	pSketchDef3 = pSketch3->GetDefinition();//получаем параметры эскиза
	pSketchDef3->SetPlane(pPart->GetDefaultEntity(o3d_planeXOY));//плоскость созданную для отверстия пишем просто название смещ плоскости
	pSketch3->Create();
	p2DDoc3 = pSketchDef3->BeginEdit();
	p2DDoc3->ksLineSeg(0.875 * D1 / 2 + 0.625 * D1 / 2, 0, D1 / 2 + D1 / 14, 0, 1);
	p2DDoc3->ksLineSeg(D1 / 2 + D1 / 14, 0, D1 / 2 + D1 / 14, B / 2, 1);
	p2DDoc3->ksLineSeg(D1 / 2 + D1 / 14, B / 2, ((0.875 * D1 / 2 + 0.625 * D1 / 2) + (D1 / 2 + D1 / 14, 0, D1 / 2 + D1 / 14)) / 2, B / 2, 1);
	p2DDoc3->ksLineSeg(((0.875 * D1 / 2 + 0.625 * D1 / 2) + (D1 / 2 + D1 / 14, 0, D1 / 2 + D1 / 14)) / 2, B / 2, ((0.875 * D1 / 2 + 0.625 * D1 / 2) + (D1 / 2 + D1 / 14, 0, D1 / 2 + D1 / 14)) / 2, B / 2 - B / 16, 1);
	p2DDoc3->ksLineSeg(((0.875 * D1 / 2 + 0.625 * D1 / 2) + (D1 / 2 + D1 / 14, 0, D1 / 2 + D1 / 14)) / 2, B / 2 - B / 16, 0.875 * D1 / 2 + 0.625 * D1 / 2, B / 2 - B / 16, 1);


	p2DDoc3->ksLineSeg(0.875 * D1 / 2 + 0.625 * D1 / 2, -B, D1 / 2 + D1 / 14, -B, 1);
	p2DDoc3->ksLineSeg(D1 / 2 + D1 / 14, -B, D1 / 2 + D1 / 14, -B / 2 - B, 1);
	p2DDoc3->ksLineSeg(D1 / 2 + D1 / 14, -B / 2 - B, ((0.875 * D1 / 2 + 0.625 * D1 / 2) + (D1 / 2 + D1 / 14, 0, D1 / 2 + D1 / 14)) / 2, -B / 2 - B, 1);
	p2DDoc3->ksLineSeg(((0.875 * D1 / 2 + 0.625 * D1 / 2) + (D1 / 2 + D1 / 14, 0, D1 / 2 + D1 / 14)) / 2, -B / 2 - B, ((0.875 * D1 / 2 + 0.625 * D1 / 2) + (D1 / 2 + D1 / 14, 0, D1 / 2 + D1 / 14)) / 2, -B / 2 + B / 16 - B, 1);
	p2DDoc3->ksLineSeg(((0.875 * D1 / 2 + 0.625 * D1 / 2) + (D1 / 2 + D1 / 14, 0, D1 / 2 + D1 / 14)) / 2, -B / 2 + B / 16 - B, 0.875 * D1 / 2 + 0.625 * D1 / 2, -B / 2 + B / 16 - B, 1);
	p2DDoc3->ksArcBy3Points(0.875 * D1 / 2 + 0.625 * D1 / 2, B / 2 - B / 16, (0.875 * D1 / 2 + 0.625 * D1 / 2) * 1.1, (-B / 2 + B / 16 - B) / 2, 0.875 * D1 / 2 + 0.625 * D1 / 2, -B / 2 + B / 16 - B, 1);



	p2DDoc3->ksArcBy3Points(0.875 * D1 / 2 + 0.625 * D1 / 2, 0, (0.875 * D1 / 2 + 0.625 * D1 / 2) * 1.05, -B / 2, 0.875 * D1 / 2 + 0.625 * D1 / 2, -B, 1);
	p2DDoc3->ksLineSeg(0, -100, 0, 100, 3);
	pSketchDef3->EndEdit();


	ksEntityPtr telo3 = pPart->NewEntity(o3d_baseRotated);
	ksBaseRotatedDefinitionPtr ptelo3 = telo3->GetDefinition();
	ptelo3->SetSideParam(TRUE, 360);
	ptelo3->directionType* (dtNormal);
	ptelo3->SetSketch(pSketch3);
	telo3->Create();
	//сборка

	BOOL FLAGKOL = 0;
	ksEntityCollectionPtr fledges5 = pPart->EntityCollection(o3d_face);//ребра
	for (int i = 0; i < fledges5->GetCount(); i++)
	{

		ksEntityPtr face5 = fledges5->GetByIndex(i);
		ksFaceDefinitionPtr def5 = face5->GetDefinition();
		if (def5->IsCylinder()); {
			double h, r;
			def5->GetCylinderParam(&h, &r);
			double x = h;
			if (h == B / 2 - (B / 2 - B / 16) && FLAGKOL == 0)
			{
				face5->Putname("soosnost");
				face5->Update();
				FLAGKOL++;
			}

		}
		ksEdgeCollectionPtr col5 = def5->EdgeCollection();//пробегаемся по ребрам
		for (int k = 0; k < col5->GetCount() - 1; k++)
		{
			ksEdgeDefinitionPtr d5 = col5->GetByIndex(k);
			ksEdgeDefinitionPtr d6 = col5->GetByIndex(k + 1);
			if (d5->IsCircle())
			{
				ksVertexDefinitionPtr p1 = d5->GetVertex(true);
				ksVertexDefinitionPtr p2 = d6->GetVertex(true);
				double x1, y1, z1;
				double x2, y2, z2;
				p1->GetPoint(&x1, &y1, &z1);
				p2->GetPoint(&x2, &y2, &z2);
				double z = 0.875 * D1 / 2 + 0.625 * D1 / 2;
				double xz = -B;
				if (x1 == 0.875 * D1 / 2 + 0.625 * D1 / 2 && x2 == D1 / 2 + D1 / 14 &&(y1==-B||y2==-B) )
				{
					face5->Putname("bokgran");
					face5->Update();
					break;
				}
				double xxx = D1 / 2 + D1 / 14;
				double xxx2 = ((0.875 * D1 / 2 + 0.625 * D1 / 2) + (D1 / 2 + D1 / 14, 0, D1 / 2 + D1 / 14)) / 2;
				double yyy = -B / 2 - B;
				double yyy2 = B / 2;
				if (x2==xxx && x1== xxx2&&y1==yyy )
				{
					face5->Putname("withkolzo1");
					face5->Update();
					break;
				}
				if (x2 == xxx && x1 == xxx2 && y1 == yyy2)
				{
					face5->Putname("withkolzo2");
					face5->Update();
					break;
				}
			}
		}
	}
	pDoc->SaveAs(L"C:\\detali\\Part2.m3d");
#endif

#ifdef kolzodef
	pDoc = pKompasApp5->Document3D();
	pDoc->Create(false, true);
	pPart = pDoc->GetPart(pTop_Part);

	ksEntityPtr pSketch4 = pPart->NewEntity(o3d_sketch);
	ksSketchDefinitionPtr pSketchDef4 = pSketch4->GetDefinition();
	ksDocument2DPtr p2DDoc4 = pSketchDef4->BeginEdit();
	pSketchDef4->EndEdit();
	pSketchDef4 = pSketch4->GetDefinition();//получаем параметры эскиза
	pSketchDef4->SetPlane(pPart->GetDefaultEntity(o3d_planeXOY));//плоскость созданную для отверстия пишем просто название смещ плоскости
	pSketch4->Create();
	p2DDoc4 = pSketchDef4->BeginEdit();
	int l = (D1 / 2 - D1 / 14 - D1 / 28 - D1 / 2 - D1 / 14 - D1 / 28, B / 4 * 2 + B / 8 + B / 4) / 2;
	p2DDoc4->ksLineSeg(0, D1 / 2 - D1 / 14 - D1 / 28, l / 2, D1 / 2 - D1 / 14 - D1 / 28, 1);
	p2DDoc4->ksLineSeg(l / 2, D1 / 2 - D1 / 14 - D1 / 28, l / 2, D1 / 2 - D1 / 14 - D1 / 28 + D1 / 4 + l / 4+l/2, 1);
	p2DDoc4->ksLineSeg(l / 2, D1 / 2 - D1 / 14 - D1 / 28 + D1 / 4 + l / 4+l/2, -l / 2, D1 / 2 - D1 / 14 - D1 / 28 + D1 / 4 + l / 4+l/2, 1);
	p2DDoc4->ksLineSeg(-l / 2, D1 / 2 - D1 / 14 - D1 / 28 + D1 / 4 + l / 4+l/2, -l / 2, D1 / 2 - D1 / 14 - D1 / 28 + D1 / 2 - D1 / 4 - l / 8, 1);
	p2DDoc4->ksLineSeg(0, D1 / 2 - D1 / 14 - D1 / 28, 0, D1 / 2 - D1 / 14 - D1 / 28 + D1 / 2 - D1 / 4 - l / 8, 1);
	p2DDoc4->ksLineSeg(0, D1 / 2 - D1 / 14 - D1 / 28 + D1 / 2 - D1 / 4 - l / 8, -l / 2, D1 / 2 - D1 / 14 - D1 / 28 + D1 / 2 - D1 / 4 - l / 8, 1);


	p2DDoc4->ksLineSeg(-100, 0, 100, 0, 3);
	//p2DDoc4->ksLineSeg(D1 / 2 - D1 / 14 - D1 / 28, 0, (0.875 * D1 / 2 + 0.625 * D1 / 2) + (D1 / 2 + D1 / 14), 0, 1);
	pSketchDef4->EndEdit();

	ksEntityPtr telo4 = pPart->NewEntity(o3d_baseRotated);
	ksBaseRotatedDefinitionPtr ptelo4 = telo4->GetDefinition();
	ptelo4->SetSideParam(TRUE, 360);
	ptelo4->directionType* (dtNormal);
	ptelo4->SetSketch(pSketch4);
	telo4->Create();

	ksEntityPtr pSketch5 = pPart->NewEntity(o3d_sketch);
	ksSketchDefinitionPtr pSketchDef5 = pSketch5->GetDefinition();
	ksDocument2DPtr p2DDoc5 = pSketchDef5->BeginEdit();
	pSketchDef5->EndEdit();
	pSketchDef5 = pSketch5->GetDefinition();//получаем параметры эскиза
	pSketchDef5->SetPlane(pPart->GetDefaultEntity(o3d_planeYOZ));//плоскость созданную для отверстия пишем просто название смещ плоскости
	pSketch5->Create();
	p2DDoc5 = pSketchDef5->BeginEdit();
	p2DDoc5->ksCircle(0, D1 / 2, D1 / 25, 1);
	pSketchDef5->EndEdit();

	ksEntityPtr otv5 = pPart->NewEntity(o3d_cutExtrusion);
	ksCutExtrusionDefinitionPtr potv5 = otv5->GetDefinition();
	potv5->directionType = dtNormal;
	potv5->SetSketch(pSketch5);
	potv5->SetSideParam(true, etThroughAll, 100, 0, false);//A это глубина выреза
	potv5->SetSideParam(false, etThroughAll, 100, 0, false);//A это глубина выреза
	otv5->Create();

	ksEntityPtr circcopy5 = pPart->NewEntity(o3d_circularCopy);
	ksCircularCopyDefinitionPtr circcopydef5 = circcopy5->GetDefinition();
	circcopydef5->SetAxis(pPart->GetDefaultEntity(o3d_axisOX));
	circcopydef5->SetCopyParamAlongDir(8, 360, true, false);
	ksEntityCollectionPtr ColEn5 = circcopydef5->GetOperationArray();
	ColEn5->Add(otv5);
	circcopy5->Create();

	bool FLAGN = 0;
	int flagkol = 0;
	ksEntityPtr pChamfer3 = pPart->NewEntity(o3d_chamfer);
	ksChamferDefinitionPtr pChamferDef3 = pChamfer3->GetDefinition();
	ksEntityCollectionPtr flc3 = pChamferDef3->array();
	pChamferDef3->SetChamferParam(true, l / 4, l / 4);
	flc3 = pChamferDef3->array();
	flc3->Clear();
	ksEntityCollectionPtr fledges6 = pPart->EntityCollection(o3d_face);//ребра
	for (int i = 0; i < fledges6->GetCount(); i++)
	{

		ksEntityPtr face5 = fledges6->GetByIndex(i);
		ksFaceDefinitionPtr def5 = face5->GetDefinition();
		if (def5->IsCylinder()); {
			double h, r;
			def5->GetCylinderParam(&h, &r);
			double x = h;
			if (h == l / 2 && r == D1 / 2 - D1 / 14 - D1 / 28 && flagkol == 0)
			{
				face5->Putname("soosnostkol");
				face5->Update();
				flagkol++;
			}
			if (r == D1 / 25 && FLAGN == 0)
			{
				face5->Putname("otver");
				face5->Update();
				FLAGN++;
			}

		}
		
		ksEdgeCollectionPtr col5 = def5->EdgeCollection();//пробегаемся по ребрам
		for (int k = 0; k < col5->GetCount() - 1; k++)
		{
			ksEdgeDefinitionPtr d5 = col5->GetByIndex(k);
			ksEdgeDefinitionPtr d6 = col5->GetByIndex(k + 1);
			if (d5->IsCircle())
			{
				ksVertexDefinitionPtr p1 = d5->GetVertex(true);
				ksVertexDefinitionPtr p2 = d6->GetVertex(true);
				double x1, y1, z1;
				double x2, y2, z2;
				p1->GetPoint(&x1, &y1, &z1);
				p2->GetPoint(&x2, &y2, &z2);
				double z =   D1 / 2 - D1 / 14 - D1 / 28 + D1 / 2 - D1 / 4 - l / 8;
				double z22 = D1 / 2 - D1 / 14 - D1 / 28;
				double z32 = D1 / 2 - D1 / 14 - D1 / 28 + D1 / 4 + l / 4 + l / 2;
				double z42 = D1 / 2 - D1 / 14 - D1 / 28;
				if (y1 == D1 / 2 - D1 / 14 - D1 / 28 + D1 / 2 - D1 / 4 - l / 8&&z2!=0)
				{
					face5->Putname("bokgrankol");
					face5->Update();
					//break;
				}
				if (y1 == D1 / 2 - D1 / 14 - D1 / 28 + D1 / 4 + l / 4 + l / 2&&z2!=0)
				{
					flc3->Add(d5);
				}
			}
		}
	}

	pChamfer3->Create();
	pDoc->SaveAs(L"C:\\detali\\Part3.m3d");
#endif
#endif
#ifdef OPA
	pDoc = pKompasApp5->Document3D();
	pDoc->Create(false, false);
	//pDocsb = pKompasApp5->ActiveDocument3D();
	pPart = pDoc->GetPart(pTop_Part);
	ksPartPtr flanez1, flanez2, kolzo, kolzo1, kolzo2;

	pDoc->SetPartFromFile(L"C:\\detali\\Part1.m3d", pPart, VARIANT_FALSE);
	pDoc->SetPartFromFile(L"C:\\detali\\Part1.m3d", pPart, VARIANT_FALSE);
	pDoc->SetPartFromFile(L"C:\\detali\\Part2.m3d", pPart, VARIANT_FALSE);
	pDoc->SetPartFromFile(L"C:\\detali\\Part3.m3d", pPart, VARIANT_FALSE);
	pDoc->SetPartFromFile(L"C:\\detali\\Part3.m3d", pPart, VARIANT_FALSE);
	ksPartCollectionPtr partCollect = pDoc->PartCollection(VARIANT_TRUE);


	flanez1 = pDoc->GetPart(0);
	flanez2 = pDoc->GetPart(1);
	kolzo = pDoc->GetPart(2);
	kolzo1 = pDoc->GetPart(3);
	kolzo2 = pDoc->GetPart(4);
	ksEntityCollectionPtr PartCol;


	pPart = partCollect->GetByIndex(0);//фланец 1
	PartCol = pPart->EntityCollection(o3d_unknown);
	ksEntityPtr inner_diameter = PartCol->GetByName("inner diameter", true, true);
	ksEntityPtr bolthole = PartCol->GetByName("bolthole", true, true);
	ksEntityPtr dno = PartCol->GetByName("dno", true, true);


	pPart = partCollect->GetByIndex(1);//фланец 2
	PartCol = pPart->EntityCollection(o3d_unknown);
	ksEntityPtr inner_diameter1 = PartCol->GetByName("inner diameter", true, true);
	ksEntityPtr bolthole1 = PartCol->GetByName("bolthole", true, true);
	ksEntityPtr dno1 = PartCol->GetByName("dno", true, true);


	pPart = partCollect->GetByIndex(2);//резинка
	PartCol = pPart->EntityCollection(o3d_unknown);
	ksEntityPtr kolsoos = PartCol->GetByName("soosnost", true, true);
	ksEntityPtr kolbokgran = PartCol->GetByName("bokgran", true, true);
	ksEntityPtr withkolzo1 = PartCol->GetByName("withkolzo1", true, true);
	ksEntityPtr withkolzo2 = PartCol->GetByName("withkolzo2", true, true);
	//фланец и фланец

	pPart = partCollect->GetByIndex(3);//фланец 2
	PartCol = pPart->EntityCollection(o3d_unknown);
	ksEntityPtr kolcosos = PartCol->GetByName("soosnostkol", true, true);
	ksEntityPtr kolcootv = PartCol->GetByName("otver", true, true);
	ksEntityPtr kolcobok = PartCol->GetByName("bokgrankol", true, true);


	pPart = partCollect->GetByIndex(4);//фланец 2
	PartCol = pPart->EntityCollection(o3d_unknown);
	ksEntityPtr kolcosos1 = PartCol->GetByName("soosnostkol", true, true);
	ksEntityPtr kolcootv1 = PartCol->GetByName("otver", true, true);
	ksEntityPtr kolcobok1 = PartCol->GetByName("bokgrankol", true, true);

	pDoc->AddMateConstraint(mc_Concentric, inner_diameter, inner_diameter1, -1, 0, 0);
	pDoc->AddMateConstraint(mc_Concentric, bolthole, bolthole1, 0, 0, 0);
	pDoc->AddMateConstraint(mc_Distance, dno1, dno, 0, 0, -B);
	pDoc->AddMateConstraint(mc_Concentric, inner_diameter, kolsoos, 0, 0, 0);
	pDoc->AddMateConstraint(mc_Distance, kolbokgran, dno, 0, 0, 0);

	pDoc->AddMateConstraint(mc_Concentric, kolcosos, kolsoos, 0, 0, 0);
	pDoc->AddMateConstraint(mc_Concentric, kolcosos1, kolsoos, 0, 0, 0);

	pDoc->AddMateConstraint(mc_Concentric, kolcootv, bolthole, 0, 0, 0);
	pDoc->AddMateConstraint(mc_Concentric, kolcootv1, bolthole1, 0, 0, 0);

	////резинка с кольцом

	pDoc->AddMateConstraint(mc_Distance, kolcobok, withkolzo1, -1, 2, 0);
	pDoc->AddMateConstraint(mc_Distance, kolcobok1, withkolzo2, 0, 2, 0);

	

	pDoc->RebuildDocument();
#endif
	//pKompasApp5.Detach();
// DEBUG

}