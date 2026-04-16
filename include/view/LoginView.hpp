#ifndef LOGIN_VIEW_HPP
#define LOGIN_VIEW_HPP
#include <wx/wx.h>

class Router;

class LoginView : public wxPanel {
private:
  wxTextCtrl *login;
  wxTextCtrl *pass;
  Router *router;

public:
  wxButton *submit;
  wxButton *registerButton;
  LoginView(wxWindow *window, Router *router);
  virtual ~LoginView();

  wxString getLoginValue() const { return login->GetValue(); }

  wxString getPassValue() const { return pass->GetValue(); }
};

#endif // !LOGIN_VIEW_HPP
