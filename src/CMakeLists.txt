add_executable(mrturtle main.cpp)
target_link_libraries(mrturtle PUBLIC types backend
  Qt5::Core Qt5::Widgets Qt5::Quick Qt5::Qml)
target_include_directories(mrturtle PUBLIC "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/src"
  "${PROJECT_SOURCE_DIR}/src/Backend"
  "${PROJECT_SOURCE_DIR}/src/Backend/Commands"
  "${PROJECT_SOURCE_DIR}/src/Types")
target_compile_options(mrturtle PUBLIC -Wconversion -Werror -Wall -Wextra)

set_target_properties(Qt5::Quick PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")
set_target_properties(Qt5::Core PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")

add_subdirectory(Types)
add_subdirectory(Backend)