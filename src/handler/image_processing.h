#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <string>

#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

class image_processing {
    public:
        cv::Mat multipartFileToMat(std::string multipartFile);
};

#endif
