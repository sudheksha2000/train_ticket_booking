#ifndef PASSENGER_HPP

#define PASSENGER_HPP
#include "header.hpp"





class passenger:: public user_base
{
	string preference;
public:
	int get_preference()
	{
		return preference;
	}
	passenger(string name,string gender,int  age,string);
	~passenger();

};

#endif
