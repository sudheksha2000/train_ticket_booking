#include "passenger.hpp"


passenger :: passenger(string name,string gender,int age) : user_base(name,gender,age)
{
}

passenger :: passenger(string name,string gender,int age,string pref) : user_base(name,gender,age),preference(pref)
{
}

passenger :: ~passenger()
{
}

void user_base::get_details()
{
	cout << "name\t    :  "<<name<<endl;
	cout << "age\t     :  "<<age<<endl;
	cout << "gender\t     :  "<<gender<<endl;
}
