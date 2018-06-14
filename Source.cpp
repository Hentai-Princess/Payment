//14Оплата счета представлена структурой с полями : название фирмы, вид работ, единица измерения, стоимость единицы выполненной работы,
//дата исполнения, объем работ.Поиск по названию фирмы, виду работ, дате исполнения.
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "HelpUtils.h"
#include "Operation.h"
#include "Payment.h"
using namespace std;




int Menu()
{
	cout << " --------------------Меню---------------------  " << endl;
	cout << "1 - Добавить элемент" << endl;
	cout << "2 - Удалить элемент" << endl;
	cout << "3 - Изменить элемент" << endl;
	cout << "4 - Вывод на экран" << endl;
	cout << "5 - Сохранить в файл " << endl;
	cout << "6 - Линейный поиск" << endl;
	cout << "7 - Двоичный поиск" << endl;
	cout << "8 - Вывести подможество на экран" << endl;
	cout << "9 - Сохранить подмножество в файл" << endl;
	cout << "0 - Выход" << endl;
	int n = InputNumber(0, 9, "Ваш выбор: ");
	cout << "\n";
	return n;
}

bool ChangeInputData()
{
	Task<Payment> task;
	bool change = true;
	cout << " --------------------Меню---------------------  " << endl;
	cout << "1 - Заполнение контейнера с консоли" << endl;
	cout << "2 - Заполнение контейнера из файла " << endl;
	cout << "0 - Выход" << endl;
	int changemenu = InputNumber(0, 2, "Ваш выбор: ");
	switch (changemenu)
	{
	case 1:
		task.ReadFromScreen(InputScreenPayment);
		break;

	case 2:
		change=task.ReadFromFile(ReadFromString);
		break;

	default:
		change = false;
		break;
	}
	if (change)
			{
				Payment elem;
				vector<Payment> subset;
				Payment search_elem;
				int numb;
				while (1)
				{
					int n = Menu();
					switch (n)
					{
					case 1:
						task.Add(InputScreenPayment());
						break;
		
					case 2:
						task.OutputScreen(task.vect, OutputScreenPayment);
						task.Remove(InputNumber(0, task.size(), "Введите номер удаляемого эл-та (0 - если передумали удалять): "));
						break;
		
					case 3:
						task.OutputScreen(task.vect, OutputScreenPayment);
						numb = InputNumber(0, task.size(), "Введите номер изменяеиого эл-та (0 - если передумали изменять): ");
						if (numb != 0)
							task.vect[numb-1] = elem.ChangePayment(task.vect[numb-1]);
						break;
		
					case 4:
						task.OutputScreen(task.vect,OutputScreenPayment);
						break;
		
					case 5:
						task.OutputFile(task.vect,ToString);
						break;
					case 6:
						numb = InputNumber(1, 5, "Выберите тип поиска:\n1 - по дому\n2 - по квартире\n3 - по фамилии\n4 - по дате\n5 - по наличию долга\nВаш выбор: ");
						search_elem = InputChangeTypeSearch(numb);
						subset = task.LinearySearch(search_elem,SearchElement,numb);
						if (subset.size() != 0)
							task.OutputScreen(subset, OutputScreenPayment2);
						else
							cout << "Элементы не найдены" << endl;
						break;
		
					case 7:
						numb = InputNumber(1, 5, "Выберите тип поиска:\n1 - по дому\n2 - по квартире\n3 - по фамилии\n4 - по дате\n5 - по наличию долга\nВаш выбор: ");
						search_elem = InputChangeTypeSearch(numb);
						subset = task.BinarySearch(numb,search_elem, Sorte,SearchElement);
						if (subset.size() != 0)
							task.OutputScreen(subset, OutputScreenPayment2);
						else
							cout << "Элементы не найдены" << endl;
						break;
		
					case 8:
						task.OutputScreen(subset,OutputScreenPayment);
						break;
		
					case 9:
						task.OutputFile(subset,ToString);
						break;

		
					default:
						cout << "Выход " << endl; exit(0);
						break;
		
					}
				}
			}
			else
				cout << "До свидания!\n";
			system("pause");
}

void main()
{
	setlocale(LC_ALL, "Russian");
	ChangeInputData();
}