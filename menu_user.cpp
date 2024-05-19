#include "CDLL.h"


int main()
{
    tambah_prevp("Super", 3000, 0);
    tambah_prevp("B aja", 2000, 1);
    tambah_prevp("Duper", 5000, 2);
    int choice;
    int inputPulsa;
    int inputKuota;

    do
    {
    menu:
        // dummy dataa

        cout << "\n\n>>>>> E-COUNTER ARRZ <<<<<" << endl;
        cout << "Apa Yang Ingin Anda Beli?" << endl;
        cout << "1. Pulsa" << endl;
        cout << "2. Kuota" << endl;
        cout << "3. Lihat Keranjang" << endl;
        cout << "4. Bayar" << endl;
        cout << "Harap Pilih: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            tampil_pulsa();

            cout << "Masukan ke keranjang: " << endl;
            cin >> inputPulsa;
            tambah_keranjang(inputPulsa - 1);
            break;
        }
        case 2:
        {
            tambahPesanan();
            tampilPesanan();

            break;
        }
        case 3:
        {
            tampil_keranjang();
            break;
        }
        case 4:
        {
            // Memilih metode pembayaran
            cout << "\n>>>>> Harap Pilih Metode Pembayaran <<<<<" << endl;
            cout << "1. BCA" << endl;
            cout << "2. Dana" << endl;
            cout << "3. Gopay" << endl;
            cout << "0. Kembali" << endl;
            // int paymentChoice;
        }
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (choice != 5); // Ulangi hingga pilihan adalah untuk keluar

    return 0;
}
