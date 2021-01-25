#include <iostream>
#include <cmath>

using namespace std;

double factorial(double Value){
    if(Value == 0.0) return 1;
    return Value*factorial(Value-1);
}

double denominatorSum(double V, double A){
    double result = 0.0;

    for(double i=0.0; i <= V; i++){
        result += pow(A, i)/factorial(i);
    }

    return result;
}

double formula(double V, double A){
    double E = (pow(A, V)/factorial(V))/denominatorSum(V, A);
    return E;
}

int main()
{
    int choose;
    bool run = true;
    double E, A, V;

    cout << "1. V, A -> E" << endl;
    cout << "2. A, E -> V" << endl;
    cout << "3. V, E -> A" << endl;
     cout << "4.  V, A -> E, Z, R, wariancja " << endl;
    cout << "5. EXIT" << endl;

    while(run){
        cout << "> ";
        cin >> choose;

        switch(choose){
            case 1:{
                cout << "V = "; cin >> V; cout << "A = "; cin >> A;
                E=formula(V,A);
                cout << "E = " << E << endl;
                double R, Z, Q;
                R=A*E;
                Q=R*(A/(V+1-A+R)+1-R);
                Z=Q/R;
                cout<< "R = " <<R<< endl;
                cout<< "Wariancja = "<<Q <<endl;
                cout<< "Z = "<<Z<<endl;
                break;
            }
            case 2:{
                cout << "A = "; cin >> A; cout << "E = "; cin >> E;
                double tempE = 0xFFFFFFFF;
                V = 0.0;

                while(tempE>E){
                    V++;
                    tempE = formula(V, A);
                }

                double tempLowerV = formula(V-1, A);

                if( (E - tempE) > (tempLowerV - E) ){
                    cout << "V = " << V-1 << endl;
                }else{
                    cout << "V = " << V << endl;
                }

                break;
            }
            case 3:{
                cout << "V = "; cin >> V; cout << "E = "; cin >> E;
                A = 0.0;

                while(E > formula(V, A)){
                    A += 0.0001;
                }

                cout << "A = " << A << endl;
                break;
            }
            case 4:{
             cout << "V = "; cin >> V; cout << "A = "; cin >> A;
                E=formula(V,A);
                cout << "E = " << E << endl;
                double R, Z, Q;
                R=A*E;
                Q=R*(A/(V+1-A+R)+1-R);
                Z=Q/R;
                cout<< "R = " <<R<< endl;
                cout<< "Wariancja = "<<Q <<endl;
                cout<< "Z = "<<Z<<endl;
                break;


             break;
            }
            case 5:{
                run = false;
                break;
            }
            default:{
                cout << "Input error" << endl;
            }
        }
    }

    return 0;
}
