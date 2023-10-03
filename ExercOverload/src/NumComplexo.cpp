#include "numcomplexo.h"

#define DEBUG_ON
#define DEC_PRECISION 2
#define PI 3.14159265359

NumComplexo::NumComplexo(string rec_pol, double re_mod, double im_ang){
    if(rec_pol == "rec"){
        _Re = re_mod;
        _Im = im_ang;
        calc_mod();
        calc_ang();
    }else if(rec_pol == "pol"){
        _Mod = re_mod;
        _Ang = im_ang;
        calc_re();
        calc_im();
    }else{
        #ifdef DEBUG_ON
        cout << "Declaracao invalida de NumComplexo";
        #endif
        exit(EXIT_FAILURE);
    }
}

void NumComplexo::calc_re(){
	_Re = _Mod*cos(_Ang);
}

void NumComplexo::calc_im(){
	_Im = _Mod*sin(_Ang);
}

void NumComplexo::calc_mod(){
	_Mod = sqrt((_Re*_Re)+(_Im*_Im));
}

void NumComplexo::calc_ang(){
	if(_Im||_Re){			//if realizado para evitar a indeterminação 0/0 (que gera um erro em atan2)
		_Ang = atan2(_Im,_Re);
	}else{
		_Ang=0;
	}
}

void NumComplexo::get_rec_form(double *re, double *im){
	*re = _Re;*im = _Im;
};

void NumComplexo::get_pol_form_deg(double *mod, double *ang){
	*mod = _Mod;
	*ang = _Ang*180/PI;
};

void NumComplexo::get_pol_form_rad(double *mod, double *ang){
	*mod = _Mod;
	*ang = _Ang;
};

void NumComplexo::set_rec_form(double re, double im){
	_Re = re;
	_Im = im;
};

void NumComplexo::set_pol_form_deg(double mod, double ang){
	_Mod = mod;
	_Ang = (ang*PI)/180;
};

void NumComplexo::set_pol_form_rad(double mod, double ang){
	_Mod = mod;
	_Ang = ang;
};

NumComplexo NumComplexo::operator+ (const NumComplexo &num){
    NumComplexo result;
    result._Re = this->_Re + num._Re;
    result._Im = this->_Im + num._Im;
    result.calc_mod();
    result.calc_ang();
    return result;
}

NumComplexo NumComplexo::operator- (const NumComplexo &num){
    NumComplexo result;
    result._Re = this->_Re - num._Re;
    result._Im = this->_Im - num._Im;
    result.calc_mod();
    result.calc_ang();
    return result;
}

NumComplexo NumComplexo::operator* (const NumComplexo &num){
    NumComplexo result;
    result._Mod = this->_Mod * num._Mod;
    result._Ang = this->_Ang + num._Ang;
    result.calc_re();
    result.calc_im();
    return result;
}

NumComplexo NumComplexo::operator/ (const NumComplexo &num){
    NumComplexo result;
    result._Mod = this->_Mod / num._Mod;
    result._Ang = this->_Ang - num._Ang;
    result.calc_re();
    result.calc_im();
    return result;
}

void NumComplexo::operator= (const NumComplexo &num){
	this->_Re = num._Re;
	this->_Im = num._Im;
	this->_Mod = num._Mod;
	this->_Ang = num._Ang;
}

ostream& operator<< (ostream &out,const NumComplexo &num){
    out << fixed << setprecision(DEC_PRECISION);
    out << num._Re << " + j" << num._Im << "  |  " << num._Mod << '<' << (num._Ang*180)/PI;
    return out;
}
