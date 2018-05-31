#include "Lab1112_final.h"
#include "newWindow.h"
#include <QDesktopServices>
#include <string>
#include "StudentsModel.h"
#include "StudentsView.h"

Lab1112_final::Lab1112_final(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	initialize(this->moviesArr);
	
	initializeTable(this->moviesArr);
	initializeWatchList();
	initializeFiltering2();
	
	connect(ui.addPushButton, SIGNAL(clicked()), this, SLOT(addMovie()));
	connect(ui.removePushButton, SIGNAL(clicked()), this, SLOT(deleteMovie2()));
	connect(ui.updatePushButton, SIGNAL(clicked()), this, SLOT(updateMovie2()));
	connect(ui.nextPushButton, SIGNAL(clicked()), this, SLOT(nextMovie()));
	connect(ui.clearPushButton, SIGNAL(clicked()), this, SLOT(clearLineEdit()));
	connect(ui.toWatchPushButton, SIGNAL(clicked()), this, SLOT(addWatchList()));
	connect(ui.watchPushButton, SIGNAL(clicked()), this, SLOT(toBrowser()));
	connect(ui.exitPushButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui.activityLineEdit, &QLineEdit::textChanged, [this] { searching(); });
	connect(ui.CSVpushButton, SIGNAL(clicked()), this, SLOT(CSV()));
	connect(ui.HTMLpushButton, SIGNAL(clicked()), this, SLOT(HTML()));
	connect(ui.undoPushButton, SIGNAL(clicked()), this, SLOT(undo()));
	connect(ui.redoPushButton, SIGNAL(clicked()), this, SLOT(redo()));
	connect(ui.windowPushButton, &QPushButton::clicked, [this] {
		StudentsModel *model = new StudentsModel{ watchList };
		StudentsView da{ model };
		da.show();
		QEventLoop loop;
		connect(this, SIGNAL(destroyed()), &loop, SLOT(quit()));
		loop.exec();
	});

}

void  Lab1112_final::clearLineEdit()
{
	ui.titleLineEdit->clear();
	ui.genreLineEdit->clear();
	ui.yearLineEdit->clear();
	ui.likesLineEdit->clear();
	ui.trailerLineEdit->clear();
	ui.minutesLineEdit->clear();
}

void Lab1112_final::initializeTable(vector<Movie> moviesArr)
{
	int i;
	ui.allMoviesTableWidget->setColumnCount(6);
	ui.allMoviesTableWidget->setRowCount(moviesArr.size());

	ui.allMoviesTableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem(QString::fromStdString("Title")));
	ui.allMoviesTableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem(QString::fromStdString("Genre")));
	ui.allMoviesTableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem(QString::fromStdString("Year")));
	ui.allMoviesTableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem(QString::fromStdString("Likes")));
	ui.allMoviesTableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem(QString::fromStdString("Trailer")));
	ui.allMoviesTableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem(QString::fromStdString("Minutes")));

	for (i = 0; i < moviesArr.size(); i++)
	{
		ui.allMoviesTableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(moviesArr[i].getTitle())));
		ui.allMoviesTableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(moviesArr[i].getGenre())));
		ui.allMoviesTableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(to_string(moviesArr[i].getYear()))));
		ui.allMoviesTableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(to_string(moviesArr[i].getLikes()))));
		ui.allMoviesTableWidget->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(moviesArr[i].getTrailer())));
		ui.allMoviesTableWidget->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(to_string(moviesArr[i].getMinutes()))));
	}
}

void Lab1112_final::initializeWatchList()
{
	int i;
	ui.watchTableWidget->setColumnCount(6);
	ui.watchTableWidget->setRowCount(watchList.size());

	ui.watchTableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem(QString::fromStdString("Title")));
	ui.watchTableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem(QString::fromStdString("Genre")));
	ui.watchTableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem(QString::fromStdString("Year")));
	ui.watchTableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem(QString::fromStdString("Likes")));
	ui.watchTableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem(QString::fromStdString("Trailer")));
	ui.watchTableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem(QString::fromStdString("Minutes")));

	for (i = 0; i < watchList.size(); i++)
	{
		ui.watchTableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(watchList[i].getTitle())));
		ui.watchTableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(watchList[i].getGenre())));
		ui.watchTableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(to_string(watchList[i].getYear()))));
		ui.watchTableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(to_string(watchList[i].getLikes()))));
		ui.watchTableWidget->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(watchList[i].getTrailer())));
		ui.watchTableWidget->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(to_string(watchList[i].getMinutes()))));
	}
}

void Lab1112_final::initializeFiltering()
{
	int i;
	ui.activityTableWidget->setColumnCount(6);
	ui.activityTableWidget->setRowCount(filterArr.size());

	ui.activityTableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem(QString::fromStdString("Title")));
	ui.activityTableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem(QString::fromStdString("Genre")));
	ui.activityTableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem(QString::fromStdString("Year")));
	ui.activityTableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem(QString::fromStdString("Likes")));
	ui.activityTableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem(QString::fromStdString("Trailer")));
	ui.activityTableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem(QString::fromStdString("Minutes")));

	for (i = 0; i < filterArr.size(); i++)
	{
		ui.activityTableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(filterArr[i].getTitle())));
		ui.activityTableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(filterArr[i].getGenre())));
		ui.activityTableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(to_string(filterArr[i].getYear()))));
		ui.activityTableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(to_string(filterArr[i].getLikes()))));
		ui.activityTableWidget->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(filterArr[i].getTrailer())));
		ui.activityTableWidget->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(to_string(filterArr[i].getMinutes()))));
	}
}

void Lab1112_final::initializeFiltering2()
{
	int i;
	ui.activityTableWidget->setColumnCount(6);
	ui.activityTableWidget->setRowCount(moviesArr.size());

	ui.activityTableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem(QString::fromStdString("Title")));
	ui.activityTableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem(QString::fromStdString("Genre")));
	ui.activityTableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem(QString::fromStdString("Year")));
	ui.activityTableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem(QString::fromStdString("Likes")));
	ui.activityTableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem(QString::fromStdString("Trailer")));
	ui.activityTableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem(QString::fromStdString("Minutes")));

	for (i = 0; i < moviesArr.size(); i++)
	{
		ui.activityTableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(moviesArr[i].getTitle())));
		ui.activityTableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(moviesArr[i].getGenre())));
		ui.activityTableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(to_string(moviesArr[i].getYear()))));
		ui.activityTableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(to_string(moviesArr[i].getLikes()))));
		ui.activityTableWidget->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(moviesArr[i].getTrailer())));
		ui.activityTableWidget->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(to_string(moviesArr[i].getMinutes()))));
	}
}

void Lab1112_final::addWatchList()
{
	QString title = ui.titleLineEdit->text();
	QString genre = ui.genreLineEdit->text();
	QString year = ui.yearLineEdit->text();
	QString likes = ui.likesLineEdit->text();
	QString trailer = ui.trailerLineEdit->text();
	QString minutes = ui.minutesLineEdit->text();

	ui.titleLineEdit->clear();
	ui.genreLineEdit->clear();
	ui.yearLineEdit->clear();
	ui.likesLineEdit->clear();
	ui.trailerLineEdit->clear();
	ui.minutesLineEdit->clear();

	int idx = indexMovie(moviesArr, title.toStdString());

	if (idx == -1)
		return;

	ui.watchTableWidget->clear();
	Movie m = Movie{ title.toStdString(), genre.toStdString(), year.toInt(),  likes.toInt(), trailer.toStdString(),  minutes.toInt() };
	watchList.push_back(m);
	initializeWatchList();
}

void Lab1112_final::toBrowser()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", moviesArr[index].getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}

void Lab1112_final::addToTable(Movie m)
{
	int idx = ui.allMoviesTableWidget->rowCount();
	ui.allMoviesTableWidget->insertRow(idx);

	ui.allMoviesTableWidget->setItem(idx - 1, 0, new QTableWidgetItem(QString::fromStdString(m.getTitle())));
	ui.allMoviesTableWidget->setItem(idx - 1, 1, new QTableWidgetItem(QString::fromStdString(m.getGenre())));
	ui.allMoviesTableWidget->setItem(idx - 1, 2, new QTableWidgetItem(QString::fromStdString(to_string(m.getYear()))));
	ui.allMoviesTableWidget->setItem(idx - 1, 3, new QTableWidgetItem(QString::fromStdString(to_string(m.getLikes()))));
	ui.allMoviesTableWidget->setItem(idx - 1, 4, new QTableWidgetItem(QString::fromStdString(m.getTrailer())));
	ui.allMoviesTableWidget->setItem(idx - 1, 5, new QTableWidgetItem(QString::fromStdString(to_string(m.getMinutes()))));

}

void Lab1112_final::searching()
{
	int i;
	QString s1 = ui.activityLineEdit->text();
	if (!s1.isEmpty())
	{
		string s;
		s = s1.toStdString();
		for (i = 0; i < moviesArr.size(); i++)
		{
			if (moviesArr[i].getTitle().find(s) != string::npos || moviesArr[i].getGenre().find(s) != string::npos || to_string(moviesArr[i].getYear()).find(s) != string::npos || to_string(moviesArr[i].getLikes()).find(s) != string::npos || to_string(moviesArr[i].getMinutes()).find(s) != string::npos || moviesArr[i].getTrailer().find(s) != string::npos)
				filterArr.push_back(moviesArr[i]);

		}
		ui.activityTableWidget->clear();
		initializeFiltering();
		filterArr.clear();
	}
	else
	{
		ui.activityTableWidget->clear();
		initializeFiltering2();
	}
}

void Lab1112_final::CSV()
{
	FileSaver *saver = new CSVType{ watchList };
	saver->writeToFile(watchList);
}

void Lab1112_final::HTML()
{
	FileSaver *saver = new HTMLType{ watchList };
	saver->writeToFile(watchList);
}

void Lab1112_final::undo()
{
	if (uA.size() > 0)
	{
		uA.back()->executeUndo(moviesArr);
		uA.pop_back();
		initializeTable(this->moviesArr);
		writingToFile(moviesArr);
	}
	else
		ui.titleUpdateLineEdit->setText("Cannot perform UNDO anymore");

}

void Lab1112_final::redo()
{
	if (rA.size() > 0)
	{
		rA.back()->executeRedo(moviesArr);
		rA.pop_back();
		initializeTable(this->moviesArr);
		writingToFile(moviesArr);
	}
	else
		ui.titleUpdateLineEdit->setText("Cannot perform REDO anymore");

}

void Lab1112_final::deleteMovie2()
{
	QString title = ui.titleLineEdit->text();
	int idx = indexMovie(moviesArr, title.toStdString());

	ui.titleLineEdit->clear();
	ui.genreLineEdit->clear();
	ui.yearLineEdit->clear();
	ui.likesLineEdit->clear();
	ui.trailerLineEdit->clear();
	ui.minutesLineEdit->clear();

	if (idx == -1)
		return;

	undoAction *a = new UndoRemove{ moviesArr, moviesArr[idx] };
	uA.push_back(a);

	redoAction *b = new redoRemove{ moviesArr, moviesArr[idx] };
	rA.push_back(b);

	deleteMovie(moviesArr, idx);
	writingToFile(moviesArr);

	ui.allMoviesTableWidget->removeRow(idx);
}

void Lab1112_final::updateMovie2()
{
	QString title = ui.titleLineEdit->text();
	QString genre = ui.genreLineEdit->text();
	QString year = ui.yearLineEdit->text();
	QString likes = ui.likesLineEdit->text();
	QString trailer = ui.trailerLineEdit->text();
	QString minutes = ui.minutesLineEdit->text();
	QString title2 = ui.titleUpdateLineEdit->text();
	int idx = indexMovie(moviesArr, title2.toStdString());

	ui.titleUpdateLineEdit->clear();
	ui.titleLineEdit->clear();
	ui.genreLineEdit->clear();
	ui.yearLineEdit->clear();
	ui.likesLineEdit->clear();
	ui.trailerLineEdit->clear();
	ui.minutesLineEdit->clear();

	undoAction *a = new UndoUpdate{ moviesArr, moviesArr[idx], title.toStdString() };
	uA.push_back(a);

	ui.allMoviesTableWidget->setItem(idx, 0, new QTableWidgetItem(title));
	ui.allMoviesTableWidget->setItem(idx, 1, new QTableWidgetItem(genre));
	ui.allMoviesTableWidget->setItem(idx, 2, new QTableWidgetItem(year));
	ui.allMoviesTableWidget->setItem(idx, 3, new QTableWidgetItem(likes));
	ui.allMoviesTableWidget->setItem(idx, 4, new QTableWidgetItem(trailer));
	ui.allMoviesTableWidget->setItem(idx, 5, new QTableWidgetItem(minutes));

	moviesArr[idx].setTitle(title.toStdString());
	moviesArr[idx].setGenre(genre.toStdString());
	moviesArr[idx].setYear(year.toInt());
	moviesArr[idx].setLikes(likes.toInt());
	moviesArr[idx].setTrailer(trailer.toStdString());
	moviesArr[idx].setMinutes(minutes.toInt());

	redoAction *b = new redoUpdate{ moviesArr, moviesArr[idx], title2.toStdString() };
	rA.push_back(b);

	writingToFile(moviesArr);

}

void Lab1112_final::nextMovie()
{
	ui.titleUpdateLineEdit->clear();
	ui.titleLineEdit->clear();
	ui.genreLineEdit->clear();
	ui.yearLineEdit->clear();
	ui.likesLineEdit->clear();
	ui.trailerLineEdit->clear();
	ui.minutesLineEdit->clear();

	ui.titleLineEdit->setText(QString::fromStdString(moviesArr[index].getTitle()));
	ui.genreLineEdit->setText(QString::fromStdString(moviesArr[index].getGenre()));
	ui.yearLineEdit->setText(QString::number(moviesArr[index].getYear()));
	ui.likesLineEdit->setText(QString::number(moviesArr[index].getLikes()));
	ui.trailerLineEdit->setText(QString::fromStdString(moviesArr[index].getTrailer()));
	ui.minutesLineEdit->setText(QString::number(moviesArr[index].getMinutes()));
	if (index == moviesArr.size() - 1)
		this->index = 0;
	this->index++;
}

void Lab1112_final::addMovie()
{
	QString title = ui.titleLineEdit->text();
	QString genre = ui.genreLineEdit->text();
	QString year = ui.yearLineEdit->text();
	QString likes = ui.likesLineEdit->text();
	QString trailer = ui.trailerLineEdit->text();
	QString minutes = ui.minutesLineEdit->text();

	ui.titleLineEdit->clear();
	ui.genreLineEdit->clear();
	ui.yearLineEdit->clear();
	ui.likesLineEdit->clear();
	ui.trailerLineEdit->clear();
	ui.minutesLineEdit->clear();

	int idx = indexMovie(moviesArr, title.toStdString());

	if (idx != -1)
		return;

	ui.allMoviesTableWidget->clear();
	Movie m = Movie{ title.toStdString(), genre.toStdString(), year.toInt(),  likes.toInt(), trailer.toStdString(),  minutes.toInt() };
	
	undoAction *a = new UndoAdd{ moviesArr, m };
	uA.push_back(a);

	redoAction *b = new redoAdd{ moviesArr, m };
	rA.push_back(b);

	moviesArr.push_back(m);
	writingToFile(moviesArr);
	initializeTable(moviesArr);
}
