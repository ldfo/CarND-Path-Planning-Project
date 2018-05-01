#ifndef PATHPLANNER_H
#define PATHPLANNER_H

#include <math.h>
#include <iostream>
#include <vector>

#include "Eigen-3.3/Eigen/Core"
#include "Eigen-3.3/Eigen/QR"

#include "spline.h"

// path planner class
class PathPlanner{

	public:
		// Destructor
		virtual ~PathPlanner(); 

		// Change Lane, 0 is left, 1 middle and 2 the right one
		void changeLane(int lane); 
};

#endif //PATHPLANNER_H