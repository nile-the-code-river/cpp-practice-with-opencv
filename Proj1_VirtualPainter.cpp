#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void get_webcam();
void find_colour(Mat img);

void main() {
	get_webcam();
}

void get_webcam() {
	VideoCapture cap(0);
	Mat img;

	while (true) {
		cap.read(img);
		find_colour(img);
		imshow("Image", img);
		waitKey(1);
	}
}

vector<vector<int>> myColours{	{0,179,210,255,69,255}, // red
								{80,179,31,255,108,182}}; // sky blue

vector<Scalar> myColourValues{ {0,0,255},//red
									{255,0,0} //blue
};

void find_colour(Mat img) {
	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	for (int i = 0; i < myColours.size(); i++) {
		Scalar lower(myColours[i][0], myColours[i][2], myColours[i][4]);
		Scalar upper(myColours[i][1], myColours[i][3], myColours[i][5]);

		Mat mask;
		inRange(imgHSV, lower, upper, mask);
		imshow(to_string(i), mask);
	}
}