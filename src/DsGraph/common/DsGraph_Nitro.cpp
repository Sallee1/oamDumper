#include "pch.h"
#include "DsGraph_Nitro.h"

void DsGraph_Nitro::getDataFromFile(std::ifstream& graphFile)
{
  graphFile.seekg(0x28);
  graphFile.read((char*)&dataSize, sizeof(dataSize));

  auto buf = std::make_unique<char[]>(dataSize);
  graphFile.seekg(0x30);
  graphFile.read(buf.get(), dataSize);
  //8bpp，直接读取
  data8Bpp = cv::Mat(1, dataSize, CV_8U, buf.get()).clone();

  //4bpp，需要拆分位平面
  cv::Mat plane0 = cv::Mat(dataSize, 1, CV_8U, buf.get()).clone();
  cv::Mat plane1 = cv::Mat(dataSize, 1, CV_8U, buf.get()).clone();
  plane0 = plane0 & 0b00001111;
  plane1 = (plane1 & 0b11110000) / 16;
  cv::hconcat(plane0, plane1, data4Bpp);

  data4Bpp = data4Bpp.reshape(0, std::vector<int>{1, static_cast<int>(dataSize) * 2});
}

cv::Mat DsGraph_Nitro::getSubData(uint32_t charaID, cv::Size2i charaSize, bool isBpp8)
{
  uint32_t oamDataSize = charaSize.width * charaSize.height;
  uint32_t oamAddr = isBpp8 ? charaID * 128 : charaID * 256;

  //获取子数据
  cv::Mat subData;
  if (isBpp8) {
    subData = data8Bpp(cv::Rect2d(oamAddr, 0, oamDataSize, 1));
  }
  else
  {
    subData = data4Bpp(cv::Rect2d(oamAddr, 0, oamDataSize, 1)).clone();
  }
  return subData;
}
