/*
**
** Copyright 2016, The Android Open Source Project
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#define LOG_TAG "android.hardware.keymaster@3.0-service"

#include <android/hardware/keymaster/3.0/IKeymasterDevice.h>

#include <hidl/HidlTransportSupport.h>
#include <hidl/LegacySupport.h>

#include <cutils/properties.h>

using android::status_t;
using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using android::hardware::registerPassthroughServiceImplementation;
using android::hardware::keymaster::V3_0::IKeymasterDevice;


int main() {
    configureRpcThreadpool(1, true);
    status_t result = registerPassthroughServiceImplementation<IKeymasterDevice>("default");
    if (result != android::OK) {
        return result;
    }
    property_set("keymaster.status", "ready");

    joinRpcThreadpool();

    return -1;
}