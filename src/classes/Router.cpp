#include "../../include/classes/Router.hpp"
#include "../include/additionalScripts/Logger.hpp"

Logger logger;

Router::Router(wxWindow *container) : container(container) {}

Router::~Router() {

  // INFO: na razie nic
  // TODO: przy destrukcji usuwanie wszystkich dodanych widokow (?)
}

bool Router::findRoute(const std::string &name) {
  auto search_elem = Router::routes.find(name);

  if (search_elem != Router::routes.end()) {
    logger.log(LogLevel::Info, "Element " + name + " istnieje w routerze");
    return true;
  } else {
    logger.log(LogLevel::Info, "Element " + name + " nie istnieje w routerze");
    return false;
  }
}

void Router::add(const std::string &name, wxWindow *window) {

  if (!Router::findRoute(name)) {
    Router::routes.insert({name, window});
    logger.log(LogLevel::Info, "Pomyslnie dodano element route: " + name);
  } else {
    logger.log(LogLevel::Info, "Nie udalo sie dodac elementu route: " + name +
                                   ". Element juz istnieje.");
  }
}

void Router::remove(std::string name) {

  if (Router::findRoute(name)) {
    Router::routes.erase(name);

    logger.log(LogLevel::Info, "Pomyslnie usunieto route: " + name);
  } else {
    logger.log(LogLevel::Error, "Nie udalo sie usunac elementu route: " + name);
  }
}

void Router::navigate(std::string name) {
  if (!Router::findRoute(name)) {
    logger.log(LogLevel::Error,
               "Element " + name + " nie istnieje w routerze.");
    return;
  }

  if (!Router::current.empty()) {
    Router::routes[current]->Hide();
  }

  if (Router::routes[name] == nullptr) {
    logger.log(LogLevel::Error, "Element " + name + " jest `nullptr`.");
    return;
  }

  Router::routes[name]->Show();
  Router::container->Layout();
  Router::current = name;
}

void Router::showAllRoutes() {
  int index = 1;
  for (const auto &route : Router::routes) {
    logger.log(LogLevel::Debug,
               std::to_string(index) + ".router: " + route.first);
    index++;
  }
}
