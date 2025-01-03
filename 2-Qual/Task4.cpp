#include <bits/stdc++.h>

using namespace std;

struct node {
	int data {0};
	struct node* left;
	struct node* right;
};

// void inOrderX(node* root)
// {
// 	if (root != NULL)
// 	{
// 		inOrderX(root->left);
// 		cout << root->data << " ";
// 		inOrderX(root->right);
// 	}
// }

int inOrder(node* root)
{
	if (root != NULL)
	{
		if (root->data == 0) {
			if (root->left != NULL) {
				root->left->data = 1;
			}
			if (root->right != NULL) {
				root->right->data = 2;
			}
			int res1 = inOrder(root->left);
			int res2 = inOrder(root->right);
			if (root->left != NULL) {
				root->left->data = 2;
			}
			if (root->right != NULL) {
				root->right->data = 1;
			}
			int res12 = inOrder(root->left);
			int res22 = inOrder(root->right);
			return 1 + max(res1 + res2, res12 + res22);
		}
		if (root->data == 1) {
			if (root->left != NULL) {
				root->left->data = 0;
			}
			if (root->right != NULL) {
				root->right->data = 2;
			}
			int res1 = inOrder(root->left);
			int res2 = inOrder(root->right);
			if (root->left != NULL) {
				root->left->data = 2;
			}
			if (root->right != NULL) {
				root->right->data = 0;
			}
			int res12 = inOrder(root->left);
			int res22 = inOrder(root->right);
			return max(res1 + res2, res12 + res22);

		}
		if (root->data == 2) {
			if (root->left != NULL) {
				root->left->data = 1;
			}
			if (root->right != NULL) {
				root->right->data = 0;
			}
			int res1 = inOrder(root->left);
			int res2 = inOrder(root->right);
			if (root->left != NULL) {
				root->left->data = 0;
			}
			if (root->right != NULL) {
				root->right->data = 1;
			}
			int res12 = inOrder(root->left);
			int res22 = inOrder(root->right);
			return max(res1 + res2, res12 + res22);

		}
	}
	return 0;
}

int inOrderM(node* root)
{
	if (root != NULL)
	{
		if (root->data == 0) {
			if (root->left != NULL) {
				root->left->data = 1;
			}
			if (root->right != NULL) {
				root->right->data = 2;
			}
			int res1 = inOrderM(root->left);
			int res2 = inOrderM(root->right);
			if (root->left != NULL) {
				root->left->data = 2;
			}
			if (root->right != NULL) {
				root->right->data = 1;
			}
			int res12 = inOrderM(root->left);
			int res22 = inOrderM(root->right);
			return 1 + min(res1 + res2, res12 + res22);
		}
		if (root->data == 1) {
			if (root->left != NULL) {
				root->left->data = 0;
			}
			if (root->right != NULL) {
				root->right->data = 2;
			}
			int res1 = inOrderM(root->left);
			int res2 = inOrderM(root->right);
			if (root->left != NULL) {
				root->left->data = 2;
			}
			if (root->right != NULL) {
				root->right->data = 0;
			}
			int res12 = inOrderM(root->left);
			int res22 = inOrderM(root->right);
			return min(res1 + res2, res12 + res22);

		}
		if (root->data == 2) {
			if (root->left != NULL) {
				root->left->data = 1;
			}
			if (root->right != NULL) {
				root->right->data = 0;
			}
			int res1 = inOrderM(root->left);
			int res2 = inOrderM(root->right);
			if (root->left != NULL) {
				root->left->data = 0;
			}
			if (root->right != NULL) {
				root->right->data = 1;
			}
			int res12 = inOrderM(root->left);
			int res22 = inOrderM(root->right);
			return min(res1 + res2, res12 + res22);

		}
	}
	return 0;
}

node* newNode(int data)
{
	node* n = (node*)malloc(sizeof(node));
	n->data = data;
	n->left = n->right = NULL;
	return (n);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long n;
	cin >> n;

	vector<int> d;

	while (n != 0) {
		int val { (int) n % 10 };
		d.push_back(val);
		n /= 10;
	}
	if (d[-1] == 0) { cout << 0 << " " << 0 << endl; return 0; }
	d.push_back(1);

	reverse(d.begin(), d.end());

	stack<node*> s;
	node* r = newNode(1);
	s.push(r);
	while (!s.empty() && !d.empty()) {
		node* t = s.top();
		s.pop();
		int t2 = d[0];
		d.erase(d.begin());
		if (t2 == 1) {
			node* l = newNode(-1);
			t->left = l;
			s.push(l);
		}
		if (t2 == 2) {
			node* l = newNode(-1);
			t->left = l;
			s.push(l);
			node* r = newNode(-1);
			t->right = r;
			s.push(r);
		}
	}

	// inOrderX(r);

	cout << inOrderM(r) << " " << inOrder(r) << endl;

	return 0;
}