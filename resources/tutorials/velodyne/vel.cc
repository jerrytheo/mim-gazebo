#include <gazebo/gazebo_config.h>
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/gazebo_client.hh>


int main(int _argc, char** _argv)
{
    // Load gazebo as a client.
    gazebo::client::setup(_argc, _argv);

    // Create our node for communication.
    gazebo::transport::NodePtr node(new gazebo::transport::Node());
    node->Init();

    // Publish to the velodyne topic
    gazebo::transport::PublisherPtr pub =
        node->Advertise<gazebo::msgs::Vector3d>("vel_cmd");

    // Wait for a subscriber to connect to this publisher.
    pub->WaitForConnection();

    // Create a vector3d message.
    gazebo::msgs::Vector3d msg;

    // Set the velocity in the x-component.
    gazebo::msgs::Set(&msg, ignition::math::Vector3d(std::atof(_argv[1]), 0, 0));

    // Send the message.
    pub->Publish(msg);

    // Shut everything down.
    gazebo::client::shutdown();
}