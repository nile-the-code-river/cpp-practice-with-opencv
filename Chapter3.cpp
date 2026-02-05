#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void resize_and_crop_img();

void main3() {
	resize_and_crop_img();
}

void resize_and_crop_img() {
	string path = "Resources/test.png";
	
	Mat img = imread(path);
	Mat imgResized;
	Mat imgResizedByScale;
	Mat imgCropped;
	
	// resize
	Size sz(680,480);
	resize(img, imgResized, sz);
	resize(img, imgResizedByScale, Size(), 0.5, 0.5);

	cout << "before: " << img.size() << endl;
	cout << "after:" << sz << endl;

	// crop
	Rect roi(100, 100, 300, 250);
	imgCropped = img(roi);


	imshow("Image", img);
	imshow("imgResized", imgResized);
	imshow("imgResizedByScale", imgResizedByScale);
	imshow("imgCropped", imgCropped);

	waitKey(0);
}
