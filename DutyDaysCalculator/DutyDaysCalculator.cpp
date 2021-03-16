#include <iostream>
#include <ctime>
#include <string> 
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <cmath>

using namespace boost;

boost::gregorian::date getEasterSunday()
{
	boost::posix_time::ptime timeLocal = boost::posix_time::second_clock::local_time();
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

	return boost::gregorian::date(timeLocal.date().year(), month, sunday);
}

bool isWorkDay(boost::gregorian::date dateToCheck)
{
	boost::posix_time::ptime timeLocal = boost::posix_time::second_clock::local_time();
	boost::gregorian::date easterSunday = getEasterSunday();

	boost::gregorian::days oneDay(1);
	boost::gregorian::days twoDays(2);
	boost::gregorian::days threeDays(3);
	boost::gregorian::days tenDays(10);
	boost::gregorian::days twentySixDays(26);
	boost::gregorian::days thirtyNineDays(39);

	if (dateToCheck.day_of_week() == boost::gregorian::Sunday || dateToCheck.day_of_week() == boost::gregorian::Saturday)
		return false;

	if (dateToCheck == boost::gregorian::date(timeLocal.date().year(), 1, 1)) // Nytårsdag
		return false;
	if (dateToCheck == (easterSunday - threeDays)) // Skærtorsdag
		return false;
	if (dateToCheck == (easterSunday - twoDays)) // Langfredag
		return false;
	if (dateToCheck == easterSunday) // Påskedag
		return false;
	if (dateToCheck == (easterSunday + oneDay)) // 2. påskedag
		return false;
	if (dateToCheck == (easterSunday + twentySixDays)) // Store bededag
		return false;
	if (dateToCheck == (easterSunday + thirtyNineDays)) // Kristi Himmelfartsdag
		return false;
	if (dateToCheck == (easterSunday + thirtyNineDays + tenDays)) // Pinsedag
		return false;
	if (dateToCheck == (easterSunday + thirtyNineDays + tenDays + oneDay)) // 2. Pinsedag
		return false;
	if (dateToCheck == boost::gregorian::date(timeLocal.date().year(), 12, 26)) // Nytårsdag
		return false;
	if (dateToCheck == boost::gregorian::date(timeLocal.date().year(), 12, 25)) // Nytårsdag
		return false;

	return true;

}


int main()
{
	std::cout << "Greetings!\n";
	std::cout << "All dates should be in the following format: dd-mm-yyyy\n";
	std::cout << "Enter the first day of the shift:\n";

	// Startdate
	std::string inputStartDateString;
	std::cin >> inputStartDateString;
	std::cout << "You entered: " << inputStartDateString << "\n";
	boost::gregorian::date startDate = boost::gregorian::from_uk_string(inputStartDateString);

	// Enddate
	std::cout << "Enter the last day of the shift:\n";
	std::string inputEndDateString;
	std::cin >> inputEndDateString;
	std::cout << "You entered: " << inputEndDateString << "\n";
	boost::gregorian::date endDate = boost::gregorian::from_uk_string(inputEndDateString);

	int workDays = 0;
	int offDays = 0;

	boost::gregorian::date currentDate = startDate;
	boost::gregorian::days oneDay(1);

	while (endDate > currentDate)
	{
		if (isWorkDay(currentDate))
			workDays++;
		else
			offDays++;
		currentDate = currentDate + oneDay;
	}
	std::cout << workDays << " arbejdsdage\n";
	std::cout << offDays << " fridage\n";
}