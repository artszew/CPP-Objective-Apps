#include "../../library/include/model/GroupCourse.h"
#include "../../library/include/model/Teacher.h"
#include "../../library/include/model/Lesson.h"
#include "../../library/include/model/Client.h"
GroupCourse::GroupCourse(const int lessonID, const pt::ptime& beginDateAndTime, float duration, const std::string& subject, std::shared_ptr<Client> client, std::shared_ptr<Teacher> teacher, AmountOfMembers amountOfMembers)
    : Lesson(lessonID, beginDateAndTime, duration, subject, client, teacher), amountOfMembers(amountOfMembers) {}

float GroupCourse::getLessonPrice() const {
    float price = (getTeacher()->getBasePrice() * Lesson::getDuration()); // stawka podstawowa
    price = (getClient()->applyDiscount(price)); // uwzględnij szkołę/klasę ucznia
    switch(amountOfMembers) { // uwzględnij liczność grupy
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
    
AmountOfMembers GroupCourse::getAmountOfMembers() {
    return amountOfMembers;
}

std::string GroupCourse::getInfo() const {
    std::string info = Lesson::getInfo();
    info += ", type: group course";
    info += "Lesson price: " + std::to_string(getLessonPrice());
    return info;
}

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

GroupCourse::~GroupCourse() {}

