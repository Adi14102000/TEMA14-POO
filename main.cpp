#include<iostream>
using namespace std;

class Polinom_dinamic
{
    private:
        struct Nod{
            double coef;
            double pow;
            Nod *next;
        } ;

        Nod* cap;
        Nod *crt;

    public:
        Polinom_dinamic()
        {
            cap=NULL;
        }

        ~Polinom_dinamic()
        {
            crt=cap;
            while(crt!=NULL)
            {
               Nod* next=crt->next;
               crt=next;
            }
            cap=0;
        }
        Polinom_dinamic(Polinom_dinamic &pol)
        {
            if(pol.cap==NULL)
                cap=NULL;
            else
            {
                cap=new Nod;
                cap->coef=pol.cap->coef;
                cap->pow=pol.cap->pow;
                Nod* crt=cap;
                Nod* cappol=pol.cap;
                Nod* polcrt=cappol;
                while(polcrt->next !=NULL)
                {
                    crt->next=new Nod;
                    crt->next->coef=polcrt->next->coef;
                    crt->next->pow=polcrt->next->pow;
                    polcrt=polcrt->next;
                    crt=crt->next;
                }
            }
        }
        void add(int x, int y)
        {
            Nod *p= new Nod;
            p->coef=x;
            p->pow=y;
            p->next=cap;
            cap=p;
        }
        double val_punct(double x)
        {
            crt=cap;
            double s=0, aux;
            while(crt!=NULL)
            {
                aux=1;
                for(double i=0; i<crt->pow; i++)
                    aux=aux*x;
                s=s+crt->coef*aux;
                crt=crt->next;
            }
            return s;
        }
        void afisare()
        {
            crt=cap;
            while(crt!=NULL)
            {
                cout<<crt->coef<<"x^"<<crt->pow<<"+";
                crt=crt ->next;
            }
        }
        Polinom_dinamic operator+(Polinom_dinamic a)
        {
            Polinom_dinamic r;
            Nod* crt1;
            crt=cap;
            bool ok;
            double s, b;
            while(crt!=NULL)
            {
                crt1=a.cap;
                ok=false;
                while(crt1!=NULL)
                {
                    if(crt1->pow==crt->pow)
                    {
                        ok=true;
                        s=crt->coef+crt1->coef;
                        b=crt->pow;
                        r.add(s, b);
                        break;
                    }
                    crt1=crt1->next;
                }
                if(ok==false)
                {
                    s=crt->coef;
                    b=crt->pow;
                    r.add(s, b);
                }
                crt=crt->next;
            }
            crt1=a.cap;
            while(crt1!=NULL)
            {
                crt=cap;
                ok=false;
                while(crt!=NULL)
                {
                  if(crt1->pow==crt->pow)
                    {
                        ok=true;
                        break;
                    }
                    crt=crt->next;
                }
                if(ok==false)
                {
                    s=crt1->coef;
                    b=crt1->pow;
                    r.add(s, b);
                }
                crt1=crt1->next;
            }

            return r;

        }
        Polinom_dinamic operator-(Polinom_dinamic a)
        {
            Polinom_dinamic r;
            Nod* crt1;
            crt=cap;
            bool ok;
            double s, b;
            while(crt!=NULL)
            {
                crt1=a.cap;
                ok=false;
                while(crt1!=NULL)
                {
                    if(crt1->pow==crt->pow)
                    {
                        ok=true;
                        s=crt->coef-crt1->coef;
                        b=crt->pow;
                        r.add(s, b);
                        break;
                    }
                    crt1=crt1->next;
                }
                if(ok==false)
                {
                    s=crt->coef;
                    b=crt->pow;
                    r.add(s, b);
                }
                crt=crt->next;
            }
            crt1=a.cap;
            while(crt1!=NULL)
            {
                crt=cap;
                ok=false;
                while(crt!=NULL)
                {
                  if(crt1->pow==crt->pow)
                    {
                        ok=true;
                        break;
                    }
                    crt=crt->next;
                }
                if(ok==false)
                {
                    s=-crt1->coef;
                    b=-crt1->pow;
                    r.add(s, b);
                }
                crt1=crt1->next;
            }

            return r;

        }
Polinom_dinamic operator*(Polinom_dinamic a)
        {
            Polinom_dinamic r;
            Polinom_dinamic aux;
            Nod* crt1;
            Nod* crt2;
            Nod* crt3;
            crt=cap;
            double s, b;
            bool ok, verif;
            while(crt!=NULL)
            {
                crt1=a.cap;
                while(crt1!=NULL)
                {
                    s=crt->coef*crt1->coef;
                    b=crt->pow+crt1->pow;
                    aux.add(s, b);
                    crt1=crt1->next;
                }
                crt=crt->next;
            }
            crt1=aux.cap;
            while(crt1!=NULL)
            {
             crt2=crt1->next;
             ok=true;
             s=crt1->coef;
             while(crt2!=NULL)
             {
                 if(crt1->pow==crt2->pow)
                 {
                     ok=false;
                     s=s+crt1->coef;
                 }
                 crt2=crt2->next;
             }
             if(ok)
             {
                 s=crt1->coef;
                 b=crt1->pow;
                 r.add(s, b);
             }
             else
             {
                 crt3=r.cap;
                 verif=true;
                 while(crt3!=NULL)
                 {
                     if(crt3->pow==crt1->pow)
                        verif=false;
                    crt3=crt3->next;
                 }
                 if(verif)
                 {
                     b=crt1->pow;
                     r.add(s, b);
                 }
             }
             crt1=crt1->next;
            }
          return r;
        }


};
int main()
{
    Polinom_dinamic p1, p2, p3;
    double s;
    p1.add(1, 1);
    p1.add(1, 0);
    p2.add(3, 2);
    p2.add(1, 1);
    p2.add(1, 0);
    p1.afisare();
    cout<<endl;
    p2.afisare();
    cout<<endl;
    p3=p1+p2;
    p3.afisare();
    cout<<endl;
    p3=p1-p2;
    p3.afisare();
    cout<<endl;
    p3=p1*p2;
    p3.afisare();
    return 0;
}
