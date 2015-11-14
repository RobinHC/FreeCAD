/***************************************************************************
 *   Copyright (c) 2013 Jan Rheinländer <jrheinlaender@users.sourceforge.net>        *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/


#ifndef GUI_TASKVIEW_TaskFemConstraintSymmetry_H
#define GUI_TASKVIEW_TaskFemConstraintSymmetry_H

#include <Gui/TaskView/TaskView.h>
#include <Gui/Selection.h>
#include <Gui/TaskView/TaskDialog.h>

#include "TaskFemConstraint.h"
#include "ViewProviderFemConstraintSymmetry.h"

class Ui_TaskFemConstraintSymmetry;

namespace App {
class Property;
}

namespace Gui {
class ViewProvider;
}

namespace FemGui {

class TaskFemConstraintSymmetry : public TaskFemConstraint
{
    Q_OBJECT

public:
    TaskFemConstraintSymmetry(ViewProviderFemConstraintSymmetry *ConstraintView,QWidget *parent = 0);
    virtual ~TaskFemConstraintSymmetry();

    virtual const std::string getReferences() const;

private Q_SLOTS:
    void onReferenceDeleted(void);

protected:
    virtual void changeEvent(QEvent *e);

private:
    virtual void onSelectionChanged(const Gui::SelectionChanges& msg);

private:
    Ui_TaskFemConstraintSymmetry* ui;
};

/// simulation dialog for the TaskView
class TaskDlgFemConstraintSymmetry : public TaskDlgFemConstraint
{
    Q_OBJECT

public:
    TaskDlgFemConstraintSymmetry(ViewProviderFemConstraintSymmetry *ConstraintView);

    /// is called by the framework if the dialog is accepted (Ok)
    virtual bool accept();

};

} //namespace FemGui

#endif // GUI_TASKVIEW_TaskFemConstraintSymmetry_H
