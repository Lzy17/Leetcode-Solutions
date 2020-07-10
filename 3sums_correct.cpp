class Solution {
public:
vector<vector<int>> threeSum( vector<int>& nums ) {
	vector<vector<int>> result;
	int size = nums.size();
	if( size <= 2 ) return result;

	sort( nums.begin(), nums.end() );
	int sum;
	for( int i=0; i < size - 2; i++ ) {
		if( nums[i] > 0 ) break;
		if( i > 0 && nums[i-1] == nums[i] ) continue;

		int start = i + 1, end = nums.size() - 1;
		while( start < end ) {
			sum = nums[i] + nums[start] + nums[end];
			if( sum == 0 ) {
				result.push_back( { nums[i], nums[start], nums[end] } );
				start++;
				end--;
				while( start < end && nums[start] == nums[start - 1] ) start++;
				while( start < end && nums[end] == nums[end + 1] ) end--;
			}
			else if( sum > 0 )
				end--;
			else
				start++;
		}
	}
	return result;
}
};
