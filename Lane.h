#ifndef __LANE_H__
#define __LANE_H__

#include <vector>

#include "Vehicle"
#include "Section"

class Lane {
  private:
    ///Private Variables
    // Vector of Sections
    vector<Section*> sections;
    int direction; //1 north, 2 east, 3 south, 4 west

  public:
    ///Constructors
    // Default Constructor
    Lane();
    // Constructor
    Lane(int length, Section* intSec1, Section* intSec2, int direction);

    // Destructor
    ~Lane();

    ///Functions
    // Changes occupied status
    Section* getSection(int i);
    inline int getDirection() {return direction;}
    void allotSections(Vehicle vehicle);//Do we need this?

};

#endif
