#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateBobotProfit(const string& nim, vector<int>& weight, vector<int>& profit) {
    for (char c : nim) {
        int val = (c == '0') ? 11 : (c - '0');
        weight.push_back(val);
    }
    vector<int> contohProfit = {21, 35, 70, 42, 80, 20, 10, 5};
    for (int i = 0; i < weight.size(); i++) {
        profit.push_back(contohProfit[i % contohProfit.size()]);
    }
}

void knapsack() {
    cout << "===== Knapsack Problem dengan Algoritma Greedy =====" << endl;

    string nim;
    cout << "Masukkan NIM (8 digit): ";
    cin >> nim;

    vector<int> weight, profit;
    generateBobotProfit(nim, weight, profit);

    cout << "Bobot dan Profit berdasarkan NIM:\n";
    for (int i = 0; i < weight.size(); i++) {
        cout << "Objek " << i+1 << ": Berat = " << weight[i] << ", Profit = " << profit[i] << endl;
    }

    int kapasitas = 15;
    cout << "Kapasitas knapsack diatur otomatis = " << kapasitas << endl;

    vector<pair<double, int>> rasio(weight.size());
    for (int i = 0; i < weight.size(); i++) {
        rasio[i] = make_pair((double)profit[i] / weight[i], i);
    }
    sort(rasio.rbegin(), rasio.rend());

    int totalProfit = 0;
    int sisaKapasitas = kapasitas;
    vector<double> hasil(weight.size(), 0);

    for (int i = 0; i < (int)weight.size(); i++) {
        int idx = rasio[i].second;
        if (weight[idx] <= sisaKapasitas) {
            hasil[idx] = 1;
            sisaKapasitas -= weight[idx];
            totalProfit += profit[idx];
        } else {
            hasil[idx] = (double)sisaKapasitas / weight[idx];
            totalProfit += profit[idx] * hasil[idx];
            sisaKapasitas = 0;
            break;
        }
    }

    cout << "\nHasil knapsack (fraksional):\n";
    for (int i = 0; i < (int)weight.size(); i++) {
        if (hasil[i] > 0)
            cout << "Objek " << i+1 << ": " << hasil[i]*100 << "% dimasukkan\n";
    }
    cout << "Total profit maksimal: " << totalProfit << endl;
}

int main() {
    cout << "===============================================\n";
    cout << "NAMA  : MUHAMMAD IBNU PRADIPTA\n";
    cout << "NIM   : 23533832\n";
    cout << "KELAS : 4A TI\n";
    cout << "===============================================\n\n";

    knapsack();
    return 0;
}
