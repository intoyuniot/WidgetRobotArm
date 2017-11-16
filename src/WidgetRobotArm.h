#ifndef WIDGET_ROBOT_ARM_H_
#define WIDGET_ROBOT_ARM_H_

#include "application.h"




class WidgetRobotArm : public WidgetBaseClass
{

public:
    WidgetRobotArm(uint8_t ucItem = 0);
    ~WidgetRobotArm();
    void begin(void (*UserCallBack)(void) = NULL);
    int getBase(void);
    int getShoulder(void);
    int getElbow(void);
    int getWrist(void);
    int getGripper(void);
    
private:
    char pCmdControlTopic[64];
    char pDataStatusTopic[64];
    uint8_t _Item = 0;         
	int  _baseValue;	
	int  _shoulderValue;	
	int  _elbowValue;	
	int  _wristValue;	
	int  _gripperValue;
    void (*_EventCb)(void);
    void widgetBaseCallBack(uint8_t *payload, uint32_t len);

};

#endif
