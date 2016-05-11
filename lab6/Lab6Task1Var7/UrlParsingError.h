#pragma once

using namespace std;


class CUrlParsingError : public invalid_argument
{
public:
	CUrlParsingError(const string & errorMessage);
};

