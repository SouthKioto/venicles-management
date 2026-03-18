#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP
#include <wx/wx.h>

class MainView : public wxFrame {
public:
  MainView();
  void setGreetingText(const std::string &text);
  wxButton *m_button;
  wxStaticText *m_text;
};

#endif
