#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp"
#include <ctime>


using namespace cv;
using namespace std;

int main() {

	float A[500][500];						/*Initializing Matrix A*/
	int n = 500, m = 500;					/*Initializing local variables*/
	double start = clock();					/*Initializing a variable start to input the clock time at the start of the execution*/

	srand(1234);
											/*Generating a Random Matrix using Rand function and parallelized for loop*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			A[i][j] = rand();
		}
	}

	double stop = clock();					/*Initializing a variable start to input the clock time at the start of the execution*/
	cout << (stop - start) / double(CLOCKS_PER_SEC) << endl;

	Mat image(Size(500, 500), CV_32FC1, A); /*Generating HeatMap corresponding to Matrix A*/

	//cout << image;

	image.convertTo(image, CV_8UC3);
	namedWindow("image1", CV_WINDOW_FREERATIO);
	imshow("image1", image);				/*Displaying HeatMap*/
	waitKey(0);
}
