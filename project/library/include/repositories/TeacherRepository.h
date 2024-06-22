// include/repositories/TeacherRepository.h
#ifndef TEACHERREPOSITORY_H
#define TEACHERREPOSITORY_H

#include <vector>
#include <string>
#include "../../library/include/typedefs.h"

class TeacherRepository {
private:
    std::vector<TeacherPtr> teachers;
public:
    TeacherPtr get(size_t index) const;
    void add(const TeacherPtr& teacher);
    void remove(const TeacherPtr& teacher);
    std::string report() const;
    size_t size() const;
    std::vector<TeacherPtr> findBy(TeacherPredicate predicate) const;
    std::vector<TeacherPtr> findAll () const;
};

#endif // TEACHERREPOSITORY_H

