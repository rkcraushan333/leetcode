class Minheap{
private:
    int sz;
    vector<int>v;
public:
    Minheap(int n)
    {
        sz = 0;
        v.resize(n+1);
    }
    void Push(int val)
    {
        sz++;
        v[sz] = val;
        int last = sz;
        while(last>1)
        {
            if(v[last]<v[last/2])
            {
                swap(v[last],v[last/2]);
                last /= 2;
            }
            else break;
        }
    }
    void Pop()
    {
        swap(v[1],v[sz]);
        sz--;
        int curr = 1;
        while(curr<sz)
        {
            int l = 2*curr;
            int r = 2*curr+1;
            int c = curr;
            if(l<=sz&&v[c]>v[l]) c = l;
            if(r<=sz&&v[c]>v[r]) c = r;
            if(c==curr) break;
            swap(v[c],v[curr]);
            curr = c;
        }
    }
    int Size()
    {
        return sz;
    }
    int Top()
    {
        return v[1];
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        Minheap pq(nums.size());
        for(auto i:nums)
        {
            if(pq.Size()<k) pq.Push(i);
            else if(pq.Top()<i)
            {
                pq.Pop();
                pq.Push(i);
            }
        }
        return pq.Top();
    }
};