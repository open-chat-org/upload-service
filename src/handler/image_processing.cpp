#include "image_processing.h"

cv::Mat image_processing::multipartFileToMat(std::string multipartFile) {
    std::vector<char> vector_data(multipartFile.begin(), multipartFile.end());

    cv::Mat data_mat(vector_data, true);
    cv::Mat image(cv::imdecode(data_mat, 1));

    return image;
}
