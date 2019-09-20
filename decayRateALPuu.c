#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

double decayRate29(double malp);
double decayRate30(double malp);

void decayRateALPuu()
{
        double decayWidth;
	double malp;
        int temp1;
	int temp2;
	
	cout << "Choose an equation you want to implement for calculation of decay width " << endl;
	cout << " 1: eq.29 , 2: eq.30 " << endl;
	cin >> temp2;
	
	cout << "Using equation 29" << endl;
	cout << "Choose the mass of an ALP" << endl;
	cout << "1: 10 GeV, 2: 80 GeV, 3: 350 GeV" << endl;
	cout << "=================================" << endl;
	cin >> temp1;
	
	switch (temp2) {

	case 1 : 	if(temp1 ==1){
				malp = 1.000000e+01;}
			else if(temp1 == 2){
				malp = 8.000000e+01;}
			else malp = 3.500000e+02;
		
			cout << "Summary of Decay Width for the Process ALP > u u~" << endl;
		        cout << "================================================" << endl;
		
		        decayWidth = decayRate29(malp);
		
		        cout << "Decay Width = " << decayWidth << " GeV " << endl;
		        cout << "================================================" << endl;
			break;

	case 2 :	if(temp1 ==1){
                                malp = 1.000000e+01;}
                        else if(temp1 == 2){
                                malp = 8.000000e+01;}
                        else malp = 3.500000e+02;

			cout << "Summary of Decay Width for the Process ALP > u u~" << endl;
                        cout << "================================================" << endl;
			decayWidth = decayRate30(malp);

                        cout << "Decay Width = " << decayWidth << " GeV " << endl;
                        cout << "================================================" << endl;
                        break;
	
	}
}




double decayRate29(double malp)
{
	cout << "Which coupling you want to turn on ? " << endl;
	cout << " 1: Cu, 2: Cgg , 3: both " << endl;
	int k;
	cin >> k;

	double Cu,Cgg;

	if(k==1){        
		Cu = 1.000000e+00;
		Cgg = 0.0000000e+00;}
	else if(k==2){
		int m;
		cout << "To Set Cgg = 1 press 0 and to set Cgg = 1/4phi press any integer number other than zero" <<endl;
		cin >> m;
		if(m==0){
			Cu = 0.000000e+00;
        		Cgg = 1.0000000e+00;}
		else{
			Cu = 0.000000e+00;
                        Cgg = 8.0000000e-02;}
		}
	else{
		Cu = 1.000000e+00;
        	Cgg = 1.0000000e+00;}

        const double lembda= 1.000000e+03;
        const int n= 1; //only one flavor is used
	double alpha;
	double DR;

	if(malp==1.000000e+01){
		alpha = 0.179;}
	else if(malp == 8.000000e+01){
		alpha = 0.121;}
	else alpha =  0.099;


	DR= ((32*M_PI*pow(alpha,2)*pow(malp,3))/pow(lembda,2))*(1+((97/4)-(7*n/6))*(alpha/M_PI))*abs(pow((Cgg+(Cu*n)/32*M_PI*M_PI),2));
	
      
	return DR;

}

double decayRate30(double malp)
{
	const double lembda= 1.000000e+03;
	const double mu= 0.0022;
	const double cuu= 1.000000e+00;
	double DR;

	DR =((3*malp*pow(mu,2)*pow(cuu,2))/(8*M_PI*pow(lembda,2)))*(sqrt(1-(4*pow(mu,2))/(pow(malp,2))));
	
	return DR;
}
