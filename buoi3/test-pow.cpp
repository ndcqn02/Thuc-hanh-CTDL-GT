// #include <iostream>
// using namespace std;
// int main(){
// 	int x;
// 	cout <<" cuongdep trai";
// 	cin >> x;
// 	cout <<"xuat x: %d",x;
// }

#include <iostream>
using namespace std;

int main()
{
	double r = 0.0;

	// Đọc giá trị bán kính từ bàn phím
	cout << "Please input radius: ";
	cin >> r;
	
	// Xuất ra kết quả tính toán tương ứng
	cout << "\t=> Circumference: " << 2 * r * 3.14159265359 << endl;
	cout << "\t=> Area: " << r * r * 3.14159265359 << endl;
}