/*
	C - how to programming
	C programming turorial
*/

/*
	***Coding conventions
	Tên hàm: viết thường
	Camel Case: codingConvention
		Tên biến, Tham số, 
	Uppercase: System.IO		 <tên định danh có từ 2 ký tự trở xuống>
		Hằng số
	Mỗi câu lệnh riêng rẽ trên một dòng.
	Mỗi dấu ngoặc {} nằm trên một dòng (ngoại lệ khởi tạo giá trị cho mảng, nếu chỉ có một lệnh thì có thể không cần đánh dấu khối mã nguồn)
	Quy định chú thích: Chỉ sử dụng // và /// để chú thích. Không dùng /* */
/*
	Statements: lệnh
		Là một dòng có thể thực thi được và kết thúc bởi dấu ';'
		+ Khối lệnh
			đặt bên trong {} >> coi như một lệnh
			Những giá trị khởi tạo bên trong khối lệnh là biến cục bộ
*/

/*
	List
	Chương 1: Kn cơ bản
		1. Basic
			* Khai báo
			Mỗi biến khai báo >> đều có địa chỉ riêng (thay đổi sau mỗi lần chạy code) và giá trị nó đang lưu giữ
			* scanf("", &ten_bien)
			Hàm scanf cần biết địa chỉ của biến đó trong bộ nhớ >> thay đổi nội dung của ô nhớ đó
			scanf("%nd", &i) >> phải nhập đủ n chữ số trong 1 lần nhập thì scanf mới đọc
			* printf
			printf("...") or printf("...""...");
			printf("%n.mf", a); >>  n là số space trước số đó
									m là số chữ số lấy đằng sau dấu phẩy
			printf("%nd, value); >> (n is a negative integer) can le ben trai
									(n is a positive integer) can le ben phai
		2. Các kiểu dữ liệu cơ bản
			Tùy vào HĐH 32 or 64 bit
			- Kiểm tra kích thước 1 kiểu: lệnh sizeof(ten_kieu) >> Cách tính khoảng gia trị: 2^(8 * kich_thuoc) -1
				Mỗi phần tử thuộc 1 kiểu, sẽ có kích thước của kiểu đó
				=> sizeof(ten_mang) == NUM_C * NUM_R * sizeof(ten_kieu);
			- Quy định các phép toán biến có thể thao tác
		3. Biến
		4. Các chuẩn vào ra dữ liệu
			%0nd - "định dạng số nguyên có n chữ số, đệm bên trái bằng số 0"
			%.nf - "dấu phẩy động, lấy n số thập phân sau dấu phẩy"
		5. Hằng số
		6. Toán tử - phép toán - Thứ tự ưu tiên
		7. Thư viện
			<ctype.h>
			<limits.h>
			<math.h>
			<stdbool.h>
			<stdio.h>
			<stdlib.h>
			<string.h>
			<time.h>
	Chương 2: Các câu lệnh điều khiển
		1. Cấu trúc rẽ nhánh if - else
		2. Cấu trúc rẽ nhánh swich - case
		3. Cấu trúc điều khiển LẶP
			ctrl C >> thoát vòng lặp vô hạn
		4. Cấu trúc điều khiển lựa chọn ĐỆ QUY
		5. Lệnh break, continue
			Chỉ thực hiện được trong vòng lặp
	Chương 3: Hàm >> dễ bảo trì, mở rộng, phân tách chương trình
		1. Hàm - function
		2. Tham chiếu, tham trị
			Tham số (biến hình thức - formal parameters) - các biến được khai báo trong () khi định nghĩa hàm >> biến cục bộ
			Đối số (arguments) - các biến or giá trị được truyền vào hàm khi thực hiện lời gọi hàm - là biến or giá trị, địa chỉ
	Chương 4: Mảng
		1. Khái niệm liên quan tới MẢNG
			* MẢNG là một kiểu dữ liệu có cấu trúc
		2. Truyền mảng vào hàm, trả về mảng tử một hàm
		3. Tìm kiếm trong mảng
		4. Mảng 2 chiều
	Chương 5: Con trỏ
		1. con trỏ
		2. Con trỏ và mảng
		3. Truyền tham chiếu và Biến tham chiếu
	Chương 6: Kí tự và xâu
	1.Cơ bản về kí tự và xâu kí tự
	2.Các hàm thao tác với kí tự đơn
	3.Các hàm chuyển đổi xâu kí tự
	4.Các hàm chuẩn vào ra với kí tự và xâu kí tự.
	5.Các hàm thao tác với xâu kí tự
	6.
	7.
	8.
	9.
	Chương 7: Các kiểu dữ liệu có cấu trúc
	Chương 8: Thao tác với file
	Chương 9: Mở rộng
	1. Thuật toán sắp xếp 
		Bubble Sort - nổi bọt				   < làm phần tử nhỏ nhất nổi lên trên >
		Interchange sort - đổi chỗ trực tiếp   < luôn so sánh với phần tử đầu tiên > 
		shaker Sort - cải tiến của bubble sort < phần tử nhỏ nhất nổi lên trên + phần tử lớn nhất chìm xuống dưới - kĩ thuật chặn 2 đầu >> thu hẹp khoảng cần duyệt >
		slectionSort - sắp xếp chọn	trực tiếp  < làm phần tử min nổi lên trên, chạy index rồi swap 2 phần tử của mảng>
*/

/*
	2. Các kiểu dữ liệu cơ bản
	Kiểu			Kích thước (byte)	Khoảng giá trị									Định dạng
	bool								true or false

	char(KiTu)				1					-128 to 127										%c ( null = "" = '\0' )
	 unsinged				1					0 to 255

	int						2 or 4				-32,7K to 32,7K or -2,1 tỉ to 2,1 tỉ			%d, %i
	 unsinged									0 to 65,5K		or 0 to ~4,3 tỉ					%u

	short (short int %hd)	2																	%hi
	 usigned																					%hu

	long					4																	%ld, %li
	 unsigned				4
	long int				4 or 8																%li

	long long				8																	%llu, %lld
	long long int			8																	%lli
																		 Độ chính xác (chứ số)
	float					4					1.2E -38 to 3.4E +38	  6						%f
	double					8					3.3E -308 to 1.7E +308	  15					%lf, %lF
	long double				10, 12 or 16		3.4E -4932 to 1.1E +4932  19					%Lf
*/
/*
	3. Biến
	Là tên của vùng nhớ >> lưu trữ dữ liệu: các dữ liệu đầu vào lấy từ file, do người dùng nhập liệu, kq đầu ra khi tính toán, các dữ liệu trung gian khi thực hiện ctr.
	Mỗi biến: 1 kiểu dữ liệu nhất định, phải được khai báo trước khi sử dụng
	Biến trong C: phân biệt chữ hoa, thường Ex: an, An, AN là hoàn toàn khác nhau
	*** Cú pháp
	ten_kieu ten_bien;
	Ex: int sum, i, j = 0;
	Quy ước tên biến:
	- Tên biến bắt đầu bằng chữ cái or gạch dưới (_); k trùng với các keyword trong C
	- Tên biến dài hơn 1 từ >> chữ cái tiếp theo viết hoa (đặt tên biến có ý nghĩa - Quy tắc CAMELCASE)
	*** 3 loại biến
	Biến toàn cục: phạm vi sd trong toàn bộ ctr, khai báo ở ngoài all các hàm, khối;
	Biến cục bộ	 :					khối/hàm, kể từ sau vị trí được khai báo
	Biến hình thức:
	Ex: char KiTu = 'C';
*/
/*
	4. Các chuẩn vào ra dữ liệu
	Mỗi một kiểu dữ liệu sẽ có 1 định dạng nhập xuất
	Quay lại 2.
	*** Ép kiểu:
		- Chuyển đổi một biến từ kiểu dữ liệu này sang kiểu dữ liệu khác
		- Cú pháp: 
			(ten_kieu)bieu_thuc											>> chuyển kiểu tường minh
			1.0 * bieu_thuc	- đổi sang kiểu số thực
			1.0f *	bieu thuc (type float)												>> chuyển kiểu ngầm định
		CHUYỂN KIỂU NGẦM ĐỊNH: Trong quá trình biên dịch, nếu phát hiện một lệnh gán giá trị khác kiểu cho một biến, trình biên dịch sẽ tự động chuyển kiểu
		Ex: 
		int n = 16.96 >> n = 16; 
		double m = 13 >> m = 13.0

	*** Nâng cấp số nguyên
		- quá trình chuyển đổi giá trị kieu_char thành ASCII trước khi thực hiện phép tính
		Ex: 
		1.  char c = 'c', int i = 21;
			tong = c + i = 120 (giá trị ASCII của c là 99)
		2.  char d = 'a' + 3;
			d = 'd' (do 'a' = 97 và 'd' = 100)
	*** Phép chuyển đổi số học thông thường
		Khi tính toán một biểu thức, vd các phép toán số học, các hạng tử cần có cùng kiểu thì việc tính toán mới diễn ra, nếu các hạng tử không cùng kiểu >> xảy ra kiểu ngầm định
	kiểu nhỏ hơn sẽ chuyển sang kiểu lớn hơn
		int -> usigned int -> long -> unsigned long -> long long -> unsigned long long -> float -> double -> long double
		- Thực hiện cho toán tử gán và toán tử logic || hoặc &&
		Ex:int i = 21; char c = 'c'; float tong;
		tong = i + c = 120.000000
*/
/*
	5. Hằng số
	#define ten_bien gia_tri 
		Ex: #define PI 3.14
	const ten_kieu ten_bien = gia_tri; 
		>> có thể đặt được ở ngoài or trong hàm/khối
		>> ten_bien nên viết hoa hết

	Đặc biệt
	\\: kí tự \
	\?: kí tự ? (tương tự với ", ', b, c, d ...)
	%%: kí tự %
	\n: xuống dòng (new line)
	\a: chuông (Alarm)
	\t: tab ngang (tab)			\v:tab dọc (vertical navigation)
	\b: backspace (xóa đi 1 kí tự)
	\r: đưa về đầu hàng, không xuống hàng (return - trở về)
		printf("\t\t\tabc")		>>		abc
		printf("\t\t\t\rabc")	>>abc
		
*/
/*
	6. Toán tử - Phép toán - Thứ tự ưu tiên - Ý nghĩa kí tự
	* Toán tử 1 ngôi
	!: Toán tử logic > Phủ định, "khác"
	++, -- : Ex: a++ = ++a (a = a + 1)

	* Thứ tự ưu tiên
	++a >> phép gán "=" >> a++;

	* Toán tử 3 ngôi
	char (%s) ten_bien = dieu_kien?"...":dieu_kien?"...":"...";
	int	 (%d) ten_bien = dieu_kien? a : b;		(int a, b)
	>> tương tự chức năng của if else

	* Toán tử 2 ngôi
	Toán tử toán học: + - * 
		/ (phép chia thường int hoặc float đều được)
		% (phép chia dư)
	Toán tử so sánh: == >= <= > < !=
	Toán tử logic: && (và); || (hoặc);
	Toán tử gán: = += -= *= /= %= Ex: a += 1 là a = a + 1;

	* Toán tử con trỏ
	Toán tử address-of: &ten_bien		>> trả về giá trị kiểu int*

	*Ý nghĩa kí tự
	{...}: đánh dấu một khối mã nguồn
	&	 : tham chiếu đến || địa chỉ
*/
/*
	7. Thư viện

	*** <ctype.h>
		* Hàm số sẵn có (Áp dụng với kí tự đơn)
			Trả về true nếu tham số c thỏa mãn điều kiện được mô tả:
			int c >> giá trị int đại diện cho kí tự đó (giá trị mã ASCII)
		int isblank( int c); Test khoảng trống			{space và tab}
			blank: chỗ trống
		isspace(int c); Test white-space '\n' '\v' '\t' '\r' '\f'			{tab, newline, vertical tab, form feed, carriage return, và space}
		int islower( int c); Test chữ thường
		int isupper(int c); Test chữ hoa
		int isalpha( int c); Test chữ cái
			alpha: đứng đầu bảng chữ cái Hy Lạp
		int isdigit( int c); Test chữ số thập phân				Ex: '0' '100'
		int isxdigit(int c); Test ký tự thập lục phân			{ 0 1 2 3 4 5 6 7 8 9 A B C D E F a b c d e f }
		int isalnum( int c); Test chữ-số
			alnum: alpha || number
		int ispunct(int c); Test một punctuation char			{! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~}
			punctuation: chấm câu
		int isgraph(int c); Test ký tự graphical với Locale			{Ký tự chữ-số và ký tự punctuation}
		int isprint(int c); Test c có thể in được			{Ký tự chữ-số, Ký tự punctuation và Ký tự whitespace}
		int cntrl( int c); Test ký tự điều khiển			{Trong ASCII, các ký tự này có các mã hóa trong hệ bát phân từ 000 tới 037, và 177 (DEL)}
		
		Nhận và trả về một int:
		int tolower(int c); chữ hoa -> chữ thường
		int toupper(int c); chữ thường -> chữ hoa

	*** <limits.h>
		Thư viện lưu lại các max, min của các kiểu dữ liệu nhập xuất đã được định nghĩa
		Ex: SHRT_MAX, LONG_LONG_MIN, ...

	*** math.h
		kieu_tra_ve: double
		sqrt (x)
		cbrt (x): căn bậc 3
		exp  (x) : e mũ x
		log	 (x) : ln(x)
		log10 (x) : log(x)
		abs (int x): Absolute value of x
			fabs  (x) <đối với số thực>
		ceil  (x) : làm tròn lên số nguyên gần nhất >= x
		round (x) : làm tròn số
		floor (x) : làm tròn xuống số nguyên gần nhất <= x
		pow	  (x, y): x mũ y
		fmod  (x, y): phần dư x cho y Ex: fmod(12.55, 4) = 0.55
		sin	  (x): tính sin của x <tính theo radian> tương tự	tan (x), asin (x), acos(x), cos(x), atan (x)
			sin (90 * 1.0 / 180) = 1
		kieu_tra_ve : int

	*** stdbool.h
		sử dụng kiểu bool

	*** stdio.h
		* Kí tự và xâu kí tự
		Trả về giá trị int đại diện cho kí tự đó (giá trị mã ASCII)
			int getchar(); không nhận bất kì tham số nào, chỉ nhập được 1 kí tự một lần
				Ex: ten_bien = getchar();
			int putchar(int c); xuất duy nhất một kí tự
			gets(char *str);
			char *fgets(char *s, int n, stdin)
			int puts(const char *s)
		
	*** stdlib.h
		* Hàm sinh số ngẫu nhiên
			rand()%n: tạo ra 1 số ngẫu nhiên 0 - (n-1)
			rand()  : tạo ra 1 số ngẫu nhiên 0 - Hằng số RAND_MAX
		* Hàm chuyển đổi xâu kí tự thành giá trị số
			double strtod (const char *str, char **endPtr)
			long strtol( const char *str, char **endPtr, int base )
			unsigned long strtoul( const char *str, char **endPtr, int base )
			Tương tự với strtoll và strtoull
		* Cấp phát bộ nhớ động
			malloc
			calloc
			realloc

	*** string.h
		size_t strlen(const char *str)
		char *strcpy( char *dest, const char *src )
			DESTination: đích đến
			SouRCe: nguồn
			CoPY: sao chép
		char *strncpy( char *dest, const char *src, int n )
		char *strcat( char *str1, const char *str2 )
			conCATenate: ghép
		char *strncat( char *str1, const char *str2, int n )

		char *strlwr(char *s)
			LoWeR: thấp
		char *strupr(char *s)
			UPeR: cao
		char *strrev(char *s);
			reverse: đảo ngược
		char *strchr(char *s,int ch)

		char *strrchr(char *s,char ch)
			rearmost: cuối cùng
		char *strstr(char *s, char *s1);
		int strcmp(char *s1,char *s2)
			CoMPare: so sánh
		
	*** time.h
		srand(time(NULL)) >> kết hợp với hàm sinh số ngẫu nhiên
*/

/*
	1. Cấu trúc rẽ nhánh if - else
	* if(dieu_kien)
	Nếu sau if chỉ có 1 hàm/lệnh >> không cần {}
	* if(dieu_kien) {} else {}
	dieu_kien có thể là toán tử so sánh, tính đúng (khác 0) sai (0, '\0')
*/
/*
	2. Cấu trúc rẽ nhánh swich - case
	Sintax:
		cast_type variable;
		scanf (getchar())
		switch (variable)
		{
			case 'alphal' (number):
				{
					staetments
					...
					break;
				}
			default: ...
		}
	Ex:
	int main(){
		char luachon;
		printf("");
		luachon = getchar();

		switch (luachon){
			case 'a':
			case 'A': 
			case 'b':
			case 'B': {
				printf("");
				break;
			}
			case 'c':
			case 'C': {
				printf("");
				break;
			default: printf(""); >> khong chon 1 trong 4 đáp án trên
		}
*/
/*
	3. Cấu trúc điều kiện lặp
	* while (dieu_kien) {...}
	* do{...} while (dieu_kien);
		Luôn thực hiện ít nhất 1 lần
	* for (gia_tri_khoi_tao; dieu_kien; buoc_nhay){...}
	- Khởi tạo giá trị cho biến
		TH1: int i
			 for (i = 1; i < 10; i++){...}
			 hoặc
			 for (; i < 10; i++){...}
		TH2: for (int i = 1;...
	- Vòng lặp vô hạn
	Ex: int i = 1;
		for ( ; ; ; ){
		i++;
		if (i > 10) break;
		}
*/
/*
	1. Hàm - function
	- Là một nhóm các câu lệnh cùng thực hiện trọn vẹn một chức năng nào đó
	-Mục đích
		Tách ctr thành các đoạn code nhỏ có từng chức năng cụ thể >> Rõ ràng, tường minh
		Dễ quản lí ctr
		Thuận tiện tái sd.
	-Ex:
	int main(){

	return 0;
	}
	*** Khai báo, định nghĩa
	- Khai báo
	kieu_tra_ve ten_ham (danh_sach_tham_so);
	- Định nghĩa
	kieu_tra_ve ten_ham (danh_sach_kieu tham_so){
		//chức năng hàm
	}
	kieu_tra_ve: void, kiểu cơ bản, kiểu con trỏ, ...
	danh_sach_tham_so: Ex: (int i, int j)

	KHI MỘT BÀI SỬ DỤNG NHIỀU FUNCTION NÊN khai báo (trên phần main) RỒI định nghĩa (dưới phần main)
	
	- Phân loại
	Hàm trả về (khác kiểu void) - return ...;
	Hàm k trả về (void)
*/
/*
	2. Tham chiếu, tham trị
	* Gọi hàm bằng tham trị (passed by value):
	- ctr sẽ tạo ra giá trị bản sao của biến, sau đó gửi bản copy của biến được truyền đi.
	Do vậy mọi thay đổi nếu có trong hàm không làm thay đổi giá trị của biến gốc trước khi truyền đi
	>> Không có nhu cầu thay thay đổi giá trị của biến truyền đi

	* Gọi hàm bằng tham chiếu (passed by reference):
	- ctr sẽ truyền thẳng địa chỉ của biến hiện tại vào làm đối số của hàm được gọi. 
	Mọi thay đổi nếu có với các biến trong hàm được gọi sẽ làm thay đổi giá trị gốc của biến đã truyền đi.
	>> Khi muốn cho phép hàm được gọi thay đổi giá trị của biến truyền vào
	Ex:
	void ten_ham(int *a, int *b){
		int c = *a;
		*a = *b;
		*b = c;
	}
*/
/*
	4. Đệ quy
		Là một hàm gọi lại chính nó trực tiếp hoặc gián tiếp thông qua các hàm khác. Thường giải quyết những bài toán có đặc điểm chung.
	Trong lời gọi đệ quy, hàm đệ quy thường tự biết xử lí TH cơ bản nhất gọi là TH cơ sở/ điểm dừng. Nếu hàm đệ quy gọi với vấn đề ở TH cơ sở, nó trả về kq.
	Nếu hàm đệ quy gọi với vấn đề ở TH phức tạp, nó chia vấn đề thanh 2 phần: 1 phần nó biết cách xử lí, phần còn lại thì không. Để có thể đệ quy vấn đề nó chưa
	biết giải quyết sẽ trông giống với vấn đề gốc ban đầu nhưng nhỏ hơn, tức đỡ phức tạp hơn. Do vấn đề nhỏ hơn này giống y như vấn đề mà hàm đang xử lí nên hàm
	đệ quy tiếp tục gọi đệ quy với bản sao của hàm hiện tại để giải quyết vấn đề đang được nói tới.
		Đi kèm với keywork Return vì kq của lời gọi hàm là sự két hợp của phần vấn đề mà hàm biết cách xử lý và phần vấn đề hàm chưa biết cách xử lí >> tạo thành kq trả về nơi gọi hàm.
	Vấn đề cứ được chia nhỏ ra tới hi hàm gặp TH cơ sở, lúc này hàm sẽ lần lượt trả về kq theo chiều ngược lại của lời gọi hàm
	Ex:
	int fibo (int n){
			if ( n == 0 || n == 1)
			return 1;
			else
			return (fibo(n - 1) + fibo(n - 2));
		}
	*** So sánh đệ quy và vòng lặp
	- Cùng dựa trên cấu trúc điều khiển
	- Cùng dựa trên việc thực hiện lặp lại cùng một công việc giống nhau
	- Đều có đk kết thúc việc thực hiện lặp: Đệ quy kết thúc lặp khi gặp điểm dừng
	- Đều có thể lặp vô hạn: Đệ quy lặp vô hạn nếu vấn đề k nhở hơn sau mỗi lần đệ quy
	+ Đệ quy >> vấn đề nhỏ dần, vòng lặp >> vấn đề k đổi
	+ Đệ quy thường tiêu tốn tài nguyên máy: tốn CPU và bộ nhớ vì mỗi lần gọi, ctr lại yêu cầu cấp phát thêm không gian nhớ để lưu trữ kq và thực hiện ctr
	+ Vấn đề nào giải quyết đc = ĐQ đều có thể giải quyết bằng vòng lặp.
	Chọn ĐQ vì ĐQ thể hiện cách giải quyết vấn đề rõ ràng, tự nhiên, dễ hiểu, dễ sửa lỗi
*/
/*
	1. Khái niệm liên quan tới MẢNG
	- Là một nhóm các ô nhớ liền kề nhau dùng để lưu trữ các PHẦN TỬ cùng 1 kiểu >> mảng có kiểu là kiểu của các PHẦN TỬ
	- Để truy cập 1 PHẦN TỬ của mản, cần xđ ten_mang và vị trí của PHẦN TỬ đó trong MẢNG >> chỉ số mảng <INDEX> ( 0 to (n-1))
	2. Đn, khởi tạo, gán giá trị, duyệt các phần tử mảng
	* Khai báo:
	ten_kieu ten_mang[so_luong_phan_tu];
	- 2 loại:
	+ Khai báo mảng tĩnh	Ex: int a[5]
	+ Khai báo mảng động: kích thức mảng tăng lên khi số lượng phần tử mảng tăng lên vượt quá kích thước cũ

	* Khởi tạo
	- Mảng có thể được khởi tạo tại thời điểm khai báo mảng or sau khi khai báo
	 Cú pháp:
		kieu ten_mang[] = {danh_sach_gia_tri}
		danh_sach_gia_tri có >= 2 giá trị và phân cách bởi dấu ","
		ten_mang[index] = 12
	- Ex:
	char KiTu[] = {'H', 'E'} >> tự định số giá trị của mảng
	int arr[10] = {1, 2, 6}	 >> các phần tử còn lại sẽ là 0
	- TH k khởi tạo >> chỉ rõ số lượng phần tử
*/
/*
	2. Truyền mảng vào hàm, trả về mảng tử một hàm
	* Truyền mảng vào hàm
	- Khi khai báo biến >> được cấp phát 1 vùng nhớ trong bộ nhớ RAM >> có địa chỉ
	- Theo mặc định C, TRUYỀN MẢNG VÀO HÀM LÀ TRUYỀN THAM CHIẾU, truyền địa chỉ của phần tử đầu tiên của mảng vào hàm
	Mọi thay đổi bên trong hàm >> có thể thay đổi giá trị của các phần tử trong mảng

	- Ex
	void ip(int arr[]){
	for(int i = 0; i < max; i++) {
		scanf("%d", a[i]);
	}
	int main(){
		int arr[max];
		ip(arr);
		return 0;
	}

	CÓ THỂ TRUYỀN MẢNG VÀO HÀM THÀNH TRUYỀN THAM TRỊ BẰNG CÁCH  thêm CONST trước danh_sach_tham_so Ex: void ip (const int arr[])

	* Hàm trả về đối với mảng < sử dụng con trỏ >
	Ex:
	int* ip[](){				int timX (int *arr, int x){
		stactic int arr[max];		int i, count = 0;
		int i;						for (i = 0; i < max; i++){
		...								if (arr[i] == x) count++;
		return arr;					}		
	int main(){						return count;
		int arr[max], *b;		}
		b = ip();					int main(){
		...								int *arr;
		return 0;						...
*/
/*
	3. Tìm kiếm trong mảng
	* Tìm kiếm tuyến tính
	Xét giá trị x bất kì có cùng giá trị với phần tử nào trong mảng không
	* Tìm kiếm nhị phân
	Mảng đã sx tăng dần - ss giá trị x với giá trị phần tử giữa của mảng
	phần tử giữa == x kết thúc, > x tìm phía bên trái, < x tìm bên phải  => Làm tương tự
	void TimKiemNhiPHan(int arr[], int x) {
	int left = 0, right = max - 1, mid;
	do {
		mid = (left + right) / 2;
		if (x - arr[mid]) {
			if (x > arr[mid]) left = mid + 1;
			if (x < arr[mid]) right = mid - 1;
		}
		else {
			printf("\nFound");
			break;
		}
	} while (left <= right);
	if(x != arr[mid]) printf("\nDon't find");
}
*/
/*
	4. Mảng 2 chiều
	* Cú pháp
	ten_kieu ten_mang[so_hang][so_cot]
	Ex:
		Khởi tạo mảng 2 chiều
		int arr[2][2] = {
			{1,2},
			{3,4},
		}
	* xem số phần tử trong hàng or trong cột
	số phần tử trong mảng = sizeof(ten_mang)/sizeof(ten_kieu);
	số cột = sizeof(mot_phan_tu_cua_mang)/sizeof(ten_kieu);
	số hàng = ...

	* Sử dụng hàm để nhập hoặc xuất mảng 2 chiều
	void inp (int arr[][so_cot], int m, int n){
		int i,j;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &ten_mang[i][j]);
			}
		}
	}
*/
/*
	1. Con trỏ
	*con_tro 
		Trong đó:
			*con_tro Là một biến <chỉ giá trị của con trỏ - giá trị của biến đang trỏ tới>
			con_tro  là địa chỉ của biến đang trỏ tới
		Trường hợp khi khai báo ten_kieu *con_tro; thì * có ý nghĩa là báo cho chương trình biết ta đang khai báo con trỏ
		>> nên sử dụng ten_kieu* con_tro;
	* Khai báo
	ten_kieu *con_tro;
	Ex: int *a; >> con trỏ a kiểu int
	con trỏ sau khi khai báo nên được sử dụng ngay
	==>> Nếu con trỏ không được khởi tạo => trở thành giá trị giác >> làm chương trình chạy không đúng, gây nguy hiểm khi trùng địa chỉ biến đang sử dụng

	* Khởi tạo (3)
	int b = 18;
	a = NULL || 0 || &ten_bien (địa chỉ của 1 biến nào đó cùng kiểu)	
	Con trỏ kiểu void là loại biến con trỏ tổng quát, có thể nhận địa chỉ ở bất kì biến ở kiểu dữ liệu nào

	- cú pháp xem địa chỉ
	printf("%dinh_dang", &ten_bien || ten_con_tro);
		>> hệ cơ số 16: %x
		>> hệ thập phân: %d
	- Cách xem địa chỉ đó chứa giá trị gì
	printf("%ten_kieu", *a);			>> Ý nghĩa dấu *: trỏ đến giá trị chứa trong ô nhớ
*/
/*
	2. Con trỏ và mảng
	tên mảng >> chính là con trỏ 
	arr == &arr == &arr[0]
	int ar[] = {...}
	int *ptr = arr; int i;
	==>> ptr + i: dịch chuyển và lấy địa chỉ của ô nhớ (nhảy từ ô nhớ này sang ô nhớ kia)
	Giả sử:
		ptr += n							//ptr = ptr + (n * kich_thuoc_kieu)
	Ex: ptr = 3000; (kiểu int)				// 3000 ở đây là địa chỉ
		ptr++ >> ptr = ptr + (1 * 4) = 3004 //địa chỉ mới
	Địa chỉ của các phần tử cùng kiểu => có thể so sánh với nhau
*/		
/*
	3. Truyền tham chiếu
	Bản chất gọi hàm tham chiếu: truyền con trỏ nhận địa chỉ
*/
/*
	1.Cơ bản về kí tự và xâu kí tự
	Kí tự trong C - các kí tự hằng, đại diện bởi một số nguyên (theo bảng mã ASCII) lưu trong kiểu char
	Ex: NULL tương ứng với 0
	Đặt trong ' '

	Xâu kí tự
	Đặt trong " "
	Dùng mảng char để lưu xâu kí tự: char ten_mang[];
	Kí tự cuối cùng luôn là NULL('\0')
	Ex: "Hello" gồm {'H'...'\0'} >> cần mảng char có 6 phần tử
	>> xâu có chiều dài n kí tự thì mảng sẽ có n + 1 phần tử

	char c = '@';
	printf("%d", c);		//in ra mã ACSII
	gets(ten_xau)			// đọc vào xâu
	printf("%s", ten_xau);	// in ra xâu
	fflush(stdin)			// xóa bộ đệm (chạy trên windows)
*/
/*
	2.Các hàm thao tác với kí tự đơn
*/
/*
	3.Các hàm chuyển đổi xâu kí tự
	* Tham số
		str: xâu hằng kí tự chứa kí tự số cần chuyển đổi
		endPtr: con trỏ trỏ tới vị trí phần tử đầu tiên không thể chuyển đổi tiếp trong xâu str
		base: cơ số biểu diễn của xâu cần chuyển đổi sang hệ cơ số 10.	(2 - 8 - 16 đặc biệt 0 >> tự tìm cơ số)

	double strtod (const char *str, char **endPtr):chuyển đổi xâu kí tự chứa "kí tự số có thể chuyển đổi sang giá trị số kiểu double"
	Ex:
	const char *ptr = "   -432.575finish  s"
	char *p; double d;
	d = strtod(ptr, &p)
	printf("%lf\n", d); // -432.575
	printf("%s", p);	// "finish  s"

	>>> Mặc định là bỏ qua những khoảng trống ở đầu
		Nếu kí tự đầu tiên sau khoảng trống không phải kí tự số >> endptr dừng lại ngay tại đó >> không thể đưa ra số ở kiểu double

	long strtol( const char *str, char **endPtr, int base ): chuyển đổi xâu các kí tự số thành giá trị số nguyên dài.
	Ex:
	*ptr = "   100A.343542wwww i"
	d = strtol(ptr, &p, 2)								d = strtol(ptr, &p, 16);
	printf("%lu\n", d);			// 4					// 16^3 + 10
	printf("%s", p);			// A.343542wwww i		// .343542wwww i

	unsigned long strtoul( const char *str, char **endPtr,int base ): chuyển đổi xâu các kí tự số thành giá trị số nguyên dài không dấu
	>>> Nếu số nhận được là số âm >> tràn số >> nhận được giá trị rác
*/
/*
	4.Các hàm chuẩn vào ra với kí tự và xâu kí tự.
	* Đọc vào
	int getchar(); không nhận bất kì tham số nào, mỗi lần sử dụng chỉ đọc vào được một kí tự
		Cú pháp: ten_bien = getchar();
	int gets(char *str): đọc vào một xâu (nếu nhập quá chiều dài xâu đã khởi tạo >> tạo ra một xâu mới khác kích thước ta cần)
	
	>> Để tránh như vậy sử dụng *fgetchar()
	char *fgets(char *s, int n, stdin);
		Tham số thứ nhất: ĐỌC vào n - 1 kí tự từ bàn phím vào kết thúc bằng khi gặp dòng mới hoặc enter
		Tham số thứ ba: Cho phép ta nhập dữ liệu từ bàn phím
						hoặc nhập dữ liệu từ file
	* In ra
	int putchar(int c); Cho phép PRINT ra || RETURN
		Ex: digit = putchar(c);
	int puts(const char *s);
		In ra thông điệp chứa trong tham số, trả về giá trị khác 0 nếu thành công, EOF nếu thất bại
*/
/*
	5.Các hàm thao tác với xâu kí tự
	1. kiểu strlen( const char *str )
		>> Trả về độ dài xâu kí tự trong tham số <không tính NULL>

	2.char *strcpy( char *dest, const char *src )
		Copy content của src sang dest, kể cả kí tự ‘\0’
		>> Trả về xâu dest (nếu thành công) < chiều dài dest phải đủ lớn để chứa được src >
		
		2.1 char *strncpy( char *dest, const char *src, int n )
		Sao chép tối đa n kí tự từ xâu src sang xâu dest -> Kí tự NULL có thể không được copy nếu n <= độ dài xâu src
			>> Trả về xâu dest.
	3. char *strcat( char *str1, const char *str2 )
	Nối xâu str2 vào xâu str1. Kí tự đầu của xâu str2 sẽ thay thế kí tự kết thúc của xâu str1
		>> Trả về xâu str1 < length str1 đủ lớn để chứa được cả xâu str2 >
		
		3.1 char *strncat( char *str1, const char *str2, int n )
			Lấy tối đa n kí tự đầu từ str2 nối vào xâu str1. Kí tự NULL tự động được thêm vào sau khi nối xong.
			>>Trả về xâu str1 sau khi nối.
*/
/*
	sử dụng hàm malloc()
Hàm malloc() thực hiện cấp phát bộ nhớ bằng cách chỉ định số byte cần cấp phát. Hàm này trả về con trỏ kiểu void cho phép chúng ta có thể ép kiểu về bất cứ kiểu dữ liệu nào.

Cú pháp của hàm malloc(): 
	ptr = (castType*) malloc(size);
Ví dụ: 
	ptr = (int*) malloc(100 * sizeof(int));
Ví dụ trên thực hiện cấp phát cho việc lưu trữ 100 số nguyên. Giả sử sizeof int là 4, khi đó lệnh dưới đây thực hiện cấp phát 400 bytes. Khi đó, con trỏ ptr sẽ có giá trị là địa chỉ của byte dữ liệu đầu tiên trong khối bộ nhớ vừa cấp phát.
Trong trường hợp không thể cấp phát bộ nhớ, nó sẽ trả về một con trỏ NULL.

Sử dụng hàm calloc()
Hàm malloc() khi cấp phát bộ nhớ thì vùng nhớ cấp phát đó không được khởi tạo giá trị ban đầu. Trong khi đó, hàm calloc() thực hiện cấp phát bộ nhớ và khởi tạo tất cả các ô nhớ có giá trị bằng 0.
Hàm calloc() nhận vào 2 tham số là số ô nhớ muốn khởi tạo và kích thước của 1 ô nhớ.
Cú pháp của hàm calloc():
	ptr = (castType*)calloc(n, size); 
Ví dụ:
	ptr = (int*) calloc(100, sizeof(int)); 
Trong ví dụ trên, hàm calloc() thực hiện cấp phát 100 ô nhớ liên tiếp và mỗi ô nhớ có kích thước là số byte của kiểu int. Hàm này cũng trả về con trỏ chứa giá trị là địa chỉ của byte đầu tiên trong khối bộ nhớ vừa cấp phát.

Sử dụng hàm free()
Việc cấp phát bộ nhớ động trong C dù sử dụng malloc() hay calloc() thì chúng cũng đều không thể tự giải phóng bộ nhớ. Bạn cần sử dụng hàm free() để giải phóng vùng nhớ.
Cú pháp:
free(ptr); // ptr là con trỏ 
Lệnh này sẽ giải phóng vùng nhớ mà con trỏ ptr đã được cấp phát. Giải phóng ở đây có nghĩa là trả lại vùng nhớ đó cho hệ điều hành và hệ điều hành có thể sử dụng vùng nhớ đó vào việc khác nếu cần.
Nếu bạn không giải phóng nó thì nó sẽ tồn tại cho tới khi chương trình kết thúc. Điều này sẽ rất nguy hiểm nếu chương trình của bạn liên tục cấp phát các vùng nhớ mới và sẽ gây ra hiện tượng tràn bộ nhớ mà mình đã nhắc tới ở trên. Thử code này xem sao (bảo đảm là máy bạn sẽ bị treo và chỉ còn cách ấn nút nguồn thôi, bạn có thể để cấp phát size nhỏ hơn và theo dõi thay đổi qua Task Manager):
#include <stdio.h>
#include <stdlib.h>
 
int main(){
    for(;;){
        printf("\nCap phat %d bytes!", 1000000 * sizeof (int));
        int *ptr = (int*) malloc (1000000 * sizeof (int));
    }
}
 
Ví dụ sử dụng malloc() và free()
#include <stdio.h>
// Thư viện này cần để cấp phát bộ nhớ động
#include <stdlib.h>
 
int main()
{
    int n, i, *ptr, sum = 0;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
 
    // Nếu không thể cấp phát, 
    // hàm malloc sẽ trả về con trỏ NULL
    if (ptr == NULL)
    {
        printf("Co loi! khong the cap phat bo nho.");
        exit(0);
    }
    printf("Nhap cac gia tri: ");
    for (i = 0; i < n; ++i)
    {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }
    printf("Tong = %d", sum);
 
    // Giải phóng vùng nhớ cho con trỏ
    free(ptr);
    return 0;
}

	Sử dụng hàm realloc()
Nếu việc cấp phát bộ nhớ động không đủ hoặc cần nhiều hơn mức đã cấp phát, bạn có thể thay đổi kích thước của bộ nhớ đã được cấp phát trước đó bằng cách sử dụng hàm realloc().
Cú pháp của realloc():
	ptr = realloc(ptr, n);
Hàm này thực hiện cấp phát vùng nhớ mới cho con trỏ ptr. Vùng nhớ mới đó sẽ có kích thước mới là n bytes.
Hàm này cũng trả về con trỏ chứa giá trị là địa chỉ của byte đầu tiên trong vùng nhớ mới. Hàm này sẽ cố gắng mở rộng số ô nhớ ra phía sau nếu có thể để giữ nguyên giá trị của con trỏ ban đầu. Trong trường hợp phải đổi sang một vùng nhớ khác, hàm realloc() cũng sẽ mang theo giá trị đã có ở vùng nhớ cũ sang vùng nhớ mới và giải phóng luôn vùng nhớ cũ (đọc thêm tài liệu số 2). Trong trường hợp không thể, nó sẽ trả về con trỏ NULL giống như malloc() và calloc().
Ví dụ sử dụng hàm realloc()
Trong ví dụ dưới đây, ta sẽ sử dụng hàm realloc() để tái phân bổ lại bộ nhớ. Như trong ví dụ dưới đây thì việc cấp phát không phải di chuyển sang vùng nhớ khác mà chỉ mở rộng ra phía sau.
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr, i , n1, n2;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n1);
    ptr = (int*) malloc(n1 * sizeof(int));
    printf("Dia chi cua vung nho vua cap phat: %u", ptr);
    
    printf("\nNhap lai so luong phan tu: ");
    scanf("%d", &n2);
    // phân bổ lại vùng nhớ
    ptr = (int*) realloc(ptr, n2 * sizeof(int));
    printf("Dia chi cua vung nho duoc cap phat lai: %u", ptr);
    // giải phóng
    free(ptr);
    return 0;
}
 
Kết quả chạy:
Nhap so luong phan tu: 2
Dia chi cua vung nho vua cap phat: 1993360
Nhap lai so luong phan tu: 100
Dia chi cua vung nho duoc cap phat lai: 1993360

	Cấp phát động mảng 1 chiều
#include <stdio.h>
#include <stdlib.h>

void NhapMang(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("arr[%d] = ", i);
		// Do giá trị con trỏ là địa chỉ rồi. Nên bạn sẽ không thấy dấu & quen thuộc nữa
		scanf("%d", (arr + i));
	}
}

void XuatMang(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("arr[%d] = %d\n", i, *(arr + i));
	}
}

void ThemPhanTu(int *a, int &n, int val, int pos)
{
	// Phân bổ lại bộ nhớ đã cấp phát cho con trỏ.
	// Ta cần thêm 1 ô nhớ cho nó => dùng realloc()
	a = (int *)realloc(a, (n + 1) * sizeof(int));
	// Neu pos <= 0 => Them vao dau
	if (pos < 0)
	{
		pos = 0;
	}
	// Neu pos >= n => Them vao cuoi
	else if (pos > n)
	{
		pos = n;
	}
	// Dich chuyen mang de tao o trong truoc khi them.
	for (int i = n; i > pos; i--)
	{
		*(a + i) = *(a + i - 1);
	}
	// Chen val tai pos
	*(a + pos) = val;
	// Tang so luong phan tu sau khi chen.
	++n;
}

void XoaPhanTu(int *a, int &n, int pos)
{
	// Mang rong, khong the xoa.
	if (n <= 0)
	{
		return;
	}
	// Neu pos <= 0 => Xoa dau
	if (pos < 0)
	{
		pos = 0;
	}
	// Neu pos >= n => Xoa cuoi
	else if (pos >= n)
	{
		pos = n - 1;
	}
	// Dich chuyen mang
	for (int i = pos; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	// Cấp phát lại vùng nhớ, giờ ta chỉ cần n - 1 ô nhớ
	a = (int *)realloc(a, (n - 1) * sizeof(int));

	// Giam so luong phan tu sau khi xoa.
	--n;
}

int main()
{
	int *arr;
	int n;
	do
	{
		printf("Nhap so luong n = ");
		scanf("%d", &n);
	} while (n < 1);

	// cấp phát đủ sài
	arr = (int *)malloc(n * sizeof(int));
	// arr = (int*) calloc(n, sizeof(int));

	if (arr == NULL)
	{
		printf("Khong the cap phat!");
		exit(0);
	}

	NhapMang(arr, n);
	printf("\nMang vua nhap la:\n");
	XuatMang(arr, n);

	printf("\n=======THEM PHAN TU======\n");
	int val, pos;
	printf("\nNhap so can them: ");
	scanf("%d", &val);
	printf("\nNhap vi tri muon chen: ");
	scanf("%d", &pos);
	ThemPhanTu(arr, n, val, pos);
	printf("\nMang sau khi them:\n");
	XuatMang(arr, n);

	printf("\n=======XOA PHAN TU======\n");
	printf("\nNhap vi tri muon xoa: ");
	scanf("%d", &pos);
	XoaPhanTu(arr, n, pos);
	printf("\nMang sau khi xoa:\n");
	XuatMang(arr, n);
	// giải phóng
	free(arr);
}
*/
