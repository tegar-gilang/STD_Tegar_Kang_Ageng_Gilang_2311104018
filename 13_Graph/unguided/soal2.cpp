#include <iostream>
#include <vector>
using namespace std;

int main() {
    int numNodes, numEdges;

    // Input jumlah simpul dan sisi
    cout << "Masukkan jumlah simpul: ";
    cin >> numNodes;
    cout << "Masukkan jumlah sisi: ";
    cin >> numEdges;

    // Inisialisasi adjacency matrix
    vector<vector<int>> adjacencyMatrix(numNodes, vector<int>(numNodes, 0));

    // Input pasangan simpul yang terhubung
    cout << "Masukkan pasangan simpul:" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        // Karena graf tak berarah, hubungkan dua arah
        adjacencyMatrix[u - 1][v - 1] = 1;
        adjacencyMatrix[v - 1][u - 1] = 1;
    }

    // Output adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
