#include "stdafx.h"
#include "UrlParsingError.h"


CUrlParsingError::CUrlParsingError(const string & errorMessage)
	: invalid_argument(errorMessage)
{
}
