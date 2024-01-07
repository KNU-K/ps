#include <iostream>
using namespace std;

bool is_visit[300002];
int arr[300002];
int N, L;

int getParent(int x) {
	if (x == arr[x]) return x;
	else return arr[x] = getParent(arr[x]);
}

void setUnion(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (!is_visit[a]) {
		//a 칸에 아직 술을 안 넣은 경우.
		arr[b] = a;
	}//넣었는지 안넣었는지 모르지만, 이건 메인 문에서 처리.
	else arr[a] = b;
}

int main()
{
     ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> L;

	for (int i = 1; i <= L; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		a = getParent(a);
		b = getParent(b);
		if (!is_visit[a]) {
			is_visit[a] = true;
			setUnion(a, b);
			cout << "LADICA\n";
		}
		else if (!is_visit[b]) {
			is_visit[b] = true;
			setUnion(a, b);
			cout << "LADICA\n";
		}
		else {
			setUnion(a, b);
			cout << "SMECE\n";
		}

	}

	return 0;
}