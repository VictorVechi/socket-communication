#ifndef CMOS_SERVICE_H
#define CMOS_SERVICE_H

#include <time.h>

int open_rtc_device(void);
void set_rtc_time(int rtc, struct tm *new_time);
void update_bios_time(struct tm *new_time);
void atualizarDataHora(const char* dataHora);

char* getHorario();

#endif