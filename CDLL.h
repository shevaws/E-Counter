#include <iostream>
#include <stack>
#include <string>

using namespace std;

const int max_data = 99;
struct Item
{
    string name;
    int price;
    int id_item;
    Item *next;
    Item *prev;
};

Item current_lsa;

struct Keranjang
{
    string nama_kategori[max_data];
    int harga_produk[max_data];
    int atas = -1;
};
Keranjang cart;

struct Pesanan
{
    string data_pesanan[max_data];
    int depan = -1;
    int belakang = -1;
};
Pesanan order;

int total = 0;

Item *head;
Item *tail;
Item *pulsa;
Item *kuota;
Item *current;
Item *wanted;

void buat_pulsa(string nama, int harga, int id)
{
    pulsa = new Item;
    pulsa->name = nama;
    pulsa->price = harga;
    pulsa->id_item = id;
    pulsa->next = NULL;
    pulsa->prev = NULL;
}

void buat_kuota(string nama, int harga, int id)
{
    pulsa = new Item;
    pulsa->name = nama;
    pulsa->price = harga;
    pulsa->id_item = id;
    pulsa->next = NULL;
    pulsa->prev = NULL;
}

void inisialisasi()
{
    head = NULL;
    tail = NULL;
}

bool Item_kosong()
{
    if (head == NULL && tail == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void tambah_prevp(string nama, int harga, int id)
{
    buat_pulsa(nama, harga, id);

    if (Item_kosong())
    {
        head = pulsa;
        tail = pulsa;
    }
    else
    {
        tail->next = pulsa;
        pulsa->prev = tail;
        tail = pulsa;
    }

    tail->next = head;
    head->prev = tail;
}

void tambah_prevk(string nama, int harga, int id)
{
    buat_pulsa(nama, harga, id);

    if (Item_kosong())
    {
        head = pulsa;
        tail = pulsa;
    }
    else
    {
        tail->next = pulsa;
        pulsa->prev = tail;
        tail = pulsa;
    }

    tail->next = head;
    head->prev = tail;
}

void hapus_prev()
{
    if (Item_kosong() == true)
    {
        cout << "Tidak ada Item" << endl;
    }
    else
    {
        current = head;
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
            delete current;
        }
        else
        {
            while (current->prev != tail)
            {
                current = current->prev;
            }
            tail = current;
            current = current->prev;
            current->next = NULL;
            current->prev = NULL;
            tail->next = head;
            head->prev = tail;
            delete current;
        }
    }
}

void tampil_pulsa()
{
    if (Item_kosong() == true)
    {
        cout << "tidak ada data" << endl;
    }
    else
    {
        current = head;
        do
        {
            cout << "Nama Pulsa: " << current->name << ", ";
            cout << "Harga: " << current->price << endl;
            current = current->next;
        } while (current != head);
    }
}

// stack keranjang
bool kosongKeranjang()
{
    if (cart.atas == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool penuhKeranjang()
{
    if (cart.atas == max_data - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void tambah_keranjang(int index_cari)
{
    wanted = head;
    while (wanted != NULL && wanted->id_item != index_cari)
    {
        wanted = wanted->next;
    }
    if (wanted == NULL)
    {
        cout << "Data yang dicari tidak ditemukan." << endl;
        return;
    }

    if (penuhKeranjang() == 0)
    {
        cart.atas++;
        cart.nama_kategori[cart.atas] = wanted->name;
        cart.harga_produk[cart.atas] = wanted->price;
        total += cart.harga_produk[cart.atas];
    }
}

void hapus_keranjang()
{
    if (kosongKeranjang() == 0)
    {
        cout << "Data berhasil dihapus" << endl;
        cart.atas--;
    }
    else
    {
        cout << "keranjang kosong" << endl;
    }
}

void tampil_keranjang()
{
    if (kosongKeranjang() == 0)
    {
        cout << "Isi Keranjang:" << endl;
        for (int i = 0; i <= cart.atas; i++)
        {
            cout << "Nama Kategori: " << cart.nama_kategori[i] << ", Harga: " << cart.harga_produk[i] << endl;
        }
        cout << "\nTotal Belanjaan: " << total << endl;
    }
    else
    {
        cout << "Keranjang kosong" << endl;
        return;
    }
}

// Queue Pesanan
bool kosongPesanan()
{
    if (order.depan == -1 && order.belakang == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool penuhPesanan()
{
    if (order.belakang == max_data - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void tambahPesanan()
{
    if (penuhPesanan() == 0)
    {
        order.depan = 0;
        order.belakang = 0;
        for (int i = cart.atas; i > -1; i--)
        {
            order.data_pesanan[order.belakang] = cart.nama_kategori[i];
            cart.atas--;
            order.belakang++;
        }
    }
}

void tampilPesanan()
{
    if (kosongPesanan() == 0)
    {
        for (int i = order.depan; i < order.belakang; i++)
        {
            cout << "Nama pesanan: " << order.data_pesanan[i] << endl;
        }
    }
    else
    {
        cout << "tidak ada pesanan" << endl;
    }
}