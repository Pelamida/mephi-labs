#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char last_name[50];
    char first_name[50];
    char city[50];
    char street[50];
    int house;
    int flat;
    char faculty[50];
    int score;
} Applicant;

//чтение из файла
void readDataFromFile(Applicant applicants[], int *num_applicants) {
    FILE *file = fopen("applicants.txt", "r");
    if (file == NULL) return;
    
    *num_applicants = 0;
    while (!feof(file) && *num_applicants < MAX_SIZE) {
        fscanf(file, "%s %s %s %s %d %d %s %d", applicants[*num_applicants].last_name, applicants[*num_applicants].first_name,
               applicants[*num_applicants].city, applicants[*num_applicants].street, &applicants[*num_applicants].house,
               &applicants[*num_applicants].flat, applicants[*num_applicants].faculty, &applicants[*num_applicants].score);
        (*num_applicants)++;
    }
    fclose(file);
}

//находит проходные баллы
void PassingScores(Applicant applicants[], int num_applicants, char faculties[][50], int num_faculties, int seats) {
    for (int i = 0; i < num_faculties; i++) { //пробег по всем факультетам
        int max_score = 0, last_max_score = 310;
        int count = 1;
        
        for (int j = 0; j < num_applicants; j++) {  //найдем первый макс балл
            if (strcmp(applicants[j].faculty, faculties[i]) == 0 && applicants[j].score > max_score) {                    
                max_score = applicants[j].score;
            }
        }
        last_max_score = max_score;
        
        while (count<seats) { //найдем остальные баллы в порядке убывания
            max_score = 0;
            for (int j = 0; j < num_applicants; j++) {  //находит макс балл, меньший предыдущего
                if (strcmp(applicants[j].faculty, faculties[i]) == 0 && applicants[j].score > max_score
                    && applicants[j].score < last_max_score) {
                    max_score = applicants[j].score;
                }
            }
            if (max_score == 0) {            // если балла не нашлось, значит, 
                max_score = last_max_score; // абитуриентов меньше, чем мест
                break;                     // оставим предыдущий балл в качестве проходного
            }
            last_max_score = max_score;
            count++;
        }
        printf("%s %d\n", faculties[i], max_score); //
    }
}

//составление списков поступивших на факультеты
void CreateFacultyLists(Applicant applicants[], int num_applicants, char faculties[][50], int num_faculties) {
    
    for (int i = 0; i < num_faculties; i++) {
        printf("%s\n", faculties[i]);
        for (int j = 0; j < num_applicants; j++)
            if (strcmp(applicants[j].faculty, faculties[i]) == 0) 
                printf(" %s\n", applicants[j].first_name);
        printf("\n");
    }
}

//количество мест в общежитии
int DormitorySeats(Applicant applicants[], int num_applicants) {
    int count = 0;
    for (int i = 0; i < num_applicants; i++)
        if (strcmp(applicants[i].city, "Moscow") != 0) count++;
    return count;
}

//наиболее частые города
void CommonCities(Applicant applicants[], int num_applicants) {
    //составим список всех городов
    char cities[num_applicants][50]; 
    int counts[num_applicants], num_cities = 0;
    for (int i = 0; i < num_applicants; i++) counts[i] = 0;
    
    for (int i = 0; i < num_applicants; i++) {
    	int city_exists = 0;
        for (int j = 0; j < num_cities; j++) 
            if (strcmp(applicants[i].city, cities[j]) == 0) {
                counts[j]++;
                city_exists = 1;
                break;
            }
		if (!city_exists) {
        	strcpy(cities[num_cities], applicants[i].city);
        	counts[num_cities]++;
        	num_cities++;
        }
    }

    //посчитаем, сколько раз встречается каждый город
    int max_index = 0, max_count = 0;
    for (int i = 1; i < num_cities; i++)
        if (counts[i] > max_count) {
            max_index = i;
            max_count = counts[i];
        }
    printf("%s", cities[max_index]);
    counts[max_index] = counts[num_cities-1];
    strcpy(cities[max_index], cities[num_cities-1]);
    
    //выберем и напечатаем города по убыванию поступающих
    while (num_cities > 1) {
        max_index = 0;
        max_count = counts[0];
        for (int i = 1; i < num_cities; i++)
            if (counts[i] > max_count) {
                max_index = i;
                max_count = counts[i];
            }
        printf(" %s", cities[max_index]);
        
        counts[max_index] = counts[num_cities-1];
        strcpy(cities[max_index], cities[num_cities-1]);
        
        num_cities--;
    }
}

int main() {
    //считывание данных
    int num_applicants, seats;
    scanf("%d", &num_applicants);
    Applicant applicants[num_applicants];
    for (int i=0; i<num_applicants; i++)
        scanf("%s %s %s %s %d %d %s %d", applicants[i].first_name, applicants[i].last_name, 
        applicants[i].city, applicants[i].street, &applicants[i].house, &applicants[i].flat, 
        applicants[i].faculty, &applicants[i].score);
    scanf("%d", &seats);
    
    //составление списка факультетов
    char faculties[num_applicants][50]; 
    int num_faculties = 0;
    for (int i = 0; i < num_applicants; i++) {
    	int faculty_exists = 0;
        for (int j = 0; j < num_faculties; j++) 
            if (strcmp(applicants[i].faculty, faculties[j]) == 0) {
                faculty_exists = 1;
                break;
            }
		if (!faculty_exists) {
        	strcpy(faculties[num_faculties], applicants[i].faculty);
        	num_faculties++;
        }
    }
    
    PassingScores(applicants, num_applicants, faculties, num_faculties, seats);
    printf("\n");
    
    CreateFacultyLists(applicants, num_applicants, faculties, num_faculties);
    
    printf("%d\n\n", DormitorySeats(applicants,  num_applicants));
    
    CommonCities(applicants, num_applicants);
    printf("\n");
    
    return 0;    
}
