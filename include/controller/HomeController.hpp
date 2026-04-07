#ifndef HOMECONTROLLER_HPP
#define HOMECONTROLLER_HPP

#include "../view/HomeView.hpp"
#include <wx/event.h>

class Router;
class SQLiteDatabase;

class HomeController {
private:
  HomeView *_view;
  SQLiteDatabase *_db;

public:
  Router *router;
  HomeController(HomeView *view, SQLiteDatabase *db, Router *router);
  ~HomeController();
  void OnChangePageClicked(wxCommandEvent &event);
};

#endif // !HOMECONTROLLER_HPP
