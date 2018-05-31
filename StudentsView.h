#pragma once

#include <QWidget>
#include "ui_StudentsView.h"
#include "StudentsModel.h"

class StudentsView : public QWidget
{
	Q_OBJECT

public:
	StudentsView(StudentsModel* m, QWidget *parent = Q_NULLPTR);
	~StudentsView();

private:
	Ui::StudentsView ui;
	StudentsModel* model;
};
