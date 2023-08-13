cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(custom_stl
    VERSION 1.0.0.0
    DESCRIPTION "Кастомная версия библиотеки stl. Автор: Fallen Angel"
    LANGUAGES CXX)

#-------------------------------------------------#
#-------------------------------------------------#
#----- Пространство подключения зависимостей -----#
#-------------------------------------------------#
#-------------------------------------------------#

#---------------------------------------------------------------------#
# Так как моя версия не зависит от сторонних библиотек, то тут пусто:)#
# Но, вы можете использовать это для себя                             #
#---------------------------------------------------------------------#


#------------------------------#
#------------------------------#
#----- Пространство опций -----#
#------------------------------#
#------------------------------#

#--------------------------#
# Опции сборок классов STL #
#--------------------------#

option(BUILD_ALL "Собрать все аналоги пространства std::" OFF)
option(BUILD_VECTOR "Собрать библиотеку для динамического массива(аналог std::vector)" ON)
option(BUILD_ARRAY "Собрать библиотеку для статического массива(аналог std::array)" OFF)
option(BUILD_MAP "Собрать библиотеку для карты на красно-чёрном древе(аналог std::map)" OFF)
option(BUILD_UNORDERED_MAP "Собрать библиотеку для карты на основе hash-table(аналог std::unordered_map)" OFF)
option(BUILD_PAIR "Собрать библиотеку для пары(аналог std::pair)" ON)
option(BUILD_SINGLE_LIST "Собрать библиотеку для односвязного списка(аналог std::forward_list)" ON)
option(BUILD_DOUBLE_LIST "Собрать библиотеку для двусвязного списка(аналог std::list)" OFF)

#-----------------------------#
# Опции сборки всех библиотек #
#-----------------------------#

option(STL_SHARED_LIBS "Создать динамическую версию библиотеки" OFF)
option(STL_INSTALL_LIBS "Создать таргет <install> для библиотеки" ON)
option(STL_UNINSTALL_LIBS "Создать таргет <uninstall> для библиотеки" ON)

#-----------------------------------------------#
# Опции сборок примеров использования библиотек #
#-----------------------------------------------#


option(BUILD_EXAMPLES "Собрать примеры для библиотек" ON)


#------------------------------------------------#
#------------------------------------------------#
#----- Пространство подключений подпроектов -----#
#------------------------------------------------#
#------------------------------------------------#

#---------------------------------------------------------#
# Сборка подпроектов в зависимости от выбранных библиотек #
#---------------------------------------------------------#

if(BUILD_ALL)
    add_subdirectory(include/custom_vector)
    add_subdirectory(include/custom_array)
    add_subdirectory(include/custom_map)
    add_subdirectory(include/custom_unordered_map)
    add_subdirectory(include/custom_pair)
    add_subdirectory(include/custom_single_list)
    add_subdirectory(include/custom_double_list)
else()
    if(BUILD_VECTOR)
        add_subdirectory(include/custom_vector)
    endif()

    if(BUILD_ARRAY)
        add_subdirectory(include/custom_array)
    endif()

    if(BUILD_MAP)
        add_subdirectory(include/custom_map)
    endif()

    if(BUILD_UNORDERED_MAP)
        add_subdirectory(include/custom_unordered_map)
    endif()

    if(BUILD_PAIR)
        add_subdirectory(include/custom_pair)
    endif()

    if(BUILD_SINGLE_LIST)
        add_subdirectory(include/custom_single_list)
    endif()

    if(BUILD_DOUBLE_LIST)
        add_subdirectory(include/custom_double_list)
    endif()
endif()

#-----------------------------------------#
# Сборка примеров для собранных библиотек #
#-----------------------------------------#

if(BUILD_EXAMPLES)
    add_subdirectory(examples/custom_vector)
    add_subdirectory(examples/custom_pair)
    add_subdirectory(examples/custom_single_list)
endif()

#-------------------------------------------------------------------#
# Создание таргета "uninstall" для удаления установленных библиотек #
#-------------------------------------------------------------------#

if(STL_UNINSTALL_LIBS)
    add_custom_target("uninstall" COMMENT "Uninstall installed files")
    add_custom_command(
        TARGET "uninstall"
        POST_BUILD
        COMMENT "Uninstall files with install_manifest.txt"
        COMMAND xargs rm -vf < install_manifest.txt || echo Nothing in install_manifest.txt to be uninstalled!
    )
endif()
