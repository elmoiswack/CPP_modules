#pragma once

#include <iostream>

template <typename T> void swap(T &input1, T &input2)
{
	T temp;

	temp = input1;
	input1 = input2;
	input2 = temp;
}

template <typename T> T max(T input1, T input2)
{
	T temp;

	temp = (input1 > input2)? input1 : input2;
	return (temp);
}

template <typename T> T min(T input1, T input2)
{
	T temp;

	temp = (input1 < input2)? input1  : input2;
	return (temp);
}