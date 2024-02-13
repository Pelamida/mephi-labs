#include <stdio.h>
#include <limits.h>

void printer(int m, int n, int arr[][n]) {
	for (int i = 0; i < m; i++) {
	    for (int j = 0; j < n; j++) printf("%3d", arr[i][j]);
	    printf("\n");
	}
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    int mat[m][n];
    int values[m*n];
    for (int i=0; i<m*n; i++) scanf("%d", &values[i]);    
    
    //1.1 заполнение матрицы с помощью индексов
    int k = 0;
    for (int j=0; j<n; j+=2) {
        for (int i=m-1; i>=0; i--) {
            mat[i][j] = values[k];
            k++;
        }
        k += m;
    }
    k = m;
    for (int j=1; j<n; j+=2){
        for (int i=0; i<m; i++) {
            mat[i][j] = values[k];
            k++;
        }
        k += m;
    }
    printer(m, n, mat);
    printf("\n");
    
//     //1.2 заполнение матрицы с помощью адресов
//     int k = 0;
//     for (int j=0; j<n; j+=2) {
//         for (int i=m-1; i>=0; i--) {
//             *(*(mat+i)+j) = *(values+k);
//             k++;
//         }
//         k += m;
//     }
//     k = m;
//     for (int j=1; j<n; j+=2){
//         for (int i=0; i<m; i++) {
//             *(*(mat+i)+j) = *(values+k);
//             k++;
//         }
//         k += m;
//     }
//     printer(m, n, mat);
//     printf("\n");
    
    //2.1 нахождение столбцов с максимальным элементом матрицы, индексы
	int elmax = -INT_MAX;
	for (int i=0; i<m*n; i++) if (values[i] > elmax) elmax = values[i];
    
    int columns_with_max[n];
    for (int i=0; i<n; i++) columns_with_max[i] = 0;
    
    for (int i = 0; i < m; i++)
	    for (int j = 0; j < n; j++)
	        if (mat[i][j] == elmax) columns_with_max[j] = 1;
    
    int z = 0;
    for (int i=0; i<n; i++)
        if (columns_with_max[i]) { printf("%d", i+1); z = i; break; }
    for (int i=z+1; i<n; i++)
        if (columns_with_max[i]) printf(" %d", i+1);
    printf("\n");
    
//     //2.2 нахождение столбцов с максимальным элементом матрицы, адреса 
//     int elmax = -INT_MAX;
// 	for (int i=0; i<m*n; i++) if (*(values+i) > elmax) elmax = *(values+i);
    
//     int columns_with_max[n];
//     for (int i=0; i<n; i++) *(columns_with_max + i) = 0;
    
//     for (int i = 0; i < m; i++)
// 	    for (int j = 0; j < n; j++)
// 	        if (*(*(mat+i)+j) == elmax) *(columns_with_max + j) = 1;
    
//     int z = 0;
//     for (int i=0; i<n; i++)
//         if (*(columns_with_max + i)) { printf("%d", i+1); z = i; break; }
//     for (int i=z+1; i<n; i++)
//         if (*(columns_with_max + i)) printf(" %d", i+1);
//     printf("\n");
    
    //3.1 нахождение седлового элемента, индексы
    int mins[m][n], maxs[m][n];
    for (int i=0; i<m; i++) 
        for (int j=0; j<n; j++) { mins[i][j] = 0; maxs[i][j] = 0;}
    
    for (int i=0; i<m; i++) {
        int elmin = INT_MAX;
        for (int j=0; j<n; j++) if (mat[i][j] < elmin) elmin = mat[i][j];
        for (int j=0; j<n; j++) if (mat[i][j] == elmin) mins[i][j] = 1;
    }
    
    for (int j=0; j<n; j++) {
        int elmax = -INT_MAX;
        for (int i=0; i<m; i++) if (mat[i][j] > elmax) elmax = mat[i][j];
        for (int i=0; i<m; i++) if (mat[i][j] == elmax) maxs[i][j] = 1;
    }
    
    int saddle_element, count = 0;
    for (int i = 0; i < m; i++) 
	    for (int j = 0; j < n; j++)
	        if (mins[i][j] == 1 && maxs[i][j] == 1) {
	            count++;
	            saddle_element = mat[i][j];
	        }
	if (!count) printf("-\n");
	else if (count == 1) printf("%d\n", saddle_element);
	else printf("%d %d\n", saddle_element, count);
	
//     //3.2 нахождение седлового элемента, адреса 
//     int mins[m][n], maxs[m][n];
//     for (int i=0; i<m; i++) 
//         for (int j=0; j<n; j++) { *(*(mins+i)+j) = 0; *(*(maxs+i)+j) = 0;}
    
//     for (int i=0; i<m; i++) {
//         int elmin = INT_MAX;
//         for (int j=0; j<n; j++) if (*(*(mat+i)+j) < elmin) elmin = *(*(mat+i)+j);
//         for (int j=0; j<n; j++) if (*(*(mat+i)+j) == elmin) *(*(mins+i)+j) = 1;
//     }
    
//     for (int j=0; j<n; j++) {
//         int elmax = -INT_MAX;
//         for (int i=0; i<m; i++) if (*(*(mat+i)+j) > elmax) elmax = *(*(mat+i)+j);
//         for (int i=0; i<m; i++) if (*(*(mat+i)+j) == elmax) *(*(maxs+i)+j) = 1;
//     }
    
//     int saddle_element, count = 0;
//     for (int i = 0; i < m; i++) 
// 	    for (int j = 0; j < n; j++)
// 	        if (*(*(mins+i)+j) == 1 && *(*(maxs+i)+j) == 1) {
// 	            count++;
// 	            saddle_element = *(*(mat+i)+j);
// 	        }
// 	if (!count) printf("-\n");
// 	else if (count == 1) printf("%d\n", saddle_element);
// 	else printf("%d %d\n", saddle_element, count);
    
    return 0;
}
