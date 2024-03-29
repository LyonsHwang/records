struct Fenwick {
    int n;
    vector<ll> t;
    void init(int n_) {
        n=n_;
        t.assign(n+1,0);
    }
    bool forward(int &x) {
        x+=x&-x;
        return x<=n;
    }
    bool back(int &x) {
        x-=x&-x;
        return x;
    }
    void update(int x,ll v) {
        do t[x]=max(t[x],v);
        while(forward(x));
    }
    ll query(int x) {
        ll r=0;
        do r=max(r,t[x]);
        while(back(x));
        return r;
    }
};
