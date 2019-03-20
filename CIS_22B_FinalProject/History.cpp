#include <stdio.h>
#include "History.h"
#include<string>

using namespace std;


string History::getTimeInHistoryStart() const
{
	return timeInHisotryStart;
}

string History::getTimeInHistoryEnd() const
{
	return timeInHisotryEnd;
}

// mutators

void History::setTimeInHistoryStart(string T)
{

	timeInHisotryStart = T;

};

void History::setTimeInHistoryEnd(string e)
{

	timeInHisotryStart = e;

};