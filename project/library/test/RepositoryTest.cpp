#include <boost/test/unit_test.hpp>
#include "../include/RepositoriesManager.h"
#include "../include/model/Client.h"
#include "../include/model/Teacher.h"
#include "../include/model/Lesson.h"
#include "../include/typedefs.h"
#include <memory>

namespace btt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(RepositoryTests)

/**
 * @brief Test sprawdzający poprawność dodawania i usuwania klientów z repozytorium.
 */
BOOST_AUTO_TEST_CASE(ClientRepositoryTest) {
    RepositoriesManager manager;

    // Dodanie nowego klienta
    auto newClient = std::make_shared<Client>("Jan", 2, 3, std::make_shared<SecondarySchool>());
    manager.getClientRepository().add(newClient);

    // Sprawdzenie wielkości repozytorium po dodaniu klienta
    BOOST_CHECK_EQUAL(manager.getClientRepository().size(), 2);

    // Usunięcie klienta
    manager.getClientRepository().remove(newClient);
    // Sprawdzenie wielkości repozytorium po usunięciu klienta
    BOOST_CHECK_EQUAL(manager.getClientRepository().size(), 1);
}

/**
 * @brief Test sprawdzający poprawność dodawania i usuwania nauczycieli z repozytorium.
 */
BOOST_AUTO_TEST_CASE(TeacherRepositoryTest) {
    RepositoriesManager manager;

    // Dodanie nowego nauczyciela
    auto newTeacher = std::make_shared<Teacher>("Adam", 60, 2);
    manager.getTeacherRepository().add(newTeacher);

    // Sprawdzenie wielkości repozytorium po dodaniu nowego nauczyciela
    BOOST_CHECK_EQUAL(manager.getTeacherRepository().size(), 2);

    // Usunięcie nauczyciela
    manager.getTeacherRepository().remove(newTeacher);
    // Sprawdzenie wielkości repozytorium po usunięciu nauczyciela
    BOOST_CHECK_EQUAL(manager.getTeacherRepository().size(), 1);
}

/**
 * @brief Test sprawdzający poprawność dodawania i usuwania lekcji z repozytorium.
 */
BOOST_AUTO_TEST_CASE(LessonRepositoryTest) {
    RepositoriesManager manager;

    auto client = manager.getClientRepository().get(0);
    auto teacher = manager.getTeacherRepository().get(0);
    pt::ptime now = boost::posix_time::second_clock::local_time();
    auto newLesson = std::make_shared<Lesson>(1, now, 1, "Math", client, teacher);
    manager.getLessonRepository().add(newLesson);

    // Sprawdzenie wielkości repozytorium po dodaniu lekcji
    BOOST_CHECK_EQUAL(manager.getLessonRepository().size(), 2);

    // Usunięcie wypożyczenia
    manager.getLessonRepository().remove(newLesson);
    // Sprawdzenie wielkości repozytorium po usunięciu lekcji
    BOOST_CHECK_EQUAL(manager.getLessonRepository().size(), 1);
}

/**
 * @brief Test sprawdzający poprawność obsługi usuwania nieistniejącego klienta.
 */
BOOST_AUTO_TEST_CASE(RemoveNonExistentClientTest) {
    RepositoriesManager manager;

    // Próba usunięcia nieistniejącego klienta
    manager.getClientRepository().remove(nullptr);

    // Sprawdzenie, czy wielkość repozytorium pozostała bez zmian
    BOOST_CHECK_EQUAL(manager.getClientRepository().size(), 1);
}

/**
 * @brief Test sprawdzający poprawność obsługi usuwania nieistniejącego nauczyciela.
 */
BOOST_AUTO_TEST_CASE(RemoveNonexistentTeacherTest) {
    RepositoriesManager manager;

    // Próba usunięcia nieistniejącego nauczyciela
    manager.getTeacherRepository().remove(nullptr);

    // Sprawdzenie, czy wielkość repozytorium pozostała bez zmian
    BOOST_CHECK_EQUAL(manager.getTeacherRepository().size(), 1);
}

/**
 * @brief Test sprawdzający poprawność obsługi usuwania nieistniejących zajec.
 */
BOOST_AUTO_TEST_CASE(RemoveNonexistentLessonTest) {
    RepositoriesManager manager;

    // Próba usunięcia nieistniejących zajec
    manager.getLessonRepository().remove(nullptr);

    // Sprawdzenie, czy wielkość repozytorium pozostała bez zmian
    BOOST_CHECK_EQUAL(manager.getLessonRepository().size(), 1);
}

/**
 * @brief Test sprawdzający poprawność obsługi dodawania pustego wskaźnika klienta.
 */
BOOST_AUTO_TEST_CASE(AddNullClientTest) {
    RepositoriesManager manager;

    // Próba dodania pustego wskaźnika
    manager.getClientRepository().add(nullptr);

    // Sprawdzenie, czy wielkość repozytorium pozostała bez zmian
    BOOST_CHECK_EQUAL(manager.getClientRepository().size(), 1);
}

/**
 * @brief Test sprawdzający poprawność obsługi dodawania pustego wskaźnika nauczyciela.
 */
BOOST_AUTO_TEST_CASE(AddNullTeacherTest) {
    RepositoriesManager manager;

    // Próba dodania pustego wskaźnika
    manager.getTeacherRepository().add(nullptr);

    // Sprawdzenie, czy wielkość repozytorium pozostała bez zmian
    BOOST_CHECK_EQUAL(manager.getTeacherRepository().size(), 1);
}

/**
 * @brief Test sprawdzający poprawność obsługi dodawania pustego wskaźnika do zajec.
 */
BOOST_AUTO_TEST_CASE(AddNullLessonTest) {
    RepositoriesManager manager;

    // Próba dodania pustego wskaźnika
    manager.getLessonRepository().add(nullptr);

    // Sprawdzenie, czy wielkość repozytorium pozostała bez zmian
    BOOST_CHECK_EQUAL(manager.getLessonRepository().size(), 1);
}

BOOST_AUTO_TEST_SUITE_END()

//Proste funkcje logiczne pomagające w testach repozytoriów
bool clientHasFirstNameJan(const ClientPtr& client) {
    return client->getFirstName() == "Jan";
}
bool teacherHasFirstNameArtur(const TeacherPtr& teacher) {
    return teacher->getFirstName() == "Artur";
}
bool lessonHasID1(const LessonPtr& lesson) {
    return lesson->getLessonID() == 1;
}

BOOST_AUTO_TEST_SUITE(RepositoriesPredicatesTests)

// Test dla metody findBy w repozytorium klientów
BOOST_AUTO_TEST_CASE(FindByClientTest) {
    RepositoriesManager manager;

    // Wywołanie metody findBy z wybranym predykatem
    std::vector<ClientPtr> foundClients = manager.getClientRepository().findBy(clientHasFirstNameJan);

    // Sprawdzenie, czy liczba znalezionych klientów jest poprawna
    BOOST_CHECK_EQUAL(foundClients.size(), 1); // Zakładając, że jest tylko 1 klient o nazwisku "Kowal"
}

// Test dla metody findBy w repozytorium nauczycieli
BOOST_AUTO_TEST_CASE(FindByTeacherTest) {
    RepositoriesManager manager;

    // Wywołanie metody findBy z wybranym predykatem
    std::vector<TeacherPtr> foundTeachers = manager.getTeacherRepository().findBy(teacherHasFirstNameArtur);

    // Sprawdzenie, czy liczba znalezionych nauczycieli jest poprawna
    BOOST_CHECK_EQUAL(foundTeachers.size(), 1); 
}

// Test dla metody findBy w repozytorium wypożyczeń
BOOST_AUTO_TEST_CASE(FindByLessonTest) {
    RepositoriesManager manager;

    // Wywołanie metody findBy z wybranym predykatem
    std::vector<LessonPtr> foundLessons = manager.getLessonRepository().findBy(lessonHasID1);

    // Sprawdzenie, czy liczba znalezionych wypozyczen jest poprawna
    BOOST_CHECK_EQUAL(foundLessons.size(), 1); 
}

BOOST_AUTO_TEST_SUITE_END()

