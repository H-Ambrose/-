#include "TM1637.h"     //添加数码管模块头文件（预先把TM1637库函数文件拷贝进arduino安装目录下的libraries文件夹里）
 
#define CLK 3           //数码管模块接口
#define DIO 2           //数码管模块接口
TM1637 tm1637(CLK,DIO); //定义数码管对象

int8_t displayData[] = {0x00, 0x00, 0x00, 0x00};  //四个数码管待显示的数据

void setup() {
  tm1637.set();       //数码管对象设置
  tm1637.init();      //数码管对象初始化
  ……
}

void loop() {
  ……
  tm1637.display(displayData);  //根据displayData数组的值，更新数码管显示
  ……
}
