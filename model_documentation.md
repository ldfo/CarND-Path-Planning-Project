# CarND-Path-Planning-Project Model Documentation

### The software is able to navigate more than 4.32 miles without incidents or alarms. I left it running and it reached 36 miles without incidents.


### Path Planning Prediction
Here the software uses telemetry and sensor fusion data to predict other cars
trajectories and to reason about the environment surrounding the car.
The code evaluates if:
  1) There's a car ahead
  2) There's a car left or right of the lane (for changing lanes)

The code evaluates the lane and the position of the other cars on the road at the end of the last iteration (planned trajectory) to avoid dangerous situations. 


### Path Planning Behavior

Here the software decides what to do with the given information, change lanes
if another car is on the same lane, speed up or down.

If the car is in front of us and the gap is less than 30 meters, the car tries to adapt speed.

If the car ahead is too close we try to switch lanes, first we try to change to the left lane and if the lane is clear we change.


### Path Planning Trajectory Generation

The software generates a new trajectory based of the current speed, lane,
outputs from the behavior algorithm and previous waypoints.

If there is no data on the previous path we initialize the starting point with the current car space. Otherwise we populate with the previous path.

The coordinates (shift and yaw) are transformed  to local car coordinates

The last trajectory waypoints are copied to the new generated trajectory and
the rest of the waypoints are generated fitting the spline.

The change in the car speed is determined in the behavior algorithm. It will try to reach the reference velocity set as 49 mph

#### Model Shortcomings:
A PID or MPC controller could be used to follow the Path Planning output path
extracting the desired speed from the path and then feed that into the controller.
Also for future work a MPC controller could change the cost function and use the distance
to a waypoint on the generated path.
