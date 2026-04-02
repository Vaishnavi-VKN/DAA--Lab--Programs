struct Node {
    char data; unsigned freq; Node *left, *right;
    Node(char d, unsigned f) : data(d), freq(f), left(nullptr), right(nullptr) {}
};

struct compare {
    bool operator()(Node* l, Node* r) { return l->freq > r->freq; }
};

void printCodes(Node* root, string str) {
    if (!root) return;
    if (root->data != '$') cout << root->data << ": " << str << "\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}