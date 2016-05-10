#include "stdafx.h"
#include "UrlParsingError.h"


CUrlParsingError::CUrlParsingError(const string & errorMessage)
	: invalid_argument(errorMessage)
{
	if (errorMessage == incorrect_url)
	{
		cout << incorrect_url << endl;
	}
	else if (errorMessage == incorrect_protocol)
	{
		cout << incorrect_protocol << endl;
	}
	else if (errorMessage == incorrect_port)
	{
		cout << incorrect_port << endl;
	}
}
