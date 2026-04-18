#include "../include/model/UserPageModel.hpp"

UserPageModel::UserPageModel(User *user, Router *router, Database *database)
    : user(user), router(router), database(database) {}
