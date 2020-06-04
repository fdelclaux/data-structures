/*
 *  Resources.cpp
 *
 *  COSC 052 Fall 2019
 *  Project #3
 *
 *  Due on: NOV 1, 2019
 *  Author: fsd7
 *
 *
 *  In accordance with the class policies and Georgetown's
 *  Honor Code, I certify that, with the exception of the
 *  class resources and those items noted below, I have neither
 *  given nor received any assistance on this project.
 *
 *  References not otherwise commented within the program source code.
 *  Note that you should not mention any help from the TAs, the professor,
 *  or any code taken from the class textbooks.
 */

#include "Resources.h"



/*
*****************************
*DATE Class member functions*
*****************************
*/

Date::Date(int year , int month, int day)
{
	setDate(year, month, day);
}

Date::Date(const Date& d)
{
	setDate(d.getYear(),d.getMonth(),d.getDay());
}

void Date::setDate(int year, int month, int day)
{

	string yearError = "\tRROR: invalid year ";
	string monthError = "\tERROR: invalid month ";
	string dayError = "\tERROR: invalid day ";

	if ( year > MAX_YYYY || year < MIN_YYYY )
	{
		throw invalid_argument(yearError);
		//cout << yearError << endl;
	}

	if( month > MAX_MM || month < MIN_MM )
	{
		throw invalid_argument(monthError);
		//cout << monthError << endl;
	}

	if (month == 02)
	{
		if( day < MIN_DD - 2 || day > MAX_DD - 2 )
		{
			throw invalid_argument(dayError);
			//cout << dayError << endl;
		}

	}
	else if(month == 4 || month == 6 || month == 9 || month == 11 )
	{
		if( day < MIN_DD - 1 || day > MAX_DD - 1 )
		{
			throw invalid_argument(dayError);
			cout << dayError << endl;
		}
	}
	else
	{
		if( day < MIN_DD || day > MAX_DD )
		{
			throw invalid_argument(dayError);
			cout << dayError << endl;
		}
	}
	
	yyyy = year;
	mm = month;
	dd = day;
}

void Date::setDate(const Date& d)
{
	yyyy = d.getYear();
	mm = d.getMonth();
	dd = d.getDay();
}

Date Date::operator=(const Date& d)
{

	setDate(d.getYear(), d.getMonth(), d.getDay());

}

int Date::getYear() const
{
	return yyyy;

}

int Date::getMonth() const
{
	return mm;
}

int Date::getDay() const
{
	return dd;
}

bool Date::operator ==(const Date& rhsObj) const
{
	bool equal = false;

	equal = yyyy == rhsObj.getYear() && mm == rhsObj.getMonth() && dd == rhsObj.getDay();

	return equal;
}

bool Date::operator !=(const Date& rhsObj) const
{
	bool equal = false;

	equal = !(*this == rhsObj);

	return equal;
}

bool Date::operator <=(const Date& rhsObj) const
{
	bool lessthanequal = false;

	if(yyyy < rhsObj.getYear())
	{
		lessthanequal = true;
	}
	else if ( yyyy == rhsObj.getYear())
	{
		if(mm < rhsObj.getMonth())
		{
			lessthanequal = true;
		}
		else if(mm == rhsObj.getMonth())
		{
			if(dd <= rhsObj.getDay())
			{
				lessthanequal = true;
			}
		}
	}

	return lessthanequal;
}

bool Date::operator <(const Date& rhsObj) const
{
	bool lessthan = false;

	if(yyyy < rhsObj.getYear())
	{
		lessthan = true;
	}
	else if ( yyyy == rhsObj.getYear())
	{
		if(mm < rhsObj.getMonth())
		{
			lessthan = true;
		}
		else if(mm == rhsObj.getMonth())
		{
			if(dd < rhsObj.getDay())
			{
				lessthan = true;
			}
		}
	}

	return lessthan;

}

bool Date::operator >=(const Date& rhsObj) const
{
	bool greatthanequal = false;

	if(yyyy > rhsObj.getYear())
	{
		greatthanequal = true;
	}
	else if ( yyyy == rhsObj.getYear())
	{
		if(mm > rhsObj.getMonth())
		{
			greatthanequal = true;
		}
		else if(mm == rhsObj.getMonth())
		{
			if(dd >= rhsObj.getDay())
			{
				greatthanequal = true;
			}
		}
	}

	return greatthanequal;
}

bool Date::operator >(const Date& rhsObj)  const
{
	bool greatthan = false;

	if(yyyy > rhsObj.getYear())
	{
		greatthan = true;
	}
	else if ( yyyy == rhsObj.getYear())
	{
		if(mm > rhsObj.getMonth())
		{
			greatthan = true;
		}
		else if(mm == rhsObj.getMonth())
		{
			if(dd > rhsObj.getDay())
			{
				greatthan = true;
			}
		}
	}

	return greatthan;

}

std::ostream& operator<<(std::ostream &os, const Date& d)
{

	string streamFail = "\tERROR: Stream failure";

	if( !os )
	{
		throw invalid_argument(streamFail);
		cout << streamFail << endl;
	}

	cout << std::setfill('0') << std::setw(4) << d.getYear() << '/' << std::setw(2) << d.getMonth();
	cout << '/' << d.getDay();

	return os;
}

std::istream& operator>>(std::istream &is, Date& d)
{
	string streamFail = "\tERROR: Stream failure";

	if(!is)
	{
		throw invalid_argument(streamFail);
		cout << streamFail << endl;
	}

	int year = 0;
	int month = 0;
	int day = 0;
	char slash = '/';

	is >> year >> slash >> month >> slash >> day;

	//cout << year << slash << month << slash << day << endl;

	d.setDate(year, month, day);

	return is;

}




/*
*****************************
*TIME Class member functions*
*****************************
*/
	Time::Time(int hour, int minute)
	{
		setTime(hour, minute);
	}

	void Time::setTime(int h, int m)
	{
		string hourError = "\tERROR: Invalid hour ";
		string minuteError = "\tERROR: Invalid minute ";
		string midnightError =  "\tERROR: If hour is 24, minute must be 00 ";



		if( h > MAX_HOUR || h < DEFAULT_HOUR)
		{
			throw invalid_argument(hourError);
			cout << hourError << endl;
		}

		if( m > MAX_MINUTE || m < DEFAULT_MINUTE)
		{
			throw invalid_argument(minuteError);
			cout << minuteError << endl;
		}	

		if( h == 24 && m != 00)
		{
			throw invalid_argument(midnightError);
			cout << midnightError << endl;
		}

		if( h == 00 && m == 00)
		{
			h = 24;
		}



		hh = h;
		mm = m;
	}

    Time Time::operator=(const Time& t)
    {
    	if(*this != t)
    	{
    		setTime(t.getHour(), t.getMinute());
    	}

    }

    bool Time::operator==( const Time& t) const
    {
    	bool equal = false;


    	equal = hh == t.getHour() && mm == t.getMinute();


    	return equal;
    }
    
    bool Time::operator!=( const Time& t) const
    {
    	bool notEqual = false;

    	notEqual = !(*this == t);

    	return notEqual;

    }
    
    bool Time::operator>( const Time& t) const
    {
    	bool largerThan = false;

    	if( hh > t.getHour())
    	{
    		largerThan = true;
    	}
    	else if ( hh == t.getHour() && mm > t.getMinute())
    	{
    		largerThan = true;
    	}

    	return largerThan;
    }
    
    bool Time::operator<( const Time& t) const
    {
    	bool lessThan = false;

    	if(hh < t.getHour())
    	{
    		lessThan = true;
    	}
    	else if (hh == t.getHour() && mm < t.getMinute())
    	{
    		lessThan = true;
    	}

    	return lessThan;
    }

    std::ostream& operator<<( std::ostream &os, const Time& t)
    {

    	cout << std::setfill('0') << std::setw(2) << t.getHour() << ":" << t.getHour();

    	return os;

    }

    std::istream& operator>>( std::istream &in, Time& t)
    {
    	int hour = 0;
    	int minute = 0;
    	char colon = ':';

    	in >> hour >> colon >> minute;

    	t.setTime(hour, minute);

    	//cout << "time read" << endl;

    	return in;
    }

    string readDoubleQuotedString(std::istream &is)
    {
    	string streamFail = "\tERROR: Stream failure ";

    	string openQuoteFail = "\tERROR: Opening quote not found ";

    	string closeQuoteFail = "\tERROR: Closing quote not found ";

    	if(!is)
    	{
    		throw invalid_argument(streamFail);
    	}

    	string text = "";
    	char ch;

    	is >> ch;

    	if(ch != '"')
    	{
    		throw logic_error(openQuoteFail);
    		cout << openQuoteFail << endl;
    	}
    	
		getline(is, text, '"');

		if(!is)
		{
			throw logic_error(closeQuoteFail);
		}

		return text;

	}