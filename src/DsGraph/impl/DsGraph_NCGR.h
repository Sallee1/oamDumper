#pragma once
#include <DsGraph/common/DsGraph_Nitro.h>
#include <DsGraph/type.h>
#include <pch.h>

class DsGraph_NCGR :public DsGraph_Nitro {
public:
  cv::Mat getOam(uint32_t charaID, OamSize sizeEnum, bool isBpp8 = false) override;
};