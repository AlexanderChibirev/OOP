#pragma once

using namespace std;

static const string incorrect_url = "Incorrect url";
static const string incorrect_protocol = "Incorrect protocol";
static const string incorrect_port = "Incorrect port";
static const string incorrect_domain = "Incorrect domain";

class CUrlParsingError : public invalid_argument
{
public:
	CUrlParsingError(const string & errorMessage);
};

