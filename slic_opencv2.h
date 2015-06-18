#ifndef __SLIC_OPENCV2__
#define __SLIC_OPENCV2__

#include "slic.h"

#include <opencv2/opencv.hpp>

using namespace cv;

enum method {NORMAL, FAST};

void SLIC(const Mat& src, Mat& clusters, int numSuperPixels, int nc, enum method = NORMAL);

#endif
