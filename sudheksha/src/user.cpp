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

user_derived ;; user_derived(string name,string gender,int age,struct passenger_list * list) : user_base(name,gender,age)
{
	this->list=list;
	cout << "user object  "  get_name() << "  was created"<<end;
}

user_derived :: ~user_derived()
{
	cout << "user object  " << get_name() << "  was destroyed"<<endl;
}

void  user_derived : set_id (long int id)
{
	this.id =id;
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
	cout << "Cuurent balace :  "<< wallet << endl;
}


void  cancel_ticket(user_derived * user);
{
	int number=1;
	for(auto ptr : user->booked)
	{
		cout<< "S_No  :  "<<number<<endl;
		ptr.get_details();
	}
	cout << "Enter ticket number  :  ";
	number=get_input(1);
	for(auto ptr : user->booked)
	{
		if(!number)
		{
			if(ptr->status=="CONFIRMED")
			{
				make_available(ptr->seat_ptr,from,to);
				cout << "	Ticket was cancelled , refund was credited";
				ptr->status="Cancelled";
				user->add_wallet(ptr->fare);
			}
		}
	}
}


user_derived * create_user_fileio(ifstream &in)
{
	char name[20];
	char gender[20];
	int age;
	in->getline(name,255);
	in->getline(gender,255):
	in >> age;
	string sname=upper(name);
	string sgender=upper(gender);
	struct passenger_list * list=new passenger_list;
	list->obj = new passenger(sname,sgender);
	user_derived *ptr = new user_derived(sname,sgender,age,list);
	return ptr;
}

