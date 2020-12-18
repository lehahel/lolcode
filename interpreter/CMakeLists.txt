cmake_minimum_required (VERSION 3.13)

project(ParserExample)
set(
    HEADERS
    ${ParserExample_SOURCE_DIR}/driver.hh
    ${ParserExample_SOURCE_DIR}/parser.hh
    ${ParserExample_SOURCE_DIR}/lolobject.h
    )

BISON_TARGET(
    MyParser
    parser.y
    ${ParserExample_SOURCE_DIR}/parser.cpp
    DEFINES_FILE ${ParserExample_SOURCE_DIR}/parser.hh
    DEFINES_FILE ${ParserExample_SOURCE_DIR}/lolobject.h
)

FLEX_TARGET(
    MyScanner
    scanner.l
    ${ParserExample_SOURCE_DIR}/scanner.cpp
    ${ParserExample_SOURCE_DIR}/lolobject.h
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_executable(
    ParserExample
    main.cpp
    driver.cpp
    lolobject.cpp
    ${BISON_MyParser_OUTPUTS}
    ${FLEX_MyScanner_OUTPUTS}
)
target_include_directories(ParserExample PRIVATE ${ParserExample_SOURCE_DIR})



