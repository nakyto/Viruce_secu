#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#define GNUPLOT "gnuplot -persist"
//#define GNUPLOT "cat"	// to test output
 

double theta30(double x){
  double out=3.0*sqrt(14.0)/4.0*(5.0/3.0*pow(cos(x),3)-cos(x));
  return out;
}

int main(int argc, char **argv)
{

    double theta;
    double x1,y1;

	FILE *gp;
	gp = popen(GNUPLOT, "w");	/* 'gp' is the pipe descriptor */
	if (gp == NULL) {
		printf("Error opening pipe to GNU plot.\n"
			"Install with 'sudo apt-get install gnuplot'\n");
		exit(0);
	}
	// write your gnu-plot commands here

 
	fprintf(gp, "set style data filledcurves; plot '-' lt rgb 'red'\n");
	fprintf(gp, "-10 0\n"); // start there to fill red
	
	for(theta=0;theta<=2*M_PI;theta=theta+0.01){
        x1=theta30(theta)*theta30(theta)*cos(theta);
		y1=theta30(theta)*theta30(theta)*sin(theta);

		fprintf(gp,"%lf\t%lf\n",x1,y1);
	}
	fprintf(gp, "10 0\n");	// end here to fill
		
	fclose(gp);
}
