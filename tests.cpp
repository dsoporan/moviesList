#include "Header.h"

void testIndexMovie(vector<Movie> moviesArr)
{
	int i;
	i = indexMovie(moviesArr, "Fast and furious 8");
	assert(i == 8);
	i = indexMovie(moviesArr, "Blabla");
	assert(i == -1);
}

void testCheckUnique(vector<Movie> moviesArr)
{
	int i;
	i = checkUnique(moviesArr, "Payback");
	assert(i == -1);
	i = checkUnique(moviesArr, "Blabla");
	assert(i == 1);
}

void testAll(vector<Movie> moviesArr)
{
	testIndexMovie(moviesArr);
	testCheckUnique(moviesArr);
	assert(moviesArr[0].getTitle() == "Pistruiatul");
	assert(addingMovie(moviesArr) == 1);
	assert(updateMovie(moviesArr, 0) == 1);
	assert(deleteMovie(moviesArr, 0) == 1);
	assert(rateMovie(moviesArr, "Payback") == 1);
}
