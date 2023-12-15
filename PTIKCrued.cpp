#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct laptop {
  string brand;
  string seri;
  string processor;
  string ram;
  string rom;
  string panel;
  string daya;
  string harga;
};

 //Tampilkan menu seprti Menambahkan data, Menampilkan data, Mengupdate data, Menghapus data, dan keluar dari program
void tampilkanMenu() {
  cout << "Pilih operasi yang ingin Anda lakukan:\n";
  cout << "1. Menambahkan data laptop\n";
  cout << "2. Menampilkan data laptop\n";
  cout << "3. Mengupdate data laptop\n";
  cout << "4. Menghapus data laptop\n";
  cout << "5. Keluar dari program\n";
}

//Tambah data
void tambahData(vector<laptop>& data) {
  laptop m;
  cout << "Masukkan brand laptop: ";
  cin >> m.brand;
  cout << "Masukkan serial laptop: ";
  cin >> m.seri;
  cout << "Masukkan processor laptop: ";
  cin >> m.processor;
  cout << "Masukkan ram laptop: ";
  cin >> m.ram; 
  cout << "Masukkan rom laptop: ";
  cin >> m.rom;
  cout << "Masukkan Panel laptop: ";
  cin >> m.panel; 
  cout << "Masukkan daya laptop: ";
  cin >> m.daya;
  cout << "Masukkan harga laptop: ";
  cin >> m.harga;
  data.push_back(m);
  cout << "Data laptop berhasil ditambahkan.\n";
}

//Tampilkan data
void tampilkanData(const vector<laptop>& data) {
  if (data.empty()) {
    cout << "Tidak ada data laptop.\n";
    return;
  }
  cout << "Data laptop yang tersimpan:\n";
  cout << "No.\tBrend\tSerialLaptop\tProcessor\tRAM(GB)\tROM(GB)\tPanel\tDaya\tHarga(rp)\n";
  for (int i = 0; i < data.size(); i++) {
    cout << i + 1 << "\t" << data[i].brand << "\t" << data[i].seri << "\t" << data[i].processor << "\t" << data[i].ram << "\t" << data[i].rom << "\t" << data[i].panel << "\t" << data[i].daya << "\t" << data[i].harga << "\t" << "\n";
  }
}

//Ubah data
void ubahData(vector<laptop>& data) {
  if (data.empty()) {
    cout << "Tidak ada data laptop yang dapat diubah.\n";
    return;
  }
  int indeks;
  cout << "Masukkan nomor data laptop yang ingin diubah: ";
  cin >> indeks;
  if (indeks < 1 || indeks > data.size()) { 
    cout << "Nomor data laptop tidak valid.\n";
    return;
  }
  indeks--;
  laptop m;
  cout << "Masukkan nama laptop baru: ";
  cin >> m.brand;
  cout << "Masukkan Seri laptop baru: ";
  cin >> m.seri;
  cout << "Masukkan Processor laptop baru: ";
  cin >> m.processor;
  cout << "Masukkan RAM laptop baru: ";
  cin >> m.ram;
  cout << "Masukkan ROM laptop baru: ";
  cin >> m.rom;
  cout << "Masukkan Panel laptop baru: ";
  cin >> m.panel;
  cout << "Masukkan daya laptop baru: ";
  cin >> m.daya;
  cout << "Masukkan harga laptop baru: ";
  cin >> m.harga;
  data[indeks] = m;
  cout << "Data laptop berhasil diubah.\n";
}

//Hapus data
void hapusData(vector<laptop>& data) {
  if (data.empty()) {
    cout << "Tidak ada data laptop yang dapat dihapus.\n";
    return;
  }
  int indeks;
  cout << "Masukkan nomor data laptop yang ingin dihapus: ";
  cin >> indeks;
  if (indeks < 1 || indeks > data.size()) {
    cout << "Nomor data laptop tidak valid.\n";
    return;
  }
  indeks--;
  data.erase(data.begin() + indeks);
  cout << "Data laptop berhasil dihapus.\n";
}


int main() {
  vector<laptop> data;
  int pilihan;
  bool selesai = false;
  while (!selesai) { 
    tampilkanMenu();
    cout << "Masukkan pilihan Anda: ";
    cin >> pilihan;
    switch (pilihan) {
      case 1:
        tambahData(data);
        break;
      case 2:
        tampilkanData(data);
        break;
      case 3:
        ubahData(data);
        break;
      case 4:
        hapusData(data);
        break;
      case 5:
        selesai = true; 
        cout << "Terima kasih telah menggunakan program aplikasi CRUD ini.\n";
        break;
      default: 
        cout << "Pilihan Anda tidak valid. Silakan coba lagi.\n";
        break;
    }
  }
  return 0;
}