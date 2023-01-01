    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define fi(a, n) for (int i = a; i < n; i++)
        int evalRPN(vector<string> &tokens)
        {
            stack<int> st;
            for (auto x : tokens)
            {
                if (x == "+" || x == "-" || x == "*" || x == "/")
                {
                    int t = st.top();
                    st.pop();
                    int s = st.top();
                    st.pop();

                    if (x == "+")
                    {
                        st.push(s + t);
                    }

                    if (x == "-")
                    {
                        st.push(s - t);
                    }
                    if (x == "*")
                        st.push(s * t);

                    if (x == "/")
                        st.push(s / t);
                }
                else
                {
                    int k = stoi(x);
                    st.push(k);
                }
            }
            return st.top();
        }
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<string> s;
        int t;
        cin>>t;
        while(t--){
    string x;
        cin >> x;
        s.push_back(x);
        }
        cout <<evalRPN(s)<<endl;
        return 0;
    }
