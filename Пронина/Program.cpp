#include <iostream>
#include <stdio.h>
#include <cmath>
#include "floatfann.h"
using namespace std;

typedef basic_string<char> string;
int main(int argc, char* argv[])
{
	fann_type *calc_out;
	fann_type input[3];
	int i1, i2, i3;

	struct fann *ann = fann_create_from_file("552_float.net");
	
	
	if (argc == 4)
	{
		
		input[0] = (float) argv[1][0]-'0';
		input[1] = (float)argv[2][0]-'0';
		input[2] = (float)argv[3][0]-'0';
		calc_out = fann_run(ann, input);
		printf("%.0f\n", abs(calc_out[0]));
		
	}
	else
	{
		for (i1=0; i1<2; i1++)
			for (i2=0; i2<2; i2++)
				for (i3=0;i3<2;i3++)
				{
					input[0] = (float) i1;
					input[1] = (float) i2;
					input[2] = (float) i3;
					calc_out = fann_run(ann, input);
					printf("%.0f xor !%.0f => %.0f = %.0f\n", input[0], input[1], input[2], abs(calc_out[0]));
				}
	}
	fann_destroy(ann);
	return 0;
}