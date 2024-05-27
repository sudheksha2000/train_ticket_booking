#ifndef TRAIN_HPP
#define TRAIN_HPP

#include "header.hpp"
#include "passenger.hpp"
#include "ticket.hpp"
class train;

struct seat_struct_sl
{
	vector <seat *> lower;
	vector <seat *> middle;
	vector <seat *> upper;
	vector <seat *> s_lower;
	vector <seat *> s_upper;
};


struct seat_struct_2s
{
	vector <seat *> window;
	vector <seat *> middle;
	vector <seat *> aisle;
};

struct available_struct
{
	int start;
	int end;
};

class station
{
	string name;
	int id;
	int distance;
public:
	station(int id);
	station(int,stringstream&);
	string get_name()
	{
		return name;
	}
	int get_id()
	{
		return id;
	}
	int get_distance()
	{
		return distance;
	}
};



class train 
{
	int train_no;
	string train_name;
	string origin;
	string destination; 
	vector <coach *> coach_ptr;
	vector <station *> station_ptr;
	int available_2s;
	int available_sl;
	vector<pair<user_derived*,passenger*>> passenger_ptr_wl_sl;
	vector<pair<user_derived*,passenger*>> passenger_ptr_wl_2s;
	int waiting_sl;
	int waiting_2s;
public:
	train();
	train(string);
	int get_train_no()
	{
		return train_no;
	}
	string get_train_name()
	{
		return train_name;
	}
	vector<station*> get_station_ptr()
	{
		return station_ptr;
	}
	int get_waiting_sl()
	{
		return waiting_sl;
	}
	int get_waiting_2s()
	{
		return waiting_2s;
	}
	vector<pair<user_derived*,passenger*>> get_passenger_ptr_wl_sl()
	{
		return passenger_ptr_wl_sl;
	}
	vector<pair<user_derived*,passenger*>> get_passenger_ptr_wl_2s()
	{
		return passenger_ptr_wl_2s;
	}
	train(train &obj);
	int coach_alloc(int);
	void train_details();
	void proceed(user_derived*  , vector <passenger *>,train* ,string,int,string,string);
	void book_ticket_option(user_derived * user, train * train_ptr1,string type,int fare,string from,string to);
	passenger * add_passenger(string);
	void specific_detail();
	int middle_station();	
	bool filter_src_des(string from, string to);
	void train_availablity(string from,string to);
	bool seat_check(seat * ptr1,string from, string to);
	void waiting_list(passenger* ptr,int fare,string from,string to,string type,user_derived* user,vector<ticket*>);
	int get_avail_2s()
	{
		return available_2s;
	}
	int get_avail_sl()
	{
		return available_sl;
	}
	
};

class seat
{
	int seat_number;
	int start;
	int end;
	string type;
	vector<available_struct*> available;
public:
	seat(int,int,string);
	seat(const seat &obj);
	string get_type()
	{
		return type;
	}
	int get_start()
	{
		return start;
	}
	int get_end()
	{
		return end;
	}
	vector<available_struct*> get_available()
	{
		return available;
	}
	void details();
	void change_available(seat * ptr,string from, string to,train*);
	friend bool train::seat_check(seat * ptr1,string from, string to);
	friend void make_available(seat * seat_ptr,ticket* ticket,string from,string to);
	friend void make_available(seat* seat_ptr);
};

class coach
{
	string coach_number;
	string type;
	seat_struct_2s *seat_ptr_2s;
	seat_struct_sl *seat_ptr_sl;
	int available;
public:
	coach(){};
	coach(const coach &obj);
	coach(int,int,bool);
	void seat_alloc(int seat_no,int);
	void details();
	string get_type()
	{
		return type;
	}
	int get_available()
	{
		return available;
	}
	seat_struct_2s* get_seat_ptr_2s()
	{
		return seat_ptr_2s;
	}
	seat_struct_sl* get_seat_ptr_sl()
	{
		return seat_ptr_sl;
	}
	friend bool confirm(vector <ticket *> *tickets,user_derived * user,passenger * ptr,
	train * train_ptr1,coach *  ptr1,vector<seat *> seat_ptr,int fare,string from,string to,string type);
	friend void train::train_availablity(string from,string to);
};



class day
{
	int date;
	vector <train *> train_ptr;
public:
	day(int);
	int get_date()
	{
		return date;
	}
	vector<train*> get_train_ptr()
	{
		return train_ptr;
	}
	friend void journey_function(int date,int,char);
	friend bool filter_train(int date,string from, string to,vector <train *> *ptr4);
};



class month
{
	vector <day *> day_ptr;
public:
	month(int);
	vector<day*> get_day_ptr()
	{
		return day_ptr;
	}
	friend void create_journey();
	friend void journey_function(int date,int,char);
	friend bool filter_train(int date,string from, string to,vector <train *> *ptr4);
};

void show_trains(int);

string center_align(string str, int width);

bool filter_train(int date,string from, string to,vector <train *> *ptr4);

void berth_availablity(vector<seat *>seat_ptr,string from, string to,int * sleeper,int * second_sitting,train*);

int get_fare(string from,string to,train*);
vector<seat *> berth_selection(coach * coach_ptr,string preference);
void journey_function(int date,int,char);
void make_available(seat * seat_ptr,ticket* ticket,string from,string to);
void add_money(user_derived*);
void add_passenger_wl(string type,train* train_ptr,int fare,string from,string to,user_derived* user);
#endif
