# gmtime
Simple timestamp converter based on Minix gmtime code

# Usage
```Pawn
new year, month, day, hour, minute, second;
gmtime(gettime(), year, month, day, hour, minute, second);
printf("%02d:%02d:%02d %02d.%02d.%04d", hour, minute, second, day, month, year);
```
