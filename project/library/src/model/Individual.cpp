#include "../../library/include/model/Individual.h"
#include "../../library/include/model/Teacher.h"
#include "../../library/include/model/Lesson.h"
#include "../../library/include/model/Client.h"
Individual::Individual(const int lessonID, const pt::ptime& beginDateAndTime, float duration, const std::string& subject, std::shared_ptr<Client> client, std::shared_ptr<Teacher> teacher, bool firstLesson, bool atClientHome)
    : Lesson(lessonID, beginDateAndTime, duration, subject, client, teacher), firstLesson(firstLesson), atClientHome(atClientHome) {}

bool Individual::isFirstLesson() const {
    return firstLesson;
}

void Individual::setFirstLesson(bool firstLesson) {
    this->firstLesson = firstLesson;
}

bool Individual::isAtClientHome() const {
    return atClientHome;
}

void Individual::setIsAtClientHome(bool atClientHome) {
    this->atClientHome = atClientHome;
}

float Individual::getLessonPrice() const {
    float price = (getTeacher()->getBasePrice()*Lesson::getDuration()); // stawka podstawowa
    price = (getClient()->applyDiscount(price)); // uwzględnij szkołę/klasę ucznia
    if (Individual::isAtClientHome()) { //zajęcia z dojazdem
    price*=1.1;}
    if (Individual::isFirstLesson()) { // pierwsze zajęcia
    price*=0.5;}
    return price;
}

std::string Individual::getInfo() const {
    std::string info = Lesson::getInfo();
    info += "Type: Individual\n";
    info += "First lesson: " + std::string(firstLesson ? "Yes" : "No") + "\n";
    info += "At client's home: " + std::string(atClientHome ? "Yes" : "No") + "\n";
    info += "Lesson price: " + std::to_string(getLessonPrice());
    return info;
}

Individual::~Individual() {}

