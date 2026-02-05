#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void warp_img();

void main5() {
	warp_img();
}

void warp_img() {
	string path = "Resources/cards.jpg";
	Mat img = imread(path);

	float width = 250;
	float height = 350;
	Mat matrix, imgWarp;

	Point2f src[4] = { {529,142}, {771,190}, {405,395}, {674,457} };
	Point2f dest[4] = { {0,0}, {width,0}, {0,height}, {width,height} };

	matrix = getPerspectiveTransform(src, dest);
	warpPerspective(img, imgWarp, matrix, Point(width, height));

	for (int i = 0; i < 4; i++) {
		circle(img, src[i], 10, Scalar(255, 0, 0), FILLED);
	}

	imshow("Image", img);
	imshow("ImageWarp", imgWarp);
	waitKey(0);
}
