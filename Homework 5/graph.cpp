//This file contains all of my functions for my class graph.
//Lots of stuff will be here. This is exciting. Be. Excited.

//Matthew O'Brien
//December 9th, 2014.
//Assignment5

//This here is my file containing all the functions that will be called in main for testing purposes.
//This is where all the magic happens. The guts of my program if you will.
//Please be nice to it. It took many hours of love and care to make this little baby. 
//And it was evil.


//But really, cpp file containing functions for later use and testing.

#include "graph.h"






//Builds the graph. Constructor active!
graph::graph(int sizes)
{
	adjacency_list = new vertex[sizes];
	list_size = sizes;
	
	for(int i = 0; i < list_size; ++i)
	{
		adjacency_list[i].head = NULL;
		adjacency_list[i].topic = NULL;
	}
}



//Destructor for the node. Just in case this is casuing the problem. Turns out it wasn't, but I'm keeping it for safety.
node::node()
{
	adjacent = NULL;
	next = NULL;
}


//Graph destructor. This will call my remove all function. I chose to call the remove all function here, just in case that function would be useful elsewhere. KILL THE GRAPH!
graph::~graph()
{
	remove_all();
}	


//Destroys the graph. Entirely.
int graph::remove_all()
{

	//Check if it's there
	if(!adjacency_list)
		return 0;

	//Go through each position in the array.	
	for(int i = 0; i < list_size; ++i)
	{
		node * current = adjacency_list[i].head;
			//Kill the edges!
			while(current)
			{
				adjacency_list[i].head = adjacency_list[i].head->next;
				delete current;
				current = adjacency_list[i].head;
			}
			//Remove the character values
			delete [] adjacency_list[i].topic;	
	}
}



//Menu function for testing purposes. 
int graph::menu_function()
{
	cout<<"1 will display the vertex of the graph. No connections, only the possible key words."<<endl;
	cout<<"2 will display the connections of a key word to the other vertices."<<endl;
	cout<<"3 will display a depth first traversal of the graph from a given key word."<<endl;
	cout<<"4 will exit this lovely graph and burn it to the ground."<<endl;
	cout<<"Please remember to search exactly as they are seen in lower case."<<endl;
}





//Display the vertex of the graph only. This is my "display all" function of sorts.
int graph::display_all()
{
	//Go through the vertex
	for(int i = 0; i < list_size; ++i)
	{
		//Display it
		if(adjacency_list[i].topic)
			cout<<adjacency_list[i].topic<<endl;
		else
			return 0;
	}
}



//This function will load in my keywords and make the appropriate 
//connection between the given keywords.
int graph::load_keywords()
{

	ifstream file_in;
	file_in.open("info.txt");
	if(file_in)
	{
		while(!file_in.eof())
		{
			//Temp variables for dynamic allocation
			char topic1[size];
			char topic2[size];

			//PRIMING THE PUMP! bro.
			file_in.get(topic1, size, ':');
			file_in.ignore(100, ':');
			
			//BAIL OUT! if it's empty though.
			if(!topic1)
				return 0;
			file_in.get(topic2, size, '\n');
			file_in.ignore(100, '\n');
	
			//Insert these topics into the vertex.
			//Functions will
			//check to see if they already exist.
			insert_vertex(topic1);
			insert_vertex(topic2);
			insert_edge(topic1, topic2);
		}
		file_in.close();
		file_in.clear();
	}
}




//This function will insert info into the vertex
int graph::insert_vertex(char * topic_add)
{

	for(int i = 0; i < list_size; ++i)
	{
/*		if(adjacency_list[i].topic)
		{
			if(!strcmp(adjacency_list[i].topic, topic_add))
				return 0;
		}*/
		//Check to see if that position in the array has information, if not add right away.
		if(adjacency_list[i].topic == NULL)
		{
			adjacency_list[i].topic = new char[strlen(topic_add)+1];
			strcpy(adjacency_list[i].topic, topic_add);
			return 1;
		}
		//There is info in that vertex, let's compare it. If it the same, kick out. If not, keep going til you can add.
		else if(adjacency_list[i].topic)
		{
			if(!strcmp(adjacency_list[i].topic, topic_add))
				return 0;
		}
	}
	return 1;
}



//This function will return the position in the vertex for a given topic
int graph::find_location(char * key)
{
	//Go through the vertex
	for(int i = 0; i < list_size; ++i)
	{
		//Check for info
		if(adjacency_list[i].topic)
		{
			//Compare the info, returning it's position in the array.
	 		if(!strcmp(adjacency_list[i].topic, key))
				return i;
		}
	}
	//Negative numbers here since 0 won't work because it's actually a position in the array.
	return -1;
}


//This function will add in the connection between two vertices.
int graph::insert_edge(char * topic_one, char * topic_two)
{

	int pos_one = find_location(topic_one);
	int pos_two = find_location(topic_two);

	//Adding at the front is the easiest!
	node * temp = new node;
	temp -> next = adjacency_list[pos_one].head;
	adjacency_list[pos_one].head = temp;
	
	temp -> adjacent =& adjacency_list[pos_two];
	return 1;
}



//This function will diplay all of the adjacent topics of a key topic
int graph::display_adjacent(char * key)
{
	//Find it's position
	int pos_one = find_location(key);
	//Get ready to go through the connections
	node * current = adjacency_list[pos_one].head;
	//While those connections exist, display the resulting vertex
	while(current)
	{
		cout<< current -> adjacent -> topic<<" ";
		
		current = current -> next;
	}
	return 1;
}




//This function will diplay a depth traversal of the graph
int graph::display_depth(char * key)
{
	//Find the starting point.
	int pos_one = find_location(key);
	//Gonna traverse with this bugger
	node * current = adjacency_list[pos_one].head;
	//Start point
	cout<<adjacency_list[pos_one].topic<<" ";
	//Moving along here
	while(current)
	{	//Displaying all connected vertex from the edges
		cout<<current -> adjacent -> topic<<" ";
		current = current -> adjacent -> head;
	}
}
				

//HAPPY HOLIDAYS YO
