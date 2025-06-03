[EN]
Workshop - an application that works on the principle of a car rental service.

Project - the author's application program that works as a service for scheduling tutoring, based on the workshop application, but extended with several functionalities.

General programming principles that the application code should meet:
- SRP (Single Responsibility Principle) - the principle of single responsibility.
- KISS (Keep it simple stupid) - the principle of simplicity.
- DRY (Don't Repeat Yourself) - the principle of not repeating definitions.
- The application should be of the B2C type, i.e. it should meet practical applications for the client.

Theoretically, the application should have a layered architecture:
- presentation layer - responsible for communication between the user and the application,
- logic layer - implements the application domain,
- storage layer - provides the possibility of persisting data.

For the needs of the workshop, the presentation layer will be replaced by automatic tests and the main function, and the storage layer will be limited to storing information in volatile memory. However, in the project I will try to expand them at least a little.

[PL]
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
