#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

Node* createNode(char data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Gagal mengalokasikan memori";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insertNode(Node* root, char data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    } else {
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1 && data < root->left->data) {
        return rotateRight(root);
    }

    if (balanceFactor < -1 && data > root->right->data) {
        return rotateLeft(root);
    }

    if (balanceFactor > 1 && data > root->left->data) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balanceFactor < -1 && data < root->right->data) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void preOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;

    // Memasukkan data ke dalam AVL Tree
    root = insertNode(root, 'm');
    root = insertNode(root, 'e');
    root = insertNode(root, 'a');
    root = insertNode(root, 'i');
    root = insertNode(root, 'u');
    root = insertNode(root, 'l');
    root = insertNode(root, 'o');
    root = insertNode(root, 'p');
    root = insertNode(root, 'b');

    // Traversal Preorder
    cout << "Preorder traversal: ";
    preOrderTraversal(root);
    cout << endl;

    // Traversal Inorder
    cout << "Inorder traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // Traversal Postorder
    cout << "Postorder traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
