#include "train.hpp"

extern month * schedule;
#define VAL 0x00

extern vector <train *> train_list;

train :: train()
{
	cout << "\nTrain details  :  \nEnter train No  :  ";
	train_no=get_input(1);
	cout << "Enter train name  	:  ";
	getline(cin,train_name);
	cout << "Enter origin place :  ";
	getline(cin, origin);
	cout << "Enter destination place :  ";
	getline(cin, destination);
	train_name=upper(train_name);
	origin=upper(origin);
	destination=upper(destination);
	available_2s=0;
	available_sl=0;
	waiting_2s = 1;
	waiting_sl = 1;
	int check=middle_station();
	coach_alloc(check);
	
}

int train :: middle_station()
{
	cout << "Enter total station   :  ";
	int count=get_input(count);
	int id=1;
	for(int i=0;i<count;i++)
	{
		station * ptr=new station(id);
		station_ptr.push_back(ptr);
		id++;			   
	}
	return count;
}

station :: station(int id)
{
	cout << "Enter a station  name  :  ";
	string station_name;
	getline(cin,station_name);
	cout << "Enter a distance  :  ";
	this->name = upper(station_name);
	distance=get_input(1);
	this->distance = distance;
	this->id=id;
}



int train :: coach_alloc(int check)
{
	cout <<"\nCoach details : \n";
	int coach_count;
	cout << "Enter coach count  :  ";
	coach_count=get_input(1);
	while(coach_count)
	{
		cout << "1  =  second sitting\n2  =  sleeper\n";
		cout << "Enter coach type  :  ";
		int type_number=get_input(1);
		if(type_number<1 or type_number>3) return coach_count;
		coach * ptr=new coach(type_number,check,false);
		coach_ptr.push_back(ptr);
		coach_count--;
		if(type_number==1)
		{
			available_2s+=108;
		}
		else
		{
			available_sl+=72;
		}
	}
	return 0;
}


coach :: coach(int type_number,int check,bool print)
{
	if(print)
	{
		static int num = 1;
		coach_number = "s" + to_string(num);
		num++;
	}
	else
	{
		cout << "Enter coach No  :  ";
		getline(cin,coach_number);
	}
	int seat_count,seat_no;
	seat_no=1;
	if(type_number==1)
	{
		this->type="SECOND SITTING";
		seat_count=108;
		seat_ptr_2s = new seat_struct_2s;
	}
	else
	{
		this->type="SLEEPER";
		seat_count=72;
		seat_ptr_sl = new seat_struct_sl;
	}
	while(seat_count)
	{
		seat_alloc(seat_no,check);
		seat_no++;
		seat_count--;
	}
}

void coach :: seat_alloc(int seat_no,int check)
{
	seat * ptr=new seat(seat_no,check,type);
	if(type=="SLEEPER")
	{
		seat_no%=8;
		if(seat_no==1 or seat_no==4)
		{
			seat_ptr_sl->lower.push_back(ptr);
		}
		else if(seat_no==2 or seat_no==5)
		{
			seat_ptr_sl->middle.push_back(ptr);
		}
		else if(seat_no==3 or seat_no==6)
		{
			seat_ptr_sl->upper.push_back(ptr);
		}
		else if(seat_no==7)
		{
			seat_ptr_sl->s_lower.push_back(ptr);
		}
		else
		{
			seat_ptr_sl->s_upper.push_back(ptr);
		}
	}
	else
	{
		seat_no%=6;
		if(seat_no==1 or seat_no==4)
		{
			seat_ptr_2s->window.push_back(ptr);
		}
		else if(seat_no==2 or seat_no==5)
		{
			seat_ptr_2s->middle.push_back(ptr);
		}
		else
		{
			seat_ptr_2s->aisle.push_back(ptr);
		}
	}
}

seat :: seat(int seat_no,int check,string type)
{
	this->seat_number=seat_no;
	available_struct *avail = new available_struct;
	avail->start=1;
	avail->end=check;
	this->start = 1;
	this->end = check;
	this->type = type;
	this->available.push_back(avail);
}

void train :: train_details()
{
	cout << setw(10)<<center_align(to_string(train_no),10);
	cout << setw(15)<<center_align(train_name,15);
	cout << setw(15)<<center_align(origin,15);
	cout << setw(15)<<center_align(destination,15)<<endl;
}

void train :: specific_detail()
{
	cout << "Train no   :  "<<train_no<<endl;
	cout << "Train name  :  "<<train_name<<endl;
	cout << "Origin  	:  "<<origin<<endl;
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
	available_2s = obj.available_2s;
	available_sl = obj.available_sl;
	for(auto ptr : obj.coach_ptr)
	{
		coach * ptr1=new coach(*ptr);  //changed
		coach_ptr.push_back(ptr1);
	}
	station_ptr=obj.station_ptr;
	waiting_2s = waiting_sl = 1;
}
	
coach :: coach(const coach &obj)
{
	coach_number=obj.coach_number;
	type=obj.type;
	available = obj.available;
	seat_ptr_2s = new seat_struct_2s;
	seat_ptr_sl = new seat_struct_sl;
	if(type=="SECOND SITTING")
	{
		for(auto ptr :obj.seat_ptr_2s->aisle)
		{
			seat * ptr1= new seat(*ptr);
			seat_ptr_2s->aisle.push_back(ptr1);
		}
		for(auto ptr :obj.seat_ptr_2s->middle)
		{
			seat * ptr1= new seat(*ptr);
			seat_ptr_2s->middle.push_back(ptr1);
		}
		for(auto ptr :obj.seat_ptr_2s->window)
		{
			seat * ptr1= new seat(*ptr);
			seat_ptr_2s->window.push_back(ptr1);
		}
	}
	else
	{
		for(auto ptr :obj.seat_ptr_sl->lower)
		{
			seat * ptr1= new seat(*ptr);
			seat_ptr_sl->lower.push_back(ptr1);
		}
		for(auto ptr :obj.seat_ptr_sl->upper)
		{
			seat * ptr1= new seat(*ptr);
			seat_ptr_sl->upper.push_back(ptr1);
		}
		for(auto ptr :obj.seat_ptr_sl->middle)
		{
			seat * ptr1= new seat(*ptr);
			seat_ptr_sl->middle.push_back(ptr1);
		}
		for(auto ptr :obj.seat_ptr_sl->s_lower)
		{
			seat * ptr1= new seat(*ptr);
			seat_ptr_sl->s_lower.push_back(ptr1);
		}
		for(auto ptr :obj.seat_ptr_sl->s_upper)
		{
			seat * ptr1= new seat(*ptr);
			seat_ptr_sl->s_upper.push_back(ptr1);
		}
	}

};


seat :: seat(const seat &obj)
{	
	seat_number=obj.seat_number;
	start=obj.start;
	end=obj.end;
	available_struct* ptr = new available_struct;
	ptr->start=start;
	ptr->end=end;
	type = obj.type;
	available.push_back(ptr);
};


void train_selection(user_derived *val)
{
	vector<train *> temp_train;
	cout << "Enter a date  :  ";
	int date=get_input(1);
	if(date<1 or date>31) return;
	cout << "Enter from station  :  ";
	string from,to;
	int fare;
	getline(cin,from);
	cout<< "Enter to station  :  ";
	getline(cin,to);
	from=upper(from);
	to=upper(to);
	if(filter_train(date,from,to,&temp_train))
	{
		if(temp_train.empty())
		{
			cout<<"\n0 results\n"<<endl;
			return;
		}
		choosing:
		cout << "Enter train no  :  ";
		int train_no=get_input(1);
		for(auto ptr2: temp_train)
		{
			if(ptr2->get_train_no()==train_no)
			{
				system("clear");
				cout<<ptr2->get_train_name()<<"("<<ptr2->get_train_no()<<")"<<endl;
				cout<<endl;
				ptr2->train_availablity(from,to);
				cout<<endl;
				cout<<"0  =  Back\n1  =  Continue\n";
				int choice = get_input(choice);
				if(!choice)
				{
					for(auto show_ptr:temp_train)
					{
						show_ptr->train_details();
					}
					goto choosing;
				}
				cout << "1  =  second sitting\n2  =  sleeper\n";
				cout << "Enter coach type  :  ";
				int type_number=get_input(1);
				if(type_number<1 or type_number>3) return;
				type_number--;
				string type = (type_number) ? "SLEEPER" : "SECOND SITTING";
				fare = get_fare(from,to,ptr2);
				if(type=="SLEEPER")
				{
					if(ptr2->get_avail_sl()==0) 
					{
						add_passenger_wl(type,ptr2,fare*0.5,from,to,val);
					}
					fare*=0.5;
				}
				else
				{
					if(ptr2->get_avail_2s()==0)
					{
						add_passenger_wl(type,ptr2,fare*0.75,from,to,val);
					}
					fare*=0.75;
				}
				ptr2->book_ticket_option(val,ptr2,type,fare,from,to);
			}
		}
	}
	else
	{
		cout << "\nNo  trains available\n";
	}
		
}


bool filter_train(int date,string from, string to,vector <train *> *ptr4)     //big
{
	for (auto ptr: schedule->day_ptr)
	{
		if(ptr->date==date)
		{
			if(ptr->train_ptr.empty()) return false;
			for(auto ptr1 : ptr->train_ptr )
			{
				if(ptr1->filter_src_des(from,to))
				{
					ptr4->push_back(ptr1);
					ptr1->train_details();
				}
			}
		}
	}
	return true;
}

bool train :: filter_src_des(string from, string to)
{
	int check=0;
	if(from==to)
	{
		return false;
	}
	for(auto ptr : station_ptr)
	{
		if(ptr->get_name()==from)
		{
			check=1;
		}
		if(ptr->get_name()==to && check)
		{
			return true;
		}
	}
	return false;
}



void train:: train_availablity(string from,string to)
{
	int sleeper = 0;
	int second_sitting = 0;
	for(auto ptr : coach_ptr)
	{
		if(ptr->get_type()=="SLEEPER")
		{

			berth_availablity(ptr->seat_ptr_sl->lower,from,to,&sleeper,&second_sitting,this);
			berth_availablity(ptr->seat_ptr_sl->middle,from,to,&sleeper,&second_sitting,this);
			berth_availablity(ptr->seat_ptr_sl->upper,from,to,&sleeper,&second_sitting,this);
			berth_availablity(ptr->seat_ptr_sl->s_lower,from,to,&sleeper,&second_sitting,this);
			berth_availablity(ptr->seat_ptr_sl->s_upper,from,to,&sleeper,&second_sitting,this);
		}
		else
		{
			berth_availablity(ptr->seat_ptr_2s->window,from,to,&sleeper,&second_sitting,this);
			berth_availablity(ptr->seat_ptr_2s->aisle,from,to,&sleeper,&second_sitting,this);
			berth_availablity(ptr->seat_ptr_2s->middle,from,to,&sleeper,&second_sitting,this);
		}
	}
	if(!sleeper)
	{
		cout<<"sleeper  : WL/"<<waiting_sl<<endl;
	}
	else
	{
		cout << "sleeper  :  "<<sleeper<<endl;
	}
	if(!second_sitting)
	{
		cout<<"second sitting :	WL/"<<waiting_2s<<endl;
	}
	else
	{
		cout << "second sitting  :"<< second_sitting<<endl;
	}
}

void berth_availablity(vector<seat *>seat_ptr,string from, string to,int * sleeper,int * second_sitting, train* train_ptr)
{

	for(auto ptr1 :  seat_ptr)
	{
		if(train_ptr->seat_check(ptr1,from,to))
		{
			if(ptr1->get_type()=="SLEEPER")
			{
				*sleeper+=1;
			}
			else
			{
				*second_sitting+=1;
			}
		}

	}
}


bool train::seat_check(seat * ptr1,string from, string to)
{
	int from_no;                         
	int to_no;
	for(auto ptr3:station_ptr)     
	{	
		if(ptr3->get_name()==from)
		{
			from_no=ptr3->get_id();
		}
		else if(ptr3->get_name()==to)
		{
			to_no=ptr3->get_id();
		}
	}
	if(ptr1->available.empty())
	{
		return 0;
	}
	else
	{
		for(auto ptr2 : ptr1->available)
		{
			if((ptr2->start <= from_no) && (ptr2->end >= to_no)) //biggg ptr1->get_start
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
				ptr->get_details();
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
				train_ptr1->proceed(user,temp,train_ptr1,type,fare,from,to);
				exit=0;
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
	string array[6];
	string pref;
	if(type=="SLEEPER")
	{
		cout << "1  =  Lower\n2  =  Middle\n3  =  Upper\n4  =  Side Lower\n5  =  Side Upper\n6  =  No choice\n";
		array[0]="LOWER";
		array[1]="MIDDLE";
		array[2]="UPPER";
		array[3]="SIDE LOWER";
		array[4]="SIDE UPPER";
		array[5]="NO CHOICE";
	}
	else
	{
		cout << "1  =  Window\n2  =  Middle\n3  =  Aisle\n4  =  No choice\n";
		array[0]="WINDOW";
		array[1]="SITTING_MIDDLE";
		array[2]="AISLE";
		array[3]="NO CHOICE";
	}
	cout << "Enter a prefernce  :  ";
	int prefrence=get_input(1);
	if(type=="SLEEPER" && (prefrence>0 || prefrence <6))
	{
		pref.assign(array[--prefrence]);	
		
	}
	else if(type=="SECOND SITTING" && (prefrence>0 || prefrence <4))
	{
		pref.assign(array[--prefrence]);
	}
	else
	{
		return nullptr;
	}
	name=upper(name);
	gender=upper(gender);
	passenger * list=new passenger(name,gender,age,pref);
	return list;
}



void train::proceed(user_derived * user,vector <passenger *>temp,train * train_ptr1,string type,int fare,string from,string to)
{
	vector <ticket*> tickets;
	int check=0;
	for(int i=0;i<temp.size();i++)  //ptr = > passenger
	{
		for(auto ptr1 : train_ptr1->coach_ptr)
		{
			if(ptr1->get_type()==type)
			{
				vector<seat *> seat_ptr = berth_selection(ptr1,temp[i]->get_preference());//big
				if(seat_ptr.size()!=0)
				{
					check=confirm(&tickets,user,temp[i],train_ptr1,ptr1,seat_ptr,fare,from,to,type);
				}
				else
				{
					vector <seat *> arr1[5]={ptr1->get_seat_ptr_sl()->lower,ptr1->get_seat_ptr_sl()->middle,
					ptr1->get_seat_ptr_sl()->upper,ptr1->get_seat_ptr_sl()->s_lower,ptr1->get_seat_ptr_sl()->s_upper};
					vector <seat *>arr2[3]={ptr1->get_seat_ptr_2s()->window,ptr1->get_seat_ptr_2s()->middle,
					ptr1->get_seat_ptr_2s()->aisle};
					if(type=="SLEEPER")
					{
						for(auto ptr4: arr1)
						{
							check=confirm(&tickets,user,temp[i],train_ptr1,ptr1,ptr4,fare,from,to,type);
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
							check=confirm(&tickets,user,temp[i],train_ptr1,ptr1,ptr4,fare,from,to,type);
							if(check)
							{
								break;
							}
						}
					}
				}	
			if(check)break;
			}
		}
		if(!check && temp[i]->get_preference()!="NO CHOICE")
		{
			temp[i]->set_preference("NO CHOICE");
			temp.push_back(temp[i]);
			continue;
		}
		else if(!check && temp[i]->get_preference()=="NO CHOICE")  //bigg
		{
			ticket * ptr3=new ticket(temp[i],train_ptr1,0,from,to);
			tickets.push_back(ptr3);
		}
		if(check)check=0;
	}
	user->add_tickets(tickets);
	
	cout<<"Ticket count "<<tickets.size()<<endl;
	for(auto ptr : tickets)
	{
		ptr->get_details();
	}
	temp.clear();
}

vector<seat *> berth_selection(coach * coach_ptr,string preference)  //big
{
	if(preference=="LOWER")
	{
		return coach_ptr->get_seat_ptr_sl()->lower;
	}
	else if(preference=="MIDDLE")
	{
		return coach_ptr->get_seat_ptr_sl()->middle;
	}
	else if(preference=="UPPER")
	{
		return coach_ptr->get_seat_ptr_sl()->upper;
	}
	else if(preference=="SIDE LOWER")
	{
		return coach_ptr->get_seat_ptr_sl()->s_lower;
	}
	else if(preference=="SIDE UPPER")
	{
		return coach_ptr->get_seat_ptr_sl()->s_upper;
	}
	else if(preference=="WINDOW")
	{
		return coach_ptr->get_seat_ptr_2s()->window;
	}
	else if(preference=="SITTING_MIDDLE")
	{
		return coach_ptr->get_seat_ptr_2s()->middle;
	}
	else if(preference=="AISLE")
	{
		return coach_ptr->get_seat_ptr_2s()->aisle;
	}
	return vector<seat*>();	
}



bool confirm(vector <ticket *> *tickets,user_derived * user,passenger * ptr,train * train_ptr1,coach *  ptr1,vector<seat *> seat_ptr,int fare,string from,string to,string type)
{
	int check=0;
	for (auto ptr2 : seat_ptr)
	{
		if(train_ptr1->seat_check(ptr2,from,to))
		{
			user->ticket_fare_red(fare);
			checking_money:
			if(user->get_wallet()>fare)
			{
				ptr2->change_available(ptr2,from,to,train_ptr1);
				ticket * ptr3 = new ticket(ptr,train_ptr1,ptr1,ptr2,fare,from,to); 
				tickets->push_back(ptr3);
				if(type=="SLEEPER" or type=="SECOND SITTING")  //big
				{
					return true;
					check=1;
				}
			}
			else
			{
				cout<<endl;
				cout<<"Wallet amount is insufficient"<<endl;
				cout<<"Added money to continue"<<endl;
				cout<<endl;
				add_money(user);
				goto checking_money;
			}
			
		}
		if(check)break;
	}
	return false;
}

void seat::change_available(seat * ptr,string from, string to, train* train_ptr1)
{
	int from_no;
	int to_no;
	for(auto ptr3:train_ptr1->get_station_ptr())
	{	
		if(ptr3->get_name()==from)
		{
			from_no=ptr3->get_id();
			
		}
		else if(ptr3->get_name()==to)
		{
			to_no=ptr3->get_id();
			
		}
	}
	available_struct* next = new available_struct;
	next = available[0];


	for(int i=0;i<available.size();i++)
	{
		if(i<available.size()-1)
		{
			next = available[i+1];
		}
		if(from_no>start && to_no<end)
		{
			struct available_struct * test=new available_struct;
			test->end=available[i]->end;
			available[i]->end=from_no;
			test->start=to_no;
			available.push_back(test);
			break;
		}
		else if(from_no==start and to_no==end)
		{
			available.erase(available.begin()+i);
		}
		else if(from_no>start and next->start<=available[i]->end)
		{
			available[i]->end=from_no;
		}
		else if(to_no<end and next->end>=available[i]->start)
		{
			available[i]->start=to_no;
		}
	}
}


int get_fare(string from,string to,train* train_ptr)
{
	int distance1=0;
	for(auto ptr:train_ptr->get_station_ptr())
	{
		if(ptr->get_name()==from)
		{
				distance1=ptr->get_distance();
		}
		if(ptr->get_name()==to)
		{
			distance1=ptr->get_distance()-distance1;
		}
	}
	return distance1;
}


month::month(int date)
{
	int date_val=1;
	while (date_val<=date)
	{
		day * ptr=new day(date_val);
		day_ptr.push_back(ptr);
		date_val++;
	}
}

day:: day(int date)
{
	this->date=date;
}

bool check_journey(int day_name,int train_no)
{
	for(auto ptr1 : schedule->get_day_ptr())
	{
		if(ptr1->get_date()==day_name)
		{
			for(auto ptr2 : ptr1->get_train_ptr())
			{
				if(ptr2->get_train_no()==train_no)
				{
					cout << "\nTrain was already running at specified date\n";
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
	int train_no=get_input(train_no);
	cout << "1 =  All dates\n2  =  specfic_date\nEnter an number  :  ";
	int val=get_input(1);
	char who;
	val--;
	if(!val)
	{
		int date=30;
		if(date)
		{
			who = 'a';
			journey_function(date,train_no,who);
		}
	}
	else
	{
		who = 's';
		cout <<"Enter a date :  ";
		int date=get_input(date);
		journey_function(date,train_no,who);
	}			
}

void journey_function(int date,int train_no,char who)
{
	if(date>0 or date<0)
		{
			if(check_journey(date,train_no))
			{
				for(auto ptr : train_list)
				{
					if(ptr->get_train_no()==train_no)
					{
						if(who=='s')
						{
							train * ptr1 = new train(*ptr);
							for(auto ptr2 : schedule->day_ptr)
							{
								if(ptr2->date==date)
								{
									ptr2->train_ptr.push_back(ptr1);
								}
							}
						}
						else if(who=='a')
						{
							for(auto ptr2 : schedule->day_ptr)
							{
								train* ptr1 = new train(*ptr);
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
	cout << setw(15)<<center_align("Origin",15)<< setw(15)<<center_align("Destination",15)<<endl;
	int s_no=0;
	for(train * ptr:train_list)
	{
		cout << setw(5)<<center_align(to_string(++s_no),5);  //bigg stew(5,"1")
		ptr->train_details();
	}
}



void make_available(seat * seat_ptr,ticket* ticket,string from,string to)
{
	int from_no;
	int to_no;
	for(auto ptr3:ticket->get_train_ptr()->get_station_ptr())
	{	
		if(ptr3->get_name()==from)
		{
			from_no=ptr3->get_id();
		}
		else if(ptr3->get_name()==to)
		{
			to_no=ptr3->get_id();
		}
	}
	if(seat_ptr->get_available().size()==0)
	{
		available_struct * available_ptr=new available_struct;
		available_ptr->start=from_no;
		available_ptr->end=to_no;
		seat_ptr->available.push_back(available_ptr);
	}
	available_struct * next = new available_struct;
	for(int i = 0;i<seat_ptr->get_available().size();i++)
	{
		if(i < seat_ptr->get_available().size()-1)
		{
			next = seat_ptr->get_available()[i+1];
		}
		// available_struct * next=seat_ptr->get_available()[i]+1;
		if(seat_ptr->get_available()[i]->end==from_no && next->start==to_no)
		{
			seat_ptr->get_available()[i]->end=next->end;
			seat_ptr->available.erase(seat_ptr->available.begin()+i+1);  //next delete
		}
		else if(seat_ptr->get_available()[i]->end==from_no)
		{
			seat_ptr->get_available()[i]->end=to_no;
		}
		else if(seat_ptr->get_available()[i]->start==to_no)
		{
			seat_ptr->get_available()[i]->start = from_no;
		}
		else if(next->start==to_no)
		{
			next->start=from_no;
		}
		else if(seat_ptr->get_available()[i]->start>from_no)
		{
			available_struct * available_ptr=new available_struct;
			available_ptr->start=from_no;
			available_ptr->end=to_no;
			seat_ptr->available.push_back(available_ptr);
			make_available(seat_ptr);
			break;
		}
	}
}


void make_available(seat* seat_ptr)
{
	int count=0;
	for(auto ptr:seat_ptr->available)
	{
		for(auto ptr2:seat_ptr->available)
		{
			if(ptr->end==ptr2->start)
			{
				ptr->end=ptr2->end;
				seat_ptr->available.erase(seat_ptr->available.begin()+count);
			}
		}
		count++;
	}
}
station :: station(int id,stringstream& input)
{
	string distance;
	getline(input,name,'-');
	this->name = upper(name);
	getline(input,distance,'-');
	this->distance = stoi(distance);
	this->id = id;
}
train::train(string line)
{
	string no;
	stringstream input(line);
	getline(input,no,'-');
	train_no = stoi(no);
	getline(input,train_name,'-');
	getline(input,origin,'-');
	getline(input,destination,'-');
	train_name=upper(train_name);
	origin=upper(origin);
	destination=upper(destination);
	available_2s=0;
	available_sl=0;
	getline(input,no,'-');
	int id = 1;
	int check = stoi(no);
	waiting_2s = waiting_sl = 1;
	for(int i=0;i<check;i++)
	{
		station * ptr=new station(id,input);
		station_ptr.push_back(ptr);
		id++;
	}
	getline(input,no,'-');
	int no_int = stoi(no);
	while(no_int)
	{
		getline(input,no,'-');
		coach *ptr = new coach(stoi(no),check,true);
		coach_ptr.push_back(ptr);
		no_int--;
		if(stoi(no)==1)
		{
			available_2s+=108;
		}
		else
		{
			available_sl+=72;
		}
	}

}

void train::waiting_list(passenger* ptr,int fare,string from,string to,string type,user_derived* user,vector<ticket*> tickets)
{
	if(type=="SLEEPER")
	{	
		passenger_ptr_wl_sl.push_back(make_pair(user,ptr));
		waiting_sl += 1;
	}
	else
	{
		passenger_ptr_wl_2s.push_back(make_pair(user,ptr));
		waiting_2s += 1;
	}
	ticket *ticket_ptr = new ticket(ptr,this,fare,from,to,true);
	tickets.push_back(ticket_ptr);
}

void add_passenger_wl(string type,train* train_ptr,int fare,string from,string to,user_derived* user)
{
	vector<passenger*> temp;
	bool exit = true;
	unsigned char choice;
	while(exit)
	{
		cout<<"1. add passenger\n2. confirm\n3. exit"<<endl;
		cin>>choice;
		if(choice!='1' or choice!='2' or choice!='3')
		{
			continue;
		}
		if(temp.size()==0)
		{
			cout<<"No passenger"<<endl;
		}
		else
		{
			cout<<"Current passenger : "<<endl;
			for(auto ptr:temp)
			{
				ptr->get_details();
			}
		}
		switch(choice)
		{
			case '1':
			{
				temp.push_back(train_ptr->add_passenger(type));
				break;
			}
			case '2':
			{
				checking_money:
				if(user->get_wallet() >= fare*temp.size())
				{
					vector<ticket*> tickets;
					for(auto ptr:temp)
					{
						train_ptr->waiting_list(ptr,fare,from,to,type,user,tickets);
					}
					user->add_tickets(tickets);
				}
				else
				{
					cout<<"Wallet amount is insufficient "<<endl;
					add_money(user);
					goto checking_money;
				}
				break;
			}
			case '3':
			{
				exit=false;
				break;
			}

		}		

	}
}

