#include <map>
int main() {  
  map<string, int> name_score_map;  
  name_score_map["LiMin"] = 90;  
  name_score_map["ZiLinMi"] = 79;  
  name_score_map["BoB"] = 92;  
  name_score_map.insert(make_pair("Bing",99));  
  name_score_map.insert(make_pair("Albert",86));  
 //把map中元素转存到vector中   
  vector<PAIR> name_score_vec(name_score_map.begin(), name_score_map.end());  
  sort(name_score_vec.begin(), name_score_vec.end(), CmpByValue());  
 // sort(name_score_vec.begin(), name_score_vec.end(), cmp_by_value);  
  for (int i = 0; i != name_score_vec.size(); ++i) {  
    cout << name_score_vec[i] << endl;  
  }  
  return 0;  
}  
