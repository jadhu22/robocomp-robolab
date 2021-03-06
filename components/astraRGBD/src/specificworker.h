/*
 *    Copyright (C)2018 by YOUR NAME HERE
 *
 *    This file is part of RoboComp
 *
 *    RoboComp is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    RoboComp is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
       \brief
       @author authorname
*/



#ifndef SPECIFICWORKER_H
#define SPECIFICWORKER_H

#include <genericworker.h>
#include <innermodel/innermodel.h>
#include <MultiFrameListener.h>
#include <DoubleBufferConverters.h>


class SpecificWorker : public GenericWorker
{
Q_OBJECT
    int fps;

	astra::StreamSet streamSet;
    astra::StreamReader *reader;
	bool depthB,colorB, bodyB;
	MultiFrameListener *frameListener;

//	void initializeStreams();
//	void readFrame();

public:
	SpecificWorker(MapPrx& mprx);
	~SpecificWorker();
	void terminate();
	bool setParams(RoboCompCommonBehavior::ParameterList params);

	Registration getRegistration();
	void getData(imgType &rgbMatrix, depthType &distanceMatrix, RoboCompJointMotor::MotorStateMap &hState, RoboCompGenericBase::TBaseState &bState);
	void getXYZ(PointSeq &points, RoboCompJointMotor::MotorStateMap &hState, RoboCompGenericBase::TBaseState &bState);
	void getRGB(ColorSeq &color, RoboCompJointMotor::MotorStateMap &hState, RoboCompGenericBase::TBaseState &bState);
	TRGBDParams getRGBDParams();
	void getDepth(DepthSeq &depth, RoboCompJointMotor::MotorStateMap &hState, RoboCompGenericBase::TBaseState &bState);
	void setRegistration(const Registration &value);
	void getImage(ColorSeq &color, DepthSeq &depth, PointSeq &points, RoboCompJointMotor::MotorStateMap &hState, RoboCompGenericBase::TBaseState &bState);
	void getDepthInIR(depthType &distanceMatrix, RoboCompJointMotor::MotorStateMap &hState, RoboCompGenericBase::TBaseState &bState);
//humanTracker Interface
	void getJointsPosition(int id, jointListType &jointList){return;};
	void getRTMatrixList(int id, RTMatrixList &RTMatList){return;};
	void getUser(int id, TPerson &user){return;};
	bool getJointDepthPosition(const int idperson, const string &idjoint, joint &depthjoint){return false;};	
	void getUsersList(PersonList &users);
	void getUserState(int id, TrackingState &state){return;};
	

public slots:
	void compute();

private:
	InnerModel *innerModel;

};

#endif
