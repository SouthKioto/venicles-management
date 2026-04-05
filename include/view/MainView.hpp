#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <wx/wx.h>
class Router;

class MainView : public wxFrame {
private:
  Router *router;

public:
  MainView();
};

#endif // !MAINVIEW_HPP
