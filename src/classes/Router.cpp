#include "../../include/classes/Router.hpp"
#include "../include/additionalScripts/Logger.hpp"

Logger logger;

Router::Router(wxWindow *container) : container(container) {}

Router::~Router() {

  // INFO: na razie nic
  // TODO: przy destrukcji usuwanie wszystkich dodanych widokow (?)
}

bool Router::findRoute(const std::string &name) {
  auto search_elem = routes.find(name);

  if (search_elem != routes.end()) {
    logger.log(LogLevel::Info, "Element " + name + " istnieje w routerze");
    return true;
  } else {
    logger.log(LogLevel::Info, "Element " + name + " nie istnieje w routerze");
    return false;
  }
}

void Router::add(const std::string &name, wxWindow *window) {

  if (!findRoute(name)) {
    routes.insert({name, window});
    logger.log(LogLevel::Info, "Pomyslnie dodano element route: " + name);
  } else {
    logger.log(LogLevel::Info, "Nie udalo sie dodac elementu route: " + name +
                                   ". Element juz istnieje.");
  }
}

void Router::remove(std::string name) {

  if (findRoute(name)) {
    routes.erase(name);

    logger.log(LogLevel::Info, "Pomyslnie usunieto route: " + name);
  } else {
    logger.log(LogLevel::Error, "Nie udalo sie usunac elementu route: " + name);
  }
}

void Router::navigate(std::string name) {
  if (!findRoute(name)) {
    logger.log(LogLevel::Error,
               "Element " + name + " nie istnieje w routerze.");
    return;
  }

  if (!current.empty()) {
    routes[current]->Hide();
  }

  if (routes[name] == nullptr) {
    logger.log(LogLevel::Error, "Element " + name + " jest `nullptr`.");
    return;
  }

  routes[name]->Show();

  container->Layout();
  current = name;
}

void Router::showAllRoutes() {
  int index = 1;
  for (const auto &route : routes) {
    logger.log(LogLevel::Debug,
               std::to_string(index) + ".router: " + route.first);
    index++;
  }
}
