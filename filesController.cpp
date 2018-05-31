#include "Header.h"

ostream& operator<<(ostream& os, const Movie& m) {
	os << m.title << ";" << m.genre << ";" << m.year << ';' << m.likes << ";" << m.trailer << ";" << m.minutes << ";\n";
	return os;
}

istream& operator>>(istream& is, Movie& m)
{
	string line;
	getline(is, line);
	string curword;
	vector<string> tokens;
	while (getline(is, curword, ';'))
		tokens.push_back(curword);
	if (tokens.size() == 6)
	{
		m.setTitle(tokens[0]);
		m.setGenre(tokens[1]);
		m.setYear(stoi(tokens[2]));
		m.setLikes(stoi(tokens[3]));
		m.setTrailer(tokens[4]);
		m.setMinutes(stoi(tokens[5]));

	}
	return is;
}

//Initializing Dynamic Array with movies
void initialize(vector<Movie> &movieArr)
{
	int i = 1, check = 1;
	Movie m;
	Validator valid;
	string line;
	ifstream f("database.txt");
	if (f.is_open())
	{
		while (getline(f, line, ';'))
		{
			if (i == 7)
			{
				i = 1;
				movieArr.push_back(m);
			}
			if (i == 1)
			{
				if (check == 0)
				{
					line.erase(line.begin());
					check = 0;
				}
				m.setTitle(line);
				i++;
				check = 0;
			}
			else if (i == 2)
			{
				m.setGenre(line);
				i++;
			}
			else if (i == 3)
			{
				try
				{
					stoi(line);
				}
				catch (const exception &e)
				{
					throw Exception{ "Not an integer" };
					return;
				}
				m.setYear(stoi(line));
				i++;
			}
			else if (i == 4)
			{
				try
				{
					stoi(line);
				}
				catch (const exception &e)
				{
					throw Exception{ "Not an integer" };
					return;
				}
				m.setLikes(stoi(line));
				i++;
			}
			else if (i == 5)
			{
				m.setTrailer(line);
				i++;
			}
			else if (i == 6)
			{
				try
				{
					stoi(line);
				}
				catch (const exception &e)
				{
					throw Exception{ "Not an integer" };
					return;
				}
				m.setMinutes(stoi(line));
				i++;
			}
		}
		movieArr.push_back(m);
		f.close();
	}
	else
		throw Exception{ "Not opened correctly" };
}

void writingToFile(vector<Movie> moviesArr)
{
	int i = 0;
	ofstream g("database.txt");
	for (auto movie : moviesArr)
	{
		if (i != moviesArr.size() - 1)
		{
			g << movie.getTitle() << ";";
			g << movie.getGenre() << ";";
			g << movie.getYear() << ";";
			g << movie.getLikes() << ";";
			g << movie.getTrailer() << ";";
			g << movie.getMinutes() << ";\n";
		}
		else
		{
			g << movie.getTitle() << ";";
			g << movie.getGenre() << ";";
			g << movie.getYear() << ";";
			g << movie.getLikes() << ";";
			g << movie.getTrailer() << ";";
			g << movie.getMinutes() << ";";
		}
		i++;
	}
	g.close();
}