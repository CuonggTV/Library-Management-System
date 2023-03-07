#include <stdio.h>
#include <windows.h> 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100007
struct BookDetails{
	char title[MAX];
	char author[MAX];
	char user[MAX];
	char name[MAX];
	char phonenumber[11];
	char day_receive[11];
	char month_receive[11];
	char day_retrieve[11];
	char month_retrieve[11];
} typedef Book;
struct Account_Details{
	char username[MAX];
	char password[MAX];
	char pen[MAX];
}typedef Account;

bool Login_Cus(char username[]){
	FILE *fptr;
	char con = '1';
	
	//Open file
	fptr = fopen("Cus account.txt","r");
	if(fptr ==NULL){
		printf("Cannot open file\n");
		exit(1);
	}
	
	//Search for customer
	Account p,p1;
	bool exist = false;
	
		system("cls");
		fflush(stdin);
		printf("\t\t\t\t\tEnter username: ");scanf("%s",p.username);
        printf("\t\t\t\t\tEnter password: ");scanf("%s",p.password);
        fflush(stdin);
		while(!feof(fptr)){
			//o CUOI FILE NEN BI BRUH
		    fscanf(fptr,"%s %s %s\n",p1.username,p1.password,p1.pen);
		
		    if(!strcmp(p.username,p1.username) && !strcmp(p.password,p1.password)){
			    exist = true;
		    }
	    }

		if(!exist){
		    fflush(stdin);
		    printf("\n\n");
		    printf("\t\t\t\t\tWrong username or password!\n");
	    	printf("\t\t\t\t\tPress anykey to continue.\n");
	    	printf("\t\t\t\t\tPress 0 to return.\n");
	        con = getchar();
	    	fflush(stdin);
		    if(con=='0') return false;
		    else return Login_Cus(username);
		}
	
	strcpy(username,p.username);
	fclose(fptr);
	printf("\n\t\t\t\t\tCongratulation! Log in successful!\n");
	getchar();
	fflush(stdin);
	return true;
}
bool Register(){
	FILE *fptr;
	char con = '1';
	Account p,p1;
	bool exist = false;
	
	//Open file
	fptr = fopen("Cus account.txt","r+");
	if(fptr ==NULL){
		printf("Cannot open file\n");
		exit(1);
	}
	
	do{
		system("cls");
	    printf("\t\t\t\t\tEnter username: ");scanf("%s",&p.username);
        printf("\t\t\t\t\tEnter password: ");scanf("%s",&p.password);
        //Find if the username exists or not
        while(!feof(fptr)){
		    fscanf(fptr,"%s %s %s\n",p1.username,p1.password,p1.pen);
		    if(!strcmp(p.username,p1.username)){
			   exist = true;
		    }
	    }
	    if(exist){
		    system("cls");
		    fflush(stdin);
	    	printf("\t\t\t\t\tUsername is already registed!\n");
	    	printf("\t\t\t\t\tPress anykey to continue.\n");
	    	printf("\t\t\t\t\tPress 0 to return.\n");
	    	scanf("%c",&con);
	    	fflush(stdin);
	    	if(con=='0') return false; 
		}
    }while(exist);
    printf("\t\t\t\t\tRegister successful!\n");
    fprintf(fptr,"%s %s\n",p.username,p.password);
    
    getchar();
    fclose(fptr);
    return true ;
}
bool Login_Admin(){
	FILE *fptr;
	char con = '1';
	
	//Open file
	fptr = fopen("Admin account.txt","r");
	if(fptr ==NULL){
		printf("Cannot open file\n");
		exit(1);
	}
	
	//Search for customer
	Account p,p1;
	bool exist = false;
		system("cls");
		fflush(stdin);
		printf("\t\t\t\t\tEnter username: ");scanf("%s",p.username);
        printf("\t\t\t\t\tEnter password: ");scanf("%s",p.password);
        fflush(stdin);
		while(!feof(fptr)){
			//o CUOI FILE NEN BI BRUH
		    fscanf(fptr,"%s %s\n",p1.username,p1.password,p1.pen);
		
		    if(!strcmp(p.username,p1.username) && !strcmp(p.password,p1.password)){
			    exist = true;
		    }
	    }

		if(!exist){
		    fflush(stdin);
		    printf("\n\n");
		    printf("\t\t\t\t\tWrong username or password!\n");
	    	printf("\t\t\t\t\tPress anykey to continue.\n");
	    	printf("\t\t\t\t\tPress 0 to return.\n");
	        con = getchar();
	    	fflush(stdin);
		    if(con=='0') return false;
		    else return Login_Admin();
		}
	
	fclose(fptr);
	printf("\n\t\t\t\t\tCongratulation! Log in successful!\n");
	getchar();
	fflush(stdin);
	return true;
}

void addbook(){
	FILE *fptr;
	char con = '1';
	char extra[MAX];
	Book p,p1;
	bool exist = false;
	
	//Open file
	fptr = fopen("Books.txt","r+");
	if(fptr ==NULL){
		printf("Cannot open file\n");
		exit(1);
	}
	
	do{
		system("cls");
	    printf("\t\t\t\t\tEnter book's title: ");scanf("%s",&p.title);
        printf("\t\t\t\t\tEnter author's name: ");scanf("%s",&p.author);
        //Find if the username exists or not
        while(!feof(fptr)){
		    fscanf(fptr,"%[^,], %[^,] %[^\n]\n",p1.title,p1.author,extra);
		    if(!strcmp(p.title,p1.title)){
			   exist = true;
		    }
	    }
	    if(exist){
		    system("cls");
		    fflush(stdin);
	    	printf("\t\t\t\t\tWe already have this book.\n");
	    	printf("\t\t\t\t\tPress anykey to continue.\n");
	    	printf("\t\t\t\t\tPress 0 to return.\n");
	    	scanf("%c",&con);
	    	fflush(stdin);
	    	if(con=='0') return; 
		}
    }while(exist);
    printf("\t\t\t\t\tAdd book successful!\n");
    fprintf(fptr,"%s, %s, 0, 0, 0, 0, 0, 0, 0\n",p.title,p.author);
    
    getchar();
    fclose(fptr);
    return;
}

void check_detailofallBooks(){
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
		printf("'%s' by %s.\n",b.title,b.author);
		if(strcmp(b.user,"0")){
			printf("\t\t\t\tThis book was borrewed by user '%s'.\n",b.user);
			printf("\t\t\t\tHis/Her name is %s.\n",b.name);
			printf("\t\t\t\tHis/Her phonenumber is %s.\n",b.phonenumber);
			printf("\t\t\t\tHe/She borrow this book on %s/%s.\n",b.day_receive,b.month_receive);
			printf("\t\t\t\tHe/She will return this book on %s/%s.\n",b.day_retrieve,b.month_retrieve);
		}
		else{printf("\t\t\t\tThis book is still availbe.\n");
		}
	}
	
	fclose(fptr);
	getchar();
	fflush(stdin);
}

void check_debtofallusers(){
	FILE *fptr;
	
	//Open file
	fptr = fopen("Cus account.txt","r");
	if(fptr ==NULL){
		printf("Cannot open file\n");
		exit(1);
	}
	
	//Search for customer
	Account p1;
	
		system("cls");
		fflush(stdin);
		while(!feof(fptr)){
			//o CUOI FILE NEN BI BRUH
		    fscanf(fptr,"%s %s %s\n",p1.username,p1.password,p1.pen);
		    printf("\t\t\t\t%s is in %s.000VND debt.\n",p1.username,p1.pen);
	    }
	
	fclose(fptr);
	getchar();
	fflush(stdin);
	return ;
}
void check_debt(char username[]){
	FILE *fptr;
	
	//Open file
	fptr = fopen("Cus account.txt","r");
	if(fptr ==NULL){
		printf("Cannot open file\n");
		exit(1);
	}
	
	//Search for customer
	Account p1;
	
		system("cls");
		fflush(stdin);
		while(!feof(fptr)){
			//o CUOI FILE NEN BI BRUH
		    fscanf(fptr,"%s %s %s\n",p1.username,p1.password,p1.pen);
		    if(!strcmp(username,p1.username)){
		    	printf("\t\t\t\tYour are in %s.000VND debt.\n",p1.pen);
			}
		    
	    }
	
	fclose(fptr);
	getchar();
	fflush(stdin);
	return ;
}

