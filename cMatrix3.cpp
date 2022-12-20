#include "cMatrix3.h"


cMatrix3::cMatrix3()
{
    for(int i=0;i<9;++i) a[i]=1;
}
cMatrix3::cMatrix3(double arga[9])
{
    for(int i=0; i<9;++i) a[i] = arga[i];
}


cMatrix3::~cMatrix3()
{
    //dtor
}

cMatrix3 cMatrix3::add(cMatrix3 arga)
{   cMatrix3 m;

    for(int i=0; i<9;++i)
    {
       m.a[i] = a[i] + arga.a[i];
    }

    return m;
}
cMatrix3 cMatrix3::sub(cMatrix3 arga)
{   cMatrix3 m;

    for(int i=0; i<9;++i)
    {
       m.a[i] = a[i] - arga.a[i];
    }

    return m;
}


cMatrix3 cMatrix3::trans()
{   cMatrix3 m;

    m.a[0] = a[0];
    m.a[1] = a[3];
    m.a[2] = a[6];
    m.a[3] = a[1];
    m.a[4] = a[4];
    m.a[5] = a[7];
    m.a[6] = a[2];
    m.a[7] = a[5];
    m.a[8] = a[8];


    return m;
}

cMatrix3 cMatrix3::multi(cMatrix3 arga)
{   cMatrix3 m;

    m.a[0] = a[0]*arga.a[0] + a[1]*arga.a[3] + a[2]*arga.a[6] ;
    m.a[1] = a[0]*arga.a[1] + a[1]*arga.a[4] + a[2]*arga.a[7] ;
    m.a[2] = a[0]*arga.a[2] + a[1]*arga.a[5] + a[2]*arga.a[8] ;
    m.a[3] = a[3]*arga.a[0] + a[4]*arga.a[3] + a[5]*arga.a[6] ;
    m.a[4] = a[3]*arga.a[1] + a[4]*arga.a[4] + a[5]*arga.a[7] ;
    m.a[5] = a[3]*arga.a[2] + a[4]*arga.a[5] + a[5]*arga.a[8] ;
    m.a[6] = a[6]*arga.a[0] + a[7]*arga.a[3] + a[8]*arga.a[6] ;
    m.a[7] = a[6]*arga.a[1] + a[7]*arga.a[4] + a[8]*arga.a[7] ;
    m.a[8] = a[6]*arga.a[2] + a[7]*arga.a[5] + a[8]*arga.a[8] ;

    return m;
}
cMatrix3 cMatrix3::scalarmul(double argc)
{   cMatrix3 m;

    for(int i=0; i<9;++i)
    {
       m.a[i] = argc * a[i];
    }

    return m;
}


cMatrix3 cMatrix3::inver()
{   cMatrix3 m,z;
    double x;
    m.a[0] = (a[4]*a[8]-a[5]*a[7]);
    m.a[3] = (-a[3]*a[8]+a[5]*a[6]);
    m.a[6] = (a[3]*a[7]-a[4]*a[6]);
    m.a[1] = (-a[1]*a[8]+a[2]*a[7]);
    m.a[4] = (a[0]*a[8]-a[2]*a[6]);
    m.a[7] = (-a[0]*a[7]+a[1]*a[6]);
    m.a[2] = (a[1]*a[5]-a[4]*a[2]);
    m.a[5] = (-a[3]*a[2]+a[0]*a[5]);
    m.a[8] = (a[0]*a[4]-a[1]*a[3]);




   x=  a[0]*a[4]*a[8]-a[0]*a[5]*a[7] -a[1]*a[3]*a[8]+a[1]*a[5]*a[6] + a[2]*a[3]*a[7]-a[2]*a[4]*a[6] ;
   double y = 1/x;

    z.a[0] =m.a[0]*y;
    z.a[1] =m.a[3]*y;
    z.a[2] =m.a[6]*y;
    z.a[3] =m.a[1]*y;
    z.a[4] =m.a[4]*y;
    z.a[5] =m.a[7]*y;
    z.a[6] =m.a[2]*y;
    z.a[7] =m.a[5]*y;
    z.a[8] =m.a[8]*y;




    return z;
}


cMatrix3 cMatrix3::adjoint()
{   cMatrix3 m;

    m.a[0] = (a[4]*a[8]-a[5]*a[7]);
    m.a[3] = (-a[3]*a[8]+a[5]*a[6]);
    m.a[6] = (a[3]*a[7]-a[4]*a[6]);
    m.a[1] = (-a[1]*a[8]+a[2]*a[7]);
    m.a[4] = (a[0]*a[8]-a[2]*a[6]);
    m.a[7] = (-a[0]*a[7]+a[1]*a[6]);
    m.a[2] = (a[1]*a[5]-a[4]*a[2]);
    m.a[5] = (-a[3]*a[2]+a[0]*a[5]);
    m.a[8] = (a[0]*a[4]-a[1]*a[3]);


    return m;
}

double cMatrix3::delta()
{   double x;


   x=  a[0]*a[4]*a[8]-a[0]*a[5]*a[7] -a[1]*a[3]*a[8]+a[1]*a[5]*a[6] + a[2]*a[3]*a[7]-a[2]*a[4]*a[6] ;

    return x;
}


int cMatrix3::ranks()
{   int r;


   double x=  a[0]*a[4]*a[8]-a[0]*a[5]*a[7] -a[1]*a[3]*a[8]+a[1]*a[5]*a[6] + a[2]*a[3]*a[7]-a[2]*a[4]*a[6] ;

   double y0= a[0]*a[4]-a[3]*a[2];
   double y1= a[1]*a[5]-a[2]*a[4];
   double y2= a[3]*a[7]-a[4]*a[6];
   double y3= a[4]*a[8]-a[5]*a[7];

   if(x!=0.0)
   {
       r=3;
   }
   else if (y0!=0.0 || y1!=0.0 || y2!=0.0 || y3!=0.0)
   {
       r=2;
   }
   else if (a[0]!=0.0 || a[2]!=0.0 || a[3]!=0.0 || a[4]!=0.0 || a[5]!=0.0 || a[6]!=0.0 || a[7]!=0.0 || a[8]!=0.0 )
    {
        r=1;
    }
    else
    {
        r=0;
    }

    return r;
}




void cMatrix3::show()
{
    cout<<endl;
    for(int i=0; i<9;++i)
    {
       cout<<"\t"<<a[i];
       if(i==2 || i ==5 || i==8 ) cout<<endl;
    }

}




