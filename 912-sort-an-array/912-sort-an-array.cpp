class Solution {
public:
    int method = 4;
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        switch (method){
            case 1: // bouble sort
                for(int i(0);i < n-1 ; i++){// last el is bigest
                    for(int j(0); j < n-i-1 ;j++)
                        if(nums[j] > nums[j+1])
                            swap(nums[j],nums[j+1]);
                }
                break;
            case 2: // selection sort
                for (int i = 0; i < n; i++){
                    for (int j = i + 1; j < n; j++){
                        if (nums[i] > nums[j])
                            swap(nums[i], nums[j]);
                    }
                }
                break;
            case 3: // insertion sort
                for (int i = 1; i < n; ++i){
                    int j, curr = nums[i];
                    for (j = i - 1; j >= 0 && nums[j] > curr; j--){
                        nums[j + 1] = nums[j];
                    }
                    nums[j + 1] = curr;
                }
                break;
            case 4: // merge sort
                MergeSort(nums, 0, n - 1);
                break;
            case 5: // quick sort
                Quick_sort(nums,0,n-1);
                break;
            default:
                sort(nums.begin(),nums.end());
                break;
        }
        return nums;
    }
        
    void Quick_sort(vector<int> &v,int left,int right){
        if(left>=right)
            return;
        int pi = Partition(v,left,right);
        Quick_sort(v,left,pi-1);
        Quick_sort(v,pi+1,right);
    }
    int Partition(vector<int>&v,int left,int right){
		int pivot = v[right];
		int i=left;
		for (int j = left; j < right; j++){
			if(v[j] < pivot){
				swap(v[i],v[j]);
				i++;
			}
		}
		swap(v[i],v[right]);
        return i;
	}
    
    void MergeSort(vector<int> &v, int left, int right){
		if (left >= right)
            return;
        int mid = (left + right) / 2;
        MergeSort(v, left, mid);
        MergeSort(v, mid + 1, right);
        Merge(v, left, mid, right);
	}
    void Merge(vector<int> &v, int l, int mid, int r){
		int n1 = mid + 1 - l;
		int n2 = r - mid;
		int arr1[n1], arr2[n2];//temp arrays
		for (int i = 0; i < n1; ++i)
			arr1[i] = v[l + i];
		for (int i = 0; i < n2; ++i)
			arr2[i] = v[mid + 1 + i];

		int p1 = 0, p2 = 0, k = l;
		while (p1 < n1 && p2 < n2)
		{
			if (arr1[p1] < arr2[p2])
			{
				v[k] = arr1[p1];
				p1++;
			}
			else
			{
				v[k] = arr2[p2];
				p2++;
			}
			k++;
		}
		while (p1 < n1)
		{
			v[k] = arr1[p1];
			p1++;
			k++;
		}
		while (p2 < n2)
		{
			v[k] = arr2[p2];
			p2++;
			k++;
		}
		return;
	}

};