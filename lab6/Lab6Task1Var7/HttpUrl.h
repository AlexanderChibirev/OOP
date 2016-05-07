#pragma once
#include "UrlParsingError.h"


enum Protocol
{
	HTTP = 80,
	HTTPS = 443
};

using namespace std;

class CHttpUrl
{
public:
	CHttpUrl(string const& url);
	CHttpUrl(	
		string const& domain,
		string const& document,
		Protocol protocol,
		unsigned short port);

	string GetURL() const;
	string GetDomain() const;
	string GetDocument() const;
	Protocol GetProtocol() const;
	unsigned short GetPort() const;
private:
	void SetDomain(const string & domain);
	void SetDocument(const string & document);
	void SetProtocol(const string & protocol);
	void SetProtocol(const Protocol & protocol);
	void SetPort(const string & port);
	void SetPort(const unsigned int port);
private:
	string m_url;
	string m_domain;
	string m_document;
	Protocol m_protocol;
	unsigned short m_port;
};
