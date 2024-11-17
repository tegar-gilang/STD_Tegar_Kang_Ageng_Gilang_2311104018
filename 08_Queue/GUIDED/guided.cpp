#include <iostream>
using namespace std;

const int maksimalQueue = 5;
int front = 0;
int back = 0;
string queueteller[5];

bool isFull(){
    if (back == maksimalQueue){
        return true;
    } else {
        return false;
    }
}
bool isEmpty(){
    if (back == 0){
        return true;
    }else {
        return false;
    }
}
void enqueueAntrian(string data){
    if (isFull()){
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()){
            queueteller[0] = data;
            front++;
            back++;
        } else {
            queueteller[back] = data;
            back++;
        }
    }
}
void dequeueAntrian(){
    if (isEmpty()){
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back -1; i++){
            queueteller[i] = queueteller[i + 1];
        }
        queueteller[back - 1] = " ";
        back--;
    }
}
int countqueue(){
    return back;
}
void clearqueue(){
    if (isEmpty()){
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++){
            queueteller[i] = " ";
        }
        back = 0;
        front = 0;
    }
}
void viewqueue(){
    cout << "data antrian teller: " << endl;
    for (int i = 0; i < maksimalQueue; i++){
        if (queueteller[i] != ""){
            cout << i + 1 << ". " << queueteller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}
int main(){
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewqueue();
    cout << "Jumlah Antrian= " << countqueue() << endl;
    dequeueAntrian();
    viewqueue();
    cout << "Jumlah Antrian= " << countqueue() << endl;
    clearqueue();
    viewqueue();
    cout << "Jumlah Antrian= " << countqueue() << endl;
    return 0;
}