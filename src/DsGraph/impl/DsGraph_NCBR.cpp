#include "pch.h"
#include "DsGraph_NCBR.h"
#include "Utils/utils.h"

cv::Mat DsGraph_NCBR::getOam(cv::Mat palette, DsOamType::OamData oamData)
{
  //获取子数据
  cv::Mat subData = getSubData(oamData.charaId, oamData.oamRect.size(), oamData.isBpp8);
  cv::Size2i oamMeasure = oamData.oamRect.size();
  cv::Mat outOam = subData.reshape(0, { oamMeasure.width,oamMeasure.height });
  return Utils::setPalette(outOam, palette, oamData.palId);
}
