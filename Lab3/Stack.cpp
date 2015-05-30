#include <iostream>

using namespace std;

struct Stack
{
    double d;
    struct Stack *next;
};

void pushfirst(Stack* &next, double d)
{
    Stack *pv = new Stack;
    pv->d = d;
    pv->next = next;
    next = pv;
}

void pop(Stack* &next)
{
    if (next != NULL)
    {
        double temp = next->d;
        Stack *pv = next;
        next = next->next;
        delete pv;
    }

}
void print(Stack* one)
{
    Stack *two = one;
    while (two)
    {
        cout << "\t" << two->d << endl;
        two = two->next;
    }
    cout << endl;
}


void Menu()
{
    cout << "\tChoose the action to do with Steak:" << endl;
    cout << "\n\t1. Push first element" << endl;
    cout << "\t2. Pop first element" << endl;
    cout << "\n\t0. Exit" << endl;
}

int main()
{
    Stack *p = NULL;
    int c = 10;
    double data;
    while (c != 0)
    {
        Menu();
        cout << "\nStatus of Stack: " << endl;
        print(p);
        cout << "\n>>> "; cin >> c;
        switch (c) {
            case 1:
                cout << "\nData: ";
                cin >> data;
                pushfirst(p, data);
                system("cls");
                break;
            case 2:
                pop(p);
                system("cls");
                break;
            case 0: c = 0;
                break;;
            default: cout << "Wrong action!" << endl;
                system("cls");
                break;
        }
    }
}

