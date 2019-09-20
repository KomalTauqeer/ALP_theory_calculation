#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

double triangularFunct(double x, double y);
double decayRate(int a);

void decayRateHZalp()
{
        double decayWidth;
        int a;
	cout << "Summary of Decay Width for the Process h > Z alp" << endl;
        cout << "================================================" << endl;
	cout << "Type 0 for CZh7 and any other integer for CZh5" << endl;
        cin >> a;
        decayWidth = decayRate(a);
        cout << "Decay Width = " << decayWidth << " GeV " << endl;
        cout << "================================================" << endl;
}


double triangularFunct(double x, double y)
{
	return (((1-x-y)*(1-x-y))-4*x*y);
}


double decayRate(int a)
{
	const double  mH= 1.250000e+02;
        const double  mZ= 9.118760e+01;
        const double  mA= 1.000000e+00;
        const double vev= 2.462200e+02;
        const double lembda= 1.000000e+03;
        const double CZh7= 1.000000e+00;
        const double CZh5= 1.000000e+00;
	double DR;

	if (a==0) { 
		 DR= (pow(mH,3)*pow(vev,4)*pow(CZh7,2)*pow(triangularFunct(((mZ*mZ)/(mH*mH)),((mA*mA)/(mH*mH))),1.5))/(16*4*M_PI*pow(lembda,6));
	}
 	else{
                 DR= (pow(mH,3)*pow(CZh5,2)*pow(triangularFunct(((mZ*mZ)/(mH*mH)),((mA*mA)/(mH*mH))),1.5))/(16*M_PI*pow(lembda,2));
        }  
      
	return DR;

}

