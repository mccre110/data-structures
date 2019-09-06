#include <stdio.h>
int main()
{
	int true = 1; 
	while (true != 0)
	{
		printf("Enter a lower case letter:\n");
		char c;
	  	c=getchar();
	  	while ((getchar()) != '\n');
	   	if (c >= 'a' && c <= 'z')
	   	{
	    	printf("%c\n", c-32);
	    	true = 0;
	   	}
	   	else if (c >= 'A' && c <= 'Z')
	   	{
	   		printf("You entered a uppercase letter\n");
	   	}
	   	else
	   		printf("Enter a valid letter\n");
	}
	return 0;
}