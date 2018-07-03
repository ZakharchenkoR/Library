/
//  second_struct.cpp
//  Library
//
//  Created by Роман Захарченко  on 5/12/18.
//  Copyright © 2018 Роман Захарченко . All rights reserved.
//
#include "Header.h"
#include "first_struct.h"
#include "second_struct.h"

//functions

//_1
void fillReader(Reader&obj, int&id_r)
{
	char buf[500];
	cout << "Enter the surename: ";
	cin.getline(buf, 500);
	obj.surnameReader = strdup(buf);
	cout << "Enter the name: ";
	cin.getline(buf, 500);
	obj.nameReader = strdup(buf);
	cout << "Enter the fathername: ";
	cin.getline(buf, 500);
	obj.fatherNameReader = strdup(buf);
	cout << "Enter the date of birth: " << endl;
	do {
		cout << "Day of birth : ";
		cin >> obj.dayBirths;
	} while (obj.dayBirths<1 || obj.dayBirths>31);
	do {
		cout << "Mounth of birth: ";
		cin >> obj.mounthBirths;
	} while (obj.mounthBirths>12 || obj.mounthBirths < 1);
	cout << "Year publication: ";
	cin >> obj.yearBirths;
	cout << "Enter the number of your pasport: ";
	cin >> obj.numberPasport;
	cin.ignore();
	obj.id_reader = id_r++;
}

//_2(show_struct_///////////
void showReader(Reader&obj)
{
	cout << "The reader name: \"" << obj.surnameReader << " ";
	cout << obj.nameReader << " ";
	cout << obj.fatherNameReader << "\"" << endl;
	cout << "Date birthday of the reader: \'";
	if (obj.dayBirths<10)
	{
		cout << "0" << obj.dayBirths << ".";
	}
	else
	{
		cout << obj.dayBirths << ".";
	}
	if (obj.mounthBirths<10)
	{
		cout << "0" << obj.mounthBirths << ".";
	}
	else
	{
		cout << obj.mounthBirths << ".";
	}
	cout << obj.yearBirths << "\'" << endl;
	cout << "Passport ID: " << obj.numberPasport << endl;
	cout << "Number of books read: " << obj.numberBookRead << endl;
	cout << "Id of books read: " << obj.id_reader << endl;
	cout << endl;
}

//_3
void AddReader(Reader*&arr, int & size, int&id_r)
{
	if (size == 0)
	{
		arr = new Reader[1];
	}
	else
	{
		Reader*tmp = new Reader[size + 1];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = arr[i];
		}
		delete[]arr;
		arr = tmp;
	}
	fillReader(arr[size], id_r);
	size++;
}


//_4
void showAll(Reader*arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << endl;
		cout << "Information abot the reader №" << i + 1 << endl;
		showReader(arr[i]);
	}
}

//5
void addInArray(Reader*&arr, int & size, int&id_r)
{
	cout << "How many reders do you want to add: ";
	int readers;
	cin >> readers;
	for (int i = 0;i<readers;i++)
	{
		cout << endl;
		cout << "The reader №" << i + 1 << ":" << endl;
		AddReader(arr, size, id_r);
	}
}

//_8_(полное редактирование)
void fullEditing(Reader*&obj, int&size)
{
	cout << "Enter ID to the change: ";
	int id;
	cin >> id;
	for (int i = 0;i<size;i++)
	{
		if (id == obj[i].id_reader)
		{
			char buf[500];
			delete obj[i].fatherNameReader;
			delete obj[i].nameReader;
			delete obj[i].surnameReader;
			cout << "Enter the new surename: ";
			cin.ignore();
			cin.getline(buf, 500);
			obj[i].surnameReader = strdup(buf);
			cout << "Enter the new name: ";
			cin.getline(buf, 500);
			obj[i].nameReader = strdup(buf);
			cout << "Enter the new fathername: ";
			cin.getline(buf, 500);
			obj[i].fatherNameReader = strdup(buf);
			cout << "Enter the new date of birth: " << endl;
			do {
				cout << "New day of birth : ";
				cin >> obj[i].dayBirths;
			} while (obj[i].dayBirths<1 || obj[i].dayBirths>31);
			do {
				cout << "New mounth of birth: ";
				cin >> obj[i].mounthBirths;
			} while (obj[i].mounthBirths>12 || obj[i].mounthBirths < 1);
			cout << "New year publication: ";
			cin >> obj[i].yearBirths;
			cout << "Enter the new number of your pasport: ";
			cin >> obj[i].numberPasport;
			cout << "Enter the new number of books read: ";
			cin >> obj[i].numberBookRead;
			cin.ignore();
		}
		else
		{
			cout << "Don't have book with id: " << id << endl;
		}
	}
}
//_9_(частичное редактирование)
void notFullEditing(Reader*&obj, int&size)
{
	cout << "Enter ID to the change: ";
	int id;
	cin >> id;
	for (int i = 0;i<size;i++)
	{
		if (id == obj[i].id_reader)
		{
			char buf[500];
			char yes[4] = "Yes";
			char no[3] = "No";
			cout << endl;
			cout << "Want to change the surename?" << endl;
			cout << "Enter \"Yes\" or \"No\" end tab to <ENTER>" << endl;
			cout << "Your choice: ";
			cin.ignore();
			cin.getline(buf, 500);
			char *myChoise = strdup(buf);
			if (strcmp(yes, myChoise) == 0)
			{
				delete obj[i].surnameReader;
				cout << "Enter the new surename: ";
				cin.getline(buf, 500);
				obj[i].surnameReader = strdup(buf);
				delete myChoise;
			}
			else if (strcmp(no, myChoise) == 0)
			{
				cout << "Surname has not changed!" << endl;
				delete myChoise;
			}
			else
			{
				cout << "Incorrect choice!" << endl;
				delete myChoise;
			}
			//
			cout << endl;
			cout << "Want to change the name?" << endl;
			cout << "Enter \"Yes\" or \"No\" end tab to <ENTER>" << endl;
			cout << "Your choice: ";
			cin.getline(buf, 500);
			char *myChoise1 = strdup(buf);
			if (strcmp(yes, myChoise1) == 0)
			{
				delete obj[i].nameReader;
				cout << "Enter the new name: ";
				cin.getline(buf, 500);
				obj[i].nameReader = strdup(buf);
				delete myChoise1;
			}
			else if (strcmp(no, myChoise1) == 0)
			{
				cout << "Name has not changed!" << endl;
				delete myChoise1;
			}
			else
			{
				cout << "Incorrect choice!" << endl;
				delete myChoise1;
			}
			//
			cout << endl;
			cout << "Want to change the fathername?" << endl;
			cout << "Enter \"Yes\" or \"No\" end tab to <ENTER>" << endl;
			cout << "Your choice: ";
			cin.getline(buf, 500);
			char *myChoise2 = strdup(buf);
			if (strcmp(yes, myChoise2) == 0)
			{
				delete obj[i].fatherNameReader;
				cout << "Enter the new fathername: ";
				cin.getline(buf, 500);
				obj[i].fatherNameReader = strdup(buf);
				delete myChoise2;
			}
			else if (strcmp(no, myChoise2) == 0)
			{
				cout << "Fathername has not changed!" << endl;
				delete myChoise2;
			}
			else
			{
				cout << "Incorrect choice!" << endl;
				delete myChoise2;
			}
			//
			cout << endl;
			cout << "Want to change the date of birth?" << endl;
			cout << "Enter \"Yes\" or \"No\" end tab to <ENTER>" << endl;
			cout << "Your choice: ";
			cin.getline(buf, 500);
			char *myChoise3 = strdup(buf);
			if (strcmp(yes, myChoise3) == 0)
			{
				cout << "Enter the new date of birth: " << endl;
				do {
					cout << "New day of birth : ";
					cin >> obj[i].dayBirths;
				} while (obj[i].dayBirths<1 || obj[i].dayBirths>31);
				do {
					cout << "New mounth of birth: ";
					cin >> obj[i].mounthBirths;
				} while (obj[i].mounthBirths>12 || obj[i].mounthBirths < 1);
				cout << "New year publication: ";
				cin >> obj[i].yearBirths;
				delete myChoise3;
			}
			else if (strcmp(no, myChoise3) == 0)
			{
				cout << "Date of birth has not changed!" << endl;
				delete myChoise2;
			}
			else
			{
				cout << "Incorrect choice!" << endl;
				delete myChoise3;
			}
			//
			cout << endl;
			cout << "Want to change the year publication?" << endl;
			cout << "Enter \"Yes\" or \"No\" end tab to <ENTER>" << endl;
			cout << "Your choice: ";
			cin.getline(buf, 500);
			char *myChoise4 = strdup(buf);
			if (strcmp(yes, myChoise4) == 0)
			{
				cout << "Enter the new number of your pasport: ";
				cin >> obj[i].numberPasport;
				delete myChoise4;
			}
			else if (strcmp(no, myChoise4) == 0)
			{
				cout << "Number of your pasport has not changed!" << endl;
				delete myChoise4;
			}
			else
			{
				cout << "Incorrect choice!" << endl;
				delete myChoise4;
			}
			//
			cout << endl;
			cout << "Want to change the number of books read?" << endl;
			cout << "Enter \"Yes\" or \"No\" end tab to <ENTER>" << endl;
			cout << "Your choice: ";
			cin.getline(buf, 500);
			char *myChoise5 = strdup(buf);
			if (strcmp(yes, myChoise5) == 0)
			{
				cout << "Enter the new number of books read: ";
				cin >> obj[i].numberBookRead;
				delete myChoise5;
			}
			else if (strcmp(no, myChoise5) == 0)
			{
				cout << "Number of books read has not changed!" << endl;
				delete myChoise5;
			}
			else
			{
				cout << "Incorrect choice!" << endl;
				delete myChoise5;
			}
		}
		else
		{
			cout << "Don't have book with id: " << id << endl;
		}
	}
	cin.ignore();
}

//_сортировка по фамили
void sortSurenameReader(Reader*&arr, int&size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if ((strcmp(arr[i].surnameReader, arr[i + 1].surnameReader))>0)
				swap(arr[j], arr[j - 1]);
		}
	}
}

//_сортировка по имени
void sortNameReader(Reader*&arr, int&size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if ((strcmp(arr[i].nameReader, arr[i + 1].nameReader))>0)
				swap(arr[j], arr[j - 1]);
		}
	}
}

//сортировка по отчеству
void sortFatherNameReader(Reader*&arr, int&size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if ((strcmp(arr[i].fatherNameReader, arr[i + 1].fatherNameReader))>0)
				swap(arr[j], arr[j - 1]);
		}
	}
}

//сортировка по количеству прочитаных книг
void sortNumberReadBook(Reader*&arr, int&size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (arr[i].numberBookRead<arr[i - 1].numberBookRead)
				swap(arr[j].numberBookRead, arr[j - 1].numberBookRead);
		}
	}
}


//сортировка по id
void sortIdReader(Reader*&arr, int&size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (arr[i].id_reader<arr[i - 1].id_reader)
				swap(arr[j].id_reader, arr[j - 1].id_reader);
		}
	}
}

//сортировка по номеру поспорта
void sortNumberPassportReader(Reader*&arr, int&size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (arr[i].numberPasport<arr[i - 1].numberPasport)
				swap(arr[j].numberPasport, arr[j - 1].numberPasport);
		}
	}
}



//_11_(Самые активные читатели)
void activeReaders(Reader*&arr, int&size)
{
	for (int i = 0;i<size;i++)
	{
		if (arr[i].numberBookRead>10)
			showReader(arr[i]);
	}
}

//_12_(удаление читателя)
void deleteReader(Reader*&arr, int&size)
{
	cout << endl;
	cout << "Enter the reader's ID to delete: ";
	int readerIdDelet;
	cin >> readerIdDelet;
	cin.ignore();
	bool have = false;
	int position_reade = 0;
	for (int i = 0;i<size;i++)
	{
		if (arr[i].id_reader == readerIdDelet)
		{
			position_reade = i;
			have = true;
			break;
		}
	}
	if (!have)
	{
		cout << endl;
		cout << "Dont have the reader with id: \"" << readerIdDelet << "\"" << endl;
		return;
	}
	if (arr[position_reade].sizeId>0)
	{
		cout << "In this writer there are books that need to be returned!" << endl;
		return;
	}
	Reader *tmp = new Reader[size - 1];
	for (int j = 0, z = 0;z<size;j++, z++)
	{

		if (j == position_reade)
			z++;
		tmp[j] = arr[z];
	}
	delete[] arr[position_reade].fatherNameReader;
	delete[] arr[position_reade].nameReader;
	delete[] arr[position_reade].surnameReader;
	delete[] arr;
	arr = tmp;
	size--;
	return;
}

//_поиск по Фамилии
void lookingReaderSurename(Reader*&arr, int&size, char surname[])
{
	for (int i = 0;i<size;i++)
	{
		if (strcmp(surname, arr[i].surnameReader) == 0)
			showReader(arr[i]);
	}
}

//_поиск по имени
void lookingReaderName(Reader*&arr, int&size, char name[])
{
	for (int i = 0;i<size;i++)
	{
		if (strcmp(name, arr[i].nameReader) == 0)
			showReader(arr[i]);
	}
}

//_поиск по отчеству
void lookingReaderFatherName(Reader*&arr, int&size, char fathername[])
{
	for (int i = 0;i<size;i++)
	{
		if (strcmp(fathername, arr[i].fatherNameReader) == 0)
			showReader(arr[i]);
	}
}

//_по количеству прочитаних книг
void lookingNumberBookRead(Reader*&arr, int&size, int numberBookRead)
{
	for (int i = 0;i<size;i++)
	{
		if (arr[i].numberBookRead>10)
			showReader(arr[i]);
	}
}

//_поиск по Id
void lookingReaderId(Reader*&arr, int&size, int id)
{
	for (int i = 0;i<size;i++)
	{
		if (arr[i].id_reader == id)
		{
			showReader(arr[i]);
			break;
		}
	}
}

//_поиск по номеру паспорта
void lookingNumberPasspornReader(Reader*&arr, int&size, int numberPassport)
{
	for (int i = 0;i<size;i++)
	{
		if (arr[i].numberPasport == numberPassport)
		{
			showReader(arr[i]);
			break;
		}
	}
}

// поиск по штрафниках
void lookingPenaltyReaders(Reader*&arr, int&size, double penalty)
{
	for (int i = 0;i<size;i++)
	{
		if (arr[i].penalty>10)
		{
			showReader(arr[i]);
			cout << "__________________________________" << endl;
			cout << "This reader have a penalty: " << arr[i].penalty*penalty << "$" << endl;
		}

	}
}
