// include/repositories/LessonRepository.h
#ifndef LESSONREPOSITORY_H
#define LESSONREPOSITORY_H

#include <vector>
#include <string>
#include "../../library/include/typedefs.h"

class LessonRepository {
private:
    std::vector<LessonPtr> lessons;
public:
    LessonPtr get(size_t index) const;
    void add(const LessonPtr& lesson);
    void remove(const LessonPtr& lesson);
    std::string report() const;
    size_t size() const;
    std::vector<LessonPtr> findBy(LessonPredicate predicate) const;
    std::vector<LessonPtr> findAll () const;
};

#endif // LESSONREPOSITORY_H

