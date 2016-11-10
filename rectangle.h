/*
 *Filename:main.cc
 *
 *Description:小学生图形面积周长计算系统矩形类源文件
 *
 *Author:rutk1t0r
 *
 *Date:2016.11.10
 *
 *GPL
 */

#ifndef HELP_SETS_PRIMARY_STU_AREA_GIRTH_JUDGE_RECTANGLE_H
#define HELP_SETS_PRIMARY_STU_AREA_GIRTH_JUDGE_RECTANGLE_H

#include "polygon.h"

class CRectangle: public CPolygon
{

public:
	CRectangle();
	virtual ~CRectangle(){};
	virtual void create_side();
	virtual void show_side();
	virtual void paint();
	virtual datatype area();
	virtual datatype girth();

private:
	datatype length;
	datatype width;
};


#endif //HELP_SETS_PRIMARY_STU_AREA_GIRTH_JUDGE_RECTANGLE_H
