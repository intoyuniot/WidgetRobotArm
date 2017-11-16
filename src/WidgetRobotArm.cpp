
#include "WidgetRobotArm.h"


WidgetRobotArm::WidgetRobotArm(uint8_t ucItem)
{
    _Item=ucItem;
    memset(pCmdControlTopic,0,sizeof(pCmdControlTopic));
    memset(pDataStatusTopic,0,sizeof(pDataStatusTopic));  
    sprintf(pCmdControlTopic,"channel/robotArm_%d/cmd/control",_Item);   
    sprintf(pDataStatusTopic,"channel/robotArm_%d/data/status",_Item);  
}

WidgetRobotArm::~WidgetRobotArm()
{
    
}

void WidgetRobotArm::begin(void (*UserCallBack)(void))
{
    _EventCb=UserCallBack;
    IntoRobot.subscribe(pCmdControlTopic, NULL, this);
}

int WidgetRobotArm::getBase(void)
{
	return _baseValue;
}

int WidgetRobotArm::getShoulder(void)
{
	return _shoulderValue;
}

int WidgetRobotArm::getElbow(void)
{
	return _elbowValue;
}

int WidgetRobotArm::getWrist(void)
{
	return _wristValue;
}

int WidgetRobotArm::getGripper(void)
{
	return _gripperValue;
}

void WidgetRobotArm::widgetBaseCallBack(uint8_t *payload, uint32_t len)
{
   if(!jsonGetValue(payload,"b",_baseValue)) return;
   if(!jsonGetValue(payload,"s",_shoulderValue)) return;
   if(!jsonGetValue(payload,"e",_elbowValue)) return;
   if(!jsonGetValue(payload,"wr",_wristValue)) return;
   if(!jsonGetValue(payload,"g",_gripperValue)) return;
   _EventCb();
   IntoRobot.publish(pDataStatusTopic,1);
}

