//Matthew O'Brien
//Assignment 2
//CPP file containing the functions of the list ADT.



#include "list.h"



//Constructor for queue class.
queue::queue()
{
	store_rear = NULL;
}
	


//Destructor for queue class.
queue::~queue()
{
	store_node * current = store_rear->next;
	store_rear->next = NULL;
	while(current)
	{
		store_rear = current -> next;
		delete current;
		current = store_rear;
	}
}	
	


//Adds a store to the back of the list. As well as copying all of the products and features of that 
//that store.
int queue::enqueue(store_node & toadd_store)
{
	if(!toadd_store.store_name)
		return 0;

	store_node * temp_store = new store_node;
	temp_store -> store_name = new char[strlen(toadd_store.store_name)+1];
	strcpy(temp_store -> store_name, toadd_store.store_name);

	if(!store_rear)
	{
		store_rear = temp_store;
		temp_store -> next = temp_store;
	}
	else
	{
		temp_store -> next = store_rear -> next;
		store_rear -> next = temp_store;
	}
	
	product_node * product_current = toadd_store.product_head;
	
	while(product_current)
	{
		product_node * temp_product = new product_node;
		temp_product -> product_name = new char[strlen(product_current -> product_name)+1];
		strcpy(temp_product -> product_name, product_current -> product_name);
		
		temp_product -> next = temp_store -> product_head;
		temp_store -> product_head = temp_product;
		
	
	
		feature_node * feature_current = product_current -> feature_head;

		while(feature_current)
		{
			feature_node * temp_feature = new feature_node;
			temp_feature -> features = new char[strlen(feature_current -> features)+1];
			strcpy(temp_feature -> features, feature_current -> features);
			
			temp_feature -> next = temp_product -> feature_head;
			temp_product -> feature_head = temp_feature;

			feature_current = feature_current -> next;
		}
		
		product_current = product_current -> next;
	}
	return 1;
}




//Removes the front of the list to the rejected pile.
int queue::dequeue(store_node & toremove_store)
{

	store_node * current = store_rear -> next;
	
	toremove_store.store_name = new char[strlen(current -> store_name)+1];
	strcpy(toremove_store.store_name, current -> store_name);
	
	current = current -> next;
	
	

}




//Displays the full queue of stores available
int queue::display()
{
	if(!store_rear)
		return 0;

	store_node * current = store_rear -> next;
	
	do
	{
		cout<<current -> store_name<<endl;
		current = current -> next;

	}while(current != store_rear);
}
