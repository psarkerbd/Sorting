#include<bits/stdc++.h>
using namespace std;

const int high = 105;

int arr[high], counting[high], output[high];

void init(int N) {
    for(int i=0; i<=N; i++) {
        counting[i] = 0;
        output[i] = 0;
    }
}

void Counting_Sort(int N) {
    for(int i=1; i<N; i++) {
        counting[i] = counting[i] + counting[i-1];
    }

    for(int i=0; i<N; i++) {
        cout << counting[i] << " ";
    }

    for(int i=0; i<N; i++) {
        int val = arr[i];
        output[counting[val]-1] = arr[i];
        counting[val] = counting[val]-1;
    }
}

void input(int N) {
    int max = INT_MIN;
    cout << "\nEnter " << N << " numbers:\n";
    for(int i=0; i<N; i++) {
        cin >> arr[i];
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "max = " << max << "\n";

    init(max + 1);

    for(int i=0; i<N; i++) {
        counting[arr[i]]+=1;
        cout << arr[i] << " has " << counting[arr[i]] << " times\n";
    }

    Counting_Sort(max + 1);

    cout << "\nSorted Data:\n";

    for(int i=0; i<N; i++) {
        cout << output[i] << " ";
    }
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;
    input(N);

    return 0;
}