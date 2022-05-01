#include<bits/stdc++.h>
using namespace std;

typedef long long int              ll;

#define inp(a, n)                  for(int Ele=0; Ele<(n); Ele++)std::cin>>a[Ele]
#define inps(a, n, sum)            for(int Ele=0; Ele<(n); Ele++){std::cin>>a[Ele]; sum += a[Ele];}
#define out(a, n)                  for(int Ele=0; Ele<(n); Ele++)std::cout<<a[Ele]<<endl
#define inp1(a, n)                 for(int Ele=1; Ele<=(n); Ele++)cin>>a[Ele]


#define mem(x,i) 				   memset((x),(i),sizeof((x)))
#define pb 						   push_back

struct node {
	int data;
	struct node* left;
	struct node* right;
};

// typedef struct node    node;

// Creating new node
node* createNode() {
	node* newNode = new node();
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

//Traversing Tree

//Pre-order
void preOrder(node *newNode) {
	if (newNode == NULL)
		return;

	cout << newNode->data << " ";
	preOrder(newNode->left);
	preOrder(newNode->right);

}

//Post-order
void postOrder(node* newNode) {
	if (newNode == NULL)
		return;

	postOrder(newNode->left);
	postOrder(newNode->right);
	cout << newNode->data << " ";
}

//In-order
void inOrder(node* newNode) {
	if (newNode == NULL)
		return;

	inOrder(newNode->left);
	cout << newNode->data << " ";
	inOrder(newNode->right);
}

//BFS Breadth-First Search
void bfs(node* newNode) {
	if (newNode == NULL)
		return;

	queue<node*> q;

	q.push(newNode);

	while (!q.empty()) {

		node* N = q.front();
		cout << N->data << " ";
		q.pop();

		if (N->left != NULL)
			q.push(N->left);
		if (N->right != NULL)
			q.push(N->right);

	}

}

//Inserting new node
node* insertNode() {
	node* temp = createNode();
	int val;
	cin >> val;
	if (val == -1)
		return 0;
	temp->data = val;
	// cout << "Enter left of" << val << ": " << endl;
	temp->left = insertNode();
	// cout << "Enter right of" << val << ": " << endl;
	temp->right = insertNode();
	return temp;
}


void solve() {
	node* root;		//creating root node
	root = insertNode();

	cout << "Level traversal: " << endl;
	bfs(root);
	cout << endl;
	cout << "Post-Order traversal: " << endl;
	postOrder(root);
	cout << endl;
	cout << "Pre-Order traversal: " << endl;
	preOrder(root);
	cout << endl;
	cout << "In-Order traversal: " << endl;
	inOrder(root);
	cout << endl;
}

int main() {
	solve();
	return 0;
}

