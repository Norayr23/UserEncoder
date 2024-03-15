# Define project
QT += widgets
TARGET = Login_App
TEMPLATE = app

# Define sources
SOURCES += \
    main.cpp \
    mainwindow/mainwindow.cpp \
    user/User.cpp \
    file_manager/FileManager.cpp \
    user_file_manager/UserFileManager.cpp

# Define headers
HEADERS += \
    mainwindow/mainwindow.h \
    user/User.h \
    file_manager/FileManager.h \
    user_file_manager/UserFileManager.h

# Define UI files
FORMS += mainwindow/mainwindow.ui

# Set C++ standard
CONFIG += c++17

# Additional configuration for Android
android {
    # Define Android-specific properties
    # android {
    #     QT += androidextras
    # }

    # Define Android-specific sources
    # SOURCES += android/...
}

# Set properties for macOS bundle
macx {
    MACOSX_BUNDLE = true
    MACOSX_BUNDLE_BUNDLE_VERSION = $$VERSION
    MACOSX_BUNDLE_SHORT_VERSION_STRING = $$VERSION
    BUNDLE_ID = com.example.Login_App
}

# Install target
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/main
INSTALLS += target

