#include "slic_opencv2.h"

#include <cmath>

using namespace std;

void SLIC(const Mat& src, Mat& clusters, int numSuperPixels, int nc, enum method) {
	int width = src.cols;
	int height = src.rows;
	double step = sqrt(width*height / (double)numSuperPixels);

	IplImage iplImg = IplImage(src);

	Slic slic;
    slic.generate_superpixels(&iplImg, step, nc);
    slic.create_connectivity(&iplImg);

    clusters.create(src.size(), CV_32S);
    for(int h = 0; h < height; h++) {
    	for(int w = 0; w < width; w++) {
    		clusters.at<int>(h,w) = slic.clusters[w][h];
    	}
    }
}
