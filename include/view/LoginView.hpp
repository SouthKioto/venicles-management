#ifndef LOGIN_VIEW_HPP
#define LOGIN_VIEW_HPP
#include <wx/richtext/richtextctrl.h>
#include <wx/wx.h>

class Router;

class LoginView : public wxPanel {
private:
  wxTextCtrl *email;
  wxTextCtrl *password;
  Router *router;
  std::vector<std::string> errors;

public:
  wxButton *submit;

  LoginView(wxWindow *window, Router *router);
  virtual ~LoginView();

  void setErrors(std::vector<std::string> &errors);

  std::vector<std::string> getErrors() const;

  wxString getEmailValue() const { return email->GetValue(); }

  wxString getPasswordValue() const { return password->GetValue(); }
};

#endif // !LOGIN_VIEW_HPP
