//Matthew O'Brien
//Assignment 4 December 2nd 2014


//Location of the struct and class used in the BST.
//This is my header file.
//Nothing else to say really, happy holidays.


#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>


using namespace std;

//Constant size input used for dynamically allocating memory later on. Hopefully no songs are longer than 50 characters.
const int size = 50;


//The song node that'll be used for the BST. Holds song information and pointers for left and right.
struct node
{
	char * title;
	char * artist;
	char * album;
	int time;
	int retrieved;
	int value;
	~node();
	node * right;
	node * left;
};
//This is the class for the BST. It will contain the functions, and the wrapper functions needed to test the ADT.
//I was thinking it would've been best to toss the functions calling for "root" within private, but I figured it didn't really matter, and was more of a style than a requirement.
class bst
{
	public:
		bst();
		~bst();
		int remove_all(node *& root);
		int menu_function();
		int load_song();
		int insert_node(node *& root, node *& to_add);
		int retrieve(node * root, char * title, node *& to_find);
		int retrieve(char * title, node *& to_find);
		int display(node * root);
		int display();
		int remove(node *& root, char * title);
		int remove(char * title);
		int title_switch(char * title);
		int display_one(node *& to_show);
	private:
		node * root;
};

	
