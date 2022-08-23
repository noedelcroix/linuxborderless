#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <xdo.h>
#include <string.h>
#include <stdlib.h>

void getScreenWidth(int * w){
    FILE * fd = popen("xdpyinfo | awk '/dimensions/ {print $2}'", "r");
    if(fd == NULL) exit(-1);

    char line [255];
    fgets(line, 255, fd);

    *w=atoi(strtok(line, "x"));
}

int main(){
    xdo_t * screen = xdo_new(NULL);
    int x;
    int y;
    Window root = 0;

    int width;

    getScreenWidth(&width);

    xdo_get_mouse_location(screen, &x, &y, NULL);

    while(1){
        xdo_wait_for_mouse_move_from(screen, x, y);
        xdo_get_mouse_location(screen, &x, &y, NULL);
        if(x==0){
            xdo_move_mouse(screen, width-5, y, 0);
        }else if (x==width-1){
            xdo_move_mouse(screen, 5, y, 0);
        }
    }
}