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
		throw CUrlParsingError("incorrect_url");
	}
}
CHttpUrl::CHttpUrl(const string &protocol, const string & domain, unsigned short port, const string & document)
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
	if (!domain.empty())
	{
		m_domain = domain;
	}
	else
	{
		throw CUrlParsingError("incorrect_domain");
	}
}
void CHttpUrl::SetDocument(const string & document)
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
		throw CUrlParsingError("incorrect_protocol");
	}
}

void CHttpUrl::SetPort(const string & port)
{
	try
	{
		if (!port.empty())
		{
			unsigned short integerPort = boost::lexical_cast<unsigned short>(port);
			if (integerPort > 0)
			{
				m_port = integerPort;
			}
		}
		else
		{
			if (m_protocol == HTTP)
			{
				m_port = 80;
			}
			else 
			{
				m_port = 443;
			}
		}
	}
	catch (boost::bad_lexical_cast &)
	{
		throw CUrlParsingError("incorrect_port");
	}
}

void CHttpUrl::SetPort(const unsigned int port)
{
	if (port > 0)
	{
		m_port = port;
	}
	else 
	{
		throw CUrlParsingError("incorrect_port");
	}
}