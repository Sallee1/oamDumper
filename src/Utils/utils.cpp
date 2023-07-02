#include "utils.h"

cv::Mat Utils::setPalette(cv::Mat graph, cv::Mat palette, int Bpp4PalId)
{
  graph += Bpp4PalId * 16;
  cv::cvtColor(graph, graph, cv::COLOR_GRAY2RGB);
  cv::Mat dst;
  cv::LUT(graph, palette, dst);
  return dst;
}