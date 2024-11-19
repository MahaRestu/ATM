#ifndef DATABASE_H//jika DATABASE_H belum didefinisikan, eksekusi selanjutnya sampai #endif
    #define DATABASE_H //mendeklarasikan DATABASE_H
    #include <string>
    struct database
    {
        std::string namaNasabah;
        int idKartu;
        std::string noRekening;
        std::string pin;
        int saldo;
    };
    extern const int banyakData = 2; //extern adalah sintaks untuk mendeklarasikan variable di luar file program utama
    extern database dataNasabah[banyakData];
#endif //Akhir baris yang dieksekusi #ifndef