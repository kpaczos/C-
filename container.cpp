#include<iostream>

using namespace std;
enum engine{B,D,E,H};
bool walidacjaNumer(string numer_rejestracyjny){
    if(numer_rejestracyjny.length() != 4)
        return true;    //b³êdny numer rejestracyjny
    for(int i = 0; i < 4; i++)
        if((static_cast<int>(numer_rejestracyjny[i]) >= 0 and static_cast<int>(numer_rejestracyjny[i]) <=47 )or
        (static_cast<int>(numer_rejestracyjny[i]) >= 58 and static_cast<int>(numer_rejestracyjny[i]) <= 64) or
        (static_cast<int>(numer_rejestracyjny[i]) >= 91 and static_cast<int>(numer_rejestracyjny[i]) <= 96) or
        (static_cast<int>(numer_rejestracyjny[i]) >= 123 and static_cast<int>(numer_rejestracyjny[i]) <=127))
            return true;    //b³êdny numer rejestracyjny
    return false;               //prwaid³owy numer rejestracyjny
}
class Car{
    public:
        Car(){}
        Car(string numer_rejestracyjny_, int moc_, double waga_, engine engine_type_):
        numer_rejestracyjny(numer_rejestracyjny_), moc(moc_), waga(waga_), engine_type(engine_type_)
        {
        }
        void showAll(){
            cout << "numer rejestracyjny "<<numer_rejestracyjny<<endl;
            cout << "moc "<<moc<<endl;
            cout << "waga  "<<waga<<endl;
            cout << "typ silnika "<<engine_type<<endl;
        }
        int getMoc(){
            return moc;
        }
        string getNumerRejestracyjny(){
            return numer_rejestracyjny;
        }
    private:
    string numer_rejestracyjny;
    int moc;
    double waga;
    engine engine_type;
};

class Catalog{
    public:
    static const int size_ = 7;
    Car list_[size_];
    Catalog(){counter_=0;}

    bool insert(Car toAdd){
        if(counter_ >= 7)
            return false;
        else{
            counter_++;
            int child = counter_;
            int parent = child/2;
            while(parent && list_[parent].getMoc() > toAdd.getMoc()){
                list_[child] = list_[parent];
                child = parent;
                parent = child/2;
            }
            list_[child] = toAdd;
        }

    }

    void deleteCar(Car toDelete){

    }
    int minChild(int parent){
        int left = parent << 1;
        int right = left + 1;
        if(left > counter_) return 0;
        if((right > counter_) or list_[left].getMoc() < list_[right].getMoc()){
            return left;
        }
        return right;
    }
    void removeMin(){
        Car last = list_[counter_--];
        int i = 1;
        int j = minChild(1);
        while(j and (list_[j].getMoc() < last.getMoc())){
            list_[i] = list_[j];
            i = j;
            j = minChild(j);
        }
        list_[i] = last;
    }
    void showCatalog(){
        for(int i = 1; i < 7 ; i++){
            cout << list_[1].getNumerRejestracyjny()<<" "<< list_[1].getMoc()<< " ";
            removeMin();
        }
    }
    private:
    int counter_;

};
int main()
{

    //Car bmw("1234", 100, 12.5, D);
    //Car audi;
    //audi.showAll();
    Catalog samochody;
   // samochody.list_[1].showAll();
    for(int i = 1; i < 7; i++){
        char engineChar;
        string numer_rejestracyjny_;
        int moc_;
        double waga_;
        do{
            cin >> numer_rejestracyjny_;
        }while(walidacjaNumer(numer_rejestracyjny_));
       // cout<<"done 1.";
        do{
            cin.clear();
            cin.ignore();
            cin >> moc_;
        }while(cin.fail());
        //cout<<"done 2.";
        cin.clear();
        do{
            cin.clear();
            cin.ignore();
            cin >> waga_;
        }while(cin.fail());
       // cout<<"done 3.";
        cin.clear();
        cin.ignore();
        do{
            cin>>engineChar;
        }while(engineChar != 'B' and engineChar != 'D' and engineChar != 'E' and engineChar != 'H');
        switch(engineChar){
                case 'B':{
                    Car samochod(numer_rejestracyjny_, moc_, waga_, B);
                    samochody.insert(samochod);
                    break;
                }
                case 'D':{
                    Car samochod(numer_rejestracyjny_, moc_, waga_, D);
                    samochody.insert(samochod);
                    break;
                }
                case 'E':{
                    Car samochod(numer_rejestracyjny_, moc_, waga_, E);
                    samochody.insert(samochod);
                    break;
                }
                case 'H':{
                    Car samochod(numer_rejestracyjny_, moc_, waga_, H);
                    samochody.insert(samochod);
                    break;
                }
            }
        //cout<<"done 4.";
    }
    //cout <<endl<<"***********************************"<<endl;
        //samochody.list_[i].showAll();
        samochody.showCatalog();
    return 0;
}
