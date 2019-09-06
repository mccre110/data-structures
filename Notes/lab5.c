#include <stdio.h> 
void swap(int *a, int *b) 
{ 
	int ab = *a;
	int ba = *b;
	*a =ba;
	*b = ab;
}
// void swap1(int a, int b) 
// { 
// 	int ab = a;
// 	int ba = b;
// 	a =ba;
// 	b = ab;
// }
int main() 
{
	int x=10;
	int y=5; 
	printf("x = %d before function call_by_reference.\n", x);
	printf("y = %d before function call_by_reference.\n", y); 
	swap1(x,y); 
	printf("x = %d after function call_by_reference.\n", x);
	printf("y = %d after function call_by_reference.\n", y);  
	return 0; 
} 
