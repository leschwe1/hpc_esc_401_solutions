#!/bin/bash
#SBATCH --job-name=cpi_cuda       # Job name
#SBATCH --time=00:10:00           # Maximum runtime (hh:mm:ss)
#SBATCH --nodes=1                 # Number of nodes
#SBATCH --ntasks-per-node=1       # Number of tasks per node
#SBATCH --gres=gpu:1              # Request 1 GPU
#SBATCH --partition=normal        # Partition name
#SBATCH --output=cpi_cuda.out     # Standard output file

module load nvhpc

srun ./cpi_cuda
