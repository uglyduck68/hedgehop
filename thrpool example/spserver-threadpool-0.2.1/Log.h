/**
* @file		Log.h
* @auther	Younghwan Kim (uglyduck68@gmail.com)
* @version	0.1
* @date		20140816
* @brief	interface file for logging. this file will be extended to Log class.
*/
#pragma once

#define	LOG(format,...)		printf(format, ##__VA_ARGS__)