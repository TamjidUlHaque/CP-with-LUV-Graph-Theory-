//The author of this beautiful code is Tamjid Ul Haque .

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key(k) : no. of elements < k
// *find_by_order(i) : value at index i (0-based)

template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename Key, typename Value>
using ordered_map = tree<Key, Value, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;

#define Bismillah() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Alhamdulillah return 0 ;
#define Input  freopen("input.txt", "r", stdin);
#define Output freopen("output.txt", "w", stdout);


typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef vector<vll> vvll;
typedef vector<pair<int, int>> vpi;
typedef vector<vpi> vvpi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define infinity LLONG_MAX
#define aura LLONG_MIN
#define F first
#define S second
#define sesh '\n'
#define gap ' '

#define lin(k) ll k ; cin >> k ;
#define sin(s) string s ; cin >> s ;
#define llvec(v,n) vector<long long > v(n) ;
#define llvecin(v,n) for(int i = 0 ; i < n ; i++) cin >> v[i] ;

#define testloop int test; cin >> test; while (test--)
#define tamjid(g) for(int i = 0 ; i < g ; ++i)
#define loop(i,start,end) for(int i = start ; i < end ; ++i)

#define len(x) int((x).size())
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()
#define nsort(v) sort(v.begin(),v.end());
#define rsort(v) sort(v.rbegin(),v.rend());
#define flip(v) reverse(v.begin(),v.end());


#define show(z) cout << z << endl
#define printtwo(a,b) cout << a << " " << b << endl
#define display(vec) for(auto value:vec) cout << value << " "
#define printpair(vec) for(auto value:vec) cout << value.first << " " << value.second << endl

#define RemoveLeadingZeros(s) (s.erase(0, s.find_first_not_of('0')))
#define eraser(s) s.erase(remove(s.begin(), s.end(), 'TheCharIwannaRemove'), s.end())
#define countsetbits(x) __builtin_popcount(x)
#define countsetbitsll(x) __builtin_popcountll(x)
#define tamjid_shuffle(vec) shuffle(vec.begin(), vec.end(), mt19937(chrono::steady_clock::now().time_since_epoch().count())) ;

#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

#define isOdd(n) ((n) & 1)
#define isEven(n) (((n) & 1) == 0)
bool powerof2(long long x) {
    return (x > 0) && ((x & (x - 1)) == 0);
}

#define Sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define Boro(vec) *(max_element(vec.begin(),vec.end()))
#define Chuto(vec) *(min_element(vec.begin(),vec.end()))
#define minidx(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxidx(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())


/*const int MXSZ = 10000033 ;
int Arr[MXSZ] ;


int rangeBitwiseOr(int L, int R) {
    int mask = L ^ R;
    int rightestBit = 0;

    while (mask) {
        rightestBit = (rightestBit << 1) | 1;
        mask >>= 1;
    }

    return R | rightestBit;
}

bool isBracketSequenceBalanced(const string &str) {
    int level = 0;

    for (auto &ch : str)
        if (ch == '(') {
            level++;
        } else {
            level--;

            if (level < 0)
                return false;
        }

    return level == 0;
}

long long factorial(long long n) {
    long long res = 1;
    for (ll i = 2; i <= n; ++i) res *= i;
    return res;
}

long long nCr(long long n, long long r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

long long nPr(long long n, long long r) {
    return factorial(n) / factorial(n - r);
}

bool CodeforcesRanklist(pair<int, int>& a, pair<int, int>& b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

ll AndOperationBetweenLtoR(ll num , ll ans){
    ll rangeAndValue = 0LL ;
    for(ll i = 62 ; i >= 0 ; i--){
        ll mask = (1LL<<i) ;
        if((num&mask) != (ans&mask)) break ;
        else{
            if((num&mask)) rangeAndValue |= mask ;
        }
    }
    return rangeAndValue ;
}


ll gcd(ll a , ll b){
    return b == 0 ? a : gcd(b,a%b) ;
}

ll lcm(ll a , ll b){
    return a * b/__gcd(a,b) ;
}

ll power(ll x , ll n){
    ll value = 1LL ;
    tamjid(n) value *= x ;
    return value ;
}

ll rootOver(ll n){
    ll x = sqrt(n) + 1 ;
    if(x*x>n) x-- ;
    return x ;
}

string decToBinary(ll n){
    string s = string(61,'0') ;
    for(ll i = 0 ; i < 61 ; i++){
        ll mask = (1LL << i) ;
        if(mask&n) s[i] = '1' ;
    }
    flip(s) ; RemoveLeadingZeros(s) ;
    return s ;
}

bool isPerfectSquare(ll n){
    ll root = sqrt(n) ;
    if(root*1LL*root==n) return true ;
    return false ;
}

bool isPrimeNumber(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

*/


/*
    ___        __              __   ______          __        _____ __             __          __  __
   /   | _____/ /___  ______ _/ /  / ____/___  ____/ /__     / ___// /_____ ______/ /______   / / / /__  ________
  / /| |/ ___/ __/ / / / __ `/ /  / /   / __ \/ __  / _ \    \__ \/ __/ __ `/ ___/ __/ ___/  / /_/ / _ \/ ___/ _ \
 / ___ / /__/ /_/ /_/ / /_/ / /  / /___/ /_/ / /_/ /  __/   ___/ / /_/ /_/ / /  / /_(__  )  / __  /  __/ /  /  __/
/_/  |_\___/\__/\__,_/\__,_/_/   \____/\____/\__,_/\___/   /____/\__/\__,_/_/   \__/____/  /_/ /_/\___/_/   \___/

*/
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

/*
const double pi = 3.141592653589793238462643 ;
*/


void IcpcDhakaRegionalist2025(){
    int n ; cin >> n ; vi vec(1,0) , odd , even ;
    for(int i = 0 ; i < n ; i++){
        int x ; cin >> x ; vec.pb(x) ;
        if(x%2) odd.pb(i+1) ;
        else even.pb(i+1) ;
    }
    vector<int> adj[n+1] ;
    for(int i = 1 ; i <= n ; i++){
        if(i+vec[i]<=n) adj[i+vec[i]].pb(i) ;
        if(i-vec[i]>=1) adj[i-vec[i]].pb(i) ;
    }

    // Odd theke BFS chalabo even e minDistance kore Pouchanur jonne.
    queue<int> bijur ; vector<bool> oddVis(n+1,false) ;
    vector<int> distanceFromOdd(n+1,0) ;
    for(auto elem:odd){
        bijur.push(elem) ; oddVis[elem] = true ;
    }
    while(!bijur.empty()){
        int node = bijur.front() ; bijur.pop() ;
        for(auto elem:adj[node]){
            if(oddVis[elem]) continue ;
            distanceFromOdd[elem] = distanceFromOdd[node] + 1 ;
            bijur.push(elem) ; oddVis[elem] = true ;
        }
    }

    // Even theke BFS chalabo even e minDistance kore Pouchanur jonne.
    queue<int> jur ; vector<bool> evenVis(n+1,false) ;
    vector<int> distanceFromEven(n+1,0) ;
    for(auto elem:even){
        jur.push(elem) ; evenVis[elem] = true ;
    }

    while(!jur.empty()){
        int node = jur.front() ; jur.pop() ;
        for(auto elem:adj[node]){
            if(evenVis[elem]) continue ;
            distanceFromEven[elem] = distanceFromEven[node] + 1 ;
            jur.push(elem) ; evenVis[elem] = true ;
        }
    }

    for(int i = 1 ; i <= n ; i++){
        if(vec[i]&1){
            if(distanceFromEven[i]) cout << distanceFromEven[i] ;
            else cout << -1 ;
        }else{
            if(distanceFromOdd[i]) cout << distanceFromOdd[i] ;
            else cout << -1 ;
        }
        if(i != n) cout << gap ;
        else cout << endl ;
    }

}

int main(){
    Bismillah() ;

    /*testloop*/ IcpcDhakaRegionalist2025() ;

    Alhamdulillah ;
}
