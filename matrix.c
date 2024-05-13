#include <stdio.h>
#include <stdlib.h>

int print_matrix(int n, int m, int matrix[n][m]) {

    char *s = "%i ";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf(s, matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}


int define_matrix(int n, int m, int matrix[][m]) {
    char s[100];
    char a[100];

    for (int r = 0; r < n; r++) {
        fgets(s, 100, stdin);
	    for (int i = 0, j = 0, k = 0; j < m; i++) {
		    if (s[i] != ' ' && s[i] != '\0') {
		    	a[k] = s[i];
		    	k++;
		    } else if (s[i] != '\0') {
		    	a[k] = '\0';
		    	*(matrix[r] + j) = atoi(a);
//		    	printf("(%i, %i)-th number is %i\n", r, j, matrix[r][j]);
		    	j++;
		    	k = 0;
		    } else {
		    	a[k] = '\0';
		    	*(matrix[r] + j) = atoi(a);
//		    	printf("(%i, %i)-th number is %i\n", r, j, matrix[r][j]);
		    	j++;
		    	k = 0;
		    	break;
		    }
        }
    }

    return 0;
}

int multiplicate_matrices(int n1, int m1, int m2, int a[][m1], int b[m1][m2], int c[n1][m2]) {
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m2; j++) {
			int sum = 0;
			
			for (int k = 0; k < m1; k++) {
				sum += a[i][k] * b[k][j];
			}

			c[i][j] = sum;
		}
	}
}

int main(void) {
    int n_a, m_a, n_b, m_b;
    printf("Print a shape of A matrix: ");
    fscanf(stdin, "%ix%i", &n_a, &m_a);
	getchar();
    printf("The shape of your matrix: (%i, %i)\n", n_a, m_a);
    int A[n_a][m_a];
    printf("Print elements of your matrix row by row:\n");
    define_matrix(n_a, m_a, A);
    
    printf("\n");
	printf("here is your matrix:\n");
    print_matrix(n_a, m_a, A);

	printf("\n");

	printf("Print a shape of B matrix: ");
    fscanf(stdin, "%ix%i", &n_b, &m_b);
	getchar();
    printf("The shape of your matrix: (%i, %i)\n", n_b, m_b);
    int B[n_b][m_b];
    printf("Print elements of your matrix row by row:\n");
    define_matrix(n_b, m_b, B);
    
    printf("\n");
	printf("here is your matrix:\n");
    print_matrix(n_b, m_b, B);

    printf("\n");

	int C[n_a][m_b];
	printf("Here is dot product of your matrices:\n");
	multiplicate_matrices(n_a, m_a, m_b, A, B, C);
	print_matrix(n_a, m_b, C);
}
    