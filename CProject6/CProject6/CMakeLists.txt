# CMakeList.txt: проект CMake для CProject6; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CProject6 "main.cpp" "Fraction.h" "Fraction.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CProject6 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
