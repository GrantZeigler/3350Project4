//Project 4 Driver
//Grant Zeigler


/*
	Midway Check:
	Done:
	Driver
	Insert Node Function
	Reflect Tree Function

	TODO:
	Remove Node function
*/

#include <string>
#include <cassert>
#include <iomanip> 
#include <iostream>
#include <cstdlib>    
#include "bintree.h"
#include <fstream>

using namespace std;

void print(int c) { cout << c << " "; };

int main()
{
	BinaryTreeNode<int>* treeHead = create_node(NULL);
	
	string input;
	string file;
	int data;

	cout << "Input File: ";
	cin >> file;
	ifstream in;
	in.open(file);
	
	do
	{
		//cout << "enter command: ";
		in >> input;

		//insert or delete the data
		if (input == "I" || input == "D")
		{
			cout << "data to add or remove: ";
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
		
		//print the tree sideways
		if (input == "P")
		{
			cout << "PRINTED TREE: " << endl;
			printTree(treeHead);
		}
		
		
		//traverse preorder
		if (input == "TR")
		{
			cout << "Traversing Preorder: ";
			preorder(print, treeHead);
			cout << endl;
		}
		//traverse inorder
		if (input == "TI")
		{
			cout << "Traversing Inorder: ";
			inorder(print, treeHead);
			cout << endl;
		}
		//traverse postorder
		if (input == "TO")
		{
			cout << "Traversing Postorder: ";
			postorder(print, treeHead);
			cout << endl;
		}
		
	} while ((input != "Q") && (input != "q"));

	in.close();
	return 0;
}