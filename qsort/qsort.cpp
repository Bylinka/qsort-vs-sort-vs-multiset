// qsort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <set>
#include <ctime>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int count = 10000000;
	int* arr = new int[count];
	int* arr2 = new int[count];
	int* arrbase = new int[count];
	srand(time(0));
	rand();

	generate(arr, arr + count, rand);
	copy(arr, arr + count, arr2);
	copy(arr, arr + count, arrbase);


	clock_t start = clock();
	qsort(arr, count, sizeof(int), [](const void* a, const void* b)->int {
		return *(int*)a - *(int*)b;
	});
	cout << "qsort time: " << (((double)clock() - start) / CLOCKS_PER_SEC) << endl;

	start = clock();
	sort(arr2, arr2 + count, [](const int i, const int j) {return i < j; });
	cout << "sort time: " << (((double)clock() - start) / CLOCKS_PER_SEC) << endl;

	start = clock();
	multiset<int> s;
	s.insert(arrbase, arrbase + count);
	copy(s.cbegin(), s.cend(), arrbase);
	cout << "binary time: " << (((double)clock() - start) / CLOCKS_PER_SEC) << endl;

	cout << endl;

	//for (auto i = 0; i < count; ++i)
	//	cout << arr[i] << " ";
	//cout << endl;
	//for (auto i = 0; i < count; ++i)
	//	cout << arr2[i] << " ";
	//cout << endl;
	//for (auto i = 0; i < count; ++i)
	//	cout << arrbase[i] << " ";
	//cout << endl;

	system("pause");
	delete[] arr, arr2, arrbase;
    return 0;
}

