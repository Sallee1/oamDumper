#pragma once
#include "DsGraph/type.h"
#include "pch.h"

class Interface_DsGraph
{
protected:
  cv::Mat data4Bpp;    //U81d
  cv::Mat data8Bpp;    //U81d
  uint32_t dataSize;
public:
  virtual void getDataFromFile(std::ifstream& graphFile) = 0;
  virtual cv::Mat getOam(uint32_t charaID, OamSize sizeEnum, bool isBpp8 = false) = 0;
};

