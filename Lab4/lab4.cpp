#include <iostream>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Binary_tree
{
    int value;
    Binary_tree *left, *right;
};

void add_element(int value, Binary_tree*& b_t)
{
    if(b_t == NULL)
    {
        b_t = new Binary_tree;
        b_t->value = value;
        b_t->left = b_t->right = NULL;
        return;
    }
    
    if (value > b_t->value)
        add_element(value, b_t->right);
    else
        add_element(value, b_t->left);
}

void print_tree(Binary_tree* b_t, int level)
{
    if(b_t)
    {
        print_tree(b_t->left, ++level);
        
        for(int i(0); i < level; i++)
            cout << "  ";
        
        cout << ">" << b_t->value << endl;
        
        print_tree(b_t->right, ++level);
    }
}

int main()
{
    
    Binary_tree* b_tree = NULL;
    
    int N, buffer;
    
    cout << "Enter the number of elements: "; cin >> N;
    
    for(int i(0); i < N; i++)
    {
        cout << "Enter the number: ";
        cin >> buffer;
        
        add_element(buffer, b_tree);
    }
    
    cout << "Result:" << endl;
    print_tree(b_tree, 0);
    
    return 0;
}


