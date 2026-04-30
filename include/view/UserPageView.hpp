#ifndef USER_PAGE_VIEW_HPP
#define USER_PAGE_VIEW_HPP

#include <wx/wx.h>

class UserPageView : public wxPanel {
private:
public:
  std::string userName;
  bool isAdmin;
  wxTextCtrl *info;
  wxButton *backButton;

  UserPageView(wxWindow *window);
};
#endif // !USER_PAGE_VIEW_HPP
