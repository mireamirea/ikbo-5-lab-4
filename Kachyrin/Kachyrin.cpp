#include <stdlib.h>
#include <stdio.h>
#include "fann.h"
#include "floatfann.h"
#include <iostream>


using std::cout;
using std::endl;

int main(int argc, char** argv) {
	int i, i1, i2, i3;
	const unsigned int num_input = 3; 
	const unsigned int num_output = 1; 
	const unsigned int num_layers = 3; 
	const unsigned int num_neurons_hidden = 3; 
	const float desired_error = (const float) 0.01; 
	const unsigned int max_epochs = 1000;
	const unsigned int epochs_between_reports = 2;
	fann_type *calc_out; 
	fann_type input[3]; 
	struct fann *ann = fann_create_standard(num_layers, num_input, num_neurons_hidden, num_output);
	fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
	fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);
	//fann_train_on_file(ann, "training.txt", max_epochs,epochs_between_reports, desired_error);- Если не выполнялось обучение НС до этого//
	ann = fann_create_from_file("550_float.net");
	if (argc == 4) {
		for (i = 0; i < 3; i++)
			if (argv[i + 1][0] == '0')
				input[i] = 0;
			else
				input[i] = 1;
		calc_out = fann_run(ann, input);
		printf("%f\n", calc_out[0]);
	}
	else
	   {
		for (i1 = 0; i1<2; i1++)
			for (i2 = 0; i2<2; i2++)
				for (i3 = 0; i3<2; i3++)
				{
					input[0] = (float)i1;
					input[1] = (float)i2;
					input[2] = (float)i3;
					calc_out = fann_run(ann, input);
					printf("%.0f xor !%.0f xor !%.0f = %.0f\n", input[0], input[1], input[2], abs(calc_out[0]));
				}
	}
	fann_destroy(ann);
	return 0;
}