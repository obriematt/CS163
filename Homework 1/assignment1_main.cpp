//Matthew O'Brien
//Assignment 1. October 21 2014
//
//Main function file, this is where the user will input information, and get out their list of helpful hints
//as well as be able to "like" certain hints they found more helpful, and of course display the hints of all or
//just a few different categories.






#include "assignment1.h"





//Main Function
int main()
{
	//Data structure and response int
	College_life dat_life;
	int response;
	
	cout<<"WELCOME TO THE COLLEGE LIFE HINTS, and stuff."<<endl;
	dat_life.menu();
	do
	{
		cout<<"Please select 1 2 3 4 5 or 6 "<<endl;
		cout<<"5 will redisplay the menu."<<endl;
		cin>>response;
		cin.ignore(100, '\n');
		cout<<endl;

		//Add a hint to a given category
		if(response == 1)
		{
			//read in the users category or hint to pass through the function calls.
			char category[SIZE];
			char hints[SIZE];
			
			cout<<"Enter the category, using only lower case as follows: registering, materials, or homework."<<endl;
			cin.get(category, SIZE, '\n');
			cin.ignore(100, '\n');
			
			cout<<"Enter the hint using only lower case: ";
			cin.get(hints, SIZE, '\n');
			cin.ignore(100, '\n');	
			dat_life.add_hint(category, hints);
		}

		//Response to like a hint
		if(response == 2)
		{
			//read in variables for the user to pass through the functions
			char category[SIZE];
			char hints[SIZE];
	
			cout<<"Enter the category: ";
			cin.get(category, SIZE, '\n');
			cin.ignore(100, '\n');
			
			dat_life.display(category);
			cout<<"Type out the hint you would like to like exactly as it is shown above."<<endl;
			cout<<"If nothing is displayed type 1 to exit back to menu."<<endl;
			cin.get(hints, SIZE, '\n');
			cin.ignore(100, '\n');
			dat_life.likes(category, hints);
		}

		//Display a single category's hints
		if(response == 3)
		{
			//read in variables for the user
			char category[SIZE];
	
			cout<<"Enter the category to display: ";
			cin.get(category, SIZE, '\n');
			cin.ignore(100, '\n');
			dat_life.display(category);
		}

		//Display all the hints for all categories
		if(response == 4)
			dat_life.display_all();

		//Redisplay the menu
		if(response == 5)
			dat_life.menu();

		//Exit
		if(response == 6)
			cout<<"Thank you for using this handy little thing. Good bye."<<endl;
		

	}while(response == 1 || response == 2 || response == 3 || response == 4 || response == 5);
	//Breaks out of the do/while loop here to exit the program.			

	return 0;
}
