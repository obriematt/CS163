//Matthew O'Brien

//Assignment 3

//Main test file to check to see if my hash table is building correctly.
//Reads in from the given Songs.txt file.


#include "list.h"




int main()
{
	//Build the table and set a response variable for the menu
	hash_table hashes;
	int response;
	//Load the songs from the file
	hashes.load_song();

	//A good ol' welcome
	cout<<"Welcome to the magical song showing diplay thing."<<endl;
	cout<<"All entries to the search must be down in lower case."<<endl;
	cout<<"All searches for deletion, and retrieval need to be the exact song title."<<endl;
	cout<<"Enjoy the song's information hunting."<<endl;	

	//Menu selection
	hashes.menu_function();
	do
	{
		cout<<"Please select 1 2 3 or 4"<<endl;
		cin>>response;
		cin.ignore(100, '\n');
		
		//Display all of the songs
		if(response == 1)
			hashes.display();
			hashes.menu_function();

		//Delete a given song by title
		if(response == 2)
		{
			char song_title[SIZE];
			cout<<"What is the song title?"<<endl;
			cin.get(song_title, SIZE, '\n');
			cin.ignore(100, '\n');
			hashes.remove(song_title);
			hashes.menu_function();
		}

		//Retrieve the song by title
		if(response == 3)
		{
			char title_song[SIZE];
			cout<<"What is the song title?"<<endl;
			cin.get(title_song, SIZE, '\n');
			cin.ignore(100, '\n');

			node * temp = new node;

			if(hashes.retrieve(title_song, temp))
				hashes.display_one(temp);
			else
				cout<<"Didn't find nothing."<<endl;
			hashes.menu_function();
		}
	
	}while(response == 1 || response == 2 || response == 3);
 

//	commented out, only used for beginning testing
//	hashes.display();

	return 0;
}
