#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp"
#include <ctime>
#include <omp.h>

using namespace cv;
using namespace std;

int main() {

	float A[500][500];						/*Initialing Matrix A*/
	int n = 500, m = 500;					/*Initializing the local variables*/
	double start = omp_get_wtime();			/*Initialing Variable start to input the clock time at the beginning of the execution*/

	srand(1234);							/*Generating Random Matrix using Rand function and parallelized for loop*/
#pragma omp parallel for private(j) shared(n,m,A)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			A[i][j] = rand();
		}
	}

	double stop = omp_get_wtime();			/*Initialing Variable stop to input the clock time at the end of the execution*/
	cout << (stop - start) / double(CLOCKS_PER_SEC) << endl;

	Mat image(Size(500, 500), CV_32FC1, A); /*generating HeatMap corresponding to Matrix A*/

	//cout << image;

	image.convertTo(image, CV_8UC3);
	namedWindow("image1", CV_WINDOW_FREERATIO);
	imshow("image1", image);				/*Displaying HeatMap*/
	waitKey(0);
}
