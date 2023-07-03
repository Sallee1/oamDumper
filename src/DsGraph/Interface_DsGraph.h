#pragma once
#include <pch.h>
#include "type.h"

class Interface_DsGraph
{
protected:
  cv::Mat data4Bpp;    //U81d
  cv::Mat data8Bpp;    //U81d
  uint32_t dataSize;
public:
  virtual void getDataFromFile(std::ifstream& graphFile) = 0;
  virtual cv::Mat getOam(cv::Mat palette, DsOamType::OamData oamData) = 0;
};

