1. Struktura aplikacji:

          |- project
               |
               |- library
               |    |- include
               |    |    |- model
               |    |        |- Client.h
               |    |        |- ClientType.h
               |    |        |- Lesson.h
               |    |        |- Individual.h
               |    |        |- GroupCourse.h
               |    |        |- Teacher.h
               |    |    |- repositories
               |    |        |- ClientRepository.h
               |    |        |- LessonRepository.h
               |    |        |- TeacherRepository.h
               |    |    |- RepositoriesManager.h
               |    |	 |- typedefs.h
               |    |- src
               |    |    |- model
               |    |        |- Client.cpp
               |    |        |- ClientType.cpp
               |    |        |- Lesson.cpp
               |    |        |- Individual.cpp
               |    |        |- GroupCourse.cpp
               |    |        |- Teacher.cpp
               |    |    |- repositories
               |    |        |- ClientRepository.cpp
               |    |        |- LessonRepository.cpp
               |    |        |- TeacherRepository.cpp
               |    |    |- RepositoriesManager.cpp
               |    |- test
               |    |    |- master.cpp
               |    |    |- AddressTest.cpp
               |    |    |- ClientTest.cpp
               |    |    |- RentTest.cpp
               |    |    |- RepositoryTest.cpp
               |    |    |- VehicleTest.cpp
               |    |
               |    |- CMakeLists.txt
               |
               |- program
               |    |- include
               |    |- src
               |    |    |- main.cpp
               |    |
               |    |- CMakeLists.txt
               |
               |- CMakeLists.txt
               

2. Wytyczne do implementacji:
- [x] Diagram UML zgodny z implementacją 
- [x] Prawidłowa struktura projektu (rozdzielenie plików źródłowych od nagłówkowych, podkatalogi z podziałem kodu ze względu na przeznaczenie)
- [x] Prawidłowe zarządzanie pamięcią i innymi zasobami (właściwe ich zdobywanie i zwalnianie - smartpointery)
- [x] Hermetyzacja (pola i metody), konstruktory i listy inicjalizacyjne
- [x] Dziedziczenie, abstrakcja i polimorfizm (uzasadnione dziedzicznie, gdzie przynajmniej dwie klasy pochodne różnią się zachowaniem, metody i destruktory wirtualne)
- [x] Pojedyncza odpowiedzialność klas (właściwe rozdzielenie odpowiedzialności między klasami)
- [x] Testy dla metod w klasach logiki aplikacji (pokrycie metod testami, ich sensowność oraz poprawne przechodzenie wszystkich testów)
- [x] Użycie wyjątków do sygnalizowania błędów (w uzasadnionych przypadkach hierarchia klas wyjątków) TODO: dodać obsluge wyjatkow w logice biznesowej
- [x] Odseparowanie logiki aplikacji od klas interfejsu użytkownika i/lub klas odpowiedzialnych za składowanie danych
- [x] Wykorzystanie w uzasadniony sposób mechanizmu delegacji (na przykład w wybranym wzorcu projektowym)
- [x] Prawidłowe wykorzystanie sprytnych wskaźników do zarządzania dynamicznie alokowaną pamięcią
- [] Wykorzystanie zewnętrznych bibliotek (z konfiguracją w cmake)
- [x] Jednolity styl kodowania zgodny z jednym ze standardów (formatowanie kodu, nazewnictwo klas, metod, pól itd.)
- [x] Właściwe komentowanie kodu źródłowego (stopień pokrycia, szczegółowość komentarzy oraz możliwość wykorzystania narzędzi do generowania dokumentacji)
- [x] Korzystanie w uzasadniony sposób z udogodnień języka C++98 (typedef, enum, przestrzenie nazw, przeciążenia operatorów)
- [X] Korzystanie w uzasadniony sposób z biblioteki standardowej języka C++98 (kolekcje, algorytmy, funktory, strumienie)
- [x] Korzystanie w uzasadniony sposób z udogodnień języka i bibliotek standardowej języka C++1x/C++2x innych niż sprytne wskaźniki
- [x] Prawidłowa komunikacja aplikacji z użytkownikiem (wystarczy interfejs tekstowy)
- TODO: Utrwalanie stanu działania aplikacji na dysku w celu jego późniejszego wczytania (wystarczy wykorzystanie plików)
- [X] Uzasadnione wykorzystanie własnych klas, funkcji i metod szablonowych (programowanie generyczne)
