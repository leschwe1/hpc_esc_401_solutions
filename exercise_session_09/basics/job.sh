#!/bin/bash
#SBATCH --job-name=blur
#SBATCH --account=uzh8
#SBATCH --time=00:05:00
#SBATCH --partition=normal
#SBATCH --constraint=gpu
#SBATCH --ntasks=1
#SBATCH --gres=gpu:1

echo "===== Running naive GPU version ====="

echo "Running blur 20 100"
srun ./blur.openacc 20 100

echo "Running blur 16 100"
srun ./blur.openacc 16 100

echo "Running blur 24 100"
srun ./blur.openacc 24 100

echo "Running blur 20 50"
srun ./blur.openacc 20 50

echo "Running blur 20 200"
srun ./blur.openacc 20 200

echo "===== Running nocopies GPU version ====="

echo "Running blur 20 100"
srun ./blur.openacc.nocopies 20 100

echo "Running blur 16 100"
srun ./blur.openacc.nocopies 16 100

echo "Running blur 24 100"
srun ./blur.openacc.nocopies 24 100

echo "Running blur 20 50"
srun ./blur.openacc.nocopies 20 50

echo "Running blur 20 200"
srun ./blur.openacc.nocopies 20 20
