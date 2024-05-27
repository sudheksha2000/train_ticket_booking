#include "binary.hpp"


binary_tree_class::binary_tree_class()
{
    binary_tree = new name_ptr;
	binary_tree->A_M= new gender_ptr(1);
	binary_tree->N_Z=new gender_ptr(1);
	binary_tree->A_M->below5 =new gender_ptr(11);
	binary_tree->A_M->above60 =new gender_ptr(12);
	binary_tree->A_M->between5_60 =new gender_ptr(13);
	binary_tree->N_Z->below5 =new gender_ptr(21);
	binary_tree->N_Z->above60 =new gender_ptr(22);
	binary_tree->N_Z->between5_60 =new gender_ptr(23);
}

void binary_tree_class :: binari_search (user_derived * ptr)
{
	struct age_ptr * age=check_name(ptr->get_name(),binary_tree);
	if(age)
	{
		struct gender_ptr * gender=check_age(ptr->get_age(),age);
		if(gender)
		{
			struct user_list * head=check_gender(ptr->get_gender(),gender,ptr);
			if(head)
			{
				head->object=ptr;
				id_gen(ptr);
				cout << "ID  :  "<<ptr->get_id()<< "\nUse it for login\n\n";
				return;
			}
		}
	}
	ptr->del_list();
	delete ptr;
}


struct age_ptr * binary_tree_class ::check_name(string name,struct name_ptr * temp)
{
	if (name[0]>=65 && name[0]<=77)
	{
		return temp->A_M;
	}
	else if(name[0]>=78 && name[0]<=90) 
	{
		return temp->N_Z;
	}
	else 
	{
		return NULL
	}
}

struct gender_ptr * binary_tree_class ::check_age(int age,struct age_ptr * temp)
{
	if(age>=0 && age<=5)
	{
		return temp->below5;
	}
	else if(age>=6 && age<=60)
	{
		return temp->between5_60;
	}
	else if(age>60 and age<100)
	{
		return temp->above60;
	}
	else 
	{
		return NULL;
	}
}

struct user_list * binary_tree_class ::check_gender(string gender,struct gender_ptr * temp,user_derived * ptr)
{
	long int id;
	if(gender=="MALE")
	{
		id=(temp->id*10)+1;
		ptr->set_id(id);
		struct user_list * head=temp->male;
		if(head)
		{
			while(head->next)
			{
				head=head->next;
			}
			head->next=new user_list;
			return head->next;
		}
		else
		{
			head=new user_list;
			temp->male=head;
			return head	
		}
	}	
	else if(gender=="FEMALE")
	{ 
		id=(temp->id*10)+2;
		ptr->set_id(id);
		struct user_list * head=temp->female;
		if(head)
		{
			while(head->next)
			{
				head=head->next;
			}
			head->next=new user_list;
			return head->next;
		}
		else
		{
			head=new user_list;
			temp->female=head;
			return head;
		}
	}
	else return NULL;
}

void id_gen(user_derived * ptr)
{
	static int val=0;
	long int result=(ptr->get_id()*100000)+val;
	val++;
	ptr->set_id(result);
}

user_derived * binary_tree_class:: check(long int id)
{
	user_derived * ptr=NULL;;
	int one=0,two=0,three=0;
	long int id1=id;
	while(id1)
	{
		three=two;
		two=one
		one=id1%10;
		id1=id1/10;
	}
	if(!one && !two && !three)
	{
		return ptr;
	}
	struct age_ptr * age;
	struct gender_ptr * gender;
	struct user_list * current;
	if(one==1) age=binary_tree->A_M;
	if(one==2) age=binary_tree->N_Z;
	if(two==1) gender=age->below5;
	if(two==3) gender=age->between5_60;
	if(two==2) gender=age->above60;
	if(three==1) current=gender->male;
	if(three==2) current=gender->female;
	while(current)
	{
		if(current->object->get_id==id)
		{
			cout << "\nLogged in  successful  :  ";
			cout << current->object->get_name()<<endl;
			return current->object
		}
		current=current->next;
	}
	return ptr;
}

void binary_tree_class:: locate_user()
{
	
	cout << "USERS:\n";
	user_list * head=binary_tree->A_M->below5->male;
	show_user(head);
	head=binary_tree->A_M->below5->female;
	show_user(head);
	head=binary_tree->A_M->between5_60->male;
	show_user(head);
	head=binary_tree->A_M->between5_60->female;
	show_user(head);
	head=binary_tree->A_M->above60->male;
	show_user(head);
	head=binary_tree->A_M->above60->female;
	show_user(head);
	head=binary_tree->N_Z->below5->male;
	show_user(head);
	head=binary_tree->N_Z->below5->female;
	show_user(head);
	head=binary_tree->N_Z->between5_60->male;
	show_user(head);
	head=binary_tree->N_Z->between5_60->female;
	show_user(head)
	head=binary_tree->N_Z->above60->male;
	show_user(head);
	head=binary_tree->N_Z->above60->female;
	show_user(head);
	
}

void binary_tree_class :: show_user(user_list * temp)
{
	while(temp)
	{
		cout << temp->object->get_name<<endl;
		temp=temp->next;
}
