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

### 2. Kompilacja 
<br>
(to jest przykład kompilacji, dla 100 lub wiecej plików tak nie robimy)

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

## Jesli wysietlaja sie jakies dziwne błędy ale kompilacja przebiegła bez problemu

```bash
bear -- make clean main
```

### ta komenda utworzy plik 'compile_commands.json' który usunie błędy

## 🛠️ Setup (Windows)

Instrukcja przygotowania środowiska i uruchomienia projektu na systemie Windows

### 1. Wymagania systemowe

zainstalujcie MSYS2 (bedziemy uzywac terminala MSYS2 MinGW 64-bit)
    
## Po instalacji uruchomcie konsolę, przejdzcie pod katalog z projektem (ja trzymam na C, najprostrze dojscie i win czasami nie radzi sobie z nazwami) i uruchomcie taką komendę:

```bash
    pacman -Syu
    pacman -S mingw-w64-ucrt-x86_64-wxwidgets3.2-msw
```

## Jesli nie macie kompilatora to 
```bash
    pacman -S mingw-w64-ucrt-x86_64-gcc
```

# 🛠️ MAKEFILE

```makefile
ifeq ($(OS),Windows_NT)
    TARGET = main.exe
    RM = del /s /q
    FixPath = $(subst /,\,$1)
else
    TARGET = main
    RM = rm -rf
    FixPath = $1
endif

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude $(shell wx-config --cxxflags)
LDFLAGS = $(shell wx-config --libs)

SRC = $(wildcard src/*.cpp) $(wildcard src/view/*.cpp) $(wildcard src/model/*.cpp) $(wildcard src/controller/*.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(call FixPath, $(OBJ) $(TARGET))

.PHONY: all clean

```


