#ifndef SPAREPART_TREE_H
#define SPAREPART_TREE_H

#include <string>
#include <fstream>
using namespace std;

struct Node {
    string name;
    int min_km;
    int max_km;
    Node* left;
    Node* right;
};

Node* createNode(string name, int min_km, int max_km);
Node* insertNode(Node* root, string name, int min_km, int max_km);

bool displayNeededPartsMatic(Node* root, int user_km, ofstream &file);
bool displayNeededPartsManual(Node* root, int user_km, ofstream &file);

void freeTree(Node* root);

#endif
