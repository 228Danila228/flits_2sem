#include <stdio.h>

int main(){
	int i, l, n;
	int d[20];
	for (l = 0; l < 20; l++){
		d[l] = 0;
		}
	printf("Введите число десятичных чисел: ");
	scanf("%d", &n);
	int a[n];
	int s = 0;
	n--;
	for(;n >= 0;n--){
		scanf("%d", &a[n]);
		s++;
		}
	l = 0;
	printf("Десятичные числа: ");
	for(i=0;i<s;i++){
		printf("%d ", a[i]);
		}
	printf("\nДвочные числа: ");
	for(i=0;i<s;i++){
		while(a[i] != 0){
			if (a[i] % 2 == 0){
				d[l] = 0;
				}
			else {
				d[l] = 1;
				}
			a[i] = a[i]/ 2;
			l++;
			}
		l--;
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
