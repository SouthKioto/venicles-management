#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include "../include/additionalScripts/Logger.hpp"
#include <wx/wx.h>
class Router;

class MainView : public wxFrame {
private:
  Router *router;

public:
  Logger *logger;
  MainView(Logger *logger);
};

#endif // !MAINVIEW_HPP
