﻿#pragma once
#include <DsGraph/common/DsGraph_Nitro.h>
#include <type.h>
#include <pch.h>

class DsGraph_NCGR :public DsGraph_Nitro {
public:
  cv::Mat getOam(DsOamType::OamData oamData) override;
};