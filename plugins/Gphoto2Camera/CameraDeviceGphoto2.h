/*
 * This file is part of the Dronecode Camera Manager
 *
 * Copyright (C) 2017  Intel Corporation. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once
#include <atomic>
#include <string>
#include <vector>

#include <gphoto2/gphoto2-camera.h>

#include "CameraDevice.h"
#include "CameraParameters.h"

class CameraDeviceCustom final : public CameraDevice {
public:
    CameraDeviceCustom(std::string device);
    ~CameraDeviceCustom();
    std::string getDeviceId() const;
    Status getInfo(CameraInfo &camInfo) const;
    bool isGstV4l2Src() const;
    Status init(CameraParameters &camParam);
    Status uninit();
    Status start();
    Status stop();
    Status read(CameraData &data);
    Status setParam(CameraParameters &camParam, const std::string param, const char *param_value,
                    const size_t value_size, const int param_type);
    Status resetParams(CameraParameters &camParam);
    Status setSize(const uint32_t width, const uint32_t height);
    Status getSize(uint32_t &width, uint32_t &height) const;
    Status getSupportedSizes(std::vector<Size> &sizes) const;
    Status setPixelFormat(const CameraParameters::PixelFormat format);
    Status getPixelFormat(CameraParameters::PixelFormat &format) const;
    Status getSupportedPixelFormats(std::vector<CameraParameters::PixelFormat> &formats) const;
    Status setMode(const CameraParameters::Mode mode);
    Status getMode(CameraParameters::Mode &mode) const;
    Status getSupportedModes(std::vector<CameraParameters::Mode> &modes) const;
    Status setFrameRate(const uint32_t fps);
    Status getFrameRate(uint32_t &fps) const;
    Status getSupportedFrameRates(uint32_t &minFps, uint32_t &maxFps);
    Status setCameraDefinitionUri(const std::string uri);
    std::string getCameraDefinitionUri() const;
    std::string getOverlayText() const;

private:
    // Declare parameter name & ID
    // Possible values of the params are in camera definition file
    static const char PARAMETER_CUSTOM_UINT8[];
    static const int ID_PARAMETER_CUSTOM_UINT8;
    static const char PARAMETER_CUSTOM_UINT32[];
    static const int ID_PARAMETER_CUSTOM_UINT32;
    static const char PARAMETER_CUSTOM_INT32[];
    static const int ID_PARAMETER_CUSTOM_INT32;
    static const char PARAMETER_CUSTOM_REAL32[];
    static const int ID_PARAMETER_CUSTOM_REAL32;
    static const char PARAMETER_CUSTOM_ENUM[];
    static const int ID_PARAMETER_CUSTOM_ENUM;
    std::string mDeviceId;
    std::atomic<CameraDevice::State> mState;
    uint32_t mWidth;
    uint32_t mHeight;
    CameraParameters::PixelFormat mPixelFormat;
    CameraParameters::Mode mMode;
    uint32_t mFrmRate;
    std::string mCamDefUri;
    std::string mOvText;
};
