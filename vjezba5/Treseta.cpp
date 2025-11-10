#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

class Karta {
private:
    string broj;
    string zog;

public:
    static const vector<string> BROJEVI;
    static const vector<string> ZOGOVI;

    Karta(string b, string z) : broj(b), zog(z) {}

    string getBroj() const { return broj; }
    string getZog() const { return zog; }

    string toString() const {
        return broj + " " + zog;
    }
};

const vector<string> Karta::BROJEVI = { "1", "2", "3", "4", "5", "6", "7", "Fante", "Konj", "Kralj" };
const vector<string> Karta::ZOGOVI = { "Bastoni", "Coppe", "Denari", "Spade" };


class Mac {
private:
    vector<Karta> karte;

    void kreirajMac() {
        karte.clear();
        for (const string& zog : Karta::ZOGOVI) {
            for (const string& broj : Karta::BROJEVI) {
                karte.push_back(Karta(broj, zog));
            }
        }
    }

public:
    Mac() {
        kreirajMac();
    }

    void promjesaj() {
        random_device rd;
        mt19937 gen(rd());
        shuffle(karte.begin(), karte.end(), gen);
    }

    vector<vector<Karta>> podijeli(int brojIgraca) {
        if (brojIgraca != 2 && brojIgraca != 4) {
            throw invalid_argument("Broj igraca mora biti 2 ili 4");
        }

        vector<vector<Karta>> podijeljeneKarte(brojIgraca);

        for (int i = 0; i < brojIgraca; i++) {
            for (int j = 0; j < 10; j++) {
                podijeljeneKarte[i].push_back(karte.back());
                karte.pop_back();
            }
        }

        return podijeljeneKarte;
    }
};


class Igrac {
private:
    string ime;
    vector<Karta> karte;
    int bodovi;

    string nazivBroja(const string& broj) const {
        if (broj == "1") return "asa";
        if (broj == "2") return "duje";
        if (broj == "3") return "trice";
        return broj;
    }

public:
    Igrac(string i) : ime(i), bodovi(0) {}

    void dodajKarte(const vector<Karta>& k) {
        karte = k;
    }

    string getIme() const { return ime; }
    int getBodovi() const { return bodovi; }

    int provjeriNapolitanu() {
        int bodovi = 0;

        for (const string& zog : Karta::ZOGOVI) {
            bool ima1 = false, ima2 = false, ima3 = false;

            for (const Karta& karta : karte) {
                if (karta.getZog() == zog) {
                    if (karta.getBroj() == "1") ima1 = true;
                    if (karta.getBroj() == "2") ima2 = true;
                    if (karta.getBroj() == "3") ima3 = true;
                }
            }

            if (ima1 && ima2 && ima3) {
                bodovi += 3;
                cout << "  → Napolitana (" << zog << "): 3 boda" << endl;
            }
        }

        return bodovi;
    }

    int provjeriTriIste() {
        int bodovi = 0;

        
        vector<string> relevantni = { "1", "2", "3" };
        for (const string& broj : relevantni) {
            int kolicina = 0;

            for (const Karta& karta : karte) {
                if (karta.getBroj() == broj) {
                    kolicina++;
                }
            }

            if (kolicina == 3) {
                bodovi += 3;
                cout << "  → Tri " << nazivBroja(broj) << ": 3 boda" << endl;
            }
            else if (kolicina == 4) {
                bodovi += 4;
                cout << "  → Cetiri " << nazivBroja(broj) << ": 4 boda" << endl;
            }
        }

        return bodovi;
    }

    int akuziraj() {
        cout << "\n" << ime << ":" << endl;
        bodovi = 0;

        bodovi += provjeriNapolitanu();
        bodovi += provjeriTriIste();

        if (bodovi == 0) {
            cout << "  → Nema akuze" << endl;
        }

        return bodovi;
    }

    void prikaziKarte() const {
        cout << "\nKarte igraca " << ime << ":" << endl;

        vector<Karta> sortirane = karte;
        sort(sortirane.begin(), sortirane.end(),
            [](const Karta& a, const Karta& b) {
                if (a.getZog() != b.getZog()) {
                    return a.getZog() < b.getZog();
                }
                auto itA = find(Karta::BROJEVI.begin(), Karta::BROJEVI.end(), a.getBroj());
                auto itB = find(Karta::BROJEVI.begin(), Karta::BROJEVI.end(), b.getBroj());
                return itA < itB;
            });

        for (const Karta& karta : sortirane) {
            cout << "  " << karta.toString() << endl;
        }
    }
};


void ispisiLiniju(int duljina = 50) {
    cout << string(duljina, '=') << endl;
}

int main() {
    ispisiLiniju();
    cout << "TRESETA - Igra akuze" << endl;
    ispisiLiniju();


    int brojIgraca;
    while (true) {
        cout << "\nUnesite broj igraca (2 ili 4): ";
        cin >> brojIgraca;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Molimo unesite broj!" << endl;
            continue;
        }

        if (brojIgraca == 2 || brojIgraca == 4) {
            break;
        }
        cout << "Broj igraca mora biti 2 ili 4!" << endl;
    }
    cin.ignore();

   
    vector<Igrac> igraci;
    for (int i = 0; i < brojIgraca; i++) {
        cout << "Unesite ime " << (i + 1) << ". igraca: ";
        string ime;
        getline(cin, ime);

        if (ime.empty()) {
            ime = "Igrac " + to_string(i + 1);
        }
        igraci.push_back(Igrac(ime));
    }

   
    Mac mac;
    mac.promjesaj();

    vector<vector<Karta>> podijeljeneKarte = mac.podijeli(brojIgraca);
    for (int i = 0; i < brojIgraca; i++) {
        igraci[i].dodajKarte(podijeljeneKarte[i]);
    }

    cout << "\n";
    ispisiLiniju();
    cout << "PODIJELJENE KARTE" << endl;
    ispisiLiniju();
    for (Igrac& igrac : igraci) {
        igrac.prikaziKarte();
    }

 
    cout << "\n";
    ispisiLiniju();
    cout << "AKUZA" << endl;
    ispisiLiniju();
    for (Igrac& igrac : igraci) {
        igrac.akuziraj();
    }

 
    cout << "\n";
    ispisiLiniju();
    cout << "REZULTATI" << endl;
    ispisiLiniju();
    for (const Igrac& igrac : igraci) {
        cout << igrac.getIme() << ": " << igrac.getBodovi() << " bodova" << endl;
    }


    int maxBodovi = 0;
    for (const Igrac& igrac : igraci) {
        if (igrac.getBodovi() > maxBodovi) {
            maxBodovi = igrac.getBodovi();
        }
    }

    vector<Igrac> pobjednici;
    for (const Igrac& igrac : igraci) {
        if (igrac.getBodovi() == maxBodovi) {
            pobjednici.push_back(igrac);
        }
    }

    if (maxBodovi > 0) {
        cout << "\n";
        ispisiLiniju();
        if (pobjednici.size() == 1) {
            cout << "POBJEDNIK: " << pobjednici[0].getIme()
                << " sa " << maxBodovi << " bodova!" << endl;
        }
        else {
            cout << "NERJESENO! Sljedeci igraci imaju " << maxBodovi << " bodova:" << endl;
            for (const Igrac& pobjednik : pobjednici) {
                cout << "  - " << pobjednik.getIme() << endl;
            }
        }
        ispisiLiniju();
    }

    return 0;
}
