#include "declareBOOK.h" 

// incresase size of array

Book* increaseStorage(Book* book, int size){
	int num;
	printf("Enter number of slots you want to increase = ");
	scanf("%d",&num);
	resize = num;
	Book* ptr = realloc(book,(size+num)*sizeof(Book));
	return ptr;
}


//print one book.
void displayOneBook(Book* book, int x){
	printf("\nBook id \t= %d",book[x].id);
	printf("\nBook name \t= %s",book[x].name);
	printf("\nBook Author \t= %s",book[x].author);
	printf("\nBook price \t= %.2lf",book[x].price);
	printf("\nBook's rating \t= %d",book[x].rating);
	printf("\nBook's category = %s",book[x].category);
	printf("\n-----------------------------------------------------");
} 
// Store book data
void storeBook(Book* book,int len){
		int i;
		len=len+count;
		for(i=count;i<len;i++){
			printf("\nEnter book id = ");
			scanf("%d",&book[i].id);
			
			printf("Enter book name = ");
			scanf("%s",&book[i].name);
			strlwr(book[i].name);
			
			printf("Enter book author = ");
			scanf("%s",&book[i].author);
			strlwr(book[i].author);
			
			printf("Enter book price = ");
			scanf("%lf",&book[i].price);
			
			printf("Enter book rating = ");
			scanf("%d",&book[i].rating);
			
			printf("Enter book category = ");
			scanf("%s",&book[i].category);
			strlwr(book[i].category);
			
			count++;
		}
		printf("\n\n==> Book added successfully");
	}



//print book data
void displayAll(Book* book){
	int j=0;
	printf("\nList of Book :-");
	printf("\n_____________________________________________________");
	for(j=0;j<count;j++){
		printf("\nBook id \t= %d",book[j].id);
		printf("\nBook name \t= %s",book[j].name);
		printf("\nBook Author \t= %s",book[j].author);
		printf("\nBook price \t= %.2lf",book[j].price);
		printf("\nBook's rating \t= %d",book[j].rating);
		printf("\nBook's category = %s",book[j].category);
		printf("\n-----------------------------------------------------|");
	}
}

int searchId(Book* book, int in_id){
	int i;
	for(i=0;i<count;i++){
		if(book[i].id == in_id){
			return i;
		}
		}
	return -1;
}

void searchName(Book* book, char* in_name){
	int j,f=0;
	for(j=0;j<count;j++){
		if(strstr(book[j].name,in_name) != NULL){
			displayOneBook(book,j);
			printf("\n");
			f++;
		}
	}
	if(f==0){
		printf("\nSorry, the book you are looking for is not available.");
	}
}

void searchAuthor(Book* book, char* in_author){
	int j,f=0;
	for(j=0;j<count;j++){
		if(strstr(book[j].author,in_author) != NULL){
			displayOneBook(book,j);
			printf("\n");
		f++;
		}
	}
	if(f==0){
		printf("\nSorry, the book you are looking for is not available.");
	}
}
		
void searchCategory(Book* book, char* in_category){
	int j,f=0;
	for(j=0;j<count;j++){
		if(strstr(book[j].category,in_category) != NULL){	
			displayOneBook(book,j);
			printf("\n");
		f++;
		}
	}
	if(f==0){
		printf("\nSorry, the book you are looking for is not available.");
	}
}

//Update book price and rating

void updatePrice(Book* book, int index){
	int new_price;
	printf("Current Price => %.2lf",book[index].price);
	printf("\nEnter new price = ");
	scanf("%d",&new_price);
	book[index].price = new_price;
	displayOneBook(book,index);
	printf("\n\n=> New Price Updated Successfully");
}
void updateRatings(Book* book, int index){
	int new_rating;
	printf("Current Rating => %d",book[index].rating);
	printf("\nEnter new rating = ");
	scanf("%d",&new_rating);
	book[index].rating = new_rating;
	displayOneBook(book,index);
	printf("\n\n=> New Rating Updated Successfully");
}

//Delete Book info
void deleteBook(Book* book,int index){
		for(;index<count;index++){
			book[index]=book[index+1];
		}
		printf("\n=> Book deleted successfully.");
		count--;
	}	

//sort Book
void sortById(Book* book){
			int ch;
			printf("\nHow you want to sort.\n1.Min to Max ID.\n2.Max to Min ID.");
			printf("\nEnter choice = ");
			scanf("%d",&ch);
			if(ch==1){
				int i,j;
				for(i=0;i<count;i++){
					for(j=i+1;j<count;j++){
						if(book[i].id > book[j].id){
							swap(book,i,j);
						}			
					}
				}
				printf("\n\n==> Sorting Completed. ");
				displayAll(book);
			}else{
				int i,j;
				for(i=0;i<count;i++){
					for(j=i+1;j<count;j++){
						if(book[i].id < book[j].id){
							swap(book,i,j);
						}			
					}
				}
			}
			printf("\n\n==> Sorting Completed. ");
			displayAll(book);
}

void sortByPrice(Book* book){
	int ch;
	printf("\nHow you want to sort.\n1.Min to Max Price.\n2.Max to Min Price.");
	printf("\nEnter choice = ");
	scanf("%d",&ch);
		if(ch==1){
			int i,j;
			for(i=0;i<count;i++){
				for(j=i+1;j<count;j++){
					if(book[i].price > book[j].price){
						swap(book,i,j);
					}			
				}
			}
			printf("\n\n=> Sorting Completed. ");
			displayAll(book);
	}else{
		int i,j;
		for(i=0;i<count;i++){
			for(j=i+1;j<count;j++){
				if(book[i].price < book[j].price){
					swap(book,i,j);
				}			
			}
		}
		}
		printf("\n\n=> Sorting Completed. ");
		displayAll(book);
}
void sortByRatings(Book* book){
	int chose;
	printf("\nHow you want to sort.\n1.Min to Max Ratings.\n2.Max to Min Ratings.");
	printf("\nEnter choice = ");
	scanf("%d",&chose);
	if(chose==1){
		int i,j;
		for(i=0;i<count;i++){
			for(j=i+1;j<count;j++){
				if(book[i].rating > book[j].rating){
					swap(book,i,j);
				}			
			}
		}
		printf("\n\n=> Sorting Completed. ");
		displayAll(book);
	}else if(chose==2){
		int i,j;
		for(i=0;i<count;i++){
			for(j=i+1;j<count;j++){
				if(book[i].rating < book[j].rating){
					swap(book,i,j);
				}			
			}
		}
	}else{
		printf("\nInvalid choice");
	}
	printf("\n\n=> Sorting Completed. ");
	displayAll(book);
}
void sortByName(Book* book){
	int i,j,ch;
	printf("\nHow you want to sort.\n1.Ascending order.\n2.Descending order.");
	printf("\nEnter choice = ");
	scanf("%d",&ch);
	if(ch==1){
		for(i=0;i<count;i++){
			for(j=i+1;j<count;j++){
				if(strcmp(book[i].name,book[j].name) == 1){
					swap(book,i,j);
				}	
			}
		}
		printf("\n\n=> Sorting Completed. ");
		displayAll(book);	
	}else if(ch==2){
		for(i=0;i<count;i++){
			for(j=i+1;j<count;j++){
				if(strcmp(book[i].name,book[j].name) == -1){
					swap(book,i,j);
				}	
			}
		}
		printf("\n\n=> Sorting Completed. ");
		displayAll(book);
	}else{
		printf("\nInvalid choice");
	}
}

//swap
void swap(Book* book,int i,int j){
	Book temp = book[j];
	book[j]=book[i];
	book[i]=temp;
}
