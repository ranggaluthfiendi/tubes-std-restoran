#ifndef RESTORAN_H_INCLUDED
#define RESTORAN_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string posisi;
    Node* parent;
    Node* child;
    Node* next;

    Node(string p) {
        posisi = p;
        parent = nullptr;
        child = nullptr;
        next = nullptr;
    }
};

Node* createNode(string posisi);
void addChild(Node* parent, Node* child);
void addSibling(Node* node, Node* sibling);
void display(Node* root, int depth = 0);
Node* search(Node* root, string posisi);
int countChildren(Node* parent);

#endif // RESTORAN_H_INCLUDED
