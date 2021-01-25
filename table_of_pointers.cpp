#include<iostream>
#include<iomanip>

using namespace std;
const double PI=3.14;

class CircleRing{
public:
    float Circuit();
    void ShowAttribiutes();
    void GetAttribiutes();
    void GetName();
    CircleRing(){};
private:
    string name_circle;
    float radius;
};
void CircleRing::GetAttribiutes(){
    cin>>name_circle;
    cin>>radius;
}
void CircleRing::GetName() {
    cout<<name_circle;
}
void CircleRing::ShowAttribiutes(){
    cout<<name_circle<<" "<<radius;
}
float CircleRing::Circuit(){
    return 2*PI*radius;
}

class Form{
public:
    virtual float CircuitF(){
    }
    virtual void ShowDataF(){
    }
    virtual void GetAttribiutesF(){
    }
    Form(){};
};

class Circle:public Form{
public:
    Circle(){};
    float BoxC();
    float CircuitF();
    void ShowDataF();
    void GetAttribiutesF();
private:
    string name_c;
    float radius_c;
};
float Circle::BoxC() {
    return 3.14*radius_c*radius_c;
}
float Circle::CircuitF() {
    return 2*3.13*radius_c;
}
void Circle::ShowDataF() {
    cout<<name_c<<" "<<radius_c;
}
void Circle::GetAttribiutesF() {
    cin>>name_c;
    cin>>radius_c;
}

class Rectangle:public Form{
public:
    Rectangle(){};
    float CircuitR();
    float BoxR();
    void ShowDataF();
    void GetAttribiutesF();
private:
    string name_r;
    float length_ar;
    float lenght_br;
};
float Rectangle::BoxR() {
    return lenght_br*length_ar;
}
float Rectangle::CircuitR() {
    return 2*length_ar+2*lenght_br;
}
void Rectangle::ShowDataF() {
cout<<name_r<<" "<<length_ar<<" "<<lenght_br;
}
void Rectangle::GetAttribiutesF() {
cin>>name_r;
cin>>length_ar;
cin>>lenght_br;
}

int main()
{
    short int task;
    cin >> task;
    switch(task)
    {
        case(1):
        {
            int  size_table;
            cin>>size_table;

            CircleRing *table_circle=new CircleRing[size_table];

            for(int i=0; i<=size_table-1; i++) {
                table_circle[i].GetAttribiutes();
            }
            for(int i=0; i<=size_table-1; i++){
                for(int j=i+1; j<=size_table-1;j++){
                    if(table_circle[i].Circuit()<table_circle[j].Circuit()){
                        swap(table_circle[i],table_circle[j]);
                    }
                }
            }
            for(int i=0; i<=size_table-1; i++) {
                table_circle[i].GetName();
                cout<<" "<<table_circle[i].Circuit()<<" ";
            }
            break;
        }
        case(2):
        {
            int number_rows, number_colums;
            cin>>number_rows;
            cin>>number_colums;
            Form ***main_table=new Form**[number_rows];

            for(int i=0; i<number_rows; i++){
                main_table[i]=new Form*[number_rows];
                for(int j=0; j<number_colums; j++) {
                    if(i%2==1) {
                        main_table[i][j]=new Rectangle();
                        main_table[i][j]->GetAttribiutesF();
                    }
                    else{
                        main_table[i][j]=new Circle();
                        main_table[i][j]->GetAttribiutesF();
                    }
                }
            }
            int show_row,show_column;
            cin>>show_row;
            cin>>show_column;
            main_table[show_row][show_column]->ShowDataF();
            break;
        }
    }
    return 1;
}
