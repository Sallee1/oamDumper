#pragma once
#include "pch.h"

class Interface_DsPal {
protected:
  cv::Mat palette;
  uint16_t colorCount;
public:
  virtual void getDataFromFile(std::ifstream& palFile) = 0;
  cv::Mat getPal();
};