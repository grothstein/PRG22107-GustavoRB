//============================================================================
// Name        : ExercVector.cpp
// Author      : Gustavo Rothstein
// Copyright   : No copyrights
// Description : Simple complex numbers calculator.
//============================================================================
#include <iostream>
#include "numcomplexo.h"

#define PI 3.14159265359

using namespace std;

int main()
{
    NumComplexo num1("rec", 3, 4), num2("pol", 6, PI/2), num3, num4;
    double re, im, mod, angd, angr;

    cout << "Testando os operadores:" << endl;
    num3 = num1 + num2;
    num4 = num1 * num2;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num1 + num2 = " << num3 << endl;
    cout << "num1 * num2 = " << num4 << endl;
    cout << "(num1 * num2)/num2 = " << num4/num2 << endl;
    cout << "(num1 * num2) - (num1 + num2) = " << num4 - num3 << endl;

    cout << endl << "Testando os getters e setters:" << endl;

    num4.get_rec_form(&re,&im);
    num4.get_pol_form_deg(&mod,&angd);
    num4.get_pol_form_rad(&mod,&angr);

    cout << "re = " << re << endl << "im = " << im <<endl;
    cout << "mod = " << mod << endl << "deg = " << angd << "  |  " << "rad = " << angr <<endl;

    num4.set_pol_form_deg(mod, angd);
    cout << num4 << endl;
    num4.set_pol_form_rad(mod, angr);
    cout << num4 << endl;
    num4.set_rec_form(re,im);
    cout << num4 << endl;

    return 0;
}
