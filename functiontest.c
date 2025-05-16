// Test program for functions
// input 4 & 9 should output "The larger of 4 and 9 is 9"
// sum of squares input 5 should output "The sum of squares up to 5 is 55"


int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int sum_of_squares(int n) {
	int sum, i;
	sum = 0;
	i = 1;

	while (i <= n) {
		sum = sum + (i * i);
		i = i + 1;
	}
	return sum;
}

void main(void) {
	int x;
	int y;
	int larger;
	int limit;
	int result;

	write "Enter first number: ";
	read x;
	write "Enter second number: ";
	read y;

	larger = max(x, y);
	write "The larger of ";
	write x;
	write " and ";
	write y;
	write " is ";
	write larger;
	write "\n";

	write "Enter a limit for sum of squares: ";
	read limit;
	result = sum_of_squares(limit);
	write "The sum of squares up to ";
	write limit;
	write " is ";
	write result;
	write "\n";
}
