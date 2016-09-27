//Matthew O'Brien
//December 9, 2014
//Assignment 5

//Main file for testing purproses. Going to get stuff done in here. Party time.





#include "graph.h"

int main()
{
	//Creating some variables.
	int response;
	graph graphed;
	
	//Loading in my data
	graphed.load_keywords();

	//Saying hi to people.
	cout<<"Welcome to the wonderful graph thing I made."<<endl;
	cout<<"All search selections must be typed exactly as shown."<<endl;
	cout<<"Merry Christmas"<<endl;
	
	//Menu function and testing
	graphed.menu_function();
	do
	{
		cout<<"Please select 1 2 3 4: ";
		cin>>response;
		cin.ignore(100, '\n');

		//Displays the full graph
		if(response == 1)
		{
			graphed.display_all();
			graphed.menu_function();
		}
		

		//Display the adjacency list of a keyword
		if(response == 2)
		{
			char key[size];
			cout<<"What key word's connections would you like to display? ";
			cin.get(key, size, '\n');
			cin.ignore(100, '\n');
			graphed.display_adjacent(key);
			cout<<endl;
			graphed.menu_function();
		}

	

		//Displays a depth first traversal of the graph given a key word search
		if(response == 3)
		{
			char key[size];
			cout<<"What key word's depth first connections would you like to diplay?";
			cin.get(key, size, '\n');
			cin.ignore(100, '\n');
			graphed.display_depth(key);
			cout<<endl;
			graphed.menu_function();
		}
	}while(response == 1 || response == 2 || response == 3);

	return 0;
}

