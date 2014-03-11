QtAttoDateTimeEdit
==================

The QtDateTimeEdit class provides a widget for editing the QtAttoDateTime

![Screenshot](https://raw.github.com/AlekseyDurachenko/QtAttoDateTimeEdit/master/qtattodatetimeedit.png)

Usage
=====
- clone the repository: git clone https://github.com/AlekseyDurachenko/QtAttoDateTimeEdit.git lib/qtattodatetimeedit
- add the line to the .pro file: include($$PWD/lib/qtattodatetimeedit/qtattodatetimeedit.pri)

Example
=======
    #include <QApplication>
    #include <QtAttoDateTimeEdit>

    int main(int argc, char *argv[])
    {
        QApplication app(argc, argv);

        QtAttoDateTimeEdit widget;
        widget.resize(200, 20);
        widget.show();

        return app.exec();
    }

Depencencies
============
- https://github.com/AlekseyDurachenko/QtAttoDateTime
