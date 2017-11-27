#ifndef __LANE_H__
#define __LANE_H__

#include <vector>

#include "Vehicle"
#include "Section"

class Lane {
  private:
    ///Private Variables
    // Vector of Sections
    vector<Section> sections;

  public:
    ///Constructors
    // Default Constructor
    Lane();
    // Constructor
    Lane(int numSections);

    // Destructor
    ~Lane();

    ///Functions
    // Changes occupied status
    Section getSection
    void allotSections(Vehicle vehicle);

};

#endif
