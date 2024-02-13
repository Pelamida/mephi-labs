#include <stdio.h>

typedef struct employee {
    char surname[15];
    char name[15];
    int department;
    int salary;
    int bonus;
    int taxes;
} Employee;

int main() {
    int size; // Количество сотрудников
    scanf("%d", &size);
    Employee employees[size];
    for (int i = 0; i < size; i++) {
        scanf("%s", employees[i].surname);
        scanf("%s", employees[i].name);
        scanf("%d", &employees[i].department);
        scanf("%d", &employees[i].salary);
        scanf("%d", &employees[i].bonus);
        scanf("%d", &employees[i].taxes);
    }
    
    //Вывод матрицы
    for (int i=0; i<size; i++)
        printf("%-15s%-15s%5d%5d%5d%5d\n", employees[i].surname, employees[i].name, employees[i].department, employees[i].salary, employees[i].bonus, employees[i].taxes);
    printf("\n");  
  
    int highestIndex = -1;
    int highestSalary = 0;
    int highestIndexes[size];
    for (int i = 0; i < size; i++) highestIndexes[i] = 0;
    // Находим сотрудников с высшей зарплатой во 2-м отделе
    for (int i = 0; i < size; i++) {
        if (employees[i].department == 2) {
            int salary = employees[i].salary + employees[i].bonus - employees[i].taxes;
            if (salary > highestSalary) {
                highestSalary = salary;
                highestIndex = i;
            }
        }
    }
    // Находим индексы всех сотрудников, получающих такие зарплаты
    for (int i = 0; i < size; i++) {
        if (employees[i].department == 2) {
            int salary = employees[i].salary + employees[i].bonus - employees[i].taxes;
            if (salary == highestSalary) highestIndexes[i] = 1;
        }
    }  
    
    //Выводим имена и фамилии всех сотрудников 2 отдела с максимальной зарплатой
    for (int i = 0; i < size; i++) 
        if (highestIndexes[i]) printf("%s %s\n", employees[i].surname, employees[i].name);
    printf("\n");
  
    //Сотрудники, зарабатывающие не меньше лучших сотрудников 2-го отдела
    for (int i = 0; i < size; i++) {
        int salary = employees[i].salary + employees[i].bonus - employees[i].taxes;
        if (salary >= highestSalary && !highestIndexes[i])
            printf("%s %s\n", employees[i].surname, employees[i].name);
    }
    
    return 0;
}
