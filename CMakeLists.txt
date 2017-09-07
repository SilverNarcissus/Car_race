cmake_minimum_required(VERSION 3.8)
project(Car_race)

set(CMAKE_CXX_STANDARD 11)
set(INC_DIR /Users/SilverNarcissus/Desktop/mysql-connector-c-6.1.11-macos10.12-x86_64/include)
set(LIB_PATH  /Users/SilverNarcissus/Desktop/mysql-connector-c-6.1.11-macos10.12-x86_64/lib)
set(SOURCE_FILES source/main.cpp utility/Database.cpp utility/Database.h utility/utils.cpp utility/utils.h test/my_test.h)

include_directories(${INC_DIR})
link_directories(${LINK_DIR})
add_executable(Car_race ${SOURCE_FILES} test/my_test.cpp)

target_link_libraries(Car_race /Users/SilverNarcissus/Desktop/mysql-connector-c-6.1.11-macos10.12-x86_64/lib/libmysqlclient.a)
