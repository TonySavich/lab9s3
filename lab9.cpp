﻿#include <iostream>

using namespace std;
void help(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        help(arr, n, largest);
    }
}

void heap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        help(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        help(arr, i, 0);
    }
}

int main()
{
    int arr[] = { 12, 91, 13, 5, 6, 7, 27, 33,  70};
    int n = 9;
    heap(arr, n);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}