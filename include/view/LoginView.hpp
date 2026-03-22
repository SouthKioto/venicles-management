#ifndef LOGIN_VIEW_HPP
#define LOGIN_VIEW_HPP
#include <wx/richtext/richtextctrl.h>
#include <wx/wx.h>

class LoginView : public wxFrame {
private:
  wxTextCtrl *name;
  wxTextCtrl *surname;

public:
  wxButton *submit;
  LoginView();
  virtual ~LoginView();

  wxString getNameValue() const { return name->GetValue(); }

  wxString getSurnameValue() const { return surname->GetValue(); }
};

#endif // !LOGIN_VIEW_HPP
