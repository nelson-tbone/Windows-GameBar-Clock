#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"
//#include "winrt/Windows.UI.Popups.h" //para a msgbox;

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
        hstring strAmPm;
        SYSTEMTIME HoraLocal;

        GetLocalTime(&HoraLocal);
        
        WORD wrdHora = HoraLocal.wHour;
        if (HoraLocal.wHour >= 12) {
            strAmPm = L"pm";
            if (HoraLocal.wHour > 12) {
                wrdHora -= 12;
            }
        }
        else {
            strAmPm = L"am";
            if (HoraLocal.wHour == 0) {
                wrdHora = 12;
            }
        }
        
        hstring strHora = to_hstring(wrdHora);
        if (strHora.size() <= 1) {
            strHora = '0' + strHora;
        }
        
        hstring strMinuto = to_hstring(HoraLocal.wMinute);
        if (strMinuto.size() <= 1) {
            strMinuto = '0' + strMinuto;
        }

        hstring strSegundo = to_hstring(HoraLocal.wSecond);
        if (strSegundo.size() <= 1) {
            strSegundo = '0' + strSegundo;
        }
        hstring strHoraLocal = strHora + L':' + strMinuto + L':' + strSegundo + strAmPm;

        lblRelogioNumeros().Text(strHoraLocal);
        lblRelogioOutLn1().Text(strHoraLocal);
        lblRelogioOutLn2().Text(strHoraLocal);
        lblRelogioOutLn3().Text(strHoraLocal);
        lblRelogioOutLn4().Text(strHoraLocal);

    }
}