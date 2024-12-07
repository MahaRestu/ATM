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
database dataNasabah[banyakData] =
{
   //"nama", id, "noRek", "pin", saldo
    {"Ucup", 0, "12345", "112233", 1000000},
    {"Otong", 1, "67890", "445566", 2500000}
};
