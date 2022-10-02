#include "Header.h"

#define kvadrat(a) pow(a,2)

//#define ax1 6
//#define ay1 5
//#define ax2 8
//#define ay2 3
//#define ax3 4
//#define ay3 6

#define GetDlina(yx1, yy1, yx2, yy2) sqrt(kvadrat(yx2 - yx1) + kvadrat(yy2 - yy1))

//#define a1 4
//#define b1 7
//#define c1 6

int main(void)
{
	system("chcp 1251>nul");
	while (1)
	{
		int nomer;
		while (1)
		{
			printf("\n�������� ��������:\n1 - ����� ����� �����\n2 - ����� �������� �����\n3 - ����� ������������ �����\n4 - ����� �������� �����\n5 - ���������� ��� ������\n6 - ������������� ����� � ������ � ������ � �����\n7 - ���������� ����� ������� �� ����������� ���� �����\n8 - �������� ������������� ������������ � ���������� ��������� � �������\n9 - ��������� ������ ���������\n");
			scanf_s("%d", &nomer);
			if (nomer == 1 || nomer == 2 || nomer == 3 || nomer == 4 || nomer == 5 || nomer == 6 || nomer == 7 || nomer == 8 || nomer == 9) {
				break;
			}
			else
			{
				system("cls");
				printf("������� ������������ ������!!! ��������� ����!");
			}
		}
		if (nomer == 1) {
			system("cls");
			int a, b;
			printf("������� ������ �����: ");
			scanf_s("%d", &a);
			printf("������� ������ �����: ");
			scanf_s("%d", &b);
			printf("����� ���������: %d\n", Summ(a, b));
			system("pause");
			system("cls");
		}
		if (nomer == 2) {
			system("cls");
			int a, b;
			printf("������� ������ �����: ");
			scanf_s("%d", &a);
			printf("������� ������ �����: ");
			scanf_s("%d", &b);
			printf("�������� ���������: %d\n", Rasn(a, b));
			system("pause");
			system("cls");
		}
		if (nomer == 3) {
			system("cls");
			int a, b;
			printf("������� ������ �����: ");
			scanf_s("%d", &a);
			printf("������� ������ �����: ");
			scanf_s("%d", &b);
			printf("������������ ���������: %d\n", Prois(a, b));
			system("pause");
			system("cls");
		}
		if (nomer == 4) {
			system("cls");
			int a, b;
			printf("������� ������ �����: ");
			scanf_s("%d", &a);
			printf("������� ������ �����: ");
			scanf_s("%d", &b);
			printf("������� ���������: %3.2f\n", Chast(a, b));
			system("pause");
			system("cls");
		}
		if (nomer == 5) {
			system("cls");
			char* a = "������ ";
			char* b = "������";
			printf("%s\n", unification(a, b));
			system("pause");
			system("cls");
		}
		if (nomer == 6) {
			system("cls");
			char* s = "159243";
			int num = ConvertToInt(s);
			printf("�����: %d", num);
			char* str = ConvertToString(num);
			printf("\n������: %s\n", str);
			system("pause");
			system("cls");
		}
		if (nomer == 7) {
			system("cls");
			GetDlinaOtr();
			system("pause");
			system("cls");
		}
		if (nomer == 8) {
			system("cls");
			GetPerPlosh();
			system("pause");
			system("cls");
		}
		if (nomer == 9) {
			break;
		}
	}
	return 0;
}

// ���������� ���� ����� � ����
char* unification(char* a, char* b)
{
	int l1 = 0, l2 = 0;
	while (a[l1] != '\0')
	{
		l1++;
	}
	while (a[l2] != '\0')
	{
		l2++;
	}
	char* c = calloc(l1 + l2, sizeof(char));
	for (int i = 0; i < l1; i++) {
		c[i] = a[i];
	}
	for (int i = 0; i < l2; i++) {
		c[i + l1] = b[i];
	}
	c[l1 + l2] = '\0';
	return c;
}

// �������������� ������ � �����
int ConvertToInt(char* s)
{
	int number = 0;
	int sign = 0; // ���� ����� ����� 0 - �������������, 1 � �������������
	int i = 0;
	if (s[0] == '-')
	{
		sign = 1;
		i++;
	}
	while (s[i] != '\0')
	{
		number = number + (s[i] & 0x0F);
		number = number * 10;
		i++;
	}
	number = number / 10;
	if (sign == 1)
	{
		number = -number;
	}
	return(number);
}

// ������� �������������� ����� � ������
char* ConvertToString(int a)
{
	int i = 0, k, l1 = 0;
	int sign = 0; // ���� ����� 0 - �������������, 1 � �������������
	if (a < 0)
	{
		sign = 1;
		a = -a;
		l1++;
	}
	int n1 = a;
	while (a > 0) // ����������� ����������� ��������� ��� ������
	{
		a = a / 10;
		l1++;
	}
	char* str1 = calloc(l1, sizeof(char));
	a = n1;
	while (a > 0)
	{
		k = a % 10;
		a = a / 10;
		str1[i] = k | 0x30;
		i++;
	}
	if (sign == 1)
	{
		str1[i] = '-';
		i++;
	}
	i--;
	char* str2 = calloc(l1, sizeof(char));
	while (i >= 0) {
		str2[a] = str1[i];
		i--; a++;
	}
	str2[a] = '\0';
	return(str2);
}

void GetDlinaOtr() // ���������� ����� ������� �� �������� �����������
{
	int x1, y1, x2, y2;
	printf("���� ��� ����� A(x1; y1) � B(x2; y2)\n");
	printf("������� x1: ");
	scanf_s("%d", &x1);
	printf("������� y1: ");
	scanf_s("%d", &y1);
	printf("������� x2: ");
	scanf_s("%d", &x2);
	printf("������� y2: ");
	scanf_s("%d", &y2);
	float dl = GetDlina(x1, y1, x2, y2);
	printf("����� �������: %f\n", dl);
}


void GetPerPlosh() // �������� ������������ � ���������� ��� ��������� � �������
{
	int x1, y1, x2, y2, x3, y3; // 4  7 4 2 5 6
	printf("������� ����� ������������ A(x1; y1), B(x2; y2), C(x3, y3)\n");
	printf("������� x1: ");
	scanf_s("%d", &x1);
	printf("������� y1: ");
	scanf_s("%d", &y1);
	printf("������� x2: ");
	scanf_s("%d", &x2);
	printf("������� y2: ");
	scanf_s("%d", &y2);
	printf("������� x3: ");
	scanf_s("%d", &x3);
	printf("������� y3: ");
	scanf_s("%d", &y3);
	float a = GetDlina(x1, y1, x2, y2);
	float b = GetDlina(x1, y1, x3, y3);
	float c = GetDlina(x2, y2, x3, y3);
	int prov = GetProverka(a, b, c);
	if (prov == 0)
	{
		printf("�������� ����� �� �������� �����������!\n");
	}
	else
	{
		float P = a + b + c;
		printf("�������� ������������ �����: %f\n", P);
		float p = P / 2;
		float S = sqrt(p * (p - a) * (p - b) * (p - c));
		printf("������� ������������ �����: %f\n", S);
	}
}

int GetProverka(float a, float b, float c) // �������� ������������� ������������
{
	if (a >= b + c)
	{
		return 0;
	}
	else if (b >= a + c)
	{
		return 0;
	}
	else if (c >= a + b)
	{
		return 0;
	}
	else {
		return 1;
	}
}