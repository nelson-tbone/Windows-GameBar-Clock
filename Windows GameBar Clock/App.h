#pragma once
#include "App.xaml.g.h"

namespace winrt::Windows_GameBar_Clock::implementation
{
    struct App : AppT<App>
    {
        App();
        
        void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs const&);
        void OnSuspending(IInspectable const&, Windows::ApplicationModel::SuspendingEventArgs const&);
        void OnNavigationFailed(IInspectable const&, Windows::UI::Xaml::Navigation::NavigationFailedEventArgs const&);
        void OnActivated(Windows::ApplicationModel::Activation::IActivatedEventArgs const& args);
        void MainPageWindowClosedHandler(IInspectable const&, IInspectable const&);

    private:
        Microsoft::Gaming::XboxGameBar::XboxGameBarWidget m_MainPage{ nullptr };
        event_token m_MainPageWindowClosedHandlerToken{};

        //todo: tem alguma coisa estranha, que esse branch de settings não deploya.
        Windows::Storage::ApplicationDataContainer localSettings = Windows::Storage::ApplicationData::Current().LocalSettings();
        inline static const auto SettingsFonteCor = L"Yellow";

    };
}
