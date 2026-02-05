#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void detect_shapes_and_contour_in_img();
void preprocess(Mat& img, Mat& imgGray, Mat& imgBlur, Mat& imgCanny, Mat& imgDil);
void get_contours(Mat imgDil, Mat img);


void main7() {
	detect_shapes_and_contour_in_img();
}

void detect_shapes_and_contour_in_img() {
	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgGray;
	Mat imgBlur;
	Mat imgCanny;
	Mat imgDil;

	preprocess(img, imgGray, imgBlur, imgCanny, imgDil);
	get_contours(imgDil, img);

	imshow("Image", img);
	imshow("imgGray", imgGray);
	imshow("imgBlur", imgBlur);
	imshow("imgCanny", imgCanny);
	imshow("imgDil", imgDil);

	waitKey(0);
}

void preprocess(Mat& img, Mat& imgGray, Mat& imgBlur, Mat& imgCanny, Mat& imgDil) {
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur, Size(9, 9), 10, 0);
	Canny(img, imgCanny, 25, 75);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);
}

void get_contours(Mat imgDil, Mat img) {
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	drawContours(img,contours, -1,Scalar(255,0,255), 2);

	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]);
		cout << area << endl;

		vector<vector<Point>> conPoly(contours.size());
		vector<Rect> boundRect(contours.size());

		if (area > 1000) {
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			cout << conPoly[i].size() << endl;

			boundRect[i] = boundingRect(conPoly[i]);

			int objCor = (int)conPoly[i].size();
			string objType;

			switch (objCor)
			{
			case 1:
			case 2:
				objType = "Wtf";
				break;
			case 3:
				objType = "Tri";
				break;
			case 4:
				objType = "Rect";
				break;
			default:
				objType = "Circle";
				break;
			}

			drawContours(img, conPoly, -1, Scalar(255, 0, 0), 1);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 0, 0), 2);
			putText(img, objType, { boundRect[i].x, boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 1, Scalar(255,0,0));
		}
	}
}