#include <stdio.h>

int main()
{
	int a[5] = {10, 13, 11, 20, 25};
	int i, l;
	int d[20];
	for (l = 0; l < 20; l++){
 		d[l] = 0;
 	}
	l = 0;
	printf("Десятичные числа: ");
	for(i=0;i<5;i++){
		printf("%d ", a[i]);	
	}
	printf("\nДвочные числа: ");
	for(i=0;i<5;i++){
		while(a[i] != 0){
			if (a[i] % 2 == 0){
				a[i] = a[i] / 2;
				d[l] = 0;
			}
			else {
				a[i] = a[i]/ 2;
				d[l] = 1;
			}
			l++;
		}
		l = l - 1;
		for(;l >= 0;l--){
			printf("%d", d[l]);
		}
		printf(" ");
		for (l = 0; l < 20; l++){
 			d[l] = 0;
 		}
		l = 0;
		
	}
return(0);
}
