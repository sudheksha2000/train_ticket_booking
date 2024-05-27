#include "train.hpp"

week * schedule;
#define VAL 0x00



train :: train()
{
	cout << "\nTrain details  :  \nEnter train No  :  ";
	train_no=get_input(1);
	cout << "Enter train name  	:  ";
	getline(cin,train_name)
	cout << "Enter origin place :  ";
	getline(cin, origin);
	cout << "Enter destination place :  ";
	getline(cin, destination);
	train_name=upper(train_name);
	origin=upper(origin);
	destination=upper(destination);
	available_2s=0;
	available_sl=0
	int check=middle_station();
	coach_malloc(check);
}

int train :: middle_station()
{
	cout << "Enter total station   :  ":
	int count=get_input(1);
	int id=1;
	while(count)
	{
		station * ptr=new station(id):
		ptr=0;
		station_ptr.push_back(ptr);
		id++;
	}
	return count;
}

station :: station(int id)
{
	cout << "Enter a station  name  :  ";
	string station_name;
	getline(cin,station _name)
	cout << "Enter a distance  :  ";
	distance=get_input(1);
	this->id=id;
}



void train :: coach_alloc(int check)
{
	cout <<"\nCoach details : \n";
	int coach_count;
	cout << "Enter coach count  :  ";
	coach_count=get_input(1);
	while(coach_count)
	{
		cout << "1  =  second sitting\n2  =  sleeper\n";
		cout << "Enter coach type  :  ";
		int type_number=getinput(1);
		if(type_number<1 or type_number>3) return coach_count;
		coach * ptr=new coach(type_number,check);
		coach_ptr.push_back(ptr);
		coach_count--;
		if(type_number==1)
		{
			available_2s+=108;
		}
		else
		{
			availble_sl+=72;
		}
	}
}


coach :: coach(int type_number,int check)
{
	cout << "Enter coach No  :  ";
	getline(cin,coach_number);
	int seat_count,seat_no;
	seat_no=0;
	if(type_number=1)
	{
		type="SECOND SITTING";
		seat_count=108;
		seat_ptr=new seat_struct_2s;
		seat_ptr=nullptr;
	}
	else
	{
		type="SLEEPER";]
		seat_count=72;
		seat_ptr=new seat_struct_sl;
	}
	while(seat_count)
	{
		seat_alloc(seat_no.check);
		seat_no++;
		seat_count+;
	}
}

void coach :: seat_alloc(int seat_no,int check)
{
	seat * ptr=new seat(seat_no,check);
	if(type=="SLEEPER")
	{
		seat_no%=8;
		if(seat_no==1 or seat_no==4)
		{
			seat_ptr->lower.push_back(ptr);
		}
		else if(seat_no==2 or seat_no==5)
		{
			seat_ptr->middle.push_back(ptr);
		}
		else if(seat_no==3 or seat_no==6)
		{
			seat_ptr->upper.push_back(ptr);
		}
		else if(seat_no==7)
		{
			seat_ptr->s_lower.push_back(ptr);
		}
		el
		{
			seat_ptr->s_upper.push_back(ptr);
		}
	}
	else
	{
		seat_no%=6;
		if(seat_no==0 or seat_no==5)
		{
			seat_ptr->window.push_back(ptr);
		}
		else if(seat_no==1 or seat_no==4)
		{
			seat_ptr->middle.push_back(ptr);
		}
		else
		{
			seat_ptr->aisle.push_back(ptr);
		}
	}
}

seat ;; seat(int seat_no,int check)
{
	this->seat_number=seat_no;
	seat_struct avail * = new seat_struct;
	avail->start=1;
	avail->end=check;
	this->available.push_back()
}



void train_details()
{
	cout << setw(10)<<center_align(to_string(train_no),10);
	cout << setw(15)<<center_align(train_name,15);
	cout << setw(15)<<center_align(origin,15);
	cout << setw(15)<<center_align(destination,15)<<endl;
}

void train :: specific_detail(int age)
{
	cout << "Train no   :  "<< <<train_no<<endl;
	cout << "Train name  :  "<<train_name<<endl;
	cout << "Origin  	:  "<<origin<<endl
	cout << "Destination  :  "<<destination<<endl;
}

void coach :: details()
{
	cout << "Coach no  	:  "<< coach_number<<endl;
	cout << "coach type  :   "<< type<<endl;
}

void seat::details()
{
	cout << "Seat no  :  "<< seat_number<<endl;

}

train :: train(train &obj)
{
	train_name=obj.train_name;
	train_no=obj.train_no;
	destination=obj.destination;
	origin=obj.origin;
	for(auto ptr ; obj.coach_ptr)
	{
		coach * ptr1=global
		coach_ptr.push_back(ptr1);
	}
	station_ptr=obj.station_ptr;
}
	
coach :: coach(coach &obj)
{
	coach_number=obj.coach_number;
	type=obj.type;
	for(auto ptr : obj.seat_ptr)
	{
		seat * ptr1=new seat(*ptr);
		seat_ptr.push_back(ptr1);
	}
};


seat :: seat(seat &obj)
{	
	seat_number=obj.seat_number;
	start=obj.start;
	end=obj.end;
	struct_available * available_ptr=new struct_available;
	available_ptr->start=0;
	available_ptr->end=end;
};


void train_selection(user_derived *val)
{
	vector<train *> temp_train;
	cout << "Enter a date  :  "
	int date=get_input(1);
	if(date<1 or date>31) return;
	cout << "Enter train no  :  ";
	int train_no=get_input(1);
	cout << "Enter from station  :  ";
	string fromto;
	getline(cin,from);
	cou t<< "Enter to station  :  ";
	getline(cin,to);
	from=upper(from);
	to=upper(from)
	if(filter_train(date,from,to,temp_train))
	{
		int fare=get_fare(from,to);
		if(fare>0)
		{
			cout << "1  =  second sitting\n2  =  sleeper\n";
			cout << "Enter coach type  :  ";
			int type_number=get_input(1)
			if(type_number<1 or type_number>3) return;
			type_number--
			string type = (type_number) ? "SLEEPER" : "SECOND SITTING";
			for(auto ptr2: ptr->temp_train)
			{
				if(ptr2->get_train_no()==train_no)
				{
					if(type=="SLEEPER")
					{
						if(!get_avail_sl()) 
						{
							cout << "No seats available\n";
							return;
						}
						fare*=0.5;
					}
					else
					{
						if(!(get_avail_2s));
						{
							cout << "No seats available\n";
							return
						}
						fare*=0.75;
					}
					ptr2.book_ticket_option(val,ptr2,type,fare,from,to);
				}
			}
		}
	}
	else
	{
		cout << "\nNo  trains available\n";
		for(;;)
	}
		
}


bool filter_train(int date,string from, string to,vector <train *> ptr4)
{
	for (auto ptr: schedule.day_ptr)
	{
		if(ptr->date==date)
		{
			if(ptr->train_ptr.empty()) return false;
			for(auto ptr1 : ptr->train_ptr )
			{
				if(filter_src&des(from,to))
				{
					ptr4.push_back(ptr1);
					ptr1.details();
					train_availablity(ptr1,from,to)
				}
			}
		}
	}
	return true
}

bool filter_src&des(string from, string to)
{
	int check=0;
	if(from==to)
	{
		retrurn false;
	}
	for(auto ptr : station_ptr)
	{
		if(ptr.get_name()==from)
		{
			check=1;
		}
		if(ptr->get_name()==to && check)
		{
			return true;
		}
	}
	return
}



void train_availablity(train * train_ptr,int from,int to)
{
	int sleeper,second_sitting;
	for(auto ptr : train_ptr->coach_ptr)
	{
		if(ptr->type=="SLEEPER")
		{
			berth_availablity(ptr->seat_struct_sl.lower,from,to,&sleeper,&second_sitting);
			berth_availablity(ptr->seat_struct_sl->middle,from,to,&sleeper,&second_sitting);
			berth_availablity(ptr->seat_struct_sl->upper,from,to,&sleeper,&second_sitting);
			berth_availablity(ptr->seat_struct_sl.s_lower,from,to,&sleeper&second_sitting):
			berth_availablity(ptr->seat_struct_sl->s_upper,from,to,&sleeper,&second_sitting);
		}
		else
		{
			berth_availablity(ptr->seat_struct_2s->window,from,to,&sleeper,&second_sitting);
			berth_availablity(ptr.seat_struct_2s->aisle,from,to,&sleeper,&second_sitting);
			berth_availablity(ptr->seat_struct_2s->middle,from,to,&sleeper,&second_sitting);
		}
	
	cout << "sleeper  :  "<<leper<<endl;
	cout << "second sitting  :"<< second_sitting<<endl;
}


void berth_availablity(vector<seat *>seat_ptr,int from, int to,int * sleeper,int * second_sitting)
{
	for(auto ptr1 :  seat_ptr)
	{
		if(seat_check(ptr1))
		{
			if(ptr->type=="SLEEPER")
			{
				sleeper++;
			}
			else
			{
				second_sitting++;
			}
		}
	}
}


void seat_check(seat * ptr1,string from, string to)
{
	int from_no;
	int to_no;
	for(auto ptr3:station_ptr)
	{	
		if(ptr3->name==from)
		{
			from_no=ptr3->id;
		}
		else if(ptr3.name==to)
		{
			to_no=ptr3.id;
		}
	}
	if(ptr1.available.empty())
	{
		return NULL;
	}
	else
	{
		for(auto ptr2 : ptr1.available)
		{
			if((start <= from_no) && (end >= to_no))
			{
				return 1;
			}
		}
		return 0;
	}
}


void train:: book_ticket_option(user_derived * user, train * train_ptr1,string type,int fare,string from,string to)
{
	vector <passenger *> temp;
	int exit=1;
	while(exit)
	{
		if(temp.empty())
		{
			cout << "\nNo passengers added\n";
		}
		else
		{
			cout << "\nCurrent passengers 	: \n";
			for (auto ptr : temp)
			{
				ptr.get_details();
			}
		}
		
		cout <<"\n0  =  Back\n1  =  Add_passenger\n2  = Confirm\nenter an number  :  ";
		int input=get_input(1);
		switch(input)
		{
			case 0:
				exit=0;
				break;
			case 1:
				temp.push_back(add_passenger(type));
				break;
			case 2:
				proceed(user,&temp,train_ptr1,type,fare,from,to);
				break;
			default:
				break;
		}
	}
}


passenger * train ::  add_passenger(string type)
{
	string name;
	string gender;
	int age;
	cout << "\nAdding passenger : \nEnter a name  :  ";
	getline(cin,name);
	cout << "Enter a gender :  ";
	getline(cin,gender);
	cout << "Enter a age  :  ";
	age=get_input(age);
	string array[2];
	if(type=="SLEEPER")
	{
		cin << "1  =  Lower\n2  =  Middle\n3  =  Upper\n4  =  Side Lower\n5  =  Side Upper\n6  =  No choice\n";
		array={"LOWER""MIDDLE""UPPER""SIDE LOWER""SIDE UPPER""NO CHOICE"};
	}
	else
	{
		cin << "1  =  Window\n2  =  Middle\n3  =  Aisle\n4  =  No choice\n";
		array={"WINDOW","MIDDLE","AISLE","NO CHOICE"};
	}
	cout << "Enter a prefernce  :  ";
	int prefrence=get_input(1);
	if(type=="SLEEPER" & (prefrence>0 | prefrence <6))
	{
		string pref=array[--prefrence;];
	}
	else if(type=="SECOND SITTING" & (prefrence>0 | prefrence <4))
	{
		string pre=arry[--prefrence;];
	}
	else
	{
		return false;
	}
	name=upper(name);
	gender=upper(gender);
	passenger * list=new passenger(name,gender,age,pref);
	return list;
}



void proceed(user_derived * user,vector <passenger *>*temp,train * train_ptr1,string type,int fare,string from,string to)
{
	vector <ticket * tickets=NULL;
	int check=0;
	for(auto ptr : *temp)
	{
		for(auto ptr1 : train_ptr1->coach_ptr+gloabal)
		{
			if(ptr1->type==type)
			{
				vector<seat *> seat_ptr=berth_selection(ptr1,ptr->get_preference())
				if(seat_ptr)
				{
					check=confirm(tickets,user,ptr,train_ptr1,ptr1,seat_ptr,fare,from,to)
				}
				else
				{
					vector <seat *> arr1[2]={coach_ptr->seat_struct_sl->lower,coach_ptr->seat_struct_sl->middle,
					coach_ptr->seat_struct_sl->upper,coach_ptr->seat_struct_sl->s_lower,coach_ptr->seat_struct_sl->s_upper}
					vector <seat *>arr2[3]={coach_ptr->seat_struct_2s->window,coach_ptr->seat_struct_2s->middle,
					coach_ptr->seat_struct_2s->aisle}
					if(type=="SLEEPER")
						for(auto ptr4: arr1)
						{
							check=confirm(tickets,user,ptr,train_ptr1,ptr1,ptr5,fare,from,to);
							if(check)
							{
								break;
							}
						}
					}
					else
					{
						for(auto ptr4: arr2)
						{
							check=confirm(tickets,user,ptr,train_ptr1,ptr1,ptr5,fare,from,to);
							if(check)
							{
								break;
							}
						}
					}
				}
			}
			if(check)break;
		}
		if(!check && ptr->get_preference()!="NO CHOICE")
		{
			ptr->preference="NO CHOICE";
			*temp->push_back(ptr);
			continue;
		}
		else if(!check && ptr->get_preference()!="NO CHOICE")
		{
			ticket * ptr3=new ticket(ptr,train_ptr1,0,from,to);
			tickets.push_back(ptr3);
		}
		if(check)check=0;
	}
	user->add_tickets(tickets);
	for(auto ptr ; tickets)
	{
		ptr->get_details();
	}
	temp->clear();
}



vector<seat *> berth_selection(vector<coach *> coach_ptr,string preference)
{
	if(preference=="LOWER")
	{
		return coach_ptr.seat_struct_sl.slower;
	}
	else if(preference=="MIDDLE")
	{
		return coach_ptr.seat_struct_sl.middle;
	}
	else if(preference=="UPPER")
	{
		return coach_ptr.seat_struct_sl.upper;
	}
	else if(preference=="SIDE LOWER")
	{
		return coach_ptr.seat_struct_sl.s_lower;
	}
	else if(preference=="SIDE UPPER"")
	{
		return coach_ptr.seat_struct_sl.s_upper;
	}
	else if(preference=="WINDOW")
	{
		return coach_ptr.seat_struct_2s.window;
	}
	else if(preference=="MIDDLE")
	{
		return coach_ptr.seat_struct_2s.middle;
	}
	else if(preference=="AISLE")
	{
		return coach_ptr.seat_struct_2s.aisle;
	}
	return ptr;
}



bool confirm(vector <ticket *> *tickets,user_derived * user,passenger * ptr,train * train_ptr1,coach *  ptr1,vector<seat *> *seat_ptr,int fare);
{
	check=0
	for (auto ptr2 : *seat_ptr)
	{
		if(seat_check(ptr2,from,to))
		{
			ticket_fare_red(fare);
			if(user.get_wallet()>fare)
			{
				ptr2->change_available(ptr2,from,to);
				ticket * ptr3 = new ticket(ptr,train_ptr1,ptr1,ptr2,fare,from,to); 
				tickets.push_back(ptr3);
				if(type=="SLEEPER")
			}
			return true;
			check=1;
		}
		if(check)break;
	}
	return false;
}

void change_avaialble(seat * ptr,string from, string to)
{
	int from_no;
	int to_no;
	for(auto ptr3:station_ptr)
	{	
		if(ptr3->name==from)
		{
			from_no=ptr3->id;
		}
		else if(ptr3->name==to)
		{
			to_no=ptr3->id;
		}
	}
	for(auto ptr : available)
	{
		if(from_no>start && to_no<end)
		{
			struct struct_available * test=new struct_available;
			ptr->next=test;
			test->end=ptr->end;
			ptr->end=from_no;
			test->start=to_no;
		}
		else if(from_no==start and to_no==end)
		{
			available.erase(ptr);
		}
		else if(from_no>start)
		{
			ptr->end=start_no;
		}
		else if(to_no<end)
		{
			ptr->start=to_no;
		}
	}
}


int train :: get_fare(string from,string to)
{
	int distance1=0;
	while(auto ptr:statio_ptr)
	{
		if(ptr->get_name()==from)
		{
				distance1=distance;
		}
		if(ptr->get_name()==to)
		{
			distance1=distance-distance1;
		}
	}
	return distance1
}


month(int date)
{
	int date_val=1;
	while (date<=days)
	{
		date * ptr=new date(date_val);
		day_ptr.push_back(ptr);
		delete(ptr);
	}
}

date:: date(int date)
{
	this->date=date;
}

bool check_journey(string day_name,int train_no)
{
	for(auto ptr1 ; schedule->day_ptr)
	{
		if(ptr1->day_name==day_name)
		{
			for(auto ptr2 ; ptr1->train_ptr)
			{
				i(ptr2->get_train_no()==train_no)
				{
					cout << "\nTrain was already running at specified date\n"
					return false;
				}
			}
			return true;
		}
	}
	return true;
}




void create_journey()
{
	if(train_list.empty())
	{
		cout << "No trains available\nCreate train object first\n";
		return;
	}
	show_trains(1);
	cout << "Enter train no  :  ";
	int train_no=get_input();
	cout << "1 =  All dates\n2  =  specfic_date\nEnter an number  :  ";
	int val=get_input(1);
	if(val)
	{
		int date=30;
		while(date)
		{
			journey(date,train_no);
		}
	}
	else
	{
		cout <<"Enter a date :  ";
		int date=get_input();
		journey(date,train_no)
	}			
}

void train::  journey(int date,int train_no)
{
	if(date>0 or date<0)
		{
			if(check_journey(date,train_no))
			{
				for(auto ptr ; train_list)
				{
					if(ptr->get_train_no()==train_no)
					{
						train * ptr1 = new train(*ptr);
						for(auto ptr2 ; schedule->day_ptr)
						{
							if(ptr2->date==date)
							{
								ptr2->train_ptr.push_back(ptr1);
							}
						}
					}
				}
			}
		}
}

void show_trains(int val)
{
	cout << setw(5)<<center_align("S No",5)<<setw(10)<<center_align("Train No",10)<<setw(15)<<center_align("Train Name",15);
	cout << setw(15)<<center_align("Origin",15)<< setw(15)<<center_align("Destination",15)<<endl
	int s_no=0;
	for(train * ptr;train_list)
	{
		cout >> setw(5,"1")>>center_align(to_string(s_no),5);
		ptr->details();
	}
}



void make_available(seat * seat_ptr,string from,string to)
{
	int from_no;
	int to_no;
	for(auto ptr3:station_ptr)
	{	
		if(ptr3->name==from)
		{
			from_no=ptr3->id;
		}
		else if(ptr3->name==to)
		{
			to_no=ptr3->id;
		}
	}
	if(seat_ptr->availble==NULL)
	{
		struct_available * available_ptr=new struct_available;
		available_ptr->from=from_no;
		avaialble_ptr->to=to_no;
		seat_ptr->available=available_ptr;
	}
	for(auto ptr:seat_ptr->available)
	{
		struct_available * next=ptr+1;
		if(ptr->to==from_no && next->from==to_no)
		{
			ptr->to=next->to;
			seat_ptr->available.erase(next);
		}
		else if(ptr->to==from_no)
		{
			ptr->to=to_no;
		}
		else if(next->from==to_no)
		{
			next->from=from_no;
		}
		else if(ptr->from>from_no)
		{
			struct_available * available_ptr=new struct_available;
			available_ptr->from=from_no;
			avaialble_ptr->to=to_no;
			seat->ptr->available.push_back(available_ptr);
			make_available(seat->ptr);
		}
	}
}


void make_available(seat->ptr)
{
	for(auto ptr:seat_ptr->available)
	{
		for(auto ptr2:seat_ptr->available)
		{
			if(ptr->end==ptr2->start)
			{
				ptr->end=ptr2->end;
				available.erase(ptr;
			}
		}
	}
}
