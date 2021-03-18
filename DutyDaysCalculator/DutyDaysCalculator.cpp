#include <iostream>
#include <ctime>
#include <string> 
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <cmath>
#include "DutyDaysCalculator.h"

using namespace boost;
using namespace boost::gregorian;
using namespace std;

boost::gregorian::date getEasterSunday()
{
	posix_time::ptime timeLocal = posix_time::second_clock::local_time();
	int year = timeLocal.date().year();
	int a = year % 19;//The remainder of the division of x by 19.
	int b = year % 4;//The remainder of the division of x by 4.
	int c = year % 7;//The remainder of the division of x by 7.
	int d = (19 * a + 24) % 30;//The remainder of the division of (19*a + 24) by 30.
	int e = (2 * b + 4 * c + 6 * d + 5) % 7;//The remainder of the division of (2*b+4*c+6*d+5) by 7.
	int sunday = (22 + d + e);//The calculation of easter sunday.
	int month = 3; // March
	if (sunday > 31)
	{
		month = 4;
		sunday -= 31;
	}

	return date(timeLocal.date().year(), month, sunday);
}

bool DutyDaysCalculator::isWorkDay(boost::gregorian::date dateToCheck)
{
	posix_time::ptime timeLocal = boost::posix_time::second_clock::local_time();
	date easterSunday = getEasterSunday();

	days oneDay(1);
	days twoDays(2);
	days threeDays(3);
	days tenDays(10);
	days twentySixDays(26);
	days thirtyNineDays(39);

	if (dateToCheck.day_of_week() == boost::gregorian::Sunday || dateToCheck.day_of_week() == boost::gregorian::Saturday)
		return false;

	if (dateToCheck == boost::gregorian::date(timeLocal.date().year(), 1, 1)) // Nyt�rsdag
		return false;
	if (dateToCheck == (easterSunday - threeDays)) // Sk�rtorsdag
		return false;
	if (dateToCheck == (easterSunday - twoDays)) // Langfredag
		return false;
	if (dateToCheck == easterSunday) // P�skedag
		return false;
	if (dateToCheck == (easterSunday + oneDay)) // 2. p�skedag
		return false;
	if (dateToCheck == (easterSunday + twentySixDays)) // Store bededag
		return false;
	if (dateToCheck == (easterSunday + thirtyNineDays)) // Kristi Himmelfartsdag
		return false;
	if (dateToCheck == (easterSunday + thirtyNineDays + tenDays)) // Pinsedag
		return false;
	if (dateToCheck == (easterSunday + thirtyNineDays + tenDays + oneDay)) // 2. Pinsedag
		return false;
	if (dateToCheck == date(timeLocal.date().year(), 12, 26)) // Nyt�rsdag
		return false;
	if (dateToCheck == date(timeLocal.date().year(), 12, 25)) // Nyt�rsdag
		return false;

	return true;

}


int main()
{
	DutyDaysCalculator dutyDaysCalculator;
	cout << "|-------------------------------------------------------------------------------------|\n";
	cout << "| Greetings!                                                                          |\n";
	cout << "| All dates should be in the following format: dd-mm-yyyy                             |\n";
	cout << "|                                                                                     |\n";
	cout << "| Enter the first day of the shift:                                                   |\n";

	// Startdate
	string inputStartDateString;
	cin >> inputStartDateString;
	date startDate = from_uk_string(inputStartDateString);

	// Enddate
	cout << "| Enter the last day of the shift:                                                    |\n";
	string inputEndDateString;
	cin >> inputEndDateString;
	date endDate = from_uk_string(inputEndDateString);

	int workDays = 0;
	int offDays = 0;

	date currentDate = startDate;
	days oneDay(1);

	while (endDate > currentDate)
	{
		if (dutyDaysCalculator.isWorkDay(currentDate))
			workDays++;
		else
			offDays++;
		currentDate = currentDate + oneDay;
	}

	cout << "|                                                                                     |\n";
	cout << "| " << workDays << " workdays                                                                         |\n";
	cout << "| " << offDays << " offdays                                                                          |\n";
	cout << "| If you took any days off, be it sickness, holiday, or something else.               |\n";
	cout << "| Then remember to add convert any relevant workdays manually,                        |\n";
	cout << "| as the system only handles weekends, and danish holidays.                           |\n";
	cout << "|-------------------------------------------------------------------------------------|\n";
}