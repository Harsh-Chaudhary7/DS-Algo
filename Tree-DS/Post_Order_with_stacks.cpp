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

//using 2 stacks
// void stack2Traversal(node * root) {
// 	stack<node*> s1;
// 	stack<node*> s2;
// 	vector<int> postOrder;

// 	s1.push(root);

// 	while (!s1.empty()) {
// 		root = s1.top();
// 		s1.pop();
// 		s2.push(root);

// 		if (root->left != NULL)
// 			s1.push(root->left);
// 		if (root->right != NULL)
// 			s1.push(root->right);
// 	}
// 	while (!s2.empty()) {
// 		postOrder.pb(s2.top()->data);
// 		s2.pop();
// 	}

// 	out(postOrder, postOrder.size());
// }


//using 1 stack
void stack1Traversal(node* root) {
	stack<node*> s1;
	node * curr = root;
	node* temp;
	vector<int> postOrder;

	while (curr != NULL || !s1.empty()) {
		if (curr != NULL) {
			s1.push(curr);
			curr = curr->left;
		}
		else {
			temp = s1.top()->right;
			if (temp == NULL) {
				temp = s1.top();
				s1.pop();
				postOrder.pb(temp->data);
				while (!s1.empty() && temp == s1.top()->right) {
					temp = s1.top();
					s1.pop();
					postOrder.pb(temp->data);
				}

			} else
				curr = temp;
		}
	}
	out(postOrder, postOrder.size());

}

void postOrder(node* newNode) {
	if (newNode == NULL)
		return;

	postOrder(newNode->left);
	postOrder(newNode->right);
	cout << newNode->data << " ";
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

	stack1Traversal(root);
	// cout << "Level traversal: " << endl;
	// bfs(root);
	// cout << endl;
	cout << "Post-Order traversal: " << endl;
	postOrder(root);
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

