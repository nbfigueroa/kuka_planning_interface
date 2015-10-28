#ifndef KUKA_ACTION_SERVER_KUKA_GOTO_CART_AS_H_
#define KUKA_ACTION_SERVER_KUKA_GOTO_CART_AS_H_

/**
  *  Kuka goto cartesian action server
  *
  *  Robot moves from its current end-effector frame of reference (6D, position + orientation)
  *  to a target frame of reference. The positions along the trajectory are computed through
  *  inverse kinematics.
  *
  **/

#include "kuka_action_server/base_action_server.h"
#include "kuka_action_server/base_ee_action.h"
#include "kuka_common_action_server/action_initialiser.h"

namespace asrv{

class Kuka_goto_cart_as : public Base_ee_action , public Base_action_server{

public:

    Kuka_goto_cart_as(ros::NodeHandle&  nh, const Action_ee_initialiser &action_ee_init);

    virtual bool execute_CB(alib_server& as_,alib_feedback& feedback,const cptrGoal& goal);

private:

    bool goto_cartesian_closed_loop(alib_server& as_,alib_feedback& feedback,const cptrGoal& goal);

private:

    inline double bell_velocity(double x,double beta,double off){
        return 1.0 - exp(-beta * (x+off) * (x+off));
    }


private:


    std::string     action_name;
    std::string     world_frame;

   // tf::Pose        curr_ee_pose;   /// end-effector current position
    tf::Pose        des_ee_pose;    /// desired end-effector position


    double          dt;
    double          default_speed;
    double          reachingThreshold;
    double          orientationThreshold;

    bool            initial_config;
    bool            simulation;
    std::size_t     tf_count;

};

}

#endif
