Struktura aplikacji po zakończeniu warsztatu nr 6:

          |- workshop
               |
               |- library
               |    |- include
               |    |    |- model
               |    |        |- Address.h
               |    |        |- Bicycle.h
               |    |        |- Car.h
               |    |        |- Client.h
               |    |        |- ClientType.h
               |    |        |- Moped.h
               |    |        |- MotorVehicle.h
               |    |        |- Rent.h
               |    |        |- Vehicle.h
               |    |    |- repositories
               |    |        |- ClientRepository.h
               |    |        |- RentRepository.h
               |    |        |- VehicleRepository.h
               |    |    |- StorageContainer.h
               |    |	 |- typedefs.h
               |    |- src
               |    |    |- model
               |    |        |- Address.cpp
               |    |        |- Bicycle.cpp
               |    |        |- Car.cpp
               |    |        |- Client.cpp
               |    |        |- ClientType.cpp
               |    |        |- Moped.cpp
               |    |        |- MotorVehicle.cpp
               |    |        |- Rent.cpp
               |    |        |- Vehicle.cpp
               |    |    |- repositories
               |    |        |- ClientRepository.cpp
               |    |        |- RentRepository.cpp
               |    |        |- VehicleRepository.cpp
               |    |    |- StorageContainer.cpp
               |    |- test
               |    |    |- master.cpp
               |    |    |- AddressTest.cpp
               |    |    |- ClientTest.cpp
               |    |    |- RentTest.cpp
               |    |    |- RepositoryTest.cpp
               |    |    |- VehicleTest.cpp
               |    |
               |    |- CMakeLists.txt
               |
               |- program
               |    |- include
               |    |- src
               |    |    |- main.cpp
               |    |- test
               |    |
               |    |- CMakeLists.txt
               |
               |- CMakeLists.txt