#include <stdio.h>
#include "History.h"
#include<string>

using namespace std;


string History::getTimeInHistory() const
{
	return timeInHisotry;
}

// mutators

void History::setTimeInHistory(string T)
{

	timeInHisotry = T;

};