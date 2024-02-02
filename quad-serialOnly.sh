#!/bin/bash -l

# Specify the current working directory as the location for executables/files
# This is the default setting.
#SBATCH -D ./

# Export the current environment to the compute node (all modules that are loaded)
# This is the default setting.
#SBATCH --export=ALL

# Specific course queue, exclusive use (for timings), max 1 min wallclock time. 
#SBATCH -p course
#SBATCH --exclusive
#SBATCH -t 1


echo '---Running Program---'

gcc quad.c func1.c -lm
time ./a.out

echo '---Ending Program----'


