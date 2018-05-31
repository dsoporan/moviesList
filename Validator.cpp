#include "Header.h"

MovieException::MovieException(vector<string> _errors) : errors{ _errors }
{

}

vector<string> MovieException::getErrors() const
{
	return this->errors;
}

void Validator::validate(Movie m)
{
	vector<string> errors;
	if (m.getTitle().size() < 3)
		errors.push_back("The title name cannot be less than 2 characters!\n");
	if (!isupper(m.getGenre()[0]))
		errors.push_back(string("The name of the artist must start with a capital letter!\n"));
	if (m.getMinutes() == 0)
		errors.push_back(string("The duration cannot be 0!\n"));

	size_t posWww = m.getTrailer().find("www");
	size_t posHttp = m.getTrailer().find("http");
	if (posWww != 0 && posHttp != 0)
		errors.push_back("The youtube source must start with one of the following strings: \"www\" or \"http\"");

	if (errors.size() > 0)
		throw MovieException(errors);
}