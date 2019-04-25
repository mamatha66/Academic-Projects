#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <ctime>

using namespace cv;
using namespace std;

int main() {

	Mat image;

	image = imread("G:/ScalableComputing/image.png", CV_LOAD_IMAGE_UNCHANGED);

	if (! image.data) {
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	int r = image.rows;
	int c = image.cols;

	Mat image1;
	image.convertTo(image1, CV_32FC1, 1.0/255.0);
	
	int C[3][3] = { {-1,-1,-1}, {-1,8,-1}, {-1,-1,-1} };
	float P[3][3];
	int a = r - 1, b = c - 1;
	Mat imageO(a, b, CV_32FC1, Scalar(0));
	
	double start = clock();

	for (int i = 1; i < r-1; i++) {
		for (int j = 1; j < c-1; j++) {

			P[0][0] = image1.at<float>(i-1, j-1);
			P[0][1] = image1.at<float>(i, j-1);
			P[0][2] = image1.at<float>(i+1, j-1);
			P[1][0] = image1.at<float>(i-1, j);
			P[1][1] = image1.at<float>(i, j);
			P[1][2] = image1.at<float>(i+1, j);
			P[2][0] = image1.at<float>(i-1, j+1);
			P[2][1] = image1.at<float>(i, j+1);
			P[2][2] = image1.at<float>(i+1, j+1);

			// Convolution
			float sum = 0;
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					sum += C[x][y] * P[x][y];
				}
			}
			imageO.at<float>(i - 1, j - 1) = sum;
			
		}
	}
	
	double stop = clock();
	cout << "Execution time - Sequential: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;

	Mat imageO1;
	//cout << "Printing Output Image" << endl;
	imageO.convertTo(imageO1, CV_8UC1, 255.0);

	namedWindow("OutputImage", CV_WINDOW_NORMAL);
	imshow("OutputImage", imageO1);
	imwrite("G:/ScalableComputing/result.png", imageO1);

	waitKey(0);
	return 0;
}