TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += bib
INCLUDEPATH += gui_glut
INCLUDEPATH += trab1
INCLUDEPATH += object

LIBS += -lGL -lGLU -lglut -l3ds -lSDL2_image

SOURCES += main.cpp \
    bib/Camera.cpp \
    bib/CameraDistante.cpp \
    bib/CameraJogo.cpp \
    bib/Desenha.cpp \
    bib/model3ds.cpp \
    bib/Vetor3D.cpp \
    gui_glut/extra.cpp \
    gui_glut/gui.cpp \
    object/Sphere.cpp \
    object/Object.cpp \
    object/Cube.cpp \
    object/ScorePoint.cpp \
    object/Fruit.cpp \
    object/Circle.cpp \
    object/Pacman.cpp

HEADERS += \
    bib/Camera.h \
    bib/CameraDistante.h \
    bib/CameraJogo.h \
    bib/Desenha.h \
    bib/model3ds.h \
    bib/Vetor3D.h \
    gui_glut/extra.h \
    gui_glut/gui.h \
    object/Sphere.h \
    object/Object.h \
    object/Cube.h \
    object/ScorePoint.h \
    object/Fruit.h \
    object/Circle.h \
    object/Pacman.h
