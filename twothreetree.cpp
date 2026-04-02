#include <iostream>
#include <vector>

class TwoThreeNode {
public:
    std::vector<int> keys;
    std::vector<TwoThreeNode*> children;
    bool isLeaf;

    TwoThreeNode(bool leaf = true) : isLeaf(leaf) {}
};

class TwoThreeTree {
private:
    TwoThreeNode* root;

    void splitChild(TwoThreeNode* x, int i) {
        TwoThreeNode* y = x->children[i];
        TwoThreeNode* z = new TwoThreeNode(y->isLeaf);

        z->keys.push_back(y->keys[1]);
        y->keys.pop_back();

        if (!y->isLeaf) {
            z->children.push_back(y->children[2]);
            z->children.push_back(y->children[3]);
            y->children.pop_back();
            y->children.pop_back();
        }

        x->children.insert(x->children.begin() + i + 1, z);
        x->keys.insert(x->keys.begin() + i, y->keys[1]);
        y->keys.pop_back();
    }

    void insertNonFull(TwoThreeNode* x, int k) {
        int i = x->keys.size() - 1;

        if (x->isLeaf) {
            x->keys.push_back(0);
            while (i >= 0 && k < x->keys[i]) {
                x->keys[i + 1] = x->keys[i];
                i--;
            }
            x->keys[i + 1] = k;
        } else {
            while (i >= 0 && k < x->keys[i]) {
                i--;
            }
            i++;
            if (x->children[i]->keys.size() == 2) {
                splitChild(x, i);
                if (k > x->keys[i]) {
                    i++;
                }
            }
            insertNonFull(x->children[i], k);
        }
    }

    void inorderTraversal(TwoThreeNode* node) {
        if (node != nullptr) {
            int i;
            for (i = 0; i < node->keys.size(); i++) {
                if (!node->isLeaf) {
                    inorderTraversal(node->children[i]);
                }
                std::cout << node->keys[i] << " ";
            }
            if (!node->isLeaf) {
                inorderTraversal(node->children[i]);
            }
        }
    }

public:
    TwoThreeTree() : root(nullptr) {}

    void insert(int k) {
        if (root == nullptr) {
            root = new TwoThreeNode();
            root->keys.push_back(k);
            return;
        }

        if (root->keys.size() == 2) {
            TwoThreeNode* s = new TwoThreeNode(false);
            s->children.push_back(root);
            splitChild(s, 0);
            int i = 0;
            if (s->keys[0] < k) {
                i++;
            }
            insertNonFull(s->children[i], k);
            root = s;
        } else {
            insertNonFull(root, k);
        }
    }

    void printInorder() {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    TwoThreeTree t;
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    std::cout << "Inorder traversal of 2-3 tree: ";
    t.printInorder();

    return 0;
}