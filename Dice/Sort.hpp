#pragma once
#include "Functions.hpp"

namespace func
{
	/*	(Bad) implementation of Quicksort. This produces a new array instead of sorting in-place.
		@param param	Array to be sorted.
		@param size		Size of param.
		@return			New array with the elements of param now sorted.
	*/
	template <typename Type> Type* nQSort (const Type param[], const usi size)
	{
		if (size == 1)						//If the array only has one element then return the array itself.
			return new Type{ param[0] };


		usi		chi = 0,					//Counts the elements of param higher than or equal to avg.
				clo = 0;					//Same as chi but for the lower side.
		Type	avg = Type(),				//Average of all the elements of param.
				*hi,						//Stores all param elements higher than avg.
				*shi,						//Sorted version of hi.
				*lo,						//Same as hi, but for the lower side.
				*slo,						//Sorted version of lo.
				*res;						//Final sorted array.

		for (usi i = 0; i < size; i++)		//Calculating the average...
			avg += param[i];
		avg /= size;

		for (usi i = 0; i < size; i++)		//Calculating chi and clo...
			if (param[i] < avg)
				clo++;
			else
				chi++;

		if (chi > 0)
			hi = new Type[chi]{ 0 };		//Now that the size is known, hi and lo are created.
		if (clo > 0)
			lo = new Type[clo]{ 0 };

		chi = clo = 0;						//chi and clo are reset.

		for (usi i = 0; i < size; i++)		//Storing all the elements of param in the corresponding array...
			if (param[i] < avg)
				lo[clo++] = param[i];
			else
				hi[chi++] = param[i];

		if (chi > 0)
			shi = nQSort(hi, chi);			//Creating new arrays with their elements sorted and deleting the unsorted ones.
		delete[] hi;

		if (clo > 0)
			slo = nQSort(lo, clo);
		delete[] lo;

		res = new Type[size]{ 0 };
		for (usi i = 0;i < chi; i++)
			res[i] = shi[i];
		for (auto i = chi; i < size; i++)
			res[i] = slo[i - chi];

		delete[] shi, slo;

		return res;
	}
}