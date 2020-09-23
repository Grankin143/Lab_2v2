#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "Windows.h"

struct lek {
	int amount, year, month, day;
	double price;
	char name[100];
	char mass[100];
};

struct apteka {
	int numOfMeds;
	char name[100];
	char num[100];
	struct lek lek[100];
};

void Init(struct apteka* apteka1, char name[], char num[], int numOfMeds, char Name_Med[][100], double Price_Med[], char Id_Med[][100], int amount[], int day[], int month[], int year[]) { // ������� �������������
	int i;
	strcpy(apteka1->name, name);
	strcpy(apteka1->num, num);
	apteka1->numOfMeds = numOfMeds;
	for (i = 0; i < numOfMeds; i++) {
		strcpy(apteka1->lek[i].name, Name_Med[i]);
		strcpy(apteka1->lek[i].mass, Id_Med[i]);
		apteka1->lek[i].price = Price_Med[i];
		apteka1->lek[i].amount = amount[i];
		apteka1->lek[i].day = day[i];
		apteka1->lek[i].month = month[i];
		apteka1->lek[i].year = year[i];
	}
}

void Read(struct apteka* apteka1) { // ������� �����
	int i, number;
	printf("\n������� �������� ������: ");
	fflush(stdin);
	gets(apteka1->name);
	printf("\n������� ����� ������: ");
	fflush(stdin);
	gets(apteka1->num);
	apteka1->numOfMeds = i = 0;
	printf("\n�������� ���������?1-��, 0-���: ");
	fflush(stdin);
	scanf("%d", &number);
	while (number == 1) {
		printf("\n������� �������� ���������: ");
		fflush(stdin);
		gets(apteka1->lek[apteka1->numOfMeds].name);
		printf("\n������� ��� ���������: ");
		fflush(stdin);
		gets(apteka1->lek[apteka1->numOfMeds].mass);
		do {
			printf("\n������� ���-�� ���������: ");
			fflush(stdin);
			scanf("%d", &apteka1->lek[apteka1->numOfMeds].amount);
		} while (apteka1->lek[apteka1->numOfMeds].amount < 0);
		printf("\n������� ���� ��������� (00.00.0000): ");
		do {
			printf("������� ����: ");
			scanf("%d", &apteka1->lek[apteka1->numOfMeds].day);
		} while (apteka1->lek[apteka1->numOfMeds].day < 0 || apteka1->lek[apteka1->numOfMeds].day > 30);
		do {
			printf("������� �����: ");
			scanf("%d", &apteka1->lek[apteka1->numOfMeds].month);
		} while (apteka1->lek[apteka1->numOfMeds].month < 0 || apteka1->lek[apteka1->numOfMeds].month > 12);
		do {
			printf("������� ���: ");
			scanf("%d", &apteka1->lek[apteka1->numOfMeds].year);
		} while (apteka1->lek[apteka1->numOfMeds].year < 2010 || apteka1->lek[apteka1->numOfMeds].year > 2020);
		do {
			printf("\n������� ���� ���������: ");
			fflush(stdin);
			scanf("%lf", &apteka1->lek[apteka1->numOfMeds].price);
		} while (apteka1->lek[apteka1->numOfMeds].price < 0);
		apteka1->numOfMeds++;
		printf("�������� ��� ���������? 1-��, 0-���: ");
		fflush(stdin);
		scanf("%d", &number);
	}
}

void Display(struct apteka apteka1) { // ������� ������
	int i;
	printf("\n�������� ������: %s\n", apteka1.name);
	printf("����� ������: %s\n", apteka1.num);
	printf("���-�� ��������: %d\n", apteka1.numOfMeds);
	for (i = 0; i < apteka1.numOfMeds; i++) {
		printf("\n��������� %d\n", i + 1);
		printf("��� ���������: %s\n", apteka1.lek[i].mass);
		printf("�������� ���������: %s", apteka1.lek[i].name);
		printf("\n����: %d.%d.%d\n", apteka1.lek[i].day, apteka1.lek[i].month, apteka1.lek[i].year);
		printf("���� ����-��: %lf\n", apteka1.lek[i].price);
		printf("����������� ���������: %d\n", apteka1.lek[i].amount);
	}
}

void Add(struct apteka* apteka1) { //������� ���������� ������ ���-��
	printf("\n������� �������� ������ ���������: ");
	fflush(stdin);
	gets(apteka1->lek[apteka1->numOfMeds].name);
	printf("\n������� ��� ������ ���������: ");
	fflush(stdin);
	gets(apteka1->lek[apteka1->numOfMeds].mass);
	do {
		printf("\n������� ���� ������ ���������: ");
		fflush(stdin);
		scanf("%lf", &apteka1->lek[apteka1->numOfMeds].price);
	} while (apteka1->lek[apteka1->numOfMeds].price < 0);
	do {
		printf("\n������� ���-�� ���������: ");
		fflush(stdin);
		scanf("%d", &apteka1->lek[apteka1->numOfMeds].amount);
	} while (apteka1->lek[apteka1->numOfMeds].amount < 0);
	printf("\n������� ���� ��������� (00.00.0000)\n");
	do {
		printf("������� ����: ");
		scanf("%d", &apteka1->lek[apteka1->numOfMeds].day);
	} while (apteka1->lek[apteka1->numOfMeds].day < 0 || apteka1->lek[apteka1->numOfMeds].day > 30);
	do {
		printf("������� �����: ");
		scanf("%d", &apteka1->lek[apteka1->numOfMeds].month);
	} while (apteka1->lek[apteka1->numOfMeds].month < 0 || apteka1->lek[apteka1->numOfMeds].month > 12);
	do {
		printf("������� ���: ");
		scanf("%d", &apteka1->lek[apteka1->numOfMeds].year);
	} while (apteka1->lek[apteka1->numOfMeds].year < 2010 || apteka1->lek[apteka1->numOfMeds].year > 2020);
	apteka1->numOfMeds++;
}

void SortDate(struct apteka* apteka1, int day[], int month[], int year[], char mass[], int number) { // ������� ����� �� ����
	int i;
	if (number == 1) {
		for (i = 0; i < apteka1->numOfMeds; i++) {
			printf("\n�������� ���-��     ����� ������     ����");
			if (apteka1->lek[i].day >= day[0])
			{
				if (apteka1->lek[i].month >= month[0]) {
					if (apteka1->lek[i].year >= year[0]) {
						printf("\n%s              %s            %d.%d.%d\n", apteka1->lek[i].name, mass, apteka1->lek[i].day, apteka1->lek[i].month, apteka1->lek[i].year);
					}
				}
			}
		}
	}
	else if (number == 2) {
		for (i = 0; i < apteka1->numOfMeds; i++) {
			printf("\n�������� ���-��     ����� ������     ����");
			if (apteka1->lek[i].day <= day[0])
			{
				if (apteka1->lek[i].month <= month[0]) {
					if (apteka1->lek[i].year <= year[0]) {
						printf("\n%s              %s             %d.%d.%d\n", apteka1->lek[i].name, mass, apteka1->lek[i].day, apteka1->lek[i].month, apteka1->lek[i].year);
					}
				}
			}
		}
	}
}

void ChangePrice(struct apteka* apteka1, char mass[], double price) { // ������� ��������� ���� ���-��
	int i;
	for (i = 0; i < apteka1->numOfMeds; i++) {
		if (strcmp(apteka1->lek[i].mass, mass) == 0) {
			apteka1->lek[i].price = price;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	struct apteka apteka1, *apteka2;
	int number, numOfMeds, amount[100], day2[100], month2[100], year2[100];
	double Price_Med[100], price;
	char mass[100], name[100], num[100], Name_Med[100][100], Id_Med[100][100];
	printf("\n������������ ���������� (������� 1) ��� ��������� (������� 2): ");
	fflush(stdin);
	scanf("%d", &number);
	if (number == 1) {
		printf("\n������� 1 ��� ������������� ��� ������� 2 ��� ����� ������: ");
		scanf("%d", &number);
		if (number == 2) {
			Read(&apteka1);
		}
		else {
			printf("\n������� �������� ������: ");
			fflush(stdin);
			gets(name);
			printf("\n������� ����� ������: ");
			fflush(stdin);
			gets(num);
			numOfMeds = 0;
			printf("\n�������� ���������? 1-��, 0-���: ");
			fflush(stdin);
			scanf("%d", &number);
			while (number == 1) {
				printf("\n������� �������� ���������: ");
				fflush(stdin);
				gets(Name_Med[numOfMeds]);
				printf("\n������� ��� ���������: ");
				fflush(stdin);
				gets(Id_Med[numOfMeds]);
				do {
					printf("\n������� ���-�� ���������: ");
					fflush(stdin);
					scanf("%d", &amount[numOfMeds]);
				} while (amount[numOfMeds] < 0);
				printf("\n������� ���� ��������� (00.00.0000)\n");
				do {
					printf("������� ����: ");
					scanf("%d", &day2[numOfMeds]);
				} while (day2[numOfMeds] < 0 || day2[numOfMeds] > 30);
				do {
					printf("������� �����: ");
					scanf("%d", &month2[numOfMeds]);
				} while (month2[numOfMeds] < 0 || month2[numOfMeds] > 12); 
				do {
					printf("������� ���: ");
					scanf("%d", &year2[numOfMeds]);
				} while (year2[numOfMeds] < 2010 || year2[numOfMeds] > 2020);
				do {
					printf("\n������� ���� ���������: ");
					fflush(stdin);
					scanf("%lf", &Price_Med[numOfMeds]);
				} while (Price_Med[numOfMeds] < 0);
				numOfMeds++;
				printf("\n�������� ��� ���������? 1-��, 0-���: ");
				scanf("%d", &number);
			}
			Init(&apteka1, name, num, numOfMeds, Name_Med, Price_Med, Id_Med, amount, day2, month2, year2);
		}
		while (number != 5) {
			printf("\n������� ����� ���������� ��������:\n");
			printf("1 - ���������� � ������\n");
			printf("2 - �������� ����� ���������\n");
			printf("3 - �������� ���� ���������\n");
			printf("4 - �������� �� ����\n");
			printf("5 - �����\n");
			scanf("%d", &number);
			if (number == 1) {
				Display(apteka1);
			}
			else if (number == 2) {
				Add(&apteka1);
			}
			else if (number == 3) {
				printf("\n������� ��� ���������: ");
				fflush(stdin);
				gets(mass);
				do {
					printf("\n������� ����� ���� ���������: ");
					fflush(stdin);
					scanf("%lf", &price);
				} while (price < 0);
				ChangePrice(&apteka1, mass, price);
			}
			else if (number == 4) {
				do {
					printf("������� ����: ");
					scanf("%d", &day2[numOfMeds]);
				} while (day2[numOfMeds] < 0 || day2[numOfMeds] > 30);
				do {
					printf("������� �����: ");
					scanf("%d", &month2[numOfMeds]);
				} while (month2[numOfMeds] < 0 || month2[numOfMeds] > 12);
				do {
					printf("������� ���: ");
					scanf("%d", &year2[numOfMeds]);
				} while (year2[numOfMeds] < 2010 || year2[numOfMeds] > 2020);
				printf("\n������� 1 (��� ������ �������� ������ �������� ����) ��� 2 (������ �������� ����): ");
				fflush(stdin);
				scanf("%d", &number);
				SortDate(&apteka1, day2, month2, year2, num, number);
			}
		}
	}
	else {
		apteka2 = (struct apteka*)malloc(sizeof(apteka));
		printf("\n������� 1 ��� ������������� ��� ������� 2 ��� ����� ������: ");
		scanf("%d", &number);
		if (number == 2) {
			Read(&apteka1);
		}
		else {
			printf("\n������� �������� ������: ");
			fflush(stdin);
			gets(name);
			printf("\n������� ����� ������: ");
			fflush(stdin);
			gets(num);
			numOfMeds = 0;
			printf("\n�������� ���������? 1-��, 0-���: ");
			fflush(stdin);
			scanf("%d", &number);
			while (number == 1) {
				printf("\n������� �������� ���������: ");
				fflush(stdin);
				gets(Name_Med[numOfMeds]);
				printf("\n������� ��� ���������: ");
				fflush(stdin);
				gets(Id_Med[numOfMeds]);
				do {
					printf("\n������� ���-�� ���������: ");
					fflush(stdin);
					scanf("%d", &amount[numOfMeds]);
				} while (amount[numOfMeds] < 0);
				do {
					printf("������� ����: ");
					scanf("%d", &day2[numOfMeds]);
				} while (day2[numOfMeds] < 0 || day2[numOfMeds] > 30);
				do {
					printf("������� �����: ");
					scanf("%d", &month2[numOfMeds]);
				} while (month2[numOfMeds] < 0 || month2[numOfMeds] > 12);
				do {
					printf("������� ���: ");
					scanf("%d", &year2[numOfMeds]);
				} while (year2[numOfMeds] < 2010 || year2[numOfMeds] > 2020);
				do {
					printf("\n������� ���� ���������: ");
					fflush(stdin);
					scanf("%lf", &Price_Med[numOfMeds]);
				} while (Price_Med[numOfMeds] < 0);
				numOfMeds++;
				printf("\n�������� ��� ���������? 1-��, 0-���: ");
				scanf("%d", &number);
			}
			Init(&apteka1, name, num, numOfMeds, Name_Med, Price_Med, Id_Med, amount, day2, month2, year2);
		}
		while (number != 5) {
			printf("\n������� ����� ���������� ��������:\n");
			printf("1 - ���������� � ������\n");
			printf("2 - �������� ����� ���������\n");
			printf("3 - �������� ���� ���������\n");
			printf("4 - �������� �� ����\n");
			printf("5 - �����\n");
			scanf("%d", &number);
			if (number == 1) {
				Display(apteka1);
			}
			else if (number == 2) {
				Add(&apteka1);
			}
			else if (number == 3) {
				printf("\n������� ��� ���������: ");
				fflush(stdin);
				gets(mass);
				do {
					printf("\n������� ����� ���� ���������: ");
					fflush(stdin);
					scanf("%lf", &price);
				} while (price < 0);
				ChangePrice(apteka2, mass, price);
			}
			else if (number == 4) {
				do {
					printf("������� ����: ");
					scanf("%d", &day2[numOfMeds]);
				} while (day2[numOfMeds] < 0 || day2[numOfMeds] > 30);
				do {
					printf("������� �����: ");
					scanf("%d", &month2[numOfMeds]);
				} while (month2[numOfMeds] < 0 || month2[numOfMeds] > 12);
				do {
					printf("������� ���: ");
					scanf("%d", &year2[numOfMeds]);
				} while (year2[numOfMeds] < 2010 || year2[numOfMeds] > 2020);
				printf("\n������� 1 (��� ������ �������� ������ �������� ����) ��� 2 (������ �������� ����): ");
				fflush(stdin);
				scanf("%d", &number);
				SortDate(apteka2, day2, month2, year2, num, number);
			}
		}
		free(apteka2);
	}
	return 0;
}