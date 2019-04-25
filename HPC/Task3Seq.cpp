/*  								TEAM 4							
PARTICIPANTS
1. NAGA MAMATHA GONUGUNTLA        - 216206223
2. KIRAN VANI HIMAJA SARMA RAVADA - 216206201
3. MOHAN BODDEDA                  - 216206222
4. DURGA PRASAD CHENNAMSHETTY     - 216205830
5. VIKRANTH UTHAYAKUMAR           - 216206183
************************************************************************************************************************/
/*							TASK 3 SEQUENTIAL					       */
/***********************************************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

int main()
{

    int n=5, m=4;								/* Initializing the local variables */
    float A[10][10];

    srand(101);									/* Random matrix with seed 101 */

    cout << "A nxm Matrix with Random Numbers. (Sequential Code)." << endl;
    
/* Initializing the variable start to input the clock time at the beginning of the execution */
    int start=clock();

    for(int i=0;i<n;i++){							/* Generating matrix A with Random Numbers */
        for(int j=0;j<m;j++){
            A[i][j] = float(rand())/float(RAND_MAX);
        }
    }

/* Initializing the variable stop to input the clock time at the end of the execution */
   int stop=clock();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << setprecision(3) << A[i][j] << "\t";
        }
        cout << endl;
    }										/* Printing the Output Matrix A */


   cout << "\nExec time: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;

return 0;
}
