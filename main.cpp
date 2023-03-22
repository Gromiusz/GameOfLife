#include <stdlib.h>
#include <stdio.h>
#include "winbgi2.h"
#include <windows.h>

int point[10], tab[102][102], ntab[100][100], l = 0;

void draw()
{
	settextstyle(1, 0, 4);

	setcolor(15);
	outtextxy(860, 100, "START");
	outtextxy(860, 160, "RESET");
	outtextxy(860, 260, "SPEED X1");
	outtextxy(860, 320, "SPEED X2");
	outtextxy(860, 380, "SPEED X4");
	outtextxy(860, 440, "SPEED X8");

	settextstyle(1, 0, 2);
	outtextxy(860, 520, "1. Kliknij na plasze w celu \"ozywienia\"");
	outtextxy(900, 550, "komorek.");
	outtextxy(860, 580, "2. Zmiana predkosci odtwarzania");
	outtextxy(900, 610, "badz zresetowanie planszy wymaga");
	outtextxy(900, 640, "uprzedniego zatrzymania symulacji.");

	settextstyle(1, 0, 4);

	
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			setcolor(4);
			tab[i + 1][j + 1] = 0;
			ntab[i][j] = 0;
			point[0] = 8 * j;
			point[1] = 8 * i;
			point[2] = point[0] + 8;
			point[3] = 8 * i;
			point[4] = point[2];
			point[5] = point[3] + 8;
			point[6] = point[0];
			point[7] = point[3] + 8;
			point[8] = point[0];
			point[9] = point[1];
			fillpoly(5, point);

			setcolor(0);
			drawpoly(5, point);
		}
	}
}


void main()
{
	graphics(1450, 820);

	int speed = 1;
	int mouseX;
	int mouseY;
	int squareX;
	int squareY;

	draw();
	setcolor(15);
	outtextxy(860, 100, "START");

	for (int i = 0;i < 102;i++)
	{
		tab[0][i] = 0;
		tab[101][i] = 0;
		tab[i][0] = 0;
		tab[i][101] = 0;
	}

	bool k[100][100];
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			k[i][j] = false;
		}
	}

	setcolor(2);

	while (true)
	{
		if (mouseup())
		{
		
		}
		else if (mousedown())
		{
			mouseX = mouseclickx();
			mouseY = mouseclicky();
			if (mouseX < 800 && mouseY < 800)
			{
				squareX = mouseX / 8;
				squareY = mouseY / 8;
				if (k[squareX][squareY] == false)
				{
					tab[squareX+1][squareY+1] = 1;
					setcolor(2);
					k[squareX][squareY] = true;
				}
				else if (k[squareX][squareY] == true)
				{
					tab[squareX + 1][squareY + 1] = 0;
					setcolor(4);
					k[squareX][squareY] = false;
				}
				point[0] = 8 * squareX;
				point[1] = 8 * squareY;
				point[2] = point[0] + 8;
				point[3] = 8 * squareY;
				point[4] = point[2];
				point[5] = point[3] + 8;
				point[6] = point[0];
				point[7] = point[3] + 8;
				point[8] = point[0];
				point[9] = point[1];
				fillpoly(5, point);

				setcolor(0);

				for (int i = 0; i < 100; i++)
				{
					for (int j = 0; j < 100; j++)
					{
						point[0] = 8 * j;
						point[1] = 8 * i;
						point[2] = point[0] + 8;
						point[3] = 8 * i;
						point[4] = point[2];
						point[5] = point[3] + 8;
						point[6] = point[0];
						point[7] = point[3] + 8;
						point[8] = point[0];
						point[9] = point[1];
						drawpoly(5, point);
					}
				}
			}
			else if (mouseX > 860 && mouseX < 1050 && mouseY>100 && mouseY < 130)
			{
				setcolor(15);

				setcolor(0);
				point[0] = 860;
				point[1] = 100;
				point[2] = point[0] + 200;
				point[3] = point[1];
				point[4] = point[2];
				point[5] = point[3] + 40;
				point[6] = point[0];
				point[7] = point[3] + 40;
				point[8] = point[0];
				point[9] = point[1];
				fillpoly(5, point);
				setcolor(15);
				outtextxy(860, 100, "STOP");
				
				while (!(mousedown() && (mouseclickx() > 860 && mouseclickx() < 1000 && mouseclicky() >100 && mouseclicky() < 130)))
				{
					if (mousedown() && (mouseclickx() > 860 && mouseclickx() < 1050 && mouseclicky() > 260 && mouseclicky() < 290))
					{
						speed = 1;
					}
					if (mousedown() && (mouseclickx() > 860 && mouseclickx() < 1050 && mouseclicky() > 320 && mouseclicky() < 350))
					{
						speed = 2;
					}
					if (mousedown() && (mouseclickx() > 860 && mouseclickx() < 1050 && mouseclicky() > 380 && mouseclicky() < 410))
					{
						speed = 4;
					}
					if (mousedown() && (mouseclickx() > 860 && mouseclickx() < 1050 && mouseclicky() > 440 && mouseclicky() < 470))
					{
						speed = 8;
					}

					Sleep(400/speed);
					for (int i = 1;i < 101;i++)
					{
						for (int j = 1;j < 101;j++)
						{
							l = 0;
							if (tab[i - 1][j - 1] == 1)
							{
								l++;
							}
							if (tab[i - 1][j] == 1)
							{
								l++;
							}
							if (tab[i - 1][j + 1] == 1)
							{
								l++;
							}
							if (tab[i][j - 1] == 1)
							{
								l++;
							}
							if (tab[i][j + 1] == 1)
							{
								l++;
							}
							if (tab[i + 1][j - 1] == 1)
							{
								l++;
							}
							if (tab[i + 1][j] == 1)
							{
								l++;
							}
							if (tab[i + 1][j + 1] == 1)
							{
								l++;
							}
							if ((tab[i][j] == 0 && l == 3) || (tab[i][j] == 1 && (l == 2 || l == 3)))
							{
								ntab[i - 1][j - 1] = 1;
							}
							else
							{
								ntab[i - 1][j - 1] = 0;
							}
						}
					}
					for (int i = 1;i < 101;i++)
					{
						for (int j = 1;j < 101;j++)
						{
							if (tab[i][j] != ntab[i - 1][j - 1])
							{
								if (ntab[i - 1][j - 1] == 0)
								{
									setcolor(4);
								}
								else if (ntab[i - 1][j - 1] == 1)
								{
									setcolor(2);
								}
								point[0] = 8 * (i - 1);
								point[1] = 8 * (j - 1);
								point[2] = point[0] + 8;
								point[3] = 8 * (j - 1);
								point[4] = point[2];
								point[5] = point[3] + 8;
								point[6] = point[0];
								point[7] = point[3] + 8;
								point[8] = point[0];
								point[9] = point[1];
								fillpoly(5, point);
								setcolor(0);
								drawpoly(5, point);
							}

							tab[i][j] = ntab[i - 1][j - 1];


						}
					}

				}
				setcolor(0);
				point[0] = 860;
				point[1] = 100;
				point[2] = point[0] + 200;
				point[3] = point[1];
				point[4] = point[2];
				point[5] = point[3] + 40;
				point[6] = point[0];
				point[7] = point[3] + 40;
				point[8] = point[0];
				point[9] = point[1];
				fillpoly(5, point);
				setcolor(15);
				outtextxy(860, 100, "START");
				

			}
			else if (mouseclickx() > 860 && mouseclickx() < 1050 && mouseclicky() > 260 && mouseclicky() < 290)
			{
			speed = 1;
			}
			else if (mouseclickx() > 860 && mouseclickx() < 1050 && mouseclicky() > 320 && mouseclicky() < 350)
			{
			speed = 2;
			}
			else if (mouseclickx() > 860 && mouseclickx() < 1050 && mouseclicky() > 380 && mouseclicky() < 410)
			{
			speed = 4;
			}
			else if (mouseclickx() > 860 && mouseclickx() < 1050 && mouseclicky() > 440 && mouseclicky() < 470)
			{
			speed = 8;
			}

			else if (mouseclickx() > 860 && mouseclickx() < 1050 && mouseclicky() > 160 && mouseclicky() < 190)
			{
			clear();
			draw();
			}
			


		}
		
	}
}
