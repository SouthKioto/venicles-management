#ifndef REGISTER_VIEW_HPP
#define REGISTER_VIEW_HPP

#include <wx/wx.h>

class Router;

class RegisterView : public wxPanel {
private:
  wxTextCtrl *name;
  wxTextCtrl *surname;
  wxTextCtrl *email;
  wxTextCtrl *password;
  wxTextCtrl *confirmPassword;
  Router *router;
  std::vector<std::string> errors;

public:
  wxButton *registerBtn;
  wxButton *backBtn;
  wxBoxSizer *errorRow;

  RegisterView(wxWindow *window, Router *router);
  virtual ~RegisterView();

  void setErrors(const std::vector<std::string> &errors);
  std::vector<std::string> getErrors() const;

  wxString getNameValue() const { return name->GetValue(); }
  wxString getSurnameValue() const { return surname->GetValue(); }
  wxString getEmailValue() const { return email->GetValue(); }
  wxString getPasswordValue() const { return password->GetValue(); }
  wxString getConfirmPasswordValue() const { return confirmPassword->GetValue(); }
};

#endif // !REGISTER_VIEW_HPP
