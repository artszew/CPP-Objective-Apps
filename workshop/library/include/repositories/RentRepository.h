// include/repositories/RentRepository.h
#ifndef RENTREPOSITORY_H
#define RENTREPOSITORY_H

#include <vector>
#include <string>
#include "../../library/include/typedefs.h"

class RentRepository {
private:
    std::vector<RentPtr> rents;
public:
    RentPtr get(size_t index) const;
    void add(const RentPtr& rent);
    void remove(const RentPtr& rent);
    std::string report() const;
    size_t size() const;
    std::vector<RentPtr> findBy(RentPredicate predicate) const;
    std::vector<RentPtr> findAll () const;
};

#endif // RENTREPOSITORY_H

