/**
 * @file Individual.cpp
 * @brief Plik zawierający implementacje metod klasy Individual, która reprezentuje zajęcia indywidualne.
 */
 
  /**
 * @brief Headery klas, których metody są wykorzystywane w klasie GroupCourse
 * @path_to Individual.h 
 * @path_to Teacher.h
 * @path_to Lesson.h
 * @path_to Client.h
 */
#include "../../library/include/model/Individual.h"
#include "../../library/include/model/Teacher.h"
#include "../../library/include/model/Lesson.h"
#include "../../library/include/model/Client.h"

/**
 * @brief Konstruktor parametrowy klasy Individual.
 * @param lessonID Identyfikator lekcji.
 * @param beginDateAndTime Data i czas kiedy odbędzie się lekcja.
 * @param duration Czas trwania lekcji (w minutach).
 * @param subject Przedmiot.
 * @param client Wskaźnik na ucznia.
 * @param teacher Wskaźnik na nauczyciela.
 * @param firstLesson Flaga informująca czy są to pierwsze zajęcia danego ucznia z danym nauczycielem.
 * @param atClientHome Flaga informująca czy zajęcia są stacjonarnie czy online.
 */
Individual::Individual(const int lessonID, const pt::ptime& beginDateAndTime, float duration, const std::string& subject, std::shared_ptr<Client> client, std::shared_ptr<Teacher> teacher, bool firstLesson, bool atClientHome)
    : Lesson(lessonID, beginDateAndTime, duration, subject, client, teacher), firstLesson(firstLesson), atClientHome(atClientHome) {}

/**
 * @brief Sprawdza, czy są to pierwsze zajęcia danego ucznia z danym nauczycielem.
 * 
 * @return True jeśli są to pierwsze zajęcia, false w przeciwnym razie.
 */
bool Individual::isFirstLesson() const {
    return firstLesson;
}

/**
 * @brief Ustawia flagę informującą, czy są to pierwsze zajęcia.
 * 
 * @param firstLesson wartość flagi.
 */
void Individual::setFirstLesson(bool firstLesson) {
    this->firstLesson = firstLesson;
}

/**
 * @brief Sprawdza, czy zajęcia odbywają się w domu klienta.
 * 
 * @return True jeśli zajęcia odbywają się w domu klienta, false w przeciwnym razie.
 */
bool Individual::isAtClientHome() const {
    return atClientHome;
}

/**
 * @brief Ustawia flagę informującą, czy zajęcia odbywają się w domu klienta.
 * 
 * @param atClientHome wartość flagi.
 */
void Individual::setIsAtClientHome(bool atClientHome) {
    this->atClientHome = atClientHome;
}

/**
 * @brief Oblicza cenę lekcji.
 * 
 * @return Cena lekcji po uwzględnieniu rabatów i dodatkowych opłat.
 */
float Individual::getLessonPrice() const {
    float price = (getTeacher()->getBasePrice()*Lesson::getDuration()); /**< stawka podstawowa */ 
    price = (getClient()->applyDiscount(price)); //**< polimorfizm obliczenia ulgi ze wzgledu na typ clienta */ 
    if (getClient()->isExtensionLevel()) { /**< poziom nauczania */
    price*=1.25;}
    if (Individual::isAtClientHome()) { /**< zajęcia z dojazdem */
    price*=1.1;}
    if (Individual::isFirstLesson()) { /**< pierwsze zajęcia */
    price*=0.5;}
    return price;
}

/**
 * @brief Pobiera informacje o lekcji.
 * 
 * @return Łańcuch znaków z informacjami o lekcji.
 */
std::string Individual::getInfo() const {
    std::string info = Lesson::getInfo();
    info += "Type: Individual\n";
    info += "First lesson: " + std::string(firstLesson ? "Yes" : "No") + "\n";
    info += "At client's home: " + std::string(atClientHome ? "Yes" : "No") + "\n";
    info += "Lesson price: " + std::to_string(getLessonPrice());
    return info;
}

/**
 * @brief Destruktor klasy Individual.
 */
Individual::~Individual() {}
