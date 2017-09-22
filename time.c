/*
 * =====================================================================================
 *
 *       Filename:  time.c
 *
 *    Description:  time.h
 *
 *        Version:  1.0
 *        Created:  22.09.2017 12:28:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <time.h>

int main() {
  time_t *now;
  time(*&now);
  printf("Sekunden seit 01.01.1970 00:00:00 Uhr: %ld\n", *now);
  *now = time(0);
  printf("%s\n", ctime(*&now));
  struct tm *myTm;
  myTm = localtime(*&now);
  printf("%02d:%02d:%02d Uhr\n", myTm->tm_hour, myTm->tm_min, myTm->tm_sec);
  return 0;
}
