#!/bin/bash
#SBATCH --job-name=dot
#SBATCH --account=uzh8
#SBATCH --time=00:05:00
#SBATCH --partition=normal
#SBATCH --constraint=gpu
#SBATCH --ntasks=1



module load nvhpc

echo "Running dot product on GPU and CPU"

srun ./dot.openacc 16

srun ./dot.openacc 18

srun ./dot.openacc 20

srun ./dot.openacc 22
