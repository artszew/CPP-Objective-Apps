/**
 * @file LessonRepository.h
 * @brief Plik zawierający deklarację klasy LessonRepository, która stanowi repozytorium zajęć.
 */
#ifndef LESSONREPOSITORY_H
#define LESSONREPOSITORY_H

#include <vector>
#include <string>
#include "../typedefs.h"

/**
 * @brief Klasa reprezentująca repozytorium zajęć.
 */
class LessonRepository {
private:
    std::vector<LessonPtr> lessons; ///< Wektor przechowujący wskaźniki do obiektów zajęć
public:

    /**
     * @brief Pobiera zajęcia na określonej pozycji.
     * 
     * @param index Indeks zajęć w wektorze.
     * @return Wskaźnik do zajęć.
     */
    LessonPtr get(size_t index) const;
    
    /**
     * @brief Dodaje zajęcia do repozytorium.
     * 
     * @param lesson Wskaźnik do zajęć do dodania.
     */
    void add(const LessonPtr& lesson);
    
     /**
     * @brief Usuwa zajęcia z repozytorium.
     * 
     * @param lesson Wskaźnik do zajęć do usunięcia.
     */
    void remove(const LessonPtr& lesson);
    
     /**
     * @brief Generuje raport o wszystkich zajęciach w repozytorium.
     * 
     * @return String z raportem.
     */
    std::string report() const;
    
    /**
     * @brief Pobiera liczbę zajęć w repozytorium.
     * 
     * @return Liczba zajeć.
     */    
    size_t size() const;
    
     /**
     * @brief Znajduje zajęcia spełniające określony warunek.
     * 
     * @param predicate Predykat określający warunek do spełnienia.
     * @return Wektor wskaźników do zajęć spełniających warunek.
     */    
    std::vector<LessonPtr> findBy(LessonPredicate predicate) const;
    
     /**
     * @brief Pobiera wszystkich zajęć z repozytorium.
     * 
     * @return Wektor wskaźników do wszystkich zajęć.
     */
    std::vector<LessonPtr> findAll () const;
};

#endif // LESSONREPOSITORY_H

