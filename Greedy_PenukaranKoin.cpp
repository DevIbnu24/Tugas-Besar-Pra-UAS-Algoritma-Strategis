#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void penukaranKoin() {
    cout << "===== Penukaran Koin dengan Algoritma Greedy =====" << endl;
    int n;
    cout << "Tuliskan Banyaknya Koin : ";
    cin >> n;

    vector<int> koin(n);
    cout << "Masukan Jenis Koin :\n";
    for (int i = 0; i < n; i++) {
        cin >> koin[i];
    }

    sort(koin.rbegin(), koin.rend());

    int nilai;
    cout << "Masukan Nilai yang ditukarkan : ";
    cin >> nilai;

    vector<int> jumlahKeping(n, 0);

    for (int i = 0; i < n; i++) {
        if (nilai >= koin[i]) {
            jumlahKeping[i] = nilai / koin[i];
            nilai = nilai % koin[i];
        }
    }

    cout << "\nHasil Penukaran Koin:\n";
    for (int i = 0; i < n; i++) {
        cout << "Jumlah Keping " << koin[i] << "-an sebanyak : " << jumlahKeping[i] << endl;
    }
}

int main() {
    cout << "===============================================\n";
    cout << "NAMA  : MUHAMMAD IBNU PRADIPTA\n";
    cout << "NIM   : 23533832\n";
    cout << "KELAS : 4A TI\n";
    cout << "===============================================\n\n";

    penukaranKoin();
    return 0;
}
