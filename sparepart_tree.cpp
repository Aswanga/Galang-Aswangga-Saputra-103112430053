#include "sparepart_tree.h"
#include <iostream>
using namespace std;

Node* createNode(string name, int min_km, int max_km) {
    Node* node = new Node();
    node->name = name;
    node->min_km = min_km;
    node->max_km = max_km;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* insertNode(Node* root, string name, int min_km, int max_km) {
    if (!root)
        return createNode(name, min_km, max_km);

    if (min_km < root->min_km)
        root->left = insertNode(root->left, name, min_km, max_km);
    else
        root->right = insertNode(root->right, name, min_km, max_km);

    return root;
}

bool displayNeededPartsMatic(Node* root, int user_km, ofstream &file) {
    if (!root) return false;

    bool found = false;

    if (displayNeededPartsMatic(root->left, user_km, file))
        found = true;

    if (user_km >= root->min_km) {
        cout << "- " << root->name << " (" << root->min_km << "-" << root->max_km << " km)\n";
        file << "- " << root->name << " (" << root->min_km << "-" << root->max_km << " km)\n";
        found = true;
    }

    if (displayNeededPartsMatic(root->right, user_km, file))
        found = true;

    return found;
}

bool displayNeededPartsManual(Node* root, int user_km, ofstream &file) {
    if (!root) return false;

    bool found = false;

    if (displayNeededPartsManual(root->left, user_km, file))
        found = true;

    if (user_km > root->max_km) {
        cout << "- " << root->name << " (" << root->min_km << "-" << root->max_km << " km)\n";
        file << "- " << root->name << " (" << root->min_km << "-" << root->max_km << " km)\n";
        found = true;
    }

    if (displayNeededPartsManual(root->right, user_km, file))
        found = true;

    return found;
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
