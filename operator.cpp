#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;
  class test
    {

    private:
        bool znak;
        int liczba;
        float mant;

    public:

        test operator+=(test);
        test operator-=(test);
        friend ostream & operator<<(ostream & stdout, const test & arg);
        friend test operator+(test,test);


        test(bool a=0, int b=0, float c=0)
        {
           znak=a;
           liczba=b;
           mant=c;

        }
        test(float c)
        {
            liczba=0;

            if(c>0)
            {
                znak=1;
            while(c>=10)
            {
                c=c/10;
                liczba++;
                mant=c;
            }
            while(c<1)
            {
                c=c*10;
                liczba--;
                mant=c;
            }
            }
            else
                 if(c<=0)
            {
                znak=0;
            while(c<=(-10))
            {
                c=c/10;
                liczba++;
                mant=c;
            }
            while(c>(-1))
            {
                c=c*10;
                liczba--;
                mant=c;
            }
            }

        }



    };



test test::operator+=(test arg)
{
    test temp;

    while(liczba!=arg.liczba)
    {
        if(liczba>arg.liczba)
        {
            liczba=liczba-1;
            mant=mant*10.0;
        }
        else if(liczba<arg.liczba)
        {
            arg.liczba=arg.liczba-1;
            arg.mant=arg.mant*10.0;
        }
    }
    if(znak==1 && arg.znak==1)
    {
    this->mant = (this->mant+arg.mant);
    this->liczba=liczba;
    }
    else if(znak==0 && arg.znak==0)
    {
    this->mant = (this->mant*(-1)+arg.mant*(-1));
    this->liczba=liczba;
    }
    else if(znak==1 && arg.znak==0)
    {
    this->mant = (this->mant+arg.mant*(-1));
    this->liczba=liczba;
    }
    else if(znak==0 && arg.znak==1)
    {
    this->mant = (this->mant*(-1)+arg.mant);
    this->liczba=liczba;
    }
    return this;
}

test test::operator-=(test arg)
{
    test temp;
    while(liczba!=arg.liczba)
    {
        if(liczba>arg.liczba)
        {
            liczba=liczba-1;
            mant=mant*10;
        }
        else
        {
            arg.liczba=arg.liczba-1;
            arg.mant=arg.mant*10;
        }
    }
    if(znak==1 && arg.znak==1)
    {
    this->mant = (this->mant-arg.mant);
    this->liczba=liczba;
    }
    else if(znak==0 && arg.znak==0)
    {
    this->mant = (this->mant*(-1)-arg.mant*(-1));
    this->liczba=liczba;
    }
    else if(znak==1 && arg.znak==0)
    {
    this->mant = (this->mant-arg.mant);
    this->liczba=liczba;
    }
    else if(znak==0 && arg.znak==1)
    {
    this->mant = (this->mant*(-1)-arg.mant);
    this->liczba=liczba;
    }
    return this;
}






test operator+(test a1, test a2)
{
    test temp;
    while(a1.liczba!=a2.liczba)
    {
        if(a1.liczba>a2.liczba)
        {
            a1.liczba=(a1.liczba-1);
            a1.mant=a1.mant*10.0;
        }
        else if(a1.liczba<a2.liczba)
        {
            a2.liczba=a2.liczba-1;
            a2.mant=a2.mant*10.0;
        }
    }
    if(a1.znak==0)
    {
        a1.mant=a1.mant*(-1);
    }
      if(a2.znak==0)
    {
        a2.mant=a2.mant*(-1);
    }
    temp.liczba=a1.liczba;
    temp.mant=a1.mant+a2.mant;
    return temp;

}
ostream & operator<<(ostream &out, const test &arg)
       {

        out<<arg.mant*pow(10,arg.liczba);

        return out;
        }


int main()
{
    char z;
    bool a;
    int b;
    float c;

     while(!(cin>>z)&&(z!='+')&&(z!='-'))
    {
        cin.clear();
        cin.ignore();
    }
    if(z=='+')
    {   a=1;
    }
    else
    {
        a=0;
    }

    while(!(cin>>b))
    {
        cin.clear();
        cin.ignore();
    }
    while(!(cin>>c))
    {
        cin.clear();
        cin.ignore();
    }

    test x0(a,b,c);

    while(!(cin>>z)&&(z!='+')&&(z!='-'))
    {
        cin.clear();
        cin.ignore();
    }
    if(z=='+')
    {   a=1;
    }
    else
    {
        a=0;
    }

     while(!(cin>>b))
    {
        cin.clear();
        cin.ignore();
    }
    while(!(cin>>c))
    {
        cin.clear();
        cin.ignore();
    }
    test x1(a,b,c);

    while(!(cin>>c))
    {
        cin.clear();
        cin.ignore();
    }
    test x2(c);

    while(!(cin>>c))
    {
        cin.clear();
        cin.ignore();
    }
    test x3(c);





    x0+=x1;
    x3 -= x2;
    test x4=x1+x3;
    cout<<x0<<" "<<x1<<" "<<x2<<" "<<x3<<" "<<x4;
    return 0;
}
