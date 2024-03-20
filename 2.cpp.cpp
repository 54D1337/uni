#include<iostream>
#include <ctime>

using namespace std;


int yes_or_no(){
    string valasz;
    while (true)
    {
        cin >> valasz;
        switch (valasz[0])
            {
            case 'Y':
            case 'y':
                return true;
            case 'N':
            case 'n':
                return false;
            default:
                cout << "Rossz bemenet probald ujra" << endl;
            }
    }
    return false;
}

struct Kartyak{
    bool visible = false;
    int value = 0;
};

int Points = 0;

void kimenet(Kartyak C[10]){
    if (system("CLS")) system("clear");
    for(int i=0;i<10; i++){
        if (C[i].visible){printf("%2d| %d \n",i+1,C[i].value);}
        else{printf("%2d| %p\n",i+1,&C[i].value);}
    }
}

void jatek(Kartyak C[10]){
    int max = 5;
    int a,b;
    while(1){

        kimenet(C);

        cout << endl;
        cout << "Valassz ketto kartyat!" << endl;
        cout << "Elso kartya: ";
        cin >> a;
        if( a < 0 or a > 10 or C[a-1].visible){
            while(1){
                    kimenet(C);
                    if(!(0 < a && a < 10)){
                        cout << endl << "Hataron kivuli szam" << endl;
                    }
                    else if((C[a-1].visible)){
                        cout << endl << "A kartya mar lathato" << endl;
                    }
                    else{
                        break;
                    }
                    cout << "Elso kartya: ";
                    cin >> a;
            }
        }
        C[a-1].visible = true;
        kimenet(C);

        cout << endl << "Masodik kartya: ";
        cin >> b;
        if(b < 0 or b > 10 or C[b-1].visible){
             while(1){
                    kimenet(C);
                    if(!(0 < b && b < 10)){
                        cout << endl << "Hataron kivuli szam" << endl;
                    }
                    else if((C[b-1].visible)){
                        cout << endl << "A kartya mar lathato" << endl;
                    }
                    else{
                        break;
                    }
                    cout << "2nd Kartyak: ";
                    cin >> b;
            }
        }
        C[b-1].visible = true;
        kimenet(C);

        cout << endl << "A valasztott kartyak " << a << " és "<< b << "." << endl;

        if(C[int(a)-1].value !=  C[int(b)-1].value){
            C[int(a)-1].visible = false;
            C[int(b)-1].visible = false;
        }
        else if(Points < max-1) {Points++; cout << endl << "Van egy parod!" << endl;}
        else{
            cout << "Megnyerted a jatekot!" << endl;
            cin.ignore();
            cout << "Kilepeshez nyomj entert!" << endl;
            cin.get();
            return;
        }
        cin.ignore();
        cout << "Nyomj entert a folytatashoz!" << endl;
        cin.get();

    }



}

int main()
{

    srand(time(NULL));
    Kartyak Kartyaks[10];
    for (int i = 0; i < 10; i++){
        if(Kartyaks[i].value != 0){continue;}

        while (1){
            int index = rand() % 10;

            if(Kartyaks[index].value != 0 || index == i){continue;}
            int r = rand() % 200 + 1;
            Kartyaks[index].value = r;
            Kartyaks[i].value = r;
            break;
            }
        }

    jatek(Kartyaks);
    return 0;
}


