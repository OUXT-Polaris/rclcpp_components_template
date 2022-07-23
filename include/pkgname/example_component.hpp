// Copyright (c) 2022 OUXT Polaris
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

#pragma once

#include "pkgname/visibility_control.h"

// Headers in ROS2
#include <rclcpp/rclcpp.hpp>

// Headers needed in pub/sub, exposed types
#include <memory> // shared_ptr in pub_
//#include <perception_msgs/msg/tracking2_d.hpp> // Tracking2D in pub_

namespace pkgname
{
class ExampleComponent : public rclcpp::Node
{
public:
  PKGNAME_PUBLIC
  explicit ExampleComponent(const rclcpp::NodeOptions & options);

private:
//  std::shared_ptr<rclcpp::Publisher<perception_msgs::msg::Tracking2D>> pub_;
//  std::shared_ptr<rclcpp::Subscription<perception_msgs::msg::Tracking2D>> sub_;
};
}
