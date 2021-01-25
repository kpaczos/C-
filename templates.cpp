#include<iostream>
using namespace std;
template <class Item> class Object
{
    Item tab[6];
    int counter=0;
public:
    void AddToTab(Item);
    void DeleteFromTab(int);
    Item Copy(int i);
};
template <class Item> void Object <Item> ::AddToTab(Item a) {
    tab[counter]=a;
    counter++;
}
template <class Item> void Object <Item> ::DeleteFromTab(int b) {
for(int i=b; i<=4; i++) {
    tab[i]=tab[i+1];
    }
}
template<class Item> Item Object<Item>::Copy(int i) {
    return tab[i];
}
class Animal
{
  private:
  string name_animal;
  float weight;
  int year_of_birth;
  string label_ID;

  public:
  Animal(string na="", float w=0, int y=0, string l="");
  void ShowAnimal(Animal);
  int GetYearOfBirth() {
      return year_of_birth;
  }
  string GetNameAnimal() {
      return name_animal;
  }
  float GetWeight() {
      return weight;
  }
  string GetLabelID() {
      return label_ID;
  }
};
Animal::Animal(string na, float w, int y, string l)
{
    name_animal=na;
    weight=w;
    year_of_birth=y;
    label_ID=l;
}
void Animal::ShowAnimal(Animal a) {
    if(a.GetNameAnimal()!="" && a.GetWeight()!=0 && a.GetYearOfBirth()!=0 && a.GetLabelID()!=""){
    cout << a.GetNameAnimal() << " " << a.GetWeight() << " " << a.GetYearOfBirth() << " " << a.GetLabelID() << " ";}
}
class Building
{
  private:
  string name_bulding;
  float position_x, position_y;
  float height;

  public:
  Building(string nb="", float GPS_x=0, float GPS_y=0, float h=0);
  void ShowBuilding(Building);
  float GetSumPos() {
      return position_x+position_y;
  }
  float GetPosX() {
      return position_x;
  }
  float GetPosY() {
      return position_y;
  }
  string GetNameBuilding() {
      return name_bulding;
  }
  float GetHeight() {
      return height;
  }
};
Building::Building(string nb, float GPS_x,float GPS_y, float h)
{
    name_bulding=nb;
    position_x=GPS_x;
    position_y=GPS_y;
    height=h;
}
void Building::ShowBuilding(Building b) {
    if (b.GetNameBuilding() != "" && b.GetHeight() != 0 && b.GetSumPos() != 0) {
        cout << b.GetNameBuilding() << " " << b.GetPosX() << " " << b.GetPosY() << " " << b.GetHeight() << " "; }
}
void SortAnimal(Animal table[])
{
    for(int i=0; i<=5; i++) {
        for (int j = 0; j <= 5; j++) {
            if(table[i].GetYearOfBirth()>table[j].GetYearOfBirth()) {
                swap(table[i],table[j]);
            }
            else if(table[i].GetYearOfBirth()==table[j].GetYearOfBirth()) {
                if(table[i].GetWeight()>table[j].GetYearOfBirth()) {
                    swap(table[i],table[j]);
                }
            }
        }
    }
}
void SortBuilding(Building table[])
{
    for(int i=0; i<=5; i++) {
        for (int j = 0; j <= 5; j++) {
            if(table[i].GetSumPos()<table[j].GetSumPos()) {
                swap(table[i],table[j]);
            }
        }
    }
}

void ClearData()
{
    cin.clear();
    cin.ignore();
}



bool CheckString(string s) {
    for(int i=0; i<=s.length(); i++) {
       if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>=0 && s[i]<=9)) {
           return 0;
       }
       else {
           return 1;
       }
    }
}

int main()
{
    Object <Animal> animal_list;
    Object <Building> building_list;

    string name_a="", ID, name_b="";
    float weight_ = 0, x=0, y=0, height_=0;
    int year_=0;

    Animal *animals[4];

    for(int i=0; i<=3; i++)
    {
        while(!(cin>>name_a) || CheckString(name_b)) {
            ClearData();
        }
        while(!(cin>>weight_) || (weight_>250000) || (weight_<=0)) {
            ClearData();
        }
        while(!(cin>>year_) || (year_>2018) || (year_<1900)) {
            ClearData();
        }
        while(!(cin>>ID) || CheckString(ID)) {
            ClearData();
        }
        animals[i]=new Animal(name_a,weight_,year_,ID);
        animal_list.AddToTab(*animals[i]);
    }
    Building *buildings[4];
    for(int i=0; i<=3; i++)
    {
        while(!(cin>>name_b) || CheckString(name_b)) {
            ClearData();
        }
        while(!(cin>>x)||(x>180)||(x<(-180))) {
            ClearData();
        }
        while(!(cin>>y)||(y>90)||(y<(-90))) {
            ClearData();
        }
        while(!(cin>>height_) || height_<0 || height_>1000) {
            ClearData();
        }
        buildings[i]=new Building(name_b,x,y,height_);
        building_list.AddToTab(*buildings[i]);
    }
    int deleter;
    while(!(cin>>deleter) || deleter<0) {
        ClearData();
    }
    animal_list.DeleteFromTab(deleter);

    Animal temp_animal[6];
    Building temp_build[6];
    for(int i=0; i<=5; i++)
    {
        temp_animal[i]=animal_list.Copy(i);
        temp_build[i]=building_list.Copy(i);
    }
    SortAnimal(temp_animal);
    SortBuilding(temp_build);

    for(int i=0; i<=5; i++) {
        temp_animal[i].ShowAnimal(temp_animal[i]);
    }
    for(int i=0; i<=5; i++) {
        temp_build[i].ShowBuilding(temp_build[i]);
    }
    return 0;
}
