class TimeMap{
public:
	unordered_map<string, vector<pair<string, int>>> mp;
	TimeMap(){
	}
	void set(string key, string value, int timestamp){
		mp[key].push_back({value, timestamp});
	}
	string get(string key, int timestamp){
		string res = "";
		if(mp.find(key) != mp.end()){
			int left = 0;
			int right = mp[key].size() - 1;	
			while(left <= right){
				int mid = left + (right - left)/2;
				auto val = mp[key][mid];
				if(val.second <= timestamp){
					res = val.first;
					left = mid + 1;
				}
				else{ 	
					right = mid - 1;
				}
			}
		}
		return res;
	}
};