#include "header2.h"

int main(int argc, char** argv)
{
	image mm;
	Mat main_map(Size(1000, 1000), CV_8UC3, Scalar(255,255,255));
	Mat mainX = main_map.clone();
	mm.map_make(&main_map, &mainX);

	while (1)
	{
		move_key = waitKeyEx();

		if (move_key == UP)
		{
			mm.main_character = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\front.png", IMREAD_COLOR);
			if (mm.second_point >= 10)
			{
				mm.second_point -= 10;
				check = 0;
			}
		}
		else if (move_key == DOWN)
		{
			mm.main_character = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\back.png", IMREAD_COLOR);
			if (mm.second_point <= 920)
			{
				mm.second_point += 10;
				check = 1;
			}
		}
		else if (move_key == RIGTH)
		{
			mm.main_character = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\rigth.png", IMREAD_COLOR);
			if (mm.first_point <= 920)
			{
				mm.first_point += 10;
				check = 2;
			}
		}
		else if (move_key == LEFT)
		{
			mm.main_character = imread("C:\\c-LJJ\\c-LJJ\\OpenCV\\OPenCV_data\\PP\\left.png", IMREAD_COLOR);
			if (mm.first_point >= 10)
			{
				mm.first_point -= 10;
				check = 3;
			}
		}
		else if (move_key == 0x1B)
			break;
		mm.img_change(&main_map, &mm.main_character);
		mm.hind = mm.img_extraction(&main_map, &mm.main_character, check);
		mm.img_change(&mainX, &mm.main_character);
		mm.fin = mm.img_extraction(&mainX, &mm.main_character, check);

		if (move_key == 97)
			mm.battle_event();

		imshow("hind", mm.hind);
		imshow("fin", mm.fin);
	}
	destroyAllWindows();
}