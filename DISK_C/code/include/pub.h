#ifndef _pub.h_
#define _pub.h_

void draw_button(int x,int y,int x1,int y1,int color);
void push_button(int x,int y,int x1,int y1);
void re_button(int x,int y,int x1,int y1);
void refram(int x,int y,int length,int wide);
void in_visible1(int x,int y,int max,int min,int length, int wide,char *con);
void in_hidden(int x,int y,int max, int min,int length,int wide,char *con);
void clearinput (int x,int y,int length,int wide,char *a);
#endif