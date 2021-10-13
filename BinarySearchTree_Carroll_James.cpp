//Author: James Carroll
//Date: October 10, 2021
//Function: This program allows the user to enter the nodes of a tree, and they are able to search for certain nodes or delete them, and the program will return the path taken to get there

#include <iostream>
#include <string>

using namespace std;

class BinarySearchTree
{
	float data;
	BinarySearchTree *left, *right;
public:
	BinarySearchTree();

	BinarySearchTree(float);

	BinarySearchTree* add(BinarySearchTree*, float);

	void search(BinarySearchTree*, float);

	BinarySearchTree* minNode(BinarySearchTree*);

	BinarySearchTree* deleteNode(BinarySearchTree*, float);
};

BinarySearchTree::BinarySearchTree()
{
	data = 0;
	left = NULL;
	right = NULL;
}

BinarySearchTree::BinarySearchTree(float value)
{
	data = value;
	left = right = NULL;
}

BinarySearchTree* BinarySearchTree::add(BinarySearchTree* root, float value)
{
	if (!root)
		return new BinarySearchTree(value);
	if (value > root->data)
		root->right = add(root->right, value);
	else
		root->left = add(root->left, value);

	return root;
}

BinarySearchTree* BinarySearchTree::minNode(BinarySearchTree* node)
{
	while (node && node->left != NULL)
		node = node->left;
	return node;
}

void BinarySearchTree::search(BinarySearchTree* root, float data)
{
	while (true)
	{
		if (root->left == NULL && root->right == NULL && data != root->data)
		{
			cout << "This node does not exists" << endl;
			break;
		}
		else if (data > root->data)
		{
			cout << root->data << ", ";
			root = root->right;
		}
		else if (data < root->data)
		{
			cout << root->data << ", ";
			root = root->left;
		}
		else if (data == root->data)
		{
			cout << data << endl;
			break;
		}
	}
}

 BinarySearchTree* BinarySearchTree::deleteNode(BinarySearchTree* root, float data)
{
	while (true)
	{
		if (root == NULL)
			return root;
		if (data < root->data)
			root->left = deleteNode(root->left, data);
		else if (data > root->data)
			root->right = deleteNode(root->right, data);
		else
		{
			if (root->left == NULL && root->right == NULL)
				return NULL;
			else if (root->right == NULL)
			{
				root = root->left;
				return root;
			}
			else if (root->left == NULL)
			{
				root = root->right;
				return root;
			}

			BinarySearchTree* temp = minNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, data);
		}
		return root;
	}
}

int main(int argc, char** argv)
{
	bool keepGoing = true;
	float value;
	BinarySearchTree tree, * root = NULL;
	int choice;

	while (true)
	{
		cout << "Enter the value you would like to insert into the binary search tree.  If you are done entering values type -1" << endl;

		cin >> value;

		if (value == -1)
			break;

		if (root == NULL)
			root = tree.add(root, value);
		else
			tree.add(root, value);	
	}

	while (keepGoing)
	{
		cout << "Would you like to:" << endl << "1. Add another value" << endl << "2. Search for a value" << endl << "3. Delete a node" << endl << "4. End Program" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter the value that you would like to add" << endl;
			cin >> value;
			tree.add(root, value);
			break;
		case 2:
			cout << "Enter the value of the node you would like to search for" << endl;
			cin >> value;
			tree.search(root, value);
			break;
		case 3:
			cout << "Enter the value of the node you would like to delete" << endl;
			cin >> value;
			tree.deleteNode(root, value);
			break;
		case 4:
			keepGoing = false;
			break;
		}
	}
}