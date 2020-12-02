//PREPEND BEGIN
#include <iostream>
using namespace std;
#define N_MAX 55
//PREPEND END

//TEMPLATE BEGIN

void reverse(char m[], char r[])
{
	int i = 0;
	for (i=0; m[i]; i++);
	r[i] = 0;
	for (int j=i-1; j>=0; j--) {
		r[j] = m[i-j-1];
	}

	// Parameter
	// m為原始字元陣列，r為reverse後的字元陣列

	// TODO
	// 將原始字元陣列reverse，以利運算時位數的對齊

	// Result
	// 即從r[0]開始的元素分別代表為個位數、十位數、百位數、...

}

void bigMoneyAdd(char m1[], char m2[], int sum[])
{
	// Parameters
	// m1為第一個大數，m2為第二個大數，sum為各位數相加後的int陣列

	// a, b 兩字元陣列分別為 m1, m2 reverse 過後的陣列
	char a[N_MAX]="", b[N_MAX]="";
	reverse(m1, a);
	reverse(m2, b);
	int carry = 0;
	char sum_reversed[N_MAX] = {0};
	for (int i=0; i<N_MAX; i++) {
		int da = 0, db = 0;
		if (a[i]) da = a[i]-'0';
		if (b[i]) db = b[i]-'0';
		sum_reversed[i] = (da + db + carry)%10 + '0';
		carry = (da + db + carry)/10;
	}
	char sum_char[N_MAX]="";
	reverse(sum_reversed, sum_char);
	for (int i=0; i<N_MAX; i++) {
		sum[i] = sum_char[i]-'0';
	}

	// TODO
	// 將顛倒後的a, b依照位數相加(考慮進位問題)

}

void bigMoneySub(char m1[], char m2[], int diff[])
{
	// Parameters
	// m1為第一個大數，m2為第二個大數，diff為各位數相減後的int陣列

	// a, b 兩字元陣列分別為 m1, m2 reverse 過後的陣列
	char a[N_MAX]="", b[N_MAX]="";
	reverse(m1, a);
	reverse(m2, b);
	int carry = 0;
	char diff_reversed[N_MAX] = {0};
	for (int i=0; i<N_MAX; i++) {
		int da = 0, db = 0;
		if (a[i]) da = a[i]-'0';
		if (b[i]) db = b[i]-'0';
		if (da - db - carry < 0) {
			diff_reversed[i] = (da - db - carry + 10)%10 + '0';
			carry = 1;
		} else {
			diff_reversed[i] = (da - db - carry)%10 + '0';
			carry = 0;
		}
	}
	char diff_char[N_MAX]="";
	reverse(diff_reversed, diff_char);
	for (int i=0; i<N_MAX; i++) {
		diff[i] = diff_char[i] - '0';
	}
	// TODO
	// 將顛倒後的a, b依照位數相減(考慮退位問題)

}

void bigMoneyPrint(int num[])
{
	cout << '$';
	int start;
	for (start=0; num[start] == 0; start++);
	for (int j = start; j < N_MAX; j++) {
		if ((N_MAX-j)%3 == 0 && j != start) {
			cout << ',';
		}
		cout << num[j];
	}
	cout << endl;
	// 將num陣列中的數字依照題目格式輸出
}

//TEMPLATE END

//APPEND BEGIN
int main(){
	char a[N_MAX] = "",b[N_MAX] = "";
	int sum[N_MAX] = {0}, diff[N_MAX] = {0};

	cin >> a >> b;

	bigMoneyAdd(a, b, sum);
	bigMoneyPrint(sum);
	bigMoneySub(a, b, diff);
	bigMoneyPrint(diff);

	return 0;
}
//APPEND END