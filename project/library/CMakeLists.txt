cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
    #headers
    include/model/Client.h
    include/model/GroupCourse.h
    include/model/Individual.h
    include/model/Lesson.h
    include/model/Teacher.h
    include/model/ClientType.h
    include/repositories/ClientRepository.h
    include/repositories/TeacherRepository.h
    include/repositories/LessonRepository.h
    include/RepositoriesManager.h
    include/typedefs.h
    #src
    src/model/Client.cpp
    src/model/GroupCourse.cpp
    src/model/Individual.cpp
    src/model/Lesson.cpp
    src/model/Teacher.cpp
    src/model/ClientType.cpp
    src/repositories/ClientRepository.cpp
    src/repositories/TeacherRepository.cpp
    src/repositories/LessonRepository.cpp
    src/RepositoriesManager.cpp
)

# Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)

# Ustawienie flagi enable_testing() w podprojekcie biblioteki
enable_testing()

# Znalezienie i dołączenie biblioteki Boost - unit test i date time
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" "date_time" REQUIRED)

# Dodanie katalogu include do ścieżek dołączanych
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

# Zdefiniowanie plików źródłowych testów
set(SOURCE_TEST_FILES # tu w przyszłości będą dodawane pliki źródłowe testów
test/ClientTest.cpp
test/TeacherTest.cpp
test/LessonTest.cpp
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
