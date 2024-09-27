#include <stdio.h>
#include <stdlib.h>
#include "declareBOOK.h"

void main(){
	count = 6;
	resize = 0;
	int size = 8;
	Book* book = (Book*)malloc(sizeof(Book)*size);
	
	book[0].id = 101;
	strcpy(book[0].name,"atomic habits");
	strcpy(book[0].author,"james clear");
	book[0].price = 500;
	book[0].rating = 4;
	strcpy(book[0].category,"management");
	
	book[1].id = 102;
	strcpy(book[1].name,"rich dad poor dad");
	strcpy(book[1].author,"robert kiyosaki");
	book[1].price = 300;
	book[1].rating = 5;
	strcpy(book[1].category,"finance");
	
	book[2].id = 103;
	strcpy(book[2].name,"art of war");
	strcpy(book[2].author,"sun tzu");
	book[2].price = 400;
	book[2].rating = 3;
	strcpy(book[2].category,"management");
	
	book[3].id = 106;
	strcpy(book[3].name,"power of subconcious mind");
	strcpy(book[3].author,"joseph murphy");
	book[3].price = 490;
	book[3].rating = 5;
	strcpy(book[3].category,"improvement"); 
	
	book[4].id = 107;
	strcpy(book[4].name,"think and grow rich");
	strcpy(book[4].author,"nepolean hill");
	book[4].price = 350;
	book[4].rating = 4;
	strcpy(book[4].category,"finance");
	
	book[5].id = 104;
	strcpy(book[5].name,"the girl who knew too much");
	strcpy(book[5].author,"vikrant khanna");
	book[5].price = 250;
	book[5].rating = 2;
	strcpy(book[5].category,"fiction");
	
	int choice;
	do{
		printf("\n\n\t\t\t\t\tBook Management");
		printf("\n\t\t\t\t_______________________________");
		printf("\n\n___MENU___\n\n1. Store Book Info.\n2. Display all Book info.\n3. Search Book.\n4. Update book info.\n5. Delete book info.\n6. Sort Book.\n7. Exit.");
		printf("\nEnter your choice = ");
		scanf("%d",&choice);
		printf("\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --");
		
		if(choice>=1 && choice<=7){
		switch(choice)
		{
			case 1:{
				int len;
				printf("\nEnter numer of book u want to store = ");
				scanf("%d",&len);
				if(count >= (size+resize) || (size+resize)<(count+len)){
					char ans;
					printf("\nBook storage is full. Do you want to increase size. Type y or n?");
					printf("\nEnter Your Choice => ");
					fflush(stdin);
					scanf("%c",&ans);
					if(ans == 'y'){
						book = increaseStorage(book,size);
						printf("\nSize increased successfully.");
					}else if(ans == 'n'){
						continue;
					}else{
						printf("\nInvalid choice.");
					}	
				}
				else{
					storeBook(book,len);
				}
				break;
			}
			case 2:{
				displayAll(book);
				break;
			}
			case 3:{
				int sel;
				printf("\nHow you want to search :-\n1. Search By Book ID.\n2. Search By Book name.\n3. Search By Author.\n4. Search By Category");
				printf("\nEnter choice = ");
				scanf("%d",&sel);
				if(sel == 1){
					int in_id,i;
					printf("\nEnter book id = ");
					scanf("%d",&in_id);
					i= searchId(book,in_id);
					if(i==-1){
						printf("\nSorry, Book not found");
					}else{
						displayOneBook(book,i);
					}
				}
				else if(sel==2){
					char in_name[30];
					printf("\nEnter Book name or a word form book name = ");
					fflush(stdin);
					gets(in_name);
					strlwr(in_name);
					printf("\n\nRESULT :-");
					searchName(book,in_name);
				}
				else if(sel ==3){
					char in_author[30];
					printf("\nEnter Author name = ");
					fflush(stdin);
					gets(in_author);
					strlwr(in_author);
					printf("\n\nRESULT :-");
					searchAuthor(book,in_author);
				}
				else if(sel == 4){
					char in_category[30];
					printf("\nEnter Category = ");
					fflush(stdin);
					gets(in_category);
					strlwr(in_category);
					printf("\n\nRESULT :-");
					searchCategory(book, in_category);
				}
				else{
					printf("\nInvalid choice");
				}
				break;
			}
			case 4:{
				int ch,in_id,index;
				printf("\nChosse what to update?\n1. Price\n2. Ratings");
				printf("\nEnter your choice = ");
				scanf("%d",&ch);
				printf("\nEnter book ID = ");
				scanf("%d",&in_id);
				index = searchId(book,in_id);
				if(index==-1){
						printf("\nSorry, Book not found");
				}
				else{
					if(ch==1){
						updatePrice(book,index);
					}else if(ch==2){
						updateRatings(book,index);
					}else{
						printf("\nInvalid choice");
					}
				}
				break;
			}
			case 5:{
				int in_id,index;
				printf("\nEnter book id = ");
				scanf("%d",&in_id);
				index = searchId(book,in_id);
				if(index==-1){
					printf("\nSorry, there is no book with such book ID.");
				}else{
					deleteBook(book,index);
				}
				break;
			}
			case 6:{
				int in;			
				printf("\nHow you want to sort :-\n1. Sort By Id.\n2. Sort By Price.\n3. Sort By Ratings.\n4. Sort By Name");
				printf("\nEnter choice = ");
				scanf("%d",&in);
				if(in==1){
					sortById(book);
				}else if(in==2){
					sortByPrice(book);
				}else if(in==3){
					sortByRatings(book);
				}else if(in==4){
					sortByName(book);
				}else{
					printf("\nInvalid Choice");
				}
				break;
			}
			}
		}else if(choice>=8){
			printf("\nInvalid choice.");
		}
	}while(choice!=7);
	
	printf("\n\t\t\t|| Thanks For Using Book Management System :) ||");	
}
