#ifndef __traffic_h__
#define __traffic_h__


class TrafficLight
{
protected:
	//create an enumerator {red, green, yellow}
	enum Color { red, green, yellow};
	int greenTime;
	int yellowTime;
	int redTime;



public:
	void change(Color to, Color from);
	int getGreenTime();
	int getYellowTime();
	int getRedTime();
	void setGreenTime();
	void setRedTime();
	void setYellowTime();
	




}

#endif
