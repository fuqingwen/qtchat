cmake_minimum_required(VERSION 3.16)
set(CMAKE_PREFIX_PATH "/Users/devin/Qt/6.8.0/macos")

project(DuckChat VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network)

# 包含所有源文件
set(PROJECT_SOURCES
        main.cpp
        widget.cpp
        widget.h
        widget.ui
        server.cpp
        server.h
        Resource.qrc
        Images/duckicon.rc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(DuckChat
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(DuckChat SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(DuckChat
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(DuckChat PRIVATE 
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
)

# 设置应用程序图标和其他属性
set_target_properties(DuckChat PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE_GUI_IDENTIFIER com.kevinwu.duckchat
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(DuckChat)
endif()
