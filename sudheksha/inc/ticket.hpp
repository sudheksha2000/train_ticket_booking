#ifndef TICKET_HPP
#define TICKET_HPP

#include "header.hpp"


class ticket
{
	string status;
	passenger * passenger_ptr;
	train * train_ptr;
	coach * coach_ptr;
	seat * seat_ptr;
	string from;
	string to;
	int fare;
public:
	ticket(passenger *ptr1,train * ptr2,coach * ptr3,seat * ptr4,,int fare,string from,string to);
	ticket(passenger *ptr1,train * ptr2,int fare,string from,string to);
	void get_details();
};

#endif
