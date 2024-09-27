#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int count, resize;
typedef struct Book{
	int id;
	char name[30];
	char author[20];
	char category[20];
	double price;
	int rating;
}Book;

//void storeBook(Book*,int);
//void displayAll(Book*);
void updatePrice(Book*,int);
void updateRatings(Book*, int);
//void deleteBook(Book*,int);
void sortById(Book*);
void sortByPrice(Book*);
void sortByRatings(Book*);
void sortByName(Book*);
//int searchId(Book*,int);
//void searchName(Book*,char*);
//void searchAuthor(Book*,char*);
//void searchCategory(Book*, char*);
//void displayOneBook(Book*,int);
void swap(Book*,int,int);
Book* increaseStorage(Book*,int);
