#ifndef GROUPCOURSE_H
#define GROUPCOURSE_H

#include "Lesson.h"

enum class AmountOfMembers { Two, Three, Four};

class GroupCourse : public Lesson {
private:
    AmountOfMembers amountOfMembers;

public:
    GroupCourse(const int lessonID, const pt::ptime& beginDateAndTime, float duration, const std::string& subject, std::shared_ptr<Client> client, std::shared_ptr<Teacher> teacher, AmountOfMembers amountOfMembers);

    virtual float getLessonPrice() const;
    
    AmountOfMembers getAmountOfMembers(); 
    
    static std::string amountOfMembersToString(AmountOfMembers amountOfMembers);

    std::string getInfo() const;

    virtual ~GroupCourse();
};

#endif // GROUPCOURSE_H

