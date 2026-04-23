#include "../include/controller/UserPageController.hpp"

UserPageController::UserPageController(UserPageView *view, UserPageModel *model,
                                       Router *router)
    : _view(view), _model(model), router(router) {}
