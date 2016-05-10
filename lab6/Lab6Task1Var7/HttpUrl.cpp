#include "stdafx.h"
#include "HttpUrl.h"

CHttpUrl::CHttpUrl(string const& url)
	: m_url(url)
{
	boost::regex ex("(http|https)://([^/ :]+):?([^/ ]*)(/?[^ #?]*)");
	boost::cmatch urlParts;
	if (regex_match(url.c_str(), urlParts, ex))
	{
		SetProtocol(boost::lexical_cast<string>(urlParts[1]));
		SetDomain(boost::lexical_cast<string>(urlParts[2]));
		SetPort(boost::lexical_cast<string>(urlParts[3]));
		SetDocument(boost::lexical_cast<string>(urlParts[4]));
	}
	else
	{
		throw CUrlParsingError(incorrect_url);
	}
}
CHttpUrl::CHttpUrl(string const& domain, string const& document, Protocol protocol, unsigned short port)
{
	SetProtocol(protocol);
	SetPort(port);
	SetDomain(domain);
	SetDocument(document);
}
std::string CHttpUrl::GetURL()const
{
	return m_url;
}
std::string CHttpUrl::GetDomain()const
{
	return m_domain;
}
std::string CHttpUrl::GetDocument()const
{
	return m_document;
}
Protocol CHttpUrl::GetProtocol()const
{
	return m_protocol;
}
unsigned short CHttpUrl::GetPort()const
{
	return m_port;
}

void CHttpUrl::SetDomain(const string & domain)
{
	boost::regex ex("/^([0-9a-z]([0-9a-z\-])*[0-9a-z]\.)+[0-9a-z\-]{1,8}$/i");
	boost::cmatch urlParts;
	if (boost::regex_match(domain.c_str(), urlParts, ex))
	{
		cout << urlParts[1];
	}
	else
	{
		throw CUrlParsingError(incorrect_url);
	}
	m_domain = domain;
}
void CHttpUrl::SetDocument(const string & document)
{
	if (!document.empty())
	{
		if (document[0] != '/')
		{
			m_document = '/' + document;
		}
		else 
		{
			m_document = document;
		}
	}
}
void CHttpUrl::SetProtocol(const string & protocol)
{
	if (protocol == "http")
	{
		m_protocol = HTTP;
	}
	else if (protocol == "https")
	{
		m_protocol = HTTPS;
	}
	else
	{
		throw CUrlParsingError(incorrect_protocol);
	}
}

void  CHttpUrl::SetProtocol(const Protocol & protocol)
{
	if (protocol == HTTP) 
	{
		m_protocol = HTTP;
	}
	else if (protocol == HTTPS)
	{
		m_protocol = HTTPS;
	}
	else 
	{
		throw CUrlParsingError(incorrect_protocol);
	}
}

void CHttpUrl::SetPort(const string & port)
{
	try
	{
		if (!port.empty())
		{
			unsigned short integerPort = boost::lexical_cast<unsigned short>(port);
			if (integerPort >= 0)
			{
				m_port = integerPort;
			}
		}
	}
	catch (boost::bad_lexical_cast &)
	{
		throw CUrlParsingError(incorrect_port);
	}
}
void CHttpUrl::SetPort(const unsigned int port)
{
	m_port = port;
}