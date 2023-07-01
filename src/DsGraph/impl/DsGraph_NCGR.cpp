#include "pch.h"
#include "DsGraph_NCGR.h"

cv::Mat DsGraph_NCGR::getOam(uint32_t charaID, OamSize sizeEnum, bool isBpp8)
{
  //获取子数据
  cv::Mat subData = getSubData(charaID, sizeEnum, isBpp8);

  cv::Size2i oamMeasure = oamSizeMapper.at(sizeEnum);
  cv::Size2i oamTileMeasure = oamMeasure / 8;
  int32_t tileCount = oamTileMeasure.width * oamTileMeasure.height;

  //拼接子数据
  cv::Mat outOam(oamMeasure, CV_8U);
  for (int i = 0; i < oamTileMeasure.height; i++)
  {
    for (int j = 0; j < oamTileMeasure.width; j++) {
      auto tileImg = subData(cv::Rect2i((i * oamTileMeasure.height + j) * 64, 0, 64, 1)).reshape(0, { 8,8 });
      auto roi = cv::Rect2i(j * 8, i * 8, 8, 8);
      tileImg.copyTo(outOam(roi));
    }
  }
  return outOam;
}
