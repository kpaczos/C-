#include<iostream>
#include<string>

using namespace std;
class Catalog;
//void InsertValue(string in_n, int in_p, double in_w, char in_t);

class Car
    {
        string number;
        int power;
        double weight;
        char type;

        public:
			Car() {}
        string show()
        {
        return number +" " + to_string(power) + " ";
        }
        int get_power()
        {
            return power;
        }
        Car(string n, int p, double w, char t):
            number(n), power(p), weight(w), type(t){}


    };

class Catalog
    {
        Car *heap;
        Car *Tab;

		/*Car min();
		void remove_min();*/
		int heap_size;

		Car min_child(Car parent);

		//Funkcje do liczenia indeksów dzieci
		int get_left(int x) {
			return 2 * x;
		};
		int get_right(int x) {
			return 2 * x + 1;
		}

		//Funkcja do liczenia indeksu rodzica
		int get_parent(int x) {
			return x / 2;
		}

		//Funkcja do przywracania w³asnoœci kopca
		void heapify(Car Tab[], int x, int n) {
			int l = get_left(x);
			int r = get_right(x);
			int s = x;

			bool something_changed = false;

			if (l <= n && Tab[l].get_power() < Tab[x].get_power()) s = l;
			else
		        s=x;
			if (r <= n && Tab[r].get_power() < Tab[s].get_power()) s = r;

			if (s != x) {
				Car tmp = Tab[x];
				Tab[x] = Tab[s];
				Tab[s] = tmp;
				heapify(Tab, s,n);
			}
		}

        public:
			Catalog() {
				heap = new Car[7];
				heap_size = 0;

			}

			//Funkcja dodaj¹ca element do kopca
			void insert(Car c) {
				heap_size++;
				int k = heap_size;	//Ustawiamy wskaŸnik na ostatni dotychczasowy element
				if (k >= 7) return;	//Zabezpieczenie przed wyjœciem poza tablicê
				//Iteruj¹c od koñca sprawdzamy czy kolejni rodzice s¹ wiêksi(z za³o¿eñ zadania, ¿e w korzeniu ma znaleŸæ siê element o najmniejszej mocy) od wstawianego elementu
				while (k > 1 && heap[get_parent(k)].get_power() > c.get_power()) {
					heap[k] = heap[get_parent(k)];	//Rodzica "zrzucamy" o poziom ni¿ej
					k = get_parent(k);
				}
				heap[k] = c; //Zapisujemy element
			}

			void show() {
				//heapsort
				Tab = new Car[7];
				int s=heap_size;
			    if(s>=7)return;
			    Car temp;
			    for(int i=0; i<s; i++)
			    {
			        Tab[i]=heap[i];
			    }
               for(int i=s; i>=2 ; i--)
               {
                    temp=Tab[i];
                    Tab[i]=Tab[1];
                    Tab[1]=temp;
                    heapify(Tab,1,s-1);
                }


				//wyœwietl tablicê wynikow¹ heapsorta

				for (int i = 1; i <= 6; i++) {
					cout << Tab[i].show()<<" ";
				}
			}

			/*int get_heap_size()
			{
				return heap_size;
			}*/

    };
    void InsertValue(string &n, int &p, double &w, char &t)
{

   do{
        cin>>n;
    }while(n.length()!=4);

    int a=7;
    int c=0;
    do{
        string Power;
        cin>>Power;
        a=Power.length();
        int b;
         for(int i=0; i<Power.length();i++)
            {
                if(Power[0]==48)
                break;
                if(Power[i]>47 && Power[i]<58)
                {
                    if(a==7)
                    b=1000000;
                    if(a==6)
                    b=100000;
                    if(a==5)
                    b=10000;
                    if(a==4)
                    b=1000;
                    if(a==3)
                    b=100;
                    if(a==2)
                    b=10;
                    if(a==1)
                    b=1;
                    c=c+(Power[i]-48)*b;
                    a--;
                }
                else
                {
                    c=0;
                    break;
                }
            }
   }while(a>=1);
   p=c;

   double W1=0;
        int x, y, L;
        do
        {
            double d;
            string W;
            cin>>W;
            L=W.length()-1;
            for(int i=0;i<W.length();i++)
            {
                if(W[i]==46)
                {
                    y=i;
                    break;
                }
            }
            x=y;
            if(y==0)
            {
                y=W.length();
                x=W.length();
            }
            for(int i=0; i<y;i++)
            {
                if(W[i]>47 && W[i]<58)
                {
                    if(x==5)
                    d=10000;
                    if(x==4)
                    d=1000;
                    if(x==3)
                    d=100;
                    if(x==2)
                    d=10;
                    if(x==1)
                    d=1;
                    W1=W1+(W[i]-48)*d;
                    x--;
                    L--;
                }
                else
                {
                    W1=0;
                    break;
                }
            }
            int f=1;
            for(int i=y+1;i<W.length();i++)
            {
                if(W[i]>47 && W[i]<58)
                {
                    if(f==5)
                    d=0.00001;
                    if(f==4)
                    d=0.0001;
                    if(f==3)
                    d=0.001;
                    if(f==2)
                    d=0.01;
                    if(f==1)
                    d=0.1;
                    W1=W1+(W[i]-48)*d;
                    f++;
                    L--;
                }
                else
                {
                    W1=0;
                    break;
                }
            }
        }while(L>=1);
        w=W1;
   do{
        cin>>t;
   }while(t!='B' && t!='D' && t!='E' && t!='H');
}

int main()
{
    Catalog C;

	for (int i = 0; i < 6; i++) {
		string plate_number="Num1";
		int power=0;
		double weight=0.0;
		char type='A';
		InsertValue(plate_number, power, weight, type);
		C.insert(Car(plate_number, power, weight, type));

	}

	C.show();
	system("pause");

    return 0;
}
