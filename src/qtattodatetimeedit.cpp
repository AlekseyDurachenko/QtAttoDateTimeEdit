// Copyright (C) 2014, Durachenko Aleksey V. <durachenko.aleksey@gmail.com>
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
#include "qtattodatetimeedit.h"
#include <QLineEdit>

QtAttoDateTimeEdit::QtAttoDateTimeEdit(QWidget *parent) :
        QAbstractSpinBox(parent)
{
    setDateTime(QtAttoDateTime());
}

QtAttoDateTime QtAttoDateTimeEdit::dateTime() const
{
    return dateTimeFromText(lineEdit()->text());
}

void QtAttoDateTimeEdit::setDateTime(const QtAttoDateTime &dateTime)
{
    lineEdit()->setText(textFromDateTime(dateTime));
}

QString QtAttoDateTimeEdit::textFromDateTime(QtAttoDateTime dateTime) const
{
    return QString("%1.%2")
            .arg(dateTime.toString("yyyy-MM-dd hh:mm:ss"))
            .arg(dateTime.microPersision(), 6, 10, QChar('0'));
}

QtAttoDateTime QtAttoDateTimeEdit::dateTimeFromText(const QString &text) const
{
    QDateTime dateTime = QDateTime::fromString(
            text.left(19), "yyyy-MM-dd hh:mm:ss");
    qint64 micro = text.right(6).toLongLong();
    return QtAttoDateTime(dateTime).addMicroSeconds(micro);
}
