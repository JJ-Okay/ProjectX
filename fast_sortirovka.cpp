#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <clocale>

using namespace std;


void quick_sort(vector <int> &v,int begin0, int end0)
{
	auto d=end0;/
	auto begin=begin0;
	auto end=end0;

	do
	{
		while(v[begin]<d)
			begin++;
		while(v[end]>d)
			end--;
		if(begin<=end)
		{
			swap(v[begin],v[end]);// ì
			begin++;
			end--;
		}
	}while(begin<=end);
	if(begin0<end)
		quick_sort(v,begin0,end);
		if(begin<end0)
			quick_sort(v,begin,end0);
}
int main()
{ 
	setlocale(LC_CTYPE,"rus");
	vector <int> arr; 
	
	for(auto i=0;i<20;i++)
		arr.push_back(i);
	
	for(size_t i=0;i<arr.size();i++)
		swap(arr[i],arr[rand()%(arr.size()-i)+i]);
	cout<<"Massiv: ";
	for(auto i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	
	quick_sort(arr,0,arr.size()-1);
	cout<<"Bystraya sortirovka:";
	for(auto i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}