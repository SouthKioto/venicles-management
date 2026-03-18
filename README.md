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
g++ -Wall -Wextra -std=c++17 -Iinclude -I/usr/lib/wx/include/gtk3-unicode-3.2 -I/usr/include/wx-3.2 -DWXUSINGDLL -D__WXGTK3__ -D__WXGTK__ -D_FILE_OFFSET_BITS=64 -c src/model/Greetings.cpp -o src/model/Greetings.o

# kompilacja widok
g++ -Wall -Wextra -std=c++17 -Iinclude -I/usr/lib/wx/include/gtk3-unicode-3.2 -I/usr/include/wx-3.2 -DWXUSINGDLL -D__WXGTK3__ -D__WXGTK__ -D_FILE_OFFSET_BITS=64 -c src/view/MainView.cpp -o src/view/MainView.o

# kompilacja kontroler
g++ -Wall -Wextra -std=c++17 -Iinclude -I/usr/lib/wx/include/gtk3-unicode-3.2 -I/usr/include/wx-3.2 -DWXUSINGDLL -D__WXGTK3__ -D__WXGTK__ -D_FILE_OFFSET_BITS=64 -c src/controller/GreetingsController.cpp -o src/controller/GreetingsController.o

# kompilacja main
g++ -Wall -Wextra -std=c++17 -Iinclude -I/usr/lib/wx/include/gtk3-unicode-3.2 -I/usr/include/wx-3.2 -DWXUSINGDLL -D__WXGTK3__ -D__WXGTK__ -D_FILE_OFFSET_BITS=64 -c src/main.cpp -o src/main.o

# laczenie w program
g++ src/main.o src/controller/GreetingsController.o src/model/Greetings.o src/view/MainView.o -o main -lwx_gtk3u_xrc-3.2 -lwx_gtk3u_html-3.2 -lwx_gtk3u_qa-3.2 -lwx_gtk3u_core-3.2 -lwx_baseu_xml-3.2 -lwx_baseu_net-3.2 -lwx_baseu-3.2
```

### Jesli wysietlaja sie jakies dziwne błędy
### (ale kompilacja przebiegła bez problemu)

```bash
bear -- make clean main
```

## 🛠️ Setup (Windows)

Instrukcja przygotowania środowiska i uruchomienia projektu na systemie Windows




