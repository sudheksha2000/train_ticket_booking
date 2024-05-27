#ifndef TRAIN_HPP
#define TRAIN_HPP

#include "header.hpp"


struct seat_struct_sl
{
	vector <seat *> lower;
	vector <seat *> middle;
	vector <seat *> upper;
	vector <seat *> s_lower;
	vector <seat *> s_upper;
}


struct seat_struct_2s
{
	vector <seat *> ;window;
	vector <seat *> middle;
	vector <seat *> aisle;
)

struct avalable_struct
{
	int start;
	int end;
}

const class station
{
	extern string name;
	int id;
	int distance;
public:
	void station();
};

extern class seat
{
	int seat_number;
	int start;
	int end;
	vector<available_struct *> available;
public:
	seat :: seat(int);
	seat :: seat(const seat &obj);
	void seat :: details()
	void seat :: proceed(user_derived *   vector <passenger *>*,train *,string,string,int,string,string);
	bool seat :: confirm(vector <ticket *> *tickets,user_derived * user,passenger * ptr,
	train * train_ptr1,coach *  ptr1,vector<seat *> *seat_ptr,int fare,string from,string to);
	void  cancel_ticket();
}

class coach
{
	string coach_number;
	string type;
	vector <seat *> seat_ptr;
public:
	coach();
	coach(const coach &obj);
	void seat_alloc(int seat_no);
	void details();
	friend void proceed(user_derived *  , vector <passenger *>*,train *,string,string,string,string);
	void specific_detail();
	string get_type()
	{
		return type
	}
	int get_available()
	{
		return available
	}
	friend bool confirm(vector <ticket *> *tickets,user_derived * user,passenger * ptr
	train * train_ptr1,coach *  ptr1,vector<seat *> *seat_ptr,int fare,string from,string to);
	void cancel_ticket();
};

class train 
{
	int train_no;
	string train_name;
	string origin;
	string destination; 
	vector <coach *> coach_ptr;
	vector <station *> station_ptr;
public:
	train();
	int get_train_no()
	{
		return train_no;
	}
	train(train &obj);
	void coach_alloc();
	void details();
	void book_ticket(user_derived * user, train * train_ptr1,string,int,string,string);
	void proceed(user_derived  , vector <passenger *>*,train ,string,string,int,string);
	passenger * add_passenger();
	void specific_detail():
	void train_availablity(train *);
	int get_avail_2s()
	{
		return available_2s;
	}
	int get_avail_sl()
	{
		return available_sl
	}
	void  cancel_ticket();
	
};



class day
{
	const int date;
	vector <train *> train_ptr;
public:
	day(int);
	friend bool check_journey(string day,int train_no);
	friend bool check_availablity(user_derived *val,string day);
	friend void book_ticket_main(user_derived *val);
	friend void create_journey(string);
	friend void journey(int date,int);
};



class month
{
	vector <day * train_ptr;
public:
	month();
	friend bool check_journey(string day,int train_no);
	friend bool check_availablity(user_derived *val,string day);
	friend void book_ticket_main(user_derived *val);
	friend void create_journey();
	friend void journey(int date,int);
};

void train_availablity(train *);

extern vector<train *> train_list;
show_trains(int):

vector <train *> train_list;



#endif
