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
			printf("\nВыберите действие:\n1 - Найти сумму чисел\n2 - Найти разность чисел\n3 - Найти произведение чисел\n4 - Найти разность чисел\n5 - Объединить две строки\n6 - Преобразовать число в строку и строку в число\n7 - Нахождение длины отрезка по координатам двух точек\n8 - Проверка существования треугольника и нахождение периметра и площади\n9 - Завершить работу программы\n");
			scanf_s("%d", &nomer);
			if (nomer == 1 || nomer == 2 || nomer == 3 || nomer == 4 || nomer == 5 || nomer == 6 || nomer == 7 || nomer == 8 || nomer == 9) {
				break;
			}
			else
			{
				system("cls");
				printf("Введены некоректнные данные!!! Повторите ввод!");
			}
		}
		if (nomer == 1) {
			system("cls");
			int a, b;
			printf("Введите первое число: ");
			scanf_s("%d", &a);
			printf("Введите второе число: ");
			scanf_s("%d", &b);
			printf("Сумма элементов: %d\n", Summ(a, b));
			system("pause");
			system("cls");
		}
		if (nomer == 2) {
			system("cls");
			int a, b;
			printf("Введите первое число: ");
			scanf_s("%d", &a);
			printf("Введите второе число: ");
			scanf_s("%d", &b);
			printf("Разность элементов: %d\n", Rasn(a, b));
			system("pause");
			system("cls");
		}
		if (nomer == 3) {
			system("cls");
			int a, b;
			printf("Введите первое число: ");
			scanf_s("%d", &a);
			printf("Введите второе число: ");
			scanf_s("%d", &b);
			printf("Произведение элементов: %d\n", Prois(a, b));
			system("pause");
			system("cls");
		}
		if (nomer == 4) {
			system("cls");
			int a, b;
			printf("Введите первое число: ");
			scanf_s("%d", &a);
			printf("Введите второе число: ");
			scanf_s("%d", &b);
			printf("Частное элементов: %3.2f\n", Chast(a, b));
			system("pause");
			system("cls");
		}
		if (nomer == 5) {
			system("cls");
			char* a = "строка ";
			char* b = "символ";
			printf("%s\n", unification(a, b));
			system("pause");
			system("cls");
		}
		if (nomer == 6) {
			system("cls");
			char* s = "159243";
			int num = ConvertToInt(s);
			printf("Число: %d", num);
			char* str = ConvertToString(num);
			printf("\nСтрока: %s\n", str);
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

// Соединение двух строк в одну
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

// Преобразования строки в число
int ConvertToInt(char* s)
{
	int number = 0;
	int sign = 0; // знак числа числа 0 - положительное, 1 — отрицательное
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

// Функция преобразования числа в строку
char* ConvertToString(int a)
{
	int i = 0, k, l1 = 0;
	int sign = 0; // знак числа 0 - положительное, 1 — отрицательное
	if (a < 0)
	{
		sign = 1;
		a = -a;
		l1++;
	}
	int n1 = a;
	while (a > 0) // Определение колличества элементов для строки
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

void GetDlinaOtr() // Нахождение длины отрезка по введённым координатам
{
	int x1, y1, x2, y2;
	printf("Есть две точки A(x1; y1) и B(x2; y2)\n");
	printf("Введите x1: ");
	scanf_s("%d", &x1);
	printf("Введите y1: ");
	scanf_s("%d", &y1);
	printf("Введите x2: ");
	scanf_s("%d", &x2);
	printf("Введите y2: ");
	scanf_s("%d", &y2);
	float dl = GetDlina(x1, y1, x2, y2);
	printf("Длина отрезка: %f\n", dl);
}


void GetPerPlosh() // Проверка треугольника и нахождение его периметра и площади
{
	int x1, y1, x2, y2, x3, y3; // 4  7 4 2 5 6
	printf("Введите точки треугольника A(x1; y1), B(x2; y2), C(x3, y3)\n");
	printf("Введите x1: ");
	scanf_s("%d", &x1);
	printf("Введите y1: ");
	scanf_s("%d", &y1);
	printf("Введите x2: ");
	scanf_s("%d", &x2);
	printf("Введите y2: ");
	scanf_s("%d", &y2);
	printf("Введите x3: ");
	scanf_s("%d", &x3);
	printf("Введите y3: ");
	scanf_s("%d", &y3);
	float a = GetDlina(x1, y1, x2, y2);
	float b = GetDlina(x1, y1, x3, y3);
	float c = GetDlina(x2, y2, x3, y3);
	int prov = GetProverka(a, b, c);
	if (prov == 0)
	{
		printf("Введённые точки не образуют треугольник!\n");
	}
	else
	{
		float P = a + b + c;
		printf("Периметр треугольника равен: %f\n", P);
		float p = P / 2;
		float S = sqrt(p * (p - a) * (p - b) * (p - c));
		printf("Площадь треугольника равна: %f\n", S);
	}
}

int GetProverka(float a, float b, float c) // Проверка существования треугольника
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