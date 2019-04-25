/*  								TEAM 4							
PARTICIPANTS
1. NAGA MAMATHA GONUGUNTLA        - 216206223
2. KIRAN VANI HIMAJA SARMA RAVADA - 216206201
3. MOHAN BODDEDA                  - 216206222
4. DURGA PRASAD CHENNAMSHETTY     - 216205830
5. VIKRANTH UTHAYAKUMAR           - 216206183
************************************************************************************************************************/
/*							TASK 1 SEQUENTIAL					       */
/***********************************************************************************************************************/

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
/* Initializing the variable start to input the clock time at the beginning of the execution */
    double start=clock();

        int n=5,m=5,p=5;						/* Initializing the local variables*/		
    	int A[5][5] = { { 1,1,1,1,1 },{ 1,1,1,1,1 },
		      { 1,1,1,1,1 },{ 1,1,1,1,1 },{ 1,1,1,1,1 } };
	int B[5][5] = { { 1,1,1,1,1 },{ 1,1,1,1,1 },
		      { 1,1,1,1,1 },{ 1,1,1,1,1 },{ 1,1,1,1,1 } };
	int AB[5][5];
	int i, j, k, sum = 0;

    cout << "This is Matrix Multiplication - Sequential Code.\n";
    for(i=0;i<n;i++){				/* Mutliplication of Matrices A and B using for loop and parallelizing the for loop*/
        for(j=0;j<m;j++){
            for(k=0;k<p;k++){
                sum += A[i][k]*B[k][j];
            }

            AB[i][j] = sum;
            sum = 0;
        }
    }
    
    cout << "A=" << endl;			/* Printing Matrix A using for loop */
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "B=" << endl;			/* Printing Matrix B using for loop */
    for(i=0;i<m;i++){
        for(j=0;j<p;j++){
            cout << B[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "AB=" << endl;			/* Printing Matrix AB using for loop */
    for(i=0;i<m;i++){
        for(j=0;j<p;j++){
            cout << AB[i][j] << "\t";
        }
        cout << endl;
    }

/* Initializing the variable stop to input the clock time at the end of the execution */
   int stop=clock();
   cout << "Exec time " << (stop-start)/double(CLOCKS_PER_SEC) << endl;
    return 0;
}
