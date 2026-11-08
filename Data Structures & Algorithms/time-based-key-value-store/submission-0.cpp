class TimeMap {
   private:
    unordered_map<string, vector<pair<int, string>>> map;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) { map[key].push_back({timestamp, value}); }

    string get(string key, int timestamp) {
        auto& values = map[key];

        int l = 0, r = values.size() - 1;
        string result = "";

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (values[m].first <= timestamp) {
                result = values[m].second;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return result;
    }
};
