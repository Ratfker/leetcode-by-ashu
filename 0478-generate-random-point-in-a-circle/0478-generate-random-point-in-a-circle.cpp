class Solution {
public:
    double radius, xc, yc;
    mt19937 rng{random_device{}()};
    uniform_real_distribution<double> dist{0.0, 1.0};

    Solution(double radius, double x_center, double y_center)
        : radius(radius), xc(x_center), yc(y_center) {}

    vector<double> randPoint() {
        double r     = radius * sqrt(dist(rng));
        double theta = 2 * M_PI * dist(rng);
        return {xc + r * cos(theta), yc + r * sin(theta)};
    }
};