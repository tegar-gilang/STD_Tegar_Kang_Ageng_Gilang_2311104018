#include <iostream>
using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right, *parent;

    Pohon(char d, Pohon *l = NULL, Pohon *r = NULL, Pohon *p = NULL) 
        : data(d), left(l), right(r), parent(p) {}
};

Pohon *root, *baru;

void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

void buatNode(char data) {
    if(isEmpty()) {
        root = new Pohon(data, NULL, NULL, NULL);
        cout << "\nNode " << data << " berhasil dibuat menjadi root" << endl;
    } else {
        cout << "\nPohon sudah dibuat." << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node) {
    if(isEmpty()) {
    cout << "\nBuat tree terlebih dahul!"<< endl;
    return NULL;
    }
    if (node->left != NULL) {
        cout << "\n Node " << node->data << " sudah ada child di kiri "<< endl;
        return NULL;
    }
    baru = new Pohon(data, NULL, NULL, node);
    node ->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan di kiri " << node->data << endl;
    return baru;
}

Pohon *insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->right != NULL) {
        cout << "\nNode " << node->data << " Sudah ada child dikanan!" << endl;
        return NULL;
    }
    baru = new Pohon(data, NULL, NULL, node);
    node->right = baru;
    cout << "\nNode " << data << " Berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}

void update(char data, Pohon *node) {
    if(isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }
    if (!node) {
        cout << "\nNode yang diinginkan tidak ada!" << endl;
        return;
    }
    char temp = node->data;
    cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;

}

void retrieve(Pohon *node) {
    if(isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }
    if(!node) {
        cout << "\nNode yang diinginkan tidak ada!" << endl;
        return;
    }
    cout << "\nData node: " << node->data << endl;
}

// cari data Tree
void find (Pohon *node){
    if(isEmpty()){
        cout<<"\nBuat Tree terlebih dahulu"<<endl;
        return;
    }
    if(!node){
        cout<< "\nNode yang ditunjuk tidak ada!"<<endl;
        return;
    }
    cout<<"\nData Node: " <<node->data<<endl;
    cout << "Root: "<<root->data <<endl;
    cout << "Parent: "<<(node->parent ? node->parent->data : '(tidak punya Parent)') << endl;
    if(node->parent){
        if(node->parent->left == node && node->parent->right){
            cout<<"Sibling: " <<node->parent->right->data << endl;
            }
        else if(node->parent->right == node && node->parent->left){
            cout << "Sibling: " << node->parent->left->data << endl;
        }
        else{
            cout << "Sibling: (tidak ada sibling)" << endl;
        }
    }
}

int main(){
    init();
    buatNode('A');
    Pohon *nodeB = insertLeft('B', root);
    Pohon *nodeC = insertRight('C', root);
    insertLeft('D', nodeB);
    insertRight('E', nodeC);
    insertLeft('F', nodeB);
    insertRight('G', nodeC);

    cout<<"\n== pemanggilan retrieve";
    retrieve(root);
    retrieve(nodeB);
    retrieve(nodeC);

    cout<<"\n== pemanggilan Find (Node B)";
    find(nodeB);

    cout<<"\n== pemanggilan Find (Node C)";
    find(nodeC);

    cout<< "\n== pemanggilan Update (Mengubah Nnode B ke menjadi Z)";
    update('Z', nodeB);

    cout<< "\n pemangilan retrieve setelah Update";
    retrieve(nodeB);

    return 0;
}