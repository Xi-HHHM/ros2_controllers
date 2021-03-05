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

#ifndef FORCE_TORQUE_SENSOR_CONTROLLER__FORCE_TORQUE_SENSOR_CONTROLLER_HPP_
#define FORCE_TORQUE_SENSOR_CONTROLLER__FORCE_TORQUE_SENSOR_CONTROLLER_HPP_

#include <memory>
#include <string>
#include <vector>

#include "controller_interface/controller_interface.hpp"
#include "force_torque_sensor_controller/visibility_control.h"
#include "geometry_msgs/msg/wrench_stamped.hpp"
#include "rclcpp_lifecycle/node_interfaces/lifecycle_node_interface.hpp"
#include "rclcpp_lifecycle/state.hpp"
#include "realtime_tools/realtime_publisher.h"

namespace force_torque_sensor_controller
{
using CallbackReturn = rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;

class ForceTorqueSensorController : public controller_interface::ControllerInterface
{
public:
  FORCE_TORQUE_SENSOR_CONTROLLER_PUBLIC
  ForceTorqueSensorController();

  FORCE_TORQUE_SENSOR_CONTROLLER_PUBLIC
  controller_interface::return_type init(const std::string & controller_name) override;

  FORCE_TORQUE_SENSOR_CONTROLLER_PUBLIC
  controller_interface::InterfaceConfiguration command_interface_configuration() const override;

  FORCE_TORQUE_SENSOR_CONTROLLER_PUBLIC
  controller_interface::InterfaceConfiguration state_interface_configuration() const override;

  FORCE_TORQUE_SENSOR_CONTROLLER_PUBLIC
  CallbackReturn on_configure(const rclcpp_lifecycle::State & previous_state) override;

  FORCE_TORQUE_SENSOR_CONTROLLER_PUBLIC
  CallbackReturn on_activate(const rclcpp_lifecycle::State & previous_state) override;

  FORCE_TORQUE_SENSOR_CONTROLLER_PUBLIC
  CallbackReturn on_deactivate(const rclcpp_lifecycle::State & previous_state) override;

  FORCE_TORQUE_SENSOR_CONTROLLER_PUBLIC
  controller_interface::return_type update() override;

protected:
  std::string sensor_name_;
  std::vector<std::string> interface_names_;
  std::string frame_id_;
  std::shared_ptr<rclcpp::Publisher<geometry_msgs::msg::WrenchStamped>> sensor_state_publisher_;
  geometry_msgs::msg::WrenchStamped wrench_state_msg_;

  using ControllerStateMsg = geometry_msgs::msg::WrenchStamped;
  using StatePublisher = realtime_tools::RealtimePublisher<ControllerStateMsg>;
  using StatePublisherPtr = std::unique_ptr<StatePublisher>;
  rclcpp::Publisher<ControllerStateMsg>::SharedPtr publisher_;
  StatePublisherPtr state_publisher_;
};

}  // namespace force_torque_sensor_controller

#endif  // FORCE_TORQUE_SENSOR_CONTROLLER__FORCE_TORQUE_SENSOR_CONTROLLER_HPP_
