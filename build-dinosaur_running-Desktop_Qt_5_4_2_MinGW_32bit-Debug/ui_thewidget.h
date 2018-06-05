/********************************************************************************
** Form generated from reading UI file 'thewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEWIDGET_H
#define UI_THEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TheWidget
{
public:

    void setupUi(QWidget *TheWidget)
    {
        if (TheWidget->objectName().isEmpty())
            TheWidget->setObjectName(QStringLiteral("TheWidget"));
        TheWidget->resize(400, 300);

        retranslateUi(TheWidget);

        QMetaObject::connectSlotsByName(TheWidget);
    } // setupUi

    void retranslateUi(QWidget *TheWidget)
    {
        TheWidget->setWindowTitle(QApplication::translate("TheWidget", "TheWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class TheWidget: public Ui_TheWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEWIDGET_H
