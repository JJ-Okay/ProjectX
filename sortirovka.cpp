#include <iostream>
using namespace std;

int main()
{
    
    setlocale(LC_ALL,"Russian");
    int size;
    cout << "Vvedite razmer massiva dlya sortirovki:" << endl ;
    cin >> size;

  
    int *a = new int[size];

    
    for (int i = 0; i < size; i++)
    {
        cout << "Vvedite chislo dlya sortirovki,=enter= dlya sleduyushhego chisla" << endl;
        cin >> a[i];
    }

    
    for (int i = 0; i < size; i++)
    {
        
        for (int j = size - 1; j > i; j--)
        {
            
            if (a[j] < a[j - 1])
            {
                swap (a[j], a[j - 1]);
            }
        }
    }

    
    cout << "Otsortirovannyj massiv:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << ' ';
    }

    return 0;
}
