//Matthew O'Brien
//Assignment 4 December 2nd 2014

//This is the list of all the functions used for the BST. This will contain all of the functions previously
//stated within the header file. Some of those functions are specifically used for testing functions, and will be commented as such later on.
//party.


#include "list.h"



//Basic insert function to put a node at the end of the tree, or to start the tree
//depending on the case
int bst::insert_node(node *& root, node *& to_add)
{
	//Creates the new node when root is null.
	if(!root)
	{
		root = new node;
		root->title = new char[strlen(to_add->title)+1];
		strcpy(root->title, to_add->title);
		root->artist = new char[strlen(to_add->artist)+1];
		strcpy(root->artist, to_add->artist);
		root->album = new char[strlen(to_add->album)+1];
		strcpy(root->album, to_add->album);
		root->time = to_add->time;
		root->retrieved = to_add->retrieved;
		root->value = to_add->value;
		root->left=root->right = NULL;
	}
	//recursive call for left or right pointers depending on the "value" of the title.
	else if(to_add->value < root->value)
		insert_node(root->left, to_add);
	else
		insert_node(root->right, to_add);
}


//Function to load in from an external file. Real important stuff here.
int bst::load_song()
{

	//Setting up the file io for getting information
	ifstream file_in;
	file_in.open("songs.txt");
	if(file_in)
	{
			
		//Setting up temp variables for dynamic allocation later.
		char title_add[size];
		char artist_add[size];
		char album_add[size];
		int time_add;
		int retrieve_add;

		//PRIMING THE PUMP!
		file_in.get(title_add, size, ':');
		file_in.ignore(100, ':');

		//BAIL OUT if there is nothing to get.
		if(!title_add)
			return 0;
		file_in.get(artist_add, size, ':');
		file_in.ignore(100, ':');
		file_in.get(album_add, size, ':');
		file_in.ignore(100, ':');
		file_in >> time_add;
		file_in.ignore(100, ':');
		file_in >> retrieve_add;
		file_in.ignore(100, '\n');
	
		//Turn the title into a number for the BST
		int number = title_switch(title_add);

		//Put this data into a node.
		node * temp = new node;
		temp -> title = new char[strlen(title_add)+1];
		strcpy(temp->title, title_add);
		temp -> artist = new char[strlen(artist_add)+1];
		strcpy(temp->artist, artist_add);
		temp -> album = new char[strlen(album_add)+1];
		strcpy(temp->album, album_add);
		temp -> time = time_add;
		temp -> retrieved = retrieve_add;
		temp -> value = number;
		
		//Using insert function to pass the temp node info into the tree's nodes.
		insert_node(root, temp);
	
		//While the file has information, or end of file
		while(!file_in.eof())
		{

			

			//Another set of basic variables to use for dynamic allocation.
			char titles[size];
			char artists[size];
			char albums[size];
			int times;
			int retrieves;
			int values;
			
			file_in.get(titles, size, ':');
			file_in.ignore(100, ':');
			if(!titles[0])
				return 0;
			file_in.get(artists, size, ':');
			file_in.ignore(100, ':');
			file_in.get(albums, size, ':');
			file_in.ignore(100, ':');
			file_in >> times;
			file_in.ignore(100, ':');
			file_in >> retrieves;
			file_in.ignore(100, '\n');	

			//temp node to pass into insert function.
			node * temps = new node;

			values = title_switch(titles);

			temps->title = new char[strlen(titles)+1];
			strcpy(temps->title, titles);
			temps->artist = new char[strlen(artists)+1];
			strcpy(temps->artist, titles);
			temps->album = new char[strlen(albums)+1];
			strcpy(temps->album, albums);
			temps->time = times;
			temps->retrieved = retrieves;
			temps->value = values;
			
			//Passing the information of the temp node into the tree
			insert_node(root, temps);
			
		}
		file_in.close();
		file_in.clear();
	
	}
}


//Input: pointer, and title.
//Out: Nothing, it's deleted.
//Removal of a song from the tree.
int bst::remove(node *& root, char *title)
{
	//No tree, get out.
	if(!root)
		return 0;

	//Traversal to the "end" of the tree
	remove(root->left, title);
	remove(root->right, title);
	
	//Comparing the node's title to the title being searched to delete.
	if(!strcmp(root->title, title))
	{
		//No children
		if(!root->left && !root->right)
		{
			delete root;
			root = NULL;
		}
		//Only has a left kid.
		else if(root->left && !root->right)
		{
			node * temps = root->left;
			delete root;
			root = temps;
		}
		//Only has a right kid
		else if(!root->left && root->right)
		{
			node * temp = root->right;
			delete root;
			root = temp;
		}
		//The right kid doesn't have a left.
		else if(!root->right->left)		
		{
			node * replaced = root->right;
			node * next = root->right->right;

			//Root root's song info
			delete [] root->title;
			delete [] root->album;
			delete [] root->artist;
			
			//Copy's the right node's info into root's info. dynamically
			//A "copy" function would've been better here.			
			root->title = new char[strlen(replaced->title)+1];
			strcpy(root->title, replaced->title);
			root->album = new char[strlen(replaced->album)+1];
			strcpy(root->album, replaced->album);
			root->artist = new char[strlen(replaced->artist)+1];
			strcpy(root->artist, replaced->artist);
			root->time = replaced->time;
			root->retrieved = replaced->retrieved;
			root->value = replaced->value;

			//Delete the right kid, fix pointers
			delete replaced;
			root->right = next;
		}
		//Covers the rest of the possible cases. Kids with kids.
		else
		{
			node * current = root->right;
			node * previous = current;
			while(current->left)
			{
				previous = current;
				current = current->left;
			}
			//Deleting roots info for copying.
			delete [] root->title;
			delete [] root->artist;
			delete [] root->album;
	
			//Again a copy function would've been nicer here.
			root->title = new char[strlen(current->title)+1];
			strcpy(root->title,current->title);
			root->artist = new char[strlen(current->artist)+1];
			strcpy(root->artist,current->artist);
			root->album = new char[strlen(current->album)+1];
			strcpy(root->album, current->album);
			root->time = current-> time;
			root->retrieved = current->retrieved;
			root->value = current->value;

			//fixing pointers and deleting the necessary node.
			previous -> left = current -> right;
			delete current;
		}
	
	}
	//These were in the wrong spot. Leaving them there to remind me not to do this again.
	//remove(root->left, title);
	//remove(root->right, title);
	return 1;
}



//Wrapper function for the removal of a node by title.
int bst::remove(char * title)
{
	return remove(root, title);
}



//Node destructor. Yup. Burning a node down.
node::~node()
{
	delete [] title;
	delete [] artist;
	delete [] album;
	right = NULL;
	left = NULL;
}


//Construct for my BST. Nice and simple.
bst::bst()
{
	root = NULL;
}



//Using a recursively remove all function to delete the entire BST. 
bst::~bst()
{
	remove_all(root);
}



//This is the recursively call used to delete the entire BST. Kept it out of the destructor in case it
//could be useful for a user to wipe out the entire tree and start over.
int bst::remove_all(node *& root)
{
	
	if(!root)
		return 0;
	remove_all(root->left);
	remove_all(root->right);
	delete root;
	root = NULL;
	return 1;
}



//This function will turn the title of a song into a number, which will then determine where it falls along the tree.
int bst::title_switch(char * title)
{
	//temp variables for the function
	int i = strlen(title);
	int h = 0;

	//turns the title into an integer
	for(int j = 0; j < i; ++j)
		h = h + title[j];
	//returns the converted title in it's ascii value form.
	return h;
}



//This function will be used to traverse the tree and retrieve a given node that is being searched for from user.
int bst::retrieve(node * root, char * title, node *& to_find)
{
	//Is there a tree? No? Why are you here? Get out.
	if(!root)
		return 0;
	

	//Comparing the title to the searched title of the retrieval.
	if(!strcmp(root->title, title))
	{
		//Hey look, you found it. Put the info into the empty box
		to_find->title = new char[strlen(root->title)+1];
		strcpy(to_find->title, root->title);
		to_find->artist = new char[strlen(root->artist)+1];
		strcpy(to_find->artist, root->artist);
		to_find->album = new char[strlen(root->album)+1];
		strcpy(to_find->album, root->album);
		to_find->time = root->time;
		to_find->retrieved = root->retrieved +1;
		root->retrieved = to_find->retrieved;
		return 1;
	}
	//Moving along the tree.
	retrieve(root->left, title, to_find);
	retrieve(root->right, title, to_find);
	return 1;	
}



//Wrapper function for the retrieve.
int bst::retrieve(char * title, node *& to_find)
{
	return retrieve(root, title, to_find);
}





//This will display only the node that is retrieved from the previous function. Created this as to not need any
//input from the user, and allows for possible use later on when passing around nodes.
int bst::display_one(node *& to_show)
{
	//Make sure it's there
	if(!to_show)
		return 0;

	//Display the info of the node.
	cout<<"The song's info is: "<<endl;
	cout<<to_show->title<<endl;
	cout<<to_show->artist<<endl;
	cout<<to_show->album<<endl;
	cout<<to_show->time<<endl;
	cout<<to_show->retrieved<<endl;
	return 1;
}




//Displays the full tree for the user.
int bst::display(node * root)
{

	//Check the tree!
	if(!root)
		return 0;

	display(root->left);	

	//Displays the information of root.
	cout<<root->title<<endl;
	cout<<root->artist<<endl;
	cout<<root->album<<endl;
	cout<<root->time<<endl;
	cout<<root->retrieved<<endl;

	display(root->right);
	return 1;
}



//Wrapper function for my display function
int bst::display()
{
	return display(root);
}



//Menu function used for testing purposes. Easily commented out for later implementation.
int bst::menu_function()
{
	cout<<"1. Display all songs."<<endl;
	cout<<"2. Delete a given song."<<endl;
	cout<<"3. Retrieve a song by title."<<endl;
	cout<<"4. Exit the program."<<endl;
}

//Thanks for looking through all of that code. Hope the term is going well for you.
//Happy Holidays.
//All I want for Christmas, is an A.
