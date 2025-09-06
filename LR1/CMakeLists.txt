cmake_minimum_required(VERSION 3.22.1) # объявляем минимальную версию cmake
project(Task_3) # устанавливаем имя проекта
set(SOURCES Task_3.cpp) # переменной SOURCES присваиваем значение test.cpp
add_executable(Task_3 ${SOURCES}) # добавляем переменную SOURCES к исполняемым файлам