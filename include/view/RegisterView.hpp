#ifndef REGISTER_VIEW_HPP
#define REGISTER_VIEW_HPP

#include <wx/wx.h>

class Router;

class RegisterView : public wxPanel {
private:
  wxTextCtrl *name;
  wxTextCtrl *surname;
  wxTextCtrl *login;
  wxTextCtrl *password;
  Router *router;

public:
  wxButton *submit;
  wxButton *changePage;
  RegisterView(wxWindow *window, Router *router);
  virtual ~RegisterView();

  wxString getNameValue() const { return name->GetValue(); }
  wxString getSurnameValue() const { return surname->GetValue(); }
  wxString getLoginValue() const { return login->GetValue(); }
  wxString getPasswordValue() const { return password->GetValue(); }
};

#endif // !REGISTER_VIEW_HPP
