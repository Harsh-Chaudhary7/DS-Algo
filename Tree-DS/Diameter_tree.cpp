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


// Max Diameter
int maxDia(node* root, int dia) {
	if (!root)
		return 0;
	int lh = maxDia(root->left, dia);
	int rh = maxDia(root->right, dia);

	dia = max(dia, lh + rh);
	return 1 + max(lh, rh);

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


	int height = maxDia(root, 0);
	cout << height << endl;

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

