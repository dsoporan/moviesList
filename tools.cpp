#include "Header.h"

//Check if a title of a movie is unique
int checkUnique(vector<Movie> moviesArr, string title)
{
	for (auto movie: moviesArr)
	{
		if (title == movie.getTitle())
			return -1;
	}
	return 1;
}

//Adding movie in Dynamic Array
int addingMovie(vector<Movie> &moviesArr)
{
	UI ui;
	Movie m;
	try
	{
		m = ui.readMovie();
	}
	catch (exception &e)
	{
		cout << e.what() << "\n";
		return 0;
	}

	if (m.getTitle() == "0")
		return 0;

	if (checkUnique(moviesArr, m.getTitle()) == -1)
	{
		cout << "Title already exist\n";
		return 0;
	}
	moviesArr.push_back(m);
	cout << "Successfully added\n";
	return 1;
}

// Returning an index of a title of a movie
int indexMovie(vector<Movie> moviesArr, string ti)
{
	int i = 0;
	for (auto movie: moviesArr)
	{
		if (ti == movie.getTitle())
			return i;
		i++;
	}
	return -1;
}

//Deleting a movie by index from Dynamic Array
int deleteMovie(vector<Movie> &moviesArr, int idx)
{
	moviesArr.erase(moviesArr.begin() + idx);
	return 1;
}

//Updating a movie
int updateMovie(vector<Movie> &moviesArr, int idx)
{
	UI ui;
	Movie m = ui.updateMovie();

	moviesArr[idx].setTitle(m.getTitle());
	moviesArr[idx].setGenre(m.getGenre());
	moviesArr[idx].setYear(m.getYear());
	moviesArr[idx].setLikes(m.getLikes());
	moviesArr[idx].setTrailer(m.getTrailer());
	moviesArr[idx].setMinutes(m.getMinutes());
	return 1;
}


void displayAll(vector<Movie> moviesArr)
{
	int i = 0;
	for (auto movie: moviesArr)
	{
		cout << i << ".\n";
		movie.print();
		cout << "\n";
		i++;
	}
}