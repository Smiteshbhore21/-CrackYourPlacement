#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkSubArray(int arr[], int n)
{
    int i = 1;
    for (i; i < n && arr[i - 1] < arr[i]; i++);
    if (i == n)
        return true;

    int j = i;
    for (j; j < n && arr[j - 1] > arr[j]; j++){
        if (arr[i - 2] > arr[j])
            return false;
    }

    if (j == n)
        return true;

    int k=j;
    if (arr[k] < arr[i-1]) 
       return false; 
  
    while (k > 1 && k < n) 
    { 
        if (arr[k] < arr[k-1]) 
            return false; 
        k++; 
    } 
    return true; 
}

int main()
{
    int arr[] = {1, 3, 4, 10, 9, 8, 7, 6, 11, 12, 13}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    checkSubArray(arr, n)? cout << "Yes" : cout << "No"; 
    return 0; 
}
