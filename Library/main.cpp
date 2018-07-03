
#include "Header.h"
#include "first_struct.h"
#include "second_struct.h"

void ShowLine()
{
	cout << "=======================================================" << endl;
}

void writeStructReaderInFile(FILE *filereader, Reader *& obj, int sizeArrReader)
{
	fwrite(&sizeArrReader, sizeof(int), 1, filereader);
	for (int i = 0; i<sizeArrReader; i++)
	{
		int surenameSize = strlen(obj[i].surnameReader) + 1;
		fwrite(&surenameSize, sizeof(int), 1, filereader);
		fwrite(obj[i].surnameReader, sizeof(char), surenameSize, filereader);

		int nameSize = strlen(obj[i].nameReader) + 1;
		fwrite(&nameSize, sizeof(int), 1, filereader);
		fwrite(obj[i].nameReader, sizeof(char), nameSize, filereader);

		int FnameSize = strlen(obj[i].fatherNameReader) + 1;
		fwrite(&FnameSize, sizeof(int), 1, filereader);
		fwrite(obj[i].fatherNameReader, sizeof(char), FnameSize, filereader);

		fwrite(&obj[i].dayBirths, sizeof(int), 1, filereader);
		fwrite(&obj[i].mounthBirths, sizeof(int), 1, filereader);
		fwrite(&obj[i].yearBirths, sizeof(int), 1, filereader);
		fwrite(&obj[i].numberPasport, sizeof(int), 1, filereader);
		fwrite(&obj[i].id_reader, sizeof(int), 1, filereader);
		fwrite(&obj[i].numberBookRead, sizeof(int), 1, filereader);

		fwrite(&obj[i].sizeId, sizeof(int), 1, filereader);
		fwrite(obj[i].take, sizeof(int), obj[i].sizeId, filereader);

		fwrite(&obj[i].overdue_days, sizeof(int), 1, filereader);
		fwrite(&obj[i].penalty, sizeof(int), 1, filereader);
		fwrite(&obj[i].penaltyOfBook, sizeof(double), 1, filereader);
	}
}


void readStructReaderInFile(FILE *filereaderRead, Reader *& obj, int&sizeReader, int &ID)
{

	fread(&sizeReader, sizeof(int), 1, filereaderRead);
	if (sizeReader == 0)
		return;
	obj = new Reader[sizeReader];
	for (int i = 0; i<sizeReader; i++)
	{
		int sizeSureName;
		fread(&sizeSureName, sizeof(int), 1, filereaderRead);
		obj[i].surnameReader = new char[sizeSureName];
		fread(obj[i].surnameReader, sizeof(char), sizeSureName, filereaderRead);

		int sizeName;
		fread(&sizeName, sizeof(int), 1, filereaderRead);
		obj[i].nameReader = new char[sizeName];
		fread(obj[i].nameReader, sizeof(char), sizeName, filereaderRead);

		int sizeFName;
		fread(&sizeFName, sizeof(int), 1, filereaderRead);
		obj[i].fatherNameReader = new char[sizeFName];
		fread(obj[i].fatherNameReader, sizeof(char), sizeFName, filereaderRead);

		fread(&obj[i].dayBirths, sizeof(int), 1, filereaderRead);
		fread(&obj[i].mounthBirths, sizeof(int), 1, filereaderRead);
		fread(&obj[i].yearBirths, sizeof(int), 1, filereaderRead);
		fread(&obj[i].numberPasport, sizeof(int), 1, filereaderRead);
		obj[i].id_reader = ID++;
		fread(&obj[i].numberBookRead, sizeof(int), 1, filereaderRead);

		fread(&obj[i].sizeId, sizeof(int), 1, filereaderRead);
		obj[i].take = new int[obj[i].sizeId];
		fread(obj[i].take, sizeof(int), obj[i].sizeId, filereaderRead);

		fread(&obj[i].overdue_days, sizeof(int), 1, filereaderRead);
		fread(&obj[i].penalty, sizeof(int), 1, filereaderRead);
		fread(&obj[i].penaltyOfBook, sizeof(double), 1, filereaderRead);
	}
}




void writeStructBookInFile(FILE *filebook, Book *& obj, int sizeArrBook)
{
	fwrite(&sizeArrBook, sizeof(int), 1, filebook);
	for (int i = 0; i<sizeArrBook; i++)
	{
		fwrite(&obj[i].dayIssue, sizeof(int), 1, filebook);
		fwrite(&obj[i].mounthIssue, sizeof(int), 1, filebook);
		fwrite(&obj[i].yearIssue, sizeof(int), 1, filebook);

		int nameBookSize = strlen(obj[i].name) + 1;
		fwrite(&nameBookSize, sizeof(int), 1, filebook);
		fwrite(obj[i].name, sizeof(char), nameBookSize, filebook);

		int authorNameSize = strlen(obj[i].authorName) + 1;
		fwrite(&authorNameSize, sizeof(int), 1, filebook);
		fwrite(obj[i].authorName, sizeof(char), authorNameSize, filebook);

		int genreBookSize = strlen(obj[i].genreBook) + 1;
		fwrite(&genreBookSize, sizeof(int), 1, filebook);
		fwrite(obj[i].genreBook, sizeof(char), genreBookSize, filebook);

		fwrite(&obj[i].priceBook, sizeof(double), 1, filebook);
		fwrite(&obj[i].ratingBook, sizeof(double), 1, filebook);
		fwrite(&obj[i].id, sizeof(int), 1, filebook);
		fwrite(&obj[i].on_hands, sizeof(bool), 1, filebook);
		fwrite(&obj[i].dayBookTaking, sizeof(int), 1, filebook);
		fwrite(&obj[i].mounthBookTaking, sizeof(int), 1, filebook);
		fwrite(&obj[i].yearBookTaking, sizeof(int), 1, filebook);
	}
}


void readStructBookInFile(FILE *filebookRead, Book *& obj, int&sizeArrBook, int &ID)
{

	fread(&sizeArrBook, sizeof(int), 1, filebookRead);
	if (sizeArrBook == 0)
		return;
	obj = new Book[sizeArrBook];
	for (int i = 0; i<sizeArrBook; i++)
	{
		fread(&obj[i].dayIssue, sizeof(int), 1, filebookRead);
		fread(&obj[i].mounthIssue, sizeof(int), 1, filebookRead);
		fread(&obj[i].yearIssue, sizeof(int), 1, filebookRead);

		int sizeNameBook;
		fread(&sizeNameBook, sizeof(int), 1, filebookRead);
		obj[i].name = new char[sizeNameBook];
		fread(obj[i].name, sizeof(char), sizeNameBook, filebookRead);

		int sizeAuthorNameSize;
		fread(&sizeAuthorNameSize, sizeof(int), 1, filebookRead);
		obj[i].authorName = new char[sizeAuthorNameSize];
		fread(obj[i].authorName, sizeof(char), sizeAuthorNameSize, filebookRead);

		int sizeGenreBook;
		fread(&sizeGenreBook, sizeof(int), 1, filebookRead);
		obj[i].genreBook = new char[sizeGenreBook];
		fread(obj[i].genreBook, sizeof(char), sizeGenreBook, filebookRead);

		fread(&obj[i].priceBook, sizeof(double), 1, filebookRead);
		fread(&obj[i].ratingBook, sizeof(double), 1, filebookRead);
		obj[i].id = ID++;
		fread(&obj[i].on_hands, sizeof(bool), 1, filebookRead);
		fread(&obj[i].dayBookTaking, sizeof(int), 1, filebookRead);
		fread(&obj[i].mounthBookTaking, sizeof(int), 1, filebookRead);
		fread(&obj[i].yearBookTaking, sizeof(int), 1, filebookRead);
	}

}

int main()
{
	double const penalty = 15.5;
	int id_books = 0;;
	int id_r = 0;
	int sizeBooks = 0;
	Book *arrBooks = nullptr;
	int sizeReader = 0;
	Reader *arrReade = nullptr;

	FILE *arrBooksFile = fopen("Arr_BooksFL.bin", "rb");
	if (arrBooksFile)
	{
		readStructBookInFile(arrBooksFile, arrBooks, sizeBooks, id_books);
	}

	FILE *arrReadersFile = fopen("Arr_ReadersFL.bin", "rb");
	if (arrReadersFile)
	{
		readStructReaderInFile(arrReadersFile, arrReade, sizeReader, id_r);
	}


	bool exit = false;
	const char readers[] = "readers";
	const char ex[] = "exit";
	const char books[] = "books";
	char buf[50];
	cout << "Welcome to \"LILBRARY\"" << endl;
	cout << "To navigate the menu, use the commands." << endl;
	ShowLine();
	cout << "To enter the \"Menu books\", use the <books> command" << endl;
	cout << "To enter the \"Menu readers\", use the <readers> command" << endl;
	cout << "To \"save\" data, use the <save> command" << endl;
	cout << "To exit the program, use the <exit> command" << endl;
	while (!exit)
	{
		bool exit_with_menu_books = false;
		bool exit_with_menu_readers = false;
		const char issue[] = "issue";
		const char return_book[] = "return";
		const char add[] = "add";
		const char show[] = "show";
		const char delete_book[] = "delete";
		const char show_all_book[] = "show_all";
		const char show_popylarity_books[] = "popularity";
		const char show_books_from_readers[] = "from_readers";
		const char exit_with_menu[] = "exit";
		const char editing_data[] = "edit";
		const char full[] = "full";
		const char partial[] = "partial";
		const char menu_search[] = "search";
		const char author[] = "author";
		const char title[] = "title";
		const char genre[] = "genre";
		const char sort[] = "sort";
		const char penalty_readers[] = "penalty_readers";
		const char active_readers[] = "active_readers";
		const char surename[] = "surename";
		const char name[] = "name";
		const char fathername[] = "fathername";
		const char id[] = "id";
		const char passport[] = "passport";
		const char save[] = "save";
		ShowLine();
		cout << "Menu books" << endl;
		cout << "Menu readers" << endl;
		cout << "Save" << endl;
		cout << "Exit" << endl;
		cout << "-> ";
		cin.getline(buf, 50);
		char *main_menu = new char[strlen(buf + 1)];
		strcpy(main_menu, buf);
		if ((strcmp(books, main_menu)) == 0)
		{
			ShowLine();
			cout << "Menu books" << endl;
			while (!exit_with_menu_books)
			{
				ShowLine();
				cout << "In this menu you can: " << endl;
				cout << "- to issue books, use the <issue> command" << endl;
				cout << "- to return books, use the <return> command" << endl;
				cout << "- to add books, use the <add> command" << endl;
				cout << "- to delete books, use the <delete> command" << endl;
				cout << "- if you want to go to the \"editing data\" menu, use the <edit> command" << endl;
				cout << "- if you want to go to the \"show\" menu, use the <show> command" << endl;
				cout << "- if you want to go to the \"search\" menu, use the <search> command" << endl;
				cout << "- if you want to go to the \"sort\" menu, use the <sort> command" << endl;
				cout << "- to exit with menu, use the <exit> command" << endl;
				ShowLine();
				cout << "1) issue" << endl;
				cout << "2) return" << endl;
				cout << "3) add" << endl;
				cout << "4) delete" << endl;
				cout << "5) edit" << endl;
				cout << "6) show" << endl;
				cout << "7) search" << endl;
				cout << "8) sort" << endl;
				cout << "9) exit" << endl;
				cout << "-> ";
				cin.getline(buf, 50);
				char *menu_books_choice = new char[strlen(buf) + 1];
				strcpy(menu_books_choice, buf);
				if (strcmp(issue, menu_books_choice) == 0)//видача книги
				{
					ShowLine();
					cout << "Enter id reader to take: ";
					int yourChoiceIdReader;
					cin >> yourChoiceIdReader;
					cout << "Enter id book to take: ";
					int yourCoiceIdBook;
					cin >> yourCoiceIdBook;
					cin.ignore();
					takeBook(arrReade, sizeReader, arrBooks, sizeBooks, yourChoiceIdReader, yourCoiceIdBook);
				}
				else if (strcmp(return_book, menu_books_choice) == 0)//возврат книги
				{
					ShowLine();
					cout << "Enter id reader to return: ";
					int yourChoiceIdReaderReturn;
					cin >> yourChoiceIdReaderReturn;
					cout << "Enter id book to return: ";
					int yourCoiceIdBookReturn;
					cin >> yourCoiceIdBookReturn;
					cin.ignore();
					returnBook(arrReade, sizeReader, arrBooks, sizeBooks, yourChoiceIdReaderReturn, yourCoiceIdBookReturn, penalty);
				}
				else if (strcmp(add, menu_books_choice) == 0)//добавление книги
				{
					ShowLine();
					AddBook(arrBooks, sizeBooks, id_books);
				}
				else if (strcmp(delete_book, menu_books_choice) == 0)//удаление кгини
				{
					ShowLine();
					deleteBook(arrBooks, sizeBooks);
				}
				else if (strcmp(editing_data, menu_books_choice) == 0)//меню редактирование
				{
					ShowLine();
					cout << "In this menu you can edit the data" << endl;
					cout << "For full editing, use the <full> command" << endl;
					cout << "For partial editing, use the <partial> command" << endl;
					cout << "1) full" << endl;
					cout << "2) partial" << endl;
					cout << "-> ";
					cin.getline(buf, 50);
					char *menu_edit = new char[strlen(buf) + 1];
					strcpy(menu_edit, buf);
					if (strcmp(menu_edit, full) == 0)//полное
					{
						ShowLine();
						fullEditing(arrBooks, sizeBooks);
					}
					else if (strcmp(menu_edit, partial) == 0)//частичное
					{
						ShowLine();
						notFullEditing(arrBooks, sizeBooks);
					}
					delete[] menu_edit;
				}
				else if (strcmp(show, menu_books_choice) == 0)//меню вивода на екран инфы
				{

					ShowLine();
					cout << "In this menu you can see the books" << endl;
					cout << "If you want to see all the books,use the <show_all> command" << endl;
					cout << "If you want to see the most popular books in your genre,use the <popylarity> command" << endl;
					cout << "If you want to see all the books that are in the hands of the reader,use the <from_readers> command" << endl;
					ShowLine();
					cout << "1) show_all" << endl;
					cout << "2) popularity" << endl;
					cout << "3) from_readers" << endl;
					cout << "-> ";
					cin.getline(buf, 50);
					char *menu_show = new char[strlen(buf) + 1];
					stpcpy(menu_show, buf);
					if (strcmp(menu_show, show_all_book) == 0)//всех книги
					{
						ShowLine();
						showAll(arrBooks, sizeBooks);
					}
					else if (strcmp(menu_show, show_popylarity_books) == 0)//популярних книг в своем жанре
					{
						ShowLine();
						cout << "Enter the genre of your book: " << endl;
						cin.getline(buf, 50);
						char *genreBook = new char[strlen(buf) + 1];
						strcpy(genreBook, buf);
						popylarytyBookInGenre(arrBooks, sizeBooks, genreBook);
						delete[] genreBook;
					}
					else if (strcmp(show_books_from_readers, menu_show) == 0)//книги на руках у читателя
					{
						ShowLine();
						booksOnHands(arrBooks, sizeBooks);
					}
					delete[] menu_show;
				}
				else if (strcmp(menu_search, menu_books_choice) == 0)//меню поиска
				{
					ShowLine();
					cout << "In this menu you can search for books: " << endl;
					cout << "- by author name,use the <author> command" << endl;
					cout << "- by book title,use the <title> command" << endl;
					cout << "- by genre of the book,use the <genre> command" << endl;
					cout << "- by popularity of the book,use the <popularity> command" << endl;
					ShowLine();
					cout << "1) author" << endl;
					cout << "2) title" << endl;
					cout << "3) genre" << endl;
					cout << "4) popularity" << endl;
					cout << "-> ";
					cin.getline(buf, 50);
					char *menu_search = new char[strlen(buf) + 1];
					stpcpy(menu_search, buf);
					if (strcmp(menu_search, author) == 0)//по автору поиск
					{
						ShowLine();
						lookingBookAuthorName(arrBooks, sizeBooks);
					}
					else if (strcmp(menu_search, title) == 0)//по названию книги поиск
					{
						ShowLine();
						lookingBookNameBook(arrBooks, sizeBooks);
					}
					else if (strcmp(menu_search, genre) == 0)//по жанру поиск
					{
						ShowLine();
						lookingBookGenreBook(arrBooks, sizeBooks);
					}
					else if (strcmp(menu_search, show_popylarity_books) == 0)//по порулярности
					{
						ShowLine();
						lookingBookPopulariryBook(arrBooks, sizeBooks);
					}
					delete[] menu_search;
				}
				else if (strcmp(menu_books_choice, sort) == 0)//меню сортировок
				{
					ShowLine();
					cout << "In this menu you can sort books" << endl;
					cout << "- by author name,use the <author> command" << endl;
					cout << "- by book title,use the <title> command" << endl;
					cout << "- by genre of the book,use the <genre> command" << endl;
					cout << "- by popularity of the book,use the <popularity> command" << endl;
					ShowLine();
					cout << "1) author" << endl;
					cout << "2) title" << endl;
					cout << "3) genre" << endl;
					cout << "4) popularity" << endl;
					cout << "-> ";
					cin.getline(buf, 50);
					char *menu_sort = new char[strlen(buf) + 1];
					stpcpy(menu_sort, buf);
					if (strcmp(menu_sort, author) == 0)//сортировки по автору
					{
						sortArrayAuthorName(arrBooks, sizeBooks);
						ShowLine();
						showAll(arrBooks, sizeBooks);
					}
					else if (strcmp(menu_sort, title) == 0)//сортировки по названию книги
					{
						sortArrayNameNameBook(arrBooks, sizeBooks);
						ShowLine();
						showAll(arrBooks, sizeBooks);
					}
					else if (strcmp(menu_sort, genre) == 0)//сортировки по жарну
					{
						sortArrayNameGenreBook(arrBooks, sizeBooks);
						ShowLine();
						showAll(arrBooks, sizeBooks);
					}
					else if (strcmp(menu_sort, show_popylarity_books) == 0)//сортировки по популярности
					{
						sortArrayRatingGenreBook(arrBooks, sizeBooks);
						ShowLine();
						showAll(arrBooks, sizeBooks);
					}
					delete[] menu_sort;
				}
				else if (strcmp(exit_with_menu, menu_books_choice) == 0)//выход с меню books
				{
					exit_with_menu_books = true;
				}
				delete[] menu_books_choice;
			}
		}
		else if (strcmp(readers, main_menu) == 0)
		{
			cout << "Menu readers" << endl;
			while (!exit_with_menu_readers)
			{
				ShowLine();
				cout << "In this menu you can: " << endl;
				cout << "- add the reader using the command <add>" << endl;
				cout << "- delete the reader using the command <delete>" << endl;
				cout << "- enter the \"show\" menu using the command <show>" << endl;
				cout << "- enter the \"data editing\" menu using the command <editing>" << endl;
				cout << "- enter the \"search\" menu using the command <serch>" << endl;
				cout << "- enter the \"sort\" menu using the command <sort>" << endl;
				cout << "- to exit the menu using the command <exit>" << endl;
				ShowLine();
				cout << "1) add" << endl;
				cout << "2) delete" << endl;
				cout << "3) show" << endl;
				cout << "4) editing" << endl;
				cout << "5) search" << endl;
				cout << "6) sort" << endl;
				cout << "7) exit" << endl;
				cout << "-> ";
				cin.getline(buf, 500);
				char *menu_readers = new char[strlen(buf) + 1];
				strcpy(menu_readers, buf);
				if (strcmp(menu_readers, add) == 0)
				{
					ShowLine();
					AddReader(arrReade, sizeReader, id_r);
				}
				else if (strcmp(menu_readers, delete_book) == 0)
				{
					deleteReader(arrReade, sizeReader);
				}
				else if (strcmp(menu_readers, show) == 0)
				{
					ShowLine();
					cout << "In this menu you can: " << endl;
					cout << "- show all readers using the command <show_all>" << endl;
					cout << "- show information about readers of penalties using the command <penalty_readers>" << endl;
					cout << "- show information about the most active readers using the command <active_readers>" << endl;
					ShowLine();
					cout << "1) show_all" << endl;
					cout << "2) penalty_readers" << endl;
					cout << "3) active_readers" << endl;
					cout << "-> ";
					cin.getline(buf, 50);
					char *menu_show_readers = new char[strlen(buf) + 1];
					strcpy(menu_show_readers, buf);
					if (strcmp(menu_show_readers, show_all_book) == 0)
					{
						ShowLine();
						showAll(arrReade, sizeReader);
					}
					else if (strcmp(menu_show_readers, active_readers) == 0)
					{
						ShowLine();
						activeReaders(arrReade, sizeReader);
					}
					else if (strcmp(menu_show_readers, penalty_readers) == 0)//штрафники и начисление штрафы
					{
						lookingPenaltyReaders(arrReade, sizeReader, penalty);
					}
					delete[] menu_show_readers;
				}
				else if (strcmp(menu_readers, editing_data) == 0)//редактирование даних о читателях
				{
					ShowLine();
					cout << "In this menu you can edit the data" << endl;
					cout << "For full editing, use the <full> command" << endl;
					cout << "For partial editing, use the <partial> command" << endl;
					cout << "1) full" << endl;
					cout << "2) partial" << endl;
					cout << "-> ";
					cin.getline(buf, 50);
					char *menu_editing = new char[strlen(buf) + 1];
					strcpy(menu_editing, buf);
					if (strcmp(menu_editing, full) == 0)
					{
						ShowLine();
						fullEditing(arrReade, sizeReader);
					}
					else if (strcmp(menu_editing, partial) == 0)
					{
						ShowLine();
						notFullEditing(arrReade, sizeReader);
					}
					delete[] menu_editing;
				}
				else if (strcmp(menu_readers, menu_search) == 0)//поиск по читателях
				{
					ShowLine();
					cout << "In this menu you can search reader: " << endl;
					cout << "- find a reader by surename use the <surename> command" << endl;
					cout << "- find a reader by name use the <name> command" << endl;
					cout << "- find a reader by fathername use the <fathername> command" << endl;
					cout << "- find a reader by id use the <id> command" << endl;
					cout << "- find a reader by number passport use the <passport> command" << endl;
					ShowLine();
					cout << "surename" << endl;
					cout << "name" << endl;
					cout << "fathername" << endl;
					cout << "id" << endl;
					cout << "passport" << endl;
					cout << "-> ";
					cin.getline(buf, 50);
					char *menu_search = new char[strlen(buf) + 1];
					strcpy(menu_search, buf);
					if (strcmp(menu_search, surename) == 0)//поиск по фамилии
					{
						ShowLine();
						cout << "Enter surename: " << endl;
						cin.getline(buf, 50);
						char *surename = new char[strlen(buf) + 1];
						strcpy(surename, buf);
						lookingReaderSurename(arrReade, sizeReader, surename);
						delete[] surename;
					}
					else if (strcmp(menu_search, name) == 0)//по имени
					{
						ShowLine();
						cout << "Enter name: " << endl;
						cin.getline(buf, 50);
						char *name = new char[strlen(buf) + 1];
						strcpy(name, buf);
						lookingReaderName(arrReade, sizeReader, name);
						delete[] name;
					}
					else if (strcmp(menu_search, fathername) == 0)//по отчеству
					{
						ShowLine();
						cout << "Enter fathername: " << endl;
						cin.getline(buf, 50);
						char *fathername = new char[strlen(buf) + 1];
						strcpy(fathername, buf);
						lookingReaderFatherName(arrReade, sizeReader, fathername);
						delete[] fathername;
					}
					else if (strcmp(menu_search, id) == 0)// по id
					{
						ShowLine();
						cout << "Enter reader id: " << endl;
						int id_reader;
						cin >> id_reader;
						cin.ignore();
						lookingReaderId(arrReade, sizeReader, id_reader);
					}
					else if (strcmp(menu_search, passport) == 0)
					{
						ShowLine();
						cout << "Enter number passport: " << endl;
						int numberPassport;
						cin >> numberPassport;
						cin.ignore();
						lookingNumberPasspornReader(arrReade, sizeReader, numberPassport);
					}
					delete[] menu_search;
				}
				else if (strcmp(menu_readers, sort) == 0)//сортировки читателей
				{

					ShowLine();
					cout << "In this menu you can sort reader: " << endl;
					cout << "- sort a reader by surename use the <surename> command" << endl;
					cout << "- sort a reader by name use the <name> command" << endl;
					cout << "- sort a reader by fathername use the <fathername> command" << endl;
					cout << "- sort a reader by id use the <id> command" << endl;
					cout << "- sort a reader by number passport use the <passport> command" << endl;
					ShowLine();
					cout << "surename" << endl;
					cout << "name" << endl;
					cout << "fathername" << endl;
					cout << "id" << endl;
					cout << "passport" << endl;
					cout << "-> ";
					cin.getline(buf, 50);
					char *menu_sort = new char[strlen(buf) + 1];
					strcpy(menu_sort, buf);
					if (strcmp(menu_sort, surename) == 0)//сортировка по фамилии
					{
						ShowLine();
						sortSurenameReader(arrReade, sizeReader);
						showAll(arrReade, sizeReader);
					}
					else if (strcmp(menu_sort, name) == 0)//сортировка по имени
					{
						ShowLine();
						sortNameReader(arrReade, sizeReader);
						showAll(arrReade, sizeReader);
					}
					else if (strcmp(menu_sort, fathername) == 0)//сортировка по отчеству
					{
						ShowLine();
						sortFatherNameReader(arrReade, sizeReader);
						showAll(arrReade, sizeReader);
					}
					else if (strcmp(menu_sort, id) == 0)//сортировка по ID
					{
						ShowLine();
						sortIdReader(arrReade, sizeReader);
						showAll(arrReade, sizeReader);
					}
					else if (strcmp(menu_sort, passport) == 0)//сортировка по поспорту
					{
						ShowLine();
						sortNumberPassportReader(arrReade, sizeReader);
						showAll(arrReade, sizeReader);
					}
					delete[] menu_sort;
				}
				else if (strcmp(menu_readers, exit_with_menu) == 0)
				{
					exit_with_menu_readers = true;
				}
				delete[] menu_readers;
			}
		}
		else if (strcmp(main_menu, save) == 0)
		{
			FILE *arrBooksFile = fopen("Arr_BooksFL.bin", "wb");
			if (arrBooksFile)
			{
				writeStructBookInFile(arrBooksFile, arrBooks, sizeBooks);
				fclose(arrBooksFile);
				ShowLine();
				cout << "Your file with book is save!" << endl;
			}

			FILE * arrReaderFile = fopen("Arr_ReadersFL.bin", "wb");
			if (arrReaderFile)
			{
				writeStructReaderInFile(arrReaderFile, arrReade, sizeReader);
				fclose(arrReaderFile);
				ShowLine();
				cout << "Your file with readers is save!" << endl;
			}
		}
		else if ((strcmp(ex, main_menu)) == 0)
		{
			if (sizeReader != 0)
			{
				for (int i = 0;i< sizeReader;i++)
				{
					delete[] arrReade[i].nameReader;
					delete[] arrReade[i].surnameReader;
					delete[] arrReade[i].fatherNameReader;
					if (arrReade[i].sizeId != 0)
					{
						for (int i = 0;i<arrReade[i].sizeId;i++)
							delete[] arrReade[i].take;
					}
				}
				delete[] arrReade;
			}
			if (sizeBooks != 0)
			{
				for (int i = 0; i<sizeBooks; i++)
				{
					delete[] arrBooks[i].authorName;
					delete[] arrBooks[i].genreBook;
					delete[] arrBooks[i].name;
				}
				delete[] arrBooks;
			}

			exit = true;
		}
		delete[] main_menu;
	}
	return 0;
}