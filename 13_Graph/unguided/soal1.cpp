#include <iostream>
#include <iomanip>
using namespace std;

struct ElmNode;

struct ElmEdge {
    ElmNode *Node;
    int weight; // Bobot
    ElmEdge *Next;
};

struct ElmNode {
    string info; // Nama simpul
    ElmEdge *firstEdge;
    ElmNode *Next;
};

struct Graph {
    ElmNode *first;
};

void CreateGraph(Graph &G) {
    G.first = nullptr;
}

void InsertNode(Graph &G, string X) {
    ElmNode *newNode = new ElmNode;
    newNode->info = X;
    newNode->firstEdge = NULL;
    newNode->Next = NULL;
    if (G.first == NULL) {
        G.first = newNode;
    } else {
        ElmNode *temp = G.first;
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = newNode;
    }
}

ElmNode *findNode(Graph G, string X) {
    ElmNode *temp = G.first;
    while (temp != NULL) {
        if (temp->info == X) {
            return temp;
        }
        temp = temp->Next;
    }
    return NULL;
}

void ConnectNode(ElmNode *N1, ElmNode *N2, int weight) {
    ElmEdge *NewEdge = new ElmEdge;
    NewEdge->Node = N2;
    NewEdge->weight = weight;
    NewEdge->Next = N1->firstEdge;
    N1->firstEdge = NewEdge;
}

void PrintAdjacencyMatrix(Graph G, int nodeCount) {
    // Header matriks
    ElmNode *row = G.first;
    cout << setw(8) << " ";
    while (row != NULL) {
        cout << setw(8) << row->info;
        row = row->Next;
    }
    cout << endl;

    // Isi matriks
    row = G.first;
    while (row != NULL) {
        cout << setw(8) << row->info;
        ElmNode *col = G.first;
        while (col != NULL) {
            // Cari bobot sisi antara row dan col
            ElmEdge *edge = row->firstEdge;
            int weight = 0; // Default tidak terhubung
            while (edge != NULL) {
                if (edge->Node == col) {
                    weight = edge->weight;
                    break;
                }
                edge = edge->Next;
            }
            cout << setw(8) << weight;
            col = col->Next;
        }
        cout << endl;
        row = row->Next;
    }
}

int main() {
    Graph G;
    CreateGraph(G);

    int n;
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> n;

    // Input nama simpul
    for (int i = 0; i < n; ++i) {
        string nodeName;
        cout << "Simpul " << i + 1 << ": ";
        cin >> nodeName;
        InsertNode(G, nodeName);
    }

    // Input bobot antar simpul
    ElmNode *row = G.first;
    while (row != NULL) {
        ElmNode *col = G.first;
        while (col != NULL) {
            int weight;
            cout << row->info << " --> " << col->info << " = ";
            cin >> weight;
            if (weight > 0) {
                ConnectNode(row, col, weight);
            }
            col = col->Next;
        }
        row = row->Next;
    }

    // Cetak matriks bobot
    cout << "\nMatriks Bobot:\n";
    PrintAdjacencyMatrix(G, n);

    return 0;
}
