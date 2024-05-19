#include "CDLL.h"

void sub_menu(int pilihan)
{
    int subPilihan;
    string inputNama;
    int inputHarga;

    do
    {
        if (pilihan == 1)
        {
            cout << "\n\n>>>>> SUB MENU PULSA<<<<<" << endl;
            tampil_pulsa();
            cout << "\n1. Tambah Pulsa" << endl;
            cout << "2. Hapus Pulsa" << endl;
            cout << "3. Update Pulsa" << endl;
            cout << "Harap Pilih: ";
            cin >> subPilihan;

            switch (subPilihan)
            {
            case 1:
            {
                cin.ignore();
                cout << "Masukan nama pulsa: ";
                getline(cin, inputNama);
                cout << "Masukan harga pulsa: ";
                cin >> inputHarga;
                tambah_prevp(inputNama, inputHarga, 01);
                break;
            }
            case 2:
            {

                break;
            }
            case 3:
            {

                break;
            }
            default:
            {
                break;
            }
            }
        }
        else if (pilihan == 2)
        {
            cout << "\n\n>>>>> SUB MENU KUOTA<<<<<" << endl;
            tampil_pulsa();
            cout << "\n1. Tambah kuota" << endl;
            cout << "2. Hapus kuota" << endl;
            cout << "3. Update kuota" << endl;
            cout << "Harap Pilih: ";
            cin >> subPilihan;

            switch (subPilihan)
            {
            case 1:
            {
                cout << "Masukan nama kuota: ";
                getline(cin, inputNama);
                cout << "Masukan harga kuota: ";
                cin >> inputHarga;
                tambah_prevk(inputNama, inputHarga, 02);
                break;
            }
            case 2:
            {

                break;
            }
            case 3:
            {

                break;
            }
            default:
            {
                break;
            }
            }
        }
    } while (subPilihan != 0);
}

int main()
{
    int choice;
    do
    {
    menu:
        // Menampilkan menu utama
        cout << "\n\n>>>>> ADMIN E-COUNTER ARRZ <<<<<" << endl;
        cout << "Modifikasi Data" << endl;
        cout << "1. Pulsa" << endl;
        cout << "2. Kuota" << endl;
        cout << "0. Keluar" << endl;
        cout << "Harap Pilih: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            sub_menu(1);
            break;
        }
        case 2:
        {
            sub_menu(2);
            break;
        }
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (choice != 0); // Ulangi hingga pilihan adalah untuk keluar

    return 0;
}
