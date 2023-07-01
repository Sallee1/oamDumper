#pragma once
#include <pch.h>
namespace Utils {
  cv::Mat setPalette(cv::Mat graph, cv::Mat palette, int Bpp4PalId = 0)
  {
    graph += Bpp4PalId * 16;
    cv::cvtColor(graph, graph, cv::COLOR_GRAY2RGB);
    cv::Mat dst;
    cv::LUT(graph, palette, dst);
    return dst;
  }
}