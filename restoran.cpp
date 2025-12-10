#include "restoran.h"

Node* createNode(string posisi) {
    return new Node(posisi);
}

void addChild(Node* parent, Node* child) {
    if (!parent) return;
    child->parent = parent;
    if (!parent->child)
        parent->child = child;
    else {
        Node* temp = parent->child;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = child;
    }
}

void addSibling(Node* node, Node* sibling) {
    if (!node) return;
    while (node->next != nullptr)
        node = node->next;
    node->next = sibling;
    sibling->parent = node->parent;
}

void display(Node* root, int depth) {
    if (!root) return;
    for (int i = 0; i < depth; i++)
        cout << "   ";
    cout << "- " << root->posisi << endl;
    display(root->child, depth + 1);
    display(root->next, depth);
}

Node* search(Node* root, string posisi) {
    if (!root) return nullptr;
    if (root->posisi == posisi) return root;
    Node* found = search(root->child, posisi);
    if (found) return found;
    return search(root->next, posisi);
}

int countChildren(Node* parent) {
    if (!parent || !parent->child) return 0;
    int count = 0;
    Node* temp = parent->child;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}
