#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMP 100
#define MAX_TS 1000

// ========== STRUCT ==========
typedef struct {
    char empId[20];
    char name[50];
    char position[15];
    double baseSalary;
    int workDay;
} Employee;

typedef struct {
    char logId[20];
    char empId[20];
    char date[20];
    char status[10];
} TimeSheet;

// ========== GLOBAL ==========
Employee employees[MAX_EMP];
TimeSheet timeSheets[MAX_TS];
int empCount = 0;
int tsCount = 0;

// ========== PROTOTYPE ==========
void removeNewline(char str[]);
int  findEmployeeIndex(char id[]);

void addEmployee();       // 1
void updateEmployee();    // 2
void deleteEmployee();    // 3
void printEmployees();    // 4
void searchEmployee();    // 5
void sortEmployees();     // 6
void clockIn();           // 7
void viewTimeSheet();     // 8

// ========== MAIN ==========
int main() {
    int choice;

    do {
        printf("\n================== MENU ==================\n");
        printf("1. Them nhan vien moi\n");
        printf("2. Cap nhat ho so nhan vien\n");
        printf("3. Xoa nhan vien\n");
        printf("4. Hien thi danh sach nhan vien\n");
        printf("5. Tra cuu nhan vien (theo ten)\n");
        printf("6. Sap xep danh sach nhan vien theo luong co ban\n");
        printf("7. Cham cong ngay\n");
        printf("8. Xem bang cong\n");
        printf("9. Thoat\n");
        printf("=========================================\n");

        printf("\nMoi nhap: ");
        scanf("%d", &choice);
        getchar();   // xoa \n trong buffer

        switch (choice) {
        case 1: addEmployee();    break;
        case 2: updateEmployee(); break;
        case 3: deleteEmployee(); break;
        case 4: printEmployees(); break;
        case 5: searchEmployee(); break;
        case 6: sortEmployees();  break;
        case 7: clockIn();        break;
        case 8: viewTimeSheet();  break;
        case 9: exit(0);
        default:
            printf("\nLoi - Khong nhap tu 1 den 9\n");
        }
    } while (1);

    return 0;
}

// ========== IMPLEMENTATION ==========

void removeNewline(char str[]) {
    str[strcspn(str, "\n")] = '\0';
}

int findEmployeeIndex(char id[]) {
    int i;
    for (i = 0; i < empCount; i++) {
        if (strcmp(employees[i].empId, id) == 0) {
            return i;
        }
    }
    return -1;
}

// 1. Them nhan vien
void addEmployee() {
    if (empCount >= MAX_EMP) {
        printf("Danh sach nhan vien da day!\n");
        return;
    }

    Employee e;
    printf("\n--- THEM NHAN VIEN MOI ---\n");

    // ID khong trung va khong rong
    while (1) {
        printf("Nhap ID: ");
        fgets(e.empId, 20, stdin);
        removeNewline(e.empId);

        if (strlen(e.empId) == 0) {
            continue;
        }
        if (findEmployeeIndex(e.empId) != -1) {
            printf("ID da ton tai, vui long nhap lai.\n");
        } else {
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
    printf("Them thanh cong!\n");
}

// 2. Cap nhat ho so
void updateEmployee() {
    char id[20];
    int idx;

    printf("\n--- CAP NHAT HO SO ---\n");
    printf("Nhap ID nhan vien can sua: ");
    fgets(id, 20, stdin);
    removeNewline(id);

    idx = findEmployeeIndex(id);
    if (idx == -1) {
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

// 3. Xoa nhan vien
void deleteEmployee() {
    char id[20];
    int idx, i;
    char c;

    printf("\n--- XOA NHAN VIEN ---\n");
    printf("Nhap ID nhan vien can xoa: ");
    fgets(id, 20, stdin);
    removeNewline(id);

    idx = findEmployeeIndex(id);
    if (idx == -1) {
        printf("Khong tim thay nhan vien!\n");
        return;
    }

    printf("Ban co chac muon xoa %s (y/n)? ", employees[idx].name);
    scanf("%c", &c);
    getchar();

    if (c == 'y' || c == 'Y') {
        for (i = idx; i < empCount - 1; i++) {
            employees[i] = employees[i + 1];
        }
        empCount--;
        printf("Da xoa thanh cong!\n");
    } else {
        printf("Da huy xoa.\n");
    }
}

// 4. Hien thi danh sach
void printEmployees() {
    int i;

    if (empCount == 0) {
        printf("\nDanh sach rong!\n");
        return;
    }

    printf("\n%-10s %-25s %-15s %-15s %-10s\n",
           "ID", "Ten", "Chuc vu", "Luong CB", "Ngay cong");
    printf("-------------------------------------------------------------------------------\n");

    for (i = 0; i < empCount; i++) {
        printf("%-10s %-25s %-15s %-15.0f %-10d\n",
               employees[i].empId,
               employees[i].name,
               employees[i].position,
               employees[i].baseSalary,
               employees[i].workDay);
    }
}

// 5. Tim kiem theo ten
void searchEmployee() {
    char keyword[50];
    int i, found = 0;

    printf("\n--- TIM KIEM NHAN VIEN ---\n");
    printf("Nhap ten can tim: ");
    fgets(keyword, 50, stdin);
    removeNewline(keyword);

    for (i = 0; i < empCount; i++) {
        if (strstr(employees[i].name, keyword) != NULL) {
            printf("%-10s %-25s %-15s %-15.0f %-10d\n",
                   employees[i].empId,
                   employees[i].name,
                   employees[i].position,
                   employees[i].baseSalary,
                   employees[i].workDay);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay nhan vien phu hop.\n");
    }
}

// 6. Sap xep theo luong giam dan
void sortEmployees() {
    int i, j;
    Employee tmp;

    for (i = 0; i < empCount - 1; i++) {
        for (j = 0; j < empCount - i - 1; j++) {
            if (employees[j].baseSalary < employees[j + 1].baseSalary) {
                tmp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = tmp;
            }
        }
    }

    printf("Da sap xep danh sach theo luong giam dan.\n");
    printEmployees();
}

// 7. Cham cong
void clockIn() {
    char id[20], date[20];
    int idx, i;
    TimeSheet ts;

    if (tsCount >= MAX_TS) {
        printf("Bang cong da day!\n");
        return;
    }

    printf("\n--- CHAM CONG ---\n");
    printf("Nhap ID nhan vien: ");
    fgets(id, 20, stdin);
    removeNewline(id);

    idx = findEmployeeIndex(id);
    if (idx == -1) {
        printf("ID khong ton tai!\n");
        return;
    }

    printf("Nhap ngay (DD/MM/YYYY): ");
    fgets(date, 20, stdin);
    removeNewline(date);

    // kiem tra da cham cong ngay nay chua
    for (i = 0; i < tsCount; i++) {
        if (strcmp(timeSheets[i].empId, id) == 0 &&
            strcmp(timeSheets[i].date, date) == 0) {
            printf("Nhan vien nay da duoc cham cong ngay %s roi!\n", date);
            return;
        }
    }

    employees[idx].workDay++;

    sprintf(ts.logId, "LOG%03d", tsCount + 1);
    strcpy(ts.empId, id);
    strcpy(ts.date, date);
    strcpy(ts.status, "Di lam");

    timeSheets[tsCount++] = ts;

    printf("Cham cong thanh cong! So ngay cong hien tai: %d\n",
           employees[idx].workDay);
}

// 8. Xem bang cong
void viewTimeSheet() {
    char id[20];
    int i;

    printf("\n--- XEM BANG CONG ---\n");
    printf("Nhap ID nhan vien: ");
    fgets(id, 20, stdin);
    removeNewline(id);

    if (findEmployeeIndex(id) == -1) {
        printf("ID khong ton tai!\n");
        return;
    }

    printf("\nLich su cham cong cua %s:\n", id);
    printf("%-10s %-15s %-10s\n", "LogID", "Ngay", "Trang thai");

    for (i = 0; i < tsCount; i++) {
        if (strcmp(timeSheets[i].empId, id) == 0) {
            printf("%-10s %-15s %-10s\n",
                   timeSheets[i].logId,
                   timeSheets[i].date,
                   timeSheets[i].status);
        }
    }
}

