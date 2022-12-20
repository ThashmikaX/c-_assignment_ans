#include <iostream>
#include "cMatrix3.h"

using namespace std;


int main()
{
    int h;
    cout<< "how many matrix do you have? ";
    cin>>h;


    if (h==1){
                double a1[9];
                cout<<"Enter terms for matrix(3*3)"<<endl;
                cout<<"Note:Enter your input as row by row"<<endl;
                for(int i=0; i<9; i++)
                {
                    cin>>a1[i];
                }
                cMatrix3 m1(a1);
                cMatrix3  m4,m5,m8,m7,m9;
                cout<<" "<<endl;
                cout<<"1 - inverse"<<endl;
                cout<<"2 - adjoint"<<endl;
                cout<<"3 - rank"<<endl;
                cout<<"4 - scalar"<<endl;

                int p;
                cout<<" "<<endl;
                cout<<"enter option... "; cin>>p;
                cout<<" "<<endl;


                double  q =2;
                switch(p)
                {
                    case 1: m9 = m1.inver(); m1.show(); cout<<endl<<"Result : "; m9.show();break;
                    case 2: m8 = m1.adjoint(); m1.show(); cout<<endl<<"Result : "; m8.show();break;
                    case 3: cout<<m1.ranks(); cout<<endl<<"Result : ";m1.show(); break;
                    case 4: m7 = m1.trans(); cout<<endl<<"Result : "; m1.show(); m7.show();break;
                    case 5: m4 = m1.scalarmul(q); m1.show(); m4.show();break;
                    default: cout<<"incorrect case";
                }
    }


    if (h==2){
                double a1[9] , a2[9];
                cout<<"Enter terms for 1st matrix(3*3)"<<endl;
                cout<<"Note:Enter your input as row by row"<<endl;
                for(int i=0; i<9; i++)
                {
                    cin>>a1[i];
                }
                cout<<"Enter terms for 2nd matrix(3*3)"<<endl;
                cout<<"Note:Enter your input as row by row"<<endl;
                for(int i=0; i<9; i++)
                {
                    cin>>a2[i];
                }
                cMatrix3 m1(a1), m2(a2);
                cMatrix3 m3, m4,m5,m6,m8,m9;
                //show list
                int q;
                cout<<endl<<"1 - addition"<<endl;
                cout<<"2 - subtraction"<<endl;
                cout<<"3 - multiplication"<<endl<<" "<<endl;
                cout<<"enter option... "; cin>>q;
                switch(q)
                {
                    case 1: m3 = m1.add(m2); m1.show(); m2.show(); cout<<endl<<"Result : "; m3.show();break;
                    case 2: m5 = m1.sub(m2); m1.show(); m2.show(); cout<<endl<<"Result : "; m5.show();break;
                    case 3: m6 = m1.multi(m2); m1.show(); m2.show(); cout<<endl<<"Result : "; m6.show(); break;

                    default: cout<<"incorrect case";

                }

    }











    return 0;
}
