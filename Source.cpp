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
	
	cout << "Вы добавили клиента №" << id_user+1 << " на " << info[id_user][0] << " часов. Итог: " << info[id_user][1] << endl;
	id_user++;
	menu();
}

void menu() {
	int num;

	cout << "Приветсвуем Вас в программе оплаты парковки!\n" << endl;
	cout << "Выберите нужный вам пункт меню:"  << endl;
	cout << "\t1 - зарегистрировать клиента" <<  endl;
	cout << "\t2 - вывести общий доход" <<  endl;

	cin >> num;

	if (num == 1)
	{
		if (id_user + 1 == 4)
		{
			system("cls");
			cout << "Ошибка! Максимально 3 клиента." << endl;
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
			cout << "Ошибка! Вы еще не добавили клиентов." << endl;
			menu();
		}
		system("cls");
		showItog();
	}
	else
	{
		system("cls");
		cout << "Ошибка! Выберите верный пункт меню." << endl;
		menu();
	}

}
void showItog()
{
	double max_time = 0, max_price = 0;
	cout << "Автомобиль\tЧасы\tПлата\n";
	for (int i = 0; i < 3; i++)
	{
		cout << i+1 << "\t\t" << info[i][0] << "\t" << info[i][1] << "\n";
		max_time += info[i][0];
		max_price += info[i][1];
	}
	cout << "Итого" << "\t\t" << max_time << "\t" << max_price << endl;
	system("pause");
	
	system("cls");
	menu();
}
void addClient() {
	int num;
	bool status = false;
	double time = 0;
	cout << "Вы желаете добавить клиента?" <<  endl;
	cout << "\t1 - да"  << endl;
	cout << "\t2 - нет"  << endl;
	cin >> num;

	if (num == 1)
	{
		system("cls");
		while (!status)
		{
			cout << "Введите насколько хотите припарковать автомобиль(от 1 до 24 часов):";
			cin >> time;

			if (time < 1 || time > 24)
			{
				status = false;
				system("cls");
				cout << "Ошибка! Часы от 1 до 24!" << endl;
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
		cout << "Ошибка! Выберите верный пункт меню." << endl;
		addClient();
	}
}