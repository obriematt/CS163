//Matthew O'Brien
//Header file containing the struct and classes used in this assignment.
//Homework 3



#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;


//A constant int used for data imput
const int SIZE = 50;


//My song node including all the song's information
struct node
{
	char * title;
	char * artist;
	char * album;
 	int time;
	int retrieved;
	node * next;
	~node();
};



//The ADT's functions and private data. The size for the constructor is set to 5 but can be easily changed from
//here in order to deal with larger sizes of data.
class hash_table
{
	public:
		hash_table(int size = 5);
		~hash_table();
		int menu_function();
		int load_song();
		int retrieve(char * title, node *& to_find);
		int display();
		int remove(char * title);
		int hash_function(char * title);
		int display_one(node *& to_show);

	private:
		node ** table;
		int hash_table_size;
};
