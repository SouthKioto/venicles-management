# Venicle Management System

### Aplikacja do zarzadzania flota pojazdow

## 🛠️ Setup (Linux)

Instrukcja przygotowania środowiska i uruchomienia projektu na systemie Linux

### 1. Wymagania systemowe
Zainstaluj kompilator C++, bibliotekę wxWidgets oraz narzędzie do generowania bazy kompilacji dla LSP:

```bash
sudo pacman -Syu
sudo pacman -S build-essential libwxgtk3.2-dev bear
```

### Kompilacja 
```bash
# kompilacja model
g++ -std=c++17 -Iinclude $(wx-config --cxxflags) -c src/model/Greetings.cpp -o src/model/Greetings.o

# kompilacja widok
g++ -std=c++17 -Iinclude $(wx-config --cxxflags) -c src/view/MainView.cpp -o src/view/MainView.o

# kompilacja kontroler
g++ -std=c++17 -Iinclude $(wx-config --cxxflags) -c src/controller/GreetingsController.cpp -o src/controller/GreetingsController.o

# kompilacja main
g++ -std=c++17 -Iinclude $(wx-config --cxxflags) -c src/main.cpp -o src/main.o

# laczenie w program
g++ src/main.o src/model/Greetings.o src/view/MainView.o src/controller/GreetingsController.o -o main $(wx-config --libs)
```

## 🛠️ Setup (Windows)

Instrukcja przygotowania środowiska i uruchomienia projektu na systemie Windows




