#include<stdio.h>
int main() {
	int t;
	long int l, r, count;
	long int i;
	scanf("%d", &t);
	while(t--) {
		scanf("%ld%ld", &l, &r);
		count = 0;
		for(i=l; i<=r; i++) {
			// printf("%ld %ld\n", i, !i%2);
			if (i%10 == 2 || i%10 == 3 || i%10 == 9) {
				// printf("%ld", i);
				count++;
			}
		}
		printf("%ld ", count);
	}
	return 0;
}