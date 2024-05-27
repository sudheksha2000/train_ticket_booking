#ifndef PASSENGER_HPP

#define PASSENGER_HPP
#include "header.hpp"

#include "user.hpp"

class passenger: public user_base
{
	string preference;
public:
	string get_preference()
	{
		return preference;
	}
	void set_preference(string type)
	{
		preference = type;
	}
	passenger(string name,string gender,int age);
	passenger(string name,string gender,int age,string pref);
	~passenger();

};

#endif
