#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab1112_final.h"
#include "Header.h"

class Lab1112_final : public QMainWindow
{
	Q_OBJECT

public:
	Lab1112_final(QWidget *parent = Q_NULLPTR);
	void initializeTable(vector<Movie> moviesArr);
	void initializeWatchList();
	void initializeFiltering();
	void initializeFiltering2();
	void addToTable(Movie m);
	

private:
	vector<Movie> moviesArr;
	vector<Movie> watchList;
	vector<Movie> filterArr;
	vector<undoAction*> uA;
	vector<redoAction*> rA;
	int index = 0;

private slots:
	void addMovie();
	void deleteMovie2();
	void updateMovie2();
	void nextMovie();
	void clearLineEdit();
	void addWatchList();
	void toBrowser();
	void searching();
	void CSV();
	void HTML();
	void undo();
	void redo();

private:
	Ui::Lab1112_finalClass ui;
};
