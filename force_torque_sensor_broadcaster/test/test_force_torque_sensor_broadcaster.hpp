// Copyright (c) 2021, Stogl Robotics Consulting UG (haftungsbeschränkt)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*
 * Author: Subhas Das, Denis Stogl
 */

#ifndef TEST_FORCE_TORQUE_SENSOR_BROADCASTER_HPP_
#define TEST_FORCE_TORQUE_SENSOR_BROADCASTER_HPP_

#include <memory>
#include <string>
#include <vector>

#include "gmock/gmock.h"

#include "force_torque_sensor_broadcaster/force_torque_sensor_broadcaster.hpp"

// subclassing and friending so we can access member varibles
class FriendForceTorqueSensorBroadcaster : public force_torque_sensor_broadcaster::
  ForceTorqueSensorBroadcaster
{
  FRIEND_TEST(ForceTorqueSensorBroadcasterTest, SensorNameParameterNotSet);
  FRIEND_TEST(ForceTorqueSensorBroadcasterTest, InterfaceNamesParameterNotSet);
  FRIEND_TEST(ForceTorqueSensorBroadcasterTest, FrameIdParameterNotSet);
  FRIEND_TEST(ForceTorqueSensorBroadcasterTest, SensorNameParameterIsEmpty);
  FRIEND_TEST(ForceTorqueSensorBroadcasterTest, InterfaceNameParameterIsEmpty);

  FRIEND_TEST(ForceTorqueSensorBroadcasterTest, ActivateSuccess);
  FRIEND_TEST(ForceTorqueSensorBroadcasterTest, UpdateTest);
  FRIEND_TEST(ForceTorqueSensorBroadcasterTest, SensorStatePublishTest);
};

class ForceTorqueSensorBroadcasterTest : public ::testing::Test
{
public:
  static void SetUpTestCase();
  static void TearDownTestCase();

  void SetUp();
  void TearDown();

  void SetUpStateController();

protected:
  std::unique_ptr<FriendForceTorqueSensorBroadcaster> state_controller_;
};

#endif  // TEST_FORCE_TORQUE_SENSOR_BROADCASTER_HPP_
