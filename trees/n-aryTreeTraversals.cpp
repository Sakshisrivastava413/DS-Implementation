#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode(int val): val(val) {}
    TreeNode(int x, vector<TreeNode*> _children) : val(x), children(_children) {}
};

void preorderRecursive(TreeNode *root) {
    if(!root) return;
    cout << root->val << " ";
    for(int i = 0; i < root->children.size(); i++) {
        preorderRecursive(root->children[i]);
    }
}

void preorderIterative(TreeNode *root) {
    if(!root) return;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()) {
        auto top = s.top();
        s.pop();
        cout << top->val << " ";
        for(int i = top->children.size() - 1; i >= 0; i--) {
            s.push(top->children[i]);
        }
    }
}

void postorderRecursive(TreeNode* root) {
    if(!root) return;
    for(int i = 0; i < root->children.size(); i++) {
        postorderRecursive(root->children[i]);
    }
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
        for(int i = 0; i < top->children.size(); i++) s.push(top->children[i]);
    }
    reverse(res.begin(), res.end());
    for(int node: res) cout << node << " ";
}

void inorderIterative(TreeNode* root) {
    if(!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        auto top = q.front();
        q.pop();
        cout << top->val << " ";
        for(int i = 0; i < top->children.size(); i++) q.push(top->children[i]);
    }
}

int main() {
    TreeNode *root = new TreeNode(1);
    cout << root->children.size();
    (root->children).push_back(new TreeNode(2)); 
    (root->children).push_back(new TreeNode(3)); 
    (root->children).push_back(new TreeNode(4)); 
    (root->children).push_back(new TreeNode(5)); 
    (root->children[0]->children).push_back(new TreeNode(6)); 
    (root->children[0]->children).push_back(new TreeNode(8)); 
    (root->children[2]->children).push_back(new TreeNode(7)); 
    (root->children[3]->children).push_back(new TreeNode(9)); 
    (root->children[3]->children).push_back(new TreeNode(10)); 
    (root->children[3]->children).push_back(new TreeNode(11));
    cout << "Recursive Preorder: ";
    preorderRecursive(root);
    cout << "\nIterative Preorder: ";
    preorderIterative(root);
    cout << "\nRecursive Postorder: ";
    postorderRecursive(root);
    cout << "\nIterative Postorder: ";
    postorderIterative(root);
    cout << "\nIterative Inorder: ";
    inorderIterative(root);
}
