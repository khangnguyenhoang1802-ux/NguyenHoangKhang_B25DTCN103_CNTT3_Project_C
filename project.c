#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char empId[20];
	char name[50];
	char position[15];
	double baseSalary;
	int workDay;
} employee;

typedef struct {
	char logId[20];
	char empId[20];
	char date[20];
	char status[10];
} timesheet;

void inputNStudents();
int employeesIdExisted(char stuId[]);
int validateDay(int day, int month, int year);
int validateMonth(int month);
int validateYear(int year);

void addInfoEmployees;
void updateProfile;
void layOffEmployees;


int main(){
	int choice;
	
	do{
		printf("\n=================== MENU ===================\n");
		printf("\|n1. Them nhan vien moi");
        printf("\|n2. Cap nhat ho so nhan vien");
        printf("\|n3. Sa thai nhan vien");
        printf("\|n4. Hien thi danh sach nhan vien");
        printf("\|n5. Tra cuu nhan vien");
        printf("\|n6. Sap xep danh sach nhan vien theo luong co ban");
        printf("\|n7. Cham cong ngay");
        printf("\|n8. Xem bang cong");
        printf("\|n9. Thoat");
        printf("==============================================");
        
        printf("\nMoi nhap: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                inputNStudents();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                addStudentToLast();
                break;
            case 4:
                deleteStudentById();
                break;
            case 5:
                updateStudentById();
                break;
            case 6:
                sortStudentsByName();
                break;
            case 7:
                searchStudentById();
                break;
            case 8:
            	
            	break;
            case 9:
                exit(0);
            default:
                printf("\nLoi - Khong nhap tu 1 den 8");
        }
	}
}

