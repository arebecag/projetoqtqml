project(envia VERSION 0.0.1.0 LANGUAGES CXX)

string(TOUPPER "${PROJECT_NAME}" PROJ_NAME)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Qml CONFIG REQUIRED)
find_package(Qt5DBus CONFIG REQUIRED)

set(SRC
    envia.qrc
    src/envia.cpp
    src/leitor.cpp
    src/servidor.cpp
)

set(HDR
    src/defs.hpp
    src/leitor.hpp
    src/servidor.hpp
)

add_executable(${PROJECT_NAME}_exe ${SRC} ${HDR})

set_target_properties(${PROJECT_NAME}_exe PROPERTIES
    OUTPUT_NAME ${PROJECT_NAME}
)

target_link_libraries(${PROJECT_NAME}_exe Qt5::Widgets)
target_link_libraries(${PROJECT_NAME}_exe Qt5::Qml)
target_link_libraries(${PROJECT_NAME}_exe Qt5::DBus)

target_compile_definitions(${PROJECT_NAME}_exe PRIVATE -D${PROJ_NAME}_VERSION="${PROJECT_VERSION}")
target_compile_definitions(${PROJECT_NAME}_exe PRIVATE -D${PROJ_NAME}_VERSION_MAJOR=${PROJECT_VERSION_MAJOR})
target_compile_definitions(${PROJECT_NAME}_exe PRIVATE -D${PROJ_NAME}_VERSION_MINOR=${PROJECT_VERSION_MINOR})
target_compile_definitions(${PROJECT_NAME}_exe PRIVATE -D${PROJ_NAME}_VERSION_PATCH=${PROJECT_VERSION_PATCH})
target_compile_definitions(${PROJECT_NAME}_exe PRIVATE -D${PROJ_NAME}_VERSION_BUILD=${PROJECT_VERSION_TWEAK})

include(Platform)
include(Compiler)

add_custom_target(run_envia
    COMMAND ${PROJECT_NAME}_exe
    DEPENDS ${PROJECT_NAME}_exe
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

get_target_property(EXE_OUTPUT_NAME ${PROJECT_NAME}_exe OUTPUT_NAME)

add_custom_target(run_envia_debug
    COMMAND ${SYSTEM_DEBUGGER} ${DEBUGGER_PARAMS} ${EXE_OUTPUT_NAME}
    DEPENDS ${PROJECT_NAME}_exe
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

target_include_directories(${PROJECT_NAME}_exe PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(${PROJECT_NAME}_exe PRIVATE ${CMAKE_SOURCE_DIR}/src/include)

target_compile_definitions(${PROJECT_NAME}_exe PRIVATE ${PLATFORM_DEFINES})
target_compile_definitions(${PROJECT_NAME}_exe PRIVATE ${CXX_COMPILER_DEFINES})

target_compile_options(${PROJECT_NAME}_exe PRIVATE ${CXX_COMPILER_OPTIONS})

include(CheckIncludeFileCXX)

check_include_file_cxx(cinttypes HAVE_CINTTYPES)
check_include_file_cxx(cstddef   HAVE_CSTDDEF)

if(${HAVE_CINTTYPES})
    target_compile_definitions(${PROJECT_NAME}_exe PRIVATE -DHAVE_INTTYPES_H)
endif()

if(${HAVE_CSTDDEF})
    target_compile_definitions(${PROJECT_NAME}_exe PRIVATE -DHAVE_STDDEF_H)
endif()

include(CheckCXXSourceCompiles)

check_cxx_source_compiles(
    "int main() {
        void *ptr = nullptr;

        return 0;
    }"
    HAVE_NULLPTR
)

if (${HAVE_NULLPTR})
    target_compile_definitions(${PROJECT_NAME}_exe PRIVATE -DHAVE_NULLPTR)
endif()
