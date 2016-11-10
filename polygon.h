/*
 *Filename:main.cc
 *
 *Description:小学生图形面积周长计算系统之图形抽象类头文件
 *
 *Author:rutk1t0r
 *
 *Date:2016.11.10
 *
 *GPL
 */


#ifndef HELP_SETS_PRIMARY_STU_AREA_GIRTH_JUDGE_POLYGON_H
#define HELP_SETS_PRIMARY_STU_AREA_GIRTH_JUDGE_POLYGON_H


#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstdio>

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef int datatype;
const int MAX_NUM = 100;
const int PI = 3;
class CPolygon
{
public:
	virtual ~CPolygon(){};
	virtual void create_side() = 0;
	virtual void show_side() = 0 ;
	virtual void paint() = 0;
	virtual datatype area() = 0;
	virtual datatype girth() = 0 ;
};



#endif //HELP_SETS_PRIMARY_STU_AREA_GIRTH_JUDGE_POLYGON_H
