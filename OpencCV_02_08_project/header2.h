#include <opencv2/opencv.hpp>
#include <iostream>
#include <conio.h>
#include <random>

#define _CRT_SECURE_NO_WARNINGS
#define UP 0x260000
#define DOWN 0x280000		
#define RIGTH 0x270000
#define LEFT 0x250000
#define quzi_01 "C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\wq.gif"
#define quzi_02 "C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\eve.gif"
#define quzi_03 "C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\pi.gif"
#define quzi_04 "C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\zzz.gif"
#define quzi_05 "C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\red.gif"
#define quzi_06 "C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\han.gif"
#define quzi_07 "C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\liza.gif"
#define quzi_08 "C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\king.gif"
#define quzi_09 "C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\nan.gif"
#define quzi_10 "C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\gira.gif"
#define data 10

using namespace cv;
using namespace std;

int check = 0;
int c_move = 0;
int move_key;
int move_key2;

bool mouse_is_pressing = false;
int start_x, start_y, end_x, end_y;
int step = 0;

int check1 = 0;
int check2 = 0;
int check3 = 0;
int check4 = 0;
int check5 = 0;
void mouse_callback(int event, int x, int y, int flags, void* param);

class image
{
public:
	int height = 0;
	int width = 0;
	int first_point = 450; //시작위치
	int second_point = 550; //시작위치
	int pointx = 0;
	int pointy = 0;
	int quzi_list[data];
	int list_num = 0;
	int stop_key = 1;
	VideoCapture cap;
	Mat main_character = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\back.png", IMREAD_COLOR);
	Mat fin;	
	Mat hind;
	Mat cc;
public:

	void battle_event()
	{
		Vec3b color_1 = hind.at<Vec3b>(Point(first_point, second_point + 20));
		if ((int(color_1.val[0]) == 2) && (int(color_1.val[1]) == 2) && (int(color_1.val[2]) == 2))
		{
			Mat battle_window(Size(700, 500), CV_8UC3, Scalar(255, 255, 255));
			int ab = 0;
			if (!cap.isOpened())
			{
				cout << "동영상 열 수 없습니다." << endl;
				move_key2 = 99;
			}
			namedWindow("battle_window");
			setMouseCallback("battle_window", mouse_callback);

			Mat img_frame, img_frame2;
			VideoCapture cap, cap2;

			for (int i = 0; i < 10; i++)
			{
				random_device rd;
				mt19937 gen(rd());
				uniform_int_distribution<int> dis(1, 10);
				quzi_list[i] = dis(gen);
				for (int j = 0; j < i; j++)
				{
					if (quzi_list[i] == quzi_list[j])
					{
						i--;
						continue;
					}
				}
			}

			for (int i = 0; i < 10; i++)
			{
				cout << quzi_list[i] << endl;
			}

			ad(&cap, quzi_list[list_num]);
			while (1)
			{
				random_q(&cap, quzi_list[list_num], &img_frame);
				bool ret = cap.read(img_frame);
				if (!ret)
				{
					ad(&cap, quzi_list[list_num]);
					continue;
				}
				resize(img_frame, img_frame, Size(200, 200));
				Mat roi(img_frame, Rect(0, 0, img_frame.cols, img_frame.rows));
				roi.copyTo(battle_window(Rect(250, 50, img_frame.cols, img_frame.rows)));
				rectangle(battle_window, Point(0, 300), Point(700, 500), Scalar(0, 0, 0), 2);
				rectangle(battle_window, Point(600, 250), Point(700, 300), Scalar(0, 0, 0), 2);
				line(battle_window, Point(0, 399), Point(700, 399), Scalar(0, 0, 0), 2);
				line(battle_window, Point(349, 300), Point(349, 500), Scalar(0, 0, 0), 2);
				quzi(&battle_window);
				text_make(&battle_window);
				text_make2(&battle_window);
				text_make3(&battle_window);
				imshow("battle_window", battle_window);
				cout << stop_key << endl;
				if (stop_key >= 11)
				{
					move_key2 = 27;
				}
				else
					move_key2 = waitKey(50);

				if (move_key2 == 27)
				{
					stop_key = 1;
					move_key = 0x1B;
					cap.release();
					destroyWindow("battle_window");
					break;
				}
			}
		}
	}
	void text_make3(Mat* text_ing)
	{
		Mat send_img = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\send.png", IMREAD_COLOR);

		resize(send_img, send_img, Size(80, 40));
		Mat roi_send_img(send_img, Rect(0, 0, send_img.cols, send_img.rows));
		roi_send_img.copyTo((*text_ing)(Rect(610, 252, send_img.cols, send_img.rows)));
	}

	void text_make2(Mat* text_ing)
	{
		Mat c_img1;
		Mat c_img2;
		Mat c_img3;
		Mat c_img4;
		if (quzi_list[list_num] == 1)
		{
			c_img1 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\iron.png", IMREAD_COLOR);
			c_img2 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\fair.png", IMREAD_COLOR);
			c_img3 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\ice.png", IMREAD_COLOR);
			c_img4 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\fire.png", IMREAD_COLOR);
		}
		else if (quzi_list[list_num] == 2)
		{
			c_img1 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\ele.png", IMREAD_COLOR);
			c_img2 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\fair.png", IMREAD_COLOR);
			c_img3 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\nomal.png", IMREAD_COLOR);
			c_img4 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\fire.png", IMREAD_COLOR);
		}
		else if (quzi_list[list_num] == 3)
		{
			c_img1 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\ele.png", IMREAD_COLOR);
			c_img2 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\po.png", IMREAD_COLOR);
			c_img3 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\stone.png", IMREAD_COLOR);
			c_img4 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\ice.png", IMREAD_COLOR);
		}
		else if (quzi_list[list_num] == 4)
		{
			c_img1 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\stone.png", IMREAD_COLOR);
			c_img2 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\fire.png", IMREAD_COLOR);
			c_img3 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\fair.png", IMREAD_COLOR);
			c_img4 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\esl.png", IMREAD_COLOR);
		}
		else if (quzi_list[list_num] == 5)
		{
			c_img1 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\sinho.png", IMREAD_COLOR);
			c_img2 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\gandon.png", IMREAD_COLOR);
			c_img3 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\alro.png", IMREAD_COLOR);
			c_img4 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\songdo.png", IMREAD_COLOR);
		}
		else if (quzi_list[list_num] == 6)
		{
			c_img1 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\fair.png", IMREAD_COLOR);
			c_img2 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\ice.png", IMREAD_COLOR);
			c_img3 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\dragon.png", IMREAD_COLOR);
			c_img4 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\gra.png", IMREAD_COLOR);
		}
		else if (quzi_list[list_num] == 7)
		{
			c_img1 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\fire.png", IMREAD_COLOR);
			c_img2 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\ele.png", IMREAD_COLOR);
			c_img3 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\ice.png", IMREAD_COLOR);
			c_img4 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\gra.png", IMREAD_COLOR);
		}
		else if (quzi_list[list_num] == 8)
		{
			c_img1 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\stone.png", IMREAD_COLOR);
			c_img2 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\iron.png", IMREAD_COLOR);
			c_img3 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\ice.png", IMREAD_COLOR);
			c_img4 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\water_mm.png", IMREAD_COLOR);
		}
		else if (quzi_list[list_num] == 9)
		{
			c_img1 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\sinho.png", IMREAD_COLOR);
			c_img2 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\gandon.png", IMREAD_COLOR);
			c_img3 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\kal.png", IMREAD_COLOR);
			c_img4 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\songdo.png", IMREAD_COLOR);
		}
		else if (quzi_list[list_num] >= 10)
		{
			c_img1 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\sim.png", IMREAD_COLOR);
			c_img2 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\space.png", IMREAD_COLOR);
			c_img3 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\time.png", IMREAD_COLOR);
			c_img4 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\dive.png", IMREAD_COLOR);
		}

		resize(c_img1, c_img1, Size(250, 50));
		resize(c_img2, c_img2, Size(250, 50));
		resize(c_img3, c_img3, Size(250, 50));
		resize(c_img4, c_img4, Size(250, 50));
		Mat roi_img1(c_img1, Rect(0, 0, c_img1.cols, c_img1.rows));
		roi_img1.copyTo((*text_ing)(Rect(25, 320, c_img1.cols, c_img1.rows)));

		Mat roi_img2(c_img2, Rect(0, 0, c_img2.cols, c_img2.rows));
		roi_img2.copyTo((*text_ing)(Rect(367, 320, c_img1.cols, c_img1.rows)));

		Mat roi_img3(c_img3, Rect(0, 0, c_img3.cols, c_img3.rows));
		roi_img3.copyTo((*text_ing)(Rect(25, 420, c_img1.cols, c_img1.rows)));

		Mat roi_img4(c_img4, Rect(0, 0, c_img4.cols, c_img4.rows));
		roi_img4.copyTo((*text_ing)(Rect(367, 420, c_img1.cols, c_img1.rows)));


	}

	void text_make(Mat *text_ing)
	{
		Mat num_img;
		if (stop_key == 1)
			num_img = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\number_img_1.png", IMREAD_COLOR);
		else if (stop_key == 2)
			num_img = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\number_img_2.png", IMREAD_COLOR);
		else if (stop_key == 3)
			num_img = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\number_img_3.png", IMREAD_COLOR);
		else if (stop_key == 4)
			num_img = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\number_img_4.png", IMREAD_COLOR);
		else if (stop_key == 5)
			num_img = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\number_img_5.png", IMREAD_COLOR);
		else if (stop_key == 6)
			num_img = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\number_img_6.png", IMREAD_COLOR);
		else if (stop_key == 7)
			num_img = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\number_img_7.png", IMREAD_COLOR);
		else if (stop_key == 8)
			num_img = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\number_img_8.png", IMREAD_COLOR);
		else if (stop_key == 9)
			num_img = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\number_img_9.png", IMREAD_COLOR);
		else if (stop_key >= 10)
			num_img = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\number_img_10.png", IMREAD_COLOR);
		resize(num_img, num_img, Size(40, 40));
		Mat roi_img(num_img, Rect(0, 0, num_img.cols, num_img.rows));
		roi_img.copyTo((*text_ing)(Rect(0, 0, num_img.cols, num_img.rows)));

		Mat num_img2;
		if (quzi_list[list_num] == 1)
			num_img2 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\quzi_01.png", IMREAD_COLOR);
		else if (quzi_list[list_num] == 2)
			num_img2 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\quzi_02.png", IMREAD_COLOR);
		else if (quzi_list[list_num] == 3)
			num_img2 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\quzi_03.png", IMREAD_COLOR);
		else if (quzi_list[list_num] == 4)
			num_img2 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\quzi_04.png", IMREAD_COLOR);
		else if (quzi_list[list_num] == 5)
			num_img2 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\quzi_05.png", IMREAD_COLOR);
		else if (quzi_list[list_num] == 6)
			num_img2 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\quzi_06.png", IMREAD_COLOR);
		else if (quzi_list[list_num] == 7)
			num_img2 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\quzi_07.png", IMREAD_COLOR);
		else if (quzi_list[list_num] == 8)
			num_img2 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\quzi_08.png", IMREAD_COLOR);
		else if (quzi_list[list_num] == 9)
			num_img2 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\quzi_09.png", IMREAD_COLOR);
		else if (quzi_list[list_num] >= 10)
			num_img2 = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\quzi_10.png", IMREAD_COLOR);

		resize(num_img2, num_img2, Size(600, 40));
		Mat roi_img2(num_img2, Rect(0, 0, num_img2.cols, num_img2.rows));
		roi_img2.copyTo((*text_ing)(Rect(40, 0, num_img2.cols, num_img2.rows)));
	}

	void ad(VideoCapture* cc, int num)
	{
		if (num == 1)
			(*cc).open(quzi_01);
		else if (num == 2)
			(*cc).open(quzi_02);
		else if (num == 3)
			(*cc).open(quzi_03);
		else if (num == 4)
			(*cc).open(quzi_04);
		else if (num == 5)
			(*cc).open(quzi_05);
		else if (num == 6)
			(*cc).open(quzi_06);
		else if (num == 7)
			(*cc).open(quzi_07);
		else if (num == 8)
			(*cc).open(quzi_08);
		else if (num == 9)
			(*cc).open(quzi_09);
		else if (num == 10)
			(*cc).open(quzi_10);
	}
	void random_q(VideoCapture *cc, int num, Mat* a)
	{
		if (check5 == 1)
		{
			if (stop_key >= 11)
			{
				list_num;
			}
			else if (num == 1 && (check1 == 1 && check2 == 1 && check3 == 0 && check4 == 0))
			{
				list_num++;
				stop_key++;
			}
			else if (num == 2 && (check1 == 0 && check2 == 0 && check3 == 1 && check4 == 0))
			{
				list_num++;
				stop_key++;
			}
			else if (num == 3 && (check1 == 1 && check2 == 0 && check3 == 0 && check4 == 0))
			{
				list_num++;
				stop_key++; 
			}
			else if (num == 4 && (check1 == 0 && check2 == 0 && check3 == 0 && check4 == 1))
			{
				list_num++; 
				stop_key++;
			}
			else if (num == 5 && (check1 == 0 && check2 == 1 && check3 == 0 && check4 == 0))
			{
				list_num++;
				stop_key++;
			}
			else if (num == 6 && (check1 == 0 && check2 == 0 && check3 == 1 && check4 == 1))
			{
				list_num++;
				stop_key++;
			}
			else if (num == 7 && (check1 == 0 && check2 == 1 && check3 == 0 && check4 == 0))
			{
				list_num++;
				stop_key++;
			}
			else if (num == 8 && (check1 == 0 && check2 == 0 && check3 == 0 && check4 == 1))
			{
				list_num++;
				stop_key++;
			}
			else if (num == 9 && (check1 == 1 && check2 == 0 && check3 == 0 && check4 == 0))
			{
				list_num++;
				stop_key++;
			}
			else if (num == 10 && (check1 == 0 && check2 == 0 && check3 == 0 && check4 == 1))
			{
				list_num++;
				stop_key++;
			}

			ad(cc, quzi_list[list_num]);

			(*cc).read(*a);
			check1 = 0;
			check2 = 0;
			check3 = 0;
			check4 = 0;
		}
		check5 = 0;
	}

	void quzi(Mat* battle)
	{
		if (check1 == 1)
			rectangle(*battle, Point(2, 302), Point(347, 398), Scalar(0, 255, 0), 5);
		else if (check1 == 0)
			rectangle(*battle, Point(2, 302), Point(347, 398), Scalar(255, 255, 255), -1);
		if (check2 == 1)
			rectangle(*battle, Point(351, 302), Point(698, 398), Scalar(0, 255, 0), 5);
		else if (check2 == 0)
			rectangle(*battle, Point(351, 302), Point(698, 398), Scalar(255, 255, 255), -1);
		if (check3 == 1)
			rectangle(*battle, Point(2, 401), Point(347, 498), Scalar(0, 255, 0), 5);
		else if (check3 == 0)
			rectangle(*battle, Point(2, 401), Point(347, 498), Scalar(255, 255, 255), -1);
		if (check4 == 1)
			rectangle(*battle, Point(351, 401), Point(698, 498), Scalar(0, 255, 0), 5);
		else if (check4 == 0)
			rectangle(*battle, Point(351, 401), Point(698, 498), Scalar(255, 255, 255), -1);
		if (check5 == 1)
			rectangle(*battle, Point(602, 252), Point(698, 298), Scalar(0, 0, 255), 5);
		else if (check5 == 0)
			rectangle(*battle, Point(602, 252), Point(698, 298), Scalar(255, 255, 255), -1);
	}

	void map_make(Mat* map, Mat* map2)
	{
		for (int i = 0; i < 20; i++) //오브젝트 위치 잡기용
		{
			for (int j = 0; j < 20; j++)
			{
				if(i == 0 && (j != 1 && j != 2))
					rectangle((*map), Rect(pointx, pointy, 50, 50), Scalar(0, 0, 0), -1);
				if((i >= 1 || i <= 14) && (j == 1 || j == 2))//길
					rectangle((*map), Rect(pointx, pointy, 50, 50), Scalar(255, 0, 0), -1);
				if((i == 3 || i == 4 || i == 11 || i == 12) && (j >= 3 && j <= 16))//길
					rectangle((*map), Rect(pointx, pointy, 50, 50), Scalar(255, 0, 0), -1); 
				if((i >= 5 && i <= 10) && (j == 15 || j == 16))//길
					rectangle((*map), Rect(pointx, pointy, 50, 50), Scalar(255, 0, 0), -1); 
				if((i >= 1 && i <= 19) && (j == 0 || j == 19))
					rectangle((*map), Rect(pointx, pointy, 50, 50), Scalar(0, 0, 0), -1);
				if (i >= 15 && (j >= 1 && j <= 18))
					rectangle((*map), Rect(pointx, pointy, 50, 50), Scalar(1, 1, 1), -1);
				if((i == 1 || i == 2) && (j > 2 && j <= 7))
					rectangle((*map), Rect(pointx, pointy, 50, 50), Scalar(0, 255, 0), -1);

				wall_make(map, map2, i, j, pointx, pointy);
				water_make(map, map2, i, j, pointx, pointy);
				road_make(map, map2, i, j, pointx, pointy);
				greed_make(map, map2, i, j, pointx, pointy);
				pointx += 50;
			}
			pointy += 50;
			pointx = 0;
		}
		rectangle((*map), Rect(200, 70, 70, 70), Scalar(2, 2, 2), -1);
		add_char(map, map2);
	}

	void add_char(Mat* map, Mat* map2)
	{
		int ppox = 0;
		int ppoy = 0;
		int stop = 0;
		Mat img_ka = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\ca.png", IMREAD_COLOR);
		resize(img_ka, img_ka, Size(70, 70));
		Mat img_ka_gray;
		cvtColor(img_ka, img_ka_gray, COLOR_BGR2GRAY);
		Mat img_ka_mask;
		threshold(img_ka_gray, img_ka_mask, 254, 255, THRESH_BINARY);
		Mat img_ka_mask_inv = ~img_ka_mask;

		int hh = map->rows;
		int ww = map->cols;

		for (int i = 0; i < hh; i++)
		{
			for (int j = 0; j < ww; j++)
			{
				Vec3b color_1 = (*map).at<Vec3b>(Point(j, i));

				if ((int(color_1.val[0]) == 2) && (int(color_1.val[1]) == 2) && (int(color_1.val[2]) == 2))
				{
					ppox = j;
					ppoy = i;
					stop++;
					break;
				}
			}
			if (stop == 1)
				break;
		}
		Mat img_roi(*map2, Rect(ppox, ppoy, 70, 70));
		Mat img1, img2;
		bitwise_and(img_ka, img_ka, img1, img_ka_mask_inv);
		bitwise_and(img_roi, img_roi, img2, img_ka_mask);
		Mat dst;
		add(img1, img2, dst);
		dst.copyTo((*map2)(Rect(ppox, ppoy, 70, 70)));
	}

	void greed_make(Mat* map, Mat* map2, int i, int j, int pointx, int pointy)
	{
		Mat greed;
		Vec3b color_1 = (*map).at<Vec3b>(Point(pointx, pointy));

		if ((int(color_1.val[0]) == 255) && (int(color_1.val[1]) == 255) && (int(color_1.val[2]) == 255))
		{
			greed = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\greed.png", IMREAD_COLOR);
			resize(greed, greed, Size(50, 50));
			rectangle((*map2), Rect(pointx, pointy, 50, 50), Scalar(0, 0, 0), -1);
			greed.copyTo((*map2)(Rect(pointx, pointy, 50, 50)));
		}
		else if ((int(color_1.val[0]) == 0) && (int(color_1.val[1]) == 255) && (int(color_1.val[2]) == 0))
		{
			greed = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\greed2.png", IMREAD_COLOR);
			resize(greed, greed, Size(50, 50));
			rectangle((*map2), Rect(pointx, pointy, 50, 50), Scalar(0, 0, 0), -1);
			greed.copyTo((*map2)(Rect(pointx, pointy, 50, 50)));
		}
	}

	void road_make(Mat* map, Mat* map2, int i, int j, int pointx, int pointy)
	{
		Mat road;
		Vec3b color_1 = (*map).at<Vec3b>(Point(pointx, pointy));
		if (((i >= 1 || i <= 14) && (j == 1 || j == 2)) || ((i >= 5 && i <= 10) && (j == 15 || j == 16)))
		{
			if (j == 1 || j == 15)
			{
				road = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_road.png", IMREAD_COLOR);
			}
			else if(j == 2 && (i == 3 || i == 11))
				road = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_road2_1.png", IMREAD_COLOR);
			else if(j == 2 && (i == 4 || i == 12))
				road = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_road2_2.png", IMREAD_COLOR);
			else
				road = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_road2.png", IMREAD_COLOR);
		}
		else if ((i == 3) && (j >= 3 && j <= 15))
			road = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_road3.png", IMREAD_COLOR);
		else if ((i == 3) && (j == 16))
			road = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_road5.png", IMREAD_COLOR);
		else if ((i == 4) && (j >= 3 && j <= 16))
		{
			if(j == 15)
				road = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_road2_3.png", IMREAD_COLOR);
			else if(j == 16)
				road = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_road2.png", IMREAD_COLOR);
			else
				road = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_road3_2.png", IMREAD_COLOR);
		}
		else if ((i == 11) && (j >= 3 && j <= 16))
		{
			if (j == 15)
				road = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_road4.png", IMREAD_COLOR);
			else if (j == 16)
				road = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_road2.png", IMREAD_COLOR);
			else
				road = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_road3.png", IMREAD_COLOR);
		}
		else if ((i == 12) && (j >= 3 && j <= 16))
		{
			if(j == 16)
				road = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_road5_2.png", IMREAD_COLOR);
			else
				road = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_road3_2.png", IMREAD_COLOR);
		}
		else
		{
			road = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_road.png", IMREAD_COLOR);
		}
		resize(road, road, Size(50, 50));
		if ((int(color_1.val[0]) == 255) && (int(color_1.val[1]) == 0) && (int(color_1.val[2]) == 0))
		{
			rectangle((*map2), Rect(pointx, pointy, 50, 50), Scalar(0, 0, 0), -1);
			road.copyTo((*map2)(Rect(pointx, pointy, 50, 50)));
		}
	}
	void water_make(Mat* map, Mat* map2, int i, int j, int pointx, int pointy)
	{
		Mat water;
		Vec3b color_1 = (*map).at<Vec3b>(Point(pointx, pointy));

		if ((i == 15) && (j == 1 || j == 18))
		{
			water = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_water2.png", IMREAD_COLOR);
			if (j == 18)
				water = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_water3.png", IMREAD_COLOR);
		}
		else if((i == 15)&& (j >= 2 && j <= 17))
			water = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_water.png", IMREAD_COLOR);
		else if (i >= 16 && (j == 1 || j == 18))
		{
			if(j == 1)
				water = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_water5.png", IMREAD_COLOR);
			else
				water = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_water6.png", IMREAD_COLOR);
		}
		else
			water = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_water4.png", IMREAD_COLOR);
		resize(water, water, Size(50, 50));
		if ((int(color_1.val[0]) == 1) && (int(color_1.val[1]) == 1) && (int(color_1.val[2]) == 1))
		{
			rectangle((*map2), Rect(pointx, pointy, 50, 50), Scalar(0, 0, 0), -1);
			water.copyTo((*map2)(Rect(pointx, pointy, 50, 50)));
		}
	}
	void wall_make(Mat* map, Mat* map2, int i, int j, int pointx, int pointy)
	{
		Mat wall;
		Vec3b color_1 = (*map).at<Vec3b>(Point(pointx, pointy));
		if (i == 0 && j == 19)
			wall = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_wall2.png", IMREAD_COLOR);
		else if ((i >= 1 && i <= 19) && (j == 19))
			wall = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_wall3.png", IMREAD_COLOR);
		else if ((i >= 0 && i <= 19) && (j == 0))
		{
			wall = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_wall3.png", IMREAD_COLOR);
			img_rotate(&wall, 180);
		}
		else
			wall = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\mini_wall.png", IMREAD_COLOR);
		resize(wall, wall, Size(50, 50));
		if ((int(color_1.val[0]) == 0) && (int(color_1.val[1]) == 0) && (int(color_1.val[2]) == 0))
		{
			rectangle((*map2), Rect(pointx, pointy, 50, 50), Scalar(0, 0, 0), -1);
			wall.copyTo((*map2)(Rect(pointx, pointy, 50, 50)));
		}
	}

	void img_rotate(Mat* object, int value)
	{
		Mat M = getRotationMatrix2D(Point(object->cols / 2, object->rows / 2), value, 1);
		warpAffine(*object, *object, M, Size(object->cols, object->rows));
	}

	void img_change(Mat* map, Mat* cha)
	{
		resize(*cha, *cha, Size(70, 70));
		namedWindow("main_character");
		imshow("main_character", *cha);
		resize(*map, *map, Size(1000, 1000));
	}

	Mat img_add(Mat** map, Mat* result)
	{
		Mat ii2 = (**map).clone();
		(*result).copyTo(ii2(Rect(first_point, second_point, width, height)));

		return ii2;
	}

	void move_check(Mat** map, int check)
	{
		if (check == 0)
		{
			Vec3b color_1 = (**map).at<Vec3b>(Point(first_point + 35, second_point + 30));
			if ((int(color_1.val[0]) <= 10) && (int(color_1.val[1]) <= 10) && (int(color_1.val[2]) <= 10))
			{
				second_point += 10;
			}
		}
		else if(check == 1)
		{
			Vec3b color_1 = (**map).at<Vec3b>(Point(first_point + 35, second_point + 60));
			if ((int(color_1.val[0]) <= 10) && (int(color_1.val[1]) <= 10) && (int(color_1.val[2]) <= 10))
			{
				second_point -= 10;
			}
		}
		else if (check == 2)
		{
			Vec3b color_1 = (**map).at<Vec3b>(Point(first_point + 50, second_point + 35));
			if ((int(color_1.val[0]) <= 10) && (int(color_1.val[1]) <= 10) && (int(color_1.val[2]) <= 10))
			{
				first_point -= 10;
			}
		}
		else if (check == 3)
		{
			Vec3b color_1 = (**map).at<Vec3b>(Point(first_point + 10, second_point + 35));
			if ((int(color_1.val[0]) <= 10) && (int(color_1.val[1]) <= 10) && (int(color_1.val[2]) <= 10))
			{
				first_point += 10;
			}
		}
	}

	Mat img_extraction(Mat* map, Mat* cha, int check)
	{
		move_check(&map, check);
		Mat img_hsv;
		cvtColor(*cha, img_hsv, COLOR_BGR2HSV);
		Mat img_mask;
		Vec3b lower_g = Vec3b(60 - 15, 0, 0);
		Vec3b lower_h = Vec3b(60 + 15, 255, 255);
		inRange(img_hsv, lower_g, lower_h, img_mask);

		height = cha->rows;
		width = cha->rows;

		Mat roi_img(*map, Rect(first_point, second_point, width, height));
		Mat img1;
		bitwise_and(roi_img, roi_img, img1, img_mask);

		img_mask = ~img_mask;
		Mat img2;
		bitwise_and(*cha, *cha, img2, img_mask);

		Mat result;
		add(img1, img2, result);

		Mat end;
		end = img_add(&map, &result);

		return end;
	}
};

void mouse_callback(int event, int x, int y, int flags, void* param)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		mouse_is_pressing = true;
		start_x = x;
		start_y = y;
		step = 1;
	}

	else if (event == EVENT_MOUSEMOVE)
	{
		if (mouse_is_pressing)
		{
			end_x = x;
			end_y = y;
		}
	}
	else if (event == EVENT_LBUTTONUP)
	{
		mouse_is_pressing = false;

		if ((x >= 2 && x <= 349) && (y >= 302 && y <= 398))
		{
			if (check1 == 0)
				check1 = 1;
			else
				check1 = 0;
		}
		else if ((x >= 351 && x <= 698) && (y >= 302 && y <= 398))
		{
			if (check2 == 0)
				check2 = 1;
			else
				check2 = 0;
		}
		else if ((x >= 2 && x <= 349) && (y >= 402 && y <= 498))
		{
			if (check3 == 0)
				check3 = 1;
			else
				check3 = 0;
		}
		else if ((x >= 351 && x <= 698) && (y >= 402 && y <= 498))
		{
			if (check4 == 0)
				check4 = 1;
			else
				check4 = 0;
		}
		else if ((x >= 600 && x <= 700) && (y >= 250 && y <= 300))
		{
			check5 = 1;
		}
		end_x = x;
		end_y = y;
	}
}
