#!/bin/bash -l

# Specify the current working directory as the location for executables/files
# This is the default setting.
#SBATCH -D ./

# Export the current environment to the compute node (modules that you have loaded in...
# ...the login node will be loaded onto the compute node)

# This is the default setting.
#SBATCH --export=ALL

# Specific course queue, exclusive use (for timings), max 1 min wallclock time. 
#SBATCH -p course
#SBATCH --exclusive
#SBATCH -t 1

# No special modules need to be loaded for this job

echo '---Running Program---'

gcc -std=c99 quad.c func1.c -lm

time ./a.out

echo '---Ending Program----'


