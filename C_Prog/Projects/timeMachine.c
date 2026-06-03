#include <stdio.h>
#include <time.h>

int main() {
time_t current = time(NULL);
struct tm future_tm, past_tm;

	 // 1. Break down current time into components
 	 future_tm = *localtime(&current);
 	 past_tm = *localtime(&current);

	 // 2. Increment and decrement the year component
	 future_tm.tm_year += 3; // Move forward 3 years
 	 past_tm.tm_year -= 3;   // Move backward 3 years

	 // 3. Rebuild into time_t (handles leap years automatically)
 	 time_t future = mktime(&future_tm);
 	 time_t past = mktime(&past_tm);
 	 // 4. Print results
	 printf("\nTime Travel future (3 years): %s", ctime(&future));
	 printf("Time Travel Past (3 years): %s", ctime(&past));

	 return 0;
}
	                                                            
