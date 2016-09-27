//Matthew O'Brien
//Assignment 2
//This CPP file will be used for the destructors of the 4 structs. I made this extra file simply for organization. The other files were strictly
//used for the queue, stack, and ordered list. This way I kept to that organization, and made a new file for the structs alone. 




#include "list.h"


//Feature node destructor
feature_node::~feature_node()
{
	delete [] features;
	next = NULL;
}


//Product node destructor
product_node::~product_node()
{
	delete [] product_name;
	next = NULL;
	feature_head = NULL;
}



//Store node destructor
store_node::~store_node()
{

	delete [] store_name;
	next = NULL;
	product_head = NULL;
} 



//Stack node destructor
{
	
	array_head = NULL;
	next = NULL;
}


