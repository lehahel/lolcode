cmake_minimum_required (VERSION 3.13)

add_library(LOLOBJECT STATIC lolobject.cpp lolobject.h)
add_library(LOLDRIVER STATIC loldriver.cpp loldriver.h)
add_library(COMDRIVER STATIC driver.cpp driver.hh)

project(ParserExample)
set(
    HEADERS
    ${ParserExample_SOURCE_DIR}/driver.hh
    ${ParserExample_SOURCE_DIR}/parser.hh
    )

find_package(BISON REQUIRED)
BISON_TARGET(
    MyParser
    parser.y
    ${ParserExample_SOURCE_DIR}/parser.cpp
    DEFINES_FILE ${ParserExample_SOURCE_DIR}/parser.hh
)

find_package(FLEX REQUIRED)
FLEX_TARGET(
    MyScanner
    scanner.l
    ${ParserExample_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_executable(
    INTERPRETER
    main.cpp
    driver.cpp
    lolobject.cpp
    loldriver.cpp
    lexems.cpp
    ${BISON_MyParser_OUTPUTS}
    ${FLEX_MyScanner_OUTPUTS}
)
# target_include_directories(ParserExample PRIVATE ${ParserExample_SOURCE_DIR})
target_link_libraries(LOLOBJECT LOLDRIVER)
target_link_libraries(INTERPRETER LOLDRIVER LOLOBJECT COMDRIVER)


