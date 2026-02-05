#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void draw_in_img();

void main4() {
	draw_in_img();
}

void draw_in_img() {
	Mat img(512, 512, CV_8UC3, Scalar(255,255,255));

	circle(img, Point(256, 256), 155, Scalar(255,0,0),FILLED);
	rectangle(img, Point(10, 20), Point(100, 120), Scalar(0,0,255), 2);
	line(img, Point(130, 200), Point(382, 300), Scalar(0,255,0), 2);

	putText(img, "This is a text", Point(137,262), FONT_HERSHEY_TRIPLEX, 0.8, Scalar(255,0,255), 2);

	imshow("img",img);

	waitKey(0);
}
