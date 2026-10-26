#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);

        return node;
    }

   
    void inorder(Node* node) {
        if (node == nullptr)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    
    void preorder(Node* node) {
        if (node == nullptr)
            return;

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    
    void postorder(Node* node) {
        if (node == nullptr)
            return;

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void inorder() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void preorder() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    void postorder() {
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int n, value, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }

    do {
        cout << "\nBST Operations\n";
        cout << "1. Inorder Traversal\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Postorder Traversal\n";
        cout << "4. All Traversals\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tree.inorder();
                break;

            case 2:
                tree.preorder();
                break;

            case 3:
                tree.postorder();
                break;

            case 4:
                tree.inorder();
                tree.preorder();
                tree.postorder();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
