// include/repositories/REPOSITORIESMANAGER.h
#ifndef REPOSITORIESMANAGER_H
#define REPOSITORIESMANAGER_H

#include "repositories/ClientRepository.h"
#include "repositories/TeacherRepository.h"
#include "repositories/LessonRepository.h"
#include "../../library/include/model/Client.h"
#include "../../library/include/model/Teacher.h"
#include "../../library/include/model/Lesson.h"

class RepositoriesManager {
private:
    ClientRepository clientRepo;
    TeacherRepository teacherRepo;
    LessonRepository lessonRepo;

public:
    RepositoriesManager();
    ClientRepository& getClientRepository();
    TeacherRepository& getTeacherRepository();
    LessonRepository& getLessonRepository();
    void initializeTestData();
};

#endif // REPOSITORIESMANAGER_H

