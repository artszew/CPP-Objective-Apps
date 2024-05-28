//Introduction project.



#include <iostream>

#include "../../library/include/model/Client.h"
#include "../../library/include/model/Address.h"
#include "../../library/include/model/Vehicle.h"
#include "../../library/src/model/Client.cpp"
#include "../../library/src/model/Address.cpp"
#include "../../library/src/model/Vehicle.cpp"

using namespace std;



int main()

{

    // Tworzenie obiektu adresu
    Address address_1("Lodz", "Aleja Politechniki", "20/4");
    cout << endl << address_1.getInfo() << endl;

    // Tworzenie obiektu pierwszego klienta
    Client client_1 ("Artur", "Szewczykowski", "0123456789", &address_1); // Obiekt tworzony na stosie (stack)
    Client &ref_c1 = client_1; // Referencja do obiektu
    cout << endl << ref_c1.getInfo() << endl;

    // Obiekt drugiego klienta
    Client *client_2Ptr = new Client("Jan","Kowalski","0987654321", &address_1); // Obiekt tworzony na stercie (heap)
    cout << endl <<client_2Ptr->getInfo() << endl; // Dla wskaźnika używamy -> zamiast '.'
    cout << "Adres pamięci wskaźnika na Client2: " << client_2Ptr << endl << endl;

    // Tworzenie obiektu pierwszego pojazdu
    Vehicle vehicle_1 ("EL 21B15", 10); // Obiekt tworzony na stosie (stack)
    Vehicle &ref_v1 = vehicle_1; // Referencja do obiektu
    cout << endl << ref_v1.getInfo() << endl;

    // Próba zmiany wartości parametru FirstName obiektu Client1
    cout << "Próba zmiany wartości parametru FirstName obiektu Client1:\n";
    ref_c1.setFirstName("");
    cout << "Aktualne imię klienta: " << ref_c1.getFirstName() << endl;
    cout << "Czy widzisz poprzednią wartość parametru - 'Artur'? Jeżeli tak, to nie udało się zmienić wartości na pustą.\n\n";



    // Zwolnienie zaalokowanej pamięci dla obiektu drugiego klienta
    delete client_2Ptr;



    return 0;

}
