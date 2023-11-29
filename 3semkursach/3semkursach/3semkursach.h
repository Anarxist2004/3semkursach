
// 3semkursach.h: основной файл заголовка для приложения 3semkursach
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMy3semkursachApp:
// Сведения о реализации этого класса: 3semkursach.cpp
//

class CMy3semkursachApp : public CWinApp
{
public:
	CMy3semkursachApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy3semkursachApp theApp;
