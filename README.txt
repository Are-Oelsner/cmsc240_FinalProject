Authors: Are, Ryan, Maddie

Project Goal: Simulate a traffic intersection

Notes:
four lanes of traffic total, Eastbound, Westbound, Northbound and Southbound
Traffic lights that control the intersection, which are synchronized
Have cars, SUVs and trucks, which will change the decision parameters for
going through a yellow light etc. Inherit from a base class ~vehicle
when modelling lanes divide the road into sections
No U-turns
No right on red in base model, can extend to this if we want
Can make decisions about clearing potential deadlock scenarios, Ex. yield in
favor of the northeast
Different size vehicles take up a different number of sections
Vehicle sizes are given
Cars take two sections
SUVs take three sections
Trucks take 4 sections
Vehicles move one section at a time / clock tick?||unit of time?
For each clock tick update every car that can move
Can assume vehicles act like caterpillars so they can turn easily
yellow light means that cars can only go if they will be able to make it fully
through the intersection by the time it turns red.
Can start with cars originally going straight with lights, and then add turns in
later.

Might need to make a GUI or can do that for extra credit


mt19937 Mersenne Twister Pseudo-Random Number Generator


TODO::
Early class design due next monday

////////////////////////////////////////////////////////////////////////////////
Classes:

Ryan
Vehicle
    Car
    SUV
    Truck

Are
Intersection
Lane
Section 

Maddie
TrafficLight
Random
Main
Clock

////////////////////////////////////////////////////////////////////////////////
Ownership:

main
  vehicles
    ->Lane
      ->sections
  Intersection
    Lane
      Section
      TrafficLight
  Random
  Clock


////////////////////////////////////////////////////////////////////////////////
Classes:
Vehicle
  //Private Variables
  int size //number of sections

    Car
    SUV
    Truck

Intersection
Lane
Section
  Points to neighbor sections
  traffic flow
TrafficLight

Random

Clock

