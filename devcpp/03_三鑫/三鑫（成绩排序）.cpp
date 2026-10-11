#include <bits/stdc++.h>
using namespace std;

int n;
struct student{
	string name;
	int grade;
}a[25];

bool cmt(student a, student b) {
	if(a.grade > b.grade) return true;
	if(a.grade < b.grade) return false;
	int len = min(a.name.size(), b.name.size());
	for (int i = 0; i < len; i++)
	    if(a.name[i] < b.name[i]) return true;
		else if(a.name[i] > b.name[i]) return false;
	return a.name.size() < b.name.size(); 
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
	 	cin >> a[i].name >> a[i].grade;
	sort(a + 1, a + n + 1, cmt);
	for (int i = 1; i <= n; i++)
	    cout << a[i].name << " " << a[i].grade << endl;
	return 0;
}
