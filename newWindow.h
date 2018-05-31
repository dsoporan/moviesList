#pragma once

#include <QWidget>
#include "ui_newWindow.h"

class newWindow : public QWidget
{
	Q_OBJECT

public:
	newWindow(QWidget *parent = Q_NULLPTR);
	~newWindow();

private:
	Ui::newWindow ui;
};
