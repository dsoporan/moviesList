#include "StudentsView.h"

StudentsView::StudentsView(StudentsModel* m, QWidget *parent)
	: QWidget(parent), model{m}
{
	ui.setupUi(this);

	ui.studentsTableView->setModel(this->model);
}

StudentsView::~StudentsView()
{
}
