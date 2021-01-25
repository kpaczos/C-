#include<iostream>
#include <sstream>
#include <string>
using namespace std;

class Person
{
public:
    void ShowPersonalData(Person);
    float GetWeight();
    float GetHeight();
    float IndexBMI(Person);

    Person(string fn="", string ln="", float w=0, float h=0, int a=0, char s='M');

    string first_name;
    string last_name;
    float weight;
    float height;
    int age;
protected:
    char sex_;
};
Person::Person(string fn, string ln, float w, float h, int a, char s)
{
    first_name=fn;
    last_name=ln;
    weight=w;
    height=h;
    age=a;
    sex_=s;
}
void Person::ShowPersonalData(Person arg)
{
    cout<<arg.first_name<<" "<<arg.last_name<<" "<<arg.weight<<" "<<arg.height<<" "<<arg.age<<" ";
}

float Person::IndexBMI(Person arg)
{
    float arg_weight,arg_height;
    arg_weight=GetWeight();
    arg_height=GetHeight();
    return arg_weight/(arg_height*arg_height);
}
float Person::GetWeight()
{
    return weight;
}
float Person::GetHeight()
{
    return height;
}




class Student:public Person
{
public:
    float AverageGrade();
    int GetYearOfCollege();
    int DeleteYearOfCollege();
    string DeleteFirstName();
    string DeleteLastName();
    int DeleteAge();
    string DeleteIndexNumber();
    float DeleteHeight();
    float DeleteWeight();
    string GetIndexNumber();
    string GetFirstName();
    string GetLastName();
    friend istream &operator>>(istream &in, Student & arg);

    Student();
    Student(const string &fn, const string &ln, float w, float h, int a, char s, string in="", int yoc=0, double g[]=0);

private:
    string index_number;
    int  year_of_college{};
    double grades[10]{}; //powinno byc 10
};

double global;
istream &operator>>(istream& in, Student & arg)
{
    in>>arg.first_name;
    in>>arg.last_name;
    in>>arg.weight;
    in>>arg.height;
    in>>arg.age;
    in>>arg.sex_;
    in>>arg.index_number;
    in>>arg.year_of_college;
    bool flag=true;
    string temp;
    while(flag) {
        in >> arg.grades[0];
        temp=to_string(arg.grades[0]);
        if(temp[1]!='.')
        {
           global=arg.grades[0];
            break;
        }
        in >> arg.grades[1];
        temp=to_string(arg.grades[1]);
        if(temp[1]!='.')
        {
            global=arg.grades[1];
            break;
        }
        in >> arg.grades[2];
        temp=to_string(arg.grades[2]);
        if(temp[1]!='.')
        {
            global=arg.grades[2];
            break;
        }

        in >> arg.grades[3];
        temp=to_string(arg.grades[3]);
        if(temp[1]!='.')
        {
            global=arg.grades[3];
            break;
        }
        in >> arg.grades[4];
        temp=to_string(arg.grades[4]);
        if(temp[1]!='.')
        {
            global=arg.grades[4];
            break;
        }
      /* in >> arg.grades[5];
        temp=to_string(arg.grades[5]);
        if(temp[1]!='.')
        {
            global=arg.grades[5];
            break;
        }




*/
        flag=false;
    }



    return in;
}

Student::Student(const string &fn, const string &ln, float w, float h, int a, char s, string in, int yoc, double g[]) : Person(fn, ln, w, h, a, s) {


    index_number=in;
    year_of_college=yoc;
    for(int i=0; i<=9; i++) // powinno byc i<=9
    {
        grades[i]=g[i];
    }
}

int Student::GetYearOfCollege() {
    return year_of_college;
}
int Student::DeleteYearOfCollege() {
    return 0;
}


string Student::DeleteFirstName()
{
    return "";
}
string Student::DeleteLastName()
{
    return "";
}
int Student::DeleteAge()
{
    return 0;
}
string Student::DeleteIndexNumber()
{
    return "";
}
float Student::DeleteHeight()
{
    return 0;
}
float Student::DeleteWeight()
{
    return 0;
}
string Student::GetIndexNumber()
{
    return index_number;
}
string Student::GetFirstName()
{
    return first_name;
}
string Student::GetLastName()
{
    return last_name;
}
float Student::AverageGrade()
{
    float sum_value=0;
    int sum_grades=0;
    for(int i=0; i<=4; i++)
    {
        if(grades[i]!=0)
        {
            sum_grades++;
        }
        else
        {
            break;
        }
        sum_value+=grades[i];
    }
    return sum_value/sum_grades;
}

Student::Student() {

}

class Subject
{
public:
    void AddStudent(Student);
    int UptadeMaxStudent();
    void DeleteStudent();
    void SortStudents();
    void ShowThreeStudents(int);



    Subject();
    Subject(string sn, Student t[][10], int ms);

private:
    string subject_name;
    Student table[5][10];
    int max_student;
};


    Subject::Subject(string sn, Student t[][10], int ms)
{
        subject_name=sn;


        for(int j=0; j<=4; j++) {

            for (int i = 0; i <= 9; i++) {
                table[j][i] = t[j][i];
            }
        }

       max_student=ms;
}
Subject::Subject() {}






void Subject::AddStudent(Student a)
{
    int temp_year_of_college;
    temp_year_of_college=a.GetYearOfCollege();

    for(int i=0; i<=9; i++)
    {
        if (table[temp_year_of_college][i].GetYearOfCollege()!=1 && table[temp_year_of_college][i].GetYearOfCollege()!=2 && table[temp_year_of_college][i].GetYearOfCollege()!=3 && table[temp_year_of_college][i].GetYearOfCollege()!=4 && table[temp_year_of_college][i].GetYearOfCollege()!=5)
        {
            table[temp_year_of_college][i]=a;
            break;

        }


    }
}

int Subject::UptadeMaxStudent()
{
        Student temp;
    int sum_student=0;
    for(int i=0; i<=4; i++)
    {
        for(int j=0; j<=9; j++)
        {
           if(table[i][j].GetYearOfCollege()==5 || table[i][j].GetYearOfCollege()==1 || table[i][j].GetYearOfCollege()==2 || table[i][j].GetYearOfCollege()==3 || table[i][j].GetYearOfCollege()==4)
            {
                sum_student++;
            }
        }
    }
    return sum_student;
}

void Subject::DeleteStudent()
{   int year;
    string index;
    cin>>year;
    cin>>index;


        Student temp;
    temp.DeleteFirstName();
    temp.DeleteLastName();
    temp.DeleteAge();
    temp.DeleteYearOfCollege();
    temp.DeleteIndexNumber();
    temp.DeleteHeight();
    temp.DeleteWeight();


        for(int j=0; j<=9; j++)
        {
            if(table[year][j].GetIndexNumber()==index)
            {
                table[year][j]=temp;
            }
        }


}
void Subject::SortStudents()
{

        for(int i=0; i<=9; i++)
        {
            for(int j=0; j<=9; j++)
            {

                if(table[0][j].AverageGrade()<table[0][j+1].AverageGrade())
                {
                    swap(table[0][j], table[0][j+1]);
                }
                if(table[1][j].AverageGrade()<table[1][j+1].AverageGrade())
                {
                    swap(table[1][j], table[1][j+1]);
                }
                if(table[2][j].AverageGrade()<table[2][j+1].AverageGrade())
                {
                    swap(table[2][j], table[2][j+1]);
                }
                if(table[3][j].AverageGrade()<table[3][j+1].AverageGrade())
                {
                    swap(table[3][j], table[3][j+1]);
                }
                if(table[4][j].AverageGrade()<table[4][j+1].AverageGrade())
                {
                    swap(table[4][j], table[4][j+1]);
                }
            }
        }

}
void Subject::ShowThreeStudents(int year)
{
        SortStudents();
        cout<<table[year][0].GetIndexNumber()<<" "<<table[year][0].GetFirstName()<<" "<<table[year][0].GetLastName()<<" "
        <<table[year][1].GetIndexNumber()<<" "<<table[year][1].GetFirstName()<<" "<<table[year][1].GetLastName()<<" "
        <<table[year][2].GetIndexNumber()<<" "<<table[year][2].GetFirstName()<<" "<<table[year][2].GetLastName();

}

class Employee:public Person
{
public:
    void UntilRetirement();

    Employee();
    Employee(const string &fn, string ln, float w, float h, int a, char s, string bn, string p, float r, float se);
    friend istream &operator>>(istream &in, Employee & arg);

private:
    string business_name;
    string position;
    float reward{};
    float seniority{};

};

istream &operator>>(istream &in, Employee & arg);

istream &operator>>(istream& in, Employee & arg)
{

    in>>arg.first_name;
    in>>arg.last_name;
    in>>arg.weight;
    in>>arg.height;
    in>>arg.age;
    in>>arg.sex_;
    in>>arg.business_name;
    in>>arg.position;
    in>>arg.reward;
    in>>arg.seniority;
    return in;
}



Employee::Employee(const string &fn, string ln, float w, float h, int a, char s, string bn, string p, float r, float se)
        : Person(fn, ln, w, h, a, s) {
    first_name=fn;
    last_name=ln;
    weight=w;
    height=h;
    age=a;
    sex_=s;
    business_name=bn;
    position=p;
    reward=r;
    seniority=s;

}

Employee::Employee() {}
void Employee::UntilRetirement()
{
    if(sex_=='K')
    {
        cout<<60-age;
    }
    else
    {
        cout<< 65-age;
    }
}




int main()
{

    string name_of_subject;
    Subject kierunek;
    cin>>name_of_subject;
    Student a0, a1, a2, a3, a4, a5, a6, a7,a8,a9;
    cin>>a0;
    kierunek.AddStudent(a0);
    cin>>a0;
    kierunek.AddStudent(a1);
    cin>>a2;
    kierunek.AddStudent(a2);
    cin>>a3;
    kierunek.AddStudent(a3);
    cin>>a4;
    kierunek.AddStudent(a4);
    cin>>a5;
    kierunek.AddStudent(a5);
    cin>>a6;
    kierunek.AddStudent(a6);
    cin>>a7;
    kierunek.AddStudent(a7);
    cin>>a8;
    kierunek.AddStudent(a8);
    cin>>a9;
    kierunek.AddStudent(a9);


    kierunek.ShowThreeStudents(global);

   Employee p1;
   cin>>p1;
   Employee p2;
   cin>>p2;
   cout<<" ";
    p1.UntilRetirement();
    cout<<" ";
    p2.UntilRetirement();
    return 0;
}