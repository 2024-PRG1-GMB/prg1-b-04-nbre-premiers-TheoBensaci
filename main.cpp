/**
 *   HEIG-VD
 *   De: Theo Bensaci
 *   Date: 10:41 03.10.2024
 *   Description: Calculateur de nombre premier
 */


#include <iostream>
#include <limits>
using namespace std;

int main(){
    const int c_min = 2;        // valeur min
    const int c_max = 1000;     // valeur max

    char state = 1;          // 0 = exit, 1 = input number,2 = restart input

    // titre 
    cout    << "-------------------------------\n"
            << "|                             |\n"
            << "| THE PRIME NUMBER CALCULATOR |\n"
            << "|                             |\n"
            << "-------------------------------\n"
            << "   Heig-vd    -   Theo Bensaci \n"
            << "______________________________\n"
            << "    affiche tous les nombres  \n" 
            << " premier entre 1 et la valeur \n"
            << "           saisie             \n"
            << "______________________________\n"
            << endl; 

    do{

        switch (state)
        {

            // state pour l'inpute des nombres / affichage des nombres
            case 1:
            {
                int inputNumber;
                cout    << "Entrer une valeur (int) ["<<c_min<<"-"<<c_max<<"] : ";
                cin     >> inputNumber;

                if(inputNumber < c_min || inputNumber > c_max){
                    bool toLow=inputNumber<c_min;

                    cout    <<          "[!] votre numbre est "
                            << (toLow?   "en dessous de ":"au dessus de ")
                            << (toLow?   c_min           :c_max         ) 
                            << " [!]\n"
                            << endl;

                    break;
                }

                cout << "\nNumber :"<< endl;

                int nNumber=0;
                for (int i = c_min; i <= inputNumber; i++)
                {

                    bool prime=true;

                    for (int j = c_min; j < i; j++)
                    {

                        // si divisable => papss prime
                        if(i!=j && i%j==0){
                            prime=false;
                            break;
                        }

                    }

                    if(prime){
                        nNumber++;
                        cout <<i<<"\t";
                        
                        // passe a ligne tous les 5 nombres
                        if(nNumber==5){
                            cout<< endl;
                            nNumber=0;
                        }
                    }
                }
                cout<< endl;
                state = 2;
        }

        case 2: 
            {
                // state pour recommencer
                char car;
                cout    << "\nvoulez vous recomencez ? [o/n] : ";
                cin     >> car;

                car = tolower(car);
                
                state = (car=='n')?0:(car=='o')?1:3;
                break;
            }
        }
    }
    while (state!=0);

    return EXIT_SUCCESS;
    
}
