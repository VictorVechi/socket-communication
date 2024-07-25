#define RTC_DEVICE "/dev/rtc0"

int open_rtc_device() {
    int rtc = open(RTC_DEVICE, O_RDWR);
    if (rtc == -1) {
        perror("Não foi possível abrir " RTC_DEVICE);
        exit(EXIT_FAILURE);
    }
    return rtc;
}

void set_rtc_time(int rtc, struct tm *new_time) {
    struct rtc_time rtc_tm;

    rtc_tm.tm_sec = new_time->tm_sec;
    rtc_tm.tm_min = new_time->tm_min;
    rtc_tm.tm_hour = new_time->tm_hour;
    rtc_tm.tm_mday = new_time->tm_mday;
    rtc_tm.tm_mon = new_time->tm_mon;
    rtc_tm.tm_year = new_time->tm_year;

    if (ioctl(rtc, RTC_SET_TIME, &rtc_tm) == -1) {
        perror("Não foi possível definir a data e hora do RTC");
        close(rtc);
        exit(EXIT_FAILURE);
    }
}

void update_bios_time(struct tm *new_time) {
    int rtc = open_rtc_device();
    set_rtc_time(rtc, new_time);
    printf("Data e hora da BIOS atualizadas com sucesso.\n");
    close(rtc);
}

#define RTC_DEVICE "/dev/rtc0"

int open_rtc_device() {
    int rtc = open(RTC_DEVICE, O_RDWR);
    if (rtc == -1) {
        perror("Não foi possível abrir " RTC_DEVICE);
        exit(EXIT_FAILURE);
    }
    return rtc;
}

void set_rtc_time(int rtc, struct tm *new_time) {
    struct rtc_time rtc_tm;

    rtc_tm.tm_sec = new_time->tm_sec;
    rtc_tm.tm_min = new_time->tm_min;
    rtc_tm.tm_hour = new_time->tm_hour;
    rtc_tm.tm_mday = new_time->tm_mday;
    rtc_tm.tm_mon = new_time->tm_mon;
    rtc_tm.tm_year = new_time->tm_year;

    if (ioctl(rtc, RTC_SET_TIME, &rtc_tm) == -1) {
        perror("Não foi possível definir a data e hora do RTC");
        close(rtc);
        exit(EXIT_FAILURE);
    }
}

void update_bios_time(struct tm *new_time) {
    int rtc = open_rtc_device();
    set_rtc_time(rtc, new_time);
    printf("Data e hora da BIOS atualizadas com sucesso.\n");
    close(rtc);
}