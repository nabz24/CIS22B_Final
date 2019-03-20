#include <stdio.h>
#include "Sport.h"
#include<string>

using namespace std;




string Sport::getSport() const
{
	return sport;
}

// mutators

void Sport::setSport(string s)
{

	sport = s;

};