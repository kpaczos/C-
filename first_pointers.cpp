#include <iostream>
using namespace std;

class Element{
    Element *Next;
    int *Value;
public:
    Element(Element *next, int value){
        Next=next;
        Value=new int(value);
    }
    int GetVal(){
        return *Value;
    }
friend class List;
};

class List{
Element *First;
public:
    void AddEl(int val);
    void DelEl(int val);
    void ShowEl();
    List() {
        First = nullptr;
    }
};

void List::AddEl(int val) {
    First=new Element(First, val);
}
void List::DelEl(int val) {

Element *pre;
Element *tmp;
tmp=First;
pre= nullptr;

while(tmp!= nullptr){

    if(tmp->GetVal()==val) {

        if (tmp == First) {
            First = First->Next;
            delete tmp;
            tmp = First;
            pre = nullptr;
            continue;
        } else {
            pre->Next = tmp->Next;
            delete tmp;
            tmp = First;
            pre = nullptr;
            continue;
        }
    }
    pre=tmp;
    tmp=tmp->Next;
}
}
void List::ShowEl() {
    Element *tmp;
    tmp=First;

    while(tmp!= nullptr)
    {
        cout<<tmp->GetVal()<<" ";
        tmp=tmp->Next;
    }

}



int main() {


    int M,N,value;

    List list;
    cin>>M;

    for(int i=0; i<M; i++)
    {
        cin>>value;
        list.AddEl(value);
    }

    cin>>N;

    for(int i=0; i<N; i++)
    {
        cin>>value;
        list.DelEl(value);
    }
    list.ShowEl();

    return 0;
}