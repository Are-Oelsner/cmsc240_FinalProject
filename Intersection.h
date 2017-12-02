#ifndef __SECTION_H__
#define __SECTION_H__

class Section {
  protected:
    ///Private Variables
    // Section status
    bool occupied;
    bool isIntersection;

    // Section flow
    bool up;
    bool right;
    bool down;
    bool left;

    // Neighbor Sections
    Section upSection;
    Section rightSection;
    Section downSection;
    Section leftSection;


  public:
    ///Constructors
    // Default Constructor
    Section();

    // Destructor
    ~Section();

    ///Functions
    // Changes occupied status
    void toggleOccupied();
    // get occupied status
    bool getOccupied() {return occupied;}
    // get isIntersections status
    bool getIsIntersection() {return isIntersection;}

    // get up
    inline bool up() {return up;}
    // get right
    inline bool right() {return right;}
    // get down
    inline bool down() {return down;}
    // get left
    inline bool left() {return left;}

    // get upSection
    Section getUp();
    // get rightSection
    Section getRight();
    // get downSection
    Section getDown();
    // get leftSection
    Section getLeft();
};

#endif
