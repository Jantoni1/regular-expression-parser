find_package (Boost COMPONENTS  unit_test_framework REQUIRED) #system filesystem
set(TEST_PROJECT_NAME "${PROJECT_NAME}_test")
set(tests_sources
        test_main.cpp
        test_main.h
        lexer_tests.cpp
        lexer_tests.h
        parser_tests.cpp
        parser_tests.h generator_tests.cpp generator_tests.h pattern_tests.cpp pattern_tests.h)

#set(Boost_USE_STATIC_RUNTIME TRUE)
#add_definitions(-DBOOST_TEST_DYN_LINK)
add_executable(${TEST_PROJECT_NAME} EXCLUDE_FROM_ALL ${tests_sources})
include_directories(${CMAKE_SOURCE_DIR}/src
        ${Boost_INCLUDE_DIRS}
        ${BOOST_LIBRARIES}
        )
target_link_libraries(
        ${TEST_PROJECT_NAME}
        Parser
        )

set_property(TARGET ${TEST_PROJECT_NAME} PROPERTY CXX_STANDARD 11)