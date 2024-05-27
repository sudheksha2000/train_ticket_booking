#ifndef TICKET_HPP
#define TICKET_HPP

#include "header.hpp"
#include "passenger.hpp"
#include "train.hpp"

class ticket
{
	passenger * passenger_ptr;
	train * train_ptr;
	coach * coach_ptr;
	seat * seat_ptr;
	string from;
	string to;
	int fare;
public:
	string status;
	ticket(passenger *ptr1,train * ptr2,coach * ptr3,seat * ptr4,int fare,string from,string to);
	ticket(passenger *ptr1,train * ptr2,int fare,string from,string to);
	ticket(passenger *ptr1,train*ptr2,int fare,string from,string to,bool print);
	void get_details();
	train* get_train_ptr()
	{
		return train_ptr;
	}
	string get_status()
	{
		return status;
	}
	seat* get_seat_ptr()
	{
		return seat_ptr;
	}
	string get_from()
	{
		return from;
	}
	string get_to()
	{
		return to;
	}
	int get_fare()
	{
		return fare;
	}
};


#endif
