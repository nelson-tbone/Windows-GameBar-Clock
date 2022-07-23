#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"
#include "winrt/Windows.UI.Popups.h" //para a msgbox;

using namespace winrt;
using namespace std;
using namespace Windows::UI::Xaml;
using namespace Windows::Foundation;
using namespace std::chrono_literals;

namespace winrt::Windows_GameBar_Clock::implementation
{

    MainPage::MainPage()
    {
        InitializeComponent();
        StartTimerAndRegisterHandler();
    }

    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainPage::StartTimerAndRegisterHandler()
    {
        auto timer = Windows::UI::Xaml::DispatcherTimer();
        timer.Interval(std::chrono::milliseconds{ 500 });
        timer.Start();
        auto registrationtoken = timer.Tick({ this, &MainPage::OnTick });
    }

    void MainPage::OnTick(IInspectable const& sender, IInspectable const& args)
    {
        SYSTEMTIME HoraLocal;
        GetLocalTime(&HoraLocal);
        hstring strHora = to_hstring(HoraLocal.wHour);
        hstring strMinuto = to_hstring(HoraLocal.wMinute);
        hstring strSegundo = to_hstring(HoraLocal.wSecond);
        hstring strHoraLocal = strHora + L':' + strMinuto + +L':' + strSegundo;

        /* -- aqui tem as tentativas de formatação;
        SYSTEMTIME HoraLocal;
        GetLocalTime(&HoraLocal);
        hstring strHora = to_hstring(HoraLocal.wHour);
        hstring strMinuto = to_hstring(HoraLocal.wMinute);
        hstring strHoraLocal = strHora + L':' + strMinuto;
        //char teste[100];
        //sprintf_s(teste,"The local time is: %02d:%02d\n", HoraLocal.wHour, HoraLocal.wMinute);
        //strHoraLocal = winrt::to_hstring(teste);
         //txtTextoBoxo().Text(strHoraLocal);
        //hstring testestring = to_string(teste);
        txtTextoBoxo().Text(strHoraLocal);
        */

        lblRelogio().Text(strHoraLocal);
    }
}