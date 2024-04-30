/*
Author: JNIDV
Date created: 2024-04-30

Solution:
Use merge sort to interact with the pairs (i, j) such that A[i] < A[j].
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ans = 0;

void merge(int array[], const int left, const int mid, const int right) {
    const int subArrayOne = mid - left + 1, subArrayTwo = right - mid;
    int *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];
    for (auto i = 0; i < subArrayOne; i++) {
        leftArray[i] = array[left + i];
    }
    ll sum = 0;
    for (auto j = 0; j < subArrayTwo; j++) {
        rightArray[j] = array[mid + 1 + j];
        sum += rightArray[j];
    }
    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0, indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            ans += sum - (ll) (subArrayTwo - indexOfSubArrayTwo) * leftArray[indexOfSubArrayOne];
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            sum -= rightArray[indexOfSubArrayTwo];
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int array[], const int begin, const int end) {
    if (begin >= end) {
        return;
    }   
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void solve() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    mergeSort(A, 0, N - 1);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
