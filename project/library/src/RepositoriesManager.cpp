/**
 * @file RepositoriesManager.cpp
 * @brief Plik zawierający implementacje metod klasy RepositoriesManager, która zarządza repozytoriami.
 */
 
  /**
 * @brief Headery klas, których metody są wykorzystywane w klasie GroupCourse
 * @path_to RepositoriesManager.h
 * @path_to Client.h
 * @path_to Teacher.h
 * @path_to Lesson.h
 */
#include "../../library/include/RepositoriesManager.h"
#include "../../library/include/model/Client.h"
#include "../../library/include/model/Teacher.h"
#include "../../library/include/model/Lesson.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
namespace pt = boost::posix_time;

/**
 * @brief Konstruktor klasy RepositoriesManager. Inicjalizuje repozytoria przykładowymi danymi.
 */
RepositoriesManager::RepositoriesManager() {
    initializeTestData();
}

/**
 * @brief Zwraca referencję do repozytorium klientów.
 * @return Referencja do repozytorium klientów.
 */
ClientRepository& RepositoriesManager::getClientRepository() {
    return clientRepo;
}

/**
 * @brief Zwraca referencję do repozytorium pojazdów.
 * @return Referencja do repozytorium pojazdów.
 */
TeacherRepository& RepositoriesManager::getTeacherRepository() {
    return teacherRepo;
}

/**
 * @brief Zwraca referencję do repozytorium wypożyczeń.
 * @return Referencja do repozytorium wypożyczeń.
 */
LessonRepository& RepositoriesManager::getLessonRepository() {
    return lessonRepo;
}

/**
 * @brief Inicjalizuje repozytoria przykładowymi danymi.
 */
void RepositoriesManager::initializeTestData() {
    ClientPtr client0 = std::make_shared<Client>("Jan", 1, 3, std::make_shared<SecondarySchool>());
    clientRepo.add(client0);

    TeacherPtr teacher0 = std::make_shared<Teacher>("Artur", 60, 1);
    teacherRepo.add(teacher0);
    
    std::string lessonDate("2024-06-26 14:20:00.000");
    pt::ptime t=pt::time_from_string(lessonDate);
    LessonPtr lesson0 = std::make_shared<Lesson>(1, t, 1, "Math", client0, teacher0);
    lessonRepo.add(lesson0);
    
    // Dodaj ręcznie wypożyczenie do listy bieżących lekcji klienta
    client0->addLesson(lesson0);
}



