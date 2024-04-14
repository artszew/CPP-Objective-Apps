//Introduction project.



#include <iostream>

#include "../../library/include/model/Client.h"

#include "../../library/src/model/Client.cpp"

using namespace std;



int main()

{

    // Tworzenie obiektu pierwszego klienta

    Client client_1 ("Artur", "Szewczykowski", "0123456789"); // Obiekt tworzony na stosie (stack)

    Client &ref = client_1; // Referencja do obiektu

    cout << endl << ref.getInfo() << endl;



    // Obiekt drugiego klienta

    Client *client_2Ptr = new Client("Jan","Kowalski","0987654321"); // Obiekt tworzony na stercie (heap)

    cout << endl <<client_2Ptr->getInfo() << endl; // Dla wskaźnika używamy -> zamiast '.'

    cout << "Adres pamięci wskaźnika na Client2: " << client_2Ptr << endl << endl;



    // Próba zmiany wartości parametru FirstName obiektu Client1

    cout << "Próba zmiany wartości parametru FirstName obiektu Client1:\n";

    ref.setFirstName("");

    cout << "Aktualne imię klienta: " << ref.getFirstName() << endl;

    cout << "Czy widzisz poprzednią wartość parametru - 'Artur'? Jeżeli tak, to nie udało się zmienić wartości na pustą.\n\n";



    // Zwolnienie zaalokowanej pamięci dla obiektu drugiego klienta

    delete client_2Ptr;



    return 0;

}
