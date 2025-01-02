#include <iostream>
#include <queue>
using namespace std;

struct ElmNode;

struct ElmEdge{
    ElmNode *Node;
    ElmEdge *Next;
};

struct ElmNode{
    char info;
    bool visited;
    ElmEdge *firstEdge;
    ElmNode *Next;
};

struct Graph{
    ElmNode *first;
};

void CreateGraph(Graph &G){
    G.first = nullptr;
}

void InsertNode(Graph &G, char X){
    ElmNode *newNode = new ElmNode;
    newNode->info = X;
    newNode->visited = false;
    newNode->firstEdge = NULL;
    newNode->Next = NULL;
    if(G.first == NULL){
        G.first = newNode;
    }else{
        ElmNode *temp = G.first;
        while(temp->Next != NULL){
            temp=temp->Next;
        }
        temp->Next = newNode;
    }
}

void ConnectNode(ElmNode *N1, ElmNode *N2){
    ElmEdge *NewEdge = new ElmEdge;
    NewEdge->Node = N2;
    NewEdge->Next = N1->firstEdge;
    N1->firstEdge = NewEdge;
}

void printInfoGraph(Graph G){
    ElmNode *temp = G.first;
    while(temp != NULL){
        cout << temp->info <<" ";
        temp = temp->Next;
    }
    cout << endl;
}

void resetVisited(Graph G){
    ElmNode *temp = G.first;
    while (temp != NULL){
        temp->visited = false;
        temp = temp->Next;
    } 
}

void PrintDFS(Graph G, ElmNode*N){
    if(N == NULL){
        return;
    }
    N->visited = true;
    cout << N->info << " ";
    ElmEdge *edge = N->firstEdge;
    while(edge != NULL){
        if(!edge->Node->visited){
            PrintDFS(G, edge->Node);
        }
        edge = edge->Next;
    }
}

void PrintBFS(Graph &G, ElmNode *N){
    queue<ElmNode*> q;
    q.push(N);
    N->visited = true;

    while (!q.empty()){
        ElmNode *current = q.front();
        q.pop();
        cout << current->info << " ";

        ElmEdge *edge = current->firstEdge;
        while(edge != NULL){
            if(!edge->Node->visited){
                edge->Node->visited = true;
                q.push(edge->Node);
            }
            edge = edge->Next;
        }
    }
}

int main(){
    Graph G;

    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    ElmNode *A = G.first;
    ElmNode *B = A->Next;
    ElmNode *C = B->Next;
    ElmNode *D = C->Next;
    ElmNode *E = D->Next;
    ElmNode *F = E->Next;
    ElmNode *G1 = F->Next;
    ElmNode *H = G1->Next;

    ConnectNode(A,B);
    ConnectNode(A,C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, G1);
    ConnectNode(D, H);

    cout << " DFS traversal : ";
    resetVisited(G);
    PrintDFS(G, A);
    cout<<endl;

    cout<<"BFS Traversal : ";
    resetVisited(G);
    PrintBFS(G, A);
    cout << endl;
    return 0;
}


