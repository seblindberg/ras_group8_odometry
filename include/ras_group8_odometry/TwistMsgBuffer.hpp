#pragma once

// ROS
#include <ros/assert.h>
#include <geometry_msgs/TwistStamped.h>

/* TODO: Document the methods.
 */

namespace ras_group8_odometry
{

class TwistMsgBuffer
{
 public:
  /* Constructor.
   */
  TwistMsgBuffer();

  /* Destructor.
   */
  virtual ~TwistMsgBuffer();

  bool
    isInitialized();

  bool
    isValid();
    
  void
    insert(const geometry_msgs::TwistStamped& msg);
  
  const geometry_msgs::TwistStamped*
    head()
  {
    ROS_ASSERT(msgs_until_initialized_ <= 1);
    return msg_head_;
  }
    
  const geometry_msgs::TwistStamped*
    tail()
  {
    ROS_ASSERT(msgs_until_initialized_ == 0);
    return msg_tail_;
  }
  
 private:
  void
    flush();
   
  /* Variables
   */
  int msgs_until_initialized_;
   
  const geometry_msgs::TwistStamped  msg_a_;
  const geometry_msgs::TwistStamped  msg_b_;
  
  const geometry_msgs::TwistStamped* msg_head_;
  const geometry_msgs::TwistStamped* msg_tail_;
};

} /* namespace */

