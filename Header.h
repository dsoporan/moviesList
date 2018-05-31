#pragma once
#include <iostream>
#include <string> 
#include <Windows.h>
#include <crtdbg.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Movie
{
private:
	string title;
	string genre;
	int year;
	int likes;
	string trailer;
	int minutes;

public:
	Movie()
	{
	}
	~Movie()
	{
	}
	Movie(string title, string genre, int year, int likes, string trailer, int min)
	{
		this->title = title;
		this->genre = genre;
		this->year = year;
		this->likes = likes;
		this->trailer = trailer;
		this->minutes = min;
	}
	Movie constructMovie(string title, string genre, int year, int likes, string trailer, int minutes);
	void print();
	void printBrowser();
	void setTitle(string ti);
	void setGenre(string gen);
	void setYear(int yr);
	void setLikes(int likes);
	void setTrailer(string tr);
	void setMinutes(int min);
	string getTitle();
	string getGenre();
	string getTrailer();
	int getLikes();
	int getYear();
	void incLikes();
	int getMinutes();
	bool operator<(int val);
	friend istream& operator>>(istream& is, Movie& s);
	friend ostream& operator<<(ostream& os, const Movie& s);
};

class UI
{
public:
	void menu();
	void menu2();
	void menu3();
	Movie readMovie();
	Movie updateMovie();
};

class Exception : public std::runtime_error
{
private:
	std::string message;

public:
	Exception(const std::string& m) : runtime_error{ m } {}
	std::string getMessage() const { return message; }

	const char* what() { return message.c_str(); }
};

class MovieException
{
private:
	vector<string> errors;

public:
	MovieException() {};
	MovieException(vector<string> _errors);
	vector<string> getErrors() const;
};

class Validator
{
public:
	Validator() {}
	static void validate(Movie m);
};

class FileSaver
{
public:
	virtual void writeToFile(vector<Movie> moviesArr) = 0;
	virtual ~FileSaver() {};
};

class CSVType : public FileSaver
{
private:
	vector<Movie> moviesArrCSV;
public:
	void writeToFile(vector<Movie> moviesArr);
	CSVType() {};
	CSVType(vector<Movie> mov)
	{
		this->moviesArrCSV = mov;
	}
	~CSVType() {};
};

class HTMLType : public FileSaver
{
private:
	vector<Movie> moviesArrHTML;
public:
	void writeToFile(vector<Movie> moviesArr);
	HTMLType() {};
	HTMLType(vector<Movie> m)
	{
		this->moviesArrHTML = m;
	}
	~HTMLType() {};
};

int indexMovie(vector<Movie> moviesArr, string ti);

class undoAction
{
public:
	virtual void executeUndo(vector<Movie> &movArr) = 0;
	virtual ~undoAction() {};
};

class UndoAdd : public undoAction
{
private:
	Movie addedMovie;
	vector<Movie> moviesArr;
public:
	UndoAdd()
	{

	}
	UndoAdd(vector<Movie> movArr, Movie m)
	{
		this->addedMovie = m;
		this->moviesArr = movArr;
	}
	~UndoAdd()
	{

	}
	void executeUndo(vector<Movie> &movArr)
	{
		int idx = indexMovie(movArr, addedMovie.getTitle());
		movArr.erase(movArr.begin() + idx);
	}
};

class UndoRemove : public undoAction
{
private:
	Movie deletedMovie;
	vector<Movie> moviesArr;
public:
	UndoRemove()
	{

	}
	UndoRemove(vector<Movie> movArr, Movie m)
	{
		this->deletedMovie = m;
		this->moviesArr = movArr;
	}
	~UndoRemove()
	{

	}
	void executeUndo(vector<Movie> &movArr)
	{
		movArr.push_back(deletedMovie);
	}
};

class UndoUpdate : public undoAction
{
private:
	Movie updatedMovie;
	vector<Movie> moviesArr;
	string title;
public:
	UndoUpdate()
	{

	}
	UndoUpdate(vector<Movie> movArr, Movie m, string ti)
	{
		this->updatedMovie = m;
		this->moviesArr = movArr;
		this->title = ti;
	}
	~UndoUpdate()
	{

	}
	void executeUndo(vector<Movie> &movArr)
	{
		int idx = indexMovie(movArr, title);
		movArr[idx] = updatedMovie;
	}
};


class redoAction
{
public:
	virtual void executeRedo(vector<Movie> &movArr) = 0;
	virtual ~redoAction() {};
};

class redoAdd : public redoAction
{
private:
	Movie addedMovie;
	vector<Movie> moviesArr;
public:
	redoAdd()
	{

	}
	redoAdd(vector<Movie> movArr, Movie m)
	{
		this->addedMovie = m;
		this->moviesArr = movArr;
	}
	~redoAdd()
	{

	}
	void executeRedo(vector<Movie> &movArr)
	{
		movArr.push_back(addedMovie);
	}
};

class redoRemove : public redoAction
{
private:
	Movie deletedMovie;
	vector<Movie> moviesArr;
public:
	redoRemove()
	{

	}
	redoRemove(vector<Movie> movArr, Movie m)
	{
		this->deletedMovie = m;
		this->moviesArr = movArr;
	}
	~redoRemove()
	{

	}
	void executeRedo(vector<Movie> &movArr)
	{
		int idx = indexMovie(movArr, deletedMovie.getTitle());
		movArr.erase(movArr.begin() + idx);
	}
};

class redoUpdate : public redoAction
{
private:
	Movie updatedMovie;
	vector<Movie> moviesArr;
	string title;
public:
	redoUpdate()
	{

	}
	redoUpdate(vector<Movie> movArr, Movie m, string ti)
	{
		this->updatedMovie = m;
		this->moviesArr = movArr;
		this->title = ti;
	}
	~redoUpdate()
	{

	}
	void executeRedo(vector<Movie> &movArr)
	{
		int idx = indexMovie(movArr, title);
		movArr[idx] = updatedMovie;
	}
};

void testMovieClass();
void initialize(vector<Movie> &movieArr);
int checkUnique(vector<Movie> moviesArr, string title);
int addingMovie(vector<Movie> &moviesArr);
int deleteMovie(vector<Movie> &moviesArr, int idx);
int updateMovie(vector<Movie> &moviesArr, int idx);
void displayAll(vector<Movie> moviesArr);
int getMoviesByGenre(vector<Movie> moviesArr, vector<Movie> &moviesArr2, string genre);
void printCurrent(vector<Movie> moviesArr, int idx);
void next(vector<Movie> moviesArr, int &curr);
int rateMovie(vector<Movie> &moviesArr, string title);
void emptyArray(vector<Movie> &moviesArr);
void testIndexMovie(vector<Movie> moviesArr);
void testCheckUnique(vector<Movie> moviesArr);
void testAll(vector<Movie> moviesArr);
void printToFile(Movie mov);
void writingToFile(vector<Movie> moviesArr);