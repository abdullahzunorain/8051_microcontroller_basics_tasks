/*
task_12_part(8):
2nd approach:
Make a function called display_num_7seg(long num) which takes any arbitrary number as input, 
converts it and displays it on the seven segment displays. e.g. If you call  
long num = 42354245; 
display_num_7seg(num); 
The above code should display 42354245 on the seven segment displays. If num = 
97561654 then the seven segment displays should display 97561654. Do conversion in 
real time and don’t hard code the number to be displayed.

*/

#include <REG52.H>

sbit p1 = P2^2;
sbit p2 = P2^3;
sbit p3 = P2^4;

void my_func(int digit);    //func prototype
void display_num_7seg(long num); //func prototype


//timer function(for delay)
void M0T0delay(void) {
  int dell;  
	for(dell=0; dell<29; dell++){
		TMOD = 0x01;  // 16-bit non-autoreload mode, timer_0, mode_1
    TL0 = 0x99; 
    TH0 = 0xEF;
    TR0 = 1;
    while (TF0 == 0);
    TR0 = 0;
    TF0 = 0;
	}
}


// main func..
void main() {
	
    long num = 93475857;
	
    while (1) {
        display_num_7seg(num);
    }
}

//
void display_num_7seg(long num) {
    int i;
	
    // Loop through each digit position of the number (from right to left)
		for (i = 0; i < 8; i++) {
			// Set the state of display 1 based on whether the current digit position is odd or even
			p1 =  i & 0x01;
			// Set the state of display 2 based on whether the current digit position is odd or even
			p2 = (i >> 1) & 0x01;
			// Set the state of display 3 based on whether the current digit position is odd or even
			p3 = (i >> 2) & 0x01;
			// Show the current digit on the seven-segment display
			my_func(num % 10);
			// Move to the next digit by dividing the number by 10
			num /= 10;
			// Introduce a delay to make the displayed digits visible for a short period
			M0T0delay();
	 }
}

void my_func(int digit) {
    switch(digit) {
        case 0:
            P0 = 0x3F;
            break;
        case 1:
            P0 = 0x06;
            break;
        case 2:
            P0 = 0x5B;
            break;
        case 3:
            P0 = 0x4F;
            break;
        case 4:
            P0 = 0x66;
            break;
        case 5:
            P0 = 0x6D;
            break;
        case 6:
            P0 = 0x7D;
            break;
        case 7:
            P0 = 0x07;
            break;
        case 8:
            P0 = 0x7F;
            break;
        case 9:
            P0 = 0x6F;
            break;
    }
}





/*
let's break down the `display_num_7seg` function step by step:

```c
void display_num_7seg(long num) {
    int i;
    for (i=0; i<8; i++) {
```
This function loops 8 times, representing each digit of the number to be displayed on the 7-segment display. The loop variable `i` is used to keep track of which digit we are currently displaying.

```c
        p1 = i & 0x01;
        p2 = (i >> 1) & 0x01;
        p3 = (i >> 2) & 0x01;
```
Inside the loop, we manipulate the `p1`, `p2`, and `p3` special bit variables to control the pins of Port 2. These pins are typically used to select which 7-segment display to activate in a multi-digit display setup. By setting these pins appropriately, we can select the correct display for each digit.

- `p1`, `p2`, and `p3` are used to select one of the eight digits (0 to 7) on the display.
- The `&` operator is a bitwise AND operation, and `0x01` is a hexadecimal number with a binary representation of `00000001`. When we perform `i & 0x01`, we effectively isolate the least significant bit of `i`.
- The `>>` operator is a bitwise right shift operation. By shifting `i` right by 1 or 2 bits, we isolate the next two bits of `i` to select the appropriate digit.

```c
        my_func(num % 10);
```
After selecting the correct display using `p1`, `p2`, and `p3`, we call the `my_func` function to display the current digit on that display. We pass `num % 10` as an argument to `my_func` to get the least significant digit of `num`. The `%` operator calculates the remainder when `num` is divided by 10, giving us the last digit of the number.

```c
        M0T0delay();
```
After displaying the digit, we introduce a delay to control the timing of the display. This delay ensures that each digit is displayed for a short period before moving on to the next digit.

```c
        num /= 10;
    }
}
```
Finally, we divide `num` by 10 to remove the least significant digit and prepare for the next iteration of the loop. This effectively shifts `num` to the right, making the next digit the least significant digit for the next iteration.

Overall, this function iterates through each digit of the input number, selects the appropriate display for each digit, and then calls `my_func` to display the digit on that display. It introduces a delay between each digit to control the timing of the display.





//Sure, let's break it down:

//1. **Start of the Function**: This function is called `display_num_7seg` and it's used to show a number on a special kind of display called a "7-segment display". This display looks like a number 8 and can show numbers from 0 to 9.

//2. **Looping Through Each Digit**: Imagine you have a long number written on a paper, and you want to show each digit of that number on the display. This loop helps us do just that. It starts from the first digit (which is the rightmost one) and goes up to the eighth digit (which is the leftmost one). We use the variable `i` to keep track of which digit we are currently looking at.

//3. **Choosing the Right Segment Display**: Now, imagine the display as a bunch of boxes, each labeled with a number from 0 to 7. We need to tell the display which box to light up to show the current digit. That's what these lines do:
//   - `p1 = i & 0x01;`: This line tells the display which box to light up for the ones place of the number. For example, if `i` is 3, then `p1` will be 1 (because 3 & 1 equals 1).
//   - `p2 = (i >> 1) & 0x01;`: This line tells the display which box to light up for the tens place of the number. For example, if `i` is 3, then `p2` will be 1 (because 1 & 0 equals 1).
//   - `p3 = (i >> 2) & 0x01;`: This line tells the display which box to light up for the hundreds place of the number. For example, if `i` is 3, then `p3` will be 0 (because 0 & 0 equals 0).

//4. **Showing the Digit**: Now that we've told the display which box to light up, we need to tell it what number to show in that box. That's where the `my_func` function comes in. It takes the current digit of the number (`num % 10`) and shows it on the display.

//5. **Waiting a Bit**: After showing the digit, we wait for a short time (`M0T0delay`) before moving on to the next digit. This is like pausing for a moment before flipping to the next page of a book.

//6. **Moving to the Next Digit**: Finally, we need to move to the next digit of the number so that we can show it on the display. We do this by dividing the number by 10 (`num /= 10`). For example, if `num` was 12345, after this line it would become 1234, then 123, then 12, and so on.

//7. **Looping Again**: We repeat this process for each of the eight digits of the number until we've shown all of them on the display.

//That's how the function works! It's like telling the display which box to light up and then telling it what number to show in that box, one digit at a time.


//*/


///*
//Explanation of `p1 =  i & 0x01;` line:
////
//Sure! Let's break it down in a simple way:

//Imagine we have two numbers, `i` and `0x01`.

//- `i` represents the current digit we're looking at. For example, if `i` is 3, it means we're currently looking at the digit 3.
//- `0x01` is a special number that looks like this in binary: `00000001`.

//Now, let's use a simple example:

//- If `i` is 3 and we do `i & 0x01`, it's like saying "compare the binary digits of `i` and `0x01` and only keep the bits that are the same in both numbers".

//Let's see it step by step:

//- `i` in binary is `00000011` (because 3 is represented as `11` in binary).
//- `0x01` in binary is `00000001`.

//Now, we compare each digit (bit) of `i` with the corresponding bit of `0x01`:

//- The first bit of `i` is `0`, and the first bit of `0x01` is `1`. They are different, so the result of the comparison is `0`.
//- The second bit of `i` is `1`, and the second bit of `0x01` is `1`. They are the same, so the result of the comparison is `1`.

//So, when we do `i & 0x01`, we get `00000001`, which is `1` in decimal.

//This means that if `i` is an odd number, the result will be `1`, and if `i` is an even number, the result will be `0`.

//In summary, `p1 = i & 0x01` is a way to check if the current digit is odd or even, and it sets `p1` accordingly.
////


//// explanation of this line of code==> `p2 = (i >> 1) & 0x01;`

//Sure! Let's break it down in a simple way:

//Imagine we have two numbers, `i` and `0x01`.

//- `i` represents the current digit we're looking at. For example, if `i` is 3, it means we're currently looking at the digit 3.
//- `0x01` is a special number that looks like this in binary: `00000001`.

//Now, let's use a simple example:

//- If `i` is 3 and we do `i >> 1`, it's like saying "shift all the digits of `i` to the right by one place".

//Let's see it step by step:

//- `i` in binary is `00000011` (because 3 is represented as `11` in binary).
//- If we shift it to the right by one place, we get `00000001`.

//So, when we do `(i >> 1)`, we get `00000001`, which is `1` in decimal.

//Now, let's move to the next part: `& 0x01`.

//- We already have `00000001` from the previous step.
//- `0x01` in binary is `00000001`.

//Now, we compare each digit (bit) of `00000001` with the corresponding bit of `00000001`:

//- The first bit of `00000001` is `1`, and the first bit of `00000001` is `1`. They are the same, so the result of the comparison is `1`.

//So, when we do `(i >> 1) & 0x01`, we still get `00000001`, which is `1` in decimal.

//This means that `p2` will be `1` if the current digit is odd and `0` if it's even. It helps to determine which display to light up for the tens place of the number.

//// Explanation of this line of code =>  `p3 = (i >> 2) & 0x01;` : 

//Alright! Let's break it down step by step:

//1. **Shifting `i` to the Right by 2 Places**: 
//   - Imagine `i` is a number represented in binary. For example, if `i` is 5, in binary it would be `00000101`.
//   - When we do `i >> 2`, it means we are shifting all the digits of `i` to the right by 2 places. So, `00000101` becomes `00000001`.

//2. **Logical AND Operation with `0x01`**:
//   - Now, we take the result of the shifting operation (`00000001`) and perform a logical AND operation with `0x01`.
//   - `0x01` is represented in binary as `00000001`.
//   - In a logical AND operation, if both bits are 1, the result is 1. Otherwise, the result is 0.
//   
//So, let's compare each bit:

//- The first bit of `00000001` is `1`, and the first bit of `00000001` is `1`. They are the same, so the result of the comparison is `1`.

//Therefore, the result of `(i >> 2) & 0x01` would be `00000001`, which is `1` in decimal.

//This means that `p3` will be `1` if the current digit is odd and `0` if it's even. It helps to determine which display to light up for the hundreds place of the number.

//*/

//void display_num_7seg(long num) {
//    int i;
//	
//    for (i=0; i<8; i++) {
//        p1 =  i & 0x01;
//        p2 = (i >> 1) & 0x01;
//        p3 = (i >> 2) & 0x01;
//			
//        my_func(num % 10);
//        num /= 10;
//        M0T0delay();			
//    }

//}
