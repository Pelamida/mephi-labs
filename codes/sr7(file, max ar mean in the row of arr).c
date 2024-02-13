#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINES 30
#define MAX_NUMBERS 20
#define MAX_VALUE 100

int RandInRange(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    //srand(time(NULL));

    //FILE* file = fopen("file.txt", "w");
    //if (file == NULL) {
    //    printf("error\n");
    //    return 1;
    //}

    //int lineCount = RandInRange(1, MAX_LINES);
    //int maxAverage = 0;
    //int maxLineNums[MAX_LINES];
    //int maxLineCount = 0;

    //for (int i = 1; i <= lineCount; i++) {
    //    int numberCount = RandInRange(1, MAX_NUMBERS);
    //    int lineSum = 0;

    //    for (int j = 1; j <= numberCount; j++) {
    //        int number = RandInRange(1, MAX_VALUE);
    //        fprintf(file, "%d ", number);
    //        lineSum += number;
    //    }
    //    fprintf(file, "\n");

    //    int average = lineSum / numberCount;
    //    if (average > maxAverage) {
    //        maxAverage = average;
    //        maxLineCount = 0;
    //        maxLineNums[maxLineCount++] = i;
    //    } else if (average == maxAverage) {
    //        maxLineNums[maxLineCount++] = i;
    //    }
    //}

    //fclose(file);
	
	//printf("%d", maxLineNums[0]);
    //for (int i = 1; i < maxLineCount; i++) {
    //    printf(" %d", maxLineNums[i]);
    //}
    //printf("\n");
    
    int inputArray[MAX_LINES][MAX_NUMBERS];
    int countArray[MAX_LINES] = {0};  // массив для хранения количества элементов в каждой строке
    int row = 0; //индекс строки
    int col = 0; //индекс столбца
    int value = 0; //число
    char ch;

    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            if (col > 0 || col==0 && value) {
                // добавляем количество элементов в текущей строке в массив с количеством
                inputArray[row][col] = value;
                countArray[row] = col+1;
                row++;  // переходим к следующей строке
                col = 0;  // сбрасываем число элементов в текущей строке
                value = 0;
            }
        } else if (ch != ' ') {
            value = value * 10 + (ch - '0');
        } else {
            // если считываем пробел, значит число закончилось, добавляем его в массив
            inputArray[row][col] = value;
            col++;  // переходим к следующему элементу в текущей строке
            value = 0;  // сбрасываем значение
        }
    }

    // добавляем последнее значение и количество элементов в последней строке (если есть)
    if (col > 0) {
        inputArray[row][col] = value;
        countArray[row] = col + 1;
        row++;  // увеличиваем количество строк в массиве
    }

    int arithmMean[row];
    int max_arithmMean = 0;
    int sumInRow = 0;
    int max_row[row];
    
    for (int i = 0; i < row; i++) {
        arithmMean[i] = 0;
        max_row[i] = 0;
    }
    
    
    for (int i = 0; i < row; i++) {
    	sumInRow = 0;
        for (int j = 0; j < countArray[i]; j++) {
            sumInRow += inputArray[i][j];
        }
        arithmMean[i] = (double) sumInRow/countArray[i];
    }
	
	for (int i=0; i<row; i++) {
		if (max_arithmMean <= arithmMean[i]) max_arithmMean = arithmMean[i];
	}
	
	int k = 0;
	for (int i=0; i<row; i++) {
	   if (max_arithmMean == arithmMean[i]) {
	        printf("%d", i+1);
	        k = i;
	        break;
	   }
	}
	for (int i=k+1; i<row; i++) 
	    if (max_arithmMean == arithmMean[i]) printf(" %d", i+1);
	printf("\n");
    return 0;
}
