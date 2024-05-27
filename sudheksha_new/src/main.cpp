#include "main.hpp"
vector <train *> train_list;
month* schedule;

int main()
{
	initialize_function();
	account_selection();
}

void initialize_function()
{
	schedule=new month(30);
	tree =new binary_tree_class;
	load_data();
	load_trainData();
}

void account_selection()
{
	void (*func_ptr[2])()={admin_function,user};
	while(1)
	{
		cout<<"\n0  =  Exit\n1  =  Admin\n2  =  User\nEnter an Number  :  ";
		int input=get_input(input);
		if(!input)
		{
			break;
		}
		if(input==1 or input ==2)
		{
			input--;
			func_ptr[input]();
		}
	}
}

void load_data()  
{
	ifstream in;
	in.open("data.txt");
	while(!in.eof())
	{	
		user_derived *ptr=create_user_fileio(in);
		tree->binary_search(ptr);
	}
}

void admin_function()
{
	void (*func_ptr[3])()={add_train,create_journey,show_user};
	while(1)
	{
		int input;
		cout << "\n0  =   Back\n1  =  Add train\n2  =  Add journey\n3  =  Show user\nEnter an Number  :  ";
		input=get_input(input);
		if(!input)
		{
			break;
		}
		if(input>=1 || input <=4)
		{
			input--;
			func_ptr[input]();
		}
	}
}

void add_train()
{
	train * ptr2 = new train();
	train_list.push_back(ptr2);
	cout << "Train was created\nYou can create journey for this train\n";
	cout<<"Here checking seat "<<ptr2->get_avail_2s();
}




void user()
{
	void (*func_ptr[2])()={signup,login};
	while(1)
	{
		int input;
		cout << "\n0  =  Back\n1  =  Signup\n2  =  Login\nEnter an Number  :  ";
		input=get_input(input);
		if(!input)
		{
			break;
		}
		if(input>=1 && input <=2)
		{
			input--;
			func_ptr[input]();
		}
	}
}

void signup()
{
	string name;
	string gender;
	int age;
	cout << "\nEnter a name  :  ";
	getline(cin,name);
	cout << "Enter a gender  :  ";
	getline(cin,gender);
	cout << "Enter a age   :  ";
	age=get_input(age);
	name=upper(name);
	gender=upper(gender);
	struct passenger_list * list=new passenger_list;
	list->obj= new passenger(name,gender,age);
	user_derived *ptr = new user_derived(name,gender,age,list);
	tree->binary_search(ptr);
}


void login()
{
	long int id;
	cout << "\nEnter an login ID  :  ";
	id=get_input(id);
	user_derived * ptr = tree->check(id);
	if (ptr)
	{
		void (*func_ptr[5])(user_derived *)={train_selection,show_ticket,cancel_ticket,add_money,view_money};
		int input;
		while(1)
		{
			cout << "\n0  =  Back\n1  =  Book tickets\n2  =  Show tickets\n";
			cout << "3  =  cancel ticket\n4  =  Add money\n5  =  Balance money\nEnter an Number  :  ";
			input = get_input(input);
			if(!input)
			{
				return;
			}
			if(input>=1 && input <=5) 
			{
				input--;
				func_ptr[input](ptr);
			}
		}
	}
	else 
	{
		cout << "Wrong credentials"<< endl;
		return;
	}
}

void cancel_ticket(user_derived * ptr)
{
	ptr->cancel_ticket(ptr);
}


void add_money(user_derived * ptr)
{
	cout << "Enter an amount  :  ";
	int amount=get_input(1);
	if(amount>0)
	{
		ptr->add_wallet(amount);
	}
}

void view_money(user_derived* ptr)
{
	cout<<"Balance amount : ";
	cout<<ptr->get_wallet();
}

void show_ticket(user_derived *val)
{
	for(auto ptr:val->get_ticket())
	{
		cout << "\nticket_details:  \n";
		ptr->get_details();  //tickets
	}
}



string upper(string word)
{
	string result;
	for(char a:word)
	{
		result += toupper(a);
	}
	return result;
}


void show_user()
{
	tree->locate_user();
}


template <class x > x get_input(x a)
{
	x result;
	while(1)
	{
		string input;
		getline(cin,input);
		stringstream ss(input);
		if (ss >> result)
		{
			return result;
		}
		else 
		{
			cout << "\nYou entered  : "<<input << "\nEnter an number  :  ";
		}
	}
}


string center_align(const string str, int width) {
    int strLength = str.length();
    if (strLength >= width) 
    {
        return str; 
    } else
    {
        int leftPadding = (width - strLength) / 2;
        int rightPadding = width - strLength - leftPadding;
        return string(leftPadding, ' ') + str + string(rightPadding, ' ');
    }
}

void load_trainData()
{
	ifstream file("train.txt");
	static int count=0;
	string line;
	if(!file.is_open())
	{
		cout<<"Error while opening train.txt file"<<endl;
		exit(1);
	}
	while(getline(file,line))
	{
		train *train_obj = new train(line);	
		train_list.push_back(train_obj);		
	}
	cout<<"Add journey for created trains!!"<<endl;
}

