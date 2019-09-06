#include <stdio.h>
int main()
{
	float fahr, celsius;
	int lower, upper, step;
	lower=200;
	upper=0; 
	step=10;
	fahr = lower;
	while (fahr>=upper)
	{
	    celsius=(5.0/9.0)*(fahr- 32.0);    
	    printf("%3.0f %6.2f \n", fahr, celsius);
	    fahr= fahr - step; 
	}
	return 0;
}