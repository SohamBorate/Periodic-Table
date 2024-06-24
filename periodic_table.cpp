#include <algorithm>
#include <cctype>
#include <cstdlib> 
#include <iostream>
#include <random>
#include <string>
using namespace std;

string groups[18] = {
    "IA",
    "IIA",
    "IIIB",
    "IVB",
    "VB",
    "VIB",
    "VIIB",
    "VIII",
    "VIII",
    "VIII",
    "IB",
    "IIB",
    "IIIA",
    "IVA",
    "VA",
    "VIA",
    "VIIA",
    "VIIIA"
};

string tricks[18] = {
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

void ask_element(int index, bool group) {
    string element = elements[index];
    if (group) {
        cout << "Group " << index + 1 << " / " << groups[index] << "\n";
    } else {
        cout << tricks[index] << "\n";
    }

    cout << "Type the elements: ";

    string answer;
    getline(cin, answer);

    if (answer.compare(element) == 0) {
        cout << "Correct\n\n";
        return;
    }

    cout << "Wrong, elements are: ";
    cout << element << "\n";
    if (group) {
        cout << "Trick is: " << tricks[index] << "\n";
    }
    cout << "\n";
}

void ask_trick(int index, bool group) {
    string trick = tricks[index];
    if (group) {
        cout << "Group " << index + 1 << " / " << groups[index] << "\n";
    } else {
        cout << elements[index] << "\n";
    }

    cout << "Type the trick: ";

    string answer;
    getline(cin, answer);

    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    transform(trick.begin(), trick.end(), trick.begin(), ::tolower);

    if (answer.compare(trick) == 0) {
        cout << "Correct\n\n";
        return;
    }

    cout << "Wrong, trick is: ";
    cout << trick << "\n";
    if (group) {
        cout << "Elements are: " << elements[index] << "\n";
    }
    cout << "\n";
}

void easy(string arg, bool group) {
    if (string("elements").compare(arg) == 0) {
        for (int index = 0; index < 18; index++) {
            ask_element(index, group);
        }
    } else if (string("tricks").compare(arg) == 0) {
        for (int index = 0; index < 18; index++) {
            ask_trick(index, group);
        }
    }
}

void hard(string arg, bool group) {
    bool done[18] = {};
    for (int i = 0; i < 18; i++) {
        done[i] = false;
    }

    // Create a random device to seed the random number generator
    std::random_device rd;

    // Use the seed to initialize the random number generator
    std::mt19937 gen(rd());

    // Create a distribution object with the defined range
    std::uniform_int_distribution<> distrib(0, 17);

    if (string("elements").compare(arg) == 0) {
        for (int i = 0; i < 18; i++) {
            int index = 0;
            do {
                index = distrib(gen);
            } while (done[index] != false);

            done[index] = true;

            ask_element(index, group);
        }
    } else if (string("tricks").compare(arg) == 0) {
        for (int i = 0; i < 18; i++) {
            int index = 0;
            do {
                index = distrib(gen);
            } while (done[index] != false);

            done[index] = true;

            ask_trick(index, group);
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 3 || argc > 4) {
        cout << "Usage: periodic_table (groups / elements / tricks) (elements / tricks) <hard>\n";
        return 0;
    }

    if (string(argv[1]).compare("groups") == 0) {
        if (argc > 3) {
            if (string(argv[3]).compare("hard") == 0) {
                cout << "Practice " << argv[2] << " for each group (randomised)\n\n";
                hard(argv[2], true);
            }
        } else {
            cout << "Practice " << argv[2] << " for each group\n\n";
            easy(argv[2], true);
        }
    } else if (string(argv[1]).compare("elements") == 0 && string(argv[2]).compare("tricks") == 0) {
        if (argc > 3) {
            if (string(argv[3]).compare("hard") == 0) {
                cout << "Practice " << argv[1] << " by " << argv[2] << " (randomised)\n\n";
                hard(argv[1], false);
            }
        } else {
            cout << "Practice " << argv[1] << " by " << argv[2] << "\n\n";
            easy(argv[1], false);
        }
    } else if (string(argv[1]).compare("tricks") == 0 && string(argv[2]).compare("elements") == 0) {
        if (argc > 3) {
            if (string(argv[3]).compare("hard") == 0) {
                cout << "Practice " << argv[1] << " by " << argv[2] << " (randomised)\n\n";
                hard(argv[1], false);
            }
        } else {
            cout << "Practice " << argv[1] << " by " << argv[2] << "\n\n";
            easy(argv[1], false);
        }
    } else {
        cout << "Usage: periodic_table (groups / elements / tricks) (elements / tricks) <hard>\n";
    }

    return 0;
}

