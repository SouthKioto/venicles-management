# Vehicle Management System

### Aplikacja desktopowa C++ (wxWidgets) do zarządzania flotą pojazdów, zbudowana w architekturze MVC.

## Struktura projektu
 - `src/` & `include/` – Kod źródłowy i nagłówki podzielone na model, view oraz controller.
 - `database/` – Logika zapisu i obsługi danych.
 - `nlohmann/` – Biblioteka do obsługi plików JSON. 

## Przygotowanie środowiska

 - Linux: ```sudo pacman -Syu base-devel wxwidgets-gtk3 bear```
 - Windows (MSYS): ```pacman -Syu mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-wxwidgets3.2-msw```

## Kompilacja i uruchomienie

### Korzystamy z pliku Makefile:
[CONTRIBUTING.md](Makefile)

### Kompilacja

```bash 
    make main
```




