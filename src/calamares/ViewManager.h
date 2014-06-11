/* === This file is part of Calamares - <http://github.com/calamares> ===
 *
 *   Copyright 2014, Teo Mrnjavac <teo@kde.org>
 *
 *   Calamares is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Calamares is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Calamares. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include "DllMacro.h"
#include "viewpages/PagePlugin.h"

#include <QPushButton>
#include <QStackedWidget>

namespace Calamares
{

class UIDLLEXPORT ViewManager : public QObject
{
    Q_OBJECT
public:
    static ViewManager* instance();

    explicit ViewManager( QObject* parent = 0 );
    virtual ~ViewManager();

    QWidget* widget();

    void addPagePlugin( PagePlugin* plugin );

    void insertPage( AbstractPage* page );
    void setNext( AbstractPage* page );
    void removePage( AbstractPage* page );

public slots:
    void next();
    void back();

private:
    static ViewManager* s_instance;

    QWidget* m_widget;
    QStackedWidget* m_stack;
    QPushButton* m_back;
    QPushButton* m_next;
};

}

#endif // VIEWMANAGER_H
