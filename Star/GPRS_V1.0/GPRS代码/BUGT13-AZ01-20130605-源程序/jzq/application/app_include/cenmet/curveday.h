/**
* curveday.h -- 日冻结类历史数据结构
* 
* 作者: zhuzhiqiang
* 创建时间: 2009-5-12
* 最后修改时间: 2009-5-12
*/

#ifndef _CURVE_DAY_H
#define _CURVE_DAY_H

#include "app_include/cenmet/mdbconf.h"

typedef struct {
	unsigned char rdtime[5];    //抄表时间, 分时日月年
	unsigned char fenum;

	//F1
	unsigned char enepa[5*MAXNUM_METPRD];  //正向有功电能, 0~4, 0.0001kWh
	unsigned char enepi[4*MAXNUM_METPRD];  //正向无功电能, 0~4, 0.01kvarh
	unsigned char enepi1[4*MAXNUM_METPRD];  //正向无功一象限电能, 0~4, 0.01kvarh
	unsigned char enepi4[4*MAXNUM_METPRD];  //正向无功四象限电能, 0~4, 0.01kvarh
	//F2
	unsigned char enena[5*MAXNUM_METPRD];  //反向有功电能, 0~4, 0.0001kWh
	unsigned char eneni[4*MAXNUM_METPRD];  //反向无功电能, 0~4, 0.01kvarh
	unsigned char eneni2[4*MAXNUM_METPRD];  //反向无功二象限电能, 0~4, 0.01kvarh
	unsigned char eneni3[4*MAXNUM_METPRD];  //反向无功三象限电能, 0~4, 0.01kvarh
	//F3
	unsigned char dmnpa[3*MAXNUM_METPRD];  //当月正向有功最大需量,0~4,0.0001kW
	unsigned char dmntpa[4*MAXNUM_METPRD];  //当月正向有功最大需量发生时间,0~4,分时日月
	unsigned char dmnpi[3*MAXNUM_METPRD];  //当月正向无功最大需量,0~4,0.0001kvar
	unsigned char dmntpi[4*MAXNUM_METPRD];  //当月正向无功最大需量发生时间,0~4,分时日月
	//F4
	unsigned char dmnna[3*MAXNUM_METPRD];  //当月反向有功最大需量,0~4,0.0001kW
	unsigned char dmntna[4*MAXNUM_METPRD];  //当月反向有功最大需量发生时间,0~4,分时日月
	unsigned char dmnni[3*MAXNUM_METPRD];  //当月反向无功最大需量,0~4,0.0001kvar
	unsigned char dmntni[4*MAXNUM_METPRD];  //当月反向无功最大需量发生时间,0~4,分时日月
	//F5
	//unsigned char enepa_day[4*MAXNUM_METPRD];     //当日正向有功电能量, 0.0001kWh
	//F6
	//unsigned char enepi_day[4*MAXNUM_METPRD];     //当日正向无功电能量, 0.0001kvarh
	//F7
	//unsigned char enena_day[4*MAXNUM_METPRD];     //当日反向有功电能量, 0.0001kWh
	//F8
	//unsigned char eneni_day[4*MAXNUM_METPRD];     //当日反向无功电能量, 0.0001kvarh
	//F153
	unsigned char enepa_abc[5*3];	//ABC相正向有功电能示值, 0.0001kWh
	//F154
	unsigned char enepi_abc[4*3];	//ABC相正向无功电能示值, 0.01kvarh
	//F155
	unsigned char enena_abc[5*3];	//ABC相反向有功电能示值, 0.0001kWh
	//F156
	unsigned char eneni_abc[4*3];	//ABC相正向无功电能示值, 0.01kvarh
} db_metday_t;

typedef struct {
	//F49
	unsigned char pwr_time[2];    //终端日供电时间, min
	unsigned char rest_cnt[2];    //终端日复位次数
	//F50
	unsigned char sw_time[4];	 //跳闸累计次数
	//F53
	unsigned char comm_bytes[4];  //终端与主站日通信流量, 字节
	//F221
	unsigned char sig_max;
	unsigned char sigmax_time[2];  //min, hour
	unsigned char sig_min;
	unsigned char sigmin_time[2];  //min, hour
} db_termday_t;

#endif /*_CURVE_DAY_H*/

