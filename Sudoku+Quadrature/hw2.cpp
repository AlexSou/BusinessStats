//============================================================================
// Name        : hw2.cpp
// Author      : Alejandro Soulier as4094
// Description : Output answer of integration to a file.
//============================================================================

#include <iostream>
#include "quadrature.h"
#include "nr3.h"
#include <math.h>
using namespace std;



Doub funct(Doub x) //Output function to integrate.
{
	Doub a, b;
	a = 2.0;
	b = 10.0;
	return a/x + b*x*x - (exp(x)/sqrt(x));
}

//Return absolute value of 2 doubles.
Doub absVal(Doub ans, Doub realVal) {
	Doub diff;
	diff = ans - realVal;
	if(diff < 0){
		diff = diff * -1.0;
	}
	return diff;
}

//Main procedure.
int main() {

	Doub outDiff, x0, x1, realVal;
	int  dP;
	x0 = 1.0;
	x1 = 5.0;
	realVal = 342.681288444693835;
	Doub eps = 1.0e-10;
	int lvlPrecision = 11;
	double ppdQtrapMat[lvlPrecision][2];
	double ppdQsimpMat[lvlPrecision][2];
	ofstream outTrap, outTrapSimp;
	clock_t start, end;
	double cpuTime;

	//Create matrix with qtrap.
	for (int n = 1; n < lvlPrecision; n ++){
		start = clock();
		dP = -1*n;
		eps = 1.0 * pow(10.0,dP);
		ppdQtrapMat[n][1] = qtrap(funct, x0, x1, eps);
		end = clock();
		cpuTime= (end-start);
		ppdQtrapMat[n][0] = cpuTime;
	}

	//Create matrix with qsimp.
	for (int i = 1; i < lvlPrecision; i ++){
		start = clock();
		dP = -1*i;
		eps = 1.0 * pow(10.0,dP);
		ppdQsimpMat[i][1] = qsimp(funct, x0, x1, eps);
		end = clock();
		cpuTime= (end-start);
		ppdQsimpMat[i][0] = cpuTime;
	}

	//Write to a file.
	outTrap.open("Qtrap.txt");
	if( !outTrap ) {
		cerr << "Error" << endl;
		exit(1);
	}
	outTrap.precision(20);
	for(int j = 1; j < lvlPrecision; j++) {
		outDiff = log(absVal(ppdQtrapMat[j][1], realVal));
		outTrap << outDiff << " " << ppdQtrapMat[j][0] << endl;
	}
	outTrap.close();

	outTrapSimp.open("Qsimp.txt");
	if( !outTrapSimp ) {//Error writing to file.
		cerr << "Error" << endl;
		exit(1);
	}
	outTrapSimp.precision(20);
	for(int k = 1; k < lvlPrecision; k++) {
		outDiff = log(absVal(ppdQsimpMat[k][1], realVal));
		outTrapSimp << outDiff << " " << ppdQsimpMat[k][0] << endl;
	}
	outTrapSimp.close();

	return 0;
}
//End of file.
