//Matthew O'Brien
//Assignment 2


//CPP file containing the full list of functions for my ordered list ADT


#include "list.h"


//Constructor for the ordered list class
ordered_list::ordered_list()
{

	feature_array = NULL;
	int total_array = 0;
}




//Destructor for the ordered list class
ordered_list::~ordered_list()
{

	delete [] feature_array;
}




//Inserts the desired feature in a ordered manner.
int ordered_list::insert(int position, feature_node & toadd_feature)
{


	feature_array[position].features = new char[strlen(toadd_feature.features)+1];
	strcpy(feature_array[position].features, toadd_feature.features);	


}




//This function will remove a feature of a product/
int ordered_list::remove(int position)
{
	delete [] feature_array[position].features;
}



//Retrieves the feature of a product depending on it's position
int ordered_list::retrieve(int position, feature_node & tofind_feature)
{
	if(!feature_array[position].features)
		return 0;
	
	tofind_feature.features = new char[strlen(feature_array[position].features)+1];
	strcpy(tofind_feature.features, feature_array[position].features);
	return 1;
}



//Builds the array struct of nodes for the features. Then the class will have access to this array with it's private data members, and information can be passed accordingly.
int ordered_list::build_array(int total_size)
{
	
	feature_node * array = new feature_node[total_size];
	total_array = total_size;
}


//Displays the ordered list of features for the given product
int ordered_list::display()
{
	if(!feature_array)
		return 0;

	for(int i = 0; i<total_array;i++)
	{
		cout<<feature_array[i].features<<endl;
	}

}








