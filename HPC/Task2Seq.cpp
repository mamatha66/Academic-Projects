/*  								TEAM 4							
PARTICIPANTS
1. NAGA MAMATHA GONUGUNTLA        - 216206223
2. KIRAN VANI HIMAJA SARMA RAVADA - 216206201
3. MOHAN BODDEDA                  - 216206222
4. DURGA PRASAD CHENNAMSHETTY     - 216205830
5. VIKRANTH UTHAYAKUMAR           - 216206183
************************************************************************************************************************/
/*							TASK 2 SEQUENTIAL					       */
/***********************************************************************************************************************/

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
        int n=5,m=5,p=5;						/* Initializing the local variables */
    	int A[5][5] = { { 1,1,1,1,1 },{ 1,1,1,1,1 },
		      { 1,1,1,1,1 },{ 1,1,1,1,1 },{ 1,1,1,1,1 } };
	int B[5][5] = { { 1,1,1,1,1 },{ 1,1,1,1,1 },
		      { 1,1,1,1,1 },{ 1,1,1,1,1 },{ 1,1,1,1,1 } };
        int C[5][5] = { { 1,1,1,1,1 },{ 1,1,1,1,1 },
		      { 1,1,1,1,1 },{ 1,1,1,1,1 },{ 1,1,1,1,1 } };
	int AB[5][5];
	int i=0, j=0, k=0, sum = 0;

    cout << "This is Matrix Multiplication - Sequential Code." << endl;

/* Initializing the variable start to input the clock time at the beginning of the execution */
double start=clock();

    for(i=0;i<n;i++){					/* Mutliplication of Matrices A and B using for loop */
        for(j=0;j<m;j++){
	    AB[i][j] = 0;
            for(k=0;k<p;k++){
                AB[i][j] += A[i][k]*B[k][j];
            }
        }
    }


   for(i=0;i<n;i++){					/* Addition of Matrix C to the Output Matrix AB using for loop */
       for(j=0;j<p;j++){
	   AB[i][j] += C[i][j];
       }
    }

/* Initializing the variable stop to input the clock time at the end of the execution */
double stop=clock();

    for(i=0;i<n;i++){					/* Printing the Output Matrix AB*/
        for(j=0;j<p;j++){
            cout << AB[i][j] << "\t";
        }
        cout << endl;
    }


   cout << "Exec time" << (stop-start)/double(CLOCKS_PER_SEC) << endl;
    return 0;
}
