/*
 *Filename:circle.cc
 *
 *Description:小学生图形面积周长计算系统之类圆的源文件
 *
 *Author:rutk1t0r
 *
 *Date:2016.11.10
 *
 *GPL
 */

#include "circle.h"

CCircle::CCircle()
{
	create_side();
}

void CCircle::create_side()
{
	radius =  rand() % MAX_NUM;
}

void CCircle::show_side()
{
	cout<<"圆的半径为 "<<radius<<"(注意PI取值为"<<PI<<")"<<endl;
}

void CCircle::paint()
{
	cout<<"此处应该调用圆的画图接口"<<endl;
}

datatype CCircle::area()
{
	return PI * radius * radius;
}

datatype CCircle::girth()
{
	return 2 * PI * radius;
}
