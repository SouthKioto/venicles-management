#include "../include/additionalScripts/Logger.hpp"
#include "../include/database/Database.hpp"
#include "../include/view/MainView.hpp"
#include <wx/wx.h>

class VenicleManagement : public wxApp {

public:
  virtual bool OnInit() override {

    std::unique_ptr<Logger> logger = std::make_unique<Logger>();

    std::unique_ptr<Database> database =
        std::make_unique<Database>(logger.get());
    database->initDatabase();

    std::unique_ptr<MainView> mainView =
        std::make_unique<MainView>(logger.get(), database.get());
    mainView->Show();
    return true;
  }
};

wxIMPLEMENT_APP(VenicleManagement);
