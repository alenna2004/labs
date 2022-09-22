#include <stdio.h>


int inverse(int num){
	int inversed_num = 0;
	while (num){
		inversed_num = inversed_num*10 + num%10;
		num /= 10;
	}
	return inversed_num;
}


int find_num_digit(int digit, int num){
	int res = 0;
	while (num){
		int cur_digit = num % 10;
		if (cur_digit==digit){
			res +=1;
		}
		num /= 10;
	}
	return res;
}


int f_num(int num){
	int res = 0;
	int i = 9;
	for (i; i>0; i-=1){
		int num_digits = find_num_digit(i, num);
		if (num_digits){
			for (num_digits; num_digits>0; num_digits-=1){
				res = res*10 + i;
			}
		}
	}
	return res;
}


int main(void){
	int num;
	int sign = 1;
	int res = 0;
	int check = scanf("%d", &num);
	if (check != 1){
		printf("You can write only integer");
		return 1;
	}
	if (num<0){
		sign = -1;
		num *= -1;
		int nuls = find_num_digit(0, num);
		res = f_num(num);
		if (nuls){
			for (nuls; nuls>0; nuls-=1){
				res*=10;
			}
		}
	}
	else{
		res = inverse(f_num(num));
	}
	printf("%d\n", res*sign);
	return 0;
}
