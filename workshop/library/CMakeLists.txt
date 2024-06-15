cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
    src/model/Client.cpp
    include/model/Client.h
    src/model/Address.cpp
    include/model/Address.h
    src/model/Vehicle.cpp
    include/model/Vehicle.h
    src/model/Rent.cpp
    include/model/Rent.h
    src/model/Bicycle.cpp
    include/model/Bicycle.h
    src/model/MotorVehicle.cpp
    include/model/MotorVehicle.h
    src/model/Car.cpp
    include/model/Car.h
    src/model/Moped.cpp
    include/model/Moped.h
    src/model/ClientType.cpp
    include/model/ClientType.h
    src/repositories/ClientRepository.cpp
    include/repositories/ClientRepository.h
    src/repositories/RentRepository.cpp
    include/repositories/RentRepository.h
    src/repositories/VehicleRepository.cpp
    include/repositories/VehicleRepository.h
    src/StorageContainer.cpp
    include/StorageContainer.h
   )

# Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)

# Ustawienie flagi enable_testing() w podprojekcie biblioteki
enable_testing()

# Znalezienie i dołączenie biblioteki Boost
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

# Dodanie katalogu include do ścieżek dołączanych
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

# Zdefiniowanie plików źródłowych testów
set(SOURCE_TEST_FILES # tu w przyszłości będą dodawane pliki źródłowe testów
test/ClientTest.cpp
test/AddressTest.cpp
test/VehicleTest.cpp
test/RentTest.cpp
test/master.cpp
test/RepositoryTest.cpp
)

add_executable (LibraryTester ${SOURCE_TEST_FILES})

#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries (LibraryTester
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#dodaj test LibraryTest. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(LibraryTest LibraryTester
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

add_custom_target(check
        ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
