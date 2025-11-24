#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_EMP 100
#define MAX_TS 1000

typedef struct {
        char empId[20];
        char name[50];
        char position[15];
        double baseSalary;
        int workDay;
}employee;

typedef struct {
        char logId[20];
        char empId[20];
        char date[20];
        char status[10];
}timeSheet;

employee employees[MAX_EMP];
timeSheet timeSheets[MAX_TS];
int empCount = 0;
int tsCount = 0;

void addEmployee();
void updateEmployee();
void deleteEmployee();
void printEmployees();
void searchEmployee();
void sortEmployees();
void clockIn();
void viewTimeSheet();

void removeNewline(char str[]);
int  findEmployeeIndex(char id[]);

int main(){
    int choice;

    do{
        printf("\n====================== MENU ======================");
        printf("\n|1. Them nhan vien moi                           |");
        printf("\n|2. Cap nhat ho so nhan vien                     |");
        printf("\n|3. Sa thai nhan vien                            |");
        printf("\n|4. Hien thi danh sach nhan vien                 |");
        printf("\n|5. Tra cuu nhan vien                            |");
        printf("\n|6. Sap xep danh sach nhan vien theo luong co ban|");
        printf("\n|7. Cham cong ngay                               |");
        printf("\n|8. Xem bang cong                                |");
        printf("\n|9. Thoat                                        |");
        printf("\n==================================================");

        printf("\nMoi ban chon chuc nang: ");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:{
                addEmployee();
                break;
            }    
            case 2:{
                updateEmployee();
                break;
            }
            case 3:{
                deleteEmployee;
                break;
            }
            case 4:{
                printEmployees;
                break;
            } 
            case 5:{
                searchEmployee;
                break;
            }
            case 6:{
                sortEmployees;
                break;
            }
            case 7:{
                clockIn;
                break;
            }
            case 8:{
                    viewTimeSheet;
                    break;
            }
            case 9:{
                printf("Cam on vi da den!hihi");
                return 0;
                break;
            }
            default:{
                printf("\nLoi - Ban chi duoc nhap tu 1 den 9");
            }
        }
    }while(1);
}

void removeNewline(char str[]){
    str[strcspn(str, "\n")] = '\0';
}

int findEmployeeIndex(char id[]){
    for(int i = 0; i < empCount; i++){
        if(strcmp(employees[i].empId, id) == 0){
            return i;
        }
    }
    return -1;
}

void addEmployee(){
    if(empCount >= MAX_EMP){
        printf("Danh sach nhan vien da day!\n");
        return;
    }

    employee e;
    printf("\n===THEM NHAN VIEN MOI===\n");

    while(1){
        printf("Nhap ID: ");
        fgets(e.empId, 20, stdin);
        removeNewline(e.empId);

        if(strlen(e.empId) == 0){
                printf("Khong duoc nhap rong!");
                continue;
        }
        if(findEmployeeIndex(e.empId) != -1){
            printf("ID da ton tai, vui long nhap lai.\n");
        }else{
            break;
        }
    }

    printf("Nhap ten: ");
    fgets(e.name, 50, stdin);
    removeNewline(e.name);

    printf("Nhap chuc vu: ");
    fgets(e.position, 15, stdin);
    removeNewline(e.position);

    printf("Nhap luong co ban: ");
    scanf("%lf", &e.baseSalary);
    getchar();

    e.workDay = 0;

    employees[empCount++] = e;
    printf("Them nhan vien moi thanh cong!\n");
}

void updateEmployee(){
        char id[50];

        printf("\n===CAP NHAT HO SO NHAN VIEN===\n");
        printf("Nhap id nhan vien can cap nhat: ");
        fgets(id,20,stdin);
        removeNewline(id);

        int idx = findEmployeeIndex(id);
    if(idx == -1){
        printf("Khong tim thay nhan vien!\n");
        return;
    }

    printf("Nhap chuc vu moi: ");
    fgets(employees[idx].position, 15, stdin);
    removeNewline(employees[idx].position);

    printf("Nhap luong co ban moi: ");
    scanf("%lf", &employees[idx].baseSalary);
    getchar();

    printf("Cap nhat thanh cong!\n");
}
