#!/bin/bash
#SBATCH --job-name=cuda_scaling
#SBATCH --time=00:30:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --gres=gpu:1
#SBATCH --partition=normal
#SBATCH --output=cuda_scaling.out

module load nvhpc

#given blocjs and threads from task
blocks=(60 120 180 240 300 360 420 600)
threads=(16 32 48 64 80 96 112 128 144 160)

#make output file
echo "NUM_BLOCK,NUM_THREAD,Time(s)" > timing_results.csv

#loop over given blocks/threads
for b in "${blocks[@]}"; do
  for t in "${threads[@]}"; do
    echo "Running NUM_BLOCK=$b NUM_THREAD=$t"
    time_str=$(srun ./cpi_cuda_scaling $b $t | grep "computed in" | awk '{print $10}')
    echo "$b,$t,$time_str" >> timing_results.csv
  done
done
