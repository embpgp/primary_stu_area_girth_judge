/*
 *Filename:main.cc
 *
 *Description:小学生图形面积周长计算系统正方形类源文件
 *
 *Author:rutk1t0r
 *
 *Date:2016.11.10
 *
 *GPL
 */

#include "square.h"


CSquare::CSquare()
{
	create_side();
}

void CSquare::create_side()
{
	side =  rand() % MAX_NUM;
}

void CSquare::show_side()
{
	cout<<"这个正方形的边长为 "<<side<<endl;
}

void CSquare::paint()
{
	cout<<"此处应该调用正方形的画图接口"<<endl;
}

datatype CSquare::area()
{
	return side * side;
}

datatype CSquare::girth()
{
	return 4 * side;
}
