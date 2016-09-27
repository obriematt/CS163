//Matthew O'Brien
//Assignment 1. October 21 2014
//This cpp file contains all of the functions that will be used within my main function for adding, displaying, and liking. 
//




#include "assignment1.h"


//This function will sort of the lists according to allow for the lists to be ordered in a higher number of likes being at the front of the list.
//Passing in the pointers for the hint just "liked" and the head pointer for the list.
//I left old code and test conditions in, but just commented them out since I used them a lot for fixing my program.
int College_life::sort_list(node *& head, node *& to_change)
{
	//Traversal nodes	
	node * current = head;
	node * previous = head;

	while(previous -> next != to_change)
		previous = previous -> next;
	
	//cout<<"Begin"<<endl;
	if(current -> likes <= to_change -> likes)
	{	
		//cout<<"TEST1"<<endl;
		previous -> next = to_change -> next;
		to_change -> next = head;
		head = to_change;
		return 1;
	}		
	while(current -> next != to_change)
	{
		if(current -> next -> likes <= to_change -> likes)
		{
			//cout<<"TEST 2"<<endl;
			//to_change -> next = current -> next;
			//current -> next = to_change;
			previous -> next = to_change -> next;
			to_change -> next = current -> next;
			current -> next = to_change;
			return 1;
		}
		current = current -> next;
		//cout<<"test 3"<<endl;
	}
	//cout<<"end"<<endl;
	return 0;			
}		



//Menu function to reduce the size of the main function, as well as be able to call it again if the user forgets what the inputs are suppose to me.
//No nothing passed into this function.
int College_life::menu()
{
	cout<<"When selecting categories, please use only lower case letters, and only pick from registering, materials, and homework."<<endl;
	cout<<"When typing out hints, only use lower case letters, and keep them to a minimum, as you will need to type them out exactly when 'liking' a hint."<<endl;
	cout<<"1. Adding a hint to a given category."<<endl;
	cout<<"2. Liking a hint from a given category."<<endl;
	cout<<"3. Displaying only one category's hints and likes."<<endl;
	cout<<"4. Displaying all of the category's hints and likes."<<endl;
	cout<<"5. Redisplays the menu."<<endl;
	cout<<"6. Exits the program."<<endl;
	return 0;
}


//This function will display all of the lists, or tell the user their are no hints for the given category. There will be no arguments passed in ,as it's used to display all information.
//Input: nothing
//Output: The Registering Hints:
//	  **Hints
//	  **Likes
//repeated for the homework, and materials. 
int College_life::display_all()
{
	//Counter is used to display the Hints in a more organized fashion and count them.
	node * current;
	int counter = 1; 

	current = head_registering;

	if(!head_registering)
		cout<<"There are no registering hints."<<endl;
	else 
		cout<<"The Registering Hints: "<<endl;

	while(current)
	{
		cout<<counter<<". "<<current -> hints<<endl;
		cout<<"Likes: "<<current -> likes<<endl;
		++counter;
		current = current -> next;
	}
	//Reset counter to one, and begin to display the next list.
	counter = 1;
	current = head_materials;

	if(!head_materials)
		cout<<"There are no materials hints."<<endl;
	else
		cout<<"The Materials Hints: "<<endl;

	while(current)
	{
		cout<<counter<<". "<<current -> hints<<endl;
		cout<<"Likes: "<<current -> likes<<endl;
		++counter;
		current = current -> next;
	}
	
	//Reset back to one, display next list.	
	counter = 1;
	current = head_homework;


	if(!head_homework)
		cout<<"There are no homework hints."<<endl;
	else
		cout<<"The Homework Hints: "<<endl;

	while(current)
	{
		cout<<counter<<". "<<current -> hints<<endl;
		cout<<"Likes: "<<current -> likes<<endl;
		++counter;
		current = current -> next;
	}
	return 1;
}



		
//Displays a single list of hints dependant on which category is selected by the user.
//Input: **Category, registering, materials, homework
//Out: **No list
//	 Hint followed by likes.
//This is the first function using the same three comparisons over and over, this should have been fixed and optimized into a smaller function call, but I ran out of time.
//After I fixed my sort function problems I realized how I could have done this better, but I jut didn't have the time to make it prettier. Please excuse the same
//redundant code in the next few functions.
int College_life::display(char category[])
{
	//Counter variable to display the list in a more organized fashion.
	node * current;
	int counter = 1;
	

	//The next few strcmps will directly compare the category entered to one of the three possible inputs, and display that given list.
	//This is ugly and needs to be optimized.
	if(!strcmp(category, "registering"))
	{
		current = head_registering;
		if(!head_registering)
			return 0;
		cout<<"The Registering Hints:"<<endl;
		while(current)
		{
			cout<<counter<<". "<<current -> hints<<endl;
			cout<<"Likes: "<<current -> likes<<endl;
			++counter;
			current = current -> next;
		}
		return 1;
	}
	
	if(!strcmp(category, "materials"))
	{
		current = head_materials;

		if(!head_materials)
			return 0;
		cout<<"The Materials Hints:"<<endl;
		while(current)
		{
			cout<<counter<<". "<<current -> hints<<endl;
			cout<<"Likes: "<<current -> likes<<endl;
			++counter;
			current = current -> next;
		}
		return 1;
	}

	if(!strcmp(category, "homework"))
	{
		current = head_homework;
		if(!head_homework)
			return 0;
		cout<<"The Homework Hints:"<<endl;
		while(current)
		{
			cout<<counter<<". "<<current -> hints<<endl;
			cout<<"Likes: "<<current -> likes<<endl;
			++counter;
			current = current -> next;
		}
		return 1;
	}
}




//Used to enter into a list of the given category, and like one of the hints from that category.
//Input from user, the category they want to like: registering, materials, homework.
//followed by a display of that given list.
//Next input is the hint exactly as shown they want to like.
//No output.
int College_life::likes(char category[], char hint[])
{
	//Used for traversal
	node * current;
	

	//These next few strcmps are used to enter the correct list before using current to traverse
	//Ugly and should have been changed.
	if(!strcmp(category, "registering"))
	{
		current = head_registering;
		if(!head_registering)
		{
			cout<<"There is no hints for registering to like."<<endl;
			return 0;
		}
		while(current)
		{
			if(!strcmp(hint, current -> hints))
			{
				current -> likes = (current -> likes+1);
				if(current == head_registering)
					return 1;
				else
					sort_list(head_registering, current);
				return 1;
			}
			current = current -> next;
		}
		return 0;
	}
	
	if(!strcmp(category, "materials"))
	{
		current = head_materials;
		if(!head_materials)
		{
			cout<<"There are no hints for materials to like."<<endl;
			return 0;
		}
		while(current)
		{
			if(!strcmp(hint, current -> hints))
			{
				current -> likes = (current -> likes +1);
				if(current == head_registering)
					return 1;
				else
					sort_list(head_materials, current);
				return 1;
			}
			current = current -> next;
		}
		return 0;
	}

	if(!strcmp(category, "homework"))
	{
		current = head_homework;
		if(!head_homework)
		{
			cout<<"There are no hints for homework to like."<<endl;
			return 0;
		}
		while(current)
		{
			if(!strcmp(hint, current -> hints))
			{
				current -> likes = (current -> likes +1);
				if(current == head_homework)
					return 1;
				else
					sort_list(head_homework, current);
				return 1;
			}
			current = current -> next;
		}
		return 0;
	}
}




//This function will add a hint to a given category.
//Input: registering, homework, or materials
//Input 2: A given hint.
//Output: Nothing until displayed
int College_life::add_hint(char category[], char hint[])
{
	//Nodes for adding a new node, and traversing the lists
	node * temp = new node;
	node * current;
	

	//The next few compares are used to determine the list. These functions are overused and really should have been made differently if I had more time.
	//Very ugly, and needs to be changed.
	if(!strcmp(category, "registering"))
	{
	
		current = head_registering;
		if(!head_registering)
		{
			head_registering = temp;
			temp -> hints = new char[strlen(hint)+1];
			strcpy(temp -> hints, hint);
			temp -> likes = 0;
		//	cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
			return 1;
		}			

		while(current -> next)
		{
			current = current -> next;
		}
		current -> next = temp;
		temp -> hints = new char[strlen(hint)+1];
		strcpy(temp -> hints, hint);
		temp -> likes = 0;
		return 1;
	}

	if(!strcmp(category, "materials"))
	{
	
		current = head_materials;
		if(!head_materials)
		{ 
			head_materials = temp;
			temp -> hints = new char[strlen(hint)+1];
			strcpy(temp -> hints, hint);
			temp -> likes = 0;
			return 1;
		}
	
		while(current -> next)
		{
			current = current -> next;
		}
		current -> next = temp;
		temp -> hints = new char[strlen(hint)+1];
		strcpy(temp -> hints, hint);
		temp -> likes = 0;
		return 1;
	}

	if(!strcmp(category, "homework"))
	{
		
		current = head_homework;
		if(!head_homework)
		{
			head_homework = temp;
			temp -> hints = new char[strlen(hint)+1];
			strcpy(temp -> hints, hint);
			temp -> likes = 0;
			return 1;
		}
		
		while(current -> next)
		{
			current = current -> next;
		}
		current -> next = temp;
		temp -> hints = new char[strlen(hint)+1];
		strcpy(temp -> hints, hint);
		temp -> likes = 0;
		return 1;
	}
	return 0;
		
}



//Node deconstructor
node::~node()
{
	delete [] hints;
	next = NULL;
}



//Data structure constructor
College_life::College_life()
{
	head_registering = NULL;
	head_materials = NULL;
	head_homework = NULL;
}



//Data structure deconstructor
College_life::~College_life()
{
	node * temp;

	while(head_registering)
	{
		temp = head_registering -> next;
		delete head_registering;
		head_registering = temp;
	}
	
	while(head_materials)
	{
		temp = head_materials -> next;
		delete head_materials;
		head_materials = temp;
	}
	
	while(head_homework)
	{
		temp = head_homework -> next;
		delete head_homework;
		head_homework = temp;
	}
	
}
