Workshop - aplikacja działająca na zasadzie wypożyczalni samochodów.

Project - autorki program aplikacja działający jako serwis umawania korepetycji, bazujacy na aplikacji warsztatowej, jednak rozszerzony o kilka funkcjonalnosci.

Ogólne zasady programowania, które ma spełniać kod aplikacji:
- SRP (Single Responsibility Principle) - zasada pojedynczej odpowiedzialności.
- KISS (Keep it simple stupid) - zasada prostoty.
- DRY (Don't Repeat Yourself) - zasada niepowtarzania definicji.
- Aplikacja ma być typu B2C, czyli spełniać zastosowanie praktyczne dla klienta.

Teoretycznie aplikacja powinna posiadać architekturę warstwową:
- warstwa prezentacji - odpowiada za komunikację użytkownika z aplikacją,
- warstwa logiki - realizuje domenę aplikacji,
- warstwa składowania - zapewnia możliwość utrwalenia danych.

Na potrzeby warsztatu warstwę prezentacji zastąpią testy automatyczne i funkcja main, a warstwa składowania zostanie ograniczona do składowania informacji w pamięci ulotnej. W projekcie postaram się jednak chociaż trochę je rozbudować.
