#include <iostream>
#include <cstddef>
#include <string>

struct Student {
    std::string ime;
    std::string jmbag;
    int godina_studija;
    int etcs_bodovi;
    double prosjek;
};

void filter_students(Student studenti[], std::size_t n,
    void (*akcija)(Student&),
    bool (*filter)(Student&))
{
    for (std::size_t i = 0; i < n; i++) {
        if (filter(studenti[i])) {  
            akcija(studenti[i]);    
        }
    }
}

void ispis(Student& s)
{
    std::cout << "Ime: " << s.ime
        << ", JMBAG: " << s.jmbag
        << ", Godina: " << s.godina_studija
        << ", ETCS: " << s.etcs_bodovi
        << ", Prosjek: " << s.prosjek << std::endl;
}


void povecaj_godinu(Student& s)
{
    s.godina_studija++;
    std::cout << "Student " << s.ime << " prelazi u "
        << s.godina_studija << ". godinu" << std::endl;
}

int main()
{
    
    Student studenti[] = {
        {"Ana Anić", "0036512345", 1, 30, 4.2},
        {"Marko Marković", "0036523456", 1, 0, 0.0},
        {"Ivana Ivić", "0036534567", 2, 50, 3.8},
        {"Petar Petrić", "0036545678", 1, 15, 2.5},
        {"Luka Lukić", "0036556789", 3, 60, 4.5},
        {"Maja Majić", "0036567890", 2, 45, 3.6},
        {"Nina Ninić", "0036578901", 1, 55, 4.0}
    };

    std::size_t n = sizeof(studenti) / sizeof(studenti[0]);

 
    auto prva_godina_polozio = [](Student& s) {
        return s.godina_studija == 1 && s.etcs_bodovi > 0;
        };


    auto prosjek_veci_od_3_5 = [](Student& s) {
        return s.prosjek > 3.5;
        };


    auto polozio_45_etcs = [](Student& s) {
        return s.etcs_bodovi >= 45;
        };



    std::cout << "Studenti 1. godine koji su položili barem 1 ispit " << std::endl;
    filter_students(studenti, n, ispis, prva_godina_polozio);
    std::cout << std::endl;

  
    std::cout << "Studenti s prosjekom > 3.5 " << std::endl;
    filter_students(studenti, n, ispis, prosjek_veci_od_3_5);
    std::cout << std::endl;

  
    std::cout << "Povećanje godine za studente s 45+ ETCS " << std::endl;
    filter_students(studenti, n, povecaj_godinu, polozio_45_etcs);
    std::cout << std::endl;


    return 0;
}
