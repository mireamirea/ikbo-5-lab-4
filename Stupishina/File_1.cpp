#include <iostream>
#include <stdio.h>
#include "fann.h"
#include "floatfann.h"

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
const unsigned int num_input = 3;
const unsigned int num_output = 1;
const unsigned int num_layers = 3;
const unsigned int num_neurons_hidden = 3;
const float desired_error = (const float) 0.01;
const unsigned int max_epochs = 50;
const unsigned int epochs_between_reports = 2;

fann_type *calc_out;
fann_type input[3];
struct fann *ann = fann_create_standard(num_layers, num_input, num_neurons_hidden, num_output);

fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);
fann_train_on_file(ann, "training.txt", max_epochs, epochs_between_reports, desired_error);
fann_save(ann, "462_float.net");
fann_destroy(ann);
system("pause");
return 0;
}
