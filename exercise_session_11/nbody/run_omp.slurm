#!/bin/bash
#SBATCH --job-name=nbody_omp
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=128
#SBATCH --time=00:30:00
#SBATCH --partition=normal



export OMP_NUM_THREADS=128

/usr/bin/time ./nbody

