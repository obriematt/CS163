//Matthew O'Brien
//Assignment 1. October 21 2014.
//
//Header file that contains the node struct, and data structure.
//Also contains the constant variable size for user inputs.



#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;



//Used for user input of data to dynamically allocate later on.
const int SIZE = 100;	


//The nodes of the the LLL.
struct node
{
	char * hints;
	int likes;

	
	~node();
	node * next;
};


//Data structure for "College Life"
class College_life
{
	public:
		College_life();
		~College_life();
		int add_hint(char category[], char hint[]);
		int likes(char category[], char hint[]);
		int display_all();
		int display(char category[]);
		int menu();
		int sort_list(node *& head, node *& to_change);

	private:
		node * head_registering;
		node * head_materials;
		node * head_homework;
};
