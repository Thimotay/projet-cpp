
add_executable(mainLauncher mainLauncher.cpp)

target_link_libraries(mainLauncher PUBLIC src sfml-system sfml-graphics sfml-window sfml-audio box2d tmxlite)

add_custom_target(copy-resources ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/resources)
file(GLOB RESOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/resources/*.*)
file(GLOB RESOURCES_IMAGE CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/resources/images/*.*)
file(GLOB RESOURCES_TILEMAP CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/resources/images/tilemap/*.*)
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/resources
        DEPENDS ${CMAKE_SOURCE_DIR}/resources
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/resources
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/resources/images
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/resources/images/tilemap
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${RESOURCES}
        ${CMAKE_CURRENT_BINARY_DIR}/resources
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${RESOURCES_TILEMAP}
        ${CMAKE_CURRENT_BINARY_DIR}/resources/images/tilemap
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${RESOURCES_IMAGE}
        ${CMAKE_CURRENT_BINARY_DIR}/resources/images)
add_dependencies(mainLauncher copy-resources)