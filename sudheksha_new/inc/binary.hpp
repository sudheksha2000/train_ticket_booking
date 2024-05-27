#ifndef BINARY_TREE_HPP

#define BINARY_TREE_HPP

#include "header.hpp"
#include "user.hpp"


struct user_list
{
	user_derived *object;
	struct user_list *next;
	user_list():next(nullptr){};
};

struct gender_ptr
{
	int id;
	struct user_list * male;
	struct user_list * female;
	gender_ptr(int id): id(id){};
};

struct age_ptr
{
	struct gender_ptr * below5;
	struct gender_ptr * above60;
	struct gender_ptr * between5_60;
	age_ptr(int id):below5(nullptr),above60(nullptr),between5_60(nullptr){};
};

struct name_ptr
{
	struct age_ptr * A_M;
	struct age_ptr * N_Z;
};

class binary_tree_class
{
    struct name_ptr * binary_tree;
public:
    binary_tree_class();
    void binary_search (user_derived * ptr);
    struct gender_ptr * check_age(int age,struct age_ptr * temp);
    struct user_list * check_gender(string gender,struct gender_ptr * temp,user_derived * ptr);
    struct age_ptr * check_name(string name,struct name_ptr * temp);
    user_derived * check(long int id);
    void show_user(user_list * temp);
    void locate_user();
};

void id_gen(user_derived * ptr);
#endif
