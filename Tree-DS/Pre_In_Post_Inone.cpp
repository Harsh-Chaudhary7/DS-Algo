#include<bits/stdc++.h>
using namespace std;

typedef long long int              ll;

#define inp(a, n)                  for(int Ele=0; Ele<(n); Ele++)std::cin>>a[Ele]
#define inps(a, n, sum)            for(int Ele=0; Ele<(n); Ele++){std::cin>>a[Ele]; sum += a[Ele];}
#define out(a, n)                  for(int Ele=0; Ele<(n); Ele++)std::cout<<a[Ele]
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

void preinpost(node* root) {
	stack<pair<node* , int>> s;
	s.push({root, 1});
	vector<int> pre, in, post;
	if (root == NULL)
		return;

	while (!s.empty()) {
		auto it = s.top();
		s.pop();

		if (it.second == 1) {
			pre.pb(it.first->data);
			it.second++;
			s.push(it);

			if (it.first->left != NULL)
				s.push({it.first->left, 1});
		}

		else if (it.second == 2) {
			in.pb(it.first->data);
			it.second++;
			s.push(it);

			if (it.first->right != NULL)
				s.push({it.first->right, 1});
		}

		else {
			post.pb(it.first->data);
		}
	}
	cout << "Pre: " << endl;
	out(pre, pre.size());
	cout << endl;
	cout << "In: " << endl;
	out(in, in.size());
	cout << endl;
	cout << "Post: " << endl;
	out(post, post.size());
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

	preinpost(root);
	// stack1Traversal(root);
	// cout << "Level traversal: " << endl;
	// bfs(root);
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

