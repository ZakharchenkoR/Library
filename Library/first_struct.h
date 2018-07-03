#pragma once
//
//  first_struct.hpp
//  Library
//
//  Created by Роман Захарченко  on 5/12/18.
//  Copyright © 2018 Роман Захарченко . All rights reserved.
//

#ifndef first_struct_hpp
#define first_struct_hpp
#include "second_struct.h"

struct Book
{
	int dayIssue;
	int mounthIssue;
	int yearIssue;
	char *name;
	char *authorName;
	char *genreBook;
	double priceBook;
	double ratingBook;
	int id;
	bool on_hands = false;
	int dayBookTaking;
	int mounthBookTaking;
	int yearBookTaking;
};



void fillBook(Book&obj, int&id_books);
void showBook(Book&obj);
void fullEditing(Book*&obj, int&size);
void notFullEditing(Book*&obj, int&size);
void AddBook(Book*&arr, int & size, int&id_books);
void showAll(Book*arr, int size);
void addInArray(Book*&arr, int & size);
void sortArrayAuthorName(Book*&arr, int size);
void sortArrayNameNameBook(Book*&arr, int size);
void sortArrayNameGenreBook(Book*&arr, int size);
void sortArrayRatingGenreBook(Book*&arr, int size);
void lookingBookAuthorName(Book*&arr, int&size);
void lookingBookNameBook(Book*&arr, int&size);
void lookingBookGenreBook(Book*&arr, int&size);
void lookingBookPopulariryBook(Book*&arr, int&size);
void booksOnHands(Book*&arr, int&size);
void deleteBook(Book*&arr, int&size);
void takeBook(Reader*&arrRaeder, int&sizeReader, Book*&arrBook, int&sizeBook, int yourChoiceIdReader, int yourChoiceIdBook);
void returnBook(Reader*&arrRaeder, int&sizeReader, Book*&arrBook, int&sizeBook, int IdReaderForReturn, int IdBookForReturn, double penalty);
void listBooksOnHands(Reader*&arrReader, int&sizeReader, Book*&arrBook, int&sizeBook, int idReader);
void dataBookTaking(Book*&arrBook, int&sizeBook, int positionBook);
void dataReturnBookOnLibrary(Book*&arrBook, int&sizeBook, int positionIdBook, Reader*&arrReader, int positionIdReader, double const penalty);
void popylarytyBookInGenre(Book*&arr, int&size, char genre[]);
#endif /* first_struct_hpp */
