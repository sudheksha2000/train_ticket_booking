#include "ticket.hpp"

ticket::ticket(passenger *ptr1,train * ptr2,coach * ptr3,seat * ptr4,int fare,string  from,string to)
{
	status="*CONFIRMED*";
	passenger_ptr=ptr1;
	train_ptr=ptr2*global;
	coach_ptr=ptr3:
	seat_ptr=ptr4;
	fare=fare;
	from=from;
	to=to;
}


ticket::ticket(passenger *ptr1,train * ptr2,int fare,string from, string to)
{
	status="*NOT BOOKED*";
	passenger_ptr=ptr1;
	train_ptr=ptr2;
	coach_ptr=0x0;
	seat_ptr=0x0;
	fare=fare;
	from=from;
	to=to;
}

vooid ticket::get_details()
{
	cout << "Status :  "<<status<endl;
	passenger_ptr.get_details();
	train_ptr.specific_detail();
	cout << "From  :  "<< from<<endl;
	cout << "To  :  "<<to<<end;
	if(coach_ptr && seat_ptr)
	{
		coach_ptr.details();
		seat_ptr.details();
	}
	cout << "Fare  :   "<<fare<endl;
}


