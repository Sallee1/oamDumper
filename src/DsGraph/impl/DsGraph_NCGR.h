﻿#pragma once
#include <pch.h>
#include <DsGraph/common/DsGraph_Nitro.h>
#include <type.h>

class DsGraph_NCGR :public DsGraph_Nitro {
public:
  cv::Mat getOam(cv::Mat palette, DsOamType::OamData oamData) override;
};