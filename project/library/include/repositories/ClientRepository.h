// include/repositories/ClientRepository.h
#ifndef CLIENTREPOSITORY_H
#define CLIENTREPOSITORY_H

#include <vector>
#include <string>
#include "../../library/include/typedefs.h"

class ClientRepository {
private:
    std::vector<ClientPtr> clients;
public:
    ClientPtr get(size_t index) const;
    void add(const ClientPtr& client);
    void remove(const ClientPtr& client);
    std::string report() const;
    size_t size() const;
    std::vector<ClientPtr> findBy(ClientPredicate predicate) const;
    std::vector<ClientPtr> findAll () const;
};

#endif // CLIENTREPOSITORY_H

