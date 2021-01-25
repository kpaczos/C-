#include <iostream>
#include <cassert>
#include <string>

using namespace std;

template <class T> class link;

// ======================================================================
//                    Class Template list
// ======================================================================
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
};
// ======================================================================
//                    Class Template link
// ======================================================================
template <class T>
class link {
private:
    T Value;
    link <T> *Next;

    link(T val, link *ptr) : Value(val), Next(ptr) { }
public:
    link <T> *insert(T value);      // after current link

    friend class list <T>;
};

// ======================================================================
//                    Class Template double_ended list
// ======================================================================

template <class T>
class double_ended : public list<T> {
public:
    double_ended() : Last(nullptr) {}
    virtual void add(T value);      //override 3 functions
    virtual void delete_all();
    virtual void remove_first();
    void add_to_end(T value);     // new function
    friend ostream& operator<< (ostream&,double_ended const&);
protected:
    link <T> * Last;
};

// ======================================================================
//                    Class Template link - attributes
// ======================================================================
template <class T> link <T> * link <T> ::insert(T value)
{
    Next = new link <T>(value, Next);
    return Next;
}

// ======================================================================
//                    Class Template list - attributes
// ======================================================================
template <class T> void list <T> ::add(T value)
{
    First = new link <T>(value, First);
}

template <class T> T list <T> ::first_element() const
{
    assert(First != nullptr);
    return First->Value;
}


template <class T> bool list <T> ::is_empty() const
{
    return First == nullptr;
}


template <class T> bool list <T> ::includes(T value) const
{
    for (link <T> *p = First; p; p = p->Next)
        if (value == p->Value)return true;
    return false;
}

template <class T> void list <T> ::remove_first() {
    assert(First != nullptr);
    link <T> *ptr = First;  // save pointer to the first item
    First = ptr->Next;      // reassign the First node
    delete ptr;
}

template <class T> void list <T> ::delete_all() {
    link <T> *next;
    for (link <T> *p = First; p; p = next) {
        next = p->Next;
        delete p;
    }
    First = nullptr;
}

// ======================================================================
//                    Class Template double_ended list - attributes
// ======================================================================

template <class T> void double_ended <T> ::add(T value) {
    if (list<T>::is_empty()) {
        list <T> ::add(value);
        Last = this->First; // handling empty list
    }
    else list <T> ::add(value);
}

template <class T>
void double_ended <T> ::add_to_end(T value) {
    if (Last != nullptr)
        Last = Last->insert(value);
    else
        add(value);
}

template <class T> void double_ended <T> ::delete_all() {
    list <T> ::delete_all();
    Last = nullptr;
}

template <class T> void double_ended <T> ::remove_first() {
    list <T> ::remove_first();
    if (list<T>::is_empty()) Last = nullptr;
}
ostream& operator<< (ostream &wyjscie, double_ended const&x)
{
    wyjscie<<x.first_element(); ;
    return wyjscie;
}
// ======================================================================
//                            main
// ======================================================================

int main() {
    cout << "Hello World!" << endl;

    double_ended<int> myListFirst;
    double_ended<int> myListSecond;

    int K;
    cin>>K;   //ile elementow

    for(int i=0; i<K; i++){
        int element;
        cin>>element;
        myListFirst.add_to_end(element);
    }

    int L;
    cin>>L;
    for(int i=0; i<L; i++){
        myListFirst.remove_first();
    }

    int M;
    cin>>M;   //ile elementow

    for(int i=0; i<M; i++){
        int element;
        cin>>element;
        myListSecond.add_to_end(element);
    }
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        myListFirst.remove_first();
    }

    //"=============== Print list in FIFO order ===============" << endl;

   while(!myListSecond.is_empty())
    {
        cout << myListSecond.first_element() << endl;
        myListSecond.remove_first();
    }
    while(!myListFirst.is_empty())
    {
        cout << myListFirst.first_element() << endl;
        myListFirst.remove_first();
    }



    return 0;
}
// ======================================================================