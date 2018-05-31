#include "Header.h"

// Copying movies with a specified genre
int getMoviesByGenre(vector<Movie> moviesArr, vector<Movie> &moviesArr2, string genre)
{
	if (genre == "*")
		moviesArr2 = moviesArr;
	else
		for (auto movie : moviesArr)
		{
			if (movie.getGenre() == genre)
				moviesArr2.push_back(movie);
		}
		//auto it = copy_if(moviesArr.begin(), moviesArr.end(), moviesArr2.begin(), [](string genre, Movie m) {return (genre == m.getGenre()); });
	return 1;
}

// Print current movie
void printCurrent(vector<Movie> moviesArr, int idx)
{
	moviesArr[idx].printBrowser();
}

//Going to the next movie
void next(vector<Movie> moviesArr, int &curr)
{
	if (curr == moviesArr.size() - 1)
		curr = 0;
	else
		curr++;
}

// Incrementing likes
int rateMovie(vector<Movie> &moviesArr, string title)
{
	for (auto movie: moviesArr)
	{
		if (movie.getTitle() == title)
		{
			movie.incLikes();
			return 1;
		}
	}
	return 0;
}

// Emptying Dynamic Array
void emptyArray(vector<Movie> &moviesArr)
{
	moviesArr.erase(moviesArr.begin(), moviesArr.end());
}