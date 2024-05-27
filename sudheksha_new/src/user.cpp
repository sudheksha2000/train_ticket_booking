#include "user.hpp"


user_base :: user_base(string name,string gender,int age)
{
	this->name=name;
	this->gender=gender;
	this->age=age;
}

user_base :: ~user_base()
{
}

user_derived::user_derived(string name,string gender,int age,struct passenger_list * list) : user_base(name,gender,age)
{
	this->list=list;
	this->wallet = 0;
}

user_derived :: ~user_derived()
{
}

void  user_derived :: set_id (long int id)
{
	this->id =id;
}

void user_derived :: add_tickets(vector <ticket *> tickets)
{
	for(auto ptr:tickets)
	{
		booked.push_back(ptr);
	}
}

void user_derived::add_wallet(int amount)
{
	wallet+=amount;
}

void user_derived :: ticket_far_red(int amount)
{
	wallet+=amount;
	
	cout<<"Amount  :  "<<amount << "added to wallet\n";
	cout << "Current balance :  "<< wallet << endl;
}


void user_derived::cancel_ticket(user_derived* user)
{
	int number=1;
	int count=1;
	if(!user->booked.size())
	{
		cout<<endl;
		cout<<"NO TICKETS"<<endl;
		return;
	}
	for(auto ptr : user->booked)
	{
		cout<< "S_No  :  "<<number<<endl;
		ptr->get_details();
		number++;
	}
	cout << "Enter ticket number  :  ";
	number=get_input(1);
	for(auto ptr : user->booked)
	{
		if(number==count)
		{
			if(ptr->get_status()=="*CONFIRMED*")
			{
				make_available(ptr->get_seat_ptr(),ptr,ptr->get_from(),ptr->get_to());
				cout << "	Ticket was cancelled , refund was credited";
				ptr->status="Cancelled";
				cout<<endl;
				user->ticket_far_red(ptr->get_fare());
			}
		}
		count++;
	}
}

// void user_derived :: cancel_waiting_list()
// {
// 	//
// }

user_derived * create_user_fileio(ifstream &in)
{
	char name[20];
	char gender[20];
	int age;
	in.getline(name,20);
	in.getline(gender,20);
	in >> age;
	string sname=upper(name);
	string sgender=upper(gender);
	struct passenger_list * list=new passenger_list;
	list->obj = new passenger(sname,sgender,age);
	user_derived *ptr = new user_derived(sname,sgender,age,list);
	return ptr;
}



