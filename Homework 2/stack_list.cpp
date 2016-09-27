//Matthew O'Brien
//Assignment 2
//CPP file containing all of the functions used for the "stack" ADT.


#include "list.h"


//Contstructor for the stack class. Setting it's pointers to null.
stack::stack()
{
	stack_head = NULL;
}



//Stack destructor. Should delete each node as well as the character array within the node.
stack::~stack()
{
	while(stack_head)
	{
		stack_node * current = stack_head;
		stack_head = stack_head -> next;
		delete [] current -> array_head;
		delete current;
	}
}
	

//Pushes a rejected store onto the top of the stack. Most recently rejected store to the top.
int stack::push(store_node & toadd_store)
{

	if(!stack_head || top_index == MAX)
	{
		stack_node * temp = new stack_node;
		temp -> array_head = new store_node[MAX];

		top_index = 0;

		temp -> array_head[top_index].store_name = new char[strlen(toadd_store.store_name)+1];
		strcpy(temp->array_head[top_index].store_name, toadd_store.store_name);
		
		++top_index;
		
		temp -> next = stack_head;
		stack_head = temp;
		return 1;
	}

	stack_head->array_head[top_index].store_name = new char[strlen(toadd_store.store_name)+1];
	strcpy(stack_head->array_head[top_index].store_name, toadd_store.store_name);
	++top_index;
	return 1;
}



//Pops the stack, or decrements the stack down by one, removing the last node that was added.
int stack::pop()
{


	if(!stack_head)
		return 0;
	if(top_index == 0)
	{
		stack_node * current = stack_head;
		stack_head = stack_head -> next;
		delete [] current -> array_head;
		delete current;
		top_index = MAX - 1;
		return 1;
	}
	
	--top_index;
	return 1;
}



//Function to "peek" at the very last store that was tossed into the rejected pile.
int stack::peek(store_node & tosee_store)
{
	
	int counter = top_index;
	
	
	if(!stack_head)
		return 0;

	if(top_index == 0)
	{
		stack_node * current = stack_head;
		current = current -> next;
		if(!current)
			return 0;
		counter = MAX -1;
		
		tosee_store.store_name = new char[strlen(stack_head->array_head[counter].store_name)+1];
		strcpy(tosee_store.store_name, stack_head->array_head[counter].store_name);	
	}
	else
	{
		tosee_store.store_name = new char[strlen(stack_head->array_head[top_index-1].store_name)+1];
		strcpy(tosee_store.store_name, stack_head->array_head[top_index-1].store_name);
	}





}




//Function to display the rejected pile of stores.
int stack::display()
{

	int counter = top_index;
	
	if(!stack_head)
		return 0;
	
	stack_node * current = stack_head;
	if(counter == 0)
	{
		cout<<stack_head->array_head[counter].store_name<<endl;
		current = current -> next;
		counter = MAX - 1;
	}	

	while(current)
	{

		do
		{
			--counter;
			cout<<stack_head->array_head[counter].store_name<<endl;

		}while(counter != 0);

		current = current -> next;
		counter = MAX -1;
	}
	
}












