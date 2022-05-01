#include<bits/stdc++.h>
using namespace std;

typedef long long int              ll;

#define inp(a, n)                  for(int Ele=0; Ele<(n); Ele++)std::cin>>a[Ele]
#define inps(a, n, sum)            for(int Ele=0; Ele<(n); Ele++){std::cin>>a[Ele]; sum += a[Ele];}
#define out(a, n)                  for(int Ele=0; Ele<(n); Ele++)std::cout<<a[Ele]<<endl
#define inp1(a, n)                 for(int Ele=1; Ele<=(n); Ele++)cin>>a[Ele]
#define max(a,b)				   (a>b?a:b)


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

//Post-order
void postOrder(node* newNode) {
	if (newNode == NULL)
		return;

	postOrder(newNode->left);
	postOrder(newNode->right);
	cout << newNode->data << " ";
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

//Max Height

int check(node* root) {
	if (root == NULL)
		return 0;

	int lh = check(root->left);
	int rh = check(root->right);

	if (lh == -1 && rh == -1)
		return -1;
	if (abs(lh - rh) > 1)
		return -1;


	return 1 + max(rh, lh);
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


	int height = check(root);
	if (height == -1)
		cout << "Not BBT" << endl;
	else
		cout << "BBT" << endl;
	// cout << "Level traversal: " << endl;
	// bfs(root);
	// cout << endl;
	// cout << "Post-Order traversal: " << endl;
	// postOrder(root);
	// cout << endl;
	// cout << "Pre-Order traversal: " << endl;
	// preOrder(root);
	// cout << endl;
	// cout << "In-Order traversal: " << endl;
	// inOrder(root);
	// cout << endl;
}

int main() {
	solve();
	return 0;
}

