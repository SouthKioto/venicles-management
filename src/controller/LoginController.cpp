#include "../include/controller/LoginController.hpp"
#include "../include/classes/Router.hpp"
#include "../include/classes/User.hpp"
#include "../include/view/MainView.hpp"
#include <iostream>

LoginController::LoginController(LoginModel *model, LoginView *view,
                                 Router *router)
    : _model(model), _view(view), router(router) {
  _view->submit->Bind(wxEVT_BUTTON, &LoginController::OnSubmitClicked,
                      this);
}

LoginController::~LoginController() {}

void LoginController::OnSubmitClicked(wxCommandEvent &event) {
  // Pobranie danych z pól formularza
  wxString nameValue = _view->getNameValue();
  wxString surnameValue = _view->getSurnameValue();

  std::cout << "Submit clicked! Name: " << nameValue.ToStdString() << ", Surname: " << surnameValue.ToStdString() << std::endl;

  // Prosta walidacja – sprawdź, czy pola nie są puste
  if (nameValue.IsEmpty() || surnameValue.IsEmpty()) {
    wxMessageBox("Wypełnij wszystkie pola!", "Błąd", wxOK | wxICON_ERROR);
    return;
  }

  // Przykładowe dane (możesz dostosować)
  std::string email = "testowy@test.com";
  std::string pass = "123";
  int age = 50;

  // Utworzenie nowego użytkownika
  User *newUser = new User(nameValue.ToStdString(), surnameValue.ToStdString(), email, pass, age);

  // Zapis do bazy danych
  // Database db("users.json");
  // db.writeInto(*newUser);

  // Ustawienie użytkownika w modelu
  _model->setUser(newUser);

  std::cout << "Navigating to home..." << std::endl;
  // Nawigacja do widoku home
  this->router->navigate("home");
  std::cout << "Navigation done!" << std::endl;
}

void LoginController::OnChangePageClicked(wxCommandEvent &event) {
  this->router->navigate("home");
}