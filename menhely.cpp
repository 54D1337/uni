#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Allat {
public:
    void setNev(const string& nev) {
        this->nev = nev;
    }
    void setKor(const int& kor) {
        this->kor = kor;
    }
    void setSzin(const string& szin) {
        this->szin = szin;
    }
    void setFajta(const string& fajta) {
        this->fajta = fajta;
    }

    void kiirAdatok() const {
        cout << "Nev: " << nev << ", Kor: " << kor << ", Szin: " << szin << ", Fajta: " << fajta << endl;
    }

    string nev;
    int kor;
    string szin;
    string fajta;
};

vector<Allat> allatok;

void openfile() {
    fstream myfile("allatok.txt");
    string mytext;
    
    while (getline(myfile, mytext)) {
        //stringstream ss(mytext);
        //string token;
        /*int i = 0;
        while (getline(ss, token, ',')) {
            if (i == 0) {
                x.setNev(token);
            } else if (i == 1) {
                x.setKor(stoi(token));
            } else if (i == 2) {
                x.setSzin(token);
            } else if (i == 3) {
                x.setFajta(token);
            }
            i++;
        }*/

        Allat x;
        int word = 0;
        string nev = "";
        int kor = 0;
        string szin = "";
        string fajta = "";

        for (int i = 0; i < mytext.size(); i++)
        {
            if (mytext[i] == ',')
            {
                word += 1;
                continue;
            }
            else{
                if (word == 0) {
                    nev += mytext[i];
                }
                x.setNev(nev);

                if(word == 1) {
                    kor = mytext[i]-48;
                }
                x.setKor(kor);

                if(word == 2) {
                    szin += mytext[i];
                }
                x.setSzin(szin);

                if(word == 3) {
                    fajta += mytext[i];
                }
                x.setFajta(fajta);

            }
        }
        
        allatok.push_back(x);
    }
    myfile.close();
}

void kiirAllatok(string attr, string val) {
    cout << "Az allatok adatai:" << endl;
    for (const auto& allat : allatok) {
        if (attr == "Nev" && val == allat.nev) {
            allat.kiirAdatok();
        } else if (attr == "Kor" && val == to_string(allat.kor)) {
            allat.kiirAdatok();
        } else if (attr == "Szin" && val == allat.szin) {
            allat.kiirAdatok();
        } else if (attr == "Fajta" && val == allat.fajta) {
            allat.kiirAdatok();
        }
    }
}


int main() {
    cout << "Keresés" << endl;
    cout << "Nev/Kor/Szin/Fajta:{ertek}";
    string keres;
    cin >> keres;
    string attr;
    string val;
    int word = 0;
    for (int i = 0; i < keres.size(); i++)
    {
        if (keres[i] == ':'){
            word += 1;
            continue;
        }
        else{
            if (word == 0){
                attr += keres[i];
            }
            else{
                val += keres[i];
            }
            
        }
    }
    //cout << val;
    openfile();
    kiirAllatok(attr,val);
    

    return 0;
}
