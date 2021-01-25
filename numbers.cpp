#include <iostream>
#include <math.h>
#inclide 'cos.h'
class FloatNumber{
private:
    bool sign;
    int index;
    float mantissa;
public:
    test operator+=(test);
        test operator-=(test);
        friend ostream & operator<<(ostream & stdout, const test & arg);
        friend test operator+(test,test);
FloatNumber(bool a=0, int b=0, float c=0)
{
sign=a;
index=b;
mantissa=c;
}
FloatNumber(float c)
{
    index=0;
    if(c>0)
    {
        sign=1;
        while(c>=10)
        {
            c=c/10;
            index++;
            mantissa=c;
        }
        while(c<1)
        {
            c=c*10;
            index--;
            mantissa=c;
        }
    }
    else
    if(c<0)
    {
        sign=0;
        while(c<=(-10))
        {
            c=c/10;
            index++;
            mantissa=c;
        }
        while(c>(-1))
        {
            c=c*10;
            index--;
            mantissa=c;
        }
    }
}
};

FloatNumber FloatNumber::operator+=(FloatNumber arg)
{
    FloatNumber temp;
    while(index!=arg.index)
    {
        if(index>arg.index)
        {
            index=index-1;
            mantissa=mantissa*10.0;
        }
        else if(index<arg.index)
        {
            arg.index=arg.index-1;
            arg.mantissa=arg.mantissa*10.0;
        }
    }
    if(sign==1 && arg.sign==1)
    {
        this->mantissa = (this->mantissa+arg.mantissa);
        this->index=index;
    }
    else if(sign==0 && arg.sign==0)
    {
        this->mantissa = (this->mantissa*(-1)+arg.mantissa*(-1));
        this->index=index;
    }
    else if(sign==1 && arg.sign==0)
    {
        this->mantissa = (this->mantissa+arg.mantissa*(-1));
        this->index=index;
    }
    else if(sign==0 && arg.sign==1)
    {
        this->mantissa = (this->mantissa*(-1)+arg.mantissa);
        this->index=index;
    }
    return this;
}

FloatNumber FloatNumber::operator-=(FloatNumber arg)
{
    FloatNumber temp;
    while(index!=arg.index)
    {
        if(index>arg.index)
        {
            index=index-1;
            mantissa=mantissa*10;
        }
        else
        {
            arg.index=arg.index-1;
            arg.mantissa=arg.mantissa*10;
        }
    }
    if(sign==1 && arg.sign==1)
    {
        this->mantissa = (this->mantissa-arg.mantissa);
        this->index=index;
    }
    else if(sign==0 && arg.sign==0)
    {
        this->mantissa = (this->mantissa*(-1)-arg.mantissa*(-1));
        this->index=index;
    }
    else if((sign==1 && arg.sign==0)|| (sign==0 && arg.sign==1))
    {
        this->mantissa = (this->mantissa+arg.mantissa*(-1));
        this->index=index;
    }

    return this;
}

FloatNumber operator+(FloatNumber a1, FloatNumber a2)
{
    FloatNumber temp;
    while(a1.index!=a2.index)
    {
        if(a1.index>a2.index)
        {
            a1.index=(a1.index-1);
            a1.mantissa=a1.mantissa*10.0;
        }
        else if(a1.index<a2.index)
        {
            a2.index=a2.index-1;
            a2.mantissa=a2.mantissa*10.0;
        }
    }
    if(a1.sign==0)
    {
        a1.mantissa=a1.mantissa*(-1);
    }
    if(a2.sign==0)
    {
        a2.mantissa=a2.mantissa*(-1);
    }
    temp.index=a1.index;
    temp.mantissa=a1.mantissa+a2.mantissa;

    return temp;

}
ostream & operator<<(ostream &out, const FloatNumber &arg)
{

    out<<arg.mantissa*pow(10,arg.index);
    return out;
}

bool CheckBool()
{
    char arg;
    while(!(cin>>arg)||((arg!='+')&&(arg!='-')))
    {
        cin.clear();
        cin.ignore();
    }
    if(arg=='+')
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int CheckInt()
{
    int arg;
    while(!(cin>>arg))
    {
        cin.clear();
        cin.ignore();
    }
    return arg;
}

float CheckFloat()
{
    float arg;
    while(!(cin>>arg))
    {
        cin.clear();
        cin.ignore();
    }
    return arg;
}




int main()
{
    bool sign;
    int index;
    float mantissa;

    sign=CheckBool();
    index=CheckInt();
    mantissa=CheckFloat();

    FloatNumber x0(sign,index,mantissa);

    sign=CheckBool();
    index=CheckInt();
    mantissa=CheckFloat();

    FloatNumber x1(sign,index,mantissa);

    mantissa=CheckFloat();
    FloatNumber x2(mantissa);

    mantissa=CheckFloat();
    FloatNumber x3(mantissa);

    x0+=x1;

    x3 -= x2;

    FloatNumber x4=x1+x3;
    cout<<x0<<" "<<x1<<" "<<x2<<" "<<x3<<" "<<x4;
    return 0;
}
