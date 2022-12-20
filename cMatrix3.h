#ifndef CMATRIX3_H
#define CMATRIX3_H

#include <iostream>
using namespace std;
// number of raws
#define nR 3
//number of columns
#define nC 3

class cMatrix3
{
    public:
        /** Default constructor */
        cMatrix3();
        cMatrix3(double a[nC*nR]);

        /** Default destructor */
        virtual ~cMatrix3();
        cMatrix3 add(cMatrix3 arga);// =this + argc
        cMatrix3 sub(cMatrix3 arga);// =this - argc
        cMatrix3 prod(cMatrix3 arga);// = this . argc
        cMatrix3 multi(cMatrix3 arga);
        cMatrix3 trans();
        cMatrix3 adjoint();
        cMatrix3 inver();
        double delta();
        int ranks();



        cMatrix3 scalarmul(double c); // = c x this (c -constant)
        cMatrix3 inverse(); //  inverse of this

        void show();// display this
        void show_list1();

    private:
        double a[nC*nR]; // matrix data

};

#endif // CMATRIX3_H
