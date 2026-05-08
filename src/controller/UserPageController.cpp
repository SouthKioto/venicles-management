#include "../include/controller/UserPageController.hpp"
#include "../include/classes/Session.hpp"

UserPageController::UserPageController(UserPageView *view, UserPageModel *model,
                                       Router *router)
    : _view(view), _model(model), router(router) {

  _view->backButton->Bind(wxEVT_BUTTON, &UserPageController::OnBackButtonClick,
                          this);

  _view->isAdmin = Session::getInstance().getAdmin();
};

void UserPageController::OnBackButtonClick(wxCommandEvent &event) {
  this->router->navigate("home");
}
