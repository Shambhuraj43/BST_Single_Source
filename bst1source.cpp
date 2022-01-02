/*
Shambhuraj Wadghule
CSCI 36200 Data Structures
Assignment 2
*/


#include<iostream>
#include <deque>         
#include <list>           
#include <queue>
#include<stack>
using namespace std;


//Node* root = NULL;		//global root of the tree 
stack<int> s;
int BSTArray[] = { 6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99 };

//Node structure

struct Node {

	int data;
	struct Node* left;
	struct Node* right;

};

//A constant Node object used in printBST function
static Node * const endOfQueue = NULL;



//adds the node
Node* fill(int data) {
	
	Node* temp = new Node();
	temp->data = data;

	temp->left = NULL;
	temp->right = NULL;

	return temp;
}


//inserts a new node in BST
Node* insertNode(int data, Node* root){
		
	if (root == NULL) {
		
		root = fill(data);
		
	}
	else if(data <= root->data) {
		
		root->left = insertNode(data, root->left);
	}
	else {
		root->right = insertNode(data, root->right);
	}

	return root;

}

//prints the tree level by level
	void printBST(Node *root) {

		if (root == NULL) return;

		queue<Node *> q;
		q.push(root);
		q.push(endOfQueue);
		while (true) {
			Node *currentNode = q.front();
			q.pop();
			if (currentNode != endOfQueue) {
				cout << currentNode->data << ' ';
				if (currentNode->left != NULL) {
					q.push(currentNode->left);
				}
				if (currentNode->right != NULL) {
					q.push(currentNode->right);
				}
			}
			else {
				cout << '\n';
				if (q.empty()) 
						break;
				q.push(endOfQueue);
			}
		}
	}

	

	//pushes the tre elements to the stack 
	void pushToStack(Node *root)
	{

		if (root == NULL)
		{
			return;
		}
		
		
		s.push(root->data);
		pushToStack(root->left);
		pushToStack(root->right);
	}


	//finds the kth smallest element in tree the k is user defined
	int kthSmallest(Node* root, int k) 
	{
		while (!s.empty())
		{
			cout << '\t' << s.top();
			s.pop();
		}
		return BSTArray[k];
	}



int main(void) {

	Node* root = NULL;
	int k;


	//creates the array using the array of values already defined
	for (int i = 0; i < sizeof(BSTArray) / sizeof(BSTArray[0]);i++)
	{
		root = insertNode( BSTArray[i], root);
	}


	printBST(root);

	cout << "Enter value for K :";
	
	cin >> k;
	
	int kthSmallestNum = kthSmallest(root, k);
	
	cout << kthSmallestNum <<endl;


	//system("pause");
	
	return 0;

}
