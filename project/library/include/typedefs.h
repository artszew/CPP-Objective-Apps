#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <memory>
#include "../../library/include/model/Lesson.h"
#include "../../library/include/model/GroupCourse.h"
#include "../../library/include/model/Individual.h"
#include "../../library/include/model/Teacher.h"
#include "../../library/include/model/Client.h"
#include "../../library/include/model/ClientType.h"

typedef std::shared_ptr<Teacher> TeacherPtr;
typedef std::shared_ptr<Individual> IndividualPtr;
typedef std::shared_ptr<GroupCourse> GroupCoursePtr;
typedef std::shared_ptr<Lesson> LessonPtr;
typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<ClientType> ClientTypePtr;
// Typ predykatu dla klasy Client
typedef std::function<bool(ClientPtr)> ClientPredicate;

// Typ predykatu dla klasy Lesson
typedef std::function<bool(LessonPtr)> LessonPredicate;

// Typ predykatu dla klasy Teacher
typedef std::function<bool(TeacherPtr)> TeacherPredicate;

#endif // TYPEDEFS_H
