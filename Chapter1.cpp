#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void show_img();
void show_vid();
void show_webcam();

void main1() {
	show_webcam();
}

void show_img() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	imshow("Image", img);
	waitKey(0);
}

void show_vid() {
	string path = "Resources/test_video.mp4";
	VideoCapture cap(path);
	Mat img;

	while (true) {
		cap.read(img);
		imshow("Image", img);
		waitKey(1);
	}
}

void show_webcam() {
	VideoCapture cap(0);
	Mat img;

	while (true) {
		cap.read(img);
		imshow("Image", img);
		waitKey(1);
	}
}