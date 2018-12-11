#include <stdio.h>
#include <string.h>

int main()
{
	char str[10] = "abc\0def";
	char dstr[10];
	strcpy(dstr, str);
	printf("dstr = %s\n", dstr);
	char str1[] = "abc";
	char dst1[100] = "Abcdef";
	if (str1 > dst1) {
		printf("[%s] > [%s]\n", str1, dst1);
	}else if (str1 < dst1) {
		printf("[%s] < [%s]\n", str1, dst1);
	}else {
		printf("[%s] == [%s]\n", str1, dst1);
	}
	/*字符串的追加*/
	char str2[] = "abcde";
	char str3[] = "figk";
	strcat(str2, str3);
	printf("str2 = %s\n", str2);
	strncat(str2, str3, 2);
	printf("str2_str3+2 = %s\n", str2);
	return 0;
}