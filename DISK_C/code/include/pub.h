/**
  ******************************************************************************
  * @file   pub.h
  * @brief   This file provides some small but usefull functions such as draw some common buttons
  ******************************************************************************
  */
#ifndef _pub.h_
#define _pub.h_

void draw_button(int x,int y,int x1,int y1,int color);
void button_change(int x,int y,int x1,int y1);
void button_recover(int x,int y,int x1,int y1);
void ESC_draw();
void ESC_change();
void ESC_recover();
void refram(int x,int y,int length,int wide);
void in_visible1(int x,int y,int max,int min,int length, int wide,char *con);
void in_hidden(int x,int y,int max, int min,int length,int wide,char *con);
void clearinput (int x,int y,int length,int wide,char *a);
#endif
