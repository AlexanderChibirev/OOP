// Lab6Task1Var7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HttpUrl.h"

using namespace std;

void WorkWithUser() 
{
	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		string url;
		cin >> url;
		try
		{
			CHttpUrl urls(url);
			cout << "protocol: " << urls.GetProtocol() << endl;
			cout << "domain: " << urls.GetDomain() << endl;
			cout << "port: " << urls.GetPort() << endl;
			cout << "document: " << urls.GetDocument() << endl;
		}
		catch (CUrlParsingError)
		{
			cout << "invalid_argument" << endl;
		}
	}
}

int main()
{
	WorkWithUser();
	return 0;
}

