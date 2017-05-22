/*MANISH SHARMA - 22/05/2017*/
/*if need function form, then make the arrays global and use arr.clear() when the test case gets over.*/
    int main() {
        //taking input
        int n;sd(n);
        int i,x;
        vector<int> arr,block_arr;
        rep(i,n){
            cin>>x;
            arr.pb(x);
        }

        //creating block array
        int block_size = sqrt(n);
        int sum=0;
        rep(i,n)
        {
            if(i%block_size == 0)
            {
                sum=0;
                block_arr.pb(0);
            }
            block_arr[i/block_size]+=arr[i];
        }

        //updation at ix -> val
        int ix = 2;
        int val = 10;
        int block_ix = ix/block_size;
        block_arr[block_ix] += val - arr[ix];
        arr[ix] = val;

        //query
        int q,l,r;sd(q);
        while(q--){
            cin>>l>>r;
            int tot=0;//required value

            //before overlapping blocks
            while(l%block_size!=0 && l>0 && l<r)
            {
                tot+= arr[l++];
            }

            //overlapping blocks
            while(l+block_size <= r)
            {
                tot+=block_arr[l/block_size];
                l+=block_size;
            }

            //after overlapping block
            while(l<=r)
            {
                tot+=arr[l++];
            }

            cout<<tot<<endl;

        }

    	return 0;
    }

