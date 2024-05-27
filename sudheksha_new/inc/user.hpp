#ifndef USER_HPP

#define USER_HPP

#include "header.hpp"

class user_base
{
	string name;
	string gender;
	int age;
public:
	user_base(string name,string gender,int  age);
	~user_base();
	string get_name()
	{
		return name;
	}
	string get_gender() 
	{
		return gender;
	}
	int get_age()
	{
		return  age;
	}
	void get_details();
};


#include "ticket.hpp"

extern vector <ticket *> tickets;


struct passenger_list
{
	passenger * obj;
	struct passenger_list * next;
};



class user_derived : public user_base
{
	long int id;
	long int mobile_number;
	struct  passenger_list * list;
	vector <ticket *> booked;
	int wallet;
public :                               // syntax changed
	user_derived(string name,string gender,int  age,struct passenger_list *);
	~user_derived();
	int get_id()
	{
		return id;
	}
	void set_id(long int id);
	struct passenger_list *get_list()
	{
		return list;
	}
	void del_list()
	{
		delete list;
	}
	void add_tickets(vector<ticket *>);
	vector <ticket *> get_ticket()
	{
		return booked;
	}
	void add_wallet(int amount);
	int get_wallet()
	{
		return wallet;
	}
	void ticket_far_red(int amount);
	void ticket_fare_red(int val)
	{
		wallet-=val;                       // name changed 
	}
	void cancel_ticket(user_derived*);
	void cancel_waiting_list();
};

user_derived * create_user_fileio(ifstream &in);
#endif



