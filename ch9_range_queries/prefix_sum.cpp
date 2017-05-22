 /*MANISH SHARMA - 22/05/2017*/
 int main() {
        int n;sd(n);
        int i,x;
        vector<int> arr,prefix_arr;
        rep(i,n){
            cin>>x;
            arr.pb(x);
            prefix_arr.pb(x);
        }
        for(i=1;i<n;i++){
            prefix_arr[i] += prefix_arr[i-1];
        }
        int q,a,b;sd(q);
        while(q--){
            cin>>a>>b;
            cout<<prefix_arr[b]-prefix_arr[a-1]<<endl;
        }
    	return 0;
    }