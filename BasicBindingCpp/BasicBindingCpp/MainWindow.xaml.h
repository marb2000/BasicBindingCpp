#pragma once

#pragma push_macro("GetCurrentTime")
#undef GetCurrentTime

#include "MainWindow.g.h"

#pragma pop_macro("GetCurrentTime")

namespace winrt::BasicBindingCpp::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();
    public:
        int32_t MyValue();
        void MyValue(int32_t newValue);
        winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token);
    private:
        int32_t myValue;
        winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> propertyChanged;
    };
}

namespace winrt::BasicBindingCpp::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
