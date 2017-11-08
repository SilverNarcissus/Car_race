cmake_minimum_required(VERSION 3.8)
project(Car_race)

set(CMAKE_CXX_STANDARD 11)
#头文件列表
set(INC_DIR ./include ./googletest/include)
#源文件列表
set(SOURCE_FILES source/houghMain.cpp
        utility/Database.cpp
        utility/Database.h
        utility/utils.cpp
        utility/utils.h
        test/my_test.h)

add_subdirectory(./googletest)
#需要链接库的位置
link_directories(./lib)
#引用的头文件位置
include_directories(${INC_DIR})

#库列表
set(LIBRARYS libgtest.a libpthread.dylib libmysqlclient.a libopencv_core.2.4.13.dylib libopencv_highgui.2.4.13.dylib libopencv_imgproc.2.4.13.dylib libopencv_ml.2.4.13.dylib)

add_executable(Car_race ${SOURCE_FILES} test/my_test.cpp)

target_link_libraries(Car_race ${LIBRARYS})
