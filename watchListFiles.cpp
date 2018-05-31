#include "Header.h"

void CSVType::writeToFile(vector<Movie> moviesArr)
{
	int i = 0;
	ofstream g("CSVfile.csv");
	for (auto movie : moviesArr)
	{
		if (i != moviesArr.size() - 1)
		{
			g << movie.getTitle() << ",";
			g << movie.getGenre() << ",";
			g << movie.getYear() << ",";
			g << movie.getLikes() << ",";
			g << movie.getTrailer() << ",";
			g << movie.getMinutes() << ",\n";
		}
		else
		{
			g << movie.getTitle() << ",";
			g << movie.getGenre() << ",";
			g << movie.getYear() << ",";
			g << movie.getLikes() << ",";
			g << movie.getTrailer() << ",";
			g << movie.getMinutes() << ",";
		}
		i++;
	}
	g.close();
}

void HTMLType::writeToFile(vector<Movie> moviesArr)
{
	ofstream g("HTMLfile.html");
	g << "<!DOCTYPE html>\n";
	g << "<html>\n";
	g << "<head>\n";
	g << "<title>WatchList movies</title>\n";
	g << "</head>\n";
	g << "<body>\n";
	g << "<table border = '1'>\n";
	g << "<tr>\n";
	g << "<td>Title</td>\n";
	g << "<td>Genre</td>\n";
	g << "<td>Year</td>\n";
	g << "<td>Likes</td>\n";
	g << "<td>Link</td>\n";
	g << "</tr>\n";
	for (auto movie : moviesArr)
	{
		g << "<tr>\n";
		g << "<td>" << movie.getTitle() << "</td>\n";
		g << "<td>" << movie.getGenre() << "</td>\n";
		g << "<td>" << movie.getYear() << "</td>\n";
		g << "<td>" << movie.getLikes() << "</td>\n";
		g << "<td><a href =" << '"' << movie.getTrailer() << '"' << ">Link</a></td>\n";
		g << "</tr>\n";
	}
	g << "</table>\n";
	g << "</body>\n";
	g << "</html>\n";
}