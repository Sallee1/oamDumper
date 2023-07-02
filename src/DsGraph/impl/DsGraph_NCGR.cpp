#include "pch.h"
#include "DsGraph_NCGR.h"
#include "Utils/utils.h"

cv::Mat DsGraph_NCGR::getOam(cv::Mat palette, DsOamType::OamData oamData)
{
  //获取子数据
  cv::Mat subData = getSubData(oamData.charaId, oamData.oamRect.size(), oamData.isBpp8);

  cv::Size2i oamMeasure = oamData.oamRect.size();
  cv::Size2i oamTileMeasure = oamMeasure / 8;
  int32_t tileCount = oamTileMeasure.width * oamTileMeasure.height;

  //拼接子数据
  cv::Mat outOam(oamMeasure, CV_8U);
  for (int i = 0; i < oamTileMeasure.height; i++)
  {
    for (int j = 0; j < oamTileMeasure.width; j++) {
      auto tileImg = subData(cv::Rect2i((i * oamTileMeasure.width + j) * 64, 0, 64, 1)).reshape(0, { 8,8 });
      auto roi = cv::Rect2i(j * 8, i * 8, 8, 8);
      tileImg.copyTo(outOam(roi));
    }
  }
  return Utils::setPalette(outOam, palette, oamData.palId);
}
