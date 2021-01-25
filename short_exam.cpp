#include <iostream>

using namespace std;

////////////////////////////////////////////////////
//              KLASA FIGURA
////////////////////////////////////////////////////

class Figure{
public:
    Figure(string name_c) : name(name_c) {}
    virtual double pole() { return 0.0; }
    virtual string typ() { string typ = "DEFAULT"; return typ; }
    string getName() { return name; }
private:
    string name;
};

////////////////////////////////////////////////////
//              KLASA KWADRAT
////////////////////////////////////////////////////
class Square : public Figure{
public:
    Square(string name_c, double a_c) : Figure(name_c), a(a_c) {}
    string typ() { string typ = "kwadrat"; return typ; }
    double pole() { return a*a; };

private:
    double a;
};

////////////////////////////////////////////////////
//              KLASA TROJKAT
////////////////////////////////////////////////////
class Triangle : public Figure{
public:
    Triangle(string name_c, double a_c, double h_c) : Figure(name_c), a(a_c), h(h_c) {}
    string typ() { string typ = "trojkat"; return typ; }
    double pole() { return (a*h)/2; };
private:
    double a;
    double h;
};

////////////////////////////////////////////////////
//              KLASA POJEMNIK
////////////////////////////////////////////////////
class Box{
public:
    Box(int size_c) : size(size_c), counter(0) {}
    void display();
    void add(string typ, string name, double a, double h);
    void remove(double pole);
private:
    int size;
    Figure **wsk = new Figure*[size]{nullptr};
    int counter;
};

void Box :: display() {
    for (int i = 0; i < size; ++i) {
        if(wsk[i] != nullptr ){
            double pole = wsk[i]->pole();
            string name = wsk[i]->getName();
            string typ = wsk[i]->typ();
            cout << name << " " << typ << " " << pole << " ";
        }
    }
}

void Box :: add(string typ, string name, double a, double h) {
    for(int i=0; i<size; i++){
        if(wsk[i] == nullptr){
            if(typ == "kwadrat"){
                wsk[i] = new Square(name, a);
                counter++;
                return;
            }else if(typ == "trojkat"){
                wsk[i] = new Triangle(name, a, h);
                counter++;
                return;
            }
        }
    }
}

void Box :: remove(double pole){
    for(int i=0; i<size; i++){
        if(wsk[i] != nullptr and wsk[i]->pole() == pole){
            delete wsk[i];
            wsk[i] = nullptr;
            counter--;
        }
    }
}

////////////////////////////////////////////////////
//              MAIN
////////////////////////////////////////////////////

int main() {

    int M, N;
    double a, h, D;
    string typ, name;

    cin >> N;

    Box pudelko(N);

    cin >> M;

    for(int i=0; i<M; i++){
        cin >> typ;

        if(typ == "kwadrat"){
            cin >> name;
            cin >> a;
            h = 0;
            pudelko.add(typ, name, a, h);
        }else if(typ == "trojkat"){
            cin >> name;
            cin >> a;
            cin >> h;
            pudelko.add(typ, name, a, h);
        }

    }

    cin >> D;

    pudelko.remove(D);

    pudelko.display();

    return 0;
}