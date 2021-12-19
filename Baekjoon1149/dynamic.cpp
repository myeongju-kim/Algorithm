#include <stdio.h>
#define MIN(X,Y) ((X<Y) ? X : Y)
​

int main(void) {
	int n;
	int R, G, B;
	int R_Min = 0, G_Min = 0, B_Min = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &R, &G, &B);
		R += MIN(G_Min, B_Min);
		G += MIN(R_Min, B_Min);
		B += MIN(R_Min, G_Min);
		R_Min = R;
		G_Min = G;
		B_Min = B;
	}
	printf("%d", MIN(R_Min, MIN(G_Min, B_Min)));
	return 0;

}