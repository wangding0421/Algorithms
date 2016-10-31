#include <iostream>
using namespace std;

struct TreeNode{
    int key;
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int k, int v):
        key(k),
        val(v),
        left(nullptr),
        right(nullptr){}
};

class BSTHash{
public:
    BSTHash(){
        root_ = nullptr;
    }

    BSTHash(int k, int v){
        root_ = new TreeNode(k,v);
    }

    string PrintTree() {
        return PrintTreeHelper(root_);
    }

    string PrintTreeHelper(TreeNode* node) {
        string result = "";
        if (node == nullptr) {
            result += "# ";
            return result;
        }

        result += to_string(node->val);
        result += " ";
        result += PrintTreeHelper(node->left);
        result += PrintTreeHelper(node->right);
        return result;
    }

    void Add(int k, int v){
        if (root_) AddHelper(k, v, root_);
        else {
            root_ = new TreeNode(k, v);
        }
    }

    void AddHelper(int k, int v, TreeNode* node) {
        if (k < node->key) {
            if (node->left) {
                AddHelper(k, v, node->left);
            } else {
                node->left = new TreeNode(k, v);
            }
        } else if (k > node->key) {
            if (node->right) {
                AddHelper(k, v, node->right);
            } else {
                node->right = new TreeNode(k,v);
            }
        } else {
            node->val = v;
        }
        return;
    }

    int find(int k) {
        return FindHelper(k, root_); 
    }

    int FindHelper(int k, TreeNode* root) {
        if (root == nullptr) {
            return -1;
        }
        if (root->key == k) {
            return root->val;
        } else if (root->key < k) {
            return FindHelper(k, root->right);
        } else {
            return FindHelper(k, root->left);
        }
    }
private:
    TreeNode* root_;
};

int main() {
    BSTHash b(12,10);
    cout << b.PrintTree() << endl;
    cout << "add 5,4" << endl;
    b.Add(5, 4);
    cout << b.PrintTree() << endl;
    cout << "add 10, 100" << endl;
    b.Add(10,100);
    cout << "add 11, 100" << endl;
    b.Add(11, 100);
    cout << b.PrintTree() << endl;

    cout << b.find(10);
    cout << b.find(12) << b.find(5) << b.find(13) << endl;
}
