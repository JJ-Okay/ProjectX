#include <iostream>
#include <conio.h>
/*! \fn void print_arr (int* arr, int n)
 *  \brief print an array
 *  \param arr a pointer to array.
 *  \param n a size of array.
 */


using namespace std;
void print_arr (int* arr, int n)
{
	for (int i=0; i<n; i++)
		cout<<arr[i]<<endl;
}
/*! \fn void enter_arr (int* arr, int n)
 *  \brief enter an array
 *  \param arr a pointer to array.
 *  \param n a size of array.
 */
void enter_arr (int* arr, int n)
{
	for (int i=0; i<n;i++)
			cin>> arr [i];
}
/*! \fn void swap (int* a, int* b)
 *  \brief swap two elenments
 *  \param a a pointer to element.
 *  \param b a pointer to element.
 */
void swap (int *a, int *b)
{
		int temp;
		temp=*a;
		*a=*b;
		*b=temp;
}
/*! \fn void quick_sort (int* s_arr, int first, int last)
 *  \brief sort an array by quick type of sorting
 *  \param first an index of first element.
 *  \param last an index of last element .
 */
void quick_sort(int* s_arr, int first, int last)
{
    int i = first, j = last, x = s_arr[(first + last) / 2];
 
    do {
        while (s_arr[i] < x) i++;
        while (s_arr[j] > x) j--;
 
        if(i <= j) {
            if (s_arr[i] > s_arr[j]) swap(&s_arr[i], &s_arr[j]);
            i++;
            j--;
        }
    } while (i <= j);
 
    if (i < last)
        quick_sort(s_arr, i, last);
    if (first < j)
        quick_sort(s_arr, first, j);
}

int main()
{
	int num=0;
	cout << "Enter the number of of elements:\n";
	cin >> num;

	int* mass= new int [num];
	cout << "Enter the elements:\n";
	enter_arr(mass,num);
	quick_sort(mass, 0, num-1);
	cout<<"New array:\n";
	print_arr(mass,num);
	delete [] mass;

	getch();
}