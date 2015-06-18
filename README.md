# SLIC Superpixel Implementation
This repository forks the original repo at <a href="https://github.com/PSMM/SLIC-Superpixels">PSMM/SLIC-Superpixels</a>. A wrapper is added for OpenCV 2 data structures.

## Method Declaration

```c++
void SLIC(const Mat& src, Mat& clusters, int numSuperPixels, int nc, enum method = NORMAL);
```

numSuperPixels is the desired number of superpixels.
nc is the weight factor.

## Usage

Include header

```c++
#include "slic_opencv2.h"
```

Call function

```c++
SLIC(imgLab, clusters, 400, 40, NORMAL);
```

## Exemplary result
The images below shows an example of an over-segmentation using 400 superpixels and a weight factor of 40.
<p align="center">
  <img src="https://github.com/PSMM/SLIC-Superpixels/blob/master/dog.png?raw=true" alt="Dog"/>
  <img src="https://github.com/PSMM/SLIC-Superpixels/blob/master/dog_segmentation.png?raw=true" alt="Dog Segmentation"/>
</p>
