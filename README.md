<b><h1>Vehicle Management System<h1></b>

<h3>Aplikacja desktopowa C++ (wxWidgets) do zarządzania flotą pojazdów, zbudowana w architekturze MVC.</h3>

<b><h2>Struktura projektu</h2></b>
 - `src/` & `include/` – Kod źródłowy i nagłówki podzielone na model, view oraz controller.
 - `database/` – Logika zapisu i obsługi danych.
 - `nlohmann/` – Biblioteka do obsługi plików JSON. 

<h2>Przygotowanie środowiska</h2>

 - Linux: ```sudo pacman -Syu base-devel wxwidgets-gtk3 bear```
 - Windows (MSYS): ```pacman -Syu mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-wxwidgets3.2-msw```

<h2>Kompilacja i uruchomienie</h2>

<h3>Korzystamy z pliku Makefile:<h3>
[Makefile](./Makefile)


<h3>Kompilacja</h3>

```bash 
    make main
```




