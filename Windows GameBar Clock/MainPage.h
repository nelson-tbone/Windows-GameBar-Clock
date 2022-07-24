#pragma once

#include "MainPage.g.h"

namespace winrt::Windows_GameBar_Clock::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void StartTimerAndRegisterHandler();
        void OnTick(IInspectable const& sender, IInspectable const& args);
    };
}

namespace winrt::Windows_GameBar_Clock::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
