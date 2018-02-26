
//flip image horizontally
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	//Reading an image
	Mat image = imread("C:\\Users\\HP\\Pictures\\Download\\p1.jpg");

	//Displaying an image
	imshow("1", image);

	Mat grey_image(image.rows, image.cols, CV_8UC1);

	Mat horizontal_Flip(image.rows, image.cols, CV_8UC1);

	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			grey_image.at<uchar>(i, j) = (image.at<Vec3b>(i, j)[0] + image.at<Vec3b>(i, j)[1] + image.at<Vec3b>(i, j)[2]) / 3;
		}
	}

	//Displaying grey image
	imshow("2", grey_image);

	for (int i = 0; i < image.rows; i++)
	{
		int m = image.cols;
		m--;

		for (int j = 0; j < image.cols; j++)
		{
			horizontal_Flip.at<uchar>(i, j) = grey_image.at<uchar>(i, m);
			m--;
		}

	}

	imshow("3", horizontal_Flip);

	waitKey(0);

	return 1;
}