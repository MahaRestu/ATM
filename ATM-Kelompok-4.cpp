#include <iostream>
#include <windows.h> //Fungsi sleep() dan system() merupakan bagian dari library ini
using namespace std;

//Inisiasi variable-variable
string pin = "241063";
int saldo = 1170000;//1.170.000

//inisiasi function
void tampilan_awal();
void kartu_atm();
char input_pilihan_bahasa();
void inputPin_INA();
int menu_INA();
void inputPin_ENG();
int menu_ENG();

//Program Utama
int main()
{
    tampilan_awal();
    kartu_atm();
    char pilihan_bahasa = input_pilihan_bahasa();
    if (pilihan_bahasa == '1')
    {
        inputPin_INA();
        menu_INA();
    }else
    {
        inputPin_ENG();
        menu_ENG();
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
char input_pilihan_bahasa()
{
    char pilihan_bahasa;
    pilihBahasa://label untuk statement goto
    cout << "=============================================" << endl;
    cout << "\tSilakan pilih bahasa Anda" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "\t\b\bPlease select your language\n\n";
    cout << "1. Indonesia\n2. English\nMasukkan input(1/2):";
    cin >> pilihan_bahasa;
    if (pilihan_bahasa != '1' && pilihan_bahasa !='2')
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
    return pilihan_bahasa;
    
}
void inputPin_INA()
{
    string input_pin;
    int hitungPinSalah = 0;
    do
    {
        system("cls");
        cout << "=============================================" << endl;
        cout << "\t\t\b\bMasukkan Pin Anda: " <<endl;
        cout << "\t\t\t\b\b"; cin >> input_pin;
        cout << "=============================================" << endl;
        if (input_pin == pin)
        {
            system("cls");
        }else
        {
            system("cls");
            cout << "=============================================" << endl;
            cout << "\tPin yang Anda masukkan salah" << endl;
            cout << "\nSilakan masukkan kembali pin Anda" << endl;
            cout << "Peringatan! Anda akan diblokir jika memasukkan\npin yang salah sebanyak 3 kali" << endl;
            cout << "=============================================" << endl;
            hitungPinSalah++;
            system("pause");
            if (hitungPinSalah > 2)
            {
                system("cls");
                cout << "=============================================" << endl;
                cout << "Demi alasan keamanan Anda tidak dapat \nbertransaksi untuk sementara waktu." << endl;
                cout << "\n\nSilakan ambil kembali kartu Anda" << endl;
                cout << "=============================================" << endl;
                system("pause");
                exit(0);
            }
            
        }
    } while (input_pin != pin && hitungPinSalah < 3);
    
}
void inputPin_ENG()
{
    string input_pin;
    int incorrectPinCount = 0;
    do
    {
        system("cls");
        cout << "=============================================" << endl;
        cout << "\t\tEnter your Pin: " <<endl;
        cout << "\t\t\t\b\b"; cin >> input_pin;
        cout << "=============================================" << endl;
        if (input_pin == pin)
        {
            system("cls");
        }else
        {
            system("cls");
            cout << "=============================================" << endl;
            cout << "\tYou entered an incorrect pin" << endl;
            cout << "\nPlease enter your pin again" << endl;
            cout << "Warning! You will be blocked if you enter the\nincorrect pin 3 times" << endl;
            cout << "=============================================" << endl;
            incorrectPinCount++;
            system("pause");
            if (incorrectPinCount > 2)
            {
                system("cls");
                cout << "=============================================" << endl;
                cout << "For security reason you will be temporarily\nunable to transact" << endl;
                cout << "\n\nPlease take back your card" << endl;
                cout << "=============================================" << endl;
                system("pause");
                exit(0);
            }
            
        }
    } while (input_pin != pin && incorrectPinCount < 3);
}
int menu_INA()
{
    int pilihanMenu;
    cout << "=============================================" << endl;
    cout << "\t\tMenu Utama" << endl;
    cout << " Silakan pilih transaksi yang Anda inginkan" << endl;
    cout << "\n1. Tarik Tunai\t\t3. Transfer" << endl;
    cout << "2. Setor Tunai\t\t4. Info Saldo" <<endl;
    cout << "Masukkan pilihan transaksi Anda (1/2/3/4): "; cin >> pilihanMenu;
    cout << "=============================================" << endl;
    system("cls");
    return pilihanMenu;
}
int menu_ENG()
{
    int selectedMenu;
    cout << "=============================================" << endl;
    cout << "\t\t  Main Menu" << endl;
    cout << " Choose your prefered transaction" << endl;
    cout << "\n1. Withdraw\t\t3. Transfer" << endl;
    cout << "2. Cash Deposit\t\t4. Balance Info" <<endl;
    cout << "enter your selected transaction(1/2/3/4): "; cin >> selectedMenu;
    cout << "=============================================" << endl;
    system("cls");
    return selectedMenu;
}