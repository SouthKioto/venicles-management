#ifndef GREETINGSCONTROLLER_HPP
#define GREETINGSCONTROLLER_HPP

#include "../model/Greetings.hpp"
#include "../view/MainView.hpp"
#include <wx/wx.h>

class GreetingsController {
  Greetings *m_model;
  MainView *m_view;

public:
  GreetingsController(Greetings *model, MainView *view)
      : m_model(model), m_view(view) {

    // Łączymy event przycisku z metodą kontrolera
    m_view->m_button->Bind(wxEVT_BUTTON, &GreetingsController::OnHello, this);
  }

  void OnHello(wxCommandEvent &event) {
    // Poprawka: nazwa metody w modelu to getWelcomeMessage (zgodnie z Twoim
    // plikiem cpp)
    m_view->setGreetingText(m_model->getWelcomeMessage());
  }
};

#endif
