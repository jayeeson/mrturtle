add_executable(mrturtle main.cpp View/qml/qml.qrc)
target_link_libraries(mrturtle PUBLIC model view
  Qt5::Core Qt5::Quick Qt5::QuickControls2)
target_include_directories(mrturtle PUBLIC "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/src/Model"
  "${PROJECT_SOURCE_DIR}/src/View"
  "${PROJECT_SOURCE_DIR}/src/Controller"
  "${PROJECT_SOURCE_DIR}/src/Controller/Commands")
target_compile_options(mrturtle PUBLIC -Wconversion -Werror -Wall -Wextra)

set_target_properties(Qt5::Quick PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")
set_target_properties(Qt5::Core PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")

add_subdirectory(Model)
add_subdirectory(View)