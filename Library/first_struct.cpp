//
//  first_struct.cpp
//  Library
//
//  Created by Роман Захарченко  on 5/12/18.
//  Copyright © 2018 Роман Захарченко . All rights reserved.
//
#include "Header.h"
#include "first_struct.h"
#include "second_struct.h"


void fillBook(Book&obj, int&id_books)
{
	char buf[500];
	cout << "Enter the date of publication your book: " << endl;
	do {
		cout << "Day publication: ";
		cin >> obj.dayIssue;
	} while (obj.dayIssue<1 || obj.dayIssue>31);
	do {
		cout << "Mounth publication: ";
		cin >> obj.mounthIssue;
	} while (obj.mounthIssue>12 || obj.mounthIssue < 1);
	cout << "Year publication: ";
	cin >> obj.yearIssue;
	cout << "Enter the book title: ";
	cin.ignore();
	cin.getline(buf, 500);
	obj.name = strdup(buf);
	cout << "Enter the author of the book: ";
	cin.getline(buf, 500);
	obj.authorName = strdup(buf);
	cout << "Enter the genre of the book: ";
	cin.getline(buf, 500);
	obj.genreBook = strdup(buf);
	cout << "Enter the price of the book: ";
	cin >> obj.priceBook;
	cout << "Enter the rating of the book: ";
	cin >> obj.ratingBook;
	obj.id = id_books++;
	cin.ignore();
}

//_2(show_struct_///////////
void showBook(Book&obj)
{
	cout << "The book: \"" << obj.name << "\"" << endl;
	cout << "Date of publication of the book: \'";
	if (obj.dayIssue<10)
	{
		cout << "0" << obj.dayIssue << ".";
	}
	else
	{
		cout << obj.dayIssue << ".";
	}
	if (obj.mounthIssue<10)
	{
		cout << "0" << obj.mounthIssue << ".";
	}
	else
	{
		cout << obj.mounthIssue << ".";
	}
	cout << obj.yearIssue << "\'" << endl;
	cout << "Author of the book is: " << obj.authorName << endl;
	cout << "Genre of the book is: " << obj.genreBook << endl;
	cout << "Rating of the book is: " << obj.ratingBook << endl;
	cout << "Price of the book is: " << obj.priceBook << "$" << endl;
	cout << "Unique identificator: " << obj.id << endl;
	if (obj.on_hands)
	{
		cout << "Book on hands." << endl;
	}
	else
	{
		cout << "Book is free." << endl;
	}
	cout << endl;
}

//_3(полное редактирование данних
void fullEditing(Book*&obj, int&size)
{
	cout << "Enter ID to the change: ";
	int id;
	cin >> id;
	for (int i = 0;i<size;i++)
	{
		if (id == obj[i].id)
		{
			delete obj[i].genreBook;
			delete obj[i].authorName;
			delete obj[i].name;
			char buf[500];
			cout << "Enter the new date of publication your book: " << endl;
			do {
				cout << "New day publication: ";
				cin >> obj[i].dayIssue;
			} while (obj[i].dayIssue<1 || obj[i].dayIssue>31);
			do {
				cout << "New mounth publication: ";
				cin >> obj[i].mounthIssue;
			} while (obj[i].mounthIssue>12 || obj[i].mounthIssue < 1);
			cout << "New year publication: ";
			cin >> obj[i].yearIssue;
			cout << "Enter the new book title: ";
			cin.ignore();
			cin.getline(buf, 500);
			obj[i].name = strdup(buf);
			cout << "Enter the new author of the book: ";
			cin.getline(buf, 500);
			obj[i].authorName = strdup(buf);
			cout << "Enter the new genre of the book: ";
			cin.getline(buf, 500);
			obj[i].genreBook = strdup(buf);
			cout << "Enter the new price of the book: ";
			cin >> obj[i].priceBook;
			cout << "Enter the new rating of the book: ";
			cin >> obj[i].ratingBook;
			cin.ignore();
		}
		else
		{
			cout << "Don't have book with id: " << id << endl;
			cin.ignore();
		}
	}
}

//_4(частичное редактирование
void notFullEditing(Book*&obj, int&size)
{
	const char yes[4] = "yes";
	const char no[3] = "no";
	cout << "Enter ID to the change: ";
	int id;
	cin >> id;
	cin.ignore();
	for (int i = 0;i<size;i++)
	{
		if (id == obj[i].id)
		{
			char buf[500];
			cout << "Want to change the date of publication your book:" << endl;
			cout << "Enter \"yes\" or \"no\" end tab to <ENTER>" << endl;
			cout << "Your choice: ";
			cin.getline(buf, 500);
			char *a1 = strdup(buf);
			if (strcmp(yes, a1) == 0)
			{
				do {
					cout << "New day publication: ";
					cin >> obj[i].dayIssue;
				} while (obj[i].dayIssue<1 || obj[i].dayIssue>31);
				do {
					cout << "New mounth publication: ";
					cin >> obj[i].mounthIssue;
				} while (obj[i].mounthIssue>12 || obj[i].mounthIssue < 1);
				cout << "New year publication: ";
				cin >> obj[i].yearIssue;
				cin.ignore();
				delete a1;
			}
			else if (strcmp(no, a1) == 0)
			{
				cout << "The date of publication has not changed" << endl;
				delete a1;
			}
			else
			{
				cout << "Incorrect choice: " << a1 << endl;
				delete a1;
			}
			//
			cout << "Want to change the book title:" << endl;
			cout << "Enter \"yes\" or \"no\" end tab to <ENTER>" << endl;
			cout << "Your choice: ";
			cin.getline(buf, 500);
			char *a2 = strdup(buf);
			if (strcmp(yes, a2) == 0)
			{
				delete obj[i].name;
				cout << "Enter the new book title: ";
				cin.getline(buf, 500);
				obj[i].name = strdup(buf);
				delete a2;
			}
			else if (strcmp(no, a2) == 0)
			{
				cout << "The book title has not changed" << endl;
				delete a2;
			}
			else
			{
				cout << "Incorrect choice: " << a2 << endl;
				delete a2;
			}
			//
			cout << "Want to change the author of the book:" << endl;
			cout << "Enter \"yes\" or \"no\" end tab to <ENTER>" << endl;
			cout << "Your choice: ";
			cin.getline(buf, 500);
			char *a3 = strdup(buf);
			if (strcmp(yes, a3) == 0)
			{
				delete obj[i].authorName;
				cout << "Enter the new author of the book: ";
				cin.getline(buf, 500);
				obj[i].authorName = strdup(buf);
				delete a3;
			}
			else if (strcmp(no, a3) == 0)
			{
				cout << "The author of the book has not changed" << endl;
				delete a3;
			}
			else
			{
				cout << "Incorrect choice: " << a3 << endl;
				delete a3;
			}
			//
			cout << "Want to change the genre of the book:" << endl;
			cout << "Enter \"yes\" or \"no\" end tab to <ENTER>" << endl;
			cout << "Your choice: ";
			cin.getline(buf, 500);
			char *a4 = strdup(buf);
			if (strcmp(yes, a4) == 0)
			{
				delete obj[i].genreBook;
				cout << "Enter the new genre of the book: ";
				cin.getline(buf, 500);
				obj[i].genreBook = strdup(buf);
				delete a4;
			}
			else if (strcmp(no, a4) == 0)
			{
				cout << "The genre of the book has not changed" << endl;
			}
			else
			{
				cout << "Incorrect choice: " << a4 << endl;
				delete a4;
			}
			//
			cout << "Want to change the price of the book:" << endl;
			cout << "Enter \"yes\" or \"no\" end tab to <ENTER>" << endl;
			cout << "Your choice: ";
			cin.getline(buf, 500);
			char *a5 = strdup(buf);
			if (strcmp(yes, a5) == 0)
			{
				cout << "Enter the new price of the book: ";
				cin >> obj[i].priceBook;
				cin.ignore();
				delete a5;
			}
			else if (strcmp(no, a5) == 0)
			{
				cout << "The price of the book has not changed" << endl;
				delete a5;
			}
			else
			{
				cout << "Incorrect choice: " << a5 << endl;
				delete a5;
			}
			//
			cout << "Want to change the rating of the book:" << endl;
			cout << "Enter \"yes\" or \"no\" end tab to <ENTER>" << endl;
			cout << "Your choice: ";
			cin.getline(buf, 500);
			char *a6 = strdup(buf);
			if (strcmp(a6, yes) == 0)
			{
				cout << "Enter the new rating of the book: ";
				cin >> obj[i].ratingBook;
				cin.ignore();
				delete a6;
			}
			else if (strcmp(a6, no) == 0)
			{
				cout << "The rating of the book has not changed" << endl;
				delete a6;
			}
			else
			{
				cout << "Incorrect choice: " << a5 << endl;
				delete a6;
			}
		}
		else
		{
			cout << "Don't have book with id: " << id << endl;
		}
	}
}

//_5(добавление книги)
void AddBook(Book*&arr, int & size, int&id_books)
{
	if (size == 0)
	{
		arr = new Book[1];
	}
	else
	{
		Book*tmp = new Book[size + 1];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = arr[i];
		}
		delete[]arr;
		arr = tmp;
	}
	fillBook(arr[size], id_books);
	size++;
}

//_6(вивод массива структур)
void showAll(Book*arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << endl;
		cout << "Information abot the book №" << i + 1 << endl;
		showBook(arr[i]);
	}
}

//_8(заполнение массива структур)
void addInArray(Book*&arr, int & size, int&id_r)
{
	cout << "How many books do you want to add: ";
	int books;
	cin >> books;
	cin.ignore();
	for (int i = 0;i<books;i++)
	{
		cout << "The book №" << i + 1 << ":" << endl;
		AddBook(arr, size, id_r);
	}
}

//_9(сортировка по автору)
void sortArrayAuthorName(Book*&arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if ((strcmp(arr[i].authorName, arr[i + 1].authorName))>0)
				swap(arr[j], arr[j - 1]);
		}
	}
}

//-сортировка по названию книги
void sortArrayNameNameBook(Book*&arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if ((strcmp(arr[i].name, arr[i + 1].name))>0)
				swap(arr[j], arr[j - 1]);
		}
	}
}

//-сортировка по жанру книги
void sortArrayNameGenreBook(Book*&arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if ((strcmp(arr[i].genreBook, arr[i + 1].genreBook))>0)
				swap(arr[j], arr[j - 1]);
		}
	}
}

//-сортировка по рейтингу книги
void sortArrayRatingGenreBook(Book*&arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (arr[i].ratingBook> arr[i + 1].ratingBook)
				swap(arr[j], arr[j - 1]);
		}
	}
}

//_поиск по автору
void lookingBookAuthorName(Book*&arr, int&size)
{
	char buf[50];
	cout << "Enter the author name: ";
	cin.getline(buf, 50);
	char *yourName = new char(strlen(buf) + 1);
	strcpy(yourName, buf);
	bool f = false;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].authorName, yourName) == 0)
		{
			cout << "_____________________________" << endl;
			cout << "Informations about book: " << endl;
			showBook(arr[i]);
			f = true;
		}
	}
	if (!f)
	{
		cout << endl;
		cout << "Dont have the book(s) whith author: \"" << yourName << "\"" << endl;
	}
	delete yourName;
}

//_поиск по названию книги
void lookingBookNameBook(Book*&arr, int&size)
{
	char buf[50];
	cout << "Enter the name of the book: ";
	cin.getline(buf, 50);
	char *nameBook = new char(strlen(buf) + 1);
	strcpy(nameBook, buf);
	bool f = false;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].name, nameBook) == 0)
		{
			cout << "_____________________________" << endl;
			cout << "Informations about book: " << endl;
			showBook(arr[i]);
			f = true;
		}
	}
	if (!f)
	{
		cout << endl;
		cout << "Dont have the book(s) whith name: \"" << nameBook << "\"" << endl;
	}
	delete nameBook;
}

//_поиск по жанру
void lookingBookGenreBook(Book*&arr, int&size)
{
	char buf[50];
	cout << "Enter the genre of the book: ";
	cin.getline(buf, 50);
	char *nameGenre = new char(strlen(buf) + 1);
	strcpy(nameGenre, buf);
	bool f = false;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].genreBook, nameGenre) == 0)
		{
			cout << "_____________________________" << endl;
			cout << "Informations about book: " << endl;
			showBook(arr[i]);
			f = true;
		}
	}
	if (!f)
	{
		cout << endl;
		cout << "Dont have the book(s) whith genre: \"" << nameGenre << "\"" << endl;
	}
	delete nameGenre;
}

//_поиск по популясности
void lookingBookPopulariryBook(Book*&arr, int&size)
{
	cout << "Enter the rating of the book: ";
	int rating;
	cin >> rating;
	cin.ignore();
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].ratingBook >= rating)
		{
			cout << "_____________________________" << endl;
			cout << "Informations about book: " << endl;
			showBook(arr[i]);
			count++;
		}
	}
	if (count == 0)
	{
		cout << endl;
		cout << "Dont have the book(s) whith rating: \"" << rating << "\"" << endl;
	}
}

//_11(книги на руках у читателя
void booksOnHands(Book*&arr, int&size)
{
	cout << endl;
	cout << "The book(s) on hands in the readers: " << endl;
	cout << "======================================" << endl;
	for (int i = 0;i<size;i++)
	{
		if (arr[i].on_hands)
		{
			cout << "Book №" << i + 1 << ": " << endl;
			showBook(arr[i]);
		}
	}
}

//_12(удаление книги)
void deleteBook(Book*&arr, int&size)
{
	cout << endl;
	cout << "Enter the book's ID to delete: ";
	int bookIdDelet;
	cin >> bookIdDelet;
	cin.ignore();
	bool have = false;
	int positionBook = 0;
	for (int i = 0;i<size;i++)
	{
		if (arr[i].id == bookIdDelet)
		{
			positionBook = i;
			have = true;
			break;
		}
	}
	if (!have)
	{
		cout << endl;
		cout << "Dont have the book with id: \"" << bookIdDelet << "\"" << endl;
		return;
	}
	if (arr[positionBook].on_hands)
	{
		cout << "Before deleting, the book must be returned to the library!" << endl;
		return;
	}
	Book *tmp = new Book[size - 1];
	for (int j = 0, z = 0;z<size;j++, z++)
	{

		if (j == positionBook)
			z++;
		tmp[j] = arr[z];
	}
	delete[] arr[positionBook].authorName;
	delete[] arr[positionBook].genreBook;
	delete[] arr[positionBook].name;
	delete[] arr;
	arr = tmp;
	size--;
	return;
}

//_13(видача книги)
void takeBook(Reader*&arrRaeder, int&sizeReader, Book*&arrBook, int&sizeBook, int yourChoiceIdReader, int yourChoiceIdBook)
{
	bool firsrTrue = false;
	bool secondTrue = false;
	int positionIdReader = 0;
	int positionIdBook = 0;
	for (int i = 0;i<sizeReader;i++)
	{
		if (yourChoiceIdReader == arrRaeder[i].id_reader)
		{
			firsrTrue = true;
			positionIdReader = i;
			break;
		}
	}
	if (!firsrTrue)
	{
		cout << "Don't have reader with ID!: " << yourChoiceIdReader << endl;
		return;
	}
	for (int i = 0;i<sizeBook;i++)
	{
		if (yourChoiceIdBook == arrBook[i].id)
		{
			secondTrue = true;
			positionIdBook = i;
			break;
		}
	}
	if (arrBook[positionIdBook].on_hands)
	{
		return;
	}
	if (!secondTrue)
	{
		cout << "Don't have book with ID!: " << yourChoiceIdBook << endl;
		return;
	}
	arrRaeder[positionIdReader].numberBookRead++;
	arrBook[positionIdBook].on_hands = true;
	dataBookTaking(arrBook, sizeBook, positionIdBook);
	if (arrRaeder[positionIdReader].sizeId == 0)
	{
		arrRaeder[positionIdReader].take = new int[1];
	}
	else
	{
		int *tmp = new int[arrRaeder[positionIdReader].sizeId + 1];
		for (int i = 0;i<arrRaeder[positionIdReader].sizeId;i++)
		{
			tmp[i] = arrRaeder[positionIdReader].take[i];
		}
		delete[] arrRaeder[positionIdReader].take;
		arrRaeder[positionIdReader].take = tmp;
	}
	arrRaeder[positionIdReader].take[arrRaeder[positionIdReader].sizeId] = arrBook[positionIdBook].id;
	arrRaeder[positionIdReader].sizeId++;
}

//_возврат книги
void returnBook(Reader*&arrRaeder, int&sizeReader, Book*&arrBook, int&sizeBook, int IdReaderForReturn, int IdBookForReturn, double penalty)
{
	bool firsrTrue = false;
	bool secondTrue = false;
	int positionIdReader = 0;
	int positionIdBook = 0;
	for (int i = 0;i<sizeReader;i++)
	{
		if (IdReaderForReturn == arrRaeder[i].id_reader)
		{
			firsrTrue = true;
			positionIdReader = i;
			break;
		}
	}
	if (!firsrTrue)
	{
		cout << "Don't have reader with ID!: " << IdReaderForReturn << endl;
		return;
	}
	for (int i = 0;i<arrRaeder[positionIdReader].sizeId;i++)
	{
		if (IdBookForReturn == arrRaeder[positionIdReader].take[i])
		{
			secondTrue = true;
			positionIdBook = i;
			break;
		}
	}

	if (!secondTrue)
	{
		cout << "Don't have book with ID!: " << IdBookForReturn << endl;
		return;
	}

	for (int i = 0;i<sizeBook;i++)
	{
		if (arrBook[i].id == IdBookForReturn)
		{
			arrBook[i].on_hands = false;
			dataReturnBookOnLibrary(arrBook, sizeBook, positionIdBook, arrRaeder, positionIdReader, penalty);
			break;
		}
	}

	if (arrRaeder[positionIdReader].sizeId == 1)
	{
		arrRaeder[positionIdReader].sizeId = 0;
		delete[] arrRaeder[positionIdReader].take;
		return;
	}
	int *tmp = new int[arrRaeder[positionIdReader].sizeId - 1];
	for (int i = 0, j = 0;i<arrRaeder[positionIdReader].sizeId;i++, j++)
	{
		if (arrRaeder[positionIdReader].take[i] == IdBookForReturn)
			j++;
		tmp[i] = arrRaeder[positionIdReader].take[j];
	}
	delete[] arrRaeder[positionIdReader].take;
	arrRaeder[positionIdReader].take = tmp;
	arrRaeder[positionIdReader].sizeId--;
}


//_13(книги на руках в читача)
void listBooksOnHands(Reader*&arrReader, int&sizeReader, Book*&arrBook, int&sizeBook, int idReader)
{
	bool yes = false;
	int positionIdReader = 0;
	for (int i = 0;i<sizeReader;i++)
	{
		if (idReader == arrReader[i].id_reader)
		{
			yes = true;
			positionIdReader = i;
			break;
		}
	}
	if (yes)
	{
		for (int i = 0;i<arrReader[positionIdReader].sizeId;i++)
		{
			for (int j = 0;j<sizeBook;j++)
			{
				if (arrReader[positionIdReader].take[i] == arrBook[j].id)
					showBook(arrBook[j]);
			}
		}
	}
}

//_(дата выдачи кгини читателю)
void dataBookTaking(Book*&arrBook, int&sizeBook, int positionIdBook)
{
	cout << "----------------------------------" << endl;
	cout << "If the book will be for more than 10 days you will be charged a fine of 15.5 dollars a day!" << endl;
	for (int i = 0;i<sizeBook;i++)
	{
		if (positionIdBook == arrBook[i].id)
		{
			do {
				cout << "Enter the day the book was issued: ";
				cin >> arrBook[i].dayBookTaking;
			} while (arrBook[i].dayBookTaking<1 || arrBook[i].dayBookTaking>31);

			do {
				cout << "Enter the mounth the book was issued: ";
				cin >> arrBook[i].mounthBookTaking;
			} while (arrBook[i].mounthBookTaking<1 || arrBook[i].mounthBookTaking>12);

			cout << "Enter the year the book was issued: ";
			cin >> arrBook[i].yearBookTaking;
			cin.ignore();
			break;
		}
	}
}

//_дата возврата книги читателем и начисление пени
void dataReturnBookOnLibrary(Book*&arrBook, int&sizeBook, int positionIdBook, Reader*&arrReader, int positionIdReader, double penalty)
{
	int positionBook = 0;
	int returnDay;
	int returnMounth;
	int returnYear;
	int diffye;
	int diffmon;
	int diffmon1;
	bool out = false;
	cout << "Enter the data of the book return day: " << endl;
	cout << "Day: ";
	cin >> returnDay;
	cout << "Mounth: ";
	cin >> returnMounth;
	cout << "Year: ";
	cin >> returnYear;
	cin.ignore();
	/////////////////////
	for (int i = 0;i<sizeBook;i++)
	{
		if (arrBook[i].id == positionIdBook)
		{
			positionBook = i;
			out = true;
		}

	}
	if (!out)
		return;
	else
	{
		if ((returnDay <= 31 && arrBook[positionBook].dayBookTaking <= 31) && (returnMounth <= 12 && arrBook[positionBook].mounthBookTaking <= 12))
		{
			diffye = (arrBook[positionBook].yearBookTaking - returnYear) * 365;

			if (returnMounth > 8)
			{
				diffmon = ((returnMounth - 1) * 30) + ((returnMounth - 1) / 2) + ((returnMounth - 1) % 2) - 1 + returnDay;
			}
			else if (returnMounth  > 2)
			{
				diffmon = ((returnMounth - 1) * 30) + ((returnMounth - 1) / 2) + ((returnMounth - 1) % 2) - 2 + returnDay;
			}
			else
			{
				diffmon = ((returnMounth - 1) * 30) + ((returnMounth - 1) / 2) + ((returnMounth - 1) % 2) + returnDay;
			}

			if (returnMounth > 8)
			{
				diffmon1 = ((arrBook[positionBook].mounthBookTaking - 1) * 30) + ((arrBook[positionBook].mounthBookTaking - 1) / 2) + ((arrBook[positionBook].mounthBookTaking - 1) % 2) - 1 + arrBook[positionBook].dayBookTaking;
			}
			else if (arrBook[positionBook].mounthBookTaking > 2)
			{
				diffmon1 = ((arrBook[positionBook].mounthBookTaking - 1) * 30) + ((arrBook[positionBook].mounthBookTaking - 1) / 2) + ((arrBook[positionBook].mounthBookTaking - 1) % 2) - 2 + arrBook[positionBook].dayBookTaking;
			}
			else
			{
				diffmon1 = ((arrBook[positionBook].mounthBookTaking - 1) * 30) + ((arrBook[positionBook].mounthBookTaking - 1) / 2) + ((arrBook[positionBook].mounthBookTaking - 1) % 2) + arrBook[positionBook].dayBookTaking;
			}

			if (diffye > 0) {
				(diffye -= diffmon) += diffmon1;
			}
			else {
				diffye = diffmon1 - diffmon;
			}

			if (((arrBook[positionBook].yearBookTaking - returnYear) / 2) > 1 && arrBook[positionBook].mounthBookTaking >  2)
				diffye += ((arrBook[positionBook].yearBookTaking - returnYear) / 4) + 1;
			if (diffye*(-1)>10)
			{
				cout << "Yor penaity is: " << ((diffye*(-1))*penalty) - 10 << "$" << endl;
				arrReader[positionIdReader].penalty += diffye * (-1 - 10);
			}
		}
	}
}


//_популяпные книги в своем жанре
void popylarytyBookInGenre(Book*&arr, int&size, char genre[])
{
	for (int i = 0;i<size;i++)
	{
		if (strcmp(genre, arr[i].genreBook) == 0 && arr[i].ratingBook>7)
			showBook(arr[i]);

	}
}
