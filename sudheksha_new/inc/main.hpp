#ifndef MAIN_HPP

#define MAIN_HPP

#include "header.hpp"
#include "binary.hpp"
#include "train.hpp"
#include "passenger.hpp"
#include "ticket.hpp"

binary_tree_class *tree;
vector <train *> journey;

void train_selection(user_derived *val);
 void binary_search(user_derived*);
 void create_journey();
void user();
void admin_function();
void  signup();
void login();
void book_ticket_main(user_derived *);
void show_ticket(user_derived *);
user_derived * create_user_fileio(ifstream &in);
string upper(string word);
void load_data();
template <class x > x get_input(x a);
void  check_availablity(user_derived*);
void cancel_ticket(user_derived*);
void add_train();
void id_gen(user_derived * ptr);
void show_user();
string center_align(const string str, int width);
void initialize_function();
void account_selection();
void view_money(user_derived* ptr);
void load_trainData();

#endif
