#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;


namespace winrt::BasicBindingCpp::implementation
{
    MainWindow::MainWindow()
    {
        myValue = 1980;

        InitializeComponent();
        
        this->Title(L"Testing x:Bind in C++/WinRT");
    }

    void MainWindow::MyValue(int32_t newValue) {
        if (myValue != newValue) {
            myValue = newValue;
            propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"MyValue" });
        }
    }

    int32_t MainWindow::MyValue()
    {
        return myValue;
    }


    winrt::event_token MainWindow::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler) {
        return propertyChanged.add(handler);
    }

    void MainWindow::PropertyChanged(winrt::event_token const& token) {
        propertyChanged.remove(token);
    }
}
