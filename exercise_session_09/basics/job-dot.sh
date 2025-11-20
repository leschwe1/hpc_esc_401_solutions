#!/bin/bash
#SBATCH --job-name=dot
#SBATCH --account=uzh8
#SBATCH --time=00:05:00
#SBATCH --partition=normal
#SBATCH --constraint=gpu
#SBATCH --ntasks=1
#SBATCH --gres=gpu:1

echo "Running dot product on GPU and CPU"

srun ./dot.openacc 20
