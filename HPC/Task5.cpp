/*  								TEAM 4							
PARTICIPANTS
1. NAGA MAMATHA GONUGUNTLA        - 216206223
2. KIRAN VANI HIMAJA SARMA RAVADA - 216206201
3. MOHAN BODDEDA                  - 216206222
4. DURGA PRASAD CHENNAMSHETTY     - 216205830
5. VIKRANTH UTHAYAKUMAR           - 216206183
************************************************************************************************************************/
/* 							TASK 5							       */
/***********************************************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <ctime>
using namespace std;

int main()
{
    int i,j,k, sum=0;							/* Initializing the local variables */
    int n=700, m=700, p=700;
    int A[700][700], B[700][700], C[700][700], AB[700][700];

    srand(1234);  							/* Generating Random Matrix with seed 1234 */

    /* SEQUENTIAL PROGRAM */
   
    cout << "This is a Matrix Multiplication of 700 by 700 matrices." << endl;

/* Initializing the variable start to input the clock time at the beginning of the execution */
    double start=clock();
    //cout << "A nxm Matrix with Random Numbers\n";
    for(i=0;i<n;i++){							/* Loading Matrix A with random numbers */
        for(j=0;j<m;j++){
            A[i][j] = rand()%6;
        }
    }

    //cout << "B nxm Matrix with Random Numbers\n";			/* Loading Matrix B with random numbers */
    for(i=0;i<m;i++){
        for(j=0;j<p;j++){
            B[i][j] = rand()%5;
        }
    }

    //cout << "C nxm Matrix with Random Numbers\n";			/* Loading Matrix C with random numbers */
    for(i=0;i<n;i++){
        for(j=0;j<p;j++){
            C[i][j] = rand()%9;
        }
    }

    //cout << "Multiplying A and B\n";					/* Multiplication of Matrices A and B */
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            for(k=0;k<p;k++){
                sum += A[i][k]*B[k][j];
            }

            AB[i][j] = sum;
            sum = 0;
        }
    }

    for(i=0;i<m;i++){							/* Addition of Matrix C with Matrix A */
        for(j=0;j<p;j++){
            AB[i][j] += C[i][j];
        }
    }

/* Initializing the variable stop to input the clock time at the end of the execution */
   double stop=clock();
   double Seq=(stop-start)/double(CLOCKS_PER_SEC);
   cout << "CPU time (Sequential Code): " << Seq << endl;

/*******************************************************************************************************************************/
   
    /* PARALLEL PROGRAM */
       
/* Initializing the variable start to input the clock time at the beginning of the execution */
    double startp=omp_get_wtime();
    

    #pragma omp parallel for private(j) shared(n,m,A) num_threads(5)
    for(i=0;i<n;i++){						/* Loading Matrix A with Random Numbers using parallelized for loop */
        for(j=0;j<m;j++){
            A[i][j] = rand()%6;
        }
    }


    #pragma omp parallel for private(j) shared(n,m,B) num_threads(5)
    for(i=0;i<m;i++){						/* Loading Matrix B with Random Numbers using parallelized for loop */
        for(j=0;j<p;j++){
            B[i][j] = rand()%5;
        }
    }


    #pragma omp parallel for private(j) shared(n,m,C) num_threads(5)
    for(i=0;i<n;i++){						/* Loading Matrix C with Random Numbers using parallelized for loop */
        for(j=0;j<p;j++){
            C[i][j] = rand()%9;
        }
    }

    //cout << "Multiplying A and B\n";
    #pragma omp parallel for private(j,k) num_threads(5)
    for(i=0;i<n;i++){						/* Multiplication of Matrices A and B using parallelized for loop */
        for(j=0;j<m;j++){
            for(k=0;k<p;k++){
                sum += A[i][k]*B[k][j];
            }

            AB[i][j] = sum;
            sum = 0;
        }
    }
    

    #pragma omp parallel for private(j) num_threads(5)
    for(i=0;i<m;i++){					      /* Adding Matrix C to the Output Matrix AB using Parallalized for loop */
        for(j=0;j<p;j++){
            AB[i][j] += C[i][j];
        }
    }					

/* Initializing the variable stop to input the clock time at the end of the execution */
    double stopp=omp_get_wtime();
    double Par=(stopp-startp)/double(CLOCKS_PER_SEC);
   cout << "CPU time (Parallel code with 5 threads: " << Par << endl;

/**********************************************************************************************************************/

/* Computing the Time Difference between the Sequential and Parallel Codes */

   cout << "The Parallel program is " << Seq/Par << "-times faster than Sequential program." << endl;

return 0;
}
