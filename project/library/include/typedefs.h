#ifndef TYPEDEFS_H
#define TYPEDEFS_H

 /**
 * @brief Headery klas, których metody są wykorzystywane w klasie GroupCourse
 * @path_to Lesson.h
 * @path_to GroupCourse.h
 * @path_to Individual.h
 * @path_to Teacher.h
 * @path_to Client.h
 * @path_to ClientType.h
 */
#include <memory>
#include "../../library/include/model/Lesson.h"
#include "../../library/include/model/GroupCourse.h"
#include "../../library/include/model/Individual.h"
#include "../../library/include/model/Teacher.h"
#include "../../library/include/model/Client.h"
#include "../../library/include/model/ClientType.h"

/**
 * @brief Definicje typów wskaźników do różnych klas używanych w systemie.
 */
typedef std::shared_ptr<Teacher> TeacherPtr; ///< Typ wskaźnika do obiektu Teacher
typedef std::shared_ptr<Individual> IndividualPtr; ///< Typ wskaźnika do obiektu Individual
typedef std::shared_ptr<GroupCourse> GroupCoursePtr; ///< Typ wskaźnika do obiektu GroupCourse
typedef std::shared_ptr<Lesson> LessonPtr;  ///< Typ wskaźnika do obiektu Lesson
typedef std::shared_ptr<Client> ClientPtr;  ///< Typ wskaźnika do obiektu Client
typedef std::shared_ptr<ClientType> ClientTypePtr;  ///< Typ wskaźnika do obiektu ClientType

/**
 * @brief Typ predykatu dla klasy Client.
 * 
 * @param ClientPtr Wskaźnik do obiektu Client.
 * @return True jeśli predykat jest spełniony, false w przeciwnym razie.
 */
typedef std::function<bool(ClientPtr)> ClientPredicate;

/**
 * @brief Typ predykatu dla klasy Lesson.
 * 
 * @param LessonPtr Wskaźnik do obiektu Lesson.
 * @return True jeśli predykat jest spełniony, false w przeciwnym razie.
 */
typedef std::function<bool(LessonPtr)> LessonPredicate;


/**
 * @brief Typ predykatu dla klasy Teacher.
 * 
 * @param TeacherPtr Wskaźnik do obiektu Teacher.
 * @return True jeśli predykat jest spełniony, false w przeciwnym razie.
 */
typedef std::function<bool(TeacherPtr)> TeacherPredicate;

#endif // TYPEDEFS_H

