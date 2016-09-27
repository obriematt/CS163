//Header file containing the class, structs, and what not for this assignment.
//Matthew O'Brien
//December 9 2014
//Assignment 5. Graphs


//Header file containing the two structs needed for the graph, and the class for the graph itself. Simple prototypes
//and a const int for dynamic allocation. Not a lot to see here. Move along.


#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

//Constant size input used for dynamically allocating memory later on. Hopefully no songs are longer than 50 characters.
const int size = 50;


//The topics to connet. These are the actually vertices of the graph.
struct vertex
{
	char * topic;
	struct node * head;
};




//This struct will be the "edges" of my graph. Contains the relationship from one vertex to another. As well as the pointer to the next relation between it's vertex.
struct node
{
	vertex * adjacent;
	node * next;
	node();
}; 

//This here is my ADT. It's got functions. And size info. It's cool. I named him bob
class graph
{
	public:
		graph(int sizes=20);
		~graph();
		int menu_function();
		int load_keywords();
		int insert_vertex(char * topic_add);
		int find_location(char * key);
		int insert_edge(char * topic_one, char * topic_two);
		int display_adjacent(char * key);
		int display_depth(char * key);
		int display_all();
		int remove_all();

	private:
		vertex * adjacency_list;
		int list_size;
};
