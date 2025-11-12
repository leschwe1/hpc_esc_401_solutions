#!/bin/bash
#SBATCH --job-name=cpi_openacc
#SBATCH --time=00:10:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --gres=gpu:1
#SBATCH --partition=normal
#SBATCH --output=cpi_openacc.out

module load cray
module load nvhpc

srun ./cpi_openacc
