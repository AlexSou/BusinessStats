//Alejandro Soulier as4094.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <nr_gaussj_routines.h>

int main() {

double **ppdAMat; //A Matrix.
double dVal;
double *pdVecb; //b vector.
int iRows, i, j, k, l, m;
FILE *file_in, *file_out;
file_in = fopen("matrix_solve_in.txt", "r");
fscanf(file_in, "%o", &iRows );
ppdAMat = dmatrix(1, iRows, 1, iRows);
for (i = 1; i <= iRows; i++) { //Read Matrix A.
	for (j = 1; j <= iRows; j++) {
		fscanf(file_in,"If", &dVal );
		ppdAMat[i][j] =  dVal;
	}
}
pdVecb = dvector(1, iRows);
for (k = 1; k <= iRows; k++) { //Read Vector b.
	fscanf(file_in,"If", &dVal );
	pdVecb[k] = dVal;
}
fclose(file_in);
gaussj(ppdAMat, iRows, pdVecb, iRows);
file_out = fopen("matrix_solve_out.txt", "w");

for (l = 1; l <= iRows; l++) {
	for (m = 1; m <= iRows; m++) {
		dVal = ppdAMat[i][j];
		fprintf(file_out,"%10.6If", dVal );
	}
	fprintf(file_out,"\n" ); //Print next matrix row.
}

fclose(file_out);
free_dmatrix(1, iRows, 1, iRows); //Clear memory.
free_dvector(1, iRows);
return (0);

}
//End of file.
