/**
 * @file RepositoriesManager.h
 * @brief Plik zawierający deklarację klasy RepositoriesManager, która zarządza repozytoriami.
 */
#ifndef REPOSITORIESMANAGER_H
#define REPOSITORIESMANAGER_H
 
 /**
 * @brief Headery klas, których metody są wykorzystywane w klasie GroupCourse
 * @path_to ClientRepository.h
 * @path_to TeacherRepository.h 
 * @path_to LessonRepository.h
 * @path_to Client.h
 * @path_to Teacher.h
 * @path_to Lesson.h
 */
#include "repositories/ClientRepository.h"
#include "repositories/TeacherRepository.h"
#include "repositories/LessonRepository.h"
#include "../../library/include/model/Client.h"
#include "../../library/include/model/Teacher.h"
#include "../../library/include/model/Lesson.h"

/**
 * @brief Klasa zarządzająca repozytoriami klientów, nauczycieli i lekcji.
 */
class RepositoriesManager {
private:
    ClientRepository clientRepo; ///< Repozytorium klientów
    TeacherRepository teacherRepo; ///< Repozytorium nauczycieli
    LessonRepository lessonRepo;  ///< Repozytorium lekcji

public:
    /**
    * @brief Konstruktor domyślny klasy RepositoriesManager.
    */
    RepositoriesManager();
    
    /**
    * @brief Pobiera repozytorium klientów.
    * 
    * @return Referencja do repozytorium klientów.
    */
    ClientRepository& getClientRepository();
    
    /**
    * @brief Pobiera repozytorium nauczycieli.
    * 
    * @return Referencja do repozytorium nauczycieli.
    */
    TeacherRepository& getTeacherRepository();
    
    /**
    * @brief Pobiera repozytorium lekcji.
    * 
    * @return Referencja do repozytorium lekcji.
    */ 
    LessonRepository& getLessonRepository();
    
    /**
    * @brief Inicjalizuje dane testowe.
    */
    void initializeTestData();
};

#endif // REPOSITORIESMANAGER_H

