#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right, *left;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val): val(val), right(nullptr), left(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preorderRecursive(TreeNode* root) {
    if(!root) return;
    cout << root->val << " ";
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

void preorderIterative(TreeNode* root) {
    if(!root) return;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()) {
        auto top = s.top();
        s.pop();
        cout << top->val << " ";
        if(top->right) s.push(top->right);
        if(top->left) s.push(top->left);
    }
}

void postorderRecursive(TreeNode* root) {
    if(!root) return;
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    cout << root->val << " ";
}

void postorderIterative(TreeNode* root) {
    if(!root) return;
    stack<TreeNode*> s;
    s.push(root);
    vector<int> res;
    while(!s.empty()) {
        auto top = s.top();
        s.pop();
        res.push_back(top->val);
        if(top->left) s.push(top->left);
        if(top->right) s.push(top->right);
    }
    reverse(res.begin(), res.end());
    for(int node: res) cout << node << " ";
}

void inorderRecursive(TreeNode* root) {
    if(!root) return;
    inorderRecursive(root->left);
    cout << root->val << " ";
    inorderRecursive(root->right);
}

void inorderIterative(TreeNode* root) {
    if(!root) return;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()) {
        while(root->left) {
            s.push(root->left);
            root = root->left;
        }
        auto top = s.top();
        s.pop();
        cout << top->val << " ";
        if(top->right) {
            s.push(top->right);
        }
    }
}

void levelOrder(TreeNode* root) {
    if(!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        auto top = q.front();
        q.pop();
        cout << top->val << " ";
        if(top->left) q.push(top->left);
        if(top->right) q.push(top->right);
    }
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3); 
    root->left->left = new TreeNode(4); 
    root->left->right = new TreeNode(5);
    cout << "Recursive Preorder: ";
    preorderRecursive(root);
    cout << "\nIterative Preorder: ";
    preorderIterative(root);
    cout << "\nRecursive Postorder: ";
    postorderRecursive(root);
    cout << "\nIterative Postorder: ";
    postorderIterative(root);
    cout << "\nRecursive Inorder: ";
    inorderRecursive(root);
    cout << "\nIterative Inorder: ";
    inorderIterative(root);
    cout << "\nIterative Level Order: ";
    levelOrder(root);
}
