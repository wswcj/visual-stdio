#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include<string.h>
int main()
{
	int i = 0;
	int n = 0;
	int sum = 1;
	int sum1 = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		sum *= i;
		sum1 += sum;
	}
	printf("%d\n", sum1);
	/*for (i = 1; i <= n; i++)
	{
		sum *= i;
	}
	printf("%d\n", sum);*/
	/*int ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch < '0' || ch>'9')
			continue;
		putchar(ch);
	}*/
	/*char password[20] = { 0 };
	int ret = 0;
	int ch = 0;
	scanf("%s", password);
	while ((ch = getchar()) != '\n')
	{
		;
	}
	ret = getchar();
	if (ret == 'Y')
		printf("Yes");
	if (ret == 'N')
		printf("no");*/
	return 0;
}