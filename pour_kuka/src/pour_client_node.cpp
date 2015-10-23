
#include <ros/ros.h>

#include "control_cmd_interface/control_cmd_interface.h"
#include "pour_kuka/pour_client.h"
#include "kuka_action_client/kuka_action_client.h"
#include "ros_param_parser/ros_param_parser.h"

int main(int argc,char** argv){




    ros::init(argc, argv, "control_cmd_interface");
    ros::NodeHandle nh("control_cmd_interface");

    std::string node_name = ros::this_node::getName();

    std::map<std::string,std::string> param_name_value;
    param_name_value[node_name + "/speech_topic"]           = "";
    param_name_value[node_name + "/service_name"]           = "";
    param_name_value[node_name + "/action_server_name"]     = "";

    if(!pps::parser_string(nh,param_name_value)){
        ROS_ERROR("failed to parse all parameters!");
        return -1;
    }

    std::string speech_topic       =  param_name_value[node_name + "/speech_topic"];
    std::string serivce_name       = param_name_value[node_name + "/service_name"];
    std::string action_server_name =  param_name_value[node_name + "/action_server_name"];


    // ------------- Initialise Action Client & Set Goals -------------

    Pour_client pour_client(action_server_name);
    ROS_INFO("after Pour_client");

    ci::action_callback_func action_callback = std::bind(&Pour_client::call_action,&pour_client,std::placeholders::_1);

    // --------------  Control cmd interface ----------------
    ci::Control_cmd_interface control_cmd_interface(nh,serivce_name);
    ROS_INFO("after control_cmd_interface");

    control_cmd_interface.register_callback(action_callback);

    control_cmd_interface.init_nl_subscriber(speech_topic);


    ros::spin();







    return 0;
}
