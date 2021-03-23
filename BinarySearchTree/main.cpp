#include <iostream>
#include <iomanip>

using namespace std;

// forward declaration
class Node;

typedef Node *NodePtr;

class Node {
public:
    int data;
    NodePtr left;
    NodePtr right;

    Node() : data(-1), left(nullptr), right(nullptr) {}
};

class BST {
private:
    NodePtr root;

public:
    BST() : root(nullptr) {}

    void Insert(int num) {
        insert(num, root);
    }

    void Remove(int num) {

        NodePtr node = root;
        NodePtr parent = nullptr;

        // find the node to delete
        while (node != nullptr) {
            if (num < node->data) {
                parent = node;
                node = node->left;
            } else if (num > node->data) {
                parent = node;
                node = node->right;
            } else {
                break;
            }
        }

        // didn't find the node
        if (node == nullptr) return;

        // case 1: node with two children
        if (node->left != nullptr && node->right != nullptr) {
            // start left
            NodePtr successor = node->left;

            // go as far right as I can
            parent = node;
            while (successor->right != nullptr) {
                parent = successor;
                successor = successor->right;
            }

            // swap values with the successor
            node->data = successor->data;
            // the successor becomes the node to delete
            node = successor;
        }

        // now that we have dealt with the two child case
        // we can assume the node to delete has one or no
        // children

        // assume there is a left child
        NodePtr subtree = node->left;
        // if no left child, then assume a right child
        if (subtree == nullptr) {
            subtree = node->right;
        }

        if (parent == nullptr) {
            // deleting the root node
            // make the child the new root
            root = subtree;
        } else if (parent->left == node) {
            // deleting a left child
            // connect parent to grandchild
            parent->left = subtree;
        } else if (parent->right == node) {
            // deleting a right child
            parent->right = subtree;
        }

        // finally I can delete!
        delete node;
    }

private:
    void insert(int num, NodePtr &node) {
        if (node == nullptr) {
            node = new Node();
            node->data = num;
        } else if (num < node->data) {
            insert(num, node->left);
        } else if (num > node->data) {
            insert(num, node->right);
        } else {
            cout << "Node value " << node->data << " already exists." << endl;
        }
    }

    void printTree(ostream &output, NodePtr &node, int indent) {
        if (node != nullptr) {
            printTree(output, node->right, indent + 8);
            output << setw(indent) << node->data << endl;
            printTree(output, node->left, indent + 8);
        }
    }

    friend ostream &operator<<(ostream &output, BST &bst);
};

ostream &operator<<(ostream &output, BST &bst) {
    bst.printTree(output, bst.root, 0);
    return output;
}

int main() {

    BST bst;

    bst.Insert(5);
    bst.Insert(3);
    bst.Insert(7);
    bst.Insert(2);
    bst.Insert(4);
    bst.Insert(6);
    bst.Insert(8);

    cout << bst << endl;

    // test 2
    cout << "\n\nTest 2\n";
    cout << "------" << endl;

    bst.Remove(7);

    cout << bst << endl;

    return 0;
}