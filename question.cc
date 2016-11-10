/*
 *Filename:main.cc
 *
 *Description:小学生图形面积周长计算系统问题类源文件
 *
 *Author:rutk1t0r
 *
 *Date:2016.11.10
 *
 *GPL
 */


#include "question.h"


//构造函数中直接初始化所有的数据成员
CQuestion::CQuestion(int num):num_elem(num)
{

	int rand_num;
	for(int i = 0; i < num_elem; ++i)
	{
		rand_num =  rand() % (MAX_COUNT+1);
		pPolygon[i] = create_polygon(rand_num);
		answer_post[i].answer_area = 0;
		answer_post[i].answer_girth = 0;
	}


	current = 0;
	sum_score = 0;

}

//逐此析构所有的对象
CQuestion::~CQuestion()
{
	for(int i = 0; i < num_elem; ++i)
	{
		delete pPolygon[i];
	}
}

//根据需要可以继续增加,比如三角形和梯形啥的,注意同步头文件中的枚举变量
CPolygon *CQuestion::create_polygon(int rand_num)
{
	switch(rand_num)
	{
		case CRICLE:      //圆
			return new CCircle();
		break;

		case SQUARE:   //正方形
			return new CSquare();
		break;

		case RECTANGLE: //矩形
			return new CRectangle();
		break;

		default:
			return NULL;
		break;
	}
}

void CQuestion::show_answer_status(CPolygon *polygon, int offset)
{
	if(polygon == NULL || offset >= num_elem || offset < 0)
	{
		return ;
	}
	polygon->paint();
	polygon->show_side();
	cout<<"您回答此题的答案的面积为 "<<answer_post[offset].answer_area<<\
	",周长为 "<<answer_post[offset].answer_girth<<endl\
	<<"注意~如果都为0,可能您还未输入答案"<<endl;

}


int CQuestion::answer_question(void)
{
	if(current+1 == num_elem)
	{
		return 1;    //题目做完了应该
	}
	show_answer_status(pPolygon[current], current);
	cout<<"请输入您的答案,格式为:面积 周长,例如 34 67 "<<endl;
	datatype area_tmp;
	datatype girth_tmp;
	cin>>area_tmp>>girth_tmp;
	answer_post[current].answer_area = area_tmp;
	answer_post[current].answer_girth = girth_tmp;
	current = ++current % num_elem; //保证区间0~num_elem-1
	return 0;
}

void CQuestion::show_answer_by_offset(int offset)
{
	if(offset >= num_elem)
	{
		return ;
	}
	pPolygon[offset]->paint();
	pPolygon[offset]->show_side();
	cout<<"此图形正确答案面积为 "<<pPolygon[offset]->area()\
		<<",周长为 "<<pPolygon[offset]->girth()<<endl;
}

void CQuestion::pre()
{
	current = --current % num_elem;
	show_answer_status(pPolygon[current], current);

}
void CQuestion::next()
{
	//取余的思想在于循环队列
	current = ++current % num_elem;
	show_answer_status(pPolygon[current], current);
}

//这里的获取成绩可以更加灵活地发挥
unsigned long CQuestion::get_sum_score()
{
	for(int i = 0; i < current; ++i)
	{
		if(pPolygon[i]->area() == answer_post[i].answer_area && \
		   pPolygon[i]->girth() == answer_post[i].answer_girth)
		{
			++sum_score;
		}
	}

	return sum_score;
}
