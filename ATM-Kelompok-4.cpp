#include <iostream>
#include <windows.h> //Fungsi sleep() dan system() merupakan bagian dari library ini
using namespace std;

//Inisiasi variable-variable
string pin = "241063";
int saldo = 1170000;//1.170.000
int pilihan_bahasa;

//inisiasi function
void tampilan_awal();
void kartu_atm();
void input_pilihan_bahasa();

//Program Utama
int main()
{
    tampilan_awal();
    kartu_atm();
    input_pilihan_bahasa();
    if (pilihan_bahasa == 1)
    {
        cout << "Bangga dengan Bahasa Persatuan";
    }else if (pilihan_bahasa == 2)
    {
        cout << "Continue in English";
    }
    
    return 0;
}

//Isi dari fungsi-fungsi
void tampilan_awal()
{
    cout << "=============================================" << endl;
    cout << "\t\t\b\bSelamat Datang di" << endl;
    cout << "\t\tCeritanya ATM" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "\t\t  Welcome to" << endl;
    cout << "\t\tCeritanya ATM" << endl;
    cout << "=============================================" << endl;
    Sleep(2000);//baris 18-24 akan ditampilkan selama 3000 milidetik
    system("cls");//membersihkan/mengosongkan layar
}
void kartu_atm()
{
    char input_kartu_atm;
    cout << "=============================================" << endl;
    cout << "\t\b\bSilakan Masukkan Kartu ATM Anda" << endl;
    cout << " (Tekan tombol mana saja untuk melanjutkan)" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "\t Enter Your ATM Card Please" << endl;
    cout << "\t(Press any key to continue)" << endl;
    cout << "=============================================" << endl;
    cin>> input_kartu_atm;
    //Mengidentifikasi kartu
    if (input_kartu_atm != '4')
    {
        system("cls");
        cout << "ERROR: Kartu yang Anda masukkan tidak valid\nSilakan ambil kembali kartu Anda" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "ERROR: You entered an invalid card\nPlease, take back your card" << endl;
        exit(1);
    }else
    {
        Sleep(500);
        system("cls");
    }
}
void input_pilihan_bahasa()
{
    pilihBahasa://label untuk statement goto
    cout << "=============================================" << endl;
    cout << "\tSilakan pilih bahasa Anda" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "\t\b\bPlease select your language\n\n";
    cout << "1. Indonesia\n2. English\nMasukkan input(1/2):";
    cin >> pilihan_bahasa;
    if (pilihan_bahasa != 1 && pilihan_bahasa !=2)
    {
        Sleep(500);
        system("cls");
        cout << "=============================================" << endl;
        cout << "Input yang Anda masukkan tidak valid\nCoba lagi dengan memasukkan '1' atau '2'" <<endl;
        cout << "\n   Tekan tombol manapun untuk melanjutkan" <<endl;
        cout << "---------------------------------------------" << endl;
        cout << "You entered the invalid input\nTry again by entering '1' or '2'" <<endl;
        cout << "\n\tPress any key to continue" <<endl;
        cout << "=============================================" << endl;

        system("pause");//menghentikan program sampai user menekan tombol ,manapun
        system("cls");
        goto pilihBahasa;//statement goto, ketika dijalankan program langsung/balik lagi menuju ke label.
    }
}