#include<bits/stdc++.h>
using namespace std;

const int high = 100;

int ar[high];

void insertion_sort(int N)
{
    int key=0;

    for(int i=1; i<N; i++)
    {
        key = ar[i];

        int j = i-1;

        while(j >= 0 && ar[j] > key)
        {
            ar[j + 1] = ar[j];            
            //cout << j << "-" << ar[j] << "\n";
            j--;
        }

        ar[j + 1] = key;
    }
}

void sorted_array(int N)
{
    for(int i=0; i<N; i++)
    {
        cout << ar[i] << " ";
    }
}

int main()
{
    int N;
    cout << "Enter N: ";
    cin >> N;

    for(int i=0; i<N; i++)
    {
        cout << "Enter element " << i+1 << ": ";
        cin >> ar[i];
    }

    cout << "Before Sorted:\n";

    for(int i=0; i<N; i++)
    {
        cout << ar[i] << " ";
    }

    insertion_sort(N);

    cout << "\nAfter Sorted:\n";

    sorted_array(N);

    return 0;
}