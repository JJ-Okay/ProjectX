#include <iostream>


using namespace std;

struct Queue
{
    int tail = 99999;
    int head = 99999;
    int qarray[100000];
};

void add(Queue* p, int value)
{
    if (p->tail < 0)
    {
        cout << "Queue is overflow!" << endl;
        return;
    }
    p->qarray[p->tail--] = value;
}
int del(Queue* p)
{
    if (p->tail == 100000)
    {
        cout << "Queue is empty!" << endl;
        return 0;
    }
    return p->qarray[p->head--];
}
void print(Queue* p)
{
    for (int i(p->head), j(0); i > p->tail; i--, j++)
        cout << "\t" << p->qarray[i] << endl;
}
void Menu()
{
    cout << "\tChoose the action to do with Queue:" << endl;
    cout << "\n\t1. Add element" << endl;
    cout << "\t2. Delete last element" << endl;
    cout << "\n\t0. Exit" << endl;
}

int main()
{
    Queue *Q = new Queue;
    int c = 10;
    double data;
    while (c != 0)
    {
        Menu();
        cout << "\nStatus of queue: " << endl;
        print(Q);
        cout << "\n>>> "; cin >> c;
        switch (c) {
            case 1:
                cout << "\nData: ";
                cin >> data;
                add(Q, data);
                system("cls");
                break;
            case 2:
                del(Q);
                system("cls");
                break;
        }
    }

    return 0;
}
