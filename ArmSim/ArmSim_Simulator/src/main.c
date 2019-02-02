#include "myARMSim.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  char* prog_mem_file; 
  if(argc < 3) {
    printf("Incorrect number of arguments. Please invoke the simulator \n\t./myARMSim <input arm file> <input latency file> \n");
    exit(1);
  }
  
  //reset the processor
  reset_proc();
  //load the program memory
  load_program_memory(argv[1]);
  parlatency(argv[2]);
  //run the simulator
  run_armsim();
  
  return 1;
}
