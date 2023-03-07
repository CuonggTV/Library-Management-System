#include <stdio.h>
#include <windows.h> 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Login Menu Function.c"
#include "date.c"
#define MAX 100007
//Hellasldasd

bool Register();
bool Login_Cus(char username[]);
//Customer activity
void check_all_Books();
void check_borrowed_Books(char username[]);
void check_avaible_Books();
void borrow_Books(char username[]);
void return_Book(char username[]);


int main(){
	char choice;
	char username[MAX];
	bool success;
	loginMenu: 
    
    system("cls");
    printf("\n\n\n");
    printf("====================================== WELCOME TO LIBRARY ======================================\n\n\n");
    printf("\t\t\t\t\t[1]=> Login as customer\n");
    printf("\n");
    printf("\t\t\t\t\t[2]=> Register as customer\n");
    printf("\n");
    printf("\t\t\t\t\t[3]=> Login as admin\n");
    printf("\n");
    printf("\t\t\t\t\t[4]=> Exit\n\n");
    printf("================================================================================================\n\n");
    printf("\t\t\tEnter Your Choice:: ");
    
    scanf("%c",&choice);
    fflush(stdin);
    switch(choice){
    	case '1':
    		success=Login_Cus(username);
    		if(success) goto CustomerMenu;
    		else goto loginMenu;
    		break;
    	case '2':
    		success=Register();
    		goto loginMenu;
    		break;
    	case '3':
    		Login_Admin();
    		goto AdminMenu;
    	case '4':
    		return 0;
    	default:
		    printf("\n\t\t\tYour choice is incorrect.\n");
		    printf("\t\t\tPlease try again.\n");
		    getchar();
		    fflush(stdin);
		    goto loginMenu;
	}
		
	//Log in as customer
	CustomerMenu:
		system("cls");
        printf("\n\n\n");
        printf("====================================== USER INTERFACE ======================================\n\n\n");
        printf("\t\t\t\t\t[1]=> Check all books.\n");
        printf("\n");
        printf("\t\t\t\t\t[2]=> Check borrowed books.\n");
        printf("\n");
        printf("\t\t\t\t\t[3]=> Check avaible books.\n");
        printf("\n");
        printf("\t\t\t\t\t[4]=> Borrow book.\n");
        printf("\n");
        printf("\t\t\t\t\t[5]=> Return book.\n");
        printf("\n");
        printf("\t\t\t\t\t[6]=> Check your debt.\n\n");
        printf("\n");
        printf("\t\t\t\t\t[7]=> Log out.\n\n");
        printf("============================================================================================\n\n");
        printf("\t\t\tEnter Your Choice:: ");
        scanf("%c",&choice);
        fflush(stdin);
        switch(choice){
    	    case '1':
    		    check_all_Books();
    		    goto CustomerMenu;
    	    case '2':
    		    check_borrowed_Books(username);
    		    goto CustomerMenu;
		    case '3':
		    	check_avaible_Books();
		    	goto CustomerMenu;
		    case '4':
		    	borrow_Books(username);
		    	goto CustomerMenu;
		    case '5':
		    	return_Book(username);
		    	goto CustomerMenu;
		    case '6':
		    	check_debt(username);
		    	goto CustomerMenu;
		    case'7':
		    	goto loginMenu;
		    default:
		    	printf("\t\t\tYour choice is incorrect.\n");
		    	printf("\t\t\tPlease try again.\n");
		        getchar();
		        fflush(stdin);
		        goto CustomerMenu;
	}
	AdminMenu:
		system("cls");
        printf("\n\n\n");
        printf("====================================== ADMIN INTERFACE ======================================\n\n\n");
        printf("\t\t\t\t\t[1]=> Add books.\n");
        printf("\n");
        printf("\t\t\t\t\t[2]=> Check detail of all books.\n");
        printf("\n");
        printf("\t\t\t\t\t[3]=> Check debt of all users.\n\n");
        printf("\n");
        printf("\t\t\t\t\t[4]=> Log out.\n");
        printf("============================================================================================\n\n");
        printf("\t\t\tEnter Your Choice:: ");
        scanf("%c",&choice);
        fflush(stdin);
        switch(choice){
    	    case '1':
    		    addbook();
    		    goto AdminMenu;
    	    case '2':
    		    check_detailofallBooks();
    		    goto AdminMenu;
    		case '3':
    		    check_debtofallusers();
    		    goto AdminMenu;
		    case '4':
		    	goto loginMenu;
		    default:
		    	printf("\t\t\tYour choice is incorrect.\n");
		    	printf("\t\t\tPlease try again.\n");
		        getchar();
		        fflush(stdin);
		        goto CustomerMenu;
	}
	return 0;
}

//void gets_num(char num[]){
//	char get;
//	do{
//		int i = 0;
//	    do{
//		    get=getchar();
//		    if(get>='0' && get <='9'){
//		    	num[i]=get;
//		    	i++;
//			}
//			else break;
//	    }
//	    if(get!='\n'){
//	    	printf("Your enter is wrong. Please enter again.\n");
//		}
//	}while(get!='\n');
//}


void check_all_Books(){
	char extra[MAX];
	FILE *fptr;
	fptr = fopen("Books.txt","r");
	
	//Open file
	if(fptr==NULL){
		printf("Cannot open file\n");
		exit(1);
	}
	
	//Processing 
	Book b;
	system("cls");
	while(!feof(fptr)){
		fscanf(fptr,"%[^,], %[^,], %[^\n]\n",b.title,b.author,extra);
		printf("\t\t\t\t'%s' by %s.\n",b.title,b.author);
	}
	
	fclose(fptr);
	getchar();
	fflush(stdin);
}

void check_borrowed_Books(char username[]){
	char extra[MAX];
	FILE *fptr;
	fptr = fopen("Books.txt","r");
	
	//Open file
	if(fptr==NULL){
		printf("Cannot open file\n");
		exit(1);
	}
	
	//Processing 
	Book b;
	system("cls");
	while(!feof(fptr)){
		fscanf(fptr,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n"
		,b.title,b.author,b.user,b.name,b.phonenumber,b.day_receive,b.month_receive,b.day_retrieve,b.month_retrieve);
		if(!strcmp(username,b.user)){
			printf("\t\t\t\t'%s' by %s.\n",b.title,b.author);
			printf("\t\t\t\tYour return date is: %s/%s.\n\n",b.day_retrieve,b.month_retrieve);
		}
	}
	fclose(fptr);
	getchar();
	fflush(stdin);
}

void check_avaible_Books(){
	char extra[MAX];
	char check;
	char check_done[3];
	FILE *fptr;
	fptr  = fopen("Books.txt","r");
	//Open file
	if(fptr==NULL){
		printf("Cannot open file.\n");
		exit(1);
	}
	
	//Processing 
	Book B;
	
	system("cls");
	printf("Avaible books: \n");
	while(!feof(fptr)){
		fscanf(fptr,"%[^,], %[^,], %[^,], %[^\n]\n",B.title,B.author,B.user,extra);
		if(!strcmp("0",B.user)){
			printf("\t\t\t\t'%s' by %s.\n",B.title,B.author);
		}
	}
	fclose(fptr);
	getchar();
	fflush(stdin);
}

void borrow_Books(char username[]){
	FILE *fptr,*tptr;
	char s_book_title[MAX];
	bool nothave=true;
	fptr = fopen("Books.txt","r");
	tptr = fopen("temp.txt","w");
	
	//Open file
	if(fptr==NULL){
		printf("Cannot open file\n");
		exit(1);
	}
	
	//Find title book
	Book b;
	system("cls");
	
	printf("\t\t\t\tEnter book's title: ");
	scanf("%[^\n]",s_book_title);
	
	while(!feof(fptr)){
		fscanf(fptr,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n"
		,b.title,b.author,b.user,b.name,b.phonenumber,b.day_receive,b.month_receive,b.day_retrieve,b.month_retrieve);
		//Neu tim thay va ko co ai muon
		if(!strcmp(b.title,s_book_title) && !strcmp("0",b.user)){
			strcpy(b.user,username);
			fflush(stdin);
			printf("\n");
			printf("\t\t\t\tEnter your name: ");scanf("%[^\n]",b.name);
			printf("\t\t\t\tEnter your phone number: ");scanf("%s",b.phonenumber);
			
			//Check valid date
			do{
				fflush(stdin);
				printf("\n\n");
				printf("\t\t\t\tEnter your day you borrow: ");scanf("%s",b.day_receive);
			    printf("\t\t\t\tEnter your month you borrow: ");scanf("%s",b.month_receive);
			}while(!check_valid_date(atoi(b.day_receive),atoi(b.month_receive)));
			
			int day_retrieve = atoi(b.day_receive);
			int month_retrieve = atoi(b.month_receive);
			day_retrive(&day_retrieve,&month_retrieve);
			
			itoa(day_retrieve,b.day_retrieve,10);
			itoa(month_retrieve,b.month_retrieve,10);
			
			//Change detail of book
			fprintf(tptr,"%s, %s, %s, %s, %s, %s, %s, %s, %s\n"
			,b.title,b.author,username,b.name,b.phonenumber,b.day_receive,b.month_receive,b.day_retrieve,b.month_retrieve);
			nothave=false;
			
			//Annouce borrow success 
			printf("\n\n");
			printf("\t\t\t\tYour borrowing was successful!\n");
			printf("\t\t\t\tYour retrieve date after 3 weeks is: %s/%s\n",b.day_retrieve,b.month_retrieve);
			printf("\t\t\t\tPlease return your book on time. If not, you will get a penalty!\n");
			continue;
		}
		
		//Neu tim thay nhung co ng muon
		else if(!strcmp(b.title,s_book_title) && strcmp("0",b.user)){
			printf("\n");
			printf("\t\t\t\tSorry, this book has been borrowed.\n");
			nothave=false;
		}
		//Copy to other file
		fprintf(tptr,"%s, %s, %s, %s, %s, %s, %s, %s, %s\n"
		,b.title,b.author,b.user,b.name,b.phonenumber,b.day_receive,b.month_receive,b.day_retrieve,b.month_retrieve);
	}
	
	fclose(fptr);
	fclose(tptr);
	remove("Books.txt");
	rename("temp.txt","Books.txt");
	
	if(nothave){
		printf("\n");
		printf("\t\t\t\tSorry, we don't have this book.\n");
	}
	getchar();
	getchar();
	fflush(stdin);
}

void return_Book(char username[]){
	check_borrowed_Books(username);
	FILE *fptr,*tptr;
	char s_book_title[MAX];
	bool nothave=true;
	fptr = fopen("Books.txt","r");
	tptr = fopen("temp.txt","w");
	
	//Open file
	if(fptr==NULL){
		printf("Cannot open file\n");
		exit(1);
	}
	
	//Find title book
	Book b;
	
	printf("\t\t\t\tEnter book's title: ");
	scanf("%[^\n]",s_book_title);
	
	while(!feof(fptr)){
		fscanf(fptr,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n"
		,b.title,b.author,b.user,b.name,b.phonenumber,b.day_receive,b.month_receive,b.day_retrieve,b.month_retrieve);
		//Neu tim thay sach minh muon
		if(!strcmp(b.title,s_book_title) && !strcmp(username,b.user)){
			fflush(stdin);
			
			//Nhap ngay de tinh penalty
			int iday_retrieve;
			int imonth_retrieve;
			do{
				fflush(stdin);
				printf("\n\n");
				printf("\t\t\t\tEnter day you return: ");scanf("%d",&iday_retrieve);
			    printf("\t\t\t\tEnter month you return: ");scanf("%d",&imonth_retrieve);
			}while(!check_valid_date(iday_retrieve,imonth_retrieve));
			
			int day_retrieve=atoi(b.day_retrieve);
			int month_retrieve= atoi(b.month_retrieve);
			
			penalty(username,iday_retrieve,imonth_retrieve,day_retrieve,month_retrieve);
			
			//Change detail of book
			fprintf(tptr,"%s, %s, 0, 0, 0, 0, 0, 0, 0\n",b.title,b.author);
			nothave=false;
			continue;
		}
		//Copy to other file
		fprintf(tptr,"%s, %s, %s, %s, %s, %s, %s, %s, %s\n"
		,b.title,b.author,b.user,b.name,b.phonenumber,b.day_receive,b.month_receive,b.day_retrieve,b.month_retrieve);
	}
	
	fclose(fptr);
	fclose(tptr);
	remove("Books.txt");
	rename("temp.txt","Books.txt");
	
	if(nothave){
		printf("\t\t\t\tYou didn't borrow this book yet.\n");
	}
	
	getchar();
	getchar();
	fflush(stdin);
	
}



