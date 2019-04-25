/*  								TEAM 4							
PARTICIPANTS
1. NAGA MAMATHA GONUGUNTLA        - 216206223
2. KIRAN VANI HIMAJA SARMA RAVADA - 216206201
3. MOHAN BODDEDA                  - 216206222
4. DURGA PRASAD CHENNAMSHETTY     - 216205830
5. VIKRANTH UTHAYAKUMAR           - 216206183
************************************************************************************************************************/
/*							TASK 3 PARALLEL						       */
/***********************************************************************************************************************/

#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

int main()
{

    int n=5, m=4;							/* Initializing the local variables */
    float A[10][10];
    int i=0, j=0,t;

    srand(101);

/* Initializing the variable start to input the clock time at the beginning of the execution */
    double start=omp_get_wtime();

#pragma omp parallel for private(j) shared(n,m,A) num_threads(8)	/* Generating Matrix A with required number of threads */
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            A[i][j] = float(rand())/float(RAND_MAX);
  	    t=omp_get_num_threads();
        }
    }

/* Initializing the variable stop to input the clock time at the end of the execution */
    double stop=omp_get_wtime();

    cout << "A nxm Matrix with Random Numbers. (Parallel Code). " << "Number of Threads: " << t << endl;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout << setprecision(3) << A[i][j] << "\t";
        }
        cout << endl;
    }									/* Priniting the Output Matrix A */ 


    cout << "\nExec time" << (stop-start)/double(CLOCKS_PER_SEC) << endl;

return 0;
}
