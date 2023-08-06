#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    long int id_no;
    char name[20];
    int birth_year;
};

int main() {
    struct student ali;

    ali.id_no = 14254;
    printf("Enter name: ");
    fgets(ali.name, sizeof(ali.name), stdin);
    ali.name[strcspn(ali.name, "\n")] = '\0';  // New line character removal

    printf("Enter birth year: ");
    scanf("%d", &ali.birth_year);

    printf("Student Information:\n");
    printf("ID: %ld\n", ali.id_no);
    printf("Name: %s\n", ali.name);
    printf("Birth Year: %d\n", ali.birth_year);

    return 0;
}
