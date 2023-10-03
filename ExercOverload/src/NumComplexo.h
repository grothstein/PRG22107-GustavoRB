#ifndef NUMCOMPLEXO_H
#define NUMCOMPLEXO_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

class NumComplexo{
private:
    double _Re;
    double _Im;
    double _Mod;
    double _Ang;

    void calc_re();
    void calc_im();
    void calc_mod();
    void calc_ang();

public:
    NumComplexo(){_Re = 0;_Im = 0;_Mod = 0;_Ang = 0;}
    NumComplexo(string rec_pol, double re_mod, double im_angrad);

    void get_rec_form(double *re, double *im);
    void get_pol_form_deg(double *mod, double *ang);
    void get_pol_form_rad(double *mod, double *ang);
    void set_rec_form(double re, double im);
    void set_pol_form_deg(double mod, double ang);
    void set_pol_form_rad(double mod, double ang);

    friend ostream& operator<< (ostream &out,const NumComplexo &num);
    NumComplexo operator+ (const NumComplexo &num);
    NumComplexo operator- (const NumComplexo &num);
    NumComplexo operator* (const NumComplexo &num);
    NumComplexo operator/ (const NumComplexo &num);
    void operator= (const NumComplexo &num);
};
#endif // NUMCOMPLEXO_H
