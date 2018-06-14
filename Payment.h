#pragma once
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"

//������ ����� 
class MyAddress {

	// �������� ������ �� ������������
	bool CorrectAddress(int house, int flat, string &message) {
		if ((house > 100) || (house < 1) || (flat > 1000) || (flat < 1))
			{
				message = "�������� ����� �����!";
				return false;
			}
	}

public:
	//���
	int house;
	//��������
	int flat;

	//����������� �� ���������
	MyAddress()
	{
		int house = 1;
		int flat = 1;
	}

	// ���� ���� � �������
	void InputAddress()
	{
		bool correct_address = true; // ��������� �� ��������� ����
		string message = "";  // ��������� � ������� ������
		do
		{
			if (!correct_address)
				cout << message << endl;
			house = InputNumber(1, 100, "���� ������:\n������� ����� ���� (1-100): ");
			flat = InputNumber(1, 1000, "������� ����� �������� (1-1000): ");
			correct_address = CorrectAddress(house, flat, message);
		} while (!correct_address);  // ��������� ���� ���� �� ���������� ����
	}

	// ������� ���� � ������ (��� ����������� ������ � ����)
	string ToString()
	{
		return ("��� " + to_string(house) + " �������� " + to_string(flat));
	}

	// ������������� �������� ���������
	bool operator == (const MyAddress &c)
	{
		return ((house == c.house) && (flat == c.flat));
	}

	// ����������� �����������
	MyAddress& operator = (MyAddress c)
	{
		house = c.house;
		flat = c.flat;

		return (*this);
	}

};

//������ ����
class MyDate {

	// �������� �������� �� ��� ����������
	bool IsLeap(int year)
	{
		if (year % 4)
			return false;
		if (year % 100)
			return true;
		return !(year % 400);
	}

	// �������� ���� �� ������������
	bool CorrectDate(int day, int month, int year,string &message) {

	    // ���� ��� ���������                            ���� �� ����������
		if ((month == 2 && day > 29 && IsLeap(year)) || (month == 2 && day > 28 && !IsLeap(year)))
		{
			message = "�������� ���-�� ���� � �������!";
			return false;
		}
		//���-�� ���� � ������
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day > 30) 
			{
				message = "�������� ���-�� ���� � ������!";
				return false;
			}
		}
	}
public:
	// ����
	int day;
	// �����
	int month;
	// ���
	int year;

	// ����������� �� ���������
	MyDate()
	{
		int day=1;
		int month=1;
		int year = 1970;
	}

	// ���� ���� � �������
	void InputDate()
	{
		bool correct_date = true; // ��������� �� ��������� ����
		string message = "";  // ��������� � ������� ������
		do
		{
			if (!correct_date)
				cout << message << endl;
			day = InputNumber(1, 31, "���� ����:\n������� ���� (1-31): ");
			month = InputNumber(1, 12, "������� ����� ������ (1-12): ");
			year = InputNumber(1970, 2100, "������� ��� (1970-2100): ");
			correct_date = CorrectDate(day, month, year, message);
		} while (!correct_date);  // ��������� ���� ���� �� ���������� ����
	}

	// ������� ���� � ������ (��� ����������� ������ � ����)
	 string ToString()
	{
		return (to_string(day) + ' ' + to_string(month) + ' ' + to_string(year));
	}
	
	// ������������� �������� ���������
	bool operator == (const MyDate &c)
	{
		return ((day == c.day) && (month == c.month) && (year == c.year));
	}

	// ����������� �����������
	MyDate& operator = (MyDate c)
	{
		day = c.day;
		month = c.month;
		year = c.year;

		return (*this);
	}

	// ������������� �������� ������
	bool operator > (const MyDate &c)
	{
		return ((year > c.year) || ((year == c.year) && (month > c.month)) || ((year == c.year) && (month == c.month) && (day>c.day)));
	}

	// ������������� �������� ������
	bool operator < (const MyDate &c)
	{
		return ((year < c.year) || ((year == c.year) && (month < c.month)) || ((year == c.year) && (month == c.month) && (day<c.day)));
	}

};

class Payment {
public:
	// �����
	MyAddress owner_address;
	// �������
	string surname;
	// ��� �������
	string payment_kind;
	// ���� �������
	MyDate payment_date;
	// ����� �������
	int summ;
	// ������� ����
	int percentage;
	// ���������� ������������ ����
	int bad_days;

	// ����������� �� ���������
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


	// ��������� ��������� "������"
	Payment ChangePayment(Payment &result)
	{
		if (InputNumber(0, 1, "�� ������ �������� �����  (0 - ���, 1 - ��)\n��� �����: ") == 1)
			result.owner_address.InputAddress();
		if (InputNumber(0, 1, "�� ������ �������� ������� " + result.surname + " (0 - ���, 1 - ��)\n��� �����: ") == 1)
			result.surname = InputInformation("������� ����� �������: ");
		if (InputNumber(0, 1, "�� ������ �������� ��� ������� " + result.payment_kind + " (0 - ���, 1 - ��)\n��� �����: ") == 1)
			result.payment_kind = InputInformation("������� ����� ��� �������: ");
		if (InputNumber(0, 1, "�� ������ �������� ���� �������  (0-���, 1 - ��)\n��� �����: ") == 1)
			result.payment_date.InputDate();
		if (InputNumber(0, 1, "�� ������ �������� ����� ������� " + to_string(result.summ) + "(0 - ���, 1 - ��) \n��� �����: ") == 1)
			result.summ = InputNumber(0, 10000, "������� ����� ����� �������: ");
		if (InputNumber(0, 1, "�� ������ �������� ������� ���� " + to_string(result.percentage) + " (0 - ���, 1 - ��)\n��� �����: ") == 1)
			result.percentage = InputNumber(0, 100, "������� ����� ������� ����: ");
		if (InputNumber(0, 1, "�� ������ �������� ���������� ������������ ���� " + to_string(result.bad_days) + " (0 - ���, 1 - ��)\n��� �����: ") == 1)
			result.bad_days = InputNumber(0, 31, "������� ����� ���������� ������������ ����: ");

		return result;
	}

	// ������������� �������� ��������� ��� ��������� "������"
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

// ������� ����� ��������� "������" � �������
Payment InputScreenPayment()
{
	Payment c;
	c.owner_address.InputAddress();
	c.surname = InputInformation("������� �������: ");
	c.payment_kind = InputInformation("������� ��� �������: ");
	c.payment_date.InputDate();
	c.summ = InputNumber(0, 10000, "������� ����� ������� (0 - 10000): ");
	c.percentage = InputNumber(0, 100, "������� ������� ���� (0-100): ");
	c.bad_days = InputNumber(0, 31, "������� ���������� ������������ ���� (0-31): ");
	return c;
}

// ������� ������ ��������� "������" �� �������
void OutputScreenPayment(Payment c)
{
	cout << "�����: " << c.owner_address.ToString() << endl;
	cout << "�������: " << c.surname << endl;
	cout << "��� �������: " << c.payment_kind << endl;
	cout << "����: " << c.payment_date.ToString() << endl;
	cout << "����� �������: " << c.summ << endl;
	cout << "������� ����: " << c.percentage << endl;
	cout << "���������� ������������ ����: " << c.bad_days<< endl;
}

// ������� ������ ��������� "������" �� ������� ��� ������
void OutputScreenPayment2(Payment c)
{
	cout << "�����: " << c.owner_address.ToString() << endl;
	cout << "�������: " << c.surname << endl;
	cout << "��� �������: " << c.payment_kind << endl;
	cout << "����: " << c.payment_date.ToString() << endl;
	cout << "����� �������: " << c.summ << endl;
	cout << "������� ����: " << c.percentage << endl;
	cout << "���������� ������������ ����: " << c.bad_days << endl;
	cout << "����� �����: " << c.summ+c.summ*c.percentage/100*c.bad_days << endl;
}


//���������� ��������� "����" �� ������ 
// ������:
// ���� ����� ���
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
		cout << "������ ������ � ����!" << endl;
	}
	return result;
}

//���������� ��������� "�����" �� ������ 
// ������:
// ��� ��� �������� ��������
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
		cout << "������ ������ � ����!" << endl;
	}
	return result;
}

//������� ��������� "������" � ������
string ToString(Payment c,int i)
{
	string result ="������ � "+to_string(i)+"\n"+ "�����: "+c.owner_address.ToString()+"\n"+"�������: "+c.surname+"\n"+"��� �������: "+c.payment_kind+"\n"+"����: "+c.payment_date.ToString()+"\n"+"����� �������: " + to_string(c.summ) + "\n" + "������� ����: " + to_string(c.percentage)+"\n" + "���������� ������������ ����: " + to_string(c.bad_days) + "\n";
	return result;
}

////���������� ��������� "������" �� ������
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
			string wrd = "�����: ";
			result.owner_address = FromStrings(s.substr(wrd.length(), s.length()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "�������: ";
			result.surname = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "��� �������: ";
			result.payment_kind = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����: ";
			result.payment_date = FromString(s.substr(wrd.length(), s.length()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����� �������: ";
			result.summ = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "������� ����: ";
			result.percentage = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "���������� ������������ ����: ";
			result.bad_days= atoi(s.substr(wrd.length(), s.length()).c_str());
		}
	}
	catch (...)
	{
		cout << "������ ������ � ����!" << endl;
	}
	return result;
}


// ����� ������� �������� �� ���������� ��������
// type_search - ��� ������
//1 - �� ����
//2 - �� ��������
//3 - �� �������
//4 - �� ����
//5 - �� ������� �����
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

// ���� �������� ������ � ����������� �� ���������� ���� 
// type_search - ��� ������
//1 - �� ����
//2 - �� ��������
//3 - �� �������
//4 - �� ����
//5 - �� ������� �����
Payment InputChangeTypeSearch(int type_search)
{
	Payment result;
	switch (type_search)
	{
	case 1:
		result.owner_address.house = InputNumber(0, 100, "������� ����� ����: ");
		return result;
	case 2:
		result.owner_address.flat = InputNumber(0, 1000, "������� ����� ��������: ");
		return result;
	case 3:
		result.surname = InputInformation("������� �������: ");
		return result;
	case 4:
		result.payment_date.InputDate();
		return result;
	case 5:
		result.bad_days = InputNumber(0, 31, "������� ���������� ������������ ����: ");
		return result;
	default:
		return result;
	}
}

// ��������� �������� � ����������� �� ���������� ���� ��� ����������
// type_search - ��� ������
//1 - �� ����
//2 - �� ��������
//3 - �� �������
//4 - �� ����
//5 - �� ������� �����
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




