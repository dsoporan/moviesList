#include "Header.h"

void Movie::setTitle(string ti)
{
	this->title = ti;
}

void Movie::setGenre(string gen)
{
	this->genre = gen;
}

void Movie::setYear(int yr)
{
	this->year = yr;
}

void Movie::setLikes(int likes)
{
	this->likes = likes;
}

void Movie::setTrailer(string tr)
{
	this->trailer = tr;
}

void Movie::setMinutes(int min)
{
	this->minutes = min;
}

string Movie::getTitle()
{
	return this->title;
}

string Movie::getGenre()
{
	return this->genre;
}

string Movie::getTrailer()
{
	return this->trailer;
}

int Movie::getLikes()
{
	return this->likes;
}

int Movie::getYear()
{
	return this->year;
}

void Movie::incLikes()
{
	this->likes++;
}

int Movie::getMinutes()
{
	return this->minutes;
}

bool Movie::operator<(int val)
{
	if (this->minutes < val)
		return true;
	return false;
}

//Creating a movie from parameters
Movie Movie::constructMovie(string title, string genre, int year, int likes, string trailer, int minutes)
{
	Movie m;
	m.setTitle(title);
	m.setGenre(genre);
	m.setYear(year);
	m.setLikes(likes);
	m.setTrailer(trailer);
	m.setMinutes(minutes);

	return m;
}

void Movie::print()
{
	cout << "Title:" << this->title << "\n";
	cout << "Genre:" << this->genre << "\n";
	cout << "Year:" << this->year << "\n";
	cout << "Likes:" << this->likes << "\n";
	cout << "Trailer: " << this->trailer << "\n";
	cout << "Minutes: " << this->minutes << "\n";
}

void Movie::printBrowser()
{
	cout << "Title:" << this->title << "\n";
	cout << "Genre:" << this->genre << "\n";
	cout << "Year:" << this->year << "\n";
	cout << "Likes:" << this->likes << "\n";
	cout << "Minutes: " << this->minutes << "\n";
	cout << "Trailer: \n";
	//ShellExecute(0, 0, this->trailer.c_str(), 0, 0, SW_SHOW);
}

void testMovieClass()
{
	Movie m = m.constructMovie("Pistruiatul", "Comedie", 1980, 10002, "https://www.youtube.com/watch?v=SqGewEjmMKM", 10);
	m.setTitle("aaa");
	m.setGenre("bbb");
	m.setLikes(11);
	m.setTrailer("ccc.ccc");
	m.setYear(2000);
	m.setMinutes(1);
	assert(m.getTitle() == "aaa");
	assert(m.getGenre() == "bbb");
	assert(m.getLikes() == 11);
	assert(m.getTrailer() == "ccc.ccc");
	assert(m.getYear() == 2000);
	assert(m.getMinutes() == 1);
	m.incLikes();
	assert(m.getLikes() == 12);
}