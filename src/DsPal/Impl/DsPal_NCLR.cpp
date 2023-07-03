#include "pch.h"
#include "DsPal_NCLR.h"

void DsPal_NCLR::getDataFromFile(std::ifstream& palFile)
{
  palFile.seekg(0, std::fstream::end);
  colorCount = std::min(256, (static_cast<uint16_t>(palFile.tellg()) - 0x28) / 2);

  //读取调色板
  palFile.seekg(0x28, std::fstream::beg);
  auto buf = std::make_unique<short[]>(colorCount * 2);
  palFile.read((char*)buf.get(), colorCount * 2);
  //转换调色板
  cv::Mat rawPalData(1, colorCount, CV_16U, buf.get());
  cv::Mat palData = cv::Mat::zeros(1, 256, CV_16U);
  rawPalData.copyTo(palData(cv::Rect2i(0, 0, colorCount, 1)));
  //分离调色板
  cv::Mat placeR = (palData & 0b11111) * 0b1000;
  cv::Mat placeG = (palData & 0b1111100000) / 0b100;
  cv::Mat placeB = (palData & 0b111110000000000) / 0b10000000;
  //转换为3通道Mat
  cv::merge(std::vector<cv::Mat>{ placeB, placeG, placeR }, palette);
  palette.convertTo(palette, CV_8U);
}
