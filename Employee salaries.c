#include <stdio.h>
#This code gives employee information
struct persalary {
    int month; /* number 1 corresponds to January, 2 corresponds to February, and so on */
    long salary;
};

struct employee {
    int empnr; /* Employee number */
    char name[12]; /* Employee name */
    struct persalary salaries[3]; /* three months salaries */
    long total; /* Sum of 3 months salaries */
    float average; /* Average of 3 months salaries*/
};

int main() {
    FILE *fp;
    struct employee employees[4];
    int i, j;

    fp = fopen("emp.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    for (i = 0; i < 4; i++) {
        fscanf(fp, "%d %s", &employees[i].empnr, employees[i].name);
        employees[i].total = 0;
        for (j = 0; j < 3; j++) {
            fscanf(fp, "%d %ld", &employees[i].salaries[j].month, &employees[i].salaries[j].salary);
            employees[i].total += employees[i].salaries[j].salary;
        }
        employees[i].average = (float)employees[i].total / 3.0;
    }

    fclose(fp);
    for (i = 0; i < 4; i++) {
        printf("Employee %d: %s\n", employees[i].empnr, employees[i].name);
        for (j = 0; j < 3; j++) {
            printf("  Month %d: %ld\n", employees[i].salaries[j].month, employees[i].salaries[j].salary);
        }
        printf("  Total salary: %ld\n", employees[i].total);
        printf("  Average salary: %.2f\n", employees[i].average);
    }

    return 0;
}


