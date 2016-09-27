//Matthew O'Brien
//Assignment 2
//Header File.
//This file contains all of the structs, classes, and prototypes that are used for the three different ADTs.


#include <cstring>
#include <cctype>
#include <iostream>


using namespace std;

const int SIZE = 100;
const int MAX = 5;


//Feature node to handle the features of the product.
struct feature_node
{
	char * features;
	int position;
	feature_node * next;
	~feature_node();
};



//Product node used to handle the list of each product. This will link up with an individual store
//And each product should have their list of features for comparison
struct product_node
{
	char * product_name;
	product_node * next;
	feature_node * feature_head;
	~product_node();
};


//The store node is used to contain the list of stores that will be searched, which will point to a
//list of products that each store contains, which then goes into their features.
struct store_node
{
	char * store_name;
	store_node * next;
	product_node * product_head;
	~store_node();
};



//The struct specifically for the stack class. It will handle the store nodes as well, to access the names of 
//the rejected stores from the queue. Contains an array and a node pointer.
struct stack_node
{
	store_node * array_head;
	stack_node * next;
	~stack_node();
};


//First ADT to handle the ordered list of the features that the user desires. These will be handled by a node that 
//contains an array of features. It will be determined by the size or amount of features that the user will want to
//compare. Nothing will be prompted by the user, rather the test function will gather that size, and set it into
//this int variable in the class.
class ordered_list
{
	public:
		ordered_list();
		~ordered_list();
		int insert(int position, feature_node & toadd_feature);
		int remove(int position);
		int retrieve(int position, feature_node & tofind_feature);
		int display();
		int build_array(int total_size);
	private:
		feature_node * feature_array;
		int total_array;
};




//Second ADT. The queue used in a circular linked list. Used to search through the stores and products
//to determine if these stores' products have the desired features. The dequeue function will actually be used
//in sequence with the push function from the stack class to "reject" a store.
class queue
{
	public:
		queue();
		~queue();
		int enqueue(store_node & toadd_store);
		int dequeue(store_node & toremove_store);
		int display();
	private:
		store_node * store_rear;
};




//Third ADT. The stack used to store the rejected stores that the user decided they did not want, and
//the go over here. This class has it's own node struct that will have a size index, equal to 5, that determines 
//how many stores go into each node. Allowing the stack to build up. 
class stack
{

	public:
		stack();
		~stack();
		int push(store_node & toadd_store);
		int pop();
		int peek(store_node & tosee_store);
		int display();
	private:
		stack_node * stack_head;
		int top_index;
};









		


