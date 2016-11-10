/*
 *Filename:main.cc
 *
 *Description:小学生图形面积周长计算系统之类圆的头文件
 *
 *Author:rutk1t0r
 *
 *Date:2016.11.10
 *
 *GPL
 */


#ifndef HELP_SETS_PRIMARY_STU_AREA_GIRTH_JUDGE_CRICLE_H
#define HELP_SETS_PRIMARY_STU_AREA_GIRTH_JUDGE_CRICLE_H

#include "polygon.h"


class CCircle:public CPolygon
{
public:
	CCircle();
	virtual ~CCircle(){};
	virtual void create_side();
	virtual void show_side() ;
	virtual void paint();
	virtual datatype area() ;
	virtual datatype girth() ;

private:
	datatype radius;
};



#endif //HELP_SETS_PRIMARY_STU_AREA_GIRTH_JUDGE_CRICLE_H
