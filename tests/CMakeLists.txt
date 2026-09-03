file(GLOB PANS_TEST_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

list(SORT PANS_TEST_SOURCES)

find_package(Threads REQUIRED)

set(PANS_TEST_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/tests")

foreach(TEST_SOURCE IN LISTS PANS_TEST_SOURCES)
    message(STATUS "${TEST_NAME}")
    get_filename_component(TEST_NAME "${TEST_SOURCE}" NAME_WE)
    message(STATUS "${TEST_NAME}")

    if(TARGET "${TEST_NAME}")
        message(FATAL_ERROR "Cannot create test target '${TEST_NAME}': a target with that name already exists.")
    endif()

    add_executable("${TEST_NAME}" "${TEST_SOURCE}")

    target_link_libraries("${TEST_NAME}" PRIVATE pans Threads::Threads)

    set_target_properties("${TEST_NAME}" PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PANS_TEST_OUTPUT_DIRECTORY}"
    )

    foreach(CONFIG IN LISTS CMAKE_CONFIGURATION_TYPES)
        string(TOUPPER "${CONFIG}" CONFIG_UPPER)
        set_target_properties("${TEST_NAME}" PROPERTIES
            "RUNTIME_OUTPUT_DIRECTORY_${CONFIG_UPPER}" "${PANS_TEST_OUTPUT_DIRECTORY}"
        )
    endforeach()

    add_test(NAME "${TEST_NAME}" COMMAND "${TEST_NAME}")
endforeach()

add_subdirectory(inner_tests)


