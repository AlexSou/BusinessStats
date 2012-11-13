/*
 * trinomial_call.c
 *Alejandro Soulier as4094
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <black_scholes_price.c>

//void trinomial_call(double *dTriVal,double dS,double dSigma,double dDivRate,double dIntRate,double dT,double dStrike,double dLambda, long int lStep) {
void main () {
	//
	double   dS = 100.0;
	double   dSigma = 0.25;
	double   dDivRate =0.02;
	double   dIntRate =0.06;
	double   dT = 0.75;
	double   dStrike =100.0;
	double   dLambda = sqrt(1.5);
	long int lStep = 3;
	int i, j, k, l, m, o, p;
	//

	double dDT, dPV, dU, dD, dP, dM, dQ, dP0, dM0, dQ0, dSwap, dTriVal;
	double *pdStockPri, *pdSwapVec, *pdTmp, *dPrice;
	FILE *file_out;
	dDT = dT/lStep;
	dPV = exp(-1 * dIntRate * dDT);
	dU = dLambda * dSigma * sqrt(dDT);
	dD = 1/dU;
	dP = 1/(2*pow(dLambda,2)) + (dIntRate-dDivRate-0.5*pow(dSigma,2))*sqrt(dT)/(2*dLambda*dSigma);
	dQ = 1/(2*pow(dLambda,2)) - (dIntRate-dDivRate-0.5*pow(dSigma,2))*sqrt(dT)/(2*dLambda*dSigma);
	dM = 1-dP-dQ;
	dP0 = dP * dPV;
	dM0 = dPV * dM;
	dQ0 = dPV * dQ;
	file_out = fopen("trinomial_results_1.txt", "w");
	pdStockPri = dvector(1,(lStep * 2 +1));
	pdSwapVec = dvector(1,(lStep * 2 +1));
	pdStockPri[0] = dS * pow(dU, lStep);
	for (i = 1; i <= (lStep * 2 +1); i++) {
		pdStockPri[i] = pdStockPri[i-1] * dD;
	}

	for (l = 1; l <= (lStep * 2 +1); l++) {
			fprintf(file_out,"%10.6If", pdStockPri[l] );

	}

	for (j = 1; j <= (lStep * 2 +1); j++) {
		dSwap = pdStockPri[j] - dS;
		if (dSwap > 0.0){
		pdSwapVec[j] = dSwap ;
		}
		else {
			pdSwapVec[j] = 0.0 ;
		}
	}
	pdTmp = pdStockPri;
	pdStockPri = pdSwapVec;
	pdSwapVec = pdTmp;
	m = lStep * 2 -1;
	p = 1;
	for (k = 1; k <= (lStep +1); k++) {
		o = p;
		for (l = 1; l <= m; l++) {
			pdSwapVec[o] = dP0* pdStockPri[o-1]+dM0*pdStockPri[o] * dQ0 * pdStockPri[o+1];
			o++;
		}
		m = m-2;
		p++;
		pdTmp = pdStockPri;
		pdStockPri = pdSwapVec;
		pdSwapVec = pdTmp;
	}

	dTriVal = pdStockPri[lStep];


	free_dvector(pdStockPri, 1,(lStep * 2 +1) );
	free_dvector(pdSwapVec, 1,(lStep * 2 +1) );
}

BlackScholesCall(*dPrice, dS, dSigma, dDivRate, dT, dStrike);
fprintf(file_out,"%10.6If", dTriVal );
for (l = 1; l <= (lStep * 2 +1); l++) {
		fprintf(file_out,"%10.6If", dPrice[l] );

}



fclose(file_out);
{



