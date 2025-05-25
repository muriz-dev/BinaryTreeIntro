#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* initialize(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return initialize(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

Node* deleteNode(Node* root, int data) {
    if (root == nullptr) return nullptr;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        if (!root->left) {
            Node* right = root->right;
            delete root;
            return right;
        }
        if (!root->right) {
            Node* left = root->left;
            delete root;
            return left;
        }

        Node* successor = root->right;
        while (successor->left) {
            successor = successor->left;
        }

        root->data = successor->data;

        root->right = deleteNode(root->right, successor->data);
    }

    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

bool search(Node* root, int data) {
    if (root == nullptr) return false;
    if (root->data == data) return true;
    if (data < root->data) return search(root->left, data);

    return search(root->right, data);
}

Node* findMin(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->left != nullptr) root = root->left;

    return root;
}

Node* findMax(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->right != nullptr) root = root->right;

    return root;
}

int height(Node* root) {
    if (root == nullptr) return -1;
    return 1 + max(height(root->left), height(root->right));
}

int countLeaves(Node* root) {
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    // Inisialisasi BST
    Node* root = nullptr;

    // Membuat node baru pada BST
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 8);
    root = insert(root, 9);
    root = insert(root, 18);
    root = insert(root, 3);
    root = insert(root, 25);

    cout << height(root) << endl;

    // Menghitung jumlah daun pada BST
    cout << "Jumlah daun: " << countLeaves(root);

    cout << endl;

    // Menghapus node tertentu pada BST
    // deleteNode(root, 15); // Jika hanya menghapus 15 maka 18 akan menggantikannya sebagai daun
    // deleteNode(root, 18); // Jika hanya menghapus 18 maka 15 akan menggantikannya sebagai daun
    // deleteNode(root, 9); // Jika hanya menghapus 18 maka 15 akan menggantikannya sebagai daun

    // Mengurutkan setiap node
    inorder(root);

    cout << endl;

    preorder(root);

    cout << endl;

    postorder(root);

    cout << endl;

    // Menghitung jumlah daun pada BST
    cout << "Jumlah daun: " << countLeaves(root) << endl;



    return 0;
}