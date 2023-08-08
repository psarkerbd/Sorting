#include<bits/stdc++.h>
using namespace std;

const int high = 105;

int ar[high], output[high];

int isMax(int x, int mx) {
    if(x > mx) {
        return x;
    }
    else {
        return mx;
    }
}

int getMax(int size) {
    int max = ar[0]; // Let the first element is maximum
    for(int i=1; i<size; i++) {
        max = isMax(ar[i], max);
    }
    cout << "Maximum number is: " << max << "\n";
    return max;
}

int input() {
    int N , mx;
    cout << "Enter N: ";
    cin >> N;
    cout << "Enter " << N << " elements:\n\n";
    for(int i=0; i<N; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> ar[i];
        output[i] = 0;
    }

    return N;
}

void printArray(int a[], int size) {
    for(int i=0; i<size; i++) {
        cout << a[i] << " ";
    }
}

void counting_sort(int size, int place) {
    int max_digit = 10;
    int counting[max_digit];

    // initialize the count array
    for(int i=0; i<max_digit; i++) {
        counting[i] = 0;
    }

    // count the digits in the main array
    for(int i=0; i<size; i++) {
        int val = ar[i] / place;
        int p = val % 10;
        counting[p] += 1;
        //cout << p << " has " << counting[p] << " times\n";
    }

    //printArray(counting, max_digit);

    // perform cumulative sum on counting array
    for(int i=1; i<max_digit; i++) {
        counting[i] += counting[i-1];
    }

    //printArray(counting, max_digit);

    // replace the position of elements in main array
    // array will be run from reverse order since
    // a number's digit count as unit, tenth, hundred and etc. 
    // from right to left
    for(int i=size-1; i>=0; i--) {
        int val = ar[i] / place;
        int p = val % 10; // the digit
        output[counting[p] - 1] = ar[i];
        counting[p] = counting[p] - 1;
    }

    for(int i=0; i<size; i++) {
        ar[i] = output[i];
    }

    for(int i=0; i<size; i++) {
        cout << ar[i] << " ";
    }

    cout << "\n";
}

void radix_sort(int size, int max) {
    for(int place = 1; max / place > 0; place *= 10) {
        counting_sort(size, place);
    }
}

int main() {
    int size = input();
    int maximum_value = getMax(size);
    radix_sort(size, maximum_value);
    cout << "Sorted Array:\n";
    printArray(ar, size);
    return 0;
}