//Project 4 Driver
//Grant Zeigler

#include <string>
#include <cassert>
#include <iomanip> 
#include <iostream>
#include <cstdlib>    
#include "bintree.h"
#include <fstream>

using namespace std;


int main()
{
	BinaryTreeNode<int>* treeHead = create_node(NULL);
	
	string input;
	string file;
	
	int data;

	cout << "Input File: ";
	cin >> file;
	ifstream in("file");

	do
	{
		in >> input;
		//insert or delete the data
		if (input == "I" || input == "D")
		{
			in >> data;

			if (input == "I")
			{
				cout << "Inserting: " << data << endl;
				insert(treeHead, data);
			}
			if (input == "D")
			{
				//remove(treeHead, data);
			}

		}
		/*
		//clear the tree
		if (input == "C")
		{
			tree_clear(treeHead);
		}

		//reflect the tree
		if (input == "R")
		{
			reflect(treeHead);
		}
		*/
		//print the tree sideways
		if (input == "P")
		{
			cout << "PRINTED TREE: " << endl;
			printTree(treeHead);
		}
		/*
		//traverse preorder
		if (input == "TR")
		{

		}
		//traverse inorder
		if (input == "TI")
		{

		}
		//traverse postorder
		if (input == "TO")
		{

		}

		*/
	} while ((input != "Q") && (input != "q"));

	in.close();
	return 0;
}