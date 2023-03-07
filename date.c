#include <stdio.h>
#include <windows.h> 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100007
bool check_valid_date(int day,int month){
	if(day<1 || month<1 || month>12){
		return false;
	}
	switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(day>31) return false;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(day>30) return false;
			break;
		case 2:
			if(day>29) return false;
			break;
	}
	return true;
}

void day_retrive(int* day,int* month){
	*day+=21;
	switch(*month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(*day>31){
				*day-=31;
				*month+=1;
			} 
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(*day>30){
			    *day-=30;
			    *month+=1;
			}
			break;
		case 2:
			if(*day>29) {
				*day-=29;
				*month+=1;
			}
			break;
	}
	if(*month>12) *month=1;
	return;
}
void penalty(char username[],int iday,int imonth,int day, int month){
	if(iday<=day && imonth<=month){
		printf("\n\t\t\t\tReturn book successful! Thanks you for using our services.\n");
		return;
	}
	int countday=0;
	while(imonth!=month){
		switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			countday += 31-iday;
			iday=1;
			imonth++;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			countday += 30-iday;
			iday=1;
			imonth++;
			break;
		case 2:
			countday += 29-iday;
			iday=1;
			imonth++;
			break;
	    }
	    if(imonth>12) imonth=1;
	}
	countday += day-iday;
	
	FILE *fptr,*tptr;
	Account p1;
	
	//Open file
	fptr = fopen("Cus account.txt","r+");
	tptr = fopen("temp.txt","w");
	if(fptr==NULL){
		printf("Cannot open file\n");
		exit(1);
	}
	
    while(!feof(fptr)){
		fscanf(fptr,"%s %s %s",p1.username,p1.password,p1.pen);
		if(!strcmp(username,p1.username)){
		   itoa(countday*5,p1.pen,10);
		   printf("\t\t\t\tYour penalty for returning book late is %d 000VND.\n",countday*5);
	    }
	    fprintf(tptr,"%s %s %s\n",p1.username,p1.password,p1.pen);
	}

    fclose(fptr);
	fclose(tptr);
	remove("Cus account.txt");
	rename("temp.txt","Cus account.txt");
    
    getchar();
    fclose(fptr);
}
