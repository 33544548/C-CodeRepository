/*
题目描述
给定一个长度为s的符文串和一一个长度为p的符文串，定义符文的等级r(s,p)表示符文串s中最多有多少个互不重叠的子事p。
现在你可以在任意位置删除任意个符文。
你需要算出在删除i(0≤i≤|s|) 个符文后得到的符文串t;的r(t,p)。.
输入格式
从文件rune .in中读入数据。
第一行是符文串s。|
第二行是符文串p。
输出格式
输出到文件rune.out中。
输出(|s| + 1)个数,第i个数表示删除i - 1个符文后得到的符文串ti- 1的r(ti -1,p)。
样例
样例输入
axbaxxb .
ab
输出样例
0 1 1 2 1 1 0 0
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1000001, M = 2001;
int n, m;
int w[N], f[M][M];
char s[N], p[N];

int main()
{
	freopen("rune.in", "r", stdin);
	freopen("rune.out", "w", stdout);
	scanf("%s%s",s, p);
	n = strlen(s);
	m = strlen(p);
	for(int i=1; i<=n; i++){ 
		/*
			axbaxxb
			ab
			每次将文本串中的i开始， 与匹配串匹配
			若js比n小且已经完全匹配完匹配串
			则存在wi，使得文本串中i往后的子序列中存在匹配串p 
		*/
		int js = i-1;
		for(int j=0; j<m; j++){
			while(s[js] != p[j] && js <= n) js++;
			js++;
			if(js > n) break;//比n大则不存在 
		}
		if(js > n) w[i] = -1;
		else w[i] = js - i + 1;
	}
	memset(f, -127/3, sizeof(f));
	f[0][0] = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			f[i+1][j+1] = max(f[i+1][j+1], f[i][j]); //删除后不产生贡献
			f[i+1][j] = max(f[i+1][j], f[i][j]); //不删除不产生贡献
			int c = j + w[i+1] - m; //删除i到i+wi-1，即之前预处理的串中，除了匹配串p的所有字符
			if(w[i] != -1)
			f[i+w[i+1]][c] = max(f[i+w[i+1]][c], f[i][j] + 1);//删除后的i所在贡献等于当前贡献+1
		}
	}
	for(int i=0; i<=n; i++)
		printf("%d ", f[n][i]);
	cout << endl;

	return 0;
}

