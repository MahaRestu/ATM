#include <iostream>
#include <windows.h> //Fungsi sleep() dan system() merupakan bagian dari header ini
#include "database.h"//Menginpor struct dan fungsi yang ada di file database.h
using namespace std;

//Deklarasi variable
int id_kartu_atm;//identitas user selama menggunakan program
string inputRekening;
int uang_transfer;


//Dklasrasi function

void kartu_atm();
char input_pilihan_bahasa();
void invalid_input_INA();
void inputPin_INA();
int menu_INA();
void tarikTunai();
void setor_tunai();
void tampilkanSaldo();
void saldoTidakCukup();
int cariIndeksDariRekening();
void transfer_INA();

void invalid_input_ENG();
void inputPin_ENG();
int menu_ENG();
void withdraw();
void cashDeposit();
void transfer_ENG();
void displayBalance();
void insufficientBalance();

//Program Utama
int main()
{
    cout << "=============================================" << endl;
    cout << "\t\t\b\bSelamat Datang di" << endl;
    cout << "\t\tCeritanya ATM" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "\t\t  Welcome to" << endl;
    cout << "\t\tCeritanya ATM" << endl;
    cout << "=============================================" << endl;
    Sleep(2000);//7 baris terakhir akan ditampilkan selama 3000 milidetik
    system("cls");//membersihkan/mengosongkan layar

    kartu_atm();
    char pilihan_bahasa = input_pilihan_bahasa();
    if (pilihan_bahasa == '1')
    {
        //Lanjutkan program dengan bahasa Indonesia
        inputPin_INA();
        pilih_menu: //label goto statement
        char pilihanMenu = menu_INA();
        if (pilihanMenu == '1')
        {
            tarikTunai();
        }else if (pilihanMenu == '2')
        {
            setor_tunai();
        }else if (pilihanMenu == '3')
        {
            transfer_INA();
        }else if (pilihanMenu == '4')
        {
            //dikosongkan supaya langsung menuju tampilkanSaldo()
        }else
        {
            invalid_input_INA();
            goto pilih_menu; // goto statement, ketika dieksekusi program kembali ke label.
        }
        tampilkanSaldo();
        system("cls");
        lanjutkanMenu:
        char lanjutkanTransaksiInput;
        cout << "=============================================" << endl;
        cout << "Apakah Anda ingin melanjutkan transaksi?" << endl;
        cout << "1. Ya\n2. Tidak\nMasukkan pilihan Anda(1/2)?"; cin >> lanjutkanTransaksiInput;
        if (lanjutkanTransaksiInput == '1')
        {
            system("cls");
            goto pilih_menu;
        }else if (lanjutkanTransaksiInput == '2')
        {
            system("cls");
            cout << "=============================================" << endl;
            cout << "\n\tTerimaksih telah bertransaksi\n" << endl;
            cout << "=============================================" << endl;
            Sleep(3000);
            system("cls");
            exit(0); //menghentikan program
        }else
        {
            invalid_input_INA();
            goto lanjutkanMenu;
        }

    }else
    {
        //Lanjutkan program dengan bahasa Inggris
        inputPin_ENG();
        select_menu:
        char selectedMenu = menu_ENG();
        if (selectedMenu == '1')
        {
            withdraw();
        }else if (selectedMenu == '2')
        {
            cashDeposit();
        }else if (selectedMenu == '3')
        {
            transfer_ENG();
        }else if (selectedMenu == '4')
        {
        }else
        {
            invalid_input_ENG();
            goto select_menu;
        }
        displayBalance();
        system("cls");
        continueTransaction:
        char continueTransactionInput;
        cout << "=============================================" << endl;
        cout << "Do you want to transact again?" << endl;
        cout << "1. Yes\n2. No\nInput your choice(1/2)?"; cin >> continueTransactionInput;
        if (continueTransactionInput == '1')
        {
            system("cls");
            goto select_menu;
        }else if (continueTransactionInput == '2')
        {
            system("cls");
            cout << "=============================================" << endl;
            cout << "\n\tThanks for your transaction\n" << endl;
            cout << "=============================================" << endl;
            Sleep(3000);
            system("cls");
            exit(0);
        }else
        {
            invalid_input_INA();
            goto continueTransaction;
        }

    }
    
    return 0;
}

/*
Isi dari fungsi-fungsi
*/

//Menampilkan pesan input yang salah. Bahasa Indonesia
void invalid_input_INA()
{
    system("cls");
    cout << "=============================================" << endl;
    cout << "\t\b\bInput tidak valid. Silakan coba lagi" << endl;
    cout << "=============================================" << endl;
    system("pause"); //menghentikan program sampai user menekan tombol manapun
}
//Menampilkan pesan invalid input. Bahasa Inggris
void invalid_input_ENG()
{
    system("cls");
    cout << "=============================================" << endl;
    cout << "\t\b\bInvalid input. Please try again" << endl;
    cout << "=============================================" << endl;
    system("pause");
}
//Mencari indeks array database berdasarkan nomer rekening
int cariIndeksDariRekening()
{
    for (int i = 0; i < banyakData; i++)
    {
        if (dataNasabah[i].noRekening == inputRekening)
        {
            return i;
        }
    }
    return -1;
}
//Program transfer. Bahasa Indonesia
void transfer_INA()
{
    system("cls");
    menuTransfer:
    cout << "=============================================" << endl;
    cout << "\t\t\t\b\b\bTransfer"<< endl;
    cout << "Masukkan saldo: Rp "; cin >> uang_transfer;
    if (dataNasabah[id_kartu_atm].saldo < uang_transfer)
    {
        saldoTidakCukup();
        goto menuTransfer;
    }
    system("cls");
    cout << "=============================================" << endl;
    cout << "Masukkan nomer rekening yang Anda tuju: "; cin >> inputRekening;
    system("cls");
    int indeksTujuan = cariIndeksDariRekening();
    if (indeksTujuan == -1)
    {
        cout << "=============================================" << endl;
        cout << "Nomer rekening tidak ditemukan\nSilakan coba lagi" << endl;
        cout << "=============================================" << endl;
        system("pause");
        goto menuTransfer;
    }else
    {
        dataNasabah[id_kartu_atm].saldo -= uang_transfer;
        dataNasabah[indeksTujuan].saldo += uang_transfer;
        cout << "=============================================" << endl;
        cout << "\n\t\t\b\bTransaksi Berhasil!\n" << endl;
        cout << "=============================================" << endl;
        Sleep(3000);
    }
}
//Program transfer. Bahasa Inggris
void transfer_ENG()
{
     system("cls");
    menuTransfer:
    cout << "=============================================" << endl;
    cout << "\t\t\t\b\b\bTransfer"<< endl;
    cout << "Input balance: Rp "; cin >> uang_transfer;
    if (dataNasabah[id_kartu_atm].saldo < uang_transfer)
    {
        insufficientBalance();
        goto menuTransfer;
    }
    system("cls");
    cout << "=============================================" << endl;
    cout << "Input the account nummber you are\nreffering to: "; cin >> inputRekening;
    system("cls");
    int indeksTujuan = cariIndeksDariRekening();
    if (indeksTujuan == -1)
    {
        cout << "=============================================" << endl;
        cout << "Account number not found\nPlease try again" << endl;
        cout << "=============================================" << endl;
        system("pause");
        goto menuTransfer;
    }else
    {
        dataNasabah[id_kartu_atm].saldo -= uang_transfer;
        dataNasabah[indeksTujuan].saldo += uang_transfer;
        cout << "=============================================" << endl;
        cout << "\n\t\t\b\bTransaction succeed!\n" << endl;
        cout << "=============================================" << endl;
        Sleep(3000);
    }
}
//Meminta user memasukkan sebuah angka (kartu ATM) yang digunakan sebagai identitas user
void kartu_atm()
{
    cout << "=============================================" << endl;
    cout << "\t\b\bSilakan Masukkan Kartu ATM Anda" << endl;
    cout << "   (Masukkan satu digit nomer sebagai ID)" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "\t Enter Your ATM Card Please" << endl;
    cout << "\t(Enter one digit number as ID)" << endl;
    cout << "=============================================" << endl;
    cin>> id_kartu_atm;
    //Mengidentifikasi kartu
    if (id_kartu_atm == dataNasabah[0].idKartu | id_kartu_atm == dataNasabah[1].idKartu)
    {
        Sleep(500);
        system("cls");
    }else
    {
        system("cls");
        cout << "ERROR: Kartu yang Anda masukkan tidak valid\nSilakan ambil kembali kartu Anda" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "ERROR: You entered an invalid card\nPlease, take back your card" << endl;
        exit(0);
    }
}
//Meminta user untuk memilih bahasa
char input_pilihan_bahasa()
{
    char pilihan_bahasa;
    pilihBahasa:
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

        system("pause");
        system("cls");
        goto pilihBahasa;
    }
    return pilihan_bahasa;
    
}
//Meminta user memasukkan pin. Bahasa Indonesia
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
        if (input_pin == dataNasabah[id_kartu_atm].pin)//mengambil pin dari dataNasabah sesuai dengan id_kartu_atm
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
    } while (input_pin != dataNasabah[id_kartu_atm].pin && hitungPinSalah < 3);
    
}
//Meminta user memasukkan pin. Bahasa Indonesia
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
        if (input_pin == dataNasabah[id_kartu_atm].pin)
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
    } while (input_pin != dataNasabah[id_kartu_atm].pin && incorrectPinCount < 3);
}
//Menampilkan menu utama ATM, meminta input pilihan menu. Bahasa Indonesia
int menu_INA()
{
    char pilihanMenu;
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
//Menampilkan menu utama ATM, meminta input pilihan menu. Bahasa Inggris
int menu_ENG()
{
    char selectedMenu;
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
//Program Tarik Tunai. Bahasa Indonesia
void tarikTunai()
{
    char pilihNominal;
    int nominalLain;
    menuTarikTunai:
    system("cls");
    cout << "=============================================" << endl;
    cout << "\t\tTarik Tunai\n" << endl;
    cout << "1. Rp 100.000\t3. Rp 1.000.000" << endl;
    cout << "2. Rp 500.000\t4. Nominal lainnya" << endl;
    cout << "Masukkan nominal transaksi Anda (1/2/3/4):"; cin >> pilihNominal;
    if (pilihNominal == '1')
    {
        if (dataNasabah[id_kartu_atm].saldo < 100000)
        {
            saldoTidakCukup();
            goto menuTarikTunai;
        }else
        {
            system("cls");
            (dataNasabah[id_kartu_atm].saldo -= 100000);
            cout << "=============================================" << endl;
            cout << "\t\b\bSelamat! Transaksi Anda berhasil" << endl;
            cout << "Silakan ambil uang Anda" << endl;
            cout << "=============================================" << endl;
        }
    }else if (pilihNominal == '2')
    {
        if (dataNasabah[id_kartu_atm].saldo < 500000)
        {
            saldoTidakCukup();
            goto menuTarikTunai;
        }else
        {
            system("cls");
            (dataNasabah[id_kartu_atm].saldo -= 500000);
            cout << "=============================================" << endl;
            cout << "\t\b\bSelamat! Transaksi Anda berhasil" << endl;
            cout << "Silakan ambil uang Anda" << endl;
            cout << "=============================================" << endl;
        }
    }else if (pilihNominal == '3')
    {
        if (dataNasabah[id_kartu_atm].saldo < 1000000)
        {
            saldoTidakCukup();
            goto menuTarikTunai;
        }else
        {
            system("cls");
            (dataNasabah[id_kartu_atm].saldo -= 1000000);
            cout << "=============================================" << endl;
            cout << "\t\b\bSelamat! Transaksi Anda berhasil" << endl;
   
            cout << "Silakan ambil uang Anda" << endl;
            cout << "=============================================" << endl;
        }
    }else if (pilihNominal == '4')
    {
        system("cls");
        cout << "=============================================" << endl;
        cout << "Silakan masukkan nominal: Rp "; cin >> nominalLain;
        if (dataNasabah[id_kartu_atm].saldo < nominalLain)
        {
            saldoTidakCukup();
            goto menuTarikTunai;
        }else
        {
            system("cls");
            (dataNasabah[id_kartu_atm].saldo -= nominalLain);
            cout << "=============================================" << endl;
            cout << "\t\b\bSelamat! Transaksi Anda berhasil" << endl;
            cout << "Silakan ambil uang Anda" << endl;
            cout << "=============================================" << endl;
        }
    }else
    {
        invalid_input_INA();
        goto menuTarikTunai;
    }
}
//Program Tarik Tunai. Bahasa Inggris
void withdraw()
{
    char pilihNominal;
    int nominalLain;
    withdrawMenu:
    system("cls");
    cout << "=============================================" << endl;
    cout << "\t\t\t\b\bwithdraw\n" << endl;
    cout << "1. Rp 100.000\t3. Rp 1.000.000" << endl;
    cout << "2. Rp 500.000\t4. Other nominal" << endl;
    cout << "Enter the amount of your transaction (1/2/3/4):"; cin >> pilihNominal;
    if (pilihNominal == '1')
    {
        if (dataNasabah[id_kartu_atm].saldo < 100000)
        {
            insufficientBalance();
            goto withdrawMenu;
        }else
        {
            system("cls");
            (dataNasabah[id_kartu_atm].saldo -= 100000);
            cout << "=============================================" << endl;
            cout << "Conratulations! Your transaction\nis success" << endl;
            cout << "Please take your money" << endl;
            cout << "=============================================" << endl;
        }
    }else if (pilihNominal == '2')
    {
        if (dataNasabah[id_kartu_atm].saldo < 500000)
        {
            insufficientBalance();
            goto withdrawMenu;
        }else
        {
            system("cls");
            (dataNasabah[id_kartu_atm].saldo -= 500000);
            cout << "=============================================" << endl;
            cout << "Conratulations! Your transaction\nis success" << endl;
            cout << "Please take your money" << endl;
            cout << "=============================================" << endl;
        }
    }else if (pilihNominal == '3')
    {
        if (dataNasabah[id_kartu_atm].saldo < 1000000)
        {
            insufficientBalance();
            goto withdrawMenu;
        }else
        {
            system("cls");
            (dataNasabah[id_kartu_atm].saldo -= 1000000);
            cout << "=============================================" << endl;
            cout << "Conratulations! Your transaction\nis success" << endl;
            cout << "Please take your money" << endl;
            cout << "=============================================" << endl;
        }
    }else if (pilihNominal == '4')
    {
        system("cls");
        cout << "=============================================" << endl;
        cout << "Enter nominal: Rp "; cin >> nominalLain;
        if (dataNasabah[id_kartu_atm].saldo < nominalLain)
        {
            insufficientBalance();
            goto withdrawMenu;
        }else
        {
            system("cls");
            (dataNasabah[id_kartu_atm].saldo -= nominalLain);
            cout << "=============================================" << endl;
            cout << "Conratulations! Your transaction\nis success" << endl;
            cout << "Please take your money" << endl;
            cout << "=============================================" << endl;
        }
    }else
    {
        invalid_input_ENG();
        goto withdrawMenu;
    }
}
//Program setor tunai. Bahasa Indonesia
void setor_tunai()
{
    system("cls");
    char pilihRekening;
    menuSetorTunai:
    cout << "=============================================" << endl;
    cout << "\t\tSetor Tunai" << endl;
    cout << "Silakan masukkan uang Anda: "; cin >> uang_transfer;
    system("cls");
    cout << "=============================================" << endl;
    cout << "Uang yang Anda masukkan sebesar: Rp " << uang_transfer;
    cout << "\n=============================================" << endl;
    system("pause");
    menuInputRekening:
    system("cls");
    cout << "=============================================" << endl;
    cout << "Setoran ke:\n1. Rekening saya\n2. Rekening lain" << endl;
    cout << "Masukkan pilihan Anda (1/2): "; cin >> pilihRekening;
    if (pilihRekening == '1')
    {
        system("cls");
        dataNasabah[id_kartu_atm].saldo += uang_transfer;
    }else if (pilihRekening == '2')
    {
        system("cls");
        cout << "=============================================" << endl;
        cout << "Masukkan nomer rekening yang Anda tuju: "; cin >> inputRekening;
        system("cls");
        int indeksTujuan = cariIndeksDariRekening();
        if (indeksTujuan == -1)
        {
            cout << "=============================================" << endl;
            cout << "Nomer rekening tidak ditemukan\nSilakan coba lagi" << endl;
            cout << "=============================================" << endl;
            system("pause");
         goto menuInputRekening;
        }else
        {
            dataNasabah[indeksTujuan].saldo += uang_transfer;
            cout << "=============================================" << endl;
            cout << "\n\t\t\b\bTransaksi Berhasil!\n" << endl;
            cout << "=============================================" << endl;
            Sleep(3000);
        }
    }else
    {
        invalid_input_INA();
        goto menuSetorTunai;
    }
}
//Program setor tunai. Bahasa Inggris
void cashDeposit()
{
    system("cls");
    char pilihRekening;
    menuCashDeposit:
    cout << "=============================================" << endl;
    cout << "\t\t\t\b\bCash Deposit" << endl;
    cout << "Please put your money: "; cin >> uang_transfer;
    system("cls");
    cout << "=============================================" << endl;
    cout << "Your money amount: Rp " << uang_transfer;
    cout << "\n=============================================" << endl;
    system("pause");
    menuInputAccount:
    system("cls");
    cout << "=============================================" << endl;
    cout << "Doposit to:\n1. My account\n2. Other account" << endl;
    cout << "Input your choice (1/2): "; cin >> pilihRekening;
    if (pilihRekening == '1')
    {
        system("cls");
        dataNasabah[id_kartu_atm].saldo += uang_transfer;
    }else if (pilihRekening == '2')
    {
        system("cls");
        cout << "=============================================" << endl;
        cout << "Input the account number you are\nreffering to: "; cin >> inputRekening;
        system("cls");
        int indeksTujuan = cariIndeksDariRekening();
        if (indeksTujuan == -1)
        {
            cout << "=============================================" << endl;
            cout << "Account number not found\nPlease try again" << endl;
            cout << "=============================================" << endl;
            system("pause");
         goto menuInputAccount;
        }else
        {
            dataNasabah[indeksTujuan].saldo += uang_transfer;
            cout << "=============================================" << endl;
            cout << "\t\tTransaction succeed!" << endl;
            cout << "=============================================" << endl;
            Sleep(3000);
        }
    }else
    {
        invalid_input_INA();
        goto menuCashDeposit;
    }
}
//Menampilkan pesan bahwa saldo tidak cukup. Bahasa Indonesia
void saldoTidakCukup()
{
    system("cls");
            cout << "=============================================" << endl;
            cout << "Saldo Anda tidak cukup untuk melanjutkan\ntransaksi" << endl;
            cout << "Saldo Anda: Rp " << dataNasabah[id_kartu_atm].saldo << endl;
            cout << "=============================================" << endl;
            system("pause");
}
//Menampilkan pesan bahwa saldo tidak cukup. Bahasa Inggris
void insufficientBalance()
{
    system("cls");
    cout << "=============================================" << endl;
    cout << "Your balance is insufficient to complete\nthe transaction" << endl;
    cout << "Your balance: Rp " << dataNasabah[id_kartu_atm].saldo << endl;
    cout << "=============================================" << endl;
    system("pause");
}
//Menampilkan saldo terkini. Bahasa Indonesia
void tampilkanSaldo()
{
    system("cls");
    cout << "=============================================" << endl;
    cout << "Sisa saldo Anda sebesar: Rp " << dataNasabah[id_kartu_atm].saldo <<endl;
    cout << "=============================================" << endl;
    system("pause");
}
//Menampilkan saldo terkini. Bahasa Inggris
void displayBalance()
{
    system("cls");
    cout << "=============================================" << endl;
    cout << "Your balance: Rp " << dataNasabah[id_kartu_atm].saldo <<endl;
    cout << "=============================================" << endl;
    system("pause");
}