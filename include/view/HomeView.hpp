#ifndef HOMEVIEW_HPP
#define HOMEVIEW_HPP

#include <wx/wx.h>

class Router;

class HomeView : public wxPanel {
private:
  Router *router;

public:
  wxButton *logoutBtn;
  wxButton *userPageBtn;

  HomeView(wxWindow *window, Router *router);

  void change();
};

#endif // !HOMEVIEW_HPP
