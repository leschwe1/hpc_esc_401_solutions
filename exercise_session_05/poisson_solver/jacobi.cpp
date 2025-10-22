#include "jacobi.h"
#include <math.h>

/**
 * @brief      Computes norm of the difference between two matrices
 *
 * @param[in]  p     Parameters
 * @param      mat1  The matrix 1
 * @param      mat2  The matrix 2
 *
 * @return     Returns \sqrt{\sum(mat1_{ij} - mat2_{ij})^2/(nx*ny)}
 */
double norm_diff(params p, double** mat1, double** mat2){

    double sum = 0.0;
    for (int i = 0; i < p.nx ; i++){
        for int j = 0, j < p.ny; j++{
            double diff = mat1[i][j] - mat2[i][j];
            sum += diff * diff;
        }
    }
    double norm = sqrt(sum) / (p.nx * p.ny);
    return norm
}

/**
 * @brief      Compute a Jacobi iteration to solve Poisson equation. This function updates
 *             u_new and u_old in-place.
 *
 * @param[in]  p      Parameters
 * @param      u_new  The new solution
 * @param      u_old  The old solution
 * @param      f      The source term
 */
void jacobi_step(params p, double** u_new, double** u_old, double** f){
    double dx = 1.0/(double(p.nx - 1));
    double dy = 1.0/(double(p.ny - 1));
    double dx2 = dx * dx;
    double dy2 = dy * dy;

    for (int i=0; i<p.nx; i++){ // move from new to old so that we use current values
        for (int j=0; j<p.ny; j++){
            u_old[i][j] = u_new[i][j];
        }
    }

    for (int i = 1; i < p.nx - 1; i++) { //Perform Jacobi for interior
        for (int j = 1; j < p.ny - 1; j++) {
            // Assuming uniform grid: Δ = dx = dy
            u_new[i][j] = 0.25 * (
                u_old[i-1][j] + u_old[i+1][j] +
                u_old[i][j-1] + u_old[i][j+1] -
                dx2 * f[i][j]  // dx2 == dy2
            );
        }
    }
    for (int i = 0; i < p.nx; i++) { //reapply boundary cond.
        double x = i * dx;
        for (int j = 0; j < p.ny; j++) {
            double y = j * dy;
            if (i == 0 || i == p.nx - 1 || j == 0 || j == p.ny - 1)
                u_new[i][j] = boundary(x, y, p.rhs_function);
        }
    }
}