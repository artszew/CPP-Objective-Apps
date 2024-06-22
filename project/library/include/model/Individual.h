#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "Lesson.h"

class Individual : public Lesson {
private:
    bool firstLesson;
    bool atClientHome;

public:
    Individual(const int lessonID, const pt::ptime& beginDateAndTime, float duration, const std::string& subject, std::shared_ptr<Client> client, std::shared_ptr<Teacher> teacher, bool firstLesson = false, bool atClientHome = false);

    bool isFirstLesson() const;
    void setFirstLesson(bool firstLesson);

    bool isAtClientHome() const;
    void setIsAtClientHome(bool atClientHome);

    float getLessonPrice() const;

    std::string getInfo() const;

    ~Individual();
};

#endif // INDIVIDUAL_H

