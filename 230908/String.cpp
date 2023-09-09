#include "pch.h"
#include "String.h"

String::String()
	: m_iLen(0), m_pString(nullptr)
{
}

String::String(const char* _pString)
	: m_iLen(0), m_pString(nullptr)
{
	if (_pString)
	{
		m_iLen = strlen(_pString);
		m_pString = new char[m_iLen + 1];
		strcpy_s(m_pString, m_iLen + 1, _pString);
	}
}

String::String(const String& str)
	: m_iLen(0), m_pString(nullptr)
{
	if (str.m_pString)
	{
		m_iLen = str.m_iLen;
		m_pString = new char[m_iLen + 1];
		strcpy_s(m_pString, m_iLen + 1, str.m_pString);
	}
}

String::~String()
{
	Sefe_Delete_Arr<char*>(m_pString);
}

String String::operator+(const char* _pString)
{
	int iLen(0);
	char* pString = nullptr;

	if (m_pString && _pString)
	{
		iLen = m_iLen + strlen(_pString);
		pString = new char[iLen + 1];

		strcpy_s(pString, iLen + 1, m_pString);
		strcat_s(pString, iLen + 1, _pString);

		String temp;
		temp.m_iLen = iLen;
		temp.m_pString = pString;

		return temp;
	}

	else if (m_pString)
	{
		return *this;
	}

	else if (_pString)
	{
		return String(_pString);
	}
	
	else
	{
		return String();
	}
	
}

String String::operator+(const String& str)
{
	int iLen = m_iLen + str.m_iLen;
	char* pString = nullptr;

	if (m_pString && str.m_pString)
	{
		pString = new char[iLen + 1];

		strcpy_s(pString, iLen + 1, m_pString);
		strcat_s(pString, iLen + 1, str.m_pString);

		String temp;
		temp.m_pString = pString;
		temp.m_iLen = iLen;

		return temp;
	}

	else if (m_pString)
	{
		return *this;
	}

	else if (str.m_pString)
	{
		return str;
	}

	else
	{
		return String();
	}
}

String& String::operator=(const char* _pString)
{
	Sefe_Delete_Arr<char*>(m_pString);
	m_iLen = 0;

	if (_pString)
	{
		m_iLen = strlen(m_pString);
		m_pString = new char[m_iLen + 1];
		strcpy_s(m_pString, m_iLen + 1, _pString);

		return *this;
	}
	else
		return *this;
}

String& String::operator=(const String& str)
{
	Sefe_Delete_Arr<char*>(m_pString);
	m_iLen = 0;

	if (str.m_pString)
	{
		m_iLen = str.m_iLen;
		m_pString = new char[m_iLen + 1];
		strcpy_s(m_pString, m_iLen + 1, str.m_pString);

		return *this;
	}
	else
		return *this;
}

String& String::operator+=(const char* _pString)
{
	if (m_pString && _pString)
	{
		*this = *this + String(_pString);
		return *this;
	}
	else if (m_pString)
	{
		return *this;
	}
	else if (_pString)
	{
		*this = String(_pString);
	}
	else
		*this;
}

String& String::operator+=(const String& str)
{
	if (m_pString && str.m_pString)
	{
		*this = *this + str;
		return *this;
	}
	else if (m_pString)
	{
		return *this;
	}
	else if (str.m_pString)
	{
		*this = str;
	}
	else
		*this;
}

bool String::operator==(const char* _pString)
{
	return !strcmp(m_pString, _pString);
}

bool String::operator==(const String& str)
{
	return !strcmp(m_pString, str.m_pString);
}

ostream& operator<<(ostream& os, const String& ref)
{
	os << ref.m_pString;

	return os;
}

istream& operator>>(istream& is, String& ref)
{
	char szInput[100];
	is >> szInput;

	ref = szInput;

	return is;
}