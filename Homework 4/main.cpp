//Matthew O'Brien
//Assignment 4 December 2nd 2014




//This file will contain my "main" function used for testing my BST. 
//It will read in from an external song file, into the tree. This file will allow for basic testing to be sure the tree works.



#include "list.h"

int main()
{

	//Build the tree!
	bst trees;
	int response;

	//Load the song from the external file here.
	trees.load_song();
//	trees.display();

	
	//Introduction to the program, and basic testing functionality
	cout<<"Welcome to the magical tree of song information."<<endl;
	cout<<"All entries for testing purposes must be entered in lower case."<<endl;
	cout<<"All entries must for deleting, or retrieving must be the exact same as the song title."<<endl;
	cout<<"Thank you."<<endl;

	//Menu function displays the options for testing.

	trees.menu_function();
	do
	{
		cout<<"Please select 1 2 3 or 4"<<endl;
		cin>>response;
		cin.ignore(100, '\n');

		//Displays the full tree of songs.
		if(response == 1)
		{
			trees.display();
			trees.menu_function();
		}
		
		//Delete a given song by title.
		if(response == 2)
		{
			char song_title[size];
			cout<<"What is the song title: ";
			cin.get(song_title, size, '\n');
			cin.ignore(100, '\n');
			trees.remove(song_title);
			trees.menu_function();
		}

		//Retrieves a given song and displays it.
		if(response == 3)
		{
			char title_song[size];
			cout<<"What is the song title exactly: ";
			cin.get(title_song, size, '\n');
			cin.ignore(100, '\n');

			node * temp = new node;
			if(trees.retrieve(title_song, temp))
				trees.display_one(temp);
			else
				cout<<"Couldn't find that song dude."<<endl;
			trees.menu_function();
		}
	}while(response == 1 || response == 2 || response == 3);

	return 0;

}










	
