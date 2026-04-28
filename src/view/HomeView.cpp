
#include "../include/view/HomeView.hpp"
#include <wx/simplebook.h>

HomeView::HomeView(wxWindow *window, Router *router,
                   const std::vector<VehicleSummary> &vehicles)
    : wxPanel(window) {
  (void)router;
  SetBackgroundColour(wxColour(17, 24, 39));
  SetForegroundColour(wxColour(229, 231, 235));

  wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer *titleRow = new wxBoxSizer(wxHORIZONTAL);

  wxStaticText *labelTitle = new wxStaticText(this, wxID_ANY, "Home page");
  labelTitle->SetForegroundColour(wxColour(255, 255, 255));

  logoutBtn = new wxButton(this, wxID_ANY, "Wyloguj");
  logoutBtn->SetBackgroundColour(wxColour(55, 65, 81));
  logoutBtn->SetForegroundColour(wxColour(255, 255, 255));
  logoutBtn->SetFont(
      wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

  titleRow->Add(labelTitle, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
  titleRow->AddStretchSpacer(1);
  titleRow->Add(logoutBtn, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

  mainSizer->Add(titleRow, 0, wxEXPAND | wxALL, 5);

  wxBoxSizer *contentRow = new wxBoxSizer(wxHORIZONTAL);

  // ----------------------------------------------------------------
  // PRAWY PANEL: podsumowanie wybranego auta (widoczne po kliknieciu)
  // ----------------------------------------------------------------
  wxPanel *summaryPanel = new wxPanel(this, wxID_ANY);
  summaryPanel->SetBackgroundColour(wxColour(31, 41, 55));
  wxBoxSizer *summarySizer = new wxBoxSizer(wxVERTICAL);

  wxStaticText *summaryTitle =
      new wxStaticText(summaryPanel, wxID_ANY, "Podsumowanie",
                       wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
  summaryTitle->SetForegroundColour(wxColour(255, 255, 255));
  summaryTitle->SetFont(wxFont(13, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
                               wxFONTWEIGHT_BOLD));

  wxStaticText *summaryPlaceholder = new wxStaticText(
      summaryPanel, wxID_ANY,
      "Kliknij \"Zarezerwuj auto\"\naby zobaczyc podsumowanie.",
      wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
  summaryPlaceholder->SetForegroundColour(wxColour(107, 114, 128));

  // Przewijalna lista kart dodawanych po kliknieciu
  wxScrolledWindow *cardsScroll = new wxScrolledWindow(
      summaryPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL);
  cardsScroll->SetBackgroundColour(wxColour(31, 41, 55));
  cardsScroll->SetScrollRate(0, 10);
  wxBoxSizer *cardListSizer = new wxBoxSizer(wxVERTICAL);
  cardsScroll->SetSizer(cardListSizer);

  // Prostokat "Laczna kwota" na dole prawego panelu
  wxPanel *totalPanel = new wxPanel(summaryPanel, wxID_ANY);
  totalPanel->SetBackgroundColour(wxColour(55, 65, 81));
  wxBoxSizer *totalSizer = new wxBoxSizer(wxHORIZONTAL);
  wxStaticText *totalLabel =
      new wxStaticText(totalPanel, wxID_ANY, "Laczna kwota:");
  totalLabel->SetForegroundColour(wxColour(255, 255, 255));
  totalLabel->SetFont(wxFont(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
                             wxFONTWEIGHT_BOLD));
  wxStaticText *totalValue =
      new wxStaticText(totalPanel, wxID_ANY, "—",
                       wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
  totalValue->SetForegroundColour(wxColour(229, 231, 235));
  totalValue->SetFont(wxFont(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
                             wxFONTWEIGHT_NORMAL));
  totalSizer->Add(totalLabel, 0, wxALL | wxALIGN_CENTER_VERTICAL, 12);
  totalSizer->AddStretchSpacer(1);
  totalSizer->Add(totalValue, 0, wxALL | wxALIGN_CENTER_VERTICAL, 12);
  totalPanel->SetSizer(totalSizer);

  summarySizer->Add(summaryTitle, 0, wxTOP | wxLEFT | wxRIGHT, 14);
  summarySizer->Add(summaryPlaceholder, 0, wxALIGN_CENTER | wxALL, 10);
  summarySizer->Add(cardsScroll, 1, wxEXPAND | wxLEFT | wxRIGHT, 10);
  summarySizer->Add(totalPanel, 0, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 14);
  summaryPanel->SetSizer(summarySizer);

  // ----------------------------------------------------------------
  // LEWY PANEL: slider z autami (jedno auto = jeden slajd)
  // ----------------------------------------------------------------
  wxPanel *sliderContainer = new wxPanel(this, wxID_ANY);
  sliderContainer->SetBackgroundColour(wxColour(31, 41, 55));
  wxBoxSizer *sliderContainerSizer = new wxBoxSizer(wxVERTICAL);

  wxSimplebook *slider = new wxSimplebook(sliderContainer, wxID_ANY);

  if (vehicles.empty()) {
    wxPanel *emptySlide = new wxPanel(slider, wxID_ANY);
    emptySlide->SetBackgroundColour(wxColour(55, 65, 81));
    wxBoxSizer *emptySizer = new wxBoxSizer(wxVERTICAL);
    wxStaticText *emptyDesc =
        new wxStaticText(emptySlide, wxID_ANY, "Brak aut w bazie",
                         wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    emptyDesc->SetForegroundColour(wxColour(156, 163, 175));
    emptySizer->AddStretchSpacer(1);
    emptySizer->Add(emptyDesc, 0, wxALIGN_CENTER | wxALL, 12);
    emptySizer->AddStretchSpacer(1);
    emptySlide->SetSizer(emptySizer);
    slider->AddPage(emptySlide, "Brak aut", true);
  }

  for (size_t i = 0; i < vehicles.size(); ++i) {
    VehicleSummary v = vehicles[i];

    wxPanel *slide = new wxPanel(slider, wxID_ANY);
    slide->SetBackgroundColour(wxColour(55, 65, 81));
    wxBoxSizer *slideSizer = new wxBoxSizer(wxVERTICAL);

    wxString cardTitle =
        wxString::Format("Auto %d: %s %s", static_cast<int>(i + 1),
                         v.brand, v.model);

    wxStaticText *slideTitle =
        new wxStaticText(slide, wxID_ANY, cardTitle, wxDefaultPosition,
                         wxDefaultSize, wxALIGN_LEFT);
    slideTitle->SetForegroundColour(wxColour(255, 255, 255));
    slideTitle->SetFont(wxFont(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
                               wxFONTWEIGHT_BOLD));

    wxStaticText *slideYear = new wxStaticText(
        slide, wxID_ANY,
        wxString::Format("Rok: %s | Kolor: %s", v.year, v.color),
        wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
    slideYear->SetForegroundColour(wxColour(156, 163, 175));

    wxButton *reserveBtn = new wxButton(slide, wxID_ANY, "Zarezerwuj auto");
    reserveBtn->SetBackgroundColour(wxColour(31, 41, 55));
    reserveBtn->SetForegroundColour(wxColour(255, 255, 255));

    reserveBtn->Bind(
        wxEVT_BUTTON,
        [v, summaryPlaceholder, cardsScroll, cardListSizer,
         summaryPanel](wxCommandEvent &) {
          summaryPlaceholder->Hide();

          // Nowy prostokat-karta dla wybranego auta
          wxPanel *card = new wxPanel(cardsScroll, wxID_ANY);
          card->SetBackgroundColour(wxColour(55, 65, 81));
          wxBoxSizer *cs = new wxBoxSizer(wxVERTICAL);

          wxStaticText *cBrand = new wxStaticText(
              card, wxID_ANY,
              wxString::Format("%s %s", v.brand, v.model));
          cBrand->SetForegroundColour(wxColour(255, 255, 255));
          cBrand->SetFont(wxFont(11, wxFONTFAMILY_DEFAULT,
                                 wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

          wxStaticText *cYear = new wxStaticText(
              card, wxID_ANY,
              wxString::Format("Rok: %s", v.year));
          wxStaticText *cColor = new wxStaticText(
              card, wxID_ANY,
              wxString::Format("Kolor: %s", v.color));
          for (wxStaticText *l : {cYear, cColor}) {
            l->SetForegroundColour(wxColour(156, 163, 175));
            l->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT,
                              wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
          }

          cs->Add(cBrand, 0, wxALL, 10);
          cs->Add(cYear,  0, wxLEFT | wxRIGHT | wxBOTTOM, 10);
          cs->Add(cColor, 0, wxLEFT | wxRIGHT | wxBOTTOM, 10);
          card->SetSizer(cs);

          cardListSizer->Add(card, 0, wxEXPAND | wxBOTTOM, 8);
          cardsScroll->FitInside();
          cardsScroll->Scroll(0, cardsScroll->GetVirtualSize().y);
          summaryPanel->Layout();
        });

    slideSizer->Add(slideTitle, 0, wxALIGN_LEFT | wxTOP | wxLEFT, 12);
    slideSizer->Add(slideYear, 0, wxALIGN_LEFT | wxLEFT | wxTOP, 6);
    slideSizer->AddStretchSpacer(1);
    slideSizer->Add(reserveBtn, 0, wxALIGN_CENTER | wxBOTTOM, 14);
    slide->SetSizer(slideSizer);

    slider->AddPage(slide, cardTitle, i == 0);
  }

  wxBoxSizer *controlsSizer = new wxBoxSizer(wxHORIZONTAL);
  wxButton *prevBtn =
      new wxButton(sliderContainer, wxID_ANY, "< Poprzedni");
  wxButton *nextBtn =
      new wxButton(sliderContainer, wxID_ANY, "Nastepny >");
  prevBtn->SetBackgroundColour(wxColour(55, 65, 81));
  prevBtn->SetForegroundColour(wxColour(255, 255, 255));
  nextBtn->SetBackgroundColour(wxColour(55, 65, 81));
  nextBtn->SetForegroundColour(wxColour(255, 255, 255));

  prevBtn->Bind(wxEVT_BUTTON, [slider](wxCommandEvent &) {
    int current = slider->GetSelection();
    int count = static_cast<int>(slider->GetPageCount());
    if (count > 0)
      slider->SetSelection((current - 1 + count) % count);
  });

  nextBtn->Bind(wxEVT_BUTTON, [slider](wxCommandEvent &) {
    int current = slider->GetSelection();
    int count = static_cast<int>(slider->GetPageCount());
    if (count > 0)
      slider->SetSelection((current + 1) % count);
  });

  controlsSizer->Add(prevBtn, 0, wxRIGHT, 8);
  controlsSizer->AddStretchSpacer(1);
  controlsSizer->Add(nextBtn, 0);

  sliderContainerSizer->Add(slider, 1, wxEXPAND | wxALL, 10);
  sliderContainerSizer->Add(controlsSizer, 0,
                             wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 10);
  sliderContainer->SetSizer(sliderContainerSizer);

  contentRow->Add(sliderContainer, 1, wxEXPAND | wxALL, 10);
  contentRow->Add(summaryPanel, 1, wxEXPAND | wxALL, 10);

  mainSizer->Add(contentRow, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 5);

  this->SetSizer(mainSizer);
  mainSizer->Fit(this);
}
