#ifndef USER_PAGE_CONTROLLER_HPP
#define USER_PAGE_CONTROLLER_HPP

#include "../include/model/UserPageModel.hpp"
#include "../include/view/UserPageView.hpp"

class UserPageController {
private:
  UserPageView *_view;
  UserPageModel *_model;

  Router *router;
  Logger *logger;

public:
  UserPageController(UserPageView *view, UserPageModel *model, Router *router);
};

#endif // !USER_PAGE_CONTROLLER_HPP
