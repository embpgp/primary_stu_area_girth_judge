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

#include "rectangle.h"

CRectangle::CRectangle()
{
	create_side();
}

void CRectangle::create_side()
{

	length =  rand() % MAX_NUM;
	width  =  rand() % MAX_NUM;
}

void CRectangle::show_side()
{
	cout<<"这个长方形的一边长为 "<<length<<",另一边长为 "<<width<<endl;
}

void CRectangle::paint()
{
	cout<<"此处应该调用长方形的画图接口"<<endl;
}

datatype CRectangle::area()
{
	return length * width;
}

datatype CRectangle::girth()
{
	return 2 * (length + width);
}
