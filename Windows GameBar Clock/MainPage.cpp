#include "pch.h"
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
        myButton().Content(box_value(L"Clicked"));
        winrt::hstring Title = L"Hello";
        winrt::hstring Content = L"Some cool content!";
        winrt::Windows::UI::Popups::MessageDialog dialog(Content, Title);
        dialog.ShowAsync();
    }
   
}
