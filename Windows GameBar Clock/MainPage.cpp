﻿#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"
#include "winrt/Windows.UI.Popups.h"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Windows_GameBar_Clock::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
    }

    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        //extern hstring strHora = L"99:99 am"; --extern seria pra variável ser global mas não funcionou se declarada no app.cpp.
        
        //txtTexto().Text(L"Teste");

        hstring strParte1 = L"parte 1";
        hstring strParte2 = L" Parte 2";
        hstring strParte1Parte2 = strParte1 + L" - " + strParte2;
        txtTexto().Text(strParte1Parte2);


        SYSTEMTIME HoraLocal;
        GetLocalTime(&HoraLocal);
        
        hstring strHora = to_hstring(HoraLocal.wHour);
        hstring strMinuto = to_hstring(HoraLocal.wMinute);
        hstring strHoraLocal = strHora + L':' + strMinuto;


        char teste[100];
        sprintf_s(teste,"The local time is: %02d:%02d\n", HoraLocal.wHour, HoraLocal.wMinute);
        strHoraLocal = winrt::to_hstring(teste);
        
        //txtTextoBoxo().Text(strHoraLocal);
        //hstring testestring = to_string(teste);
        txtTextoBoxo().Text(strHoraLocal);


        myButton().Content(box_value(L"Clicked"));
        winrt::hstring Title = L"Título da mensagem";
        hstring Content = L"Texto da mensagem!";
        winrt::Windows::UI::Popups::MessageDialog dialog(Content, Title);
        dialog.ShowAsync();
        
    }
   
}
