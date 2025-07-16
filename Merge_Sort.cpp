#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int> &arr, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);

    int i = left, j = mid+1;
    vector<int> temp;
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
}

void mergeSortMenu() {
    cout << "===== Merge Sort dengan Algoritma Divide and Conquer =====" << endl;
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Masukkan elemen array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n-1);

    cout << "Array setelah diurutkan:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "===============================================\n";
    cout << "NAMA  : MUHAMMAD IBNU PRADIPTA\n";
    cout << "NIM   : 23533832\n";
    cout << "KELAS : 4A TI\n";
    cout << "===============================================\n\n";

    mergeSortMenu();
    return 0;
}
