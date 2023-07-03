#include "pch.h"
#include "DsOam_NCER.h"

void DsOam_NCER::getDataFromFile(std::ifstream& oamFile)
{
  // 帧数
  uint16_t frameCount;
  uint32_t oamBegAddr;
  oamFile.seekg(0x18);
  oamFile.read((char*)&frameCount, sizeof(frameCount));

  bool isExtend;    //扩展模式下，帧表是16字节而不是8字节，需要特殊处理
  oamFile.seekg(0x1A);
  oamFile.read((char*)&isExtend, sizeof(isExtend));
  if (isExtend)
  {
    oamBegAddr = frameCount * 16 + 0x30;
  }
  else
  {
    oamBegAddr = frameCount * 8 + 0x30;
  }
  // 帧信息
  std::vector<std::pair<uint32_t, uint32_t>> frameInfos;
  oamFile.seekg(0x30);
  for (int i = 0; i < frameCount; i++)
  {
    uint16_t oamLen;
    uint32_t oamAddr;
    oamFile.read((char*)&oamLen, sizeof(oamLen));
    oamFile.seekg(2, std::fstream::cur);
    oamFile.read((char*)&oamAddr, sizeof(oamAddr));
    if (isExtend) {
      oamFile.seekg(8, std::fstream::cur);
    }
    oamAddr += oamBegAddr;
    frameInfos.emplace_back(std::make_pair(oamLen, oamAddr));
  }

  //获取Oam数据
  auto oamBuf = std::make_shared<uchar[]>(6);

  for (auto frameInfo : frameInfos)
  {
    std::vector<DsOamType::OamData> oamDataList;

    oamFile.seekg(frameInfo.second);
    for (int i = 0; i < frameInfo.first; i++)
    {
      oamFile.read((char*)oamBuf.get(), 6);
      auto oamData = getOamDataFromBuf(oamBuf);
      oamDataList.emplace_back(oamData);
    }
    this->oamFrameList.emplace_back(oamDataList);
  }
}

DsOamType::OamData DsOam_NCER::getOamDataFromBuf(std::shared_ptr<uchar[]> buf)
{
  DsOamType::OamData oamData;
  oamData.charaId = buf[4] + (static_cast<ushort>(0b00000011 & buf[5]) << 8);
  oamData.isBpp8 = (buf[1] & 0b00100000) >> 5;
  oamData.palId = buf[5] >> 4;
  oamData.hFlip = (buf[3] & 0b00100000) >> 5;
  oamData.vFlip = (buf[3] & 0b00010000) >> 4;

  DsOamType::OamSize oamSizeEnum = static_cast<DsOamType::OamSize>((buf[3] >> 6) + (buf[1] >> 6 << 2));
  cv::Size2i oamSize = DsOamType::oamSizeMapper.at(oamSizeEnum);

  bool XIsNig = buf[3] & 0b00000001;
  bool YIsNig = buf[0] >> 7;

  short posX = buf[2];
  short posY = buf[0] & 0b01111111;

  if (XIsNig) posX -= 256;
  if (YIsNig) posY -= 128;

  cv::Point2i oamPos(posX, posY);
  oamData.oamRect = cv::Rect(oamPos, oamSize);
  return oamData;
}
