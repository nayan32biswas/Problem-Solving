#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b
#define series(n) (n * (n + 1)) / 2
#define series_squre(n) ((n * (n + 1) * (2 * n + 1)) / 6)
#define series_cube(n) pow(serise(n), 2)
#define range_sum(lo, hi) (series(hi) - series(abs(lo - 1)))

/************************************************************************************************ Technique  ************************************************************************************************/
class Fast_input
{
    template <typename T>
    void read(T &x)
    {
        char c;
        bool t = false;
        for (c = getchar(); (c < '0' || c > '9') && c != '-'; c = getchar())
            ;
        if (c == '-')
        {
            c = getchar();
            t = true;
        }
        for (x = c - '0', c = getchar(); c >= '0' && c <= '9'; x = x * 10 + c - '0', c = getchar())
            ;
        if (t)
            x = -x;
    }
};

/**************************************************************/
class extractInteger_
{

    void extractInteger(string &str)
    {
        string temp = "";
        stringstream ss;
        ss << str;
        int number;
        while (!ss.eof())
        {
            ss >> temp;
            if (stringstream(temp) >> number)
            {
                cout << number << endl;
            }
            temp = "";
        }
    }
};

/**************************************************************/

// function to check if paranthesis are balanced
class isParanthesisBalanced_
{
    bool isParanthesisBalanced(string expr)
    {
        stack<char> s;
        char x;
        for (int i = 0; i < expr.length(); i++)
        {
            if (expr[i] == '(')
            {
                s.push(expr[i]);
            }
            else if (s.empty())
                return false;
            else if (expr[i] == ')')
            {
                x = s.top();
                s.pop();
                if (x != '(')
                    return false;
            }
        }
        return s.empty();
    }
};

/**************************************************************/
class binary_search_
{
    int arr[100];
    int find(int mid)
    {
        return arr[mid];
    }
    int binary_search_lower(int key, int n)
    {
        int start = 0, End = n - 1;
        while (End - start > 1)
        {
            int mid = (start + End) / 2;
            if (find(mid) < key)
                start = mid;
            else
                End = mid;
        }
        if (find(End) <= key)
            return End;
        return start;
    }
    int binary_search_upper(int key, int n)
    {
        int start = 0, End = n - 1;
        while (End - start > 1)
        {
            int mid = (start + End) / 2;
            if (find(mid) > key)
                End = mid;

            else
                start = mid;
        }
        if (find(start) >= key)
            return start;
        return End;
    }
    // Function to perform Ternary Search
    int ternarySearch(int l, int r, int key, int ar[])
    {
        while (r >= l)
        {
            // Find the mid1 and mid2
            int mid1 = l + (r - l) / 3;
            int mid2 = r - (r - l) / 3;
            // Check if key is present at any mid
            if (ar[mid1] == key)
            {
                return mid1;
            }
            if (ar[mid2] == key)
            {
                return mid2;
            }
            // Since key is not present at mid,
            // check in which region it is present
            // then repeat the Search operation
            // in that region
            if (key < ar[mid1])
            {
                // The key lies in between l and mid1
                r = mid1 - 1;
            }
            else if (key > ar[mid2])
            {
                // The key lies in between mid2 and r
                l = mid2 + 1;
            }
            else
            {
                // The key lies in between mid1 and mid2
                l = mid1 + 1;
                r = mid2 - 1;
            }
        }
        // Key not found
        return -1;
    }
};

/**************************************************************/

class power
{
    double power_d(float x, int y)
    {
        double temp;
        if (y == 0)
            return 1;
        temp = power_d(x, y >> 1);
        if (!(y & 1))
            return temp * temp;
        else
        {
            if (y > 0)
                return x * temp * temp;
            else
                return (temp * temp) / x;
        }
    }
    int power_i(int x, unsigned y)
    {
        int temp;
        if (y == 0)
            return 1;
        temp = power_i(x, y >> 1);
        if (!(y & 1))
            return temp * temp;
        else
            return x * temp * temp;
    }
};

/**************************************************************/

class sqrt
{
    int My_sqrt(int x)
    {
        if (x == 1 || x == 2)
            return 1;
        int y;
        for (y = x >> 1; y > (x / y); y = ((x / y) + y) >> 1)
            ;
        return y;
    }
};


/**************************************************************/

class chess_
{
    void chess(char c, int n, int m)
    {
        /*find how many maximum chesspieces don't attack any of him in n by m chess board*/
        int ans;
        if (c == 'Q')
            ans = m > n ? n : m;
        else if (c == 'r')
            ans = m > n ? n : m;
        else if (c == 'K')
            ans = (((m + 1) >> 1) * ((n + 1) >> 1));
        else if (c == 'k')
        {
            if (m < n)
                swap(n, m);
            if (n == 1)
                ans = m;
            else if (n == 2)
                ans = (m / 4) * 4 + min(m % 4, 2) * 2;
            else
                ans = (((m + 1) >> 1) * ((n + 1) >> 1)) + ((m >> 1) * (n >> 1));
        }
        printf("%d\n", ans);
    }
};

/**************************************************************/

/*
given an array. every time remove one number
and exept this number check that sum of even positon
number and odd position number is same.
*/
int solution(vector<int> &arr)
{ // follow codeforces 1118B
    int n = arr.size();
    vector<long long> odd(n + 1), even(n + 1);
    for (int i = 0; i < n; i++)
    {
        odd[i + 1] = odd[i];
        even[i + 1] = even[i];
        if ((i & 1))
            even[i + 1] += arr[i];
        else
            odd[i + 1] += arr[i];
    }
    int t_odd, t_even, coun = 0;
    for (int i = 0; i < n; i++)
    {
        t_odd = odd[i + 1] - odd[0];
        t_odd += even[n] - even[i + 1];

        t_even = even[i + 1] - even[0];
        t_even += odd[n] - odd[i + 1];
        if (i & 1)
            t_even -= arr[i];
        else
            t_odd -= arr[i];
        if (t_odd == t_even)
            coun++;
    }
    return coun;
}

/**************************************************************/

class RangeMark
{
private:
    int Size;
    vector<int> markRange;

public:
    void init(int N)
    {
        Size = N;
        markRange.resize(Size);
        fill(markRange.begin(), markRange.end(), 0);
    }
    void fastRangeRun()
    {
        for (int i = 1; i < Size; i++)
            markRange[i] += markRange[i - 1];
    }
    void fastRange(int lo, int hi)
    {
        lo = max(0, lo - 1); /// one base
        hi = min(Size - 2, hi);
        markRange[lo]++;
        markRange[hi]--;
    }
    int fastRangeMax(int lo, int hi)
    {
        int Max = 0;
        lo = max(lo, 1); /// one base
        for (int i = lo - 1; i < hi; i++)
            Max = max(Max, markRange[i]);
        return Max;
    }
};

/************************************************************************************************ Number System  ************************************************************************************************/

// n/1 + n/2 + n/3 +.....+ n/n
long long harmonic(long long n)
{
    long long ans = 0, m = sqrt(n);
    for (int i = 1; i <= m; i++)
    {
        ans += (n / i);
    }
    ans *= 2;
    return ans - m * m;
}

/**************************************************************/

class nCR_
{
    long long nCr(long long n, long long r)
    {
        if (n < (r << 1))
            r = n - r;
        long long ans = 1;
        for (int i = 1; i <= r; (ans *= n, ans /= i), i++, n--)
            ;
        return ans;
    }
};

/**************************************************************/

class big_mod_
{
    long long big_mod(long long base, long long po, long long mod)
    {
        long long ans = 1;
        while (po > 0)
        {
            if (po & 1)
                ans = (ans * base) % mod;
            base = (base * base) % mod;
            po >>= 1;
        }
        return ans % mod;
    }
};

/**************************************************************/

// euclidean gcd
class egcd_
{
    pair<int, int>
    egcd(int a, int b)
    {
        if (b == 0)
            return make_pair(1, 0);
        else
        {
            pair<int, int> d = egcd(b, a % b);
            return make_pair(d.second, d.first - (d.second) * (a / b));
        }
    }
};

/**************************************************************/

class fibonnachi
{
    // compute fibonnaci in O(1) time
    ull fibonnaci_O_1(ull n)
    {
        double phi = (1 + sqrt(5)) / 2;
        return round(pow(phi, n) / sqrt(5));
    }

    // compute fibonnaci in log(n) time
    ull fibonnaci_O_log_n(ull n)
    {
        ull i, J, k, h, t;
        i = h = 1;
        J = k = 0;
        while (n > 0)
        {
            if (n & 1)
            {
                t = J * h;
                J = i * h + J * k + t;
                i = i * k + t;
            }
            t = h * h;
            h = 2 * k * h + t;
            k = k * k + t;
            n = n >> 1;
        }
        return J;
    }
};

/**************************************************************/

class find_ncr_npr_sing_modulo_inverse
{
/* fastly answer each query of nCr */
#define Size 100005
    typedef long long int lli;
    // Do initial precalculation
    lli Fact[Size];
    lli invFact[Size];
    lli FastPowerCalc(lli a, lli n, lli mod)
    {
        if (n == 0)
            return 1;
        lli ret = FastPowerCalc(a, n / 2, mod);
        ret = (ret * ret) % mod;
        if (n % 2 == 1)
            ret = (ret * a) % mod;
        return ret;
    }
    lli ModularInverseFast(lli n, lli mod)
    {
        return FastPowerCalc(n, (mod - 2), mod);
    }
    void PreCalc(lli n, lli mod)
    {
        Fact[0] = invFact[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            Fact[i] = (Fact[i - 1] * i) % mod;
            invFact[i] = ModularInverseFast(Fact[i], mod);
        }
    }
    /* Answer per query in O (1)*/
    lli nCr(lli n, lli r, lli mod)
    {
        lli Up = Fact[n];
        lli Down1 = invFact[r];
        lli Down2 = invFact[n - r];
        lli ret = (Up * Down1) % mod;
        ret = (ret * Down2) % mod;
        return ret;
    }
    // Answer per query in O (1)
    lli nPr(lli n, lli r, lli mod)
    {
        lli Up = Fact[n];
        lli Down1 = invFact[n - r];
        lli ret = (Up * Down1) % mod;
        return ret;
    }
};

/**************************************************************/

class TrailingZeroesInBaseBOfN_factorial
{
    int findPowerOfP(int N, int p)
    {
        int count = 0;
        for (int r = p; r <= N; r *= p)
            count += floor(N / r);
        return count;
    }
    vector<pair<int, int>> primeFactorsofB(int base)
    {
        vector<pair<int, int>> ans;
        for (int i = 2; i * i <= base; i++)
        {
            if (base % i == 0)
            {
                int count = 0;
                while (base % i == 0)
                {
                    base = base / i;
                    count++;
                }
                ans.push_back(make_pair(i, count));
            }
        }
        if (base > 1)
            ans.push_back(make_pair(base, 1));
        return ans;
    }
    int largestPowerOfB(int N, int base)
    {
        int ans = INT_MAX;
        for (auto it : primeFactorsofB(base))
            ans = min(ans, (findPowerOfP(N, it.first) / it.second));
        return ans;
    }
};

/**************************************************************/

class SamllestNumberWithAlLeastNTrilingZeroesInFactorial
{
    bool check(int p, int n)
    {
        int count = 0;
        for (int f = 5; f <= p; f *= 5)
            count += floor(p / f);
        return (count >= n);
    }
    int findNum_with_binary_search(int n)
    {
        if (n == 1)
            return 5;
        int low = 0, high = 5 * n, mid;
        while (low < high)
        {
            mid = (low + high) >> 1;
            if (check(mid, n))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};

/**************************************************************/

class getTrailing0InFactorial_
{
    /* Count number of trailing zeros in n! */
    ull getTrailing0InFactorial(ull num)
    {
        if (num < 0)
            return -1;
        ull count = 0;
        for (ull i = 5; (num / i) > 0; i = i * 5)
            count = count + num / i;
        return count;
    }
};

/**************************************************************/

/* Count number of trailing zeros in (1^1)*(2^2)*(3^3)*(4^4) */
class trailing_zeros_
{
    int trailing_zeros(int N)
    {
        int count_of_two = 0, count_of_five = 0;
        for (int i = 1, val; i <= N; i++)
        {
            for (val = i; val % 2 == 0 && val > 0; count_of_two += i)
                val /= 2;
            for (; val % 5 == 0 && val > 0; count_of_five += i)
                val /= 5;
        }
        return min(count_of_two, count_of_five);
    }
};

/**************************************************************/

void findDivisors(int n)
{
    int div[n + 1];
    memset(div, 0, sizeof div);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * i <= n; j++)
            div[i * j]++;
    }
    for (int i = 1; i <= n; i++)
        cout << div[i] << " ";
}

/**************************************************************/

class PrimeThings
{
#define Size 10000000
    typedef long long lli;
    vector<unsigned> pri((Size >> 6) + 5), prime;
#define setBits(n) (pri[n >> 6] |= (1 << ((n >> 1) & 31)))
#define checkBit(n) (pri[n >> 6] & (1 << ((n >> 1) & 31)))
#define isP(n) ((n == 2) || (n > 1 && (n & 1) && !checkBit(n)))
    void seive()
    {
        unsigned i, j;
        for (i = 3; i * i <= Size; i += 2)
            if (!checkBit(i))
            {
                for (j = i * i; j < Size; j += (i << 1))
                    setBits(j);
            }
        prime.push_back(2);
        for (i = 3; i < Size; i += 2)
            if (!checkBit(i))
                prime.push_back(i);
    }
    long long phi[Size + 10];
    void computeTotient()
    {
        for (lli i = 1; i < Size; i++)
            phi[i] = i;
        for (lli p = 2; p < Size; p++)
        {
            if (phi[p] == p)
            {
                phi[p] = p - 1;
                for (lli i = 2 * p; i < Size; i += p)
                {
                    phi[i] = (phi[i] / p) * (p - 1);
                }
            }
        }
    }
    int primeDivisor(int num)
    {
        if (num < Size && isP(num))
            return 2;
        int ans = 1, coun, i, x = 2;
        for (i = 0; x * x <= num; x = prime[++i])
            if (num % x == 0)
            {
                coun = 1;
                while (!(num % x))
                {
                    num /= x;
                    coun++;
                }
                ans *= coun;
            }
        if (num > 1)
            ans <<= 1;
        return ans;
    }
    /**************************************************************/
    long long big_pow_mod(long long base, long long po, long long mod)
    {
        long long ans = 1;
        while (po > 0)
        {
            if (po & 1)
                ans = (ans * base) % mod;
            base = (base * base) % mod;
            po >>= 1;
        }
        return ans % mod;
    }
    bool miillerTest(int d, int n)
    {
        int a = 2 + rand() % (n - 4);
        int x = big_pow_mod(a, d, n);
        if (x == 1 || x == n - 1)
            return true;
        while (d != n - 1)
        {
            x = (x * x) % n;
            d *= 2;
            if (x == 1)
                return false;
            if (x == n - 1)
                return true;
        }
        return false;
    }
    bool isPrime(int n)
    {
        if (n < 5)
        {
            return n == 2 || n == 3;
        }
        int d = n - 1;
        while (d % 2 == 0)
            d /= 2;
        int k = 18; /// high number miens high accuracy
        for (int i = 0; i < k; i++)
            if (miillerTest(d, n) == false)
                return false;
        return true;
    }
};

/**************************************************************/

/// this mathod is much faster then my approche
class fast_factorial
{
    int factorial(int n, char fact[])
    {
        int i, j, m, temp, x;
        fact[0] = 1;
        m = 1;
        temp = 0;
        for (i = 1; i <= n; i++)
        {
            for (j = 0; j < m; j++)
            {
                x = fact[j] * i + temp;
                fact[j] = x % 10;
                temp = x / 10;
            }
            while (temp > 0)
            {
                fact[m] = temp % 10;
                temp = temp / 10;
                m++;
            }
        }
        reverse(fact, fact + m);
        return m; /* m is the number of factorial */
    }
};

/**************************************************************/

class string_add_mult
{
    string addition(string &value1, string &value2)
    {
        string x;
        int len, top_len, sum = 0;
        top_len = value1.size();
        len = value2.size();
        if (top_len < len)
        {
            swap(value1, value2);
            swap(len, top_len);
        }
        for (int i = top_len - 1, k = len - 1; i >= 0; i--, k--)
        {
            if (k < 0)
                sum += (value1[i] - 48);
            else
                sum += ((value1[i] - 48) + (value2[k] - 48));
            x += (sum % 10) + 48;
            sum /= 10;
        }
        if (sum > 0)
            x += (sum + 48);
        reverse(x.begin(), x.end());
        return x;
    }
    /**************************************************************/
    string multiply(string &value1, string &value2)
    {
        string temp = "";
        vector<string> sum;
        reverse(value1.begin(), value1.end());
        reverse(value2.begin(), value2.end());
        while (value1.back() == '0')
            value1.pop_back();
        while (value2.back() == '0')
            value2.pop_back();
        if (value1.size() == 0 || value2.size() == 0)
            return "0";
        int space = 0;
        for (auto val1 : value1)
        {
            sum.push_back(temp);
            int mult = space;
            while (mult--)
                sum.back() += "0";
            val1 -= '0';
            mult = 0;
            for (auto it : value2)
            {
                it -= '0';
                mult += (val1 * it);
                sum.back() += ((mult % 10) + '0');
                mult /= 10;
            }
            if (mult > 0)
            {
                sum.back() += ((mult % 10) + '0');
            }
            reverse(sum.back().begin(), sum.back().end());
            space++;
        }
        string ans = "";
        for (auto it : sum)
            ans = addition(it, ans);
        return ans;
    }
};

/**************************************************************/

class Permutation
{
    vector<vector<string>> ans;
    void Generate(vector<string> &number, int pos)
    {
        vector<string> temp;
        ans.push_back(temp);
        if (pos < 0)
        {
            ans[0] = number;
            return;
        }
        for (auto item : number)
        {
            for (auto it : ans[pos])
            {
                ans.back().push_back(item + it);
            }
        }
    }
    void genaretAllPurmutation(vector<string> &number, int length)
    { /// O( (number.size)^(length) )
        for (int i = 0; i < length; i++)
        {
            Generate(number, i - 1);
        }
        /// show all number
        for (auto arr : ans)
        {
            for (auto it : arr)
                cout << it << endl;
            puts("");
        }
    }
};

/**************************************************************/

void SlidingWindow(int arr[], int n, int k)
{
    deque<int> Qi;
    int i;
    for (i = 0; i < k; ++i)
    {
        cout << arr[i] << ' ';
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
        {
            cout << arr[Qi.back()] << ' ';
            Qi.pop_back();
        }
        cout << endl;
        Qi.push_back(i);
    }
    cout << "now " << Qi.back() << endl;
    for (i = k; i < n; ++i)
    {
        cout << arr[Qi.front()] << " ";
        while ((!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front();
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }
    cout << arr[Qi.front()];
}

/**************************************************************/

class store_string_by_matching
{
    struct node
    {
        node *NOD[26];
        int ending;
        node()
        {
            for (int i = 0; i < 27; i++)
                NOD[i] = NULL;
            ending = 0;
        }
    };
    node *root = new node();
    void add(string &str)
    {
        node *current = root;
        for (auto c : str)
        {
            c -= 'a';
            if (current->NOD[c] == NULL)
                current->NOD[c] = new node();
            current = current->NOD[c];
        }
        current->ending++;
    }
    int is_valid(string &str)
    {
        node *current = root;
        for (auto c : str)
        {
            c -= 'a';
            if (current->NOD[c] == NULL)
                return 0;
            current = current->NOD[c];
        }
        return current->ending;
    }
};

/**************************************************************/

class longestPalindromicSubstr_
{
    void printSubStr(char *str, int low, int high)
    {
        printf("Longest palindrome substring is: ");
        for (int i = low; i <= high; ++i)
            printf("%c", str[i]);
    }
    int longestPalindromicSubstr(char *str)
    {
        int maxLength = 1;
        int start = 0;
        int len = strlen(str);
        int low, high;
        for (int i = 1; i < len; ++i)
        {
            low = i - 1;
            high = i;
            while (low >= 0 && high < len && str[low] == str[high])
            {
                if (high - low + 1 > maxLength)
                {
                    start = low;
                    maxLength = high - low + 1;
                }
                --low;
                ++high;
            }
            low = i - 1;
            high = i + 1;
            while (low >= 0 && high < len && str[low] == str[high])
            {
                if (high - low + 1 > maxLength)
                {
                    start = low;
                    maxLength = high - low + 1;
                }
                --low;
                ++high;
            }
        }
        printSubStr(str, start, start + maxLength - 1);
        return maxLength;
    }
};

/**************************************************************/

class BIT_
{
    int getNext(int index)
    {
        return index + (index & -index);
    }
    int getParent(int index)
    {
        return index - (index & -index);
    }
    int tree[Size + 1], N;
    void updateBIT(int val, int index)
    {
        while (index <= N)
        {
            tree[index] += val;
            index = getNext(index);
        }
    }
    int getSum(int index)
    {
        //index++; this index is 1 base
        int sum = 0;
        while (index > 0)
        {
            sum += tree[index];
            index = getParent(index);
        }
        return sum;
    }
    void bild(int input[])
    {
        for (int i = 1; i <= N; i++)
            updateBIT(input[i - 1], i);
    }
};

/**************************************************************/

class square_root_decomposition
{
    // square root decomposition
    int arr[10000];
    vector<int> block;
    int blk_sz;
    void update(int idx, int val)
    {
        int blockNumber = idx / blk_sz;
        block[blockNumber] += val - arr[idx];
        arr[idx] = val;
    }
    int query(int l, int r)
    {
        int sum = 0;
        for (; l < r and l % blk_sz != 0 and l != 0; l++)
        {
            sum += arr[l];
        }
        for (; l + blk_sz <= r; l += blk_sz)
        {
            sum += block[l / blk_sz];
        }
        for (; l <= r; l++)
        {
            sum += arr[l];
        }
        return sum;
    }
    void construct(int input[], int n)
    {
        int blk_idx = -1;
        blk_sz = sqrt(n);
        block.resize(blk_sz + 1);
        for (int i = 0; i < n; i++)
        {
            arr[i] = input[i];
            block[i / blk_sz] += input[i];
        }
    }
};

/**************************************************************/

/// MO’s Algorithm (Query Square Root Decomposition)
class MOsAlgorithm
{
    struct node
    {
        int left, right, blk, pos, sum;
    };
    int block;
    int arr[10000];
    vector<node> query;
    bool compare(node x, node y)
    {
        if (x.left / block != y.left / block)
            return x.left / block < y.left / block;
        return x.right < y.right;
    }
    bool arrange(node &x, node &y)
    {
        return x.pos < y.pos;
    }
    void queryResults(int a[], int n, int m)
    {
        // Find block size
        block = (int)sqrt(n);
        sort(query.begin(), query.end(), compare);
        // Initialize current L, current R and current sum
        int currL = 0, currR = 0, left, right;
        int currSum = 0;
        // Traverse through all queries
        for (int i = 0; i < m; i++)
        {
            // L and R values of current range
            left = query[i].left;
            right = query[i].right;
            // Remove extra elements of previous range. For
            // example if previous range is [0, 3] and current
            // range is [2, 5], then a[0] and a[1] are subtracted
            for (; currL < left; currL++)
                currSum -= arr[currL];
            // Add Elements of current Range
            for (; currL > left; currL--)
                currSum += arr[currL - 1];
            for (; currR <= right; currR++)
                currSum += arr[currR];
            // Remove elements of previous range. For example
            // when previous range is [0, 10] and current range
            // is [3, 8], then a[9] and a[10] are subtracted
            for (; currR > right + 1; currR--)
                currSum -= arr[currR - 1];
            // Print sum of current range
            query[i].sum = currSum;
        }
        sort(query.begin(), query.end(), arrange);
        for (auto it : query)
        {
            printf("%d\n", it.sum);
        }
    }
};
/************************************************************************************************ DP or recursion  ************************************************************************************************/

class findMinRange_
{

    int findMinRange(int arr[], int size, int sumCalculate, int sumTotal)
    {
        if (size == 0)
            return abs((sumTotal - sumCalculate) - sumCalculate);
        return min(findMinRange(arr, size - 1, sumCalculate + arr[size - 1], sumTotal), findMinRange(arr, size - 1, sumCalculate, sumTotal));
    }
};

/**************************************************************/

class minSumMidValu_
{
    /// Partition a set into two subsets such that the difference of subset sums is minimum
    int minSumMidValu(int arr[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        bool dynamic[n + 1][sum + 1];
        memset(dynamic, 0, sizeof(dynamic));
        for (int i = 0; i <= n; i++)
            dynamic[i][0] = true;
        for (int i = 1; i <= sum; i++)
            dynamic[0][i] = false;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                dynamic[i][j] = dynamic[i - 1][j];
                if (arr[i - 1] <= j)
                {
                    dynamic[i][j] |= dynamic[i - 1][j - arr[i - 1]];
                }
            }
        }
        for (int j = sum / 2; j >= 0; j--)
        {
            if (dynamic[n][j] == true)
            {
                return sum - 2 * j;
            }
        }
        return INT_MAX;
    }
};

/**************************************************************/

class minmumSubsetSum_
{
    bool minmumSubsetSum(int arr[], int numberOfElement, int value)
    {
        sort(arr, arr + numberOfElement);
        reverse(arr, arr + numberOfElement); // if remove this line that can be Maximum Subset Sum
        bool table[numberOfElement + 1][value + 1];
        for (int i = 0; i < numberOfElement; i++)
        {
            table[i][0] = true;
        }
        for (int i = 1; i <= value; i++)
        {
            table[0][i] = false;
        }
        table[0][arr[0]] = true;
        puts("come");
        for (int i = 1; i < numberOfElement; i++)
        {
            for (int j = 1; j <= value; j++)
            {
                if (j < arr[i])
                {
                    table[i][j] = table[i - 1][j];
                }
                else
                {
                    if (table[i - 1][j] == true || table[i - 1][j - arr[i]] == true)
                    {
                        table[i][j] = true;
                    }
                    else
                    {
                        table[i][j] = false;
                    }
                }
            }
        }

        vector<int> subset;
        for (int i = numberOfElement - 1, j = value; i >= 0 && j > 0;)
        {
            if (table[i - 1][j] == false)
            {
                subset.push_back(arr[i]);
                j = j - arr[i];
                i--;
            }
            else
            {
                i--;
            }
        }
        for (auto it : subset)
        {
            cout << it << " ";
        }
        puts("");
        return table[numberOfElement - 1][value];
    }
};

/**************************************************************/

class matrixSum
{
public:
    typedef long long int lli;
    vector<vector<lli>> matrix, aux;
    void init(int N, int M)
    {
        aux.resize(N);
        matrix.resize(N);
        for (int i = 0; i < N; i++)
        {
            aux[i].resize(M);
            matrix[i].resize(M);
        }
    }
    int preProcess()
    {
        int N = matrix.size(), M = matrix[0].size();
        for (int i = 0; i < N; i++)
            aux[0][i] = matrix[0][i];
        for (int i = 1; i < M; i++)
            for (int j = 0; j < N; j++)
                aux[i][j] = matrix[i][j] + aux[i - 1][j];
        for (int i = 0; i < M; i++)
            for (int j = 1; j < N; j++)
                aux[i][j] += aux[i][j - 1];
    }
    int sumQuery(int tli, int tlj, int rbi, int rbj)
    {
        int res = aux[rbi][rbj];
        if (tli > 0)
            res = res - aux[tli - 1][rbj];
        if (tlj > 0)
            res = res - aux[rbi][tlj - 1];
        if (tli > 0 && tlj > 0)
            res = res + aux[tli - 1][tlj - 1];
        return res;
    }
};

/**************************************************************/

class MinimumCoinChange_
{
    int minimumCoinChange(int coin[], int numberOfCoin, int value)
    {
        sort(coin, coin + numberOfCoin);
        int INF = 99999, lim = 10000;
        int table[numberOfCoin + 1][value + 1];
        for (int i = 0; i < numberOfCoin; i++)
            table[i][0] = 0;
        for (int i = 1; i <= value; i++)
        {
            if (i % coin[0] == 0)
                table[0][i] = i / coin[0];
            else
                table[0][i] = INF;
        }
        table[0][coin[0]] = 1;
        for (int i = 1; i < numberOfCoin; i++)
        {
            for (int j = 1; j <= value; j++)
            {
                if (j < coin[i])
                    table[i][j] = table[i - 1][j];
                else
                {
                    if ((table[i][j - coin[i]]) < lim && (table[i][j - coin[i]]) > -lim)
                        table[i][j] = min(table[i - 1][j], 1 + (table[i][j - coin[i]]));
                    else
                        table[i][j] = table[i - 1][j];
                }
            }
        }
        vector<int> subset;
        for (int i = numberOfCoin - 1, j = value; i >= 0 && j > 0;)
        {
            if (table[i][j] != table[i - 1][j])
            {
                subset.push_back(coin[i]);
                j = j - coin[i];
            }
            else
                i--;
        }
        for (auto it : subset)
            cout << it << " ";
        puts("");
        return table[numberOfCoin - 1][value];
    }
};

/**************************************************************/

class MinimumCoinChange_rec
{
#define Size 3
    int arr[] = {3, 2, 1};
    int dp[8000][Size + 1];
    int call(int n, int j)
    {
        if (n == 0)
            return 1;
        if (dp[n][j] != 0)
            return dp[n][j];
        int ans = 0;
        for (int i = j; i < Size; i++)
            if (n - arr[i] >= 0)
                ans += call(n - arr[i], i);
        return dp[n][j] = ans;
    }
};

/**************************************************************/

class combination_
{
    void combination(int arr[], int temp[], int start, int End, int index, int r)
    {
        if (index == r)
        {
            for (int j = 0; j < r; j++)
                printf("%d ", temp[j]);
            printf("\n");
            return;
        }
        for (int i = start; i <= End && End - i + 1 >= r - index; i++)
        {
            temp[index] = arr[i];
            combination(arr, temp, i + 1, End, index + 1, r);
        }
    }
    /// combination(arr, temp, 0, n-1, 0, r);
};

/**************************************************************/

class heapPermutation_
{
    void heapPermutation(string &str, int N, int n)
    {
        if (N == 1)
        {
            cout << str << endl;
            return;
        }
        for (int i = 0; i < N; i++)
        {
            heapPermutation(str, N - 1, n);
            if (N & 1)
                swap(str[0], str[N - 1]);
            else
                swap(str[i], str[N - 1]);
        }
    } /// heapPermutation(str, str.size(), str.size());
};

/**************************************************************/

void printPowerSet(char *set, int set_size)
{
    /*set_size of power set of a set with set_size 
    n is (2**n -1)*/
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;

    /*Run from counter 000..0 to 111..1*/
    for (counter = 0; counter < pow_set_size; counter++)
    {
        for (j = 0; j < set_size; j++)
        {
            /* Check if jth bit in the counter is set 
            If set then print jth element from set */
            if (counter & (1 << j))
                cout << set[j];
        }
        cout << endl;
    }
}

/**************************************************************/

class Permutation
{
    vector<int> number, temp;
    vector<bool> mark;

public:
    int start;
    void add(int x)
    {
        number.push_back(x);
    }
    void permutation(int x, int n)
    {
        if (x == n)
        {
            for (int i = start; i < n; i++)
                printf("%d ", temp[i]);
            cout << endl;
            return;
        }
        for (int i = 0; i < n; i++)
            if (!mark[i])
            {
                mark[i] = 1;
                temp[x] = number[i];
                permutation(x + 1, n);
                mark[i] = 0;
            }
    }
    void run()
    {
        mark.resize(20);
        fill(mark.begin(), mark.end(), 0);
        start = 0;
        start = min(start, int(number.size()));
        temp = number;
        permutation(start, number.size());
    }
};

/**************************************************************/

class KMP_
{
    int KMP(string &text, string &pattern)
    {
        /// string find;
        int i, j, len, len1;
        len = pattern.size();
        len1 = text.size();
        if (len > len1)
            return -1;
        vector<int> temp(len);
        for (i = 1, j = 0, temp[0] = 0; i < len;)
        {
            // if index i and index j is same then increment i & j;
            if (pattern[i] == pattern[j])
                temp[i++] = ++j;
            // if j is in index 0 then forward i;
            else if (j == 0)
                temp[i++] = 0;
            // if index i and index j is not same then decrement j;
            else
                j = temp[j - 1];
        }
        for (i = 0, j = 0; i < len1 && j < len;)
        {
            if (pattern[j] == text[i])
            {
                i++, j++; // flow past loop commend;
            }
            else if (j == 0)
                i++;
            else
                j = temp[j - 1];
        }
        if (j == len)
            return i - len;
        return -1;
    }
};

/**************************************************************/

class longestCommonSubsequnce_
{
    string longestCommonSubsequnce(string &str, string &sub)
    {
        /// Longest common subsequence.
        int len, len1, i, j;
        len = str.size();
        len1 = sub.size();
        int ans[len1 + 5][len + 5];
        for (i = 0; (i <= len || i <= len1); i++)
        {
            if (i <= len)
                ans[0][i] = 0;
            if (i <= len1)
                ans[i][0] = 0;
        }
        for (i = 0; i < len1; i++)
        {
            for (j = 0; j < len; j++)
            {
                if (sub[i] == str[j])
                {
                    ans[i + 1][j + 1] = ans[i][j] + 1;
                }
                else
                {
                    ans[i + 1][j + 1] = max(ans[i + 1][j], ans[i][j + 1]);
                }
            }
        }
        cout << ans[len1][len] << endl;
        //for(i=0; i<=len1; i++) {for(j=0; j<=len; j++)printf("%d ", ans[i][j]);puts("");}
        sub.clear();
        while (len != 0 && len1 != 0)
        {
            i = ans[len1][len - 1];
            j = ans[len1 - 1][len];
            if ((i == j) && (ans[len1 - 1][len - 1] < ans[len1][len]))
            {
                sub += str[len - 1];
                len1--;
                len--;
            }
            else if (i == ans[len1][len])
                len--;
            else
                len1--;
        }
        reverse(sub.begin(), sub.end());
        return sub;
    }
};

/**************************************************************/

class longestCommonPattern_
{
    int longestCommonPattern(char *str)
    {
        int n = strlen(str);
        int L[n][n], i, j, cl;
        for (i = 0; i < n; i++)
            L[i][i] = 1;
        for (cl = 2; cl <= n; cl++)
        {
            for (i = 0; i < n - cl + 1; i++)
            {
                j = i + cl - 1;
                if (str[i] == str[j] && cl == 2)
                    L[i][j] = 2;
                else if (str[i] == str[j])
                    L[i][j] = L[i + 1][j - 1] + 2;
                else
                    L[i][j] = max(L[i][j - 1], L[i + 1][j]);
            }
        }
        return L[0][n - 1];
    }
};

/**************************************************************/

class longestPalindromicSubsequnce_
{
    int L[Size][Size];
    int longestPalindromicSubsequnce(string &str)
    {
        int n = str.size();
        int i, j, cl;
        memset(L, 0, sizeof(L));
        for (i = 0; i < n; i++)
            L[i][i] = 1;

        for (cl = 2; cl <= n; cl++)
        {
            for (i = 0; i < n - cl + 1; i++)
            {
                j = i + cl - 1;
                if (str[i] == str[j] && cl == 2)
                    L[i][j] = 2;
                else if (str[i] == str[j])
                    L[i][j] = L[i + 1][j - 1] + 2;
                else
                    L[i][j] = max(L[i][j - 1], L[i + 1][j]);
            }
        }
        return L[0][n - 1];
    }
};

/**************************************************************/

class mergeSort_
{
    void Merge(int A[], int p, int q, int r)
    {
        int n1 = q - p + 1;
        int n2 = r - q;
        int L[n1 + 1], R[n2 + 1];
        int i, j, k;
        for (i = 0; i < n1; i++)
            L[i] = A[p + i];
        for (j = 0; j < n2; j++)
            R[j] = A[q + j + 1];
        L[n1] = INT_MAX;
        R[n2] = INT_MAX;
        for (i = 0, j = 0, k = p; k <= r; k++)
        {
            if (L[i] <= R[j])
            {
                A[k] = L[i];
                i++;
            }
            else
            {
                A[k] = R[j];
                j++;
            }
        }
    }
    /// call by (array, 0, Size-1)
    void mergeSort(int A[], int p, int r)
    {
        if (p < r)
        {
            int q = (p + r) / 2;
            mergeSort(A, p, q);
            mergeSort(A, q + 1, r);
            Merge(A, p, q, r);
        }
    }
};

/************************************************************************************************ Tree  ************************************************************************************************/
/// segment tree.
class segmentTree_
{
    vector<int> segmentTree, lazy;
    void updateSegmentTreeRangeLazy(int q_low, int q_high, int delta, int start, int End, int pos)
    {
        if (start > End)
            return;
        //make sure all propagation is done at pos. If not update tree
        //at pos and mark its children for lazy propagation.
        int left = pos * 2 + 1;
        int right = pos * 2 + 2;
        if (lazy[pos] != 0)
        {
            segmentTree[pos] += (End - start + 1) * lazy[pos];
            if (start != End)
            {
                //not a leaf node
                lazy[left] += lazy[pos];
                lazy[right] += lazy[pos];
            }
            lazy[pos] = 0;
        }
        //no overlap condition
        if (q_low > End || q_high < start)
            return;
        //total overlap condition
        if (q_low <= start && q_high >= End)
        {
            segmentTree[pos] += delta;
            if (start != End)
            {
                lazy[left] += delta;
                lazy[right] += delta;
            }
            return;
        }
        //otherwise partial overlap so look both left and right.
        int mid = (start + End) / 2;
        updateSegmentTreeRangeLazy(q_low, q_high, delta, start, mid, left);
        updateSegmentTreeRangeLazy(q_low, q_high, delta, mid + 1, End, right);
    }

    int rangeMinimumQueryLazy(int q_low, int q_high, int start, int End, int pos)
    {
        if (start > End)
            return 0;
        //make sure all propagation is done at pos. If not update tree
        //at pos and mark its children for lazy propagation.
        int left = pos * 2 + 1;
        int right = pos * 2 + 2;
        if (lazy[pos] != 0)
        {
            segmentTree[pos] += (End - start + 1) * lazy[pos];
            if (start != End)
            {
                //not a leaf node
                lazy[left] += lazy[pos];
                lazy[right] += lazy[pos];
            }
            lazy[pos] = 0;
        }
        //no overlap
        if (q_low > End || q_high < start)
            return 0;
        //total overlap
        if (q_low <= start && q_high >= End)
        {
            return segmentTree[pos];
        }
        //partial overlap
        int mid = (start + End) / 2;
        return rangeMinimumQueryLazy(q_low, q_high, start, mid, left) + rangeMinimumQueryLazy(q_low, q_high, mid + 1, End, right);
    }

    void constructSTUtil(int input[], int start, int End, int pos)
    {
        if (start > End)
            return;
        if (start == End)
        {
            lazy[pos] = 0;
            segmentTree[pos] = input[start];
            return;
        }
        int left = pos * 2 + 1;
        int right = pos * 2 + 2;
        int mid = (start + End) / 2;
        constructSTUtil(input[], start, mid, left);
        constructSTUtil(input[], mid + 1, End, right);
        segmentTree[pos] = segmentTree[left] + segmentTree[right];
    }
    void updateRange(int n, int lo, int hi, int value)
    {
        updateSegmentTreeRangeLazy(lo, hi, value, 0, n - 1, 0);
    }
    int getSum(int n, int lo, int hi)
    {
        if (lo < 0 || hi > n - 1 || lo > hi)
            return -1;
        return rangeMinimumQueryLazy(lo, hi, 0, n - 1, 0);
    }
};

/**************************************************************/

class BalencedTree
{
    struct Node
    {
        int data;
        Node *left, *right;
    };

public:
    void storeBSTNodes(Node *root, vector<Node> &nodes)
    {
        if (root == NULL)
            return;

        storeBSTNodes(root->left, nodes);
        nodes.push_back(*(root));
        storeBSTNodes(root->left, nodes);
    }
    Node *buildTreeUtil(vector<Node> &nodes, int start, int end)
    {
        if (start > end)
            return NULL;
        int mid = (start + end) / 2;
        Node *root = &(nodes[mid]);
        root->left = buildTreeUtil(nodes, start, mid - 1);
        root->right = buildTreeUtil(nodes, mid + 1, end);

        return root;
    }
    Node *buildTree(Node *root)
    {
        vector<Node> nodes;
        storeBSTNodes(root, nodes);
        int n = nodes.size();
        return buildTreeUtil(nodes, 0, n - 1);
    }
    Node *newNode(int data)
    {
        Node *node = new Node;
        node->data = data;
        node->left = node->right = NULL;
        return (node);
    }
    void preOrder(Node *node)
    {
        if (node == NULL)
            return;
        printf("% d ", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
    int startHere()
    {
        Node *root = newNode(10);
        root->left = newNode(8);
        root->left->left = newNode(7);
        root->left->left->left = newNode(6);
        root->left->left->left->left = newNode(5);
        root = buildTree(root);
        printf("Preorder traversal of balanced BST is:");
        preOrder(root);
        return 0;
    }
};

/**************************************************************/
// Self Balancing BST. Thats fint how many smaller number are in right side of each number
class BalancingBST
{
    struct node
    {
        int key;
        struct node *left;
        struct node *right;
        int height;
        int size;
    };
    int max(int a, int b);
    int height(struct node *N)
    {
        if (N == NULL)
            return 0;
        return N->height;
    }
    int size(struct node *N)
    {
        if (N == NULL)
            return 0;
        return N->size;
    }
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    struct node *newNode(int key)
    {
        struct node *node = (struct node *)
            malloc(sizeof(struct node));
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
        node->size = 1;
        return (node);
    }
    struct node *rightRotate(struct node *y)
    {
        struct node *x = y->left;
        struct node *T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->size = size(y->left) + size(y->right) + 1;
        x->size = size(x->left) + size(x->right) + 1;
        return x;
    }
    struct node *leftRotate(struct node *x)
    {
        struct node *y = x->right;
        struct node *T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->size = size(x->left) + size(x->right) + 1;
        y->size = size(y->left) + size(y->right) + 1;
        return y;
    }
    int getBalance(struct node *N)
    {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }
    struct node *insert(struct node *node, int key, int *count)
    {
        if (node == NULL)
            return (newNode(key));

        if (key < node->key)
            node->left = insert(node->left, key, count);
        else
        {
            node->right = insert(node->right, key, count);
            *count = *count + size(node->left) + 1;
        }
        node->height = max(height(node->left), height(node->right)) + 1;
        node->size = size(node->left) + size(node->right) + 1;
        int balance = getBalance(node);
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    /// arr is main array and countSmaller is answer array
    void constructLowerArray(int arr[], int countSmaller[], int n)
    {
        int i, j;
        struct node *root = NULL;
        for (i = 0; i < n; i++)
            countSmaller[i] = 0;
        for (i = n - 1; i >= 0; i--)
        {
            root = insert(root, arr[i], &countSmaller[i]);
        }
    }
};

/************************************************************************************************ Graph  ************************************************************************************************/
/// DFS
class DFS
{
    vector<bool> mark;
    vector<vector<int>> graph;
    bool check;

    void dfs(int node)
    {
        mark[node] = true;
        for (auto it : graph[node])
            if (!mark[it])
                dfs(it);
    }
    bool cycle, reStack[Size];
    void directedCycle(int node)
    {
        if (cycle)
            return;
        mark[node] = true;
        reStack[node] = true;
        for (auto it : graph[node])
        {
            if (reStack[it] == true)
            {
                cycle = true;
                return;
            }
            else if (mark[it] == false)
                directedCycle(it);
        }
        reStack[node] = false;
    }

    void unDirectedCycle(int node, int parents)
    {
        if (cycle)
            return;
        mark[node] = true;
        for (auto it : graph[node])
        {
            if (it != parents && mark[it] == true)
            {
                cycle = true;
                return;
            }
            else if (!mark[it])
                unDirectedCycle(it, node);
        }
    }
    void call(int node)
    {
        fill(mark.begin(), mark.end(), false);
        for (int i = 0; i < node; i++)
            if (mark[i] == false)
                dfs(i);
        fill(mark.begin(), mark.end(), false);
        for (int i = 0; i < node; i++)
        {
            check = false;
            if (mark[i] == false)
            {
                directedCycle(i);
                if (check)
                {
                    cout << "Has cycle in node " << i << endl;
                }
            }
        }
    }
};

/**************************************************************/

class SCC
{
    stack<int> Stk;
    vector<bool> mark;
    vector<vector<int>> graph, component, graphRev;

public:
    void init(int Size)
    {
        graph.resize(Size + 1);
        mark.resize(Size + 1);
        graphRev.resize(Size + 1);
    }
    int numberOfComponent()
    {
        return component.size();
    }
    void add(int from, int to)
    {
        graph[from].push_back(to);
        graphRev[to].push_back(from);
    }
    void top_sort(int node)
    {
        mark[node] = true;
        for (auto v : graph[node])
            if (!mark[v])
                top_sort(v);
        Stk.push(node);
    }
    void dfs(int node)
    {
        mark[node] = true;
        for (auto v : graphRev[node])
            if (!mark[v])
                dfs(v);
        component.back().push_back(node);
    }
    void Strongly_Connected_Componant(int node)
    {
        fill(mark.begin(), mark.end(), false);
        for (int i = 0; i < node; i++)
            if (!mark[i])
                top_sort(i);
        vector<int> temp;
        component.clear();
        fill(mark.begin(), mark.end(), false);
        while (!Stk.empty())
        {
            if (!mark[Stk.top()])
            {
                component.push_back(temp);
                dfs(Stk.top());
            }
            Stk.pop();
        }
        for (auto comp : component)
        {
            for (auto it : comp)
                cout << it << " ";
            puts("");
        }
    }
};

/**************************************************************/

class tarjanArticulationPoint
{
    int time;
    vector<bool> mark;
    vector<int> point;
    vector<int> parents;
    vector<vector<int>> graph;
    vector<pair<int, int>> hiLowTime, articulationEdge;

public:
    void init(int Size)
    {
        time = 0;
        mark.resize(Size + 1);
        graph.resize(Size + 1);
        parents.resize(Size + 1);
        hiLowTime.resize(Size + 1);
    }
    void add(int from, int to)
    {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    void tarjan(int node)
    {
        mark[node] = true;
        hiLowTime[node] = make_pair(time, time);
        time++;
        int child = 0;
        bool isArticul = false;
        for (auto it : graph[node])
        {
            if (it == parents[node])
                continue;
            if (!mark[it])
            {
                child++;
                parents[it] = node;
                tarjan(it);
                if (hiLowTime[node].first <= hiLowTime[it].second)
                {
                    isArticul = true;
                }
                else
                {
                    hiLowTime[node].second = min(hiLowTime[node].second, hiLowTime[it].second);
                }
            }
            else
            {
                hiLowTime[node].second = min(hiLowTime[node].second, hiLowTime[it].first);
            }
        }
        if ((parents[node] == node && child >= 2) || (parents[node] != node && isArticul))
        {
            point.push_back(node);
        }
    }
    void call(int node)
    {
        point.clear();
        fill(mark.begin(), mark.end(), 0);
        for (int i = 0; i < node; i++)
            parents[i] = i;
        tarjan(3);
        for (auto it : point)
            cout << it << " ";
        puts("");
    }
};

/**************************************************************/

class BreadthFirstSearch
{
    vector<int> dis;
    vector<bool> mark;
    vector<vector<int>> graph;

public:
    void init(int Size)
    {
        graph.resize(Size + 1);
        mark.resize(Size + 1);
        dis.resize(Size + 1);
    }
    void add(int from, int to)
    {
        graph[from].push_back(to);
    }
    int distance(int node)
    {
        return dis[node];
    }
    int bfs(int source)
    {
        fill(dis.begin(), dis.end(), 0);
        queue<int> Que;
        mark[source] = true;
        Que.push(source);
        while (!Que.empty())
        {
            int current = Que.front();
            Que.pop();
            for (auto itr : graph[current])
            {
                if (mark[itr] == false)
                {
                    mark[itr] = true;
                    dis[itr] = dis[current] + 1;
                    Que.push(itr);
                }
            }
        }
    }
};

/**************************************************************/

class BellmanFord
{
#define Size 1000
    int dis[Size], parents[Size];
    bool relax(int u, int v, int w)
    {
        if (dis[v] > (w + dis[u]))
        {
            dis[v] = (w + dis[u]);
            parents[v] = u;
            return true;
        }
        return false;
    }
    bool bellman_ford(int source, vector<pair<pair<int, int>, int>> &graph, int V)
    {
        for (int i = 0; i <= V; i++)
        {
            dis[i] = 100;
            parents[i] = 0;
        }
        dis[source] = 0;
        bool check;
        for (int i = 0; i < (V - 1); i++)
        {
            for (auto it : graph)
            {
                check = relax(it.first.first, it.first.second, it.second);
            }
        }
        puts("");
        for (auto it : graph)
        {
            if (relax(it.first.first, it.first.second, it.second))
            {
                return false;
            }
        }
        return true;
    }
};

/**************************************************************/

class Dijkstra
{
private:
    int Size, source, MAXI, inc;
    bool RUN;
    vector<vector<pair<int, int>>> graph;
    vector<int> parents;
    vector<long long> distance;
    vector<bool> mark;

public:
    bool hasPath;
    void add(int from, int to, int weight)
    {
        graph[from].push_back(make_pair(weight, to));
    }
    vector<int> findPath(int dis)
    {
        vector<int> pathArray;
        if (RUN == false || dis == source)
        {
            return pathArray;
        }
        int past = dis;
        if (parents[past] == source)
            hasPath = true;
        pathArray.push_back(past);
        while (past != source && parents[past] != source)
        {
            past = parents[past];
            if (past < 0)
                break;
            pathArray.push_back(past);
        }
        if (parents[past] == source)
        {
            hasPath = true;
        }
        //puts("");
        pathArray.push_back(source);
        reverse(pathArray.begin(), pathArray.end());
        return pathArray;
    }
    void run(int S)
    {
        pair<long long, int> current;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;

        fill(mark.begin(), mark.end(), false);
        fill(distance.begin(), distance.end(), MAXI);
        fill(parents.begin(), parents.end(), -1);

        source = S;
        distance[source] = 0;
        Q.push(make_pair(0, source));
        while (!Q.empty())
        {
            current = Q.top();
            Q.pop();
            if (mark[current.second] == false)
            {
                for (auto now : graph[current.second])
                {
                    now.first += current.first;
                    if (distance[now.second] > now.first)
                    {
                        parents[now.second] = current.second;
                        distance[now.second] = now.first;
                        Q.push(now);
                    }
                }
            }
            mark[current.second] = true;
        }
        RUN = true;
        hasPath = false;
    }
    void showTheGroup()
    {
        int s = 1;
        for (auto it : graph)
        {
            printf("%d", s++);
            for (auto it1 : it)
            {
                printf(" -> (%d,%d)", it1.second + 1, it1.first + 1);
            }
            puts("");
        }
    }
    void Clear()
    {
        graph.clear();
        parents.clear();
        distance.clear();
        mark.clear();
    }
    void init(int s)
    {
        RUN = false, Size = s, MAXI = INT_MAX;
        graph.resize(Size);
        parents.resize(Size);
        distance.resize(Size);
        mark.resize(Size);
    }
};

/**************************************************************/

#define Size 105
struct edge
{
    int to, weight;
    edge(int a, int b) : to(a), weight(b) {}
};
vector<edge> graph[Size];
void spfa(int start, int n, vector<int> dis)
{
    int used[Size] = {};
    queue<int> Que;
    for (int i = 0; i < n; dis[i++] = INT_MAX)
        ;
    dis[start] = 0;
    Que.push(start);
    while (!Que.empty())
    {
        int tnt = Que.front();
        Que.pop();
        used[tnt] = 0;
        for (auto it : graph[tnt])
        {
            if (dis[it.to] > dis[tnt] + it.weight)
            {
                dis[it.to] = dis[tnt] + it.weight;
                if (used[it.to] == 0)
                {
                    used[it.to] = 1;
                    Que.push(it.to);
                }
            }
        }
    }
}
struct EEEE
{
    int node, g, h;
    EEEE(int a, int b, int c) : node(a), g(b), h(c) {}
    bool operator<(const EEEE &a) const
    {
        return g + h > a.g + a.h;
    }
};
void sol_kpath(int start, int _end, int k_th, int node)
{
    vector<int> dis(Size), cnt_kpath(Size), kpath(Size);
    spfa(_end, node, dis);
    for (int i = 0; i < node; cnt_kpath[i] = 0, kpath[i++] = -1)
        ;
    cnt_kpath[start] = 0;
    kpath[start] = -1;
    priority_queue<EEEE, vector<EEEE>> pQue;
    EEEE tnt(0, 0, 0);
    pQue.push(EEEE(start, 0, dis[start]));
    while (!pQue.empty())
    {
        tnt = pQue.top();
        pQue.pop();
        //printf("%d %d %d\n", tn.node, tn.g, tn.h);
        if (cnt_kpath[tnt.node] >= k_th || kpath[tnt.node] == tnt.g + tnt.h)
            continue;
        cnt_kpath[tnt.node]++;
        kpath[tnt.node] = tnt.g + tnt.h;
        if (tnt.node == _end && cnt_kpath[tnt.node] == k_th)
        {
            printf("%d\n", tnt.g);
            return;
        }
        for (auto it : graph[tnt.node])
        {
            pQue.push(EEEE(it.to, tnt.g + it.weight, dis[it.to]));
        }
    }
}

/**************************************************************/

vector<int> Path(int path[Size][Size], int node, int from, int to)
{
    vector<int> temp;
    temp.push_back(to);
    while ((to >= 0 && to < node) && path[from][to] != from)
    {
        temp.push_back(path[from][to]);
        to = path[from][to];
    }
    temp.push_back(from);
    reverse(temp.begin(), temp.end());
    return temp;
}
void FloydWarshall(int graph[Size][Size], int path[Size][Size], int node)
{
    for (int k = 0; k < node; k++)
        for (int i = 0; i < node; i++)
            for (int j = 0; j < node; j++)
            {
                if (graph[i][j] > graph[i][k] + graph[k][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    path[i][j] = path[k][j];
                }
            }
    vector<int> direction = Path(path, node, 2, 5);
    for (auto it : direction)
        cout << it << " ";
    puts("");
}

/**************************************************************/

int Min_vartex_cover(int node, int isGurd)
{
    if (dp[node][isGurd] != -1)
        return dp[node][isGurd];
    int sum = 0;
    for (auto v : graph[node])
    {
        if (v != parent[node])
        {
            parent[v] = node;
            if (isGurd == 0)
                sum += Min_vartex_cover(v, 1);
            else
                sum += min(Min_vartex_cover(v, 1), Min_vartex_cover(v, 0));
        }
    }
    return dp[node][isGurd] = sum + isGurd;
}

/**************************************************************/

class karuskalMST
{
    struct data
    {
        int x, y, w;
        bool operator<(const data &p) const
        {
            return w < p.w;
        }
    } temp;
    vector<int> mark;
    vector<data> graph, sTree;
    void init(int node)
    {
        mark.resize(node);
    }
    void add(int from, int to, int weight)
    {
        temp.x = from, temp.y = to, temp.w = weight;
        graph.push_back(temp);
    }
    int Find(int r)
    {
        if (mark[r] == r)
            return r;
        return mark[r] = Find(mark[r]);
    }
    int karuskal(int node)
    {
        int i, len, coun = 0, sum = 0, x, y, weight;
        sort(graph.begin(), graph.end());
        for (i = 0; i <= node; mark[i] = i, i++)
            ;

        for (auto it : graph)
        {
            x = Find(it.x);
            y = Find(it.y);
            if (x != y)
            {
                weight = it.w;
                mark[x] = y;
                coun++;
                sum += weight;
                temp.x = it.x, temp.y = it.y, temp.w = weight;
                sTree.push_back(temp);
                if (coun == node)
                    break;
            }
        }
        return sum;
    }
};

/**************************************************************/

int graph[100][100], parent[100], Node;
bool visit[100];
void primMST()
{
    int i, u, J, k, Min, key[Node + 5];
    for (i = 0; i <= Node; i++)
        key[i] = 99999;
    key[0] = key[1] = 0;
    parent[0] = parent[1] = -1;
    for (i = 1; i < Node; i++)
    {
        for (k = 1, Min = MAX; k <= Node; k++)
            if (visit[k] == false && key[k] < Min)
                Min = key[i], u = k;

        visit[u] = true;
        for (J = 1; J <= Node; J++)
            if (graph[u][J] > 0 && visit[J] == false && graph[u][J] < key[J])
                parent[J] = u, key[J] = graph[u][J];
    }
}

/**************************************************************/

class FordFulkerson
{
private:
    vector<vector<int>> graph;

public:
    bool BFS(vector<vector<int>> &residualCapacity, map<int, int> &parent, int source, int sink)
    {
        queue<int> Que;
        map<int, bool> visited;
        int node = residualCapacity.size();

        Que.push(source);
        visited[source] = true;
        while (!Que.empty())
        {
            int current = Que.front();
            Que.pop();
            for (int it = 0; it < node; it++)
            {
                if (visited[it] == false && residualCapacity[current][it] > 0)
                {
                    visited[it] = true;
                    parent[it] = current;
                    Que.push(it);
                    if (it == sink)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    int runMaxFlow(int source, int sink)
    {

        vector<vector<int>> residualCapacity;
        int node = graph.size();
        for (int i = 0; i < node; i++)
        {
            residualCapacity.push_back(vector<int>());
        }
        for (int i = 0; i < node; i++)
        {
            residualCapacity[i].resize(node);
            for (int j = 0; j < node; j++)
            {
                residualCapacity[i][j] = graph[i][j];
            }
        }

        int maxFlow = 0;
        map<int, int> parent;
        vector<int> augmentedPath;
        vector<vector<int>> augmentedPaths;

        while (BFS(residualCapacity, parent, source, sink))
        {
            augmentedPath.clear();
            int flow = INT_MAX;
            int v = sink;
            while (v != source)
            {
                augmentedPath.push_back(v);
                int u = parent[v];
                flow = min(flow, residualCapacity[u][v]);
                v = u;
            }
            augmentedPath.push_back(source);
            reverse(augmentedPath.begin(), augmentedPath.end());
            augmentedPaths.push_back(augmentedPath);

            maxFlow += flow;

            v = sink;
            while (v != source)
            {
                int u = parent[v];
                residualCapacity[u][v] -= flow;
                residualCapacity[v][u] += flow;
                v = u;
            }
        }
        print2D(augmentedPaths);
        return maxFlow;
    }
    void inputList()
    {
        int edge, u, v, w;
        cin >> edge;
        for (int i = 0; i < edge; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
        }
    }
    void inputMatrix(int node)
    {
        int w;
        for (int i = 0; i < node; i++)
        {
            for (int j = 0; j < node; j++)
            {
                scanf("%d", &graph[i][j]);
            }
        }
    }
    void print2D(vector<vector<int>> &vecInVec)
    {
        for (auto vec : vecInVec)
            print1D(vec);
        puts("");
    }
    void print1D(vector<int> &vec)
    {
        for (auto it : vec)
            cout << it << " ";
        cout << endl;
    }
    void initialization(int node)
    {
        graph.clear();
        for (int i = 0; i < node; i++)
        {
            graph.push_back(vector<int>());
        }
        for (int i = 0; i < node; i++)
        {
            graph[i].resize(node);
        }
    }
    void add(int u, int v, int weight)
    {
        graph[u][v] = weight;
    }
};

/************************************************************************************************ Calculator  ************************************************************************************************/

#define mod(a, b) a - (int)(a / b) * b
class Calculator
{
    bool is_number(char c)
    {
        return c >= '0' && c <= '9';
    }
    double calculate(double a, double b, char c)
    {
        if (c == '^')
            return pow(a, b);
        else if (c == '%')
        {
            if (b == 0)
                return a;
            return mod(a, b);
        }
        else if (c == '/')
        {
            if (b == 0)
                return 0;
            return a / b;
        }
        else if (c == '*')
            return a * b;
        else if (c == '+')
            return a + b;
        else if (c == '-')
            return a - b;
    }
    double to_number(string &s)
    {
        double sum = 0;
        for (auto it : s)
            sum = sum * 10 + (it - '0');
        return sum;
    }
    double postfix_to_cal(vector<string> &postfix)
    {
        stack<double> S;
        double a, b;
        char c;
        for (auto it : postfix)
        {
            if (is_number(it[0]))
                S.push(to_number(it));
            else
            {
                b = S.top();
                S.pop();
                a = S.top();
                S.pop();
                S.push(calculate(a, b, it[0]));
            }
        }
        return S.top();
    }
    vector<string> to_postfix(string &expre)
    {
        map<char, int> precidency;
        precidency['('] = 0;
        precidency['+'] = 1, precidency['-'] = 1;
        precidency['*'] = 2;
        precidency['/'] = 3;
        precidency['%'] = 4;
        precidency['^'] = 5;
        string temp = "(";
        int len = expre.size();
        for (int i = 0; i < len; i++)
        {
            if (expre[i] != ' ')
            {
                if (temp.back() == ')' && is_number(expre[i]))
                {
                    temp += "*";
                }
                else if (is_number(temp.back()) && expre[i] == '(')
                {
                    temp += "*";
                }
                temp += expre[i];
            }
        }
        expre = temp + ")";
        stack<char> Stk;
        len = expre.size();
        vector<string> postfix;
        for (int i = 0; i < len; i++)
        {
            if (is_number(expre[i]))
            {
                temp = "";
                for (; is_number(expre[i]); i++)
                {
                    temp += expre[i];
                }
                postfix.push_back(temp);
                i--;
            }
            else
            {
                char c = expre[i];
                if (c == '(')
                    Stk.push(c);
                else if (c == ')')
                {
                    while (Stk.top() != '(')
                    {
                        string temp = "";
                        temp += Stk.top();
                        postfix.push_back(temp);
                        Stk.pop();
                    }
                    Stk.pop();
                }
                else if (precidency[Stk.top()] < precidency[c])
                {
                    Stk.push(c);
                }
                else
                {
                    while (Stk.top() != '(' && precidency[Stk.top()] > precidency[c])
                    {
                        string temp = "";
                        temp += Stk.top();
                        postfix.push_back(temp);
                        Stk.pop();
                    }
                    Stk.push(c);
                }
            }
        }
        return postfix;
    }

public:
    double result(string &str)
    {
        return postfix_to_cal(to_postfix(str));
    }
};

/**************************************************************/

/**
    question:
        I want to sum of number a to b increment by x
    Answer:
        sum = ( x * (a + b) )/2
*/

/**
    question:
        give incremental value x, and number of increment 1 to N
        find the number of sum x to N increment by x
    Answer:
        P = (N/x)*x
        here P is the number of divisor in N
        sum = x*((P*(P+1))/2)
*/

/************************************************************************************************ Geometry  ************************************************************************************************/

typedef pair<int, int> pii;
class intersecPOINT
{ /// Intersection Of Two Straight Lines
private:
    int xx1, xx2, xx3, xx4, yy1, yy2, yy3, yy4;

public:
    bool Find(pii start1, pii End1, pii start2, pii End2)
    {
        xx1 = start1.first, yy1 = start1.second;
        xx2 = End1.first, yy2 = End1.second;

        xx3 = start2.first, yy3 = start2.second;
        xx4 = End2.first, yy4 = End2.second;
        return check();
    }
    bool under(int xx1, int xx2, double point)
    {
        if (xx1 > xx2)
            swap(xx1, xx2);
        //cout<<xx1<<" "<<xx2<<" "<<point<<endl;
        return point >= xx1 && point <= xx2;
    }
    bool check()
    {
        int aaa, bbb, eee, ccc, ddd, fff;
        aaa = -(yy1 - yy2);
        bbb = xx1 - xx2;
        eee = xx1 * yy2 - xx2 * yy1;
        ccc = -(yy3 - yy4);
        ddd = xx3 - xx4;
        fff = xx3 * yy4 - xx4 * yy3;
        double detA = aaa * ddd - bbb * ccc;
        if (detA != 0)
        {
            double x, y;
            x = (eee * ddd - bbb * fff) / detA;
            y = (aaa * fff - eee * ccc) / detA;
            //cout<<x<<" "<<y<<endl;
            return under(xx1, xx2, x) && under(xx3, xx4, x) && under(yy1, yy2, y) && under(yy3, yy4, y); /// if true thats mean two line intersection one other
        }
        else if (aaa * xx3 + bbb * yy3 - eee == 0)
            //puts("Same Line");
            return under(xx1, xx2, xx3) && under(yy1, yy2, yy3) && under(xx3, xx4, xx1) && under(yy3, yy4, yy1); /// if true thats mean two line cross one other
        else
            return false; //puts("No intersection");
    }
    bool solve()
    {

        pii start, End;
        pii leftTop, rightTop, rightButtom, leftButton;
        cin >> start.first >> start.second >> End.first >> End.second;
        cin >> leftTop.first >> leftTop.second >> rightButtom.first >> rightButtom.second;
        //scanf("%lld%lld%lld%lld", &start.first, &start.second, &End.first, &End.second);
        //scanf("%lld%lld%lld%lld", &leftTop.first, &leftTop.second, &rightButtom.first, &rightButtom.second);
        rightTop = make_pair(rightButtom.first, leftTop.second);
        leftButton = make_pair(leftTop.first, rightButtom.second);
        if (Find(start, End, leftTop, rightTop))
            return true;
        if (Find(start, End, rightTop, rightButtom))
            return true;
        if (Find(start, End, rightButtom, leftButton))
            return true;
        if (Find(start, End, leftButton, leftTop))
            return true;
        if (under(leftTop.first, rightButtom.first, start.first) && under(leftTop.second, rightButtom.second, start.second))
            return true;
        return false;
    }
};

/**************************************************************/

#define pi acos(-1)
#define fix(n) fixed << setprecision(n)
#define hulfParameterOfTriangle(a, b, c) (a + b + c) * 0.5 /// = S
#define areaOfCircle(r) (double)(r * r * pi)
#define areaOfTriangle(S, a, b, c) sqrt(S *(S - a) * (S - b) * (S - c))
#define outerCircleRadius(a, b, c) ((a * b * c) / (double)sqrt((a + b + c) * (a + b - c) * (a - b + c) * (-a + b + c)))
#define underCircleRadius(S, a, b, c) ((sqrt(S * (S - a) * (S - b) * (S - c))) / (double)S)

#define areaOfPolygon(n, S) ((S * S * n) / (4 * tan(pi / n))) /// S=side, n=number of side.

/*******************************  series sum *******************************/
/// 1^2+2^2+3^2+....+n^2
#define sum(num) ((num * (num + 1) * (2 * num + 1)) / 6);
