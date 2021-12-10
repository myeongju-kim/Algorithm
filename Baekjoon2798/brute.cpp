#include <stdio.h>

int main() {
	int n, m;
	int num[1000];
	int bf[100000];
	int index = 0;
	int max = 0;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int z = j + 1; z < n; z++) {
				bf[index] = num[i] + num[j] + num[z];
				index++;
			}
		}
	}
	for (int i = 0; i < index; i++) {
		if (m >= bf[i] && max <= bf[i])
			max = bf[i];
	}
	printf("%d", max);
	return 0;
}