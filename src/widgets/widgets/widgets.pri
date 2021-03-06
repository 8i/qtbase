# Qt widgets module

HEADERS += \
        widgets/qbuttongroup.h \
        widgets/qbuttongroup_p.h \
        widgets/qabstractspinbox.h \
        widgets/qabstractspinbox_p.h \
        widgets/qframe.h \
        widgets/qframe_p.h \
        widgets/qkeysequenceedit.h \
        widgets/qkeysequenceedit_p.h \
        widgets/qlineedit.h \
        widgets/qlineedit_p.h \
        widgets/qmainwindow.h \
        widgets/qmainwindowlayout_p.h \
        widgets/qmdiarea.h \
        widgets/qmdiarea_p.h \
        widgets/qmdisubwindow.h \
        widgets/qmdisubwindow_p.h \
        widgets/qmenu.h \
        widgets/qmenu_p.h \
        widgets/qmenubar.h \
        widgets/qmenubar_p.h \
        widgets/qscrollarea_p.h \
        widgets/qsizegrip.h \
        widgets/qslider.h \
        widgets/qspinbox.h \
        widgets/qstackedwidget.h \
        widgets/qtextedit.h \
        widgets/qtextedit_p.h \
        widgets/qtoolbar.h \
        widgets/qtoolbar_p.h \
        widgets/qtoolbarlayout_p.h \
        widgets/qtoolbarseparator_p.h \
        widgets/qabstractscrollarea.h \
        widgets/qabstractscrollarea_p.h \
        widgets/qwidgetresizehandler_p.h \
        widgets/qfocusframe.h \
        widgets/qscrollarea.h \
        widgets/qwidgetanimator_p.h \
        widgets/qwidgetlinecontrol_p.h \
        widgets/qtoolbararealayout_p.h \
        widgets/qplaintextedit.h \
        widgets/qplaintextedit_p.h

SOURCES += \
        widgets/qbuttongroup.cpp \
        widgets/qabstractspinbox.cpp \
        widgets/qeffects.cpp \
        widgets/qframe.cpp \
        widgets/qkeysequenceedit.cpp \
        widgets/qlineedit_p.cpp \
        widgets/qlineedit.cpp \
        widgets/qmainwindow.cpp \
        widgets/qmainwindowlayout.cpp \
        widgets/qmdiarea.cpp \
        widgets/qmdisubwindow.cpp \
        widgets/qmenu.cpp \
        widgets/qmenubar.cpp \
        widgets/qsizegrip.cpp \
        widgets/qslider.cpp \
        widgets/qspinbox.cpp \
        widgets/qstackedwidget.cpp \
        widgets/qtextedit.cpp \
        widgets/qtoolbar.cpp \
        widgets/qtoolbarlayout.cpp \
        widgets/qtoolbarseparator.cpp \
        widgets/qabstractscrollarea.cpp \
        widgets/qwidgetresizehandler.cpp \
        widgets/qfocusframe.cpp \
        widgets/qscrollarea.cpp \
        widgets/qwidgetanimator.cpp \
        widgets/qwidgetlinecontrol.cpp \
        widgets/qtoolbararealayout.cpp \
        widgets/qplaintextedit.cpp

qtConfig(abstractbutton) {
    HEADERS += \
        widgets/qabstractbutton.h \
        widgets/qabstractbutton_p.h

    SOURCES += \
        widgets/qabstractbutton.cpp
}

qtConfig(abstractslider) {
    HEADERS += \
        widgets/qabstractslider.h \
        widgets/qabstractslider_p.h

    SOURCES += \
        widgets/qabstractslider.cpp
}

qtConfig(calendarwidget) {
    HEADERS += widgets/qcalendarwidget.h
    SOURCES += widgets/qcalendarwidget.cpp
}

qtConfig(checkbox) {
    HEADERS += \
        widgets/qcheckbox.h

    SOURCES += \
        widgets/qcheckbox.cpp
}

qtConfig(combobox) {
    HEADERS += \
        widgets/qcombobox.h \
        widgets/qcombobox_p.h

    SOURCES += widgets/qcombobox.cpp
}

qtConfig(commandlinkbutton) {
    HEADERS += \
        widgets/qcommandlinkbutton.h

    SOURCES += \
        widgets/qcommandlinkbutton.cpp
}

qtConfig(datetimeedit) {
    HEADERS += \
         widgets/qdatetimeedit.h \
         widgets/qdatetimeedit_p.h

    SOURCES += \
         widgets/qdatetimeedit.cpp
}

qtConfig(dial) {
    HEADERS += widgets/qdial.h
    SOURCES += widgets/qdial.cpp
}

qtConfig(dockwidget) {
    HEADERS += \
        widgets/qdockwidget.h \
        widgets/qdockwidget_p.h \
        widgets/qdockarealayout_p.h

    SOURCES += \
        widgets/qdockwidget.cpp \
        widgets/qdockarealayout.cpp
}

qtConfig(fontcombobox) {
    HEADERS += widgets/qfontcombobox.h
    SOURCES += widgets/qfontcombobox.cpp
}

qtConfig(groupbox) {
    HEADERS += widgets/qgroupbox.h
    SOURCES += widgets/qgroupbox.cpp
}

qtConfig(label) {
    HEADERS += \
        widgets/qlabel.h \
        widgets/qlabel_p.h

    SOURCES += \
        widgets/qlabel.cpp
}

qtConfig(lcdnumber) {
    HEADERS += \
        widgets/qlcdnumber.h

    SOURCES += \
        widgets/qlcdnumber.cpp
}

qtConfig(progressbar) {
    HEADERS += widgets/qprogressbar.h
    SOURCES += widgets/qprogressbar.cpp
}

qtConfig(pushbutton) {
    HEADERS += \
        widgets/qpushbutton.h \
        widgets/qpushbutton_p.h

    SOURCES += \
        widgets/qpushbutton.cpp
}

qtConfig(radiobutton) {
    HEADERS += \
        widgets/qradiobutton.h

    SOURCES += \
        widgets/qradiobutton.cpp
}

qtConfig(dialogbuttonbox) {
    HEADERS += \
        widgets/qdialogbuttonbox.h

    SOURCES += \
        widgets/qdialogbuttonbox.cpp
}

qtConfig(rubberband) {
    HEADERS += widgets/qrubberband.h
    SOURCES += widgets/qrubberband.cpp
}

qtConfig(scrollbar) {
    HEADERS += \
        widgets/qscrollbar.h \
        widgets/qscrollbar_p.h

    SOURCES += widgets/qscrollbar.cpp
}

qtConfig(splashscreen) {
    HEADERS += \
        widgets/qsplashscreen.h

    SOURCES += \
        widgets/qsplashscreen.cpp
}

qtConfig(splitter) {
    HEADERS += \
        widgets/qsplitter.h \
        widgets/qsplitter_p.h

    SOURCES += widgets/qsplitter.cpp
}

qtConfig(statusbar) {
    HEADERS += widgets/qstatusbar.h
    SOURCES += widgets/qstatusbar.cpp
}

qtConfig(tabbar) {
    HEADERS += \
        widgets/qtabbar.h \
        widgets/qtabbar_p.h

    SOURCES += widgets/qtabbar.cpp
}

qtConfig(textbrowser) {
    HEADERS += widgets/qtextbrowser.h
    SOURCES += widgets/qtextbrowser.cpp
}

qtConfig(tabwidget) {
    HEADERS += widgets/qtabwidget.h
    SOURCES += widgets/qtabwidget.cpp
}

qtConfig(toolbox) {
    HEADERS += widgets/qtoolbox.h
    SOURCES += widgets/qtoolbox.cpp
}

qtConfig(toolbutton) {
    HEADERS += \
        widgets/qtoolbutton.h \
        widgets/qtoolbarextension_p.h

    SOURCES += \
        widgets/qtoolbutton.cpp \
        widgets/qtoolbarextension.cpp
}

qtConfig(widgettextcontrol) {
    HEADERS += \
        widgets/qwidgettextcontrol_p.h \
        widgets/qwidgettextcontrol_p_p.h

    SOURCES += \
        widgets/qwidgettextcontrol.cpp
}

macx {
    HEADERS += \
        widgets/qmacnativewidget_mac.h \
        widgets/qmaccocoaviewcontainer_mac.h

    OBJECTIVE_SOURCES += \
        widgets/qmenu_mac.mm \
        widgets/qmacnativewidget_mac.mm \
        widgets/qmaccocoaviewcontainer_mac.mm
}
