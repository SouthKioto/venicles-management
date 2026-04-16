#ifndef LOGIN_VIEW_HPP
#define LOGIN_VIEW_HPP
#include <wx/richtext/richtextctrl.h>
#include <wx/wx.h>

class Router;

class LoginView : public wxPanel {
private:
  wxTextCtrl *name;
  wxTextCtrl *surname;
  Router *router;

public:
  wxButton *submit;
  wxButton *changePage;

  LoginView(wxWindow *window, Router *router);
  virtual ~LoginView();

  wxString getNameValue() const { return name->GetValue(); }

  wxString getSurnameValue() const { return surname->GetValue(); }
};

#endif // !LOGIN_VIEW_HPP
