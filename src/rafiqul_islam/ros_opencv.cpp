#include<cv_bridge/cv_bridge.h>
#include<image_transport/image_transport.h>
#include<ros/ros.h>
#include<opencv2/imgproc/imgproc.hpp>
#include<sensor_msgs/image_encodings.h>
#include<opencv2/highgui/highgui.hpp>
#include<string>
using namespace std;

string NAME = "Rafiqul Islam";
ros::NodeHandle nh;
image_transport::ImageTransport transport(nh);
image_transport::Subscriber subscriber;
image_transport::Publisher publisher;

void callback(const sensor_msgs::ImageConstPtr& msg){
  cv_bridge::CvImagePtr img_pointer;
  img_pointer = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR16);
  cv::imshow(NAME, img_pointer->image);
  cv::waitKey(10);
  publisher.publish(img_pointer->toImageMsg());
}


int main(int argc, char** argv){ 
  ros::init(argc, argv, "ros_opencv");
  transport.subscribe("subscribe_image",1,&callback);
  transport.advertise("/publish_image", 1);
  ros::spin();
  
}