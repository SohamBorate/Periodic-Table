#include <algorithm>
#include <cctype>
#include <cstdlib> 
#include <iostream>
#include <random>
#include <string>
using namespace std;

string shortcuts[18] = {
    "Helina Ki Rab Se Faryaad",
    "Beta Mange Car Scooter Baap Raazi",
    "Scyla Act",
    "Teaser Half Rough",
    "Vaani Ne Tamasha Dab Kiya",
    "Chromowa",
    "Man Tak Re",
    "Fir Ruthe Oso",
    "Kaun Rahega Idhar",
    "Nahi Padhoge Pitoge",
    "Kyu Aaj Aur Khaaye",
    "Zindagi Cabada Hogayi",
    "Baingan Aloo Gajar In Thailiya",
    "Kahe Shivji Sune Parvati",
    "Nana Patekar Aishwarya Sab Bhikari",
    "Osse Tepo",
    "Fir Kal Bahar Aayi Aunty",
    "Heema Neema Aur Karima Zi Rani"
};

string elements[18] = {
    "H Li Na K Rb Cs Fr",
    "Be Mg Ca Sr Ba Ra",
    "Sc Y La Ac",
    "Ti Zr Hf Rf",
    "V Nb Ta Db",
    "Cr Mo W",
    "Mn Tc Re",
    "Fe Ru Os",
    "Co Rh Ir",
    "Ni Pd Pt",
    "Cu Ag Au",
    "Zn Cd Hg",
    "B Al Ga In Tl",
    "C Si Ge Sn Pb",
    "N P As Sb Bi",
    "O S Se Te Po",
    "F Cl Br I At",
    "He Ne Ar Kr Xe Rn"
};

void ask_element(int index) {
    string element = elements[index];
    cout << shortcuts[index] << "\n";

    string answer;
    getline(cin, answer);

    if (answer.compare(element) == 0) {
        cout << "\n";
        return;
    }

    cout << element << "\n\n";
}

void ask_shortcut(int index) {
    string shortcut = shortcuts[index];
    cout << elements[index] << "\n";

    string answer;
    getline(cin, answer);

    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    transform(shortcut.begin(), shortcut.end(), shortcut.begin(), ::tolower);

    if (answer.compare(shortcut) == 0) {
        cout << "\n";
        return;
    }

    cout << shortcut << "\n\n";
}

void easy(string arg) {
    if (string("elements").compare(arg) == 0) {
        for (int index = 0; index < 18; index++) {
            ask_element(index);
        }
    } else if (string("shortcuts").compare(arg) == 0) {
        for (int index = 0; index < 18; index++) {
            ask_shortcut(index);
        }
    } else {
        cout << "Usage: periodic_table (elements / shortcuts) <hard>\n";
    }
}

void hard(string arg) {
    bool done[18] = {};
    for (int i = 0; i < 18; i++) {
        done[i] = false;
    }

    // Create a random device to seed the random number generator
    std::random_device rd;

    // Use the seed to initialize the random number generator
    std::mt19937 gen(rd());

    // Create a distribution object with the defined range
    std::uniform_int_distribution<> distrib(0, 18);

    if (string("elements").compare(arg) == 0) {
        for (int i = 0; i < 18; i++) {
            int index = 0;
            do {
                index = distrib(gen);
            } while (done[index] != false);

            done[index] = true;

            ask_element(index);
        }
    } else if (string("shortcuts").compare(arg) == 0) {
        for (int i = 0; i < 18; i++) {
            int index = 0;
            do {
                index = distrib(gen);
            } while (done[index] != false);

            done[index] = true;

            ask_shortcut(index);
        }
    } else {
        cout << "Usage: periodic_table (elements / shortcuts) <hard>\n";
    }
}

int main(int argc, char **argv) {
    if (argc == 1) {
        cout << "Usage: periodic_table (elements / shortcuts) <hard>\n";
    } else if (argc == 2) {
        easy(argv[1]);
    } else if (argc == 3) {
        if (string(argv[2]).compare("hard") == 0) {
            hard(argv[1]);
        } else {
            cout << "Usage: periodic_table (elements / shortcuts) <hard>\n";
        }
    } else {
        cout << "Usage: periodic_table (elements / shortcuts) <hard>\n";
    }

    return 0;
}

