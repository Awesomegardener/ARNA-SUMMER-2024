//Node to transform published axes from joysticks on tablet to cmd_vel 

//TO DO: Include second joystick
//       Include limiters and other features in teleop_twist_joy

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include <math.h>


class TeleopArnaBase
{
public:
  TeleopArnaBase();


private:
  void joyCallback_linear(const sensor_msgs::Joy::ConstPtr& joy);
  void joyCallback_angular(const sensor_msgs::Joy::ConstPtr& joy);

  ros::NodeHandle nh_;
  geometry_msgs::Twist twist;

  int x_axis_, y_axis_;
  double l_scale_, a_scale_;
  ros::Publisher vel_pub_;
  ros::Subscriber joy_sub_linear_joystick;
  ros::Subscriber joy_sub_angular_joystick;

};


TeleopArnaBase::TeleopArnaBase():
  x_axis_(1),
  y_axis_(2)
{

  nh_.param("axis_linear", x_axis_, x_axis_);
  nh_.param("axis_angular", y_axis_, y_axis_);
  nh_.param("scale_angular", a_scale_, a_scale_);
  nh_.param("scale_linear", l_scale_, l_scale_);

   // TO DO: make topics subscribed from/published to be specifiable at node launch time, especially cos of potential namespace issues. Use Config file?
  vel_pub_ = nh_.advertise<geometry_msgs::Twist>("/arna_base/arna_base_controller/cmd_vel", 1);


  joy_sub_linear_joystick = nh_.subscribe<sensor_msgs::Joy>("joy_linear_pub", 10, &TeleopArnaBase::joyCallback_linear, this);
  joy_sub_angular_joystick = nh_.subscribe<sensor_msgs::Joy>("joy_angular_pub", 10, &TeleopArnaBase::joyCallback_angular, this);

}

void TeleopArnaBase::joyCallback_linear(const sensor_msgs::Joy::ConstPtr& joy)

{
  twist.linear.x = l_scale_*joy->axes[y_axis_];
  twist.linear.y = l_scale_*joy->axes[x_axis_];
  vel_pub_.publish(twist);
}
void TeleopArnaBase::joyCallback_angular(const sensor_msgs::Joy::ConstPtr& joy)
{
  twist.angular.z = a_scale_*atan2(joy->axes[y_axis_],joy->axes[x_axis_]);
  vel_pub_.publish(twist);
}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "teleop_arnabase");
  TeleopArnaBase teleop_arnabase;
  ros::spin();
}