#ifndef DATABASE_H
    #define DATABASE_H
    #include <string>
    struct database
    {
        std::string namaNasabah;
        char idKartu;
        std::string noRekening;
        std::string pin;
        int saldo;
    };
    extern const int banyakData = 2;
    extern database dataNasabah[banyakData];
#endif