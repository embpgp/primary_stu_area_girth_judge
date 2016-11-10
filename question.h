/*
 *Filename:main.cc
 *
 *Description:小学生图形面积周长计算系统之问题类头文件
 *
 *Author:rutk1t0r
 *
 *Date:2016.11.10
 *
 *GPL
 */


#ifndef HELP_SETS_PRIMARY_STU_AREA_GIRTH_JUDGE_QUESTION_H
#define HELP_SETS_PRIMARY_STU_AREA_GIRTH_JUDGE_QUESTION_H

#include <new>

#include "polygon.h"
#include "circle.h"
#include "square.h"
#include "rectangle.h"


const int MAX_ELEM_NUM = 20;
class CQuestion
{

public:
	CQuestion(int num = MAX_ELEM_NUM);
	~CQuestion();
	CPolygon *create_polygon(int rand);
	unsigned long get_sum_score();
	int  answer_question(void);
	void show_answer_status(CPolygon *polygon, int offset);
	void show_answer_by_offset(int offset);
	void pre();
	void next();
	int get_num_elem(void){return num_elem;}
	unsigned long get_current(void){return current;}
private:
	int num_elem;
	CPolygon *pPolygon[MAX_ELEM_NUM];
	unsigned long sum_score;
	unsigned long  current;

	enum polygon_type {CRICLE = 0, SQUARE, RECTANGLE, MAX_COUNT};
	struct answer_post
	{
		datatype answer_area;
		datatype answer_girth;
	}answer_post[MAX_ELEM_NUM];  //同步题号的用户输入答案
};



#endif //HELP_SETS_PRIMARY_STU_AREA_GIRTH_JUDGE_QUESTION_H
