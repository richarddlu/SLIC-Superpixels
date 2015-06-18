#include "slic_opencv2.h"

#include <iostream>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace std;

void drawBorder(const Mat& src, const Mat& clusters, Mat& imgWithBorder) {
	const int dx8[8] = {-1, -1,  0,  1, 1, 1, 0, -1};
	const int dy8[8] = { 0, -1, -1, -1, 0, 1, 1,  1};

	Mat isTaken = Mat::zeros(src.size(), CV_8U);
	imgWithBorder = src.clone();
	for(int h = 0; h < src.rows; h++) {
		for(int w = 0; w < src.cols; w++) {
			int count = 0;
			for(int i = 0; i < 8; i++) {
				if(h+dy8[i] >= 0 && h+dy8[i] < src.rows && w+dx8[i] >=0 && w+dx8[i] < src.cols) {
					if(isTaken.at<uchar>(h+dy8[i],w+dx8[i]) == 0 && clusters.at<int>(h,w) != clusters.at<int>(h+dy8[i],w+dx8[i]))
						count++;
				}
			}
			if(count >= 2) {
				imgWithBorder.at<Vec3b>(h,w) = Vec3b(0,0,255);
				isTaken.at<uchar>(h,w) = 1;
			}
		}
	}
}

int main() {

	Mat img = imread("dog.png");
	imshow("image", img);
	Mat imgLab;
	cvtColor(img, imgLab, CV_BGR2Lab);

	Mat clusters;
	SLIC(imgLab, clusters, 400, 40, NORMAL);

	Mat imgWithBorder;
	drawBorder(img, clusters, imgWithBorder);

	imshow("border", imgWithBorder);

	waitKey(0);

	return 0;
}
