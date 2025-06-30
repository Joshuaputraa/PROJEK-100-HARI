#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 5;

struct Barang
{
    string kode;
    string nama;
    int harga;
};

Barang daftarBarang[MAX] = {
    {"BRG01", "Indomie Goreng", 3000},
    {"BRG02", "Aqua Botol", 4000},
    {"BRG03", "SilverQueen", 15000},
    {"BRG04", "Taro Snack", 7000},
    {"BRG05", "Susu UHT", 9000}};

void tampilkanDaftarBarang()
{
    cout << "\nDaftar Barang:\n";
    cout << left << setw(10) << "Kode" << setw(20) << "Nama" << setw(10) << "Harga\n";
    for (int i = 0; i < MAX; i++)
    {
        cout << left << setw(10) << daftarBarang[i].kode
             << setw(20) << daftarBarang[i].nama
             << setw(10) << daftarBarang[i].harga << endl;
    }
}

int cariBarang(string kode)
{
    for (int i = 0; i < MAX; i++)
    {
        if (daftarBarang[i].kode == kode)
            return i;
    }
    return -1;
}

int main()
{
    string kodeInput;
    int qty, index, total = 0;
    char lanjut;

    cout << "=== Aplikasi Kasir Mini (Versi Console) ===\n";
    tampilkanDaftarBarang();

    do
    {
        cout << "\nMasukkan kode barang: ";
        cin >> kodeInput;
        index = cariBarang(kodeInput);
        if (index == -1)
        {
            cout << "Kode barang tidak ditemukan!\n";
            continue;
        }

        cout << "Jumlah beli: ";
        cin >> qty;

        int subtotal = daftarBarang[index].harga * qty;
        total += subtotal;

        cout << "-> " << daftarBarang[index].nama << " x" << qty
             << " = Rp" << subtotal << endl;

        cout << "Tambah barang lagi? (y/n): ";
        cin >> lanjut;

    } while (lanjut == 'y' || lanjut == 'Y');

    cout << "\n===============================\n";
    cout << "TOTAL BAYAR : Rp" << total << endl;

    int bayar;
    cout << "Uang bayar  : Rp";
    cin >> bayar;

    cout << endl;

    int kembalian = bayar - total;
    cout << "KEMBALIAN   : Rp" << kembalian << endl;
    cout << "===============================\n";
    cout << "Terima kasih telah berbelanja!\n";

    return 0;
}
