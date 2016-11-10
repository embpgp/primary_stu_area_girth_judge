/*
 *Filename:main.cc
 *
 *Description:小学生图形面积周长计算系统测试文件
 *
 *Author:rutk1t0r
 *
 *Date:2016.11.10
 *
 *GPL
 */

#include "common.h"

//菜单
void print_menu(void)
{

	puts("=============================================");
	puts("欢迎光临本系统,请按照提示码操作,谢谢合作!");
	puts("输入1 创建或重新生成新的试卷");
	puts("输入2 开始答题或者回答本题");
	puts("输入3 根据题号浏览题目的正确的答案");
	puts("输入4 交卷并获得总成绩");
	puts("输入5 查看前一题");
	puts("输入6 查看后一题");
	puts("输入7 退出本系统");
	puts("=============================================");
}

//判断输入,不要while(1)也行(本身这样写已经没作用了),看个人设计,当初的想法是一直要用户输入一个在区间范围内的数据
//现在直接改成超过就默认大小了
int judge_input(void)
{
	int num;
	while(1)
	{
		cin>>num;
		if(num > MAX_ELEM_NUM)
		{
			cout<<"对不起,您输入的题量有点大,所以我们默认就是"<<MAX_ELEM_NUM<<"个了"<<endl;
			num = MAX_ELEM_NUM;
		}
		break;
	}
	return num;
}
int main(int argc, char *argv[])
{
	system("clear"); //如果是Windows的话是cls命令清屏
	puts("===========================================");
	puts("欢迎欢迎,第一次咱们先来输入您想要答题的个数吧,比如 15");
	srand((unsigned)time(NULL));  //随机数种子,只需要一次就可以了

	CQuestion *question = new CQuestion(judge_input());

	int code = -1;
	while(1)
	{

		print_menu();  //菜单每次都提示
		cin>>code;
		switch(code)
		{
			case 1:
				delete question;  //构造之前记得释放以前的对象
				question = new CQuestion(judge_input());
				break;

			case 2:
				if(1 == question->answer_question())
				{
					cout<<"题目做完了,您的成绩是"<<question->get_sum_score()<<endl;
				}
				break;
			case 3:
				cout<<"请输入要查看题目的题号,区间为0~"<<question->get_num_elem()<<":";
				int index;
				cin>>index;
				question->show_answer_by_offset(index);
				break;

			case 4:
				cout<<"交卷了,您的成绩是"<<question->get_sum_score()<<endl;
				break;

			case 5:
				question->pre();
				break;
			case 6:
				question->next();
				break;
			case 7:
				delete question;
				cout<<"====================================="<<endl;
				cout<<"欢迎下次使用本系统,再见!"<<endl;
				exit(0);

			default:
				break;

		}
	}
	return 0;
}
