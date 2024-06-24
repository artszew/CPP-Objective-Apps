/**
 * @file GroupCourse.cpp
 * @brief Plik zawierający implementacje metod klasy GroupCourse, która reprezentuje zajęcia grupowe.
 */
 
  /**
 * @brief Headery klas, których metody są wykorzystywane w klasie GroupCourse
 * @path_to GroupCourse.h 
 * @path_to Teacher.h
 * @path_to Lesson.h
 * @path_to Client.h
 */
#include "../../library/include/model/GroupCourse.h"
#include "../../library/include/model/Teacher.h"
#include "../../library/include/model/Lesson.h"
#include "../../library/include/model/Client.h"

/**
 * @brief Lista inicjalizacyjna klasy GroupCourse.
 * @param lessonID Identyfikator lekcji.
 * @param beginDateAndTime Data i czas kiedy odbędzie się lekcja.
 * @param duration Czas trwania lekcji (w minutach).
 * @param subject Przedmiot.
 * @param client Wskaźnik na ucznia.
 * @param teacher Wskaźnik na nauczyciela.
 * @param amountOfMembers Liczba osób w grupie.
 */
GroupCourse::GroupCourse(const int lessonID, const pt::ptime& beginDateAndTime, float duration, const std::string& subject, std::shared_ptr<Client> client, std::shared_ptr<Teacher> teacher, AmountOfMembers amountOfMembers)
    : Lesson(lessonID, beginDateAndTime, duration, subject, client, teacher), amountOfMembers(amountOfMembers) {}

float GroupCourse::getLessonPrice() const {
    float price = (getTeacher()->getBasePrice() * Lesson::getDuration()); /**< stawka podstawowa */ 
    price = (getClient()->applyDiscount(price)); /**< rodzaj szkoly */ 
    if (getClient()->isExtensionLevel()) { /**< poziom nauczania */ 
    price*=1.25;}
    switch(amountOfMembers) { /**< liczebnosc grupy */ 
        case AmountOfMembers::Two:
            return price * 0.8;
        case AmountOfMembers::Three:
            return price * 0.7;
        case AmountOfMembers::Four:
            return price * 0.6;
        default:
            return price;
    }
}
   
/**
 * @brief Pobiera liczbę członków w grupie.
 * 
 * @return Liczba członków w grupie.
 */    
AmountOfMembers GroupCourse::getAmountOfMembers() {
    return amountOfMembers;
}

/**
 * @brief Pobiera informacje o kursie grupowym.
 * 
 * @return String z informacjami o kursie grupowym.
 */
std::string GroupCourse::getInfo() const {
    std::string info = Lesson::getInfo();
    info += ", type: group course";
    info += "Lesson price: " + std::to_string(getLessonPrice());
    return info;
}

/**
 * @brief Konwertuje wartość AmountOfMembers na string.
 * 
 * @param amountOfMembers Liczba członków w grupie.
 * @return String reprezentujący liczbę członków w grupie.
 */
std::string GroupCourse::amountOfMembersToString(AmountOfMembers amountOfMembers) {
    switch(amountOfMembers) {
        case AmountOfMembers::Two:
            return "2";
        case AmountOfMembers::Three:
            return "3";
        case AmountOfMembers::Four:
            return "4";
        default:
            return "Unknown";
    }
}

/**
 * @brief Destruktor klasy GroupCourse.
 */
GroupCourse::~GroupCourse() {}
