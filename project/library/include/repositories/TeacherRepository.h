/**
 * @file TeacherRepository.h
 * @brief Plik zawierający deklarację klasy TeacherRepository, która stanowi repozytorium nauczycieli.
 */
#ifndef TEACHERREPOSITORY_H
#define TEACHERREPOSITORY_H

#include <vector>
#include <string>
#include "../typedefs.h"

class TeacherRepository {
private:
    std::vector<TeacherPtr> teachers; ///< Wektor przechowujący wskaźniki do obiektów nauczycieli
public:

    /**
     * @brief Pobiera nauczyciela na określonej pozycji.
     * 
     * @param index Indeks nauczyciela w wektorze.
     * @return Wskaźnik do nauczyciela.
     */
    TeacherPtr get(size_t index) const;
     
     /**
     * @brief Dodaje nauczyciela do repozytorium.
     * 
     * @param client Wskaźnik do nauczyciela do dodania.
     */
    void add(const TeacherPtr& teacher);
    
     /**
     * @brief Usuwa nauczyciela z repozytorium.
     * 
     * @param client Wskaźnik do nauczyciela do usunięcia.
     */
    void remove(const TeacherPtr& teacher);
    
    /**
    * @brief Generuje raport o wszystkich nauczycielach w repozytorium.
    * 
    * @return String z raportem.
    */    
    std::string report() const;
    
     /**
     * @brief Pobiera liczbę nauczycieli w repozytorium.
     * 
     * @return Liczba nauczycieli.
     */
    size_t size() const;
    
    /**
     * @brief Znajduje nauczycieli spełniających określony warunek.
     * 
     * @param predicate Predykat określający warunek do spełnienia.
     * @return Wektor wskaźników do nauczycieli spełniających warunek.
     */   
    std::vector<TeacherPtr> findBy(TeacherPredicate predicate) const;
    
    /**
     * @brief Pobiera wszystkich nauczycieli z repozytorium.
     * 
     * @return Wektor wskaźników do wszystkich nauczycieli.
     */    
    std::vector<TeacherPtr> findAll () const;
    
    TeacherPtr findMostExpensiveTeacher() const;
    
    TeacherPtr findCheapestTeacher() const;
    
};

#endif // TEACHERREPOSITORY_H

