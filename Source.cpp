#include <iostream>
using namespace std;

void calculateCharges(double time);
void menu();
void addClient();
void showItog();

double info[3][2];
int id_user = 0;

void main() {
	setlocale(LC_ALL, "rus");
	menu();
}

void calculateCharges(double time) {
	
	if (time < 3.0)
	{
		info[id_user][0] = round(time);
		info[id_user][1] = 2.0;
	}
	else
	{
		if (time == 24)
		{
			info[id_user][0] = 24;
			info[id_user][1] = 10.0;
		}
		else
		{
			info[id_user][0] = round(time);
			info[id_user][1] = 2.0 + ((round(time)-3.0) * 0.5);
		}
		
	}
	
	cout << "�� �������� ������� �" << id_user+1 << " �� " << info[id_user][0] << " �����. ����: " << info[id_user][1] << endl;
	id_user++;
	menu();
}

void menu() {
	int num;

	cout << "����������� ��� � ��������� ������ ��������!\n" << endl;
	cout << "�������� ������ ��� ����� ����:"  << endl;
	cout << "\t1 - ���������������� �������" <<  endl;
	cout << "\t2 - ������� ����� �����" <<  endl;

	cin >> num;

	if (num == 1)
	{
		if (id_user + 1 == 4)
		{
			system("cls");
			cout << "������! ����������� 3 �������." << endl;
			menu();
		}
		system("cls");
		addClient();
	}
	else if (num == 2)
	{
		if (id_user == 0)
		{
			system("cls");
			cout << "������! �� ��� �� �������� ��������." << endl;
			menu();
		}
		system("cls");
		showItog();
	}
	else
	{
		system("cls");
		cout << "������! �������� ������ ����� ����." << endl;
		menu();
	}

}
void showItog()
{
	double max_time = 0, max_price = 0;
	cout << "����������\t����\t�����\n";
	for (int i = 0; i < 3; i++)
	{
		cout << i+1 << "\t\t" << info[i][0] << "\t" << info[i][1] << "\n";
		max_time += info[i][0];
		max_price += info[i][1];
	}
	cout << "�����" << "\t\t" << max_time << "\t" << max_price << endl;
	system("pause");
	
	system("cls");
	menu();
}
void addClient() {
	int num;
	bool status = false;
	double time = 0;
	cout << "�� ������� �������� �������?" <<  endl;
	cout << "\t1 - ��"  << endl;
	cout << "\t2 - ���"  << endl;
	cin >> num;

	if (num == 1)
	{
		system("cls");
		while (!status)
		{
			cout << "������� ��������� ������ ������������ ����������(�� 1 �� 24 �����):";
			cin >> time;

			if (time < 1 || time > 24)
			{
				status = false;
				system("cls");
				cout << "������! ���� �� 1 �� 24!" << endl;
			}
			else
			{
				system("cls");
				calculateCharges(time);
				status = true;
			}

		}

	}
	else if (num == 2)
	{
		system("cls");
		menu();
	}
	else
	{
		system("cls");
		cout << "������! �������� ������ ����� ����." << endl;
		addClient();
	}
}