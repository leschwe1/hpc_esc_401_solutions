#include <random>
#include <vector>
#include <cmath>

using std::vector;

struct particles {
    vector<float> x, y, z;	// position
    vector<float> vx, vy, vz;	// velocity
    vector<float> ax, ay, az;	// acceleration
};

// Initial conditions
void ic(particles &plist, int n) {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<float> dis(0.0, 1.0);

    // Resize all 9 vectors at once
    plist.x.resize(n);
    plist.y.resize(n);
    plist.z.resize(n);
    plist.vx.resize(n);
    plist.vy.resize(n);
    plist.vz.resize(n);
    plist.ax.resize(n);
    plist.ay.resize(n);
    plist.az.resize(n);

    for (int i = 0; i < n; ++i) {
        plist.x[i] = dis(gen);
        plist.y[i] = dis(gen);
        plist.z[i] = dis(gen);
        plist.vx[i] = 0.0f;
        plist.vy[i] = 0.0f;
        plist.vz[i] = 0.0f;
        plist.ax[i] = 0.0f;
        plist.ay[i] = 0.0f;
        plist.az[i] = 0.0f;
    }
}

void forces(particles &plist) {
    int n = plist.x.size();  // number of particles

    for (int i = 0; i < n; ++i) {
        float ax = 0.0f, ay = 0.0f, az = 0.0f;

        // Loop over 0 .. i-1
        for (int j = 0; j < i; ++j) {
            float dx = plist.x[j] - plist.x[i];
            float dy = plist.y[j] - plist.y[i];
            float dz = plist.z[j] - plist.z[i];
            float r = sqrtf(dx*dx + dy*dy + dz*dz);
            float ir3 = 1.0f / (r*r*r);

            ax += dx * ir3;
            ay += dy * ir3;
            az += dz * ir3;
        }

        // Loop over i+1 .. n-1
        for (int j = i + 1; j < n; ++j) {
            float dx = plist.x[j] - plist.x[i];
            float dy = plist.y[j] - plist.y[i];
            float dz = plist.z[j] - plist.z[i];
            float r = sqrtf(dx*dx + dy*dy + dz*dz);
            float ir3 = 1.0f / (r*r*r);

            ax += dx * ir3;
            ay += dy * ir3;
            az += dz * ir3;
        }

        plist.ax[i] = ax;
        plist.ay[i] = ay;
        plist.az[i] = az;
    }
}



int main(int argc, char *argv[]) {
    int N=50'000;
    particles plist;
    ic(plist,N);
    forces(plist);
    return 0;
}
