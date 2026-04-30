#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include "../include/additionalScripts/Logger.hpp"
#include "../include/database/Database.hpp"
#include <wx/wx.h>
class Router;

class MainView : public wxFrame {
private:
  Router *router;

public:
  Logger *logger;
  Database *database;
  wxPanel *container;
  wxBoxSizer *containerSizer;

  MainView(Logger *logger, Database *database);

  void initViews();
};

#endif // !MAINVIEW_HPP
