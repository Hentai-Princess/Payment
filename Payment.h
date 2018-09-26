#pragma once
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"

//подтип адрес 
class MyAddress {

	// проверка адреса на корректность
	bool CorrectAddress(int house, int flat, string &message) {
		if ((house > 100) || (house < 1) || (flat > 1000) || (flat < 1))
			{
				message = "Неверное задан адрес!";
				return false;
			}
	}

public:
	//дом
	int house;
	//квартира
	int flat;

	//конструктор по умолчанию
	MyAddress()
	{
		int house = 1;
		int flat = 1;
	}

	// ввод даты с консоли
	void InputAddress()
	{
		bool correct_address = true; // корректна ли введенная дата
		string message = "";  // сообщение о причине ошибки
		do
		{
			if !correct_address
				cout << message << endl;
			house = InputNumber(1, 100, "Ввод адреса:\nВведите номер дома (1-100): ");
			flat = InputNumber(1, 1000, "Введите номер квартиры (1-1000): ");
			correct_address = CorrectAddress(house, flat, message);
		} while (!correct_address);  // повторять ввод пока не корректная дата
	}

	// перевод даты в строку (для последующей записи в файл)
	string ToString()
	{
		return ("дом " + to_string(house) + " квартира " + to_string(flat));
	}

	// перегруженный оператор равенства
	bool operator == (const MyAddress &c)
	{
		return ((house == c.house) && (flat == c.flat));
	}

	// конструктор копирования
	MyAddress& operator = (MyAddress c)
	{
		house = c.house;
		flat = c.flat;

		return (*this);
	}

};

//подтип дата
class MyDate {

	// проверка является ли год високосным
	bool IsLeap(int year)
	{
		if year % 4
			return false;
		if year % 100
			return true;
		return !(year % 400);
	}

	// проверка даты на корректность
	bool CorrectDate(int day, int month, int year,string &message) {

	    // если год вискосный                            если не високосный
		if ((month == 2 && day > 29 && IsLeap(year)) || (month == 2 && day > 28 && !IsLeap(year)))
		{
			message = "Неверное кол-во дней в феврале!";
			return false;
		}
		//кол-во дней в месяце
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day > 30) 
			{
				message = "Неверное кол-во дней в месяце!";
				return false;
			}
		}
	}
public:
	// день
	int day;
	// месяц
	int month;
	// год
	int year;

	// конструктор по умолчанию
	MyDate()
	{
		int day=1;
		int month=1;
		int year = 1970;
	}

	// ввод даты с консоли
	void InputDate()
	{
		bool correct_date = true; // корректна ли введенная дата
		string message = "";  // сообщение о причине ошибки
		do
		{
			if (!correct_date)
				cout << message << endl;
			day = InputNumber(1, 31, "Ввод даты:\nВведите день (1-31): ");
			month = InputNumber(1, 12, "Введите номер месяца (1-12): ");
			year = InputNumber(1970, 2100, "Введите год (1970-2100): ");
			correct_date = CorrectDate(day, month, year, message);
		} while (!correct_date);  // повторять ввод пока не корректная дата
	}

	// перевод даты в строку (для последующей записи в файл)
	 string ToString()
	{
		return (to_string(day) + ' ' + to_string(month) + ' ' + to_string(year));
	}
	
	// перегруженный оператор равенства
	bool operator == (const MyDate &c)
	{
		return ((day == c.day) && (month == c.month) && (year == c.year));
	}

	// конструктор копирования
	MyDate& operator = (MyDate c)
	{
		day = c.day;
		month = c.month;
		year = c.year;

		return (*this);
	}

	// перегруженный оператор больше
	bool operator > (const MyDate &c)
	{
		return ((year > c.year) || ((year == c.year) && (month > c.month)) || ((year == c.year) && (month == c.month) && (day>c.day)));
	}

	// перегруженные оператор меньше
	bool operator < (const MyDate &c)
	{
		return ((year < c.year) || ((year == c.year) && (month < c.month)) || ((year == c.year) && (month == c.month) && (day<c.day)));
	}

};

class Payment {
public:
	// адрес
	MyAddress owner_address;
	// фамилия
	string surname;
	// вид платежа
	string payment_kind;
	// дата платежа
	MyDate payment_date;
	// сумма платежа
	int summ;
	// процент пени
	int percentage;
	// количество просроченных дней
	int bad_days;

	// конструктор по умолчанию
	Payment()
	{
		MyAddress owner_address;;
		string surname="";
		string payment_kind="";
		MyDate payment_date;
		int summ = 0;
		int percentage = 0;
		int bad_days = 0;
	}


	// изменение структуры "платеж"
	Payment ChangePayment(Payment &result)
	{
		if (InputNumber(0, 1, "Вы хотите изменить адрес  (0 - нет, 1 - да)\nВыш выбор: ") == 1)
			result.owner_address.InputAddress();
		if (InputNumber(0, 1, "Вы хотите изменить фамилию " + result.surname + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
			result.surname = InputInformation("Введите новую фамилию: ");
		if (InputNumber(0, 1, "Вы хотите изменить вид платежа " + result.payment_kind + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
			result.payment_kind = InputInformation("Введите новый вид платежа: ");
		if (InputNumber(0, 1, "Вы хотите изменить дату платежа  (0-нет, 1 - да)\nВыш выбор: ") == 1)
			result.payment_date.InputDate();
		if (InputNumber(0, 1, "Вы хотите изменить сумму платежа " + to_string(result.summ) + "(0 - нет, 1 - да) \nВыш выбор: ") == 1)
			result.summ = InputNumber(0, 10000, "Введите новую сумму платежа: ");
		if (InputNumber(0, 1, "Вы хотите изменить процент пени " + to_string(result.percentage) + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
			result.percentage = InputNumber(0, 100, "Введите новый процент пени: ");
		if (InputNumber(0, 1, "Вы хотите изменить количество просроченных дней " + to_string(result.bad_days) + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
			result.bad_days = InputNumber(0, 31, "Введите новое количество просроченных дней: ");

		return result;
	}

	// перегруженный оператор равенства для структуры "платеж"
	Payment& operator = (Payment c)
	{
		owner_address = c.owner_address;
		surname = c.surname;
		payment_kind = c.payment_kind;
		payment_date = c.payment_date;
		summ = c.summ;
		percentage = c.percentage;
		bad_days = c.bad_days;

		return (*this);
	}
};

// функция ввода структуры "платеж" с консоли
Payment InputScreenPayment()
{
	Payment c;
	c.owner_address.InputAddress();
	c.surname = InputInformation("Введите фамилию: ");
	c.payment_kind = InputInformation("Введите вид платежа: ");
	c.payment_date.InputDate();
	c.summ = InputNumber(0, 10000, "Введите сумму платежа (0 - 10000): ");
	c.percentage = InputNumber(0, 100, "Введите процент пени (0-100): ");
	c.bad_days = InputNumber(0, 31, "Введите количество просроченных дней (0-31): ");
	return c;
}

// функция вывода структуры "платеж" на консоль
void OutputScreenPayment(Payment c)
{
	cout << "Адрес: " << c.owner_address.ToString() << endl;
	cout << "Фамилия: " << c.surname << endl;
	cout << "Вид платежа: " << c.payment_kind << endl;
	cout << "Дата: " << c.payment_date.ToString() << endl;
	cout << "Сумма платежа: " << c.summ << endl;
	cout << "Процент пени: " << c.percentage << endl;
	cout << "Количество просроченных дней: " << c.bad_days<< endl;
}

// функция вывода структуры "платеж" на консоль при поиске
void OutputScreenPayment2(Payment c)
{
	cout << "Адрес: " << c.owner_address.ToString() << endl;
	cout << "Фамилия: " << c.surname << endl;
	cout << "Вид платежа: " << c.payment_kind << endl;
	cout << "Дата: " << c.payment_date.ToString() << endl;
	cout << "Сумма платежа: " << c.summ << endl;
	cout << "Процент пени: " << c.percentage << endl;
	cout << "Количество просроченных дней: " << c.bad_days << endl;
	cout << "Сумма долга: " << c.summ+c.summ*c.percentage/100*c.bad_days << endl;
}


//извлечение структуры "дата" из строки 
// Формат:
// день месяц год
MyDate FromString(string str)
{
	MyDate result;
	try
	{
		istringstream is(str);
		string s;
		if (getline(is, s, ' '))
			result.day = atoi(s.c_str());
		if (getline(is, s, ' '))
			result.month = atoi(s.c_str());
		if (getline(is, s, ' '))
			result.year = atoi(s.c_str());
	}
	catch (...)
	{
		cout << "Ошибка записи в файл!" << endl;
	}
	return result;
}

//извлечение структуры "адрес" из строки 
// Формат:
// дом дом квартира квартира
MyAddress FromStrings(string str)
{
	MyAddress result;
	try
	{
		istringstream is(str);
		string s;
		if ((getline(is, s, ' ')) && (getline(is, s, ' ')))
			result.house = atoi(s.c_str());
		if ((getline(is, s, ' ')) && (getline(is, s, ' ')))
			result.flat = atoi(s.c_str());
	}
	catch (...)
	{
		cout << "Ошибка записи в файл!" << endl;
	}
	return result;
}

//перевод структуры "платеж" в строку
string ToString(Payment c,int i)
{
	string result ="Запись № "+to_string(i)+"\n"+ "Адрес: "+c.owner_address.ToString()+"\n"+"Фамилия: "+c.surname+"\n"+"Вид платежа: "+c.payment_kind+"\n"+"Дата: "+c.payment_date.ToString()+"\n"+"Сумма платежа: " + to_string(c.summ) + "\n" + "Процент пени: " + to_string(c.percentage)+"\n" + "Количество просроченных дней: " + to_string(c.bad_days) + "\n";
	return result;
}

////считывание структуры "платеж" из строки
Payment ReadFromString(ifstream& input)
{
	Payment result;
	string s;
	try
	{
		if (!input.eof())
		{
			getline(input, s);
		}
		if (!input.eof())
		{
			getline(input, s,'\n');
			string wrd = "Адрес: ";
			result.owner_address = FromStrings(s.substr(wrd.length(), s.length()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Фамилия: ";
			result.surname = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Вид платежа: ";
			result.payment_kind = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Дата: ";
			result.payment_date = FromString(s.substr(wrd.length(), s.length()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Сумма платежа: ";
			result.summ = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Процент пени: ";
			result.percentage = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Количество просроченных дней: ";
			result.bad_days= atoi(s.substr(wrd.length(), s.length()).c_str());
		}
	}
	catch (...)
	{
		cout << "Ошибка записи в файл!" << endl;
	}
	return result;
}


// поиск равного элемента по выбранному критерию
// type_search - тип поиска
//1 - по дому
//2 - по квартире
//3 - по фамилии
//4 - по дате
//5 - по наличию долга
bool SearchElement(Payment m, Payment n, int type_search)
{
	switch (type_search)
	{
		case 1:
			return (m.owner_address.house == n.owner_address.house);
		case 2:
			return (m.owner_address.flat == n.owner_address.flat);
		case 3:
			return (m.surname == n.surname);
		case 4:
			return (m.payment_date == n.payment_date);
		case 5:
			return (m.bad_days == n.bad_days);
		default:
			return false;
	}
}

// ввод критерия поиска в зависимости от выбранного типа 
// type_search - тип поиска
//1 - по дому
//2 - по квартире
//3 - по фамилии
//4 - по дате
//5 - по наличию долга
Payment InputChangeTypeSearch(int type_search)
{
	Payment result;
	switch (type_search)
	{
	case 1:
		result.owner_address.house = InputNumber(0, 100, "Введите номер дома: ");
		return result;
	case 2:
		result.owner_address.flat = InputNumber(0, 1000, "Введите номер квартиры: ");
		return result;
	case 3:
		result.surname = InputInformation("Введите фамилию: ");
		return result;
	case 4:
		result.payment_date.InputDate();
		return result;
	case 5:
		result.bad_days = InputNumber(0, 31, "Введите количество просроченных дней: ");
		return result;
	default:
		return result;
	}
}

// сравнения структур в зависимости от выбранного поля для сортировки
// type_search - тип поиска
//1 - по дому
//2 - по квартире
//3 - по фамилии
//4 - по дате
//5 - по наличию долга
int Sorte(Payment n, Payment m, int type_search)
{
	switch (type_search)
	{
	case 1:
		if (n.owner_address.house > m.owner_address.house) return 1;
		else if (n.owner_address.house < m.owner_address.house) return -1;
		else return 0;
	case 2:
		if (n.owner_address.flat > m.owner_address.flat) return 1;
		else if (n.owner_address.flat < m.owner_address.flat) return -1;
		else return 0;
	case 3:
		if (n.surname > m.surname) return 1;
		else if (n.surname < m.surname) return -1;
		else return 0;
	case 4:
		if (n.payment_date > m.payment_date) return 1;
		else if (n.payment_date < m.payment_date) return -1;
		else return 0;
	case 5:
		if (n.bad_days > m.bad_days) return 1;
		else if (n.bad_days < m.bad_days) return -1;
		else return 0;
	default:
		return -2;
	}
}




