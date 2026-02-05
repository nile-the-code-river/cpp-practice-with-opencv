#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void find_colour();

void main_p1_c() {
	find_colour();
}

void find_colour() {
	VideoCapture cap(0);

	Mat img;
	Mat imgHSV;
	Mat mask;

	int hmin = 0;
	int smin = 110;
	int vmin = 153;
	int hmax = 19;
	int smax = 240;
	int vmax = 255;

	namedWindow("Trackbars", WINDOW_AUTOSIZE);
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue max", "Trackbars", &hmax, 179);
	createTrackbar("sat Min", "Trackbars", &smin, 255);
	createTrackbar("sat max", "Trackbars", &smax, 255);
	createTrackbar("val Min", "Trackbars", &vmin, 255);
	createTrackbar("val max", "Trackbars", &vmax, 255);

	while (true)
	{
		cap.read(img);
		cvtColor(img, imgHSV, COLOR_BGR2HSV);

		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);

		imshow("Image", img);
		imshow("imgHSV", imgHSV);
		imshow("mask", mask);

		waitKey(1);
	}
}
