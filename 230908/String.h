#pragma once

#include "Define.h"

class String
{
public:
	String();
	String(const char* _pString);
	String(const String& str);
	~String();

public:
	String		operator+ (const char* _pString);
	String		operator+ (const String& str);

	String&		operator= (const char* _pString);
	String&		operator= (const String& str);

	String&		operator+= (const char* _pString);
	String&		operator+= (const String& str);

	bool		operator== (const char* _pString);
	bool		operator== (const String& str);

public:
	friend ostream&		operator<< (ostream& os, const String& ref);
	friend istream&		operator>> (istream& is, String& ref);

private:
	char*	m_pString;
	int		m_iLen;
};

