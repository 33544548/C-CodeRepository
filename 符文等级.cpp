/*
��Ŀ����
����һ������Ϊs�ķ��Ĵ���һһ������Ϊp�ķ��Ĵ���������ĵĵȼ�r(s,p)��ʾ���Ĵ�s������ж��ٸ������ص�������p��
���������������λ��ɾ����������ġ�
����Ҫ�����ɾ��i(0��i��|s|) �����ĺ�õ��ķ��Ĵ�t;��r(t,p)��.
�����ʽ
���ļ�rune .in�ж������ݡ�
��һ���Ƿ��Ĵ�s��|
�ڶ����Ƿ��Ĵ�p��
�����ʽ
������ļ�rune.out�С�
���(|s| + 1)����,��i������ʾɾ��i - 1�����ĺ�õ��ķ��Ĵ�ti- 1��r(ti -1,p)��
����
��������
axbaxxb .
ab
�������
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
			ÿ�ν��ı����е�i��ʼ�� ��ƥ�䴮ƥ��
			��js��nС���Ѿ���ȫƥ����ƥ�䴮
			�����wi��ʹ���ı�����i������������д���ƥ�䴮p 
		*/
		int js = i-1;
		for(int j=0; j<m; j++){
			while(s[js] != p[j] && js <= n) js++;
			js++;
			if(js > n) break;//��n���򲻴��� 
		}
		if(js > n) w[i] = -1;
		else w[i] = js - i + 1;
	}
	memset(f, -127/3, sizeof(f));
	f[0][0] = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			f[i+1][j+1] = max(f[i+1][j+1], f[i][j]); //ɾ���󲻲�������
			f[i+1][j] = max(f[i+1][j], f[i][j]); //��ɾ������������
			int c = j + w[i+1] - m; //ɾ��i��i+wi-1����֮ǰԤ����Ĵ��У�����ƥ�䴮p�������ַ�
			if(w[i] != -1)
			f[i+w[i+1]][c] = max(f[i+w[i+1]][c], f[i][j] + 1);//ɾ�����i���ڹ��׵��ڵ�ǰ����+1
		}
	}
	for(int i=0; i<=n; i++)
		printf("%d ", f[n][i]);
	cout << endl;

	return 0;
}

