class Solution {
public:
    int numberOfBoomerangs(std::vector<std::vector<int>>& points) {
        int total_boomerangs = 0;
        int n = points.size();

        
        for (int i = 0; i < n; ++i) {
            
            std::unordered_map<int, int> distance_counts;
            
            for (int j = 0; j < n; ++j) {
                if (i == j) continue; 

                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int squared_distance = dx * dx + dy * dy;

                distance_counts[squared_distance]++;
            }

            
            for (auto& [distance, count] : distance_counts) {
                if (count > 1) {
                    total_boomerangs += count * (count - 1);
                }
            }
        }

        return total_boomerangs;
    }
};