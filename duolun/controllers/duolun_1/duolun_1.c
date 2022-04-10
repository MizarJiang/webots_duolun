/*
 * File:          duolun_1.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/motor.h>, etc.
 */
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <webots/robot.h>
#include <webots/Motor.h>

/*
 * You may want to add macros here.
 */
#define TIME_STEP 32

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv) {
  /* necessary to initialize webots stuff */
  wb_robot_init();
  WbDeviceTag rf_dir,lf_dir,rb_dir,lb_dir;
  WbDeviceTag rf_run,lf_run,rb_run,lb_run;
  
  
  rf_dir=wb_robot_get_device("rf_dir_motor");
  lf_dir=wb_robot_get_device("lf_dir_motor");
  rb_dir=wb_robot_get_device("rb_dir_motor");
  lb_dir=wb_robot_get_device("lb_dir_motor");
  rf_run=wb_robot_get_device("rf_run_motor");
  lf_run=wb_robot_get_device("lf_run_motor");
  rb_run=wb_robot_get_device("rb_run_motor");
  lb_run=wb_robot_get_device("lb_run_motor");
  wb_motor_set_position(rf_run,INFINITY);
  wb_motor_set_position(lf_run,INFINITY);
  wb_motor_set_position(rb_run,INFINITY);
  wb_motor_set_position(lb_run,INFINITY);
  
  
  wb_motor_set_position(rf_dir,0.785);
  wb_motor_set_position(lf_dir,-0.785);
  wb_motor_set_position(rb_dir,-0.785);
  wb_motor_set_position(lb_dir,0.785);
 
  
  wb_motor_set_velocity(rf_run,10);
  wb_motor_set_velocity(lf_run,10);
  wb_motor_set_velocity(rb_run,10);
  wb_motor_set_velocity(lb_run,10);
  
  wb_robot_step(3400);
  
  wb_motor_set_position(rf_dir,0);
  wb_motor_set_position(lf_dir,0);
  wb_motor_set_position(rb_dir,0);
  wb_motor_set_position(lb_dir,0);
  
  wb_motor_set_velocity(rf_run,6);
  wb_motor_set_velocity(lf_run,6);
  wb_motor_set_velocity(rb_run,6);
  wb_motor_set_velocity(lb_run,6);
  
  wb_robot_step(3400);
  
  for(double i=0;i<1.5707;)
  {
    wb_motor_set_position(rf_dir,i);
    wb_motor_set_position(lf_dir,i);
    wb_motor_set_position(rb_dir,i);
    wb_motor_set_position(lb_dir,i);
    
    wb_robot_step(32);
    
    i+=0.1;
  }
  
  wb_motor_set_velocity(rf_run,6);
  wb_motor_set_velocity(lf_run,6);
  wb_motor_set_velocity(rb_run,6);
  wb_motor_set_velocity(lb_run,6);
 

  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */

  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
  while (wb_robot_step(TIME_STEP) != -1) {
    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */

    /* Process sensor data here */
    

    /*
     * Enter here functions to send actuator commands, like:
     * wb_motor_set_position(my_actuator, 10.0);
     */
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
