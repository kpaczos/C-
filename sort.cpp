#include <iostream>
#include <cassert>
#include <string>

using namespace std;

template <class T> class link;
template <class T> class Iterator;


template <class T>
class list {
protected:
    link <T> *First;                // data field

public:
    list() : First(nullptr) {}      // default constructor
    list(const list &source);       // copy constructor
    virtual ~list() {};                // destructor

    virtual void add(T value);      // insert a new item
    virtual void delete_all();
    T first_element() const;        // access the first item
    virtual bool includes(T value) const;  // inclusion test
    bool is_empty() const;
    virtual void remove_first();

    friend class Iterator <T>;
};

template <class T>
class link {
private:
    T Value;
    link <T> *Next;

    link(T val, link *ptr) : Value(val), Next(ptr) { }
public:
    link <T> *insert(T value);      // after current link

    friend class list <T>;
    friend class Iterator <T>;
};



template <class T> class Iterator {
public:
    Iterator(list <T> &aList);
    virtual bool init();
    virtual T operator()();
    virtual bool operator !();
    virtual bool operator++(); // for prefix, for postfix add dummy int
    virtual bool operator++(int);
    virtual void operator=(T value);
    void remove_current();
    void add_before(T new_value);
    void add_after(T new_value);
protected:
    list <T> &my_list;             // data fields
    link <T> *previous;
    link <T> *current;
};


template <class T> link <T> * link <T> :: insert(T value)
{
    Next = new link <T>(value, Next);
    return Next;
}


template <class T> void list <T> :: add(T value)
{
    First = new link <T>(value, First);
}

template <class T> T list <T> :: first_element() const
{
    assert(First != nullptr);
    return First->Value;
}


template <class T> bool list <T> :: is_empty() const
{
    return First == nullptr;
}


template <class Point> bool list <Point> :: includes(Point) const
{
    return false;
}

template <class T> void list <T> :: remove_first() {
    assert(First != nullptr);
    link <T> *ptr = First;  // save pointer to the first item
    First = ptr->Next;      // reassign the First node
    delete ptr;
}

template <class T> void list <T> :: delete_all() {
    link <T> *next;
    for (link <T> *p = First; p; p = next){
        next = p->Next;
        delete p;
    }
    First = nullptr;
}


template <class T> Iterator <T> ::
Iterator(list <T> &aList) : my_list(aList){
    init();
}
template <class T> bool Iterator <T> :: init(){
    previous = nullptr;
    current = my_list.First;
    return current != nullptr;
}
template <class T> T Iterator <T> :: operator()(){
    assert(current != nullptr);
    return current->Value;
}
template <class T> void Iterator <T> :: operator=(T val){
    assert(current != nullptr);
    current->Value = val;
}

template <class T> void Iterator <T> :: remove_current()
{
    assert(current != nullptr);
    if (previous == nullptr)
        my_list.First = current->Next;
    else
        previous->Next = current->Next;
    delete current;
    current = nullptr;
}

template <class T> bool Iterator <T> :: operator++(){
    if (current == nullptr){           // move current pointer
        if (previous == nullptr)        // to next element
            current = my_list.First;
        else
            current = previous->Next;
    }
    else {
        previous = current;
        current = current->Next;
    }
    return current != nullptr;
} // valid for prefix operator only!

template <class T> bool Iterator <T> :: operator++(int){
    return operator++();
}

template <class T> bool Iterator <T> :: operator !(){
    if (current == nullptr and previous != nullptr)
        current = previous->Next;
    return current != nullptr;       // termination of iterator
}


template <class T> void Iterator <T> :: add_before(T val)
{
    if (previous)previous = previous->insert(val);
    else {
        my_list.list<T>::add(val);     // to avoid subclass
        previous = my_list.First;
        current = previous->Next;      // if current is NULL
    }
}

template <class T> void Iterator <T> :: add_after(T val)
{
    if (current){current->insert(val); return;}  // not shown
    if (previous)current = previous->insert(val);
    else my_list.list<T>::add(val);
}


class Point{
private:
    string name_;
    double x_;
    double y_;

public:
    Point(string name, double x, double y){
        name_=name;
        x_=x;
        y_=y;}

    double sumXY(){
        return (x_+y_);
    }

    double getX(){
        return x_;
    }

    double getY(){
        return y_;
    }

    string getName(){
        return name_;
    }

    double getXY(){
        return (getX()+getY());
    }
    
    friend ostream& operator<< (ostream&,Point const&);

};

ostream& operator<< (ostream &wyjscie, Point const& ex)
{
    wyjscie <<ex.name_<<" "<<ex.x_<<" "<<ex.y_<<" ";
    return wyjscie;
}


int main() {

    list <Point> greatList;

    string name;
    double x,y;
    int rozmiar=0, rozmiar_=0;
    cin>>rozmiar;
    rozmiar_=rozmiar;


    Point **tablica = new Point *[rozmiar];
    for (int i = 0; i < rozmiar; i++) {
        cin>>name>>x>>y;
        if((x+y)!=rozmiar_){
            tablica[i] = new Point(name, x, y);
        }
        else{
            i--;
            rozmiar--;
        }
    }

    //sortowanie----------------
    for(int i=0;i<rozmiar;i++){
        for(int j=1;j<rozmiar-i;j++){
            if(tablica[j-1]->getXY()<tablica[j]->getXY()){
                swap(tablica[j-1], tablica[j]);
            }
            else{
                if(tablica[j-1]->getXY()==tablica[j]->getXY()){

                    if(tablica[j-1]->getX()<tablica[j]->getX()){
                        swap(tablica[j-1], tablica[j]);
                    }
                    else{
                        if(tablica[j-1]->getX()==tablica[j]->getX()){
                            if(tablica[j-1]->getName()<tablica[j]->getName()){
                                swap(tablica[j-1], tablica[j]);}
                        }
                    }
                }
            }
        }
    }
    //--------------------------

    for (int i = 0; i < rozmiar; i++) {
        greatList.add(*tablica[i]);
    }

    Iterator <Point> greatIterator(greatList);
    for(greatIterator.init() ; !greatIterator ; greatIterator++){
        cout<<greatIterator();
    }

    delete [] tablica;

    return 1;
}
