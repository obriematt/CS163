//Matthew O'Brien
//Homework 3
//All of the functions used for assignment 3's hash table.

#include "list.h"




//This function will display a single node. Used for my retrieve function to display the node that was retrieved by title.
int hash_table::display_one(node *& to_show)
{

	cout<<"The song's information is:"<<endl;
	cout<<to_show->title<<endl;
	cout<<to_show->artist<<endl;
	cout<<to_show->album<<endl;
	cout<<to_show->time<<endl;
	cout<<to_show->retrieved<<endl;
	return 1;
}



//Loads the list of songs from an external file into my hashtable! Party.
int hash_table::load_song()
{
	//Sets up the file io for getting information
	ifstream file_in;
	file_in.open("Songs.txt");
	if(file_in)
	{
		//temp variables that will be used to gather the initial information
		char title_add[SIZE];
		char artist_add[SIZE];
		char album_add[SIZE];
		int time_add;
		int retrieve_add;

		//PRIMING THE PUMP!
		file_in.get(title_add, SIZE, ':');
		file_in.ignore(100, ':');
		//Leaves if there is nothing to add
		if(!title_add)
			return 0;
		file_in.get(artist_add, SIZE, ':');
		file_in.ignore(100, ':');
		file_in.get(album_add, SIZE, ':');
		file_in.ignore(100, ':');
		file_in >> time_add;
		file_in.ignore(100, ':');
		file_in >> retrieve_add;
		file_in.ignore(100, '\n');
		
		//Hash function to determine the index for the first node.
		int position = hash_function(title_add);
			
		//Transferring data to the nodes
		node * temps = new node;
		temps -> title = new char[strlen(title_add)+1];
		strcpy(temps->title, title_add);
		temps->artist = new char[strlen(artist_add)+1];
		strcpy(temps->artist, artist_add);
		temps->album = new char[strlen(album_add)+1];
		strcpy(temps->album, album_add);
		temps->time = time_add;
		temps->retrieved = retrieve_add;
		
		
		temps->next = table[position];
		table[position] = temps;
		//Loop to handle the rest of the songs that will be added to the table. After the pump hath been primed.
		while(!file_in.eof())
		{
			char titles[SIZE];
			char artists[SIZE];
			char albums[SIZE];
			int times;
			int retrieves;
			file_in.get(titles, SIZE, ':');
			file_in.ignore(100, ':');
			file_in.get(artists, SIZE, ':');
			file_in.ignore(100, ':');
			file_in.get(albums, SIZE, ':');
			file_in.ignore(100, ':');
			file_in >> times;
			file_in.ignore(100, ':');
			file_in >> retrieves;
			file_in.ignore(100, '\n');
		
			//Again, determining the position of the index for each node song.
			int positions = hash_function(titles);
			
			node * temp = new node;
			temp->title = new char[strlen(titles)+1];
			strcpy(temp->title, titles);
			temp->artist = new char[strlen(artists)+1];
			strcpy(temp->artist, artists);
			temp->album = new char[strlen(albums)+1];
			strcpy(temp->album, albums);
			temp->time = times;
			temp->retrieved = retrieves;
	
			temp->next = table[positions];
			table[positions] = temp;
		}
		file_in.close();
		file_in.clear();
	}
}



//Basic menu function to display options 
int hash_table::menu_function()
{

//	cout<<"Welcome to the magical song showing display thing."<<endl;
//	cout<<"All selections must be in lower case."<<endl;
//	cout<<"All searches must be the exact title that is displayed."<<endl;
//	cout<<"Please select from the following menu options."<<endl;
	cout<<"1.Diplay all songs."<<endl;
	cout<<"2.Delete a given song."<<endl;
	cout<<"3.Retrieve a song by title."<<endl;
	cout<<"4.Exit this program."<<endl;
}
				
//I ended up not using this code at all. But like Karla says, never delete your work, just comment it out.
/*Inserts the songs from a file
int hash_table::insert_song(char * title, node * to_add)
{

	int position = hash_function(title);
	
	node * temp = new node;
	temp -> hash_table.load_song(to_add);

	temp -> next = hash_table[position];
	hash_table[position] = temp;

}*/



//Retrieves of the song of a given title.
int hash_table::retrieve(char * title, node *& to_find)
{

	//Hash function for index
	int position = hash_function(title);

	//Base case
	if(!table[position])
		return 0;

	//Setting current equal to the index pointer
	node * current = table[position];
	while(current)
	{
		//Checking for a match, and copying data into "to_find" to be displayed later.
		if(!strcmp(current->title, title))
		{
			to_find->title = new char[strlen(current->title)+1];
			strcpy(to_find->title, current->title);
			to_find->artist = new char[strlen(current->artist)+1];
			strcpy(to_find->artist, current->artist);
			to_find->album = new char[strlen(current->album)+1];
			strcpy(to_find->album, current->album);
			to_find->time = current->time;
			to_find->retrieved = current->retrieved + 1;
			current->retrieved = to_find->retrieved;
			return 1;
	
		}
		current = current->next;
	}
	return 0;
}

//Displays the entire table of songs, only the title and album.
int hash_table::display()
{
	//FOR Loop to go through each index of the table, and display all of its node
	for(int i = 0; i < hash_table_size; ++i)
	{
		node * current = table[i];
//		cout<<"The index is "<<i<<endl;
		while(current)
		{
			//Not part of the "songs" but helpful to determine the amount of collisions
			cout<<"Index is: "<<i<<endl;
			//Actual song info
			cout<<current->title<<endl;
			cout<<current->artist<<endl;
			cout<<current->album<<endl;
			cout<<current->time<<endl;
			cout<<current->retrieved<<endl;
			current = current -> next;
		}
	}  
}

//Remove the song of a given title, the title needs to specific, couldn't get the keyword to work properly.
int hash_table::remove(char * title)
{
	//Determine the index
	int position = hash_function(title);

	//Pointers for removal.
	node * current = table[position];
	node * previous = current;
	//Checks for if the first node is a match. I realized later that this couldn't just been thrown into the while loop, but I kept it for safety.
	if(!strcmp(current->title, title))
	{
		table[position] = current -> next;
		delete current;
		current = NULL;
		return 1;
	}

	//while loop traversal to check nodes and delete.
	while(current)
	{	
		previous = current;
		current = current -> next;
		if(!strcmp(current->title, title))
		{
			previous -> next = current -> next;
			delete current;
			current = NULL;
			return 1;
		}
	}
}



//Hash function to determine the position of the array to search.
int hash_table::hash_function(char * title)
{
	//Temp variables for the function
	int i = strlen(title);
	int h = 0;
	int position;

	//Turns the title into an int value
	for(int j = 0; j < i; ++j)
		h = h + title[j];

	//Position is the mod of the size, in this case 5. My sample size was too small to go much beyond that, larger data sets would require larger sizes.
	position = h % hash_table_size;
	return position;
}



//Constructor for the hashtable of a given size.
hash_table::hash_table(int size)
{
	//I was unsure if this was entirely needed, but for easily changing the size it helps.
	hash_table_size = size;
	
	table = new node * [size];

	for(int i = 0; i < size; ++i)
		table[i] = NULL;
	
}



//Destructor for the hashtable.
hash_table::~hash_table()
{
	for(int i = 0; i < hash_table_size; ++i)
	{
		node * current = table[i];
		while(table[i])
		{
			current = table[i];
			table[i] = table[i]->next;
			delete current;
		}
	}
}



//Node destructor 
node::~node()
{

	delete [] title;
	delete [] artist;
	delete [] album;
	next = NULL;
}	
