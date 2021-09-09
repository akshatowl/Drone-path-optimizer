#include <ros/ros.h>
#include <gnc_functions.hpp>

int main(int argc, char** argv)
{
	int steps=0; //iterating over the vector

	//initialize ros
	ros::init(argc, argv, "gnc_node");
	ros::NodeHandle gnc_node;

  init_publisher_subscriber(gnc_node);

  // wait for FCU connection, loops till connection is setup
	wait4connect();

	//wait for used to switch to mode GUIDED
	wait4start();

	//creates a local reference frame
	initialize_local_frame();

  takeoff(3);

	std::vector<gnc_api_waypoint> waypoints;
	gnc_api_waypoint new_waypoint;
	new_waypoint.x = 0;
	new_waypoint.y = 0;
	new_waypoint.z = 3;
	new_waypoint.psi = 0;
	waypoints.push_back(new_waypoint);
	new_waypoint.x = -2;
	new_waypoint.y = 5;
	new_waypoint.z = 3;
	new_waypoint.psi = -90;
	waypoints.push_back(new_waypoint);
	new_waypoint.x = 0;
	new_waypoint.y = 10;
	new_waypoint.z = 3;
	new_waypoint.psi = 0;
	waypoints.push_back(new_waypoint);
	new_waypoint.x = 5;
	new_waypoint.y = 12;
	new_waypoint.z = 3;
	new_waypoint.psi = -90;
	waypoints.push_back(new_waypoint);
	new_waypoint.x = 10;
	new_waypoint.y = 10;
	new_waypoint.z = 3;
	new_waypoint.psi = -90;
	waypoints.push_back(new_waypoint);

	ros::Rate rate(2.0);

	while(ros::ok())
	{
		ros::spinOnce();
		rate.sleep();

		if(check_waypoint_reached(.5) == 1) //if actual estimated(ekf) position is in Vicinity of waypoint
		{
			if (steps < waypoints.size())
			{
				set_destination(waypoints[steps].x,waypoints[steps].y,waypoints[steps].z, waypoints[steps].psi);
				steps++;
			}
			  else{
				land(); //land the drone once every destination has been reached
		       	}
		}

	}






  return 0;
}
