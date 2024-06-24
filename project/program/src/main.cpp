#include <iostream>
//headers:
#include "../../library/include/model/Lesson.h"
#include "../../library/include/model/Individual.h"
#include "../../library/include/model/GroupCourse.h"
#include "../../library/include/model/Client.h"
#include "../../library/include/model/ClientType.h"
#include "../../library/include/model/Teacher.h"
#include "../../library/include/RepositoriesManager.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include "../../library/include/typedefs.h"
#include <iostream>
#include <string>
#include <stdexcept>

template <typename Repository, typename Object>
void addObjectToRepository(Repository& repo, const Object& object) {
    repo.add(object);}

using namespace std;
int main()
{	std::string firstName;
	std::string firstNameT;
	int clientID;
	int schoolClass;
	int schoolType;
	int teacherID;
	int basePrice;      
	RepositoriesManager manager;
        int wybor=0;
        
        cout <<"\nWitaj w aplikacji do zarzadzania i ustalania korepetycji.";
        cout <<"\nO to dostepne opcje. Po kazdym dzialaniu zostanie wyswietlona odpowiednia informacja potwierdzajaca poprawnosc wykonanej operacji.\n";
        cout <<"1 - Wyswietl informacje o danych w repozytoriach.\n";
        cout <<"2 - Utworz i dodaj do repozytorium nowego ucznia.\n";
        cout <<"3 - Utworz i dodaj do repozytorium nowego nauczyciela.\n";
        cout <<"100 - Zamknij program.\n";
        while (wybor!=100)
        {
            cout<<"\nCo chcesz zrobic teraz?\n";
            cin >>wybor;
            switch (wybor)
            {
                case 1:
                {
                    cout<<"Obecna liczba uczniow w repozytorium wynosi: " <<manager.getClientRepository().size();
                    cout <<"\nDane na temat uczniów:" <<manager.getClientRepository().report();
                    cout<<"Obecna liczba nauczycieli w repozytorium wynosi: " <<manager.getTeacherRepository().size();
                    cout <<"\nDane na temat nauczycieli:" <<manager.getTeacherRepository().report();
                    break;
                }
                case 2: {
                    cout << "Wprowadz dane nowego ucznia. Na poczatek imie:";
                    cin >> firstName;
                    cout << "ID klienta:";
                    cin >> clientID;
                    cout << "Klasa do której chodzi:";
                    cin >> schoolClass;
                    if (schoolClass < 1 || schoolClass > 8) {
                        throw std::invalid_argument("Niepoprawidlowa klasa");
                    }
                    cout << "1 - podstawowka\n2 - szkola srednia \n3 - studia\nWybierz rodzaj szkoly sposrod powyzszych:";
                    cin >> schoolType;
                    std::shared_ptr<Client> newClient = nullptr;
                    switch (schoolType)
                    {
                        case 1:
                        {
                            newClient = std::make_shared<Client>(firstName, clientID, schoolClass,
                                                                 std::make_shared<PrimarySchool>());
                        }
                        break;
                        case 2: {
                            newClient = std::make_shared<Client>(firstName, clientID, schoolClass, std::make_shared<SecondarySchool>());
                        }
                        break;
                        case 3: {
                            newClient = std::make_shared<Client>(firstName, clientID, schoolClass,std::make_shared<Student>());
                        }
                        break;
                        default:
                            throw std::invalid_argument("Niepoprawny rodzaj szkoły");
                        }
                    if (newClient != nullptr)
                    {
                    addObjectToRepository(manager.getClientRepository(), newClient); //funkcja generyczna#1
                    cout << "\nLiczba uczniów w repozytorium po dodaniu nowego ucznia wynosi: " << manager.getClientRepository().size() <<endl;
                    }
                }
                break;
                case 3:
                {
                    cout << "Wprowadz dane nowego nauczyciela. Na poczatek imie:";
                    cin >> firstNameT;
                    cout << "ID nauczyciela:";
                    cin >> teacherID;
                    cout << "Cena bazowa za 1 godzine zajec:";
                    cin >> basePrice;
                    auto newTeacher = std::make_shared<Teacher>(firstNameT, teacherID, basePrice);
                    addObjectToRepository(manager.getTeacherRepository(), newTeacher); //funkcja generyczna#2
                    cout << "\nLiczba nauczycieli w repozytorium po dodaniu nowego nauczyciela wynosi: "
                         << manager.getTeacherRepository().size() << endl;
                }
                    break;
                case 100:
                {
                break;}
                default:
                    throw std::invalid_argument("Niepoprawny wybor dzialania");
            }
        }
        cout <<"Zakonczono dzialanie programu";
        return 0;
}
