//
//  second_struct.hpp
//  Library
//
//  Created by Роман Захарченко  on 5/12/18.
//  Copyright © 2018 Роман Захарченко . All rights reserved.
//

#ifndef second_struct_hpp
#define second_struct_hpp
#include "first_struct.h"
struct Reader
{
	char *surnameReader;
	char *nameReader;
	char *fatherNameReader;
	int dayBirths;
	int mounthBirths;
	int yearBirths;
	int numberPasport;
	int id_reader;
	int numberBookRead = 0;
	int *take;
	int sizeId = 0;
	int overdue_days;
	int penalty = 0;
	double penaltyOfBook = 15.5;
};
void fillReader(Reader&obj, int&id_r);
void showReader(Reader&obj);
void AddReader(Reader*&arr, int & size, int&id_r);
void showAll(Reader*arr, int size);
void addInArray(Reader*&arr, int & size);
void notFullEditing(Reader*&obj, int&size);
void fullEditing(Reader*&obj, int&size);
void sortArray(Reader*&arr, int&size);
void activeReaders(Reader*&arr, int&size);
void deleteReader(Reader*&arr, int&size);
void lookingReaderSurename(Reader*&arr, int&size, char surname[]);
void lookingReaderName(Reader*&arr, int&size, char name[]);
void lookingReaderFatherName(Reader*&arr, int&size, char fathername[]);
void lookingNumberBookRead(Reader*&arr, int&size, int numberBookRead);
void lookingReaderId(Reader*&arr, int&size, int id);
void lookingNumberPasspornReader(Reader*&arr, int&size, int numberPassport);
void lookingPenaltyReaders(Reader*&arr, int&size, double penalty);
void sortNumberPassportReader(Reader*&arr, int&size);
void sortIdReader(Reader*&arr, int&size);
void sortNumberReadBook(Reader*&arr, int&size);
void sortFatherNameReader(Reader*&arr, int&size);
void sortNameReader(Reader*&arr, int&size);
void sortSurenameReader(Reader*&arr, int&size);
#endif /* second_struct_hpp */
#pragma once
