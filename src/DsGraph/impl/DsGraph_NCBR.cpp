#include "pch.h"
#include "DsGraph_NCBR.h"

cv::Mat DsGraph_NCBR::getOam(uint32_t charaID, OamSize sizeEnum, bool isBpp8)
{
  //获取子数据
  cv::Mat subData = getSubData(charaID, sizeEnum, isBpp8);
  cv::Size2i oamMeasure = oamSizeMapper.at(sizeEnum);
  return subData.reshape(0, { oamMeasure.width,oamMeasure.height });
}
