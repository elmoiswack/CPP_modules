#pragma once

#include <iostream>

template <typename T> 
void iter(T *arr, int len, void (*ft)(T input))
{
	for (int i = 0; i < len; i++)
	{
		ft(arr[i]);
	}
}
