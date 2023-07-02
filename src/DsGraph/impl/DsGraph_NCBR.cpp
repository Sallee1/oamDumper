#include "pch.h"
#include "DsGraph_NCBR.h"

cv::Mat DsGraph_NCBR::getOam(DsOamType::OamData oamData)
{
  //获取子数据
  cv::Mat subData = getSubData(oamData.charaId, oamData.oamRect.size(), oamData.isBpp8);
  cv::Size2i oamMeasure = oamData.oamRect.size();
  return subData.reshape(0, { oamMeasure.width,oamMeasure.height });
}
