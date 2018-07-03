#include<stdio.h>
int main() {
	int t;
	long int n, k, power;
	char s[100005];

	long int i, steps, rem_steps;

	scanf("%d", &t);
	while(t--) {
		scanf("%ld%ld", &n, &k);
		fflush(stdin);
		scanf("%s", s);
		rem_steps =  n - k;
		power = 0;

		// first step
		for(i = 1; i < k; i++) {
			if (s[i-1] != s[i]) {
				power += ((rem_steps > i) ? i : rem_steps);
			}
		}

		// all other steps
		for(i = k; i < n; i++) {
			if (s[i-1] != s[i]) {
				power += ((rem_steps > k) ? k : rem_steps);
			}		
			rem_steps--;
		}

		printf("%ld\n", power);
	}
	return 0;
}